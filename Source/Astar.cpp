#include "Astar.h"
#include <set>
#include <algorithm>

void Astar::initNodes(){
    static const FPType FPType_Max = std::numeric_limits<FPType>::max();
    std::fill(LabelVector->begin(), LabelVector->end(), FPType_Max);
    std::fill(Predecessors->begin(), Predecessors->end(),  -1);
}

FPType Astar::getCost(int destIndex) const{
    assert((destIndex >= 0) && (destIndex < _nbNodes));
    return (*LabelVector)[destIndex];
}

StarLink* Astar::getInComeLink(int destIndex) const{
    assert((destIndex >= 0) && (destIndex < _nbNodes));
    int linkIndex = (*Predecessors)[destIndex];
    return  linkIndex == -1 ?  NULL :  _netPointer->getLink(linkIndex);
}

Astar::Astar(StarNetwork* netPointer, ODMatrix* _odMatrix):ShortestPath(){

    _netPointer = netPointer;
    _nbNodes = _netPointer->getNbNodes();

    Queue = new PriorityQueue();
    LabelVector = new std::vector<FPType>(_nbNodes);
    Predecessors = new std::vector<int>(_nbNodes);

    // we need to calc the zero-flow travel times from every node to the destinations,
    // we use the following code since total number of origins = total number of destinations

    // all the destinations
    std::set<int> destinations;

    for (Origin* origin = _odMatrix->beginOrigin(); origin != NULL; origin = _odMatrix->getNextOrigin()){
        for (PairOD* od = origin->beginDest(); od != NULL; od = origin->getNextDest()){
            destinations.insert(od->getIndex());
        }
    }

    // last element of set is the largest, which is the largest we have to allocate for
    _nbDests = 1+*destinations.rbegin();

    zeroFlowTimes = new std::vector<FPType>(_nbNodes*_nbDests); 
    //zeroFlowTimes = new std::vector<FPType>(_nbNodes*_nbNodes); 

    _netPointer->calculateLinkCosts();

    for(int i = 0; i < _nbNodes; i++){
        calculate(i);
        for (std::set<int>::iterator it=destinations.begin(); it!=destinations.end(); ++it){
            zeroFlowTimes->at(i*_nbDests+*it) = LabelVector->at(*it);
        }
        //for(int j = 0; j < _nbNodes; j++){
        //    zeroFlowTimes->at(i*_nbNodes+j) = LabelVector->at(j);
        //}

    }

}

Astar::~Astar(){
    delete Queue;
    delete zeroFlowTimes;
    delete LabelVector;
    delete Predecessors;
}

void Astar::calculate(int O) {

    int u, v;
    FPType Duv;
    StarLink *nextLink;
    StarNode *curNode;

    PriorityQueue &Q = *Queue;
    std::vector<FPType> &L = *LabelVector;
    std::vector<int> &P = *Predecessors;
    StarNetwork &NP = *_netPointer;

    initNodes();

    Q = PriorityQueue();

    L[O] = 0;
    Q.push(PQPair(0, O));

    while ( !Q.empty() ){

        FPType Du = Q.top().first;
        u = Q.top().second;
        Q.pop();

        curNode = NP.beginNode(u);

        if (curNode == NULL)
            continue;

        if (curNode->getIsZone() && u != O)
            continue;

        for (nextLink = NP.beginLink();
                nextLink != NULL;
                nextLink = NP.getNextLink()) {

            v = nextLink->getNodeToIndex();

            Duv = Du + nextLink->getTime();

            if ( Duv < L[v] ){
                L[v] = Duv;
                P[v] = nextLink->getIndex();
                Q.push(PQPair(Duv, v));
            }

        } 
    } 

}

void Astar::calculate(int O, int D) {

    int u, v;
    FPType Duv;
    StarLink *nextLink;
    StarNode *curNode;

    PriorityQueue &Q = *Queue;
    std::vector<FPType> &L = *LabelVector;
    std::vector<FPType> &H = *zeroFlowTimes;
    std::vector<int> &P = *Predecessors;
    StarNetwork &NP = *_netPointer;

    initNodes();
    Q = PriorityQueue();

    L[O] = 0;
    Q.push(PQPair(0, O));

    while ( !Q.empty() ){

        u = Q.top().second;
        FPType Du = L[u];
        Q.pop();

        if ( u == D ){ 
            break;
        }

        curNode = NP.beginNode(u);

        if (curNode == NULL)
            continue;

        if (curNode->getIsZone() && u != O)
            continue;

        for (nextLink = NP.beginLink();
                nextLink != NULL;
                nextLink = NP.getNextLink()) {

            v = nextLink->getNodeToIndex();

            Duv = Du + nextLink->getTime();

            if ( Duv < L[v] ){
                L[v] = Duv;
                P[v] = nextLink->getIndex();
                Q.push(PQPair(Duv + H[v*_nbDests+D], v));
            }

        }
    }
}

