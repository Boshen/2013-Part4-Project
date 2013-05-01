#ifndef _PATH_
#define _PATH_

#include "StarLink.h"

#include <stdlib.h>
#include <list>

class Path {
	public:
		Path(); 
		~Path();
		
		// setters
		void setFlow(FPType flow);
		void setPrevFlow(FPType prevFlow); // is used only in path-based algos
		void setCurrCost(FPType cost);
		void addLinkToPath(StarLink *link);
		
		// getters
		FPType getFlow() const;
		FPType getPrevFlow() const;
		FPType getCurrCost() const;
		
		// go through path
		StarLink* beginLink() const;
		StarLink* getNextLink() const; 
		
		bool isEmpty() const;
		int size() const;
		
		void print();
		
	private:
		std::list<StarLink*> _links;
		FPType _flow;
		FPType _prevFlow;
		FPType _currCost;
		
		mutable std::list<StarLink*>::const_iterator _it;
};

#endif
