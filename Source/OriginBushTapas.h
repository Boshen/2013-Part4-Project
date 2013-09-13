#ifndef ORIGIN_BUSH_TAPAS
#define ORIGIN_BUSH_TAPAS

#include "OriginBush.h"
#include "DAGraphTapas.h"

class OriginBushTapas : public OriginBush {
	public:
		OriginBushTapas(int index, StarNetwork *net, ShortestPath *shPath, PASManager *pasManager);
		~OriginBushTapas();
		
		DAGraph* createNewDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol);
		void updateSet();
		bool improve();
		void removeUnusedLinks();
	
	private:
		DAGraphTapas *dag_;
		static ShortestPath *shPath_;
		static PASManager *pasManager_;
};

#endif
