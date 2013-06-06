#ifndef DAGRAPH_TAPAS
#define DAGRAPH_TAPAS

#include "DAGraph.h"
#include "ShortestPath.h"
#include "PASManager.h"

class DAGraphTapas : public DAGraph {
	public:
  		DAGraphTapas(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex, ShortestPath &shPath, PASManager &pasManager);
		~DAGraphTapas();
		
		bool moveFlow(int iter);
		
	private:
		ShortestPath &shPath_;
		PASManager &pasManager_;
		
};

#endif
