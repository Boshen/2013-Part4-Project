#ifndef ALGO_B
#define ALGO_B

#include "OriginBasedFlowMove.h"
#include "Path.h"
#include "UsedTypes.h"

class AlgorithmB : public OriginBasedFlowMove {
	public:
		AlgorithmB(FPType *originFlows, int originIndex, FPType zeroFlow, FPType dirTol, DAGraphNode * const * const nodes);
		~AlgorithmB();
		
		//void calcMinData(int index, StarLink* link);
		//void calcMaxData(int index, StarLink* link);
		
		bool performFlowMove(int index, int origin);
		//DAGraphNode* createDagNode(int index, FPType demand);
		//DAGraphNode** allocateNodesArray(int size);
		
		void print() const;
		
	private:
		const DAGraphNode * const * const nodes_; // memory is allocated and pointer is kept, but class 
						// who called creation is responsible for deallocation
		FPType *originFlows_;
		FPType calcFlowStep(Path* minPath, Path* maxPath, FPType minDx) const;
		void addFlow(StarLink *link, FPType dFlow);
		FPType calcDistGap(Path *path, FPType dist);
		void restoreFlows(Path *path, FPType *flowCopy);
		void restoreFlowsOrigin(Path *path, FPType *flowCopy);
		FPType calculateMinFlowMove(int index, FPType demand) const;
		void printMinPathOFlows(int index) const;
		void printMaxPathOFlows(int index) const;
		
		// for debugging
		int originIndex_;
		
		static FPType zeroFlow_;
		static FPType dirTol_;
		
};

#endif
