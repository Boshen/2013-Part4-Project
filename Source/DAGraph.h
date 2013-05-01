#ifndef _D_A_GRAPH_
#define _D_A_GRAPH_

#include "StarNetwork.h"
#include "DAGraphNode.h"
#include "OriginBasedFlowMove.h"
#include "ODMatrix.h"
#include "UsedTypes.h"

class DAGraph {
	
	public:
		DAGraph(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex);
		virtual ~DAGraph();
		
		void addLink(StarLink *link);
		bool removeUnusedLinks(); 	

		// ascending and descending passes
		const std::list<StarLink*>& getIncomeLinks(int nodeIndex) const;
		const std::list<StarLink*>& getOutLinks(int nodeIndex) const;
		std::list<StarLink*> getOutLinksCopy(int nodeIndex) const;
		
		int beginAscPass();
		int getNextAscPass();
		int beginDescPass();
		int getNextDescPass();
		
		void topologicalSort();
		
		virtual bool moveFlow();
		
		void addOriginFlow(int linkIndex, FPType demand);
		
		void print() const;
		void printOriginFlow() const;
		FPType getOriginFlow(int linkIndex) const;
		
		// for bush improvement
		bool addBetterLinks();
		
		void buildMinMaxTrees(int destIndex);
		
		// for debugging
		void printShPath(int node);
		void printMaxShPath(int node);
		
	protected:
		
		static StarNetwork* getNet();
		static FPType getZeroFlow();
		FPType getDemand(int nodeIndex) const;
		int getOriginIndex() const;
		//void setOriginFlow(int index, FPType flow);
		
	private:
		int originIndex_;
		bool addedFromP2_;
		
		DAGraphNode **nodes_;
		int *nodeIndexes_;
		int nodeSize_;
		
		StarLink **links_;
		int linkSize_; 
		std::list<int> linkIndexes_;
		
		std::list<int> topOrder_;
		
		OriginBasedFlowMove *flowMove_;
		FPType *originFlows_;
		
		// for passes
		std::list<int>::iterator currNode_;
		std::list<int>::reverse_iterator currNodeDesc_;
		
		// for improving set
		std::list<int> p2Cont_;
		bool worthAdding(int linkIndex);
		bool addFromP2();
		
		// traversal of the links that are NOT in the bush
		int getNextNotInSet(int startIndex) const;
		bool isReachable(int nodeIndex) const;
		
		// for topological sort
		int clock_;
		void explore(int vertex, bool *visited);
		void preVisit(int vertex);
		void postVisit(int vertex);
		
		//static data
		static StarNetwork * net_;
		static ODMatrix *mat_;
		static FPType zeroFlow_;
		
		// to keep track of initialisation of static variables
		static bool wasInitialised_; 
		static void initialiseStaticMembers(StarNetwork *net, ODMatrix *mat, FPType zeroFlow);
};

#endif
