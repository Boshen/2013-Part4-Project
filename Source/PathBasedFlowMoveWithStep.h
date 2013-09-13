#ifndef _PATH_BASED_FLOW_MOVE_WITH_STEP_
#define _PATH_BASED_FLOW_MOVE_WITH_STEP_

#include "PathBasedFlowMove.h"
#include "StepSize.h"

class PathBasedFlowMoveWithStep : public PathBasedFlowMove {
	public:
		PathBasedFlowMoveWithStep(StepSize *stepSize, DescDirectionPath* pathDirectionAlgo, FPType zeroFlow);
		~PathBasedFlowMoveWithStep();
		
		bool executeFlowMove();
		void setDescDirection(DescDirection* dir);
		
	private:
		StepSize *stepSize_;
		const FPType zeroFlow_;
		DescDirection* dir_;
};

#endif
