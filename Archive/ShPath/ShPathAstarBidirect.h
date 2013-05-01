#ifndef _SH_PATH_A_STAR_BIDIRECT_
#define _SH_PATH_A_STAR_BIDIRECT_

#include <cmath>
#include <iostream>
#include <set>
#include "ShPathAstar.h"
#include "ShPathInterface.h"

template <class PriorityQueue>
class IAstarBidirect : public ShPathInterface {
    protected:
        typedef class PriorityQueue::handle_type handle_t;
        PriorityQueue *Queue;
        std::vector<handle_t> *ValueKeys;
        std::vector<Label> *Labels;
        std::vector<FPType> *zeroFlowTimes;

    public:
        IAstarBidirect<PriorityQueue>(StarNetwork* _netPointer, std::vector<FPType> *_zeroFlowTimes)
            :ShPathInterface(_netPointer), zeroFlowTimes(_zeroFlowTimes)
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
    public:
        AstarForward<PriorityQueue>(StarNetwork *_netPointer, std::vector<FPType> *_zeroFlowTimes)
            :IAstarBidirect<PriorityQueue>(_netPointer, _zeroFlowTimes){}
        void initialise(int O, int D){
            this->initNodes();

            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& H = *this->zeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;

            Q.clear();

            for(int i = 0; i < nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, -H[O*nNodes+D]));
            //K[O] = Q.push(ValueKey(O, 0));
        }
        int iterate(int O, int D){

            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& H = *this->zeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;
            StarNetwork &netPointer = *this->_netPointer;

            int u = Q.top().u;
            L[u] = LABELED;
            FPType Du = N[u].dist;
            Q.pop();

            //if( u == D ){ return u; }
            StarNode* curNode = netPointer.beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                for (StarLink *nextLink = netPointer.beginLink(); nextLink != NULL; nextLink = netPointer.getNextLink()) {
                    int v = nextLink->getNodeToIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < N[v].dist ){
                        N[v].dist = Duv;
                        N[v].linkIndex = nextLink->getIndex();
                        FPType Fuv = Duv + H[v*nNodes+D];
                        //FPType Fuv = Duv;
                        if( L[v] == UNREACHED ){
                            L[v] = SCANNED;
                            K[v] = Q.push(ValueKey(v, -Fuv));
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

    public:
        AstarBackward<PriorityQueue>(StarNetwork *_netPointer, std::vector<FPType> *_zeroFlowTimes)
            :IAstarBidirect<PriorityQueue>(_netPointer, _zeroFlowTimes)
        { 
            Edges = new EdgeMap();
            for (int i = 0; i < this->_nNodes; i++){
                Edges->insert(std::make_pair(i, new StarLinkVector()));
            }
        }

        ~AstarBackward(){
            for(int i = 0; i < this->_nNodes; i++){
                delete (*Edges)[i];
            }
            delete Edges;
        }

        void setupReverseStar(){
            StarNetwork &netPointer = *this->_netPointer;
            for (StarNode *node = netPointer.beginNode(); node != NULL; node = netPointer.getNextNode()) {
                for (StarLink *nextLink = netPointer.beginLink(); nextLink != NULL; nextLink = netPointer.getNextLink()) {
                    (*Edges)[nextLink->getNodeToIndex()]->push_back(nextLink);
                }
            }
            //for (int i = 0; i < nNodes; i++){
            //    (*Edges)[i]->clear();
            //}
        }

        void initialise(int O, int D){ 
            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& H = *this->zeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            int nNodes = this->_nNodes;

            this->initNodes();

            Q.clear();

            for(int i = 0; i < nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            K[O] = Q.push(ValueKey(O, -H[D*nNodes+O]));
            //K[O] = Q.push(ValueKey(O, 0));
        }

        int iterate(int O, int D){
            PriorityQueue& Q = *this->Queue;
            std::vector<handle_t>& K = *this->ValueKeys;
            std::vector<Label>& L = *this->Labels;
            std::vector<FPType>& H = *this->zeroFlowTimes;
            std::vector<nodeInfo>& N = *this->Nodes;
            EdgeMap& E = *Edges; // map of star links
            int nNodes = this->_nNodes;
            StarNetwork &netPointer = *this->_netPointer;

            int u = Q.top().u;
            L[u] = LABELED;
            FPType Du = N[u].dist;
            Q.pop();

            //if( u == D ){ return u; } 
            StarNode* curNode = netPointer.beginNode(u);
            if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                for (size_t j = 0; j < E[u]->size(); j++){
                    StarLink *nextLink = E[u]->at(j);
                    int v = nextLink->getNodeFromIndex();
                    FPType Duv = Du + nextLink->getTime();
                    if ( Duv < N[v].dist ){
                        N[v].dist = Duv;
                        N[v].linkIndex = nextLink->getIndex();
                        FPType Fuv = Duv + H[D*nNodes+v];
                        //FPType Fuv = Duv;
                        if( L[v] == UNREACHED ){
                            L[v] = SCANNED;
                            K[v] = Q.push(ValueKey(v, -Fuv));
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

        // cost from initialised network
        // 1d vector stroing 2d data for faster access
        // access by initCosts[fromNode*nbOrigins+toNode]
        std::vector<FPType> *zeroFlowTimes;
        void setupAstar(int nbOrigins){
            zeroFlowTimes->resize(_nNodes*_nNodes);
            //std::cout << zeroFlowTimes->size() << std::endl;
            for(int i = 0; i < _nNodes; i++){
                calculate(i);
                for(int j = 0; j < _nNodes; j++){
                    zeroFlowTimes->at(i*_nNodes+j) = (*Nodes)[j].dist;
                }
            }
            std::cout << "heuristic function setup complete" << std::endl;
        }

        ShPathAstar<PriorityQueue> *astar;
        AstarForward<PriorityQueue> *astarForward;
        AstarBackward<PriorityQueue> *astarBackward;

    public:
        ShPathAstarBidirect<PriorityQueue>(StarNetwork* _netPointer):ShPathInterface(_netPointer){
            zeroFlowTimes = new std::vector<FPType>();
            astarForward = new AstarForward<PriorityQueue>(_netPointer, zeroFlowTimes);
            astarBackward = new AstarBackward<PriorityQueue>(_netPointer, zeroFlowTimes);
            astarBackward->setupReverseStar();
            astar = new ShPathAstar<PriorityQueue>(_netPointer);
        }

        ~ShPathAstarBidirect(){
            delete zeroFlowTimes;
            delete astar;
            delete astarForward;
            delete astarBackward;
        }

        void calculate(int O) { 
            astar->calculate(O); 
            for(int i = 0; i < _nNodes; i++){
                (*Nodes)[i].dist = astar->getCost(i);
                if(astar->getInComeLink(i) == NULL)
                    (*Nodes)[i].linkIndex = -1;
                else
                    (*Nodes)[i].linkIndex = astar->getInComeLink(i)->getIndex();
            }
        }


        void calculate(int O, int D) { 
            if( O == -1) {setupAstar(D); return;}

            AstarForward<PriorityQueue> &AF = *astarForward;
            AstarBackward<PriorityQueue> &AB = *astarBackward;

            AF.initialise(O, D);
            AB.initialise(D, O);

            std::set<int> setForward = std::set<int>();
            std::set<int> setBackward = std::set<int>();

            int midnode = -1;
            int forwardTopNode = -1;
            int backwardTopNode = -1;

            FPType newPath = -1;
            FPType shortestPath = std::numeric_limits<FPType>::max();
            //std::cout << O << " " << D << std::endl;
            while(true){
                bool forwardEmpty = AF.isQempty();
                if(!forwardEmpty){
                    forwardTopNode = AF.iterate(O, D);
                    //std::cout << "forward | " << forwardTopNode << std::endl;
                    if(forwardTopNode != -1){
                        setForward.insert(forwardTopNode);
                    }
                }


                if(setBackward.find(forwardTopNode) != setBackward.end()){
                    newPath = AF.getCost(forwardTopNode) + AB.getCost(forwardTopNode);
                    if(newPath > 0 && newPath < shortestPath){
                        shortestPath = newPath;
                        midnode = forwardTopNode;
                        break;
                    }
                }

                bool backwardEmpty = AB.isQempty();
                if(!backwardEmpty){
                    backwardTopNode = AB.iterate(D, O);
                    //std::cout << "backward | " << backwardTopNode << std::endl;
                    if(backwardTopNode != -1){
                        setBackward.insert(backwardTopNode);
                    }
                }

                if(setForward.find(backwardTopNode) != setForward.end()){
                    newPath = AF.getCost(backwardTopNode) + AB.getCost(backwardTopNode);
                    if(newPath > 0 && newPath < shortestPath){
                        shortestPath = newPath;
                        midnode = backwardTopNode;
                        break;
                    }
                }

                if (forwardEmpty && backwardEmpty){
                    break;
                }

            }

            // min {d_v^s + c_vw + d_w^t | v \in R^s, w \in R^t}
            // get all remaining leafs nodes from the PQs
            int node;
            while( (node = AF.popQ()) != -1){
                setForward.insert(node);
            }

            while( (node = AB.popQ()) != -1){
                setBackward.insert(node);
            }

            //std::cout << "midnode:" << std::endl;
            //std::cout << midnode << std::endl;
            //std::cout << shortestPath << std::endl;
            //std::cout << std::endl;
            std::set<int>::iterator itf; // forward
            std::set<int>::iterator itb; // backward
            //std::cout << "v[i]\tw[j]\tdv[i]\tdw[j]\tnewpath\tfstShPath\tgetTime\tgetIndex" << std::endl;
            StarNode *curNode;
            int shorterPathLinkIndex = -1;
            for(itf = setForward.begin(); itf != setForward.end(); itf++){
                curNode = _netPointer->beginNode(*itf); 

                if(curNode == NULL || curNode->getIsZone()) {continue;}

                if( AF.getCost(forwardTopNode) <= AF.getCost(*itf) ){ continue; }

                for(itb = setBackward.begin(); itb != setBackward.end(); itb++){
                    // for each outgoing link of nodes in  setForward
                    if( AB.getCost(backwardTopNode) <= AB.getCost(*itb) ){ continue; }

                    curNode = _netPointer->beginNode(*itf); 
                    for(StarLink* link = _netPointer->beginLink(); link != NULL; link = _netPointer->getNextLink()){
                        if( link->getNodeToIndex() == (*itb) ){
                            newPath = AF.getCost(*itf) + AB.getCost(*itb) + link->getTime();
                            if( newPath < shortestPath){
                                shortestPath = newPath;
                                shorterPathLinkIndex = link->getIndex();
                                forwardTopNode = *itf;
                                backwardTopNode = *itb;
                            }
                            //                    std::cout << (*itf) << "\t" << (*itb) << "\t" << AF.getCost(*itf) << "\t" << AB.getCost(*itb) << "\t" << newPath << "\t" << shortestPath << "\t\t" << link->getTime() << "\t" << link->getIndex() << std::endl;
                        }
                    }
                } // for j
            } // for i

            initNodes();
            std::deque<int> q; // link indices
            StarLink *link;
            if(shorterPathLinkIndex != -1){ // path not from midnode

                link = AF.getInComeLink(forwardTopNode);
                while( link!=NULL){
                    q.push_front(link->getIndex());
                    node = link->getNodeFromIndex();
                    link = AF.getInComeLink(node);
                }

                q.push_back(shorterPathLinkIndex);

                link = AB.getInComeLink(backwardTopNode);
                while( link!=NULL){
                    q.push_back(link->getIndex());
                    node = link->getNodeToIndex();
                    link = AB.getInComeLink(node);
                }
            }else{ // path from midnode
                //std::cout << "midnode:" << midnode << std::endl;
                link = AF.getInComeLink(midnode);
                while( link!=NULL){
                    q.push_front(link->getIndex());
                    node = link->getNodeFromIndex();
                    link = AF.getInComeLink(node);
                }

                link = AB.getInComeLink(midnode);
                if(link!=NULL){
                    node = link->getNodeToIndex();
                    while( link!=NULL){
                        q.push_back(link->getIndex());
                        link = AB.getInComeLink(node);
                        if(link==NULL)break;
                        node = link->getNodeToIndex();
                    }
                }


            }
            // build path and dist
            FPType dist = 0;
            for(size_t i = 0; i < q.size(); i++){
                link = _netPointer->getLink(q[i]);
                (*Nodes)[link->getNodeToIndex()].linkIndex = link->getIndex();
                dist += link->getTime();
                (*Nodes)[link->getNodeToIndex()].dist = dist;
            }
            (*Nodes)[O].dist = 0;


        }

        //FPType getCost(int destIndex) const{
        //    return ShPathInterface::getCost(destIndex);
        //}

        //StarLink* getInComeLink(int destIndex) const{
        //    return ShPathInterface::getInComeLink(destIndex);
        //}
};

#endif

