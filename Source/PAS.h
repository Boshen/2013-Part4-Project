#ifndef PAS_
#define PAS_

#include "StarLink.h"

#include <list>
#include <set>

class PAS {
	public:
		explicit PAS(int index, FPType zeroFlow);
		~PAS();
		
		bool isUnused(int iter) const;
		int getIndex() const;
		
		void pushFrontToCheap(StarLink *link);
		void pushFrontToExp(StarLink *link);
		
		void addOrigin(int index);
		
		void moveFlow(int iter);
		
		void print() const;
		
	private:
		int index_;
		std::list<StarLink*> segCheap_;
		std::list<StarLink*> segExp_;
		std::set<int> relevantOrigins_; // set -> to have log n complexity on insertion
		int lastIterMove_;
		static FPType zeroFlow_;
};
#endif
