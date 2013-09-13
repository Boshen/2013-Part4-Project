#ifndef _PATH_BASED_FLOW_MOVE_GP_
#define _PATH_BASED_FLOW_MOVE_GP_

#include "PathBasedFlowMove.h"

class PathBasedFlowMoveGP : public PathBasedFlowMove {
	public:
		PathBasedFlowMoveGP(FPType alpha, DescDirectionPath* pathDirectionAlgo);
		~PathBasedFlowMoveGP();
		
		bool executeFlowMove();
		void setDemand(FPType demand);
		
	private:
		FPType _alpha;
		FPType _demand;
};

#endif
