#ifndef _SH_PATH_ASTAR_BIDIRECT_
#define _SH_PATH_ASTAR_BIDIRECT_

#include <cmath>
#include <iostream>
#include <set>
#include <deque>
#include <map>
#include "ShPathInterface.h"

// https://github.com/graphhopper/graphhopper/blob/7df6a1104a6154c54aa6ba49969badc4a14220bf/core/src/main/java/com/graphhopper/routing/AStarBidirection.java
template <class PriorityQueue>
class ShPathAstarBidirect : public ShPathInterface {
    private:
        typedef class PriorityQueue::handle_type handle_t;
        typedef std::vector<StarLink*> StarLinkVector;
        typedef std::map<int, StarLinkVector*> EdgeMap;
        EdgeMap *Edges; // map of star links, sort of like reverse star

        PriorityQueue *fQueue;
        PriorityQueue *bQueue;
        std::vector<handle_t> *fValueKeys;
        std::vector<handle_t> *bValueKeys;
        std::vector<Label> *fLabels;
        std::vector<Label> *bLabels;
        std::vector<FPType> *fDist;
        std::vector<FPType> *bDist;
        std::vector<int> *fPred;
        std::vector<int> *bPred;
        std::vector<bool> *isZone;
        std::vector<FPType> *fZeroFlowTimes;
        std::vector<FPType> *bZeroFlowTimes;

        std::vector<std::pair<int, int> > *fScanned;
        std::vector<std::pair<int, int> > *bScanned;


