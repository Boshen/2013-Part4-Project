#ifndef _PATH_BASED_FLOW_MOVE_WITH_STEP_
#define _PATH_BASED_FLOW_MOVE_WITH_STEP_

#include "PathBasedFlowMove.h"
#include "StepSize.h"

class PathBasedFlowMoveWithStep : public PathBasedFlowMove {
	public:
		PathBasedFlowMoveWithStep(StepSize *stepSize, DescDirectionPath* pathDirectionAlgo);
		~PathBasedFlowMoveWithStep();
		
		bool executeFlowMove();
		
	private:
		StepSize *_stepSize;
};

#endif
