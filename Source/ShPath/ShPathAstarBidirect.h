#ifndef _SH_PATH_ASTAR_BIDIRECT_
#define _SH_PATH_ASTAR_BIDIRECT_

#include "ShPathInterface.h"

// https://github.com/graphhopper/graphhopper/blob/7df6a1104a6154c54aa6ba49969badc4a14220bf/core/src/main/java/com/graphhopper/routing/AStarBidirection.java
template <class PriorityQueue>
class ShPathAstarBidirect : public ShPathInterface {
    private:
        typedef class PriorityQueue::handle_type handle_t;
        typedef std::vector<StarLink*> StarLinkVector;
        typedef std::map<int, StarLinkVector*> EdgeMap;
        EdgeMap *Edges; // map of star links, stores reversed links from StarNetwork

        PriorityQueue *fQueue;
        PriorityQueue *bQueue;
        std::vector<handle_t> *fValueKeys;
        std::vector<handle_t> *bValueKeys;
        std::vector<FPType> *fDist;
        std::vector<FPType> *bDist;
        std::vector<int> *fPred;
        std::vector<int> *bPred;
        std::vector<bool> *isZone;
        std::vector<FPType> *fZeroFlowTimes;
        std::vector<FPType> *bZeroFlowTimes;
        std::vector<Label> *bLabels;

