#ifndef _DESC_DIRECTION_PATH_PE_APPONE_
#define _DESC_DIRECTION_PATH_PE_APPONE_

#include "DescDirectionPath.h"

class DescDirectionPathPE : public DescDirectionPath {
	public:
		DescDirectionPathPE(FPType delta);
		~DescDirectionPathPE();
		PathAndDirection** createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated);
		
};

#endif
