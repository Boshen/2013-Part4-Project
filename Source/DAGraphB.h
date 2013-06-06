#ifndef DAGRAPH_B
#define DAGRAPH_B

#include "DAGraph.h"
#include "Path.h"

class DAGraphB : public DAGraph {
	public: 
		
		DAGraphB(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex, bool useMultiStep);
		~DAGraphB();
		
		bool moveFlow(int iter);
		
		void print() const;
		
	private:
		
		//const DAGraphNode * const * const nodes_; // memory is allocated and pointer is kept, but class 
						// who called creation is responsible for deallocation
		//FPType *originFlows_;
		bool useMultiStep_;
		
		bool performFlowMove(int index, int origin);
		FPType calcFlowStep(Path* minPath, Path* maxPath, FPType minDx) const;
		void addFlow(StarLink *link, FPType dFlow);
		FPType calcDistGap(Path *path, FPType dist);
		//void restoreFlows(Path *path, FPType *flowCopy);
		//void restoreFlowsOrigin(Path *path, FPType *flowCopy);
		FPType calculateMinFlowMove(int index, FPType demand) const;
		void printMinPathOFlows(int index) const;
		void printMaxPathOFlows(int index) const;
		
		// for debugging
		int originIndex_;
		
		static FPType zeroFlow_;
		static FPType dirTol_;
};

#endif
