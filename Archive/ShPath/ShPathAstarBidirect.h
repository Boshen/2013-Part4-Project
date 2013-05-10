#ifndef _SH_PATH_A_STAR_BIDIRECT_
#define _SH_PATH_A_STAR_BIDIRECT_

#include <cmath>
#include <iostream>
#include <set>
#include <deque>
#include <map>
#include "ShPathDijkstraSTL.h"
#include "ShPathInterface.h"
#include "../Path.h"

template <class PriorityQueue>
class IAstarBidirect : public ShPathInterface {
    protected:
        typedef class PriorityQueue::handle_type handle_t;
        PriorityQueue *Queue;
        std::vector<handle_t> *ValueKeys;
        std::vector<Label> *Labels;

    public:
        IAstarBidirect<PriorityQueue>(StarNetwork* _netPointer)
            :ShPathInterface(_netPointer)
        {
            Queue = new PriorityQueue();
            ValueKeys = new std::vector<handle_t>(_nNodes);
            Labels = new std::vector<Label>(_nNodes);

        }

        ~IAstarBidirect(){
            delete Queue;
            delete ValueKeys;
            delete Labels;
        }
        bool isQempty(){ return Queue->empty(); }
        int popQ(){
            int u = -1;
            if( !isQempty() ){
                u = Queue->top().u;
                Queue->pop();
            }
            return u;
        }
        virtual int iterate(int O, int D) =0;
        virtual void initialise(int O, int D) =0;
        void calculate(int O) { } // won't be used
        void calculate(int O, int D) { } // won't be used

};

template <class PriorityQueue>
class AstarForward : public IAstarBidirect<PriorityQueue> {
    private:
        typedef class PriorityQueue::handle_type handle_t;
        std::vector<FPType> *forwardZeroFlowTimes;
        std::vector<FPType> *backwardZeroFlowTimes;
    public:
        AstarForward<PriorityQueue>(StarNetwork *_netPointer, std::vector<FPType> *forwardZeroFlowTimes, std::vector<FPType> *backwardZeroFlowTimes)
            :IAstarBidirect<PriorityQueue>(_netPointer), forwardZeroFlowTimes(forwardZeroFlowTimes), backwardZeroFlowTimes(backwardZeroFlowTimes){
                // init heuristic function as zero flows
                int nNodes = this->_nNodes;
                //zeroFlowTimes = new std::vector<FPType>(nNodes*nNodes);
                for(int i = 0; i < nNodes; i++){
                    calculate(i);
                    for(int j = 0; j < nNodes; j++){
                        (*forwardZeroFlowTimes)[i*nNodes+j] = (*this->Nodes)[j].dist;
                    }
                }

            }
        ~AstarForward(){
            //delete zeroFlowTimes;
        }

        void calculate(int O) {
            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;
            StarNetwork &netPointer = *this->_netPointer;

            this->initNodes();

            Q.clear();
            for(int i = 0; i < nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().u;
                L[u] = LABELED;
                FPType Du = N[u].dist;
                Q.pop();
                StarNode* curNode = netPointer.beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (StarLink *nextLink = netPointer.beginLink(); nextLink != NULL; nextLink = netPointer.getNextLink()) {
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

        void initialise(int O, int D){
            this->initNodes();

            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& H = *this->forwardZeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;

            Q.clear();

            for(int i = 0; i < nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, -H[O*nNodes+D]));
            //K[O] = Q.push(ValueKey(O, 0));
            (this->Scanned)->clear();
        }

        int iterate(int O, int D){

            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& HF = *this->forwardZeroFlowTimes;
            std::vector<FPType>& HB = *this->backwardZeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;
            StarNetwork &netPointer = *this->_netPointer;

            int u = Q.top().u;
            L[u] = LABELED;
            FPType Du = N[u].dist;
            Q.pop();

            StarNode* curNode = netPointer.beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                for (StarLink *nextLink = netPointer.beginLink(); nextLink != NULL; nextLink = netPointer.getNextLink()) {
                    int v = nextLink->getNodeToIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < N[v].dist ){
                        N[v].dist = Duv;
                        N[v].linkIndex = nextLink->getIndex();
                        FPType Fuv = Duv +0.5*(HF[v*nNodes+D]-HB[v*nNodes+O]);
                        if( L[v] == UNREACHED ){
                            L[v] = SCANNED;
                            K[v] = Q.push(ValueKey(v, -Fuv));
                            (this->Scanned)->push_back(std::pair<int, int>(u, v));
                        }else if( L[v] == SCANNED){
                            Q.increase(K[v], ValueKey(v, -Fuv));
                        }
                    }
                } // for each outgoing link
                return u;
            } // if can visit node
            return -1;
        }

};

template <class PriorityQueue>
class AstarBackward : public IAstarBidirect<PriorityQueue> {
    private:
        typedef class PriorityQueue::handle_type handle_t;

        typedef std::vector<StarLink*> StarLinkVector;
        typedef std::map<int, StarLinkVector*> EdgeMap;
        EdgeMap *Edges; // map of star links

