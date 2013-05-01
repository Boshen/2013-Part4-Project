#ifndef _SH_PATH_A_STAR_
#define _SH_PATH_A_STAR_

#include <cmath>
#include <iostream>
#include "ShPathInterface.h"


template <typename PriorityQueue>
class ShPathAstar : public ShPathInterface {
    private:
        typedef typename PriorityQueue::handle_type handle_t;
        PriorityQueue *Queue;
        std::vector<handle_t> *ValueKeys;
        std::vector<Label> *Labels;
        // cost from initialised network
        // 1d vector stroing 2d data for faster access
        // access by zeroFlowTimes[fromNode*_nNodes+toNode]
        std::vector<FPType> *zeroFlowTimes;

    public:
        ShPathAstar<PriorityQueue>(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new PriorityQueue();
            ValueKeys = new std::vector<handle_t>(_nNodes);
            Labels = new std::vector<Label>(_nNodes);
            zeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);

            _netPointer->calculateLinkCosts();

            for(int i = 0; i < _nNodes; i++){
                calculate(i);
                for(int j = 0; j < _nNodes; j++){
                    (*zeroFlowTimes)[i*_nNodes+j] = (*Nodes)[j].dist;
                }
            }
            //std::cout << "heuristic function setup complete" << std::endl;
        }

        ~ShPathAstar(){
            delete Queue;
            delete ValueKeys;
            delete Labels;
            delete zeroFlowTimes;

        }

        void calculate(int O) {

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
            std::vector<FPType>& H = *zeroFlowTimes;
            std::vector<nodeInfo>& N = *Nodes;

            Q.clear();
            for(int i = 0; i < _nNodes; i++){
                L[i] = UNREACHED;
            }

            //std::cout << O << " " << D << std::endl;
            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, -H[O*_nNodes+D]));
            //K[O] = Q.push(ValueKey(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().u;
                L[u] = LABELED;
                FPType Du = N[u].dist;

                //if(O == 0 && D == 10)
                //std::cout << "pop " << u << " | dist "  << Du << " | Fv " << -(*K[u]).d << std::endl;
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
                            FPType Fuv = Duv + H[v*_nNodes+D];
                            if( L[v] == UNREACHED ){
                                L[v] = SCANNED;
                                K[v] = Q.push(ValueKey(v, -Fuv));
                            }else if( L[v] == SCANNED){
                                Q.increase(K[v], ValueKey(v, -Fuv));
                            }
                        }
                    } // for each outgoing link
                    //            if(O == 0 && D == 10)
                    //std::cout << std::endl;
                } // if can visit node
            } // while !Q.empty()
        }

};

#endif

