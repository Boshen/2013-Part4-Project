#ifndef ORIGIN_BUSH_LUCE
#define ORIGIN_BUSH_LUCE

#include "OriginBush.h"
#include "DAGraphLUCE.h"

class OriginBushLUCE : public OriginBush {
	public:
		explicit OriginBushLUCE(int index, StarNetwork *net);
		~OriginBushLUCE();
		
		void updateSet();
		
		void allocateDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol);
		
	private:
		DAGraphLUCE *dag_;
		
};

#endif
