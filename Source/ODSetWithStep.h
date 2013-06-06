#ifndef OD_SET_WITH_STEP
#define OD_SET_WITH_STEP

#include "ODSet.h"
#include "DescDirection.h"
#include "Derivative.h"
#include "LineSearch.h"
#include "StepSize.h"

class ODSetWithStep : public ODSet, public DescDirection {
	public:
		ODSetWithStep(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, Derivative *der, FPType *linkFlows, LineSearch *lineSearch, PathAlgoCreator *algoCreator);
		//ODSetWithStep(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, Derivative *der, FPType *linkFlows, LineSearch *lineSearch, FPType sparsityPrecision, PathAlgoCreator *algoCreator);
		~ODSetWithStep();
		
		// from DescDirection
		FPType* getProjectedDirection();
		FPType getUpperBound();
		FPType* getLinkFlows();
		int getSize();
		int* getIndexes();
		
	private:
		StepSize *_stepSize;
		FPType *_projDir;
		int *_indexes;
		int _size;
		
		void calculateProjectedDirection();
};

#endif
