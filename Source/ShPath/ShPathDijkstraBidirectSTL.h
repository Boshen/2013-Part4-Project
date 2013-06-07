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
            for (int i = 0; i < _nNodes; i++){
                Edges->insert(std::make_pair(i, new StarLinkVector()));
            }
            for (StarNode *node = _netPointer->beginNode(); node != NULL; node = _netPointer->getNextNode()) {
                for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                    (*Edges)[nextLink->getNodeToIndex()]->push_back(nextLink);
                }
                isZone->at(node->getIndex()) = node->getIsZone();
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

            for(int i = 0; i < _nNodes; i++)
                LabelVector->at(i) = dijkstra->getCost(i);
            
            for(int i = 0; i < _nNodes; i++)
                Predecessors->at(i) = dijkstra->getInComeLink(i) == NULL ? -1 : dijkstra->getInComeLink(i)->getIndex();
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

            fDist->at(O) = 0;
            bDist->at(D) = 0;
            fQueue->push(ShPath::PQPair(0, O));
            bQueue->push(ShPath::PQPair(0, D));
        }

        void calculate(int O, int D) { 
            initialise(O, D);

            int finish = 0;
            while(finish < 2){
                finish = 0;
                if (!fIterate(O, D))
                    finish++;
                if (!bIterate(O, D))
                    finish++;
            }

            std::deque<int> q;
            int linkIndex = fPred->at(shortestPathMidNode);
            while(linkIndex!=-1){
                q.push_front(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeFromIndex();
                linkIndex = fPred->at(linkIndex);
            }
            linkIndex = bPred->at(shortestPathMidNode);
            //std::cout << linkIndex << " ";
            while(linkIndex!=-1){
                q.push_back(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeToIndex();
                linkIndex = bPred->at(linkIndex);
            }

            FPType dist = 0.0;
            for(size_t i = 0; i < q.size(); i++){
                StarLink* link = _netPointer->getLink(q[i]);
                Predecessors->at(link->getNodeToIndex()) = link->getIndex();
                dist += link->getTime();
                LabelVector->at(link->getNodeToIndex()) = dist;
            }
            LabelVector->at(O)= 0;
        }

        bool fIterate(int O, int D){
            if( fQueue->empty() )
                return false;

            int u;
            FPType Du;

            u = (fQueue->top()).second;
            Du = fDist->at(u);
            fQueue->pop();

            StarNode* curNode = _netPointer->beginNode(u);

            if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                for (StarLink *nextLink = _netPointer->beginLink();
                        nextLink != NULL;
                        nextLink = _netPointer->getNextLink()) {
                    int v = nextLink->getNodeToIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < fDist->at(v) ){
                        fDist->at(v) = Duv;
                        fPred->at(v) = nextLink->getIndex();
                        fQueue->push(ShPath::PQPair(Duv, v));
                    }
                    updateShortest(Duv, 0.0, v, D);
                } // for each outgoing link
            }
            if (checkFinishCondition())
                return false;
            return true;
        }

        bool bIterate(int O, int D){
            if( bQueue->empty() )
                return false;

            int u;
            FPType Du;

            u = (bQueue->top()).second;
            Du = bDist->at(u);
            bQueue->pop();

            StarNode* curNode = _netPointer->beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == D))) {
                for (size_t j = 0; j < Edges->at(u)->size(); j++){
                    StarLink *nextLink = Edges->at(u)->at(j);
                    int v = nextLink->getNodeFromIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < bDist->at(v)){
                        bDist->at(v) = Duv;
                        bPred->at(v) = nextLink->getIndex();
                        bQueue->push(ShPath::PQPair(Duv, v));
                    }
                    updateShortest(0.0, Duv, v, O);
                } // for each outgoing link
            } // if can visit node
            if (checkFinishCondition())
                return false;
            return true;
        }

        // http://www.cs.princeton.edu/courses/archive/spr06/cos423/Handouts/EPP%20shortest%20path%20algorithms.pdf
        // a node from overlap may not be on the shortest path!!
        // => when scanning an arc (v, w) in the forward search and w is scanned in the reverseOrder 
        //    search, update shortest = μ if df (v) + (v, w) + dr (w) < μ            
        void updateShortest(FPType fDv, FPType bDv, int v, int dest){
            if (isZone->at(v) )return;
            FPType newDist = ShPath::FPType_Max;
            if (((fDist->at(v) != newDist) && (bDist->at(v) != newDist)) || (v ==dest)){
                int *fNode = NULL, *bNode = NULL;
                if (fDv == 0.0) { // check on backward
                    newDist = bDv + fDist->at(v);
                    fNode = &(fPred->at(v));
                    bNode = &v;
                }

                if (bDv == 0.0) { // check on forward
                    newDist = fDv + bDist->at(v);
                    fNode = &v;
                    bNode = &bPred->at(v);
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
            FPType bTopDist = (bQueue->top()).first;
            FPType fTopDist = (fQueue->top()).first;
            return  fTopDist + bTopDist >= shortestPathDist;
        }

};


#endif

