#ifndef OD_SET_WITH_STEP
#define OD_SET_WITH_STEP

#include "ODSet.h"
#include "DescDirection.h"
#include "PathBasedFlowMoveWithStep.h"

class ODSetWithStep : public ODSet, public DescDirection {
	public:
		ODSetWithStep(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows, PathBasedFlowMoveWithStep* flowMove);
		~ODSetWithStep();
		
		// from DescDirection
		FPType* getProjectedDirection();
		FPType getUpperBound();
		FPType* getLinkFlows();
		int getSize();
		int* getIndexes();
		
	private:
		FPType *_projDir;
		int *_indexes;
		int _size;
		static PathBasedFlowMoveWithStep* flowMoveStep_;
		
		void calculateProjectedDirection();
		void deallocProjectedDirection();
};

#endif
