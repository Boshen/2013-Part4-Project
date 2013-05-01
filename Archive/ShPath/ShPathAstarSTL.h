#ifndef _SH_PATH_ASTAR_STL
#define _SH_PATH_ASTAR_STL

#include <queue>
#include <cmath>
#include <iostream>
#include "ShPathInterface.h"

class ShPathAstarSTL : public ShPathInterface {
    private:
        class Prioritize{
            public:
                bool operator() ( const std::pair<int, FPType>& p1, const std::pair<int, FPType>& p2){
                    return p1.second > p2.second;
                }
        };

        typedef std::pair<int, FPType> PQPair;
        typedef std::priority_queue<PQPair, std::vector<PQPair>, Prioritize > PriorityQueue;
        PriorityQueue *Queue;
        std::vector<FPType> *initCosts;
        std::vector<Label> *Labels;

        //#ifdef DEBUG
        //        int GpushCount;
        //        int GpopCount;
        //        int GincCount;
        //#endif


    public:
        ShPathAstarSTL(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new PriorityQueue();
            initCosts = new std::vector<FPType>(_nNodes*_nNodes);
            Labels = new std::vector<Label>(_nNodes);

            //#ifdef DEBUG
            //        GpushCount = 0;
            //        GpopCount = 0;
            //        GincCount = 0;
            //#endif

        }

        ~ShPathAstarSTL(){
            delete Queue;
            delete initCosts;
            delete Labels;

            //#ifdef DEBUG
            //            std::cout << "global count | pop " << GpopCount << " | push " << GpushCount << " | incr " << GincCount << std::endl;
            //#endif

        }

        void calculate(int O) {
            //calculate(O, -1);
            bool zeroFlow = false;
            initNodes();

            PriorityQueue& Q = *Queue;
            std::vector<nodeInfo>& N = *Nodes;

            //#ifdef DEBUG
            //int pushCount = 0;
            //int popCount = 0;
            //int incCount = 0;
            //#endif
            while(!Q.empty()){
                Q.pop();
            }

            N[O].dist = 0;
            Q.push(PQPair(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().first;
                FPType Du = N[u].dist;
                Q.pop();

                //#ifdef DEBUG
                //                popCount++;
                //#endif

                StarNode* curNode = _netPointer->beginNode(u);

                if ((curNode != NULL) && (!curNode->getIsZone() || (u == O))) {
                    for (StarLink *nextLink = _netPointer->beginLink(); nextLink != NULL; nextLink = _netPointer->getNextLink()) {
                        int v = nextLink->getNodeToIndex();
                        FPType Duv = Du + nextLink->getTime();
                        if( nextLink->getFlow() == 0 ){
                            zeroFlow = true;
                        }
                        //std::cout << O << " " << nextLink->getFlow() << " " << nextLink->getTime() << std::endl;
                        if ( Duv < N[v].dist ){
                            N[v].dist = Duv;
                            N[v].linkIndex = nextLink->getIndex();
                            Q.push(PQPair(v, Duv));

                            //#ifdef DEBUG
                            //                                pushCount++;
                            //#endif

                        }
                    } // for each outgoing link
                } // if can visit node
            } // while !Q.empty()
            //std::cout << std::endl;
            if ( zeroFlow){
                for(int i = 0; i < _nNodes; i++){
                    //   StarNode* toNode = _netPointer->beginNode(i);
                    (*initCosts)[O*_nNodes+i] = (*Nodes)[i].dist;
                    //(*initCosts)[O*_nNodes+i] = distance(fromNode->getX(), fromNode->getY(), toNode->getX(), toNode->getY());
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

            initNodes();

            PriorityQueue& Q = *Queue;
            std::vector<nodeInfo>& N = *Nodes;
            std::vector<FPType>& H = *initCosts;
            std::vector<Label>& L = *Labels;

            //#ifdef DEBUG
            //int pushCount = 0;
            //int popCount = 0;
            //int incCount = 0;
            //#endif
            while(!Q.empty()){
                Q.pop();
            }

            for(int i = 0; i < _nNodes; i++){
                L[i] = UNREACHED;
            }

            N[O].dist = 0;
            Q.push(PQPair(O, H[O*_nNodes+D]));
            //Q.push(PQPair(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().first;
                FPType Du = N[u].dist;
                L[u] = LABELED;
                Q.pop();

                //#ifdef DEBUG
                //                popCount++;
                //#endif

                if ( u == D ){ 
                    //#ifdef DEBUG
                    //                    if(D!=-1){
                    //                        std::cout << O << " " << D << " | pop " << popCount << " | push " << pushCount << " | incr " << incCount << std::endl;
                    //                    }
                    //                    GpopCount += popCount;
                    //                    GpushCount += pushCount;
                    //                    GincCount += incCount;
                    //#endif
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
                            Q.push(PQPair(v, Duv + H[v*_nNodes+D]));
                        }
                    } // for each outgoing link
                } // if can visit node
            } // while !Q.empty()
        }

        FPType getCost(int destIndex) const{
            return ShPathInterface::getCost(destIndex);
        }

        StarLink* getInComeLink(int destIndex) const{
            return ShPathInterface::getInComeLink(destIndex);
        }
};

#endif
