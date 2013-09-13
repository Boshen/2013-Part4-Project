#ifndef PAS_
#define PAS_

#include "StarLink.h"
//#include "DAGraphTapas.h"
class DAGraphTapas;

#include <list>
#include <set>

class PAS {
	public:
		explicit PAS(FPType zeroFlow, FPType dirTol);
		~PAS();
		
		bool isUnused(int iter) const;
		//int getIndex() const;
		
		void pushFrontToCheap(StarLink *link);
		void pushFrontToExp(StarLink *link);
		void pushBackToCheap(StarLink *link);
		void pushBackToExp(StarLink *link);
		
		// for PASManager
		StarLink* getLastCheapLink();
		StarLink* getLastExpLink();
		
		bool addOrigin(DAGraphTapas *dag);
		
		void moveFlow(int iter);
		void recalcPASCosts();
		
		bool originIsIncluded(DAGraphTapas* dag);
		
		void addCheapLinksToBush(DAGraphTapas* dag);
		void deleteLinksFromBushes();
		
		//bool hasLink(StarLink *link) const;
		void deleteOrigin(DAGraphTapas* dag);
		//bool hasSegment(const std::list<StarLink*> &seg) const;
		bool originSetIsEmpty() const;
		
		bool checkIfEffective(FPType cost, FPType v, int index, DAGraphTapas* dag);
		//void deleteCheapLinksFromBush(DAGraphTapas* dag);
		
		void print() const;
		
	private:
		//int index_;
		std::list<StarLink*> segments_[2];
		//std::list<StarLink*> segExp_;
		std::set<DAGraphTapas*> relevantOrigins_; // set -> to have log n complexity on insertion
		int lastIterMove_;
		static FPType zeroFlow_;
		FPType cheapCost_;
		FPType expCost_;
		static FPType dirTol_;
		FPType totalShift_;
		int cheapSegm_;
		bool isUnused_;
		
		FPType calculateFlowShift();
		FPType calcSegCost(int index);
		
		bool checkIfCostEffective(FPType cost) const;
		bool checkIfFlowEffective(FPType v, int index, DAGraphTapas* dag) const;
		
};
#endif
