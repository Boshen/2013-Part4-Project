#ifndef _SH_PATH_ASTAR_STL
#define _SH_PATH_ASTAR_STL

#include "ShPathInterface.h"

class ShPathAstarSTL : public ShPathInterface {
    private:
        ShPath::PriorityQueue *Queue;
        std::vector<FPType> *zeroFlowTimes;
    public:
        ShPathAstarSTL(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new ShPath::PriorityQueue();
            zeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);

            _netPointer->calculateLinkCosts();

            for(int i = 0; i < _nNodes; i++){
                calculate(i);
                for(int j = 0; j < _nNodes; j++){
                    zeroFlowTimes->at(i*_nNodes+j) = LabelVector->at(j);
                }
            }
        }

        ~ShPathAstarSTL(){
            delete Queue;
            delete zeroFlowTimes;
        }

        void calculate(int O) {
            int u, v;
            FPType Duv;
            std::vector<FPType>& L = *LabelVector;
            std::vector<int>& P = *Predecessors;
            ShPath::PriorityQueue& Q = *Queue;

            initNodes();

            Q = ShPath::PriorityQueue(); // clear

            L[O] = 0;
            Q.push(ShPath::PQPair(0, O));

            while ( !Q.empty() ){

                FPType Du = Q.top().first;
                u = Q.top().second;
                Q.pop();

                StarNode* curNode = _netPointer->beginNode(u);

                if (curNode == NULL)
                    continue;
                if (curNode->getIsZone() && u != O)
                    continue;

                for (StarLink *nextLink = _netPointer->beginLink();
                        nextLink != NULL;
                        nextLink = _netPointer->getNextLink()) {

                    v = nextLink->getNodeToIndex();

                    if(v==u)continue;

                    Duv = Du + nextLink->getTime();

                    if ( Duv < L[v] ){
                        L[v] = Duv;
                        P[v] = nextLink->getIndex();
                        Q.push(ShPath::PQPair(Duv, v));
                    }

                } 
            } 

        }

        void calculate(int O, int D) {
            int u, v;
            FPType Duv;
            std::vector<FPType>& L = *LabelVector;
            std::vector<int>& P = *Predecessors;
            ShPath::PriorityQueue& Q = *Queue;
            std::vector<FPType>& H = *zeroFlowTimes;

            initNodes();
            Q = ShPath::PriorityQueue(); // clear

            L[O] = 0;
            Q.push(ShPath::PQPair(0, O));

            while ( !Q.empty() ){

                u = Q.top().second;
                FPType Du = L[u];
                Q.pop();

                if ( u == D ){ 
                    break;
                }

                StarNode* curNode = _netPointer->beginNode(u);

                if (curNode == NULL)
                    continue;
                if (curNode->getIsZone() && u != O)
                    continue;

                for (StarLink *nextLink = _netPointer->beginLink();
                        nextLink != NULL;
                        nextLink = _netPointer->getNextLink()) {
                    v = nextLink->getNodeToIndex();

                    if(v==u)continue;

                    Duv = Du + nextLink->getTime();

                    if ( Duv < L[v] ){
                        L[v] = Duv;
                        P[v] = nextLink->getIndex();
                        Q.push(ShPath::PQPair(Duv + H[v*_nNodes+D], v));
                    }

                }
            }
        }

};

#endif
