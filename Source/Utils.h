#ifndef _UTILS_
#define _UTILS_

#include "Path.h"
#include "PathBasedFlowMove.h"
#include "StarNetwork.h"
#include "ODMatrix.h"
#include "SpiessFncCreator.h"
#include "PathSet.h"

#include <stdlib.h>
#include <list>
#include <string>

namespace Utils {


	void getDisjointLinks(Path *path1, Path *path2, std::list<StarLink*> &list, int nbLinks);

	void getCommonLinks(PathBasedFlowMove *paths, std::list<StarLink*> &list, int nbLinks);

	FPType checkFeasibility(StarNetwork *net, ODMatrix *mat);

	int parseSpiessFnc(const std::string& input, SpiessFncCreator &spCreator, bool constFnc = false);
	
	bool checkPathSetFeasibility(PathSet * pathSet, ODMatrix * mat, StarNetwork * net);
	
	bool checkPathIsValid(Path * path, int originIndex, int destIndex, int nbNodes);
	
	FPType calculate(Path *path, Path *minPath, int nbLinks);
	
	FPType calculateForDisjoint(const std::list<StarLink*> &list);
	
	FPType calculateForDisjoint2(const std::list<StarLink*> &list1, const std::list<StarLink*> &list2);
}

#endif