        std::vector<FPType> *forwardZeroFlowTimes;
        std::vector<FPType> *backwardZeroFlowTimes;
    public:
        AstarBackward<PriorityQueue>(StarNetwork *_netPointer, std::vector<FPType> *forwardZeroFlowTimes, std::vector<FPType> *backwardZeroFlowTimes)
            :IAstarBidirect<PriorityQueue>(_netPointer), forwardZeroFlowTimes(forwardZeroFlowTimes), backwardZeroFlowTimes(backwardZeroFlowTimes)
        { 
            //setup reverse star
            Edges = new EdgeMap();
            for (int i = 0; i < this->_nNodes; i++){
                Edges->insert(std::make_pair(i, new StarLinkVector()));
            }
            StarNetwork &netPointer = *this->_netPointer;
            for (StarNode *node = netPointer.beginNode(); node != NULL; node = netPointer.getNextNode()) {
                for (StarLink *nextLink = netPointer.beginLink(); nextLink != NULL; nextLink = netPointer.getNextLink()) {
                    (*Edges)[nextLink->getNodeToIndex()]->push_back(nextLink);
                }
            }
            //setup heuristic
            int nNodes = this->_nNodes;
            //zeroFlowTimes = new std::vector<FPType>(nNodes*nNodes);
            for(int i = 0; i < nNodes; i++){
                calculate(i);
                for(int j = 0; j < nNodes; j++){
                    (*backwardZeroFlowTimes)[i*nNodes+j] = (*this->Nodes)[j].dist;
                }
            }
        }

        ~AstarBackward(){
            for(int i = 0; i < this->_nNodes; i++){
                delete (*Edges)[i];
            }
            delete Edges;
            //delete zeroFlowTimes;
        }

        void calculate(int O) {
            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;
            StarNetwork &netPointer = *this->_netPointer;
            EdgeMap& E = *Edges; // map of star links

            this->initNodes();

            Q.clear();
            for(int i = 0; i < nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().u;
                L[u] = LABELED;
                FPType Du = N[u].dist;
                Q.pop();
                StarNode* curNode = netPointer.beginNode(u);
                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (size_t j = 0; j < E[u]->size(); j++){
                        StarLink *nextLink = E[u]->at(j);
                        int v = nextLink->getNodeFromIndex();
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

        void initialise(int O, int D){ 
            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& H = *this->backwardZeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;

            this->initNodes();

            Q.clear();

            for(int i = 0; i < nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, -H[O*nNodes+D]));
            //K[O] = Q.push(ValueKey(O, 0));
            (this->Scanned)->clear();
        }

        int iterate(int O, int D){

            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& HF = *this->forwardZeroFlowTimes;
            std::vector<FPType>& HB = *this->backwardZeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            EdgeMap& E = *Edges; // map of star links
            int nNodes = this->_nNodes;
            StarNetwork &netPointer = *this->_netPointer;

            int u = Q.top().u;
            L[u] = LABELED;
            FPType Du = N[u].dist;
            Q.pop();

            StarNode* curNode = netPointer.beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                for (size_t j = 0; j < E[u]->size(); j++){
                    StarLink *nextLink = E[u]->at(j);
                    int v = nextLink->getNodeFromIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < N[v].dist ){
                        N[v].dist = Duv;
                        N[v].linkIndex = nextLink->getIndex();
                        FPType Fuv = Duv + 0.5*(HF[v*nNodes+D]-HB[v*nNodes+O]);
                        if( L[v] == UNREACHED ){
                            L[v] = SCANNED;
                            K[v] = Q.push(ValueKey(v, -Fuv));
                            (this->Scanned)->push_back(std::pair<int, int>(u, v));
                        }else if( L[v] == SCANNED){
                            Q.increase(K[v], ValueKey(v, -Fuv));
                        }
                    }
                } // for each outgoing link
                return u;
            } // if can visit node
            return -1;

        }
};

template <class PriorityQueue>
class ShPathAstarBidirect : public ShPathInterface {
    private:
        ShPathDijkstraSTL *dijkstra;
        AstarForward<PriorityQueue> *astarForward;
        AstarBackward<PriorityQueue> *astarBackward;

