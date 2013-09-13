#ifndef _D_A_GRAPH_
#define _D_A_GRAPH_

#include "StarNetwork.h"
#include "DAGraphNode.h"
//#include "OriginBasedFlowMove.h"
#include "ODMatrix.h"
#include "UsedTypes.h"

class DAGraph {
	
	public:
		
		virtual ~DAGraph();
		
		void addLink(StarLink *link);
		bool removeUnusedLinks(); 
		bool removeUnusedLinks(const std::list<StarLink*> &links); 	

		// ascending and descending passes
		//const std::list<StarLink*>& getIncomeLinks(int nodeIndex) const;
		void getOutLinks(int nodeIndex, std::list<StarLink*>& listRef);
		void getInLinks(int nodeIndex, std::list<StarLink*>& listRef);
		std::list<StarLink*> getOutLinksCopy(int nodeIndex) const;
		std::list<StarLink*> getInLinksCopy(int nodeIndex) const;
		
		int beginAscPass();
		int getNextAscPass();
		int beginDescPass();
		int getNextDescPass();
		
		bool topologicalSort();
		
		virtual bool moveFlow(int iter) = 0;
		
		void addOriginFlow(int linkIndex, FPType demand);
		void addOriginFlow(StarLink* link, FPType demand);
		void setOriginFlowToZero(int linkIndex);
		
		void print() const;
		void printOriginFlow() const;
		FPType getOriginFlow(int linkIndex) const;
		int getOriginIndex() const;
			
		// for bush improvement
		bool addBetterLinks();
		
		void buildMinMaxTrees(int destIndex);
		
		// for debugging
		void printShPath(int node);
		void printMaxShPath(int node);
		
		static FPType getZeroFlow();
		FPType checkOFlowsFeasibility();
		
	protected:
		
		DAGraph(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, int originIndex);
		
		static StarNetwork* getNet();
		
		FPType getDemand(int nodeIndex) const;
		
		void setOriginFlow(int index, FPType flow);
		DAGraphNode* const getNode(int index) const;
		
		void removeFromLinkIndexes(int index);
		bool removeLink(int index);
		virtual bool handleBackEdge(StarLink* link);
		virtual void handleExploredLink(StarLink* link) {}; // does nothing by default
		virtual bool checkPositiveFlow(int linkIndex) {return true;};
		
		
		// TODO: for debugging
		static StarNetwork * net_;
		static ODMatrix *mat_;
	
		// TODO: temporary solution - just for iteration without top.order
		int *nodeIndexes_;
		int nodeSize_;
		
		//static data
		static FPType zeroFlow_;
		
	private:
		int originIndex_;
		bool addedFromP2_;
		
		FPType *originFlows_;
		DAGraphNode **nodes_;
		
		StarLink **links_;
		int linkSize_; 
		std::list<int> linkIndexes_;
		
		std::list<int> topOrder_;
		
		//OriginBasedFlowMove *flowMove_;
		
		
		// for passes
		std::list<int>::iterator currNode_;
		std::list<int>::reverse_iterator currNodeDesc_;
		
		// for improving set
		std::list<int> p2Cont_;
		
		bool worthAdding(StarLink* link);
		bool addFromP2();
		
		// traversal of the links that are NOT in the bush
		int getNextNotInSet(int startIndex) const;
		bool isReachable(StarLink* link) const;
		
		// for topological sort
		int clock_;
	//	bool backEdgeDetected_;
	
		bool explore(int vertex, bool *visited);
		void preVisit(int vertex);
		void postVisit(int vertex);
		
		// to keep track of initialisation of static variables
		static bool wasInitialised_; 
		static void initialiseStaticMembers(StarNetwork *net, ODMatrix *mat, FPType zeroFlow);
		
};

#endif
