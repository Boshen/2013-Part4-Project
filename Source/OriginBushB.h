#ifndef ORIGIN_BUSH_B
#define ORIGIN_BUSH_B

#include "OriginBush.h"
#include "DAGraphB.h"

class OriginBushB : public OriginBush {
	public:
		OriginBushB(int index, StarNetwork *net, bool useMultiStep);
		~OriginBushB();
		
		DAGraph* createNewDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol);
	
	private:
		DAGraphB *dag_;
		static bool useMultiStep_;
};

#endif
