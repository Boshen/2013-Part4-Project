#ifndef _ORIGIN_BUSH_
#define _ORIGIN_BUSH_

#include "DAGraph.h"

class OriginBush {
	
	public:
		
		OriginBush(int index, StarNetwork *net);
		virtual ~OriginBush();
		
		virtual void allocateDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol);
		
		virtual void updateSet();
		bool equilibrate(bool wasImproved);
		bool improve();
		void removeUnusedLinks();
		
		void addLink(StarLink *link);
		
		void addOriginFlow(int linkIndex, FPType demand);
		FPType getOriginFlow(int linkIndex) const;
		
		void print();
		int getOriginIndex() const;
		void printOriginFlow() const;
		
		static void updateLinkCosts();
		static StarNetwork* getNet();
		
	private:
		
		DAGraph *daGraph_;
		
		int index_;
		bool topSortUpToDate_;
		
		//static data that is the same for all objects
		static StarNetwork *net_;
		static FPType *linkFlows_;
		
		// to keep track of initialisation of static variables
		static bool wasInitialised_; 
		static void initialiseStaticMembers(StarNetwork *net);
		
		// to deallocated dynamic static members
		static int state_;
};

#endif
