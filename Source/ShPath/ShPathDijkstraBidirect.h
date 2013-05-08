#ifndef _SH_PATH_DIJKSTRA_BIDIRECT_
#define _SH_PATH_DIJKSTRA_BIDIRECT_

#include <cmath>
#include <iostream>
#include <set>
#include <deque>
#include <map>
#include "ShPathDijkstraSTL.h"
#include "ShPathInterface.h"

// https://github.com/graphhopper/graphhopper/blob/7df6a1104a6154c54aa6ba49969badc4a14220bf/core/src/main/java/com/graphhopper/routing/AStarBidirection.java
template <class PriorityQueue>
class ShPathDijkstraBidirect : public ShPathInterface {
    private:
        typedef class PriorityQueue::handle_type handle_t;
        typedef std::vector<StarLink*> StarLinkVector;
        typedef std::map<int, StarLinkVector*> EdgeMap;
        EdgeMap *Edges; // map of star links, sort of like reverse star

        PriorityQueue *fQueue;
        PriorityQueue *bQueue;
        std::vector<handle_t> *fValueKeys;
        std::vector<handle_t> *bValueKeys;
        std::vector<Label> *fLabels;
        std::vector<Label> *bLabels;
        std::vector<FPType> *fDist;
        std::vector<FPType> *bDist;
        std::vector<int> *fPred;
        std::vector<int> *bPred;
        std::vector<bool> *isZone;

        ShPathDijkstraSTL *dijkstra;

