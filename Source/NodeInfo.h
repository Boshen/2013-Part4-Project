#ifndef NODE_INFO
#define NODE_INFO

#include <stdlib.h>
#include <list>

/** Internal utility structure that is usually used to store solution of the shortest path problem.
 */
struct nodeInfo {
	FPType dist; // current shortest distance to node. In case of generalized cost, it contains agreggated value.
	int linkIndex; // internal arc id
	//int index; //nodeIndex
};

/*struct nodeInfoWithPath {
	FPType dist; // current shortest distance to node. In case of generalized cost, it contains agreggated value.
	FPType time; // -1 if not defined
	FPType toll; // -1 if not defined
	std::list<int> arcsOfPath; // path is stored explicitly - it is needed in non-addtive case
	std::list<int> predNodesList;
};*/

#endif
