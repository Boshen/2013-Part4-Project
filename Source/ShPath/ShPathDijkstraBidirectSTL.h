#ifndef _SH_PATH_DIJKSTRA_BIDIRECT_STL_
#define _SH_PATH_DIJKSTRA_BIDIRECT_STL_

#include "ShPathDijkstraSTL.h"
#include "ShPathInterface.h"

// https://github.com/graphhopper/graphhopper/blob/7df6a1104a6154c54aa6ba49969badc4a14220bf/core/src/main/java/com/graphhopper/routing/AStarBidirection.java
class ShPathDijkstraBidirectSTL : public ShPathInterface {
    private:
        typedef std::vector<StarLink*> StarLinkVector;
        typedef std::map<int, StarLinkVector*> EdgeMap;
        EdgeMap *Edges; // map of star links, sort of like reverse star

        ShPath::PriorityQueue *fQueue;
        ShPath::PriorityQueue *bQueue;
        std::vector<FPType> *fDist;
        std::vector<FPType> *bDist;
        std::vector<int> *fPred;
        std::vector<int> *bPred;
        std::vector<bool> *isZone;

        ShPathDijkstraSTL *dijkstra;

        FPType fShortestDist, bShortestDist, shortestPathDist; // for stop condition
        int fShortestNode, bShortestNode, shortestPathMidNode;
    public:
        ShPathDijkstraBidirectSTL(StarNetwork* netPointer):ShPathInterface(netPointer){

            fQueue = new ShPath::PriorityQueue();
            bQueue = new ShPath::PriorityQueue();
            fDist = new std::vector<FPType>(_nNodes);
            bDist = new std::vector<FPType>(_nNodes);
            fPred = new std::vector<int>(_nNodes);
            bPred = new std::vector<int>(_nNodes);
            isZone = new std::vector<bool>(_nNodes);

            fShortestDist = bShortestDist = shortestPathDist = ShPath::FPType_Max;
            fShortestNode = bShortestNode = shortestPathMidNode = 0;

            dijkstra = new ShPathDijkstraSTL(_netPointer);
            Edges = new EdgeMap();
            EdgeMap &Edges_ = *Edges;
            std::vector<bool> &isZone_ = *isZone;
            for (int i = 0; i < _nNodes; i++){
                Edges_.insert(std::make_pair(i, new StarLinkVector()));
            }
            for (StarNode *node = _netPointer->beginNode(); node != NULL; node = _netPointer->getNextNode()) {
                for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                    Edges_[nextLink->getNodeToIndex()]->push_back(nextLink);
                }
                isZone_[node->getIndex()] = node->getIsZone();
            }
        }

        ~ShPathDijkstraBidirectSTL(){
            delete fQueue;
            delete bQueue;
            delete fDist;
            delete bDist;
            delete fPred;
            delete bPred;
            delete isZone;

            for(int i = 0; i < _nNodes; i++){
                delete (*Edges)[i];
            }
            delete Edges;

            delete dijkstra;
        }

        void calculate(int O) { 
            dijkstra->calculate(O); 
            
            std::vector<FPType> &LabelVector_ = *LabelVector;
            std::vector<int> &Predecessors_ = *Predecessors;

            for(int i = 0; i < _nNodes; i++)
                LabelVector_[i] = dijkstra->getCost(i);

            for(int i = 0; i < _nNodes; i++)
                Predecessors_[i] = dijkstra->getInComeLink(i) == NULL ? -1 : dijkstra->getInComeLink(i)->getIndex();
        }

        void initialise(int O, int D){

            initNodes();

            fShortestDist = bShortestDist = 0.0;
            fShortestNode = bShortestNode = -1;
            shortestPathDist = ShPath::FPType_Max;

            *fQueue = ShPath::PriorityQueue();
            *bQueue = ShPath::PriorityQueue();

            std::fill(fPred->begin(), fPred->end(), -1);
            std::fill(bPred->begin(), bPred->end(), -1);
            std::fill(fDist->begin(), fDist->end(), ShPath::FPType_Max);
            std::fill(bDist->begin(), bDist->end(), ShPath::FPType_Max);

            (*fDist)[O] = 0;
            (*bDist)[D] = 0;
            fQueue->push(ShPath::PQPair(0, O));
            bQueue->push(ShPath::PQPair(0, D));
        }

        void calculate(int O, int D) { 
            initialise(O, D);

            std::vector<FPType> &LabelVector_ = *LabelVector;
            std::vector<int> &Predecessors_ = *Predecessors;
            std::vector<int> &fPred_ = *fPred;
            std::vector<int> &bPred_ = *bPred;

            int finish = 0;
            while(finish < 2){
                finish = 0;
                if (!fIterate(O, D))
                    finish++;
                if (!bIterate(O, D))
                    finish++;
            }

            std::deque<int> q;
            int linkIndex = fPred_[shortestPathMidNode];
            while(linkIndex!=-1){
                q.push_front(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeFromIndex();
                linkIndex = fPred_[linkIndex];
            }
            linkIndex = bPred_[shortestPathMidNode];
            while(linkIndex!=-1){
                q.push_back(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeToIndex();
                linkIndex = bPred_[linkIndex];
            }

            FPType dist = 0.0;
            for(size_t i = 0; i < q.size(); i++){
                StarLink* link = _netPointer->getLink(q[i]);
                Predecessors_[link->getNodeToIndex()] = link->getIndex();
                dist += link->getTime();
                LabelVector_[link->getNodeToIndex()] = dist;
            }
            LabelVector_[O]= 0;


            //static int iter = 0;
            //std::cout << iter << " " << O << " " << D << " " << fScanned->size()+bScanned->size() << std::endl;
            //iter++;
        }

        bool fIterate(int O, int D){
            ShPath::PriorityQueue &fQueue_ = *fQueue;
            std::vector<FPType> &fDist_ = *fDist;
            std::vector<int> &fPred_ = *fPred;
            StarNetwork &NP = *_netPointer;

            if( fQueue->empty() )
                return false;

            int u;
            FPType Du;

            u = fQueue_.top().second;
            Du = fDist_[u];
            fQueue_.pop();

            StarNode* curNode = NP.beginNode(u);

            if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                for (StarLink *nextLink = NP.beginLink();
                        nextLink != NULL;
                        nextLink = NP.getNextLink()) {
                    int v = nextLink->getNodeToIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < fDist_[v] ){
                        fDist_[v] = Duv;
                        fPred_[v] = nextLink->getIndex();
                        fQueue_.push(ShPath::PQPair(Duv, v));
                        //fScanned->push_back(std::make_pair(u, v));
                    }
                    updateShortest(Duv, 0.0, v, D);
                }
            }
            if (checkFinishCondition())
                return false;
            return true;
        }

        bool bIterate(int O, int D){
            ShPath::PriorityQueue &bQueue_ = *bQueue;
            std::vector<FPType> &bDist_ = *bDist;
            std::vector<int> &bPred_ = *bPred;
            EdgeMap &Edges_ = *Edges;
            StarNetwork &NP = *_netPointer;

            if( bQueue->empty() )
                return false;

            int u;
            FPType Du;

            u = bQueue_.top().second;
            Du = bDist_[u];
            bQueue_.pop();

            StarNode* curNode = NP.beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == D))) {
                for (size_t j = 0; j < Edges_[u]->size(); j++){
                    StarLink *nextLink = (*Edges_[u])[j];
                    int v = nextLink->getNodeFromIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < bDist_[v]){
                        bDist_[v] = Duv;
                        bPred_[v] = nextLink->getIndex();
                        bQueue_.push(ShPath::PQPair(Duv, v));
                        //bScanned->push_back(std::make_pair(u, v));
                    }
                    updateShortest(0.0, Duv, v, O);
                }
            }
            if (checkFinishCondition())
                return false;
            return true;
        }

        // http://www.cs.princeton.edu/courses/archive/spr06/cos423/Handouts/EPP%20shortest%20path%20algorithms.pdf
        // a node from overlap may not be on the shortest path!!
        // => when scanning an arc (v, w) in the forward search and w is scanned in the reverseOrder 
        //    search, update shortest = μ if df (v) + (v, w) + dr (w) < μ            
        void updateShortest(FPType fDv, FPType bDv, int v, int dest){

            std::vector<FPType> &fDist_ = *fDist;
            std::vector<int> &fPred_ = *fPred;
            std::vector<FPType> &bDist_ = *bDist;
            std::vector<int> &bPred_ = *bPred;
            std::vector<bool> &isZone_ = *isZone;

            if (isZone_[v]) return;
            FPType newDist = ShPath::FPType_Max;

            if ((( (fDist_[v] != newDist) && bDist_[v] != newDist)) || (v ==dest)){

                int *fNode = NULL, *bNode = NULL;

                if (fDv == 0.0) { // check on backward
                    newDist = bDv + fDist_[v];
                    fNode = &(fPred_[v]);
                    bNode = &v;
                }

                if (bDv == 0.0) { // check on forward
                    newDist = fDv + bDist_[v];
                    fNode = &v;
                    bNode = &(bPred_[v]);
                }

                if (newDist < shortestPathDist){
                    shortestPathDist = newDist;
                    fShortestNode = *fNode;
                    bShortestNode = *bNode;
                    shortestPathMidNode = v;
                }
            }
        }

        bool checkFinishCondition() {
            ShPath::PriorityQueue &fQueue_ = *fQueue;
            ShPath::PriorityQueue &bQueue_ = *bQueue;
            FPType bTopDist = bQueue_.top().first;
            FPType fTopDist = fQueue_.top().first;
            return  fTopDist + bTopDist >= shortestPathDist;
        }

};


#endif
