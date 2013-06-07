#ifndef _SH_PATH_INTERFACE_
#define _SH_PATH_INTERFACE_

#include <vector>
#include <queue>
#include <limits>
#include <cassert>
#include <algorithm>
#include <cstring>
#include "../ShortestPath.h"

#include "../StarNetwork.h"
#include "../NodeInfo.h"

namespace ShPath {
    const FPType FPType_Max = std::numeric_limits<FPType>::max();

    typedef std::pair<FPType, int> PQPair;

    class Prioritize{
        public:
            bool operator() ( const PQPair& p1, const PQPair& p2){
                return p1.first > p2.first;
            }
    };

    typedef std::priority_queue<PQPair, std::vector<PQPair>, Prioritize > PriorityQueue;

    struct ValueKey {
        FPType d; // dist
        int u; // node
        ValueKey(FPType _d, int _u) : d(_d), u(_u){}
        // The relation establishes the order in the PriorityQueue
        bool operator<(ValueKey const & rhs) const {
            return d < rhs.d;
        }
    };


}



class ShPathInterface : public ShortestPath {

    protected:
        enum Label { UNREACHED, SCANNED, LABELED };

        int _nNodes;
        std::vector<FPType> *LabelVector;
        std::vector<int> *Predecessors;
        std::vector<Label> *Labels;
        StarNetwork *_netPointer;

        inline void initNodes(){
            std::fill(LabelVector->begin(), LabelVector->end(),  ShPath::FPType_Max);
            std::fill(Predecessors->begin(), Predecessors->end(),  -1);
        }

    public:
        ShPathInterface(StarNetwork *netPointer) : _netPointer(netPointer) {
            _nNodes = _netPointer->getNbNodes();

            LabelVector = new std::vector<FPType>(_nNodes);
            Predecessors = new std::vector<int>(_nNodes);
            Labels = new std::vector<Label>(_nNodes);

        };

        ~ShPathInterface(){
            delete LabelVector;
            delete Predecessors;
            delete Labels;
        }

        virtual void calculate(int originIndex) =0;
        virtual void calculate(int originIndex, int destIndex) =0;

        FPType getCost(int destIndex) const{
            assert((destIndex >= 0) && (destIndex < _nNodes));
            return (*LabelVector)[destIndex];
        }

        StarLink* getInComeLink(int destIndex) const{
            assert((destIndex >= 0) && (destIndex < _nNodes));
            int linkIndex = (*Predecessors)[destIndex];
            return  linkIndex == -1 ?  NULL :  _netPointer->getLink(linkIndex);
        }

};

#endif
