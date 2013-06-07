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
            StarLink *nextLink;
            StarNode *curNode;

            PriorityQueue &Q = *Queue;
            std::vector<handle_t> &K = *ValueKeys;
            std::vector<FPType> &L = *LabelVector;
            std::vector<int> &P = *Predecessors;
            std::vector<Label> &LB = *Labels;
            StarNetwork &NP = *_netPointer;

            initNodes();
            Q.clear();
            std::fill(LB.begin(), LB.end(), UNREACHED);

            L[O] = 0;
            K[O] = Q.push(ShPath::ValueKey(0, O));

            while ( !Q.empty() ){

                u = Q.top().u;
                Du = L[u];
                Q.pop();
                LB[u] = LABELED;

                if ( u == D )
                    break;

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

                        if( LB[v] == UNREACHED ){
                            K[v] = Q.push(ShPath::ValueKey(-Duv, v));
                            LB[v] = SCANNED;
                        }else if (LB[v] == SCANNED){
                            Q.increase(K[v], ShPath::ValueKey(-Duv, v));
                        }

                        L[v]  = Duv;
                        P[v] = nextLink->getIndex();
                    }

                } 
            } 
        }

};

#endif
