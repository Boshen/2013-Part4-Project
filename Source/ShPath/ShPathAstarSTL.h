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


            int u, v;
            FPType Duv;
            StarLink *nextLink;
            StarNode *curNode;

            ShPath::PriorityQueue &Q = *Queue;
            std::vector<FPType> &L = *LabelVector;
            std::vector<FPType> &H = *zeroFlowTimes;
            std::vector<int> &P = *Predecessors;
            StarNetwork &NP = *_netPointer;

            std::pair<int,int> p = std::make_pair(O,D);
            if( sp_tree->find(p) == sp_tree->end()){
                sp_tree->insert(std::make_pair(p, new std::vector<int>()));
            }else{

                FPType dist = 0;
                for(size_t i = 0; i < (*sp_tree)[p]->size() ;i++){

                    dist += NP.getLink((*sp_tree)[p]->at(i))->getTime();
                }
                //if (abs(dist-(*sp_tree_dist)[p]) < 1e-6){
                //    
                //}
                std::cout << O << " " << D << " " << dist << " " << (*sp_tree_dist)[p] << std::endl;

            }

            initNodes();
            Q = ShPath::PriorityQueue();

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

            //std::cout << O << " " << D << " " << fScanned->size() << std::endl;
            /*

            if( sp_tree->find(p) == sp_tree->end()){
                sp_tree->insert(std::make_pair(p, new std::vector<int>()));
                sp_tree_changed->insert(std::make_pair(p, 0));
            }else{

                size_t i = 0;
                StarLink *link = getInComeLink(D);
                int nextDest = link->getNodeFromIndex();
                //std::cout << O << " " << D << std::endl;
                while (link != NULL) {
                    //std::cout << nextDest << " " << (*sp_tree)[p]->at(i) << " ";
                    if((*sp_tree)[p]->at(i) != nextDest || i > (*sp_tree)[p]->size()){
                        (*sp_tree_changed)[p]++;
                        //std::cout << "changed" << std::endl;
                        break;
                    }
                    nextDest = link->getNodeFromIndex();
                    link = getInComeLink(nextDest);
                    i++;
                }
                //std::cout << std::endl;

            }
            */

            (*sp_tree)[p]->clear();
            StarLink *link = getInComeLink(D);
            int nextDest = link->getNodeFromIndex();
            FPType dist = 0;
            while (link != NULL) {
                dist += link->getTime();
                (*sp_tree)[p]->push_back(link->getIndex());
                nextDest = link->getNodeFromIndex();
                link = getInComeLink(nextDest);
            }
            sp_tree_dist->insert(std::make_pair(p, dist));
        }

};

#endif
