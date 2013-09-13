#ifndef _SHORTEST_PATH_
#define _SHORTEST_PATH_

#include "StarLink.h"

/** This is the abstract class that implements the interface for the shortest-path algorithms.
 */
class ShortestPath {
	
	public:
		virtual ~ShortestPath(){};
		
		// shortest path calculation
		virtual void calculate(int originIndex) =0; // shortest path from origin originIndex to all other nodes that are reachable from this origin
		virtual void calculate(int originIndex, int destIndex) {calculate(originIndex);}; // shortest path from origin originIndex to destination destIndex
		
		// interface to get calculated information
		virtual FPType getCost(int destIndex) const =0; // returns shortest path distance to node destIndex
		virtual StarLink* getInComeLink(int destIndex) const =0; // returns pointer to a link that belongs to the shortest path to node destIndex
									// MUST return NULL if the origin is passed or if destIndex ia not reachable from current origin 
		
		void printPath(int destIndex) const {
			StarLink *link = getInComeLink(destIndex);
			int nextDest = -1;
			std::string str;
			while (link != NULL) {
				str = link->toString() + " " + str;
				nextDest = link->getNodeFromIndex();
				link = getInComeLink(nextDest);
			}
			std::cout << str << std::endl;
		};
		
	protected:
		ShortestPath(){};

};

#endif