        FPType fShortestDist, bShortestDist, shortestPathDist; // for stop condition
        int fShortestNode, bShortestNode;
        int shortestPathMidNode;
    public:
        ShPathDijkstraBidirect<PriorityQueue>(StarNetwork* netPointer):ShPathInterface(netPointer){
            fQueue = new PriorityQueue();
            bQueue = new PriorityQueue();
            fValueKeys = new std::vector<handle_t>(_nNodes);
            bValueKeys = new std::vector<handle_t>(_nNodes);
            fLabels = new std::vector<Label>(_nNodes);
            bLabels = new std::vector<Label>(_nNodes);
            fDist = new std::vector<FPType>(_nNodes);
            bDist = new std::vector<FPType>(_nNodes);
            fPred = new std::vector<int>(_nNodes);
            bPred = new std::vector<int>(_nNodes);
            isZone = new std::vector<bool>(_nNodes);

            dijkstra = new ShPathDijkstraSTL(_netPointer);
            Edges = new EdgeMap();
            for (int i = 0; i < _nNodes; i++){
                Edges->insert(std::make_pair(i, new StarLinkVector()));
            }
            for (StarNode *node = _netPointer->beginNode(); node != NULL; node = _netPointer->getNextNode()) {
                for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                    (*Edges)[nextLink->getNodeToIndex()]->push_back(nextLink);
                }
                isZone->at(node->getIndex()) = node->getIsZone();
            }
        }

        ~ShPathDijkstraBidirect(){
            delete fQueue;
            delete bQueue;
            delete fValueKeys;
            delete bValueKeys;
            delete fLabels;
            delete bLabels;
            delete fDist;
            delete bDist;
            delete fPred;
            delete bPred;
            delete isZone;
            for(int i = 0; i < _nNodes; i++){
                delete (*Edges)[i];
            }
            delete Edges;

            delete dijkstra;
        }

        void calculate(int O) { 
            dijkstra->calculate(O); 
            for(int i = 0; i < _nNodes; i++){
                (*Nodes)[i].dist = dijkstra->getCost(i);
                if(dijkstra->getInComeLink(i) == NULL)
                    (*Nodes)[i].linkIndex = -1;
                else
                    (*Nodes)[i].linkIndex = dijkstra->getInComeLink(i)->getIndex();
            }
        }

        void initialise(int O, int D){
            initNodes();

            fShortestDist = bShortestDist = 0.0;
            fShortestNode = bShortestNode = -1;
            shortestPathDist = std::numeric_limits<FPType>::max();

            fQueue->clear();
            bQueue->clear();

            for(int i = 0; i < _nNodes; i++){
                fLabels->at(i) = UNREACHED;
                bLabels->at(i) = UNREACHED;
                fPred->at(i) = -1;
                bPred->at(i) = -1;
                fDist->at(i) = std::numeric_limits<FPType>::max();
                bDist->at(i) = std::numeric_limits<FPType>::max();
            }

            fDist->at(O) = 0;
            bDist->at(D) = 0;
            fValueKeys->at(O) = fQueue->push(ValueKey(O, 0));
            bValueKeys->at(D) = bQueue->push(ValueKey(D, 0));
        }

        void calculate(int O, int D) { 
            //std::cout << O << " " << D << std::endl;
            initialise(O, D);

            int finish = 0;
            while(finish < 2){
                finish = 0;
                if (!fIterate(O, D))
                    finish++;
                if (!bIterate(O, D))
                    finish++;
            }
            //std::cout << fShortestNode << " " << bShortestNode << std::endl;

            std::deque<int> q;
            int linkIndex = fPred->at(shortestPathMidNode);
            //std::cout << linkIndex << " ";
            while(linkIndex!=-1){
                q.push_front(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeFromIndex();
                linkIndex = fPred->at(linkIndex);
            }
            linkIndex = bPred->at(shortestPathMidNode);
            //std::cout << linkIndex << " ";
            while(linkIndex!=-1){
                q.push_back(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeToIndex();
                linkIndex = bPred->at(linkIndex);
            }

            FPType dist = 0.0;
            //std::cout << ">> " << O << " " << D << std::endl;
            for(size_t i = 0; i < q.size(); i++){
                StarLink* link = _netPointer->getLink(q[i]);
                Nodes->at(link->getNodeToIndex()).linkIndex = link->getIndex();
                dist += link->getTime();
                Nodes->at(link->getNodeToIndex()).dist = dist;
                //std::cout << link->getNodeToIndex() << " ";
            }
            //std::cout << std::endl;;
            Nodes->at(O).dist = 0;
            //for(size_t i=0;i<Nodes->size();i++){
            //    std::cout << Nodes->at(i).linkIndex << " ";

            //}
            //std::cout << std::endl;;
            /*
            StarLink *link = getInComeLink(D);
            FPType nextDest = link->getNodeFromIndex();
            Path path;
            while (link != NULL) {
                path.addLinkToPath(link);
                nextDest = link->getNodeFromIndex();
                link = getInComeLink(nextDest);
            }
            path.print();
            */


        }

        bool fIterate(int O, int D){
            if( fQueue->empty() )
                return false;

            int u = (fQueue->top()).u;
            fLabels->at(u) = LABELED;
            FPType Du = fDist->at(u);
            fQueue->pop();

            StarNode* curNode = _netPointer->beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                    int v = nextLink->getNodeToIndex();
                    if(v==u)continue;
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < fDist->at(v) ){
                        fDist->at(v) = Duv;
                        fPred->at(v) = nextLink->getIndex();
                        if( fLabels->at(v) == UNREACHED ){
                            fLabels->at(v) = SCANNED;
                            fValueKeys->at(v) = fQueue->push(ValueKey(v, -Duv));
                        }else if( fLabels->at(v) == SCANNED){
                            fQueue->increase(fValueKeys->at(v), ValueKey(v, -Duv));
                        }
                    }
                    //std::cout << "fiterate " << u << " " << v << " " << Duv <<  std::endl;
                    updateShortest(Duv, 0.0, v, D);
                } // for each outgoing link
            } // if can visit node
            if (checkFinishCondition())
                return false;
            return true;
        }

        bool bIterate(int O, int D){
            if( bQueue->empty() )
                return false;

            int u = (bQueue->top()).u;
            bLabels->at(u) = LABELED;
            FPType Du = bDist->at(u);
            bQueue->pop();

            StarNode* curNode = _netPointer->beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == D))) {
                for (size_t j = 0; j < Edges->at(u)->size(); j++){
                    StarLink *nextLink = Edges->at(u)->at(j);
                    int v = nextLink->getNodeFromIndex();
                    if(v==u)continue;
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < bDist->at(v)){
                        bDist->at(v) = Duv;
                        bPred->at(v) = nextLink->getIndex();
                        if( bLabels->at(v) == UNREACHED ){
                            bLabels->at(v) = SCANNED;
                            bValueKeys->at(v) = bQueue->push(ValueKey(v, -Duv));
                        }else if( bLabels->at(v) == SCANNED){
                            bQueue->increase(bValueKeys->at(v), ValueKey(v, -Duv));
                        }
                    }
                    //std::cout << "biterate " << u << " " << v << " " << Duv << std::endl;
                    updateShortest(0.0, Duv, v, O);
                } // for each outgoing link
            } // if can visit node
            if (checkFinishCondition())
                return false;
            return true;
        }

        // http://www.cs.princeton.edu/courses/archive/spr06/cos423/Handouts/EPP%20shortest%20path%20algorithms.pdf
        // a node from overlap may not be on the shortest path!!
        // => when scanning an arc (v, w) in the forward search and w is scanned in the reverseOrder 
        //    search, update shortest = μ if df (v) + (v, w) + dr (w) < μ            
        void updateShortest(FPType fDv, FPType bDv, int v, int dest){
            if (isZone->at(v) )return;
            if (((fLabels->at(v) == SCANNED) && (bLabels->at(v) == SCANNED)) || (v ==dest)){
                FPType newDist = std::numeric_limits<FPType>::max();
                int *fNode = NULL, *bNode = NULL;
                if (fDv == 0.0) { // check on backward
                    newDist = bDv + fDist->at(v);
                    fNode = &(fPred->at(v));
                    bNode = &v;
                }

                if (bDv == 0.0) { // check on forward
                    newDist = fDv + bDist->at(v);
                    fNode = &v;
                    bNode = &bPred->at(v);
                }

                if (newDist < shortestPathDist){
                    shortestPathDist = newDist;
                    fShortestNode = *fNode;
                    bShortestNode = *bNode;
                    shortestPathMidNode = v;
                    //std::cout << v<< " " << fShortestNode << " " << bShortestNode << " " << shortestPathDist << std::endl;
                }
            }
        }

        bool checkFinishCondition() {
            FPType bTopDist = -(bQueue->top()).d;
            FPType fTopDist = -(fQueue->top()).d;
            return  fTopDist + bTopDist >= shortestPathDist;
        }
};


#endif

