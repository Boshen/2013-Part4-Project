#ifndef _SH_PATH_DIJKSTRA_SET_
#define _SH_PATH_DIJKSTRA_SET_

#include <set>
#include <cmath>
#include <iostream>
#include "ShPathInterface.h"
#include "../Path.h"

class ShPathDijkstraSet : public ShPathInterface {
    private:

        typedef std::set<ShPath::PQPair> PriorityQueue;
        PriorityQueue *Queue;


    public:
        ShPathDijkstraSet(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new PriorityQueue();

        }

        ~ShPathDijkstraSet(){
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

            std::vector<FPType> &L = *LabelVector;
            std::vector<int> &P = *Predecessors;
            PriorityQueue &Q = *Queue;
            StarNetwork &NP = *_netPointer;

            initNodes();
            Q.clear();

            L[O] = 0;
            Q.insert(ShPath::PQPair(0, O));

            while ( !Q.empty() ){
                u = Q.begin()->second;
                FPType Du = Q.begin()->first;
                Q.erase(Q.begin());

                if ( u == D ){ 
                    break;
                }

                curNode = NP.beginNode(u);

                if (curNode == NULL)
                    continue;

                if (curNode->getIsZone())
                    continue;

                for (nextLink = NP.beginLink(); 
                        nextLink != NULL;
                        nextLink = NP.getNextLink()) {
                    v = nextLink->getNodeToIndex();

                    Duv = Du + nextLink->getTime();

                    if ( Duv < L[v] ){

                        if (L[v] != ShPath::FPType_Max){
                            Q.erase(ShPath::PQPair(L[v], v));
                        }

                        L[v] = Duv;
                        P[v] = nextLink->getIndex();
                        Q.insert(ShPath::PQPair(Duv, v));
                    }

                } 
            } 
        }

};

#endif
