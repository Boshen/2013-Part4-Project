#ifndef OD_SET_GP_APP3
#define OD_SET_GP_APP3

#include "ODSet.h"
#include "PathBasedFlowMoveGP.h"
#include "ODMatrix.h"

class ODSetGPApp3 : public ODSet{
	public:
		ODSetGPApp3(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows, PathBasedFlowMoveGP* flowMove, ODMatrix *mat);
		~ODSetGPApp3();
		
	private:
		static ODMatrix* mat_;
		static PathBasedFlowMoveGP* flowMoveGP_;
		virtual void calculateProjectedDirection();
		virtual void deallocProjectedDirection();
};

#endif
