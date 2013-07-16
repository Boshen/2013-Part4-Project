#include "LabelCorrectingAl.h"

#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <limits>

LabelCorrectingAl::LabelCorrectingAl(StarNetwork *netPointer) : _netPointer(netPointer), _originIndex(-1) {
    _nbNodes = _netPointer->getNbNodes();
    _nodeList = new nodeInfo[_nbNodes];
    for (int i = 0; i < _nbNodes; i++) {
        _nodeList[i].dist = 0.0;
        //_nodeList[i].index = -1;
        _nodeList[i].linkIndex = -1;
    }

    fScanned = new std::vector<std::pair<int,int> >();

}

LabelCorrectingAl::~LabelCorrectingAl(){
    delete[] _nodeList;
    delete fScanned;
}

FPType LabelCorrectingAl::getCost(int destIndex) const{
    assert((destIndex >= 0) && (destIndex < _nbNodes));
    return _nodeList[destIndex].dist;	
}

StarLink* LabelCorrectingAl::getInComeLink(int destIndex) const {
    assert((destIndex >= 0) && (destIndex < _nbNodes));
    int linkIndex = _nodeList[destIndex].linkIndex;
    if (linkIndex == -1) return NULL;
    return _netPointer->getLink(linkIndex); 
}

int LabelCorrectingAl::getCurrentOrigin() const {
    return _originIndex;
} 

void LabelCorrectingAl::calculate(int originIndex){

    fScanned->clear();

    // initialization
    _originIndex = originIndex;

    int sequenceList[_nbNodes + 1]; // +1 - because we have one additional pointer:
    // sequenceList[_nbNodes+1] - contains the index of the current 
    // last node in the sequenceList
    int firstInSequence = -1;
    sequenceList[0] = -1;
    for (int i = 0; i < _nbNodes; i++){
        _nodeList[i].dist = std::numeric_limits<FPType>::max();
        _nodeList[i].linkIndex = -1;
        sequenceList[i + 1] = -1;
    }
    _nodeList[originIndex].dist = 0.0;
    firstInSequence = originIndex; 
    sequenceList[originIndex] = _nbNodes;
    sequenceList[_nbNodes + 1] = originIndex;

    int topNode = -1;
    StarLink *nextLink = NULL;
    StarNode *curNode = NULL;
    int nextNodeIndex = -1;
    FPType distToNextNode = 0;

    // main loop
    while (firstInSequence != _nbNodes) { // while sequence list is not empty

        topNode = firstInSequence; 
        curNode = _netPointer->beginNode(topNode);
        distToNextNode = 0;
        nextNodeIndex = -1;

        if ((curNode != NULL) && (!curNode->getIsZone() || (topNode == originIndex))) { //
            for (nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {

                nextNodeIndex = nextLink->getNodeToIndex();

                distToNextNode = _nodeList[topNode].dist + nextLink->getTime(); 
                if ( distToNextNode < _nodeList[nextNodeIndex].dist) { 
                    _nodeList[nextNodeIndex].dist = distToNextNode;
                    _nodeList[nextNodeIndex].linkIndex = nextLink->getIndex(); 
                    fScanned->push_back(std::make_pair(topNode, nextNodeIndex));
                    if (sequenceList[nextNodeIndex] < 0) { // nextNode is not on sequenceList
                        if (sequenceList[nextNodeIndex] == -1) { // nextNode has never been on sequenceList
                            // place nextNode on the bottom of sequenceList
                            sequenceList[nextNodeIndex] = _nbNodes; // nextNode is the last in sequenceList
                            sequenceList[sequenceList[_nbNodes + 1]] = nextNodeIndex; // previously last node points to nextNode now
                            sequenceList[_nbNodes + 1] = nextNodeIndex; // last pointer points to nextNodeIndex 
                        } else {
                            // place nextNode after topNode
                            sequenceList[nextNodeIndex] = sequenceList[topNode]; // nextNode now points to the node to which topNode was pointing
                            sequenceList[topNode] = nextNodeIndex; // topNodes now points to nextNode
                            if (sequenceList[nextNodeIndex] == _nbNodes) { // if topNode was the last one
                                sequenceList[_nbNodes + 1] = nextNodeIndex; // update last pointer
                            }				
                        }
                    }
                }
            }
        } 

        // topNode does not have outcoming arcs to examine
        firstInSequence = sequenceList[topNode]; 
        sequenceList[topNode] = -2;
    }


}

void LabelCorrectingAl::printScanned() {

    std::cout << "tree" << std::endl;
    for (size_t i = 0; i < fScanned->size(); i++){
        std::cout << fScanned->at(i).first << " " << fScanned->at(i).second << std::endl;
    }

}
