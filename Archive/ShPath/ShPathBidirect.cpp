#include "ShPathDijkstraHeap.h"
#include "LabelSettingAlFactory.h"
#include "ShPathBidirect.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <deque>

ShPathBidirect::ShPathBidirect(StarNetwork *netPointer):LabelSettingAl(netPointer){

    forwardAlgo = (ShPathDijkstraHeap*)LabelSettingAlFactory::get()->createLabelSettingAl("DijkstraHeap", _netPointer);

    backwardAlgo = (ShPathDijkstraHeap*)(LabelSettingAlFactory::get()->createLabelSettingAl("DijkstraHeap", _netPointer));

} 
ShPathBidirect::~ShPathBidirect(){

    delete forwardAlgo;
    delete backwardAlgo;
}

void ShPathBidirect::calculate(int originIndex){
    calculate(originIndex, -1);
}

void ShPathBidirect::calculate(int originIndex, int destIndex){
    // cast down to get ShPathBidirect methods
    //std::cout << originIndex << " " << destIndex << std::endl;

    // no destIndex, do the normal routine
    if (destIndex == -1){ 
        forwardAlgo->calculate(originIndex); 
        for(int i = 0; i < _nbNodes; i++){
            _nodeList[i].dist = forwardAlgo->getCost(i);
            _nodeList[i].linkIndex = forwardAlgo->getInComeLink(i) == NULL ? -1 : forwardAlgo->getInComeLink(i)->getIndex();
        }
        return;
    } // else we do bidirectional

    forwardAlgo->initialise(originIndex, destIndex, false);
    backwardAlgo->initialise(destIndex, originIndex, true);

    std::set<int> setForward = std::set<int>();
    std::set<int> setBackward = std::set<int>();

    int midnode = -1;
    int forwardTopNode = -1;
    int backwardTopNode = -1;
    FPType newPath = -1;
    FPType shortestPath = std::numeric_limits<FPType>::max();
    while(true){
        bool forwardEmpty = forwardAlgo->isQempty();
        if(!forwardEmpty){
            forwardTopNode = forwardAlgo->iterate();
            setForward.insert(forwardTopNode);
        }

        if(setBackward.find(forwardTopNode) != setBackward.end()){
            newPath = forwardAlgo->getCost(forwardTopNode) + backwardAlgo->getCost(forwardTopNode);
            if(newPath > 0 && newPath < shortestPath){
                shortestPath = newPath;
                midnode = forwardTopNode;
                break;
            }
        }

        bool backwardEmpty = backwardAlgo->isQempty();
        if(!backwardEmpty){
            backwardTopNode = backwardAlgo->iterate();
            setBackward.insert(backwardTopNode);
        }

        if(setForward.find(backwardTopNode) != setForward.end()){
            newPath = forwardAlgo->getCost(backwardTopNode) + backwardAlgo->getCost(backwardTopNode);
            if(newPath > 0 && newPath < shortestPath){
                shortestPath = newPath;
                midnode = backwardTopNode;
                break;
            }
        }

        if (forwardEmpty && backwardEmpty){
            break;
        }
    }

    // min {d_v^s + c_vw + d_w^t | v \in R^s, w \in R^t}
    // get all remaining leafs nodes from the PQs
    int node;
    while( (node = forwardAlgo->popQ()) != -1){
        setForward.insert(node);
    }

    while( (node = backwardAlgo->popQ()) != -1){
        setBackward.insert(node);
    }

    //std::cout << "midnode:" << std::endl;
    //std::cout << midnode << std::endl;
    //std::cout << shortestPath << std::endl;
    //std::cout << std::endl;
    std::set<int>::iterator itf; // forward
    std::set<int>::iterator itb; // backward
    //std::cout << "v[i]\tw[j]\tdv[i]\tdw[j]\tnewpath\tfstShPath\tgetTime\tgetIndex" << std::endl;
    StarNode *curNode;
    int shorterPathLinkIndex = -1;
    for(itf = setForward.begin(); itf != setForward.end(); itf++){
        curNode = _netPointer->beginNode(*itf); 

        if(curNode == NULL || curNode->getIsZone()) {continue;}

        if( forwardAlgo->getCost(forwardTopNode) <= forwardAlgo->getCost(*itf) ){ continue; }

        for(itb = setBackward.begin(); itb != setBackward.end(); itb++){
            // for each outgoing link of nodes in  setForward
            if( backwardAlgo->getCost(backwardTopNode) <= backwardAlgo->getCost(*itb) ){ continue; }

            curNode = _netPointer->beginNode(*itf); 
            for(StarLink* link = _netPointer->beginLink(); link != NULL; link = _netPointer->getNextLink()){
                if( link->getNodeToIndex() == (*itb) ){
                    newPath = forwardAlgo->getCost(*itf) + backwardAlgo->getCost(*itb) + link->getTime();
                    if( newPath < shortestPath){
                        shortestPath = newPath;
                        shorterPathLinkIndex = link->getIndex();
                        forwardTopNode = *itf;
                        backwardTopNode = *itb;
                    }
//                    std::cout << (*itf) << "\t" << (*itb) << "\t" << forwardAlgo->getCost(*itf) << "\t" << backwardAlgo->getCost(*itb) << "\t" << newPath << "\t" << shortestPath << "\t\t" << link->getTime() << "\t" << link->getIndex() << std::endl;
                }
            }
        } // for j
    } // for i

    initNodeList();
    std::deque<int> q; // link indices
    StarLink *link;
    if(shorterPathLinkIndex != -1){ // path not from midnode

        link = forwardAlgo->getInComeLink(forwardTopNode);
        while( link!=NULL){
            q.push_front(link->getIndex());
            node = link->getNodeFromIndex();
            link = forwardAlgo->getInComeLink(node);
        }

        q.push_back(shorterPathLinkIndex);

        link = backwardAlgo->getInComeLink(backwardTopNode);
        while( link!=NULL){
            q.push_back(link->getIndex());
            node = link->getNodeToIndex();
            link = backwardAlgo->getInComeLink(node);
        }
    }else{ // path from midnode
        //std::cout << "midnode:" << midnode << std::endl;
        link = forwardAlgo->getInComeLink(midnode);
        while( link!=NULL){
            q.push_front(link->getIndex());
            node = link->getNodeFromIndex();
            link = forwardAlgo->getInComeLink(node);
        }

        link = backwardAlgo->getInComeLink(midnode);
        if(link!=NULL){
            node = link->getNodeToIndex();
            while( link!=NULL){
                q.push_back(link->getIndex());
                link = backwardAlgo->getInComeLink(node);
                if(link==NULL)break;
                node = link->getNodeToIndex();
            }
        }


    }
    //std::cout << "queue" << std::endl;
    //for(size_t i =0;i < q.size();i++){
    //    std::cout << q[i] << " ";
    //}
    //std::cout << std::endl;
    // collect paths from both algo

    // build path and dist
    FPType dist = 0;
    for(size_t i = 0; i < q.size(); i++){
        link = _netPointer->getLink(q[i]);
        _nodeList[link->getNodeToIndex()].linkIndex = link->getIndex();
        dist += link->getTime();
        _nodeList[link->getNodeToIndex()].dist = dist;
    }
    _nodeList[originIndex].dist = 0;

    //for(int i = 0; i<_nbNodes; i++){
    //    std::cout << _nodeList[i].linkIndex << " ";
    //}
    //std::cout << std::endl;
    //for(int i = 0; i<_nbNodes; i++){
    //    std::cout << _nodeList[i].dist << " ";
    //}
    //std::cout << std::endl;
    //




}
