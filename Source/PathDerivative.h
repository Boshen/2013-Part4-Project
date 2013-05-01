#ifndef _PATH_DERIVATIVE_
#define  _PATH_DERIVATIVE_

#include "Path.h"

class PathDerivative {
	public:
		PathDerivative(int nbLinks);
		~PathDerivative();
		FPType calculate(Path *path, Path *minPath);
		
	private:
		int _nbLinks;
};

#endif
