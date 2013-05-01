#ifndef _PATH_BASED_FLOW_MOVE_PE_
#define _PATH_BASED_FLOW_MOVE_PE_

#include "PathBasedFlowMove.h"
#include "DescDirectionPathScaled.h"

class PathBasedFlowMovePE : public PathBasedFlowMove {
	public:
		PathBasedFlowMovePE(DescDirectionPath* pathDirectionAlgo);
		~PathBasedFlowMovePE();
		
		bool executeFlowMove();
};

#endif
