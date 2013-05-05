#ifndef _SH_PATH_ASTAR_STL
#define _SH_PATH_ASTAR_STL

#include <queue>
#include <cmath>
#include <iostream>
#include "ShPathInterface.h"

class ShPathAstarSTL : public ShPathInterface {
    private:
        class Prioritize{
            public:
                bool operator() ( const std::pair<int, FPType>& p1, const std::pair<int, FPType>& p2){
                    return p1.second > p2.second;
                }
        };

        typedef std::pair<int, FPType> PQPair;
        typedef std::priority_queue<PQPair, std::vector<PQPair>, Prioritize > PriorityQueue;
        PriorityQueue *Queue;
        //std::vector<Label> *Labels;
        std::vector<FPType> *zeroFlowTimes;

    public:

        ShPathAstarSTL(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new PriorityQueue();
            //Labels = new std::vector<Label>(_nNodes);
            zeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);


            _netPointer->calculateLinkCosts();

            for(int i = 0; i < _nNodes; i++){
                calculate(i);
                for(int j = 0; j < _nNodes; j++){
                    (*zeroFlowTimes)[i*_nNodes+j] = (*Nodes)[j].dist;
                }
            }
        }

        ~ShPathAstarSTL(){
            delete Queue;
            //delete Labels;
            delete zeroFlowTimes;
        }

        void calculate(int O) {

            initNodes();

            PriorityQueue& Q = *Queue;
            std::vector<nodeInfo>& N = *Nodes;

            while(!Q.empty()){
                Q.pop();
            }

            N[O].dist = 0;
            Q.push(PQPair(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().first;
                FPType Du = N[u].dist;
                Q.pop();

                StarNode* curNode = _netPointer->beginNode(u);

                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                        int v = nextLink->getNodeToIndex();
                        FPType Duv = Du + nextLink->getTime();

                        if ( Duv < N[v].dist ){
                            N[v].dist = Duv;
                            N[v].linkIndex = nextLink->getIndex();
                            Q.push(PQPair(v, Duv));

                        }
                    } // for each outgoing link
                } // if can visit node
            } // while !Q.empty()

        }

        void calculate(int O, int D) {
            Scanned->clear();

            initNodes();

            PriorityQueue& Q = *Queue;
            std::vector<nodeInfo>& N = *Nodes;
            //std::vector<Label>& L = *Labels;
            std::vector<FPType>& H = *zeroFlowTimes;

            while(!Q.empty()){
                Q.pop();
            }

            //for(int i = 0; i < _nNodes; i++){
            //    L[i] = UNREACHED;
            //}

            N[O].dist = 0;
            Q.push(PQPair(O, H[O*_nNodes+D]));
            while ( !Q.empty() ){
                int u = Q.top().first;
                FPType Du = N[u].dist;
                //L[u] = LABELED;
                Q.pop();

                if ( u == D ){ 
                    break;
                }

                StarNode* curNode = _netPointer->beginNode(u);

                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                        int v = nextLink->getNodeToIndex();
                        FPType Duv = Du + nextLink->getTime();
                        if ( Duv < N[v].dist ){
                            N[v].dist = Duv;
                            N[v].linkIndex = nextLink->getIndex();
                            Q.push(PQPair(v, Duv + H[v*_nNodes+D]));
                            Scanned->push_back(std::pair<int, int>(u, v));
                        }
                    } // for each outgoing link
                } // if can visit node
            } // while !Q.empty()
        }

};

#endif