        std::vector<FPType> *forwardZeroFlowTimes;
        std::vector<FPType> *backwardZeroFlowTimes;
    public:
        ShPathAstarBidirect<PriorityQueue>(StarNetwork* _netPointer):ShPathInterface(_netPointer){
            dijkstra = new ShPathDijkstraSTL(_netPointer);
            forwardZeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);
            backwardZeroFlowTimes = new std::vector<FPType>(_nNodes*_nNodes);
            astarForward = new AstarForward<PriorityQueue>(_netPointer, forwardZeroFlowTimes, backwardZeroFlowTimes);
            astarBackward = new AstarBackward<PriorityQueue>(_netPointer, forwardZeroFlowTimes, backwardZeroFlowTimes);
            _netPointer->calculateLinkCosts();
        }

        ~ShPathAstarBidirect(){
            delete dijkstra;
            delete astarForward;
            delete astarBackward;
            delete forwardZeroFlowTimes;
            delete backwardZeroFlowTimes;
        }

        std::vector< std::pair<int, int> >* getForwardScanned(){ return astarForward->Scanned; }
        std::vector< std::pair<int, int> >* getBackwardScanned(){ return astarBackward->Scanned; }

        void calculate(int O) { 
            dijkstra->calculate(O); 
            for(int i = 0; i < _nNodes; i++){
                (*Nodes)[i].dist = dijkstra->getCost(i);
                if(dijkstra->getInComeLink(i) == NULL)
                    (*Nodes)[i].linkIndex = -1;
                else
                    (*Nodes)[i].linkIndex = dijkstra->getInComeLink(i)->getIndex();
            }
        }

        void calculate(int O, int D) { 

            AstarForward<PriorityQueue> &AF = *astarForward;
            AstarBackward<PriorityQueue> &AB = *astarBackward;

            AF.initialise(O, D);
            AB.initialise(D, O);

            std::set<int> setForward = std::set<int>();
            std::set<int> setBackward = std::set<int>();

            int midnode;

            while(true){
                bool forwardEmpty = AF.isQempty();
                if(!forwardEmpty){
                    midnode = AF.iterate(O, D);
                    if(midnode != -1){
                        //std::cout << "forward | " << midnode << std::endl;
                        setForward.insert(midnode);
                    }
                }

                if(setBackward.find(midnode) != setBackward.end()){
                    break;
                }

                bool backwardEmpty = AB.isQempty();
                if(!backwardEmpty){
                    midnode = AB.iterate(D, O);
                    if(midnode != -1){
                        //std::cout << "\t\tbackward | " << midnode << std::endl;
                        setBackward.insert(midnode);
                    }
                }

                if(setForward.find(midnode) != setForward.end()){
                    break;
                }

                assert(!forwardEmpty && !backwardEmpty); // no path found

            }

            FPType pathLength = AF.getCost(midnode) + AB.getCost(midnode);

            int node;
            //while( (node = AF.popQ()) != -1){
            //    forwardScanned.insert(node);
            //}
            //while( (node = AB.popQ()) != -1){
            //    StarNode* curNode = _netPointer->beginNode(node); 
            //    if(!curNode->getIsZone())
            //        backwardScanned.insert(node);
            //}
            std::set<int>::iterator itf; // forward
            //std::set<int>::iterator itb; // backward
            int forwardTopNode = midnode;
            int backwardTopNode = midnode;
            int newLinkIndex = -1;
            //std::cout << "midnode " << midnode << std::endl;
            for(itf=setForward.begin();itf!=setForward.end();itf++){
                _netPointer->beginNode(*itf); 
                for(StarLink* link = _netPointer->beginLink(); link != NULL; link = _netPointer->getNextLink()){
                    //std::cout << link->getNodeFromIndex() << " " << link->getNodeToIndex() << std::endl;
                    if(setBackward.find(link->getNodeToIndex()) != setBackward.end()){
                        FPType newPathLength = AF.getCost(*itf) + link->getTime() + AB.getCost(link->getNodeToIndex());
                        if(newPathLength < pathLength){
                            pathLength = newPathLength;
                            forwardTopNode = link->getNodeFromIndex();
                            backwardTopNode = link->getNodeToIndex();
                            newLinkIndex = link->getIndex();
                        }
                    }
                }
            }
            //std::cout << forwardTopNode << " " << backwardTopNode << std::endl;
            // reconstruct path
            std::deque<int> q;
            StarLink* link;
            link = AF.getInComeLink(forwardTopNode);
            while( link!=NULL){
                q.push_front(link->getIndex());
                node = link->getNodeFromIndex();
                link = AF.getInComeLink(node);
                //std::cout << node << " ";
            }
            //std::cout << std::endl;

            if(newLinkIndex!=-1){
                q.push_back(newLinkIndex);
            }

            link = AB.getInComeLink(backwardTopNode);
            while( link!=NULL){
                q.push_back(link->getIndex());
                node = link->getNodeToIndex();
                link = AB.getInComeLink(node);
                //std::cout << node << " ";
            }
            //std::cout << std::endl;

            initNodes();
            // recompute dist
            FPType dist = 0;
            for(size_t i = 0; i < q.size(); i++){
                link = _netPointer->getLink(q[i]);
                (*Nodes)[link->getNodeToIndex()].linkIndex = link->getIndex();
                dist += link->getTime();
                (*Nodes)[link->getNodeToIndex()].dist = dist;
                //std::cout << link->getNodeToIndex() << " ";
            }
            //std::cout << std::endl;
            (*Nodes)[O].dist = 0;

            /*
               link = getInComeLink(D);
               FPType nextDest = link->getNodeFromIndex();
               Path path;
               while (link != NULL) {
               path.addLinkToPath(link);
               nextDest = link->getNodeFromIndex();
               link = getInComeLink(nextDest);
            //std::cout << nextDest << " ";
            }
            path.print();
            */

        }

};

#endif

