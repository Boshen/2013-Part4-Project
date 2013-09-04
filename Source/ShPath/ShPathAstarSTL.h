#ifndef _SH_PATH_ASTAR_STL
#define _SH_PATH_ASTAR_STL

#include "ShPathInterface.h"
#include <cstdlib>

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
            StarLink *nextLink;
            StarNode *curNode;

            ShPath::PriorityQueue &Q = *Queue;
            std::vector<FPType> &L = *LabelVector;
            std::vector<int> &P = *Predecessors;
            StarNetwork &NP = *_netPointer;

            initNodes();

            Q = ShPath::PriorityQueue();

            L[O] = 0;
            Q.push(ShPath::PQPair(0, O));

            while ( !Q.empty() ){

                FPType Du = Q.top().first;
                u = Q.top().second;
                Q.pop();

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

        void calculate(int O, int D) {

            std::pair<int,int> p = std::make_pair(O, D);

            int u, v;
            FPType Duv;
            StarLink *nextLink;
            StarNode *curNode;

            ShPath::PriorityQueue &Q = *Queue;
            std::vector<FPType> &L = *LabelVector;
            std::vector<FPType> &H = *zeroFlowTimes;
            std::vector<int> &P = *Predecessors;
            StarNetwork &NP = *_netPointer;

            if( sp_tree_changed->find(p) == sp_tree_changed->end() ){
                sp_tree->insert(std::make_pair(p, new std::vector<int>()));
                sp_tree_changed->insert(std::make_pair(p, 0));
            }

            std::vector<int> &SP_TREE = (*(*sp_tree)[p]);
            int &SP_TREE_CHANGED = (*sp_tree_changed)[p];

            initNodes();
            Q = ShPath::PriorityQueue();

            /*
            if ( SP_TREE_CHANGED >= 2){ // didnt change in the last 2 iters
            //if ( SP_TREE_CHANGED == 1 && rand()/(double)RAND_MAX < 0.3){ // didnt change in the last 2 iters
                for (size_t i = 0; i < SP_TREE.size(); i++)
                    P[NP.getLink(SP_TREE[i])->getNodeToIndex()] =  SP_TREE[i];
                std::vector<int> q;
                StarLink *link = getInComeLink(D);
                while (link != NULL) {
                    q.push_back(link->getIndex());
                    link = getInComeLink(link->getNodeFromIndex());
                }

                FPType dist = 0.0;
                for(int i = q.size()-1; i >= 0; i--){
                    link = NP.getLink(q[i]);
                    dist += link->getTime();
                    L[link->getNodeToIndex()] = dist;
                }

                SP_TREE_CHANGED++;
                if (SP_TREE_CHANGED == 20){ // don't comupte SP until 15 iters reached
                    SP_TREE_CHANGED=0;
                }

                return;
            }
            */

            L[O] = 0;
            Q.push(ShPath::PQPair(0, O));

            while ( !Q.empty() ){

                u = Q.top().second;
                FPType Du = L[u];
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
                        Q.push(ShPath::PQPair(Duv + H[v*_nNodes+D], v));
                        //fScanned->push_back(std::make_pair(u, v));
                    }

                }
            }

            bool changed = false;
            std::vector<int> tmp_v;
            size_t i = 0;
            nextLink = getInComeLink(D);
            while (nextLink != NULL) {
                tmp_v.push_back(nextLink->getIndex());
                if( i >= SP_TREE.size() || NP.getLink(SP_TREE[i]) != nextLink){
                    changed = true;
                }
                nextLink = getInComeLink(nextLink->getNodeFromIndex());
                i++;
            }

            //SP_TREE_CHANGED = changed?0:SP_TREE_CHANGED+1;
            if (changed)
                SP_TREE_CHANGED += 1;
            //SP_TREE_CHANGED = 1;

            SP_TREE.clear();
            for (size_t i = 0;i<tmp_v.size();i++)
                SP_TREE.push_back(tmp_v[i]);

        }

};

#endif
