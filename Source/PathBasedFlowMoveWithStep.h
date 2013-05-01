#ifndef _PATH_BASED_FLOW_MOVE_WITH_STEP_
#define _PATH_BASED_FLOW_MOVE_WITH_STEP_

#include "PathBasedFlowMove.h"
#include "StepSizeABC.h"

class PathBasedFlowMoveWithStep : public PathBasedFlowMove {
	public:
		PathBasedFlowMoveWithStep(StepSizeABC *stepSize, DescDirectionPath* pathDirectionAlgo);
		~PathBasedFlowMoveWithStep();
		
		bool executeFlowMove();
		
	private:
		StepSizeABC *_stepSize;
};

#endif
