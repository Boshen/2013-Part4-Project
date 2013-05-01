#ifndef _SH_PATH_DIJKSTRA_
#define _SH_PATH_DIJKSTRA_

#include <cmath>
#include <iostream>
#include "ShPathInterface.h"

template <typename PriorityQueue>
class ShPathDijkstra : public ShPathInterface {
    private:
        typedef typename PriorityQueue::handle_type handle_t;
        PriorityQueue *Queue;
        std::vector<handle_t> *ValueKeys;
        std::vector<Label> *Labels;

    public:
        ShPathDijkstra<PriorityQueue>(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new PriorityQueue();
            ValueKeys = new std::vector<handle_t>(_nNodes);
            Labels = new std::vector<Label>(_nNodes);

        }

        ~ShPathDijkstra(){
            delete Queue;
            delete ValueKeys;
            delete Labels;

        }

        void calculate(int O) {
            calculate(O, -1);
        }

        /*
           use increase key with negative dist value,
           boost heaps are max heaps, and Fibonacci Heaps have O(1)
           increase key
https://github.com/stegua/MyBlogEntries/blob/master/Dijkstra/dijkstra.cc
*/
        void calculate(int O, int D) {

            initNodes();

            PriorityQueue& Q = *Queue;
            std::vector<handle_t>& K = *ValueKeys;
            std::vector<Label>& L = *Labels;
            std::vector<nodeInfo>& N = *Nodes;

            Q.clear();
            for(int i = 0; i < _nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().u;
                L[u] = LABELED;
                //FPType Du = N[u].dist;
                FPType Du = -(*K[u]).d;
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
                            if( L[v] == UNREACHED ){
                                L[v] = SCANNED;
                                K[v] = Q.push(ValueKey(v, -Duv));
                            }else if( L[v] == SCANNED){
                                Q.increase(K[v], ValueKey(v, -Duv));
                            }
                        }
                    } // for each outgoing link
                } // if can visit node
            } // while !Q.empty()
        }

};

#endif
