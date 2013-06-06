#ifndef PAS_SET
#define PAS_SET

#include "ShortestPath.h"
#include "PAS.h"
#include "DAGraph.h"

#include <vector>

class PASManager {
	public:
		explicit PASManager(FPType *originFlows, const ShortestPath &shPath);
		~PASManager();
		
		void createNewPAS(const DAGraph &dag, int mergingNodeIndex); // creates new PASes if possible
		void deletePAS(int index); // deletes PAS if it is unused
		
		// traversing the set - constant iterators. NULL - is a special value meaning the end of traversal
		PAS* beginPAS() const;
		PAS* getNextPAS() const;
		
		PAS* getPASByIndex(int index) const;
		
		int getNbPAS() const;
		
		void print() const;
		
	private:
		FPType *originFlows_;
		const ShortestPath &shPath_; // for traversing the min-cost tree
		std::vector<PAS*> listOfPas_; // vector for the time being - probably another structure will be more efficient
		mutable int curPAS_; // for iterating
		
};

#endif
