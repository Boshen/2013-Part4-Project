#ifndef DAGRAPH_TAPAS
#define DAGRAPH_TAPAS

#include "DAGraph.h"
#include "ShortestPath.h"
#include "PASManager.h"

class DAGraphTapas : public DAGraph {
	public:
  		explicit DAGraphTapas(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex, ShortestPath *shPath, PASManager *pasManager);
		~DAGraphTapas();
		
		bool moveFlow(int iter);
		void setMinShift(FPType value);
		FPType getMinShift();
		
		void removeCyclicFlows();		
		
	private:
		static ShortestPath *shPath_;
		static PASManager *pasManager_;
		FPType minShift_;
		std::list<StarLink*> exploredLinks_;
		
		bool handleBackEdge(StarLink* link);
		void handleExploredLink(StarLink* link);
		bool checkPositiveFlow(int linkIndex);
		//std::list<StarLink*> findSegmentOnCycle(StarLink* link);
		
};

#endif
