#ifndef _PATH_DERIVATIVE_
#define  _PATH_DERIVATIVE_

#include "Path.h"

class PathDerivative {
	public:
		PathDerivative(int nbLinks);
		~PathDerivative();
		FPType calculate(Path *path, Path *minPath);
		FPType calculateForDisjoint(const std::list<StarLink*> &list);
		FPType calculateForDisjoint2(const std::list<StarLink*> &list1, const std::list<StarLink*> &list2);
		
	private:
		const int _nbLinks;
};

#endif
