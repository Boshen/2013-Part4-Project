#ifndef _DESC_DIRECTION_PATH_PE_SCALED_
#define _DESC_DIRECTION_PATH_PE_SCALED_

#include "DescDirectionPath.h"

class DescDirectionPathScaled : public DescDirectionPath {
	public:
		DescDirectionPathScaled(DescDirectionPath *pathDir, int nbLinks, FPType delta); // responsible for destruction of pathDir
		~DescDirectionPathScaled();
		PathAndDirection** createPathDirection(int &size, const std::list<Path*> &paths, bool &isEquilibrated);
		
	private:
		DescDirectionPath *_pathDir;
		int _nbLinks;
};

#endif
