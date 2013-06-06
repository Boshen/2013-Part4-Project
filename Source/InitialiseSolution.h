#ifndef _INITIALISE_SOLUTION_
#define _INITIALISE_SOLUTION_

#include "ShortestPath.h"
#include "PairOD.h"

#include <stdlib.h>

class InitialiseSolution {
	public:
		virtual ~InitialiseSolution(){};
		virtual void initialiseItself(StarLink* link, PairOD *dest) = 0;
		void initialiseSolution(PairOD *dest, ShortestPath *shPath){
			StarLink *link = shPath->getInComeLink(dest->getIndex());
			int nextDest = link->getNodeFromIndex();
			while (link != NULL) {
				//std::cout << "nextDest = " << nextDest << std::endl;
				initialiseItself(link, dest);
				nextDest = link->getNodeFromIndex();
				link = shPath->getInComeLink(nextDest);
			}
		};
		
		
	protected:
		InitialiseSolution(){};
		
};

#endif
