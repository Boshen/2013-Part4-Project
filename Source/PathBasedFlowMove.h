#ifndef _PATH_BASED_FLOW_MOVE_
#define _PATH_BASED_FLOW_MOVE_

#include "PathAndDirection.h"
#include "DescDirectionPath.h"

class PathBasedFlowMove {
	public:
		virtual ~PathBasedFlowMove(){};
		
		bool calculatePathDirection(const std::list<Path*> &paths);
		virtual bool executeFlowMove() = 0;
		
		// to iterate through path-based direction
		PathAndDirection* beginPathDirection();
		PathAndDirection* getNextPathDirection();
		
	protected:
		
		PathBasedFlowMove(DescDirectionPath* pathDirectionAlgo);
		
		PathAndDirection** _pathDirection;
		int _size;
		int _currDirection;
		
	private:
		
		DescDirectionPath* _pathDirectionAlgo; // is deallocated in ObjectManager
};

#endif