        FPType fShortestDist, bShortestDist, shortestPathDist; // for stop condition
        int fShortestNode, bShortestNode;
        int shortestPathMidNode;
    public:
        ShPathAstarBidirect<PriorityQueue>(StarNetwork* netPointer):ShPathInterface(netPointer){
            fQueue = new PriorityQueue();
            bQueue = new PriorityQueue();
            fValueKeys = new std::vector<handle_t>(_nNodes);
            bValueKeys = new std::vector<handle_t>(_nNodes);
            fLabels = new std::vector<Label>(_nNodes);
            bLabels = new std::vector<Label>(_nNodes);
            fDist = new std::vector<FPType>(_nNodes);
            bDist = new std::vector<FPType>(_nNodes);
            fPred = new std::vector<int>(_nNodes);
            bPred = new std::vector<int>(_nNodes);
            isZone = new std::vector<bool>(_nNodes);
            fZeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);
            bZeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);

            fScanned = new std::vector<std::pair<int, int> >();
            bScanned = new std::vector<std::pair<int, int> >();

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

            _netPointer->calculateLinkCosts();
            // forward heuristic
            for(int i = 0; i < _nNodes; i++){
                calculate(i);
                for(int j = 0; j < _nNodes; j++){
                    fZeroFlowTimes->at(i*_nNodes+j) = Nodes->at(j).dist;
                }
            }
            // backward heuristic
            for(int i = 0; i < _nNodes; i++){
                calculateBackward(i);
                for(int j = 0; j < _nNodes; j++){
                    bZeroFlowTimes->at(i*_nNodes+j) = Nodes->at(j).dist;
                }
            }
        }

        ~ShPathAstarBidirect(){
            delete fQueue;
            delete bQueue;
            delete fValueKeys;
            delete bValueKeys;
            delete fLabels;
            delete bLabels;
            delete fDist;
            delete bDist;
            delete fPred;
            delete bPred;
            delete isZone;
            delete fZeroFlowTimes;
            delete bZeroFlowTimes;
            for(int i = 0; i < _nNodes; i++){
                delete (*Edges)[i];
            }
            delete Edges;

            delete fScanned;
            delete bScanned;

        }

        void calculate(int O) { 
            initialise(O, O);
            Nodes->at(O).dist = 0;
            while ( !fQueue->empty() ){
                int u = fQueue->top().u;
                fLabels->at(u) = LABELED;
                FPType Du = Nodes->at(u).dist;
                fQueue->pop();
                StarNode* curNode = _netPointer->beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                        int v = nextLink->getNodeToIndex();
                        FPType Duv = Du + nextLink->getTime();
                        if ( Duv < Nodes->at(v).dist ){
                            Nodes->at(v).dist = Duv;
                            Nodes->at(v).linkIndex = nextLink->getIndex();
                            if( fLabels->at(v) == UNREACHED ){
                                fLabels->at(v) = SCANNED;
                                fValueKeys->at(v) = fQueue->push(ValueKey(v, -Duv));
                                fScanned->push_back(std::pair<int, int>(u, v));
                            }else if( fLabels->at(v) == SCANNED){
                                fQueue->increase(fValueKeys->at(v), ValueKey(v, -Duv));
                            }
                        }
                    }
                }
            }
        }

        void calculateBackward(int O){
            initialise(O, O);
            Nodes->at(O).dist = 0;
            while ( !fQueue->empty() ){
                int u = fQueue->top().u;
                fLabels->at(u) = LABELED;
                FPType Du = Nodes->at(u).dist;
                fQueue->pop();
                StarNode* curNode = _netPointer->beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (size_t j = 0; j < Edges->at(u)->size(); j++){
                        StarLink *nextLink = Edges->at(u)->at(j);
                        int v = nextLink->getNodeFromIndex();
                        FPType Duv = Du + nextLink->getTime();
                        if ( Duv < Nodes->at(v).dist ){
                            Nodes->at(v).dist = Duv;
                            Nodes->at(v).linkIndex = nextLink->getIndex();
                            if( fLabels->at(v) == UNREACHED ){
                                fLabels->at(v) = SCANNED;
                                fValueKeys->at(v) = fQueue->push(ValueKey(v, -Duv));
                                bScanned->push_back(std::pair<int, int>(u, v));
                            }else if( fLabels->at(v) == SCANNED){
                                fQueue->increase(fValueKeys->at(v), ValueKey(v, -Duv));
                            }
                        }
                    }
                }
            }
        }

        void initialise(int O, int D){
            initNodes();

            fScanned->clear();
            bScanned->clear();

            fShortestDist = bShortestDist = 0.0;
            fShortestNode = bShortestNode = -1;
            shortestPathDist = std::numeric_limits<FPType>::max();

            fQueue->clear();
            bQueue->clear();

            for(int i = 0; i < _nNodes; i++){
                fLabels->at(i) = UNREACHED;
                bLabels->at(i) = UNREACHED;
                fPred->at(i) = -1;
                bPred->at(i) = -1;
                fDist->at(i) = std::numeric_limits<FPType>::max();
                bDist->at(i) = std::numeric_limits<FPType>::max();
            }

            fDist->at(O) = 0;
            bDist->at(D) = 0;
            fValueKeys->at(O) = fQueue->push(ValueKey(O, 0));
            bValueKeys->at(D) = bQueue->push(ValueKey(D, 0));
        }

        void calculate(int O, int D) { 
            //std::cout << O << " " << D << " | ";
            initialise(O, D);

            int finish = 0;
            while(finish < 2){
                finish = 0;
                if (!fIterate(O, D))
                    finish++;
                if (!bIterate(O, D))
                    finish++;
            }

            // reconstrcut path
            std::deque<int> q;
            int linkIndex = fPred->at(shortestPathMidNode);
            while(linkIndex!=-1){
                //std::cout << linkIndex << " ";
                q.push_front(linkIndex);
                //std::cout << _netPointer->getLink(linkIndex)->getNodeFromIndex() << " ";
                linkIndex = _netPointer->getLink(linkIndex)->getNodeFromIndex();
                linkIndex = fPred->at(linkIndex);
            }
            //std::cout << " | ";
            //std::cout << std::endl;
            linkIndex = bPred->at(shortestPathMidNode);
            while(linkIndex!=-1){
                //std::cout << linkIndex << " ";
                q.push_back(linkIndex);
                //std::cout << _netPointer->getLink(linkIndex)->getNodeToIndex() << " ";
                linkIndex = _netPointer->getLink(linkIndex)->getNodeToIndex();
                linkIndex = bPred->at(linkIndex);
            }
            //std::cout << std::endl;

            // recalc dist on shortet path
            FPType dist = 0.0;
            //std::cout << ">> " << O << " " << D << std::endl;
            for(size_t i = 0; i < q.size(); i++){
                StarLink* link = _netPointer->getLink(q[i]);
                Nodes->at(link->getNodeToIndex()).linkIndex = link->getIndex();
                dist += link->getTime();
                Nodes->at(link->getNodeToIndex()).dist = dist;
                //std::cout << link->getNodeToIndex() << " ";
            }
            //std::cout << std::endl;;
            Nodes->at(O).dist = 0;
            //for(size_t i=0;i<Nodes->size();i++){
            //    std::cout << Nodes->at(i).linkIndex << " ";

            //}
            //std::cout << std::endl;;
            //std::cout << O << " " << D << " " << fScanned->size()+bScanned->size() << std::endl;
             //  StarLink *link = getInComeLink(D);
             //  FPType nextDest = link->getNodeFromIndex();
             //  Path path;
             //  while (link != NULL) {
             //  path.addLinkToPath(link);
             //  nextDest = link->getNodeFromIndex();
             //  link = getInComeLink(nextDest);
             //  }
             //  
             //  path.print();

            //   std::cout << fZeroFlowTimes->at(O*_nNodes+D) << " " << bZeroFlowTimes->at(D*_nNodes+O) << std::endl;
            //std::cout << "fScanned" << std::endl;
            //for(size_t i=0;i<fScanned->size();i++)
            //std::cout << fScanned->at(i).first << " ";
            //std::cout << std::endl;
            //std::cout << "bScanned" << std::endl;
            //for(size_t i=0;i<bScanned->size();i++)
            //std::cout << bScanned->at(i).first << " ";



        }

        bool fIterate(int O, int D){
            if( !fQueue->empty() ){

                int u = (fQueue->top()).u;
                fLabels->at(u) = LABELED;
                FPType Du = fDist->at(u);
                fQueue->pop();
                
                if(u == D){
                    fQueue->clear();
                    bQueue->clear();
                    return false;
                }

                StarNode* curNode = _netPointer->beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                        int v = nextLink->getNodeToIndex();
                        if(v==u || isZone->at(v))continue;
                        FPType Duv = Du + nextLink->getTime();
                        if ( Duv < fDist->at(v) ){
                            fDist->at(v) = Duv;
                            fPred->at(v) = nextLink->getIndex();
                            //FPType Huv = Duv + 0.5*(fZeroFlowTimes->at(v*_nNodes+D)-bZeroFlowTimes->at(v*_nNodes+O)) + 0.5*bZeroFlowTimes->at(D*_nNodes+O);
                            //FPType Huv = Duv + fZeroFlowTimes->at(v*_nNodes+D);
                            //FPType Huv = Duv;
                            FPType Huv = Duv + 0.5*(fZeroFlowTimes->at(v*_nNodes+D) - fZeroFlowTimes->at(O*_nNodes+v)) + 0.5*fZeroFlowTimes->at(O*_nNodes+D);
                            //std::cout << fZeroFlowTimes->at(v*_nNodes+D) << " ";
                            //std::cout << bZeroFlowTimes->at(D*_nNodes+v) << std::endl;
                            if( fLabels->at(v) == UNREACHED ){
                                fLabels->at(v) = SCANNED;
                                fValueKeys->at(v) = fQueue->push(ValueKey(v, -Huv));
                            fScanned->push_back(std::pair<int, int>(u, v));
                            }else if( fLabels->at(v) == SCANNED){
                                fQueue->increase(fValueKeys->at(v), ValueKey(v, -Huv));
                            }
                        }
                        //std::cout << "fiterate " << u << " " << v << " " << Duv <<  std::endl;
                        //if(fDist->at(v) + fZeroFlowTimes->at(v*_nNodes+D) >= shortestPathDist){
                        //    fQueue->clear();
                        //    return false;
                        //}
                        //std::cout << "f (" << u << "," << v << ") " << std::endl;
                        updateShortest(Duv, 0.0, v, D);
                    } // for each outgoing link
                } // if can visit node
                if (fQueue->empty())
                    return false;
                if (checkFinishCondition(O, D))
                    return false;
            }else if (bQueue->empty())
                return false;
            return true;
        }

        bool bIterate(int O, int D){
            if( !bQueue->empty() ){

                int u = (bQueue->top()).u;
                bLabels->at(u) = LABELED;
                FPType Du = bDist->at(u);
                bQueue->pop();

                if(u == O){
                    fQueue->clear();
                    bQueue->clear();
                    return false;
                }

                StarNode* curNode = _netPointer->beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == D))) {
                    for (size_t j = 0; j < Edges->at(u)->size(); j++){
                        StarLink *nextLink = Edges->at(u)->at(j);
                        int v = nextLink->getNodeFromIndex();
                        if(v==u || isZone->at(v))continue;
                        FPType Duv = Du + nextLink->getTime();
                        if ( Duv < bDist->at(v)){
                            bDist->at(v) = Duv;
                            bPred->at(v) = nextLink->getIndex();
                            //FPType Huv = Duv + 0.5*(bZeroFlowTimes->at(v*_nNodes+O)-fZeroFlowTimes->at(v*_nNodes+D)) + 0.5*fZeroFlowTimes->at(O*_nNodes+D);
                            //FPType Huv = Duv + bZeroFlowTimes->at(v*_nNodes+O);
                            FPType Huv = Duv + 0.5*(fZeroFlowTimes->at(O*_nNodes+v) - fZeroFlowTimes->at(v*_nNodes+D)) + 0.5*fZeroFlowTimes->at(O*_nNodes+D);
                            //FPType Huv = Duv;
                            if( bLabels->at(v) == UNREACHED ){
                                bLabels->at(v) = SCANNED;
                                bValueKeys->at(v) = bQueue->push(ValueKey(v, -Huv));
                            bScanned->push_back(std::pair<int, int>(u, v));
                            }else if( bLabels->at(v) == SCANNED){
                                bQueue->increase(bValueKeys->at(v), ValueKey(v, -Huv));
                            }
                        }
                        //std::cout << "biterate " << u << " " << v << " " << Duv << std::endl;
                        //if(bDist->at(v) + bZeroFlowTimes->at(v*_nNodes+O) >= shortestPathDist){
                        //    bQueue->clear();
                        //    return false;
                        //}
                        //std::cout << "b (" << u << "," << v << ") " << std::endl;
                        updateShortest(0.0, Duv, v, O);
                    } // for each outgoing link
                } // if can visit node
                if(bQueue->empty())
                    return false;
                if (checkFinishCondition(O, D))
                    return false;
            }else if ( fQueue->empty() )
                return false;

            return true;
        }

        // http://www.cs.princeton.edu/courses/archive/spr06/cos423/Handouts/EPP%20shortest%20path%20algorithms.pdf
        // a node from overlap may not be on the shortest path!!
        // => when scanning an arc (v, w) in the forward search and w is scanned in the reverseOrder 
        //    search, update shortest = μ if df (v) + (v, w) + dr (w) < μ            
        void updateShortest(FPType fDv, FPType bDv, int v, int dest){
            if (isZone->at(v) )return;
            if (((fLabels->at(v) == SCANNED) && (bLabels->at(v) == SCANNED)) || (v ==dest)){
                FPType newDist = std::numeric_limits<FPType>::max();
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
                //std::cout << ">> "  << v << " | " << newDist << " " << shortestPathDist << std::endl;

                if (newDist < shortestPathDist){
                    shortestPathDist = newDist;
                    fShortestNode = *fNode;
                    bShortestNode = *bNode;
                    shortestPathMidNode = v;
                }
            }
        }

        bool checkFinishCondition(int O, int D) {
            if( fQueue->empty() || bQueue->empty())
                return false;
            //FPType fTopDist = fDist->at((fQueue->top()).u);
            //FPType bTopDist = bDist->at((bQueue->top()).u);
            FPType fTopDist = -fQueue->top().d;
            FPType bTopDist = -bQueue->top().d;
            //std::cout << ">>> " << fTopDist << " " << bTopDist << " " << shortestPathDist + fZeroFlowTimes->at(O*_nNodes+D) << std::endl;
            return  fTopDist + bTopDist >= shortestPathDist + fZeroFlowTimes->at(O*_nNodes+D);
        }
};


#endif

