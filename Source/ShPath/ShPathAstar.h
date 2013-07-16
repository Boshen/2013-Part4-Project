#ifndef _SH_PATH_A_STAR_
#define _SH_PATH_A_STAR_

#include "ShPathInterface.h"


template <typename PriorityQueue>
class ShPathAstar : public ShPathInterface {
    private:
        typedef typename PriorityQueue::handle_type handle_t;

        PriorityQueue *Queue;
        std::vector<handle_t> *ValueKeys;
        // cost from initialised network
        // 1d vector stroing 2d data for faster access
        // access by zeroFlowTimes[fromNode*_nNodes+toNode]
        std::vector<FPType> *zeroFlowTimes;

    public:
        ShPathAstar<PriorityQueue>(StarNetwork* netPointer):ShPathInterface(netPointer){

            Queue = new PriorityQueue();
            ValueKeys = new std::vector<handle_t>(_nNodes);
            zeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);

            _netPointer->calculateLinkCosts();

            for(int i = 0; i < _nNodes; i++){
                calculate(i);
                for(int j = 0; j < _nNodes; j++){
                    (*zeroFlowTimes)[i*_nNodes+j] = (*LabelVector)[j];
                }
            }

        }

        ~ShPathAstar(){
            delete Queue;
            delete ValueKeys;
            delete zeroFlowTimes;
        }

        void calculate(int O) {

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

                        L[v] = Duv;
                        P[v] = nextLink->getIndex();
                    }
                } 
            } 
        }

        /*
           use increase key with negative dist value,
           boost heaps are max heaps, and Fibonacci Heaps have O(1)
           increase key
https://github.com/stegua/MyBlogEntries/blob/master/Dijkstra/dijkstra.cc
*/
        void calculate(int O, int D) {

            int u, v;
            FPType Du, Duv, Huv;
            StarLink *nextLink;
            StarNode *curNode;

            PriorityQueue &Q = *Queue;
            std::vector<handle_t> &K = *ValueKeys;
            std::vector<FPType> &L = *LabelVector;
            std::vector<FPType> &H = *zeroFlowTimes;
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

                if(u == D){
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

                        Huv = Duv + H[v*_nNodes+D];

                        if( LB[v] == UNREACHED ){
                            K[v] = Q.push(ShPath::ValueKey(-Huv, v));
                            LB[v] = SCANNED;
                            fScanned->push_back(std::make_pair(u, v));
                        }else if (LB[v] == SCANNED){
                            Q.increase(K[v], ShPath::ValueKey(-Huv, v));
                        }

                        L[v] = Duv;
                        P[v] = nextLink->getIndex();
                    }
                } 
            } 
        }

};

#endif

