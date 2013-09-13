#ifndef _ASTAR_
#define _ASTAR_

#include <vector>
#include <queue>
#include <limits>
#include <cassert>
#include "ShortestPath.h"
#include "StarNetwork.h"
#include "ODMatrix.h"

class Astar : public ShortestPath {
    private:

        typedef std::pair<FPType, int> PQPair;

        class Prioritize{
            public:
                bool operator() ( const PQPair& p1, const PQPair& p2){
                    return p1.first > p2.first;
                }
        };

        typedef std::priority_queue<PQPair, std::vector<PQPair>, Prioritize > PriorityQueue;


        PriorityQueue *Queue;

        std::vector<FPType> *zeroFlowTimes;
        std::vector<FPType> *LabelVector;
        std::vector<int> *Predecessors;

        int _nbDests;
        int _nbNodes;

        void initNodes();

        StarNetwork *_netPointer;

    public:
        Astar(StarNetwork* _netPointer, ODMatrix* _odMatrix);
        ~Astar();

        void calculate(int O);
        void calculate(int O, int D);
        FPType getCost(int destIndex) const;
        StarLink* getInComeLink(int destIndex) const;

};

#endif
