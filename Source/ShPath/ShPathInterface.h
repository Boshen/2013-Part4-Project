#ifndef _SH_PATH_INTERFACE_
#define _SH_PATH_INTERFACE_

#include <vector>
#include <cassert>
#include <limits>
#include "../ShortestPath.h"

#include "../StarNetwork.h"
#include "../NodeInfo.h"

using std::vector;
// Label for dijkstra algorithm
enum Label { UNREACHED, LABELED, SCANNED };

struct ValueKey {
    int u; // node
    FPType d; // dist
    ValueKey(int _u, FPType _d) : u(_u), d(_d){}
    // The relation establishes the order in the PriorityQueue
    inline bool operator<(ValueKey const & rhs) const {
        if (d == rhs.d)
                return u < rhs.u;
        else
                return d < rhs.d; 
    }
};

class ShPathInterface : public ShortestPath {
	
    public:
        ShPathInterface(StarNetwork *netPointer) : _netPointer(netPointer) {
            _nNodes = _netPointer->getNbNodes();
            Nodes = new vector<nodeInfo>(_nNodes);
            Scanned = new std::vector< std::pair<int, int> >();
        };

        ~ShPathInterface(){
            delete Nodes; 
            delete Scanned;
        }

        virtual void calculate(int originIndex) =0;
        virtual void calculate(int originIndex, int destIndex) =0;

        FPType getCost(int destIndex) const{
            assert((destIndex >= 0) && (destIndex < _nNodes));
            return (*Nodes)[destIndex].dist;
        }

        StarLink* getInComeLink(int destIndex) const{
            assert((destIndex >= 0) && (destIndex < _nNodes));
            int linkIndex = (*Nodes)[destIndex].linkIndex;
            if (linkIndex == -1) return NULL;
            return _netPointer->getLink(linkIndex); 
        }

        std::vector< std::pair<int, int> > *Scanned;
    protected:
        vector<nodeInfo> *Nodes;
        StarNetwork *_netPointer;
        int _nNodes;


        void initNodes(){
            for (int i = 0; i < _nNodes; i++){
                (*Nodes)[i].dist = std::numeric_limits<FPType>::max();
                (*Nodes)[i].linkIndex = -1;
            }
        }
};

#endif
