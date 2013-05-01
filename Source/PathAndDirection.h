#ifndef _PATH_AND_DIRECTION_
#define _PATH_AND_DIRECTION_

#include "Path.h"

class PathAndDirection {
	public:
		PathAndDirection();
		~PathAndDirection();
		
		Path* getPath() const;
		FPType getDirectionValue() const;
		
		void setPath(Path *path);
		void setDirection(FPType direction);
		
	private:
		Path* _path;
		FPType _directionVal;
};

#endif
