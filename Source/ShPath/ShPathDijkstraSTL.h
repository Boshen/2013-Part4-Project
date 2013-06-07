#ifndef _SH_PATH_DIJKSTRA_STL_
#define _SH_PATH_DIJKSTRA_STL_

#include "ShPathInterface.h"

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
            StarLink *nextLink;
            StarNode *curNode;

            ShPath::PriorityQueue &Q = *Queue;
            std::vector<FPType> &L = *LabelVector;
            std::vector<int> &P = *Predecessors;
            StarNetwork &NP = *_netPointer;

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
                        Q.push(ShPath::PQPair(Duv, v));
                    }

                } 
            } 

        }

};

#endif
