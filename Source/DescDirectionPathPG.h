#ifndef _DESC_DIRECTION_PATH_PG_
#define _DESC_DIRECTION_PATH_PG_

#include "DescDirectionPath.h"

class DescDirectionPathPG : public DescDirectionPath {
	public:
		DescDirectionPathPG(FPType delta);
		~DescDirectionPathPG();
		PathAndDirection** createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated);
};

#endif