        FPType fShortestDist, bShortestDist, shortestPathDist; // for termination conditions
        int fShortestNode, bShortestNode;
        int shortestPathMidNode;
    public:
        ShPathAstarBidirect<PriorityQueue>(StarNetwork* netPointer):ShPathInterface(netPointer){
            fQueue = new PriorityQueue();
            bQueue = new PriorityQueue();
            fValueKeys = new std::vector<handle_t>(_nNodes);
            bValueKeys = new std::vector<handle_t>(_nNodes);
            fDist = new std::vector<FPType>(_nNodes);
            bDist = new std::vector<FPType>(_nNodes);
            fPred = new std::vector<int>(_nNodes);
            bPred = new std::vector<int>(_nNodes);
            isZone = new std::vector<bool>(_nNodes);
            fZeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);
            bZeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);
            bLabels = new std::vector<Label>(_nNodes);

            Edges = new EdgeMap();
            for (int i = 0; i < _nNodes; i++){
                Edges->insert(std::make_pair(i, new StarLinkVector()));
            }

            for (StarNode *node = _netPointer->beginNode(); node != NULL; node = _netPointer->getNextNode()) {
                for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                    (*Edges)[nextLink->getNodeToIndex()]->push_back(nextLink);
                }
                (*isZone)[node->getIndex()] = node->getIsZone();
            }

            _netPointer->calculateLinkCosts();

            // forward heuristic
            for(int i = 0; i < _nNodes; i++){
                calculate(i);
                for(int j = 0; j < _nNodes; j++){
                    (*fZeroFlowTimes)[i*_nNodes+j] = (*LabelVector)[j];
                }
            }

            // backward heuristic
            for(int i = 0; i < _nNodes; i++){
                calculateBackward(i);
                for(int j = 0; j < _nNodes; j++){
                    (*bZeroFlowTimes)[i*_nNodes+j] = (*LabelVector)[j];
                }
            }
        }

        ~ShPathAstarBidirect(){
            delete fQueue;
            delete bQueue;
            delete fValueKeys;
            delete bValueKeys;
            delete fDist;
            delete bDist;
            delete fPred;
            delete bPred;
            delete isZone;
            delete bLabels;
            delete fZeroFlowTimes;
            delete bZeroFlowTimes;
            for(int i = 0; i < _nNodes; i++){
                delete (*Edges)[i];
            }
            delete Edges;

        }

        void initialise(int O, int D){
            initNodes();

            fShortestDist = bShortestDist = 0.0;
            fShortestNode = bShortestNode = -1;
            shortestPathDist = ShPath::FPType_Max;

            fQueue->clear();
            bQueue->clear();

            std::fill(fPred->begin(), fPred->end(), -1);
            std::fill(bPred->begin(), bPred->end(), -1);
            std::fill(fDist->begin(), fDist->end(), ShPath::FPType_Max);
            std::fill(bDist->begin(), bDist->end(), ShPath::FPType_Max);
            std::fill(Labels->begin(), Labels->end(), UNREACHED);
            std::fill(bLabels->begin(), bLabels->end(), UNREACHED);

            fDist->at(O) = 0;
            bDist->at(D) = 0;
            fValueKeys->at(O) = fQueue->push(ShPath::ValueKey(0, O));
            bValueKeys->at(D) = bQueue->push(ShPath::ValueKey(0, D));
        }


        void calculate(int O) { 
            int u, v;
            FPType Du, Duv;

            initialise(O, O);
            LabelVector->at(O) = 0.0;

            while ( !fQueue->empty() ){
                u = fQueue->top().u;
                Du = (*LabelVector)[u];
                fQueue->pop();
                (*Labels)[u] = LABELED;

                StarNode* curNode = _netPointer->beginNode(u);

                if (curNode == NULL)
                    continue;

                if (curNode->getIsZone() && u != O)
                    continue;

                for (StarLink *nextLink = _netPointer->beginLink();
                        nextLink != NULL;
                        nextLink = _netPointer->getNextLink()) {

                    v = nextLink->getNodeToIndex();

                    Duv = Du + nextLink->getTime();

                    if ( Duv < LabelVector->at(v) ){

                        if( (*Labels)[v] == UNREACHED ){
                            (*fValueKeys)[v] = fQueue->push(ShPath::ValueKey(-Duv, v));
                            (*Labels)[v] = SCANNED;
                        }else if ((*Labels)[v] == SCANNED){
                            fQueue->increase((*fValueKeys)[v], ShPath::ValueKey(-Duv, v));
                        }

                        LabelVector->at(v) = Duv;
                        Predecessors->at(v) = nextLink->getIndex();
                    }

                }
            }

        }

        void calculateBackward(int O){
            int u, v;
            FPType Du, Duv;

            initialise(O, O);
            LabelVector->at(O) = 0.0;

            while ( !fQueue->empty() ){
                u = fQueue->top().u;
                Du = LabelVector->at(u);
                fQueue->pop();
                (*Labels)[u] = LABELED;

                StarNode* curNode = _netPointer->beginNode(u);

                if (curNode == NULL)
                    continue;

                if (curNode->getIsZone() && u != O)
                    continue;

                for (size_t j = 0; j < Edges->at(u)->size(); j++){
                    StarLink *nextLink = Edges->at(u)->at(j);

                    v = nextLink->getNodeFromIndex();

                    Duv = Du + nextLink->getTime();

                    if ( Duv < LabelVector->at(v) ){

                        if( (*Labels)[v] == UNREACHED ){
                            (*fValueKeys)[v] = fQueue->push(ShPath::ValueKey(-Duv, v));
                            (*Labels)[v] = SCANNED;
                        }else if ((*Labels)[v] == SCANNED){
                            fQueue->increase((*fValueKeys)[v], ShPath::ValueKey(-Duv, v));
                        }

                        LabelVector->at(v) = Duv;
                        Predecessors->at(v) = nextLink->getIndex();
                    }

                }
            }
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

            // reconstrcut path
            std::deque<int> q;
            int linkIndex = fPred->at(shortestPathMidNode);
            while(linkIndex!=-1){
                q.push_front(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeFromIndex();
                linkIndex = fPred->at(linkIndex);
            }

            linkIndex = bPred->at(shortestPathMidNode);
            while(linkIndex!=-1){
                q.push_back(linkIndex);
                linkIndex = _netPointer->getLink(linkIndex)->getNodeToIndex();
                linkIndex = bPred->at(linkIndex);
            }

            // recalc dist on shortet path
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
            int u, v;
            FPType Du, Duv, Huv;
            if( !fQueue->empty() ){

                u = (fQueue->top()).u;
                Du = fDist->at(u);
                fQueue->pop();
                (*Labels)[u] = LABELED;

                if(u == D){
                    fQueue->clear();
                    bQueue->clear();
                    return false;
                }

                StarNode* curNode = _netPointer->beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (StarLink *nextLink = _netPointer->beginLink();
                            nextLink != NULL;
                            nextLink = _netPointer->getNextLink()) {

                        v = nextLink->getNodeToIndex();

                        if(v==u || isZone->at(v))
                            continue;

                        Duv = Du + nextLink->getTime();
                        if ( Duv < fDist->at(v) ){

                            Huv = Duv + 0.5*(fZeroFlowTimes->at(v*_nNodes+D) - fZeroFlowTimes->at(O*_nNodes+v)) + 0.5*fZeroFlowTimes->at(O*_nNodes+D);

                            if( (*Labels)[v] == UNREACHED ){
                                (*fValueKeys)[v] = fQueue->push(ShPath::ValueKey(-Huv, v));
                                (*Labels)[v] = SCANNED;
                            }else if ((*Labels)[v] == SCANNED){
                                fQueue->increase((*fValueKeys)[v], ShPath::ValueKey(-Huv, v));
                            }

                            fDist->at(v) = Duv;
                            fPred->at(v) = nextLink->getIndex();

                        }

                        updateShortest(Duv, 0.0, v, D);
                    } 
                } 

                if (fQueue->empty())
                    return false;

                if (checkFinishCondition(O, D))
                    return false;

            }else if (bQueue->empty())
                return false;

            return true;
        }

        bool bIterate(int O, int D){
            int u, v;
            FPType Du, Duv, Huv;

            if( !bQueue->empty() ){

                u = (bQueue->top()).u;
                Du = bDist->at(u);
                bQueue->pop();
                (*bLabels)[u] = LABELED;

                if(u == O){
                    fQueue->clear();
                    bQueue->clear();
                    return false;
                }

                StarNode* curNode = _netPointer->beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == D))) {
                    for (size_t j = 0; j < Edges->at(u)->size(); j++){

                        StarLink *nextLink = Edges->at(u)->at(j);
                        v = nextLink->getNodeFromIndex();
                        if(v==u || isZone->at(v))
                            continue;

                        Duv = Du + nextLink->getTime();

                        if ( Duv < bDist->at(v)){

                            Huv = Duv + 0.5*(fZeroFlowTimes->at(O*_nNodes+v) - fZeroFlowTimes->at(v*_nNodes+D)) + 0.5*fZeroFlowTimes->at(O*_nNodes+D);

                            if( (*bLabels)[v] == UNREACHED ){
                                (*bValueKeys)[v] = bQueue->push(ShPath::ValueKey(-Huv, v));
                                (*bLabels)[v] = SCANNED;
                            }else if ((*bLabels)[v] == SCANNED){
                                bQueue->increase((*bValueKeys)[v], ShPath::ValueKey(-Huv, v));
                            }

                            bDist->at(v) = Duv;
                            bPred->at(v) = nextLink->getIndex();

                        }

                        updateShortest(0.0, Duv, v, O);
                    } 
                } 

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

            if (((Labels->at(v) == SCANNED) && (bLabels->at(v) == SCANNED)) || (v ==dest)){

                FPType newDist = ShPath::FPType_Max;

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

        bool checkFinishCondition(int O, int D) {

            if( fQueue->empty() || bQueue->empty())
                return false;

            FPType fTopDist = -fQueue->top().d;
            FPType bTopDist = -bQueue->top().d;

            return  fTopDist + bTopDist >= shortestPathDist + fZeroFlowTimes->at(O*_nNodes+D);
        }
};
#endif
