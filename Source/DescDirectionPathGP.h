#ifndef _DESC_DIRECTION_PATH_GP_
#define _DESC_DIRECTION_PATH_GP_

#include "DescDirectionPath.h"

class DescDirectionPathGP : public DescDirectionPath {
	public:
		DescDirectionPathGP(FPType delta);
		~DescDirectionPathGP();
		PathAndDirection** createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated);
};

#endif
