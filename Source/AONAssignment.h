#ifndef _AON_ASSIGNMENT_
#define _AON_ASSIGNMENT_

#include "InitialiseSolution.h"
#include "StarNetwork.h"
#include "ODMatrix.h"
#include "ShortestPath.h"
#include "UsedTypes.h"

class AONAssignment {
	public:
		AONAssignment(ODMatrix *mat, ShortestPath *shPath);
		~AONAssignment();
		
		FPType execute(InitialiseSolution *solution);
		void executeForOriginBasedAlgo(InitialiseSolution *solution, StarNetwork *net);
		
	private:
		ODMatrix *_mat;
		ShortestPath *_shPath;
};

#endif
