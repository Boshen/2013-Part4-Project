#ifndef _SH_PATH_DIJKSTRA_STL_
#define _SH_PATH_DIJKSTRA_STL_

#include "ShPathInterface.h"
#include "../Path.h"

class ShPathDijkstraSTL : public ShPathInterface {
    private:
        ShPath::PriorityQueue *Queue;


    public:
        ShPathDijkstraSTL(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new ShPath::PriorityQueue();
        }

        ~ShPathDijkstraSTL(){
            delete Queue;
        }

        void calculate(int O) {
            calculate(O, -1);
        }

        void calculate(int O, int D) {
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
                        Q.push(ShPath::PQPair(Duv, v));
                    }
                } 
            } 

        }

};

#endif
