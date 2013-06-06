#ifndef ORIGIN_BUSH_TAPAS
#define ORIGIN_BUSH_TAPAS

#include "OriginBush.h"
#include "DAGraphTapas.h"

class OriginBushTapas : public OriginBush {
	public:
		OriginBushTapas(int index, StarNetwork *net);
		~OriginBushTapas();
		
		DAGraph* createNewDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol);
	
	private:
		DAGraphTapas *dag_;
};

#endif
