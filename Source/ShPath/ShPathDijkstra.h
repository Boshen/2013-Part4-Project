#ifndef _SH_PATH_DIJKSTRA_
#define _SH_PATH_DIJKSTRA_

#include "ShPathInterface.h"

template <typename PriorityQueue>
class ShPathDijkstra : public ShPathInterface {
    private:
        typedef typename PriorityQueue::handle_type handle_t;
        PriorityQueue *Queue;
        std::vector<handle_t> *ValueKeys;

    public:
        ShPathDijkstra<PriorityQueue>(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new PriorityQueue();
            ValueKeys = new std::vector<handle_t>(_nNodes);
        }

        ~ShPathDijkstra(){
            delete Queue;
            delete ValueKeys;
        }

        void calculate(int O) {
            calculate(O, -1);
        }

        void calculate(int O, int D) {

            int u, v;
            FPType Du, Duv;
            PriorityQueue& Q = *Queue;
            std::vector<handle_t>& K = *ValueKeys;
            std::vector<FPType>& L = *LabelVector;
            std::vector<int>& P = *Predecessors;

            initNodes();
            Q.clear();

            L[O] = 0;
            K[O] = Q.push(ShPath::ValueKey(0, O));
            while ( !Q.empty() ){
                u = Q.top().u;
                Du = -(*K[u]).d;
                Q.pop();

                if ( u == D )
                    break;

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
                        if( L[v] != ShPath::FPType_Max){
                            Q.increase(K[v], ShPath::ValueKey(-Duv, v));
                        }else{
                            K[v] = Q.push(ShPath::ValueKey(-Duv, v));
                        }
                        L[v]  = Duv;
                        P[v] = nextLink->getIndex();
                    }
                } 
            } 
        }

};

#endif
