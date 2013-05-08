#ifndef _SH_PATH_DIJKSTRA_STL_
#define _SH_PATH_DIJKSTRA_STL_

#include <queue>
#include <cmath>
#include <iostream>
#include "ShPathInterface.h"
#include "../Path.h"

class ShPathDijkstraSTL : public ShPathInterface {
    private:
        typedef std::pair<int, FPType> PQPair;
        
        class Prioritize{
            public:
                bool operator() ( const PQPair& p1, const PQPair& p2){
                    if ( p1.second == p2.second)
                    return p1.first > p2.first;
                    else
                    return p1.second > p2.second;
                }
        };
        
        typedef std::priority_queue<PQPair, std::vector<PQPair>, Prioritize > PriorityQueue;
        PriorityQueue *Queue;


    public:
        ShPathDijkstraSTL(StarNetwork* netPointer):ShPathInterface(netPointer){
            Queue = new PriorityQueue();

        }

        ~ShPathDijkstraSTL(){
            delete Queue;
        }

        void calculate(int O) {
            calculate(O, -1);
        }

        void calculate(int O, int D) {
            Scanned->clear();

            initNodes();

            PriorityQueue& Q = *Queue;
            std::vector<nodeInfo>& N = *Nodes;
            
            while(!Q.empty()){
                Q.pop();
            }

            N[O].dist = 0;
            Q.push(PQPair(O, 0));
            while ( !Q.empty() ){
                int u = Q.top().first;
                FPType Du = Q.top().second;
                Q.pop();

                if ( u == D ){ 
            StarLink *link = getInComeLink(D);
            FPType nextDest = link->getNodeFromIndex();
            Path path;
            while (link != NULL) {
                path.addLinkToPath(link);
                nextDest = link->getNodeFromIndex();
                link = getInComeLink(nextDest);
            }
            path.print();
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
                            Q.push(PQPair(v, Duv));
                            Scanned->push_back(std::pair<int, int>(u, v));
                        }
                    } // for each outgoing link
                } // if can visit node
            } // while !Q.empty()
        }

};

#endif
