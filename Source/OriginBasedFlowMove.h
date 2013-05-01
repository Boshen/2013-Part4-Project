#ifndef ORIGIN_BASED_FLOW_MOVE
#define ORIGIN_BASED_FLOW_MOVE

#include "StarLink.h"
#include "DAGraphNode.h"

class OriginBasedFlowMove {
	public:
		virtual ~OriginBasedFlowMove(){};
		//virtual void calcMinData(int index, StarLink* link) = 0;
		//virtual void calcMaxData(int index, StarLink* link) = 0;
		virtual bool performFlowMove(int index, int origin) = 0;
		//virtual DAGraphNode* createDagNode(int index, FPType demand) = 0;
		//virtual DAGraphNode** allocateNodesArray(int size) = 0;
		virtual void print() {};
		
	protected:
		OriginBasedFlowMove(){};
		
};
#endif
