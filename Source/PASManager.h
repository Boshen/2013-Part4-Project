#ifndef PAS_SET
#define PAS_SET

#include "ShortestPath.h"
#include "PAS.h"

#include <vector>
#include <tr1/unordered_map>

class DAGraphTapas;

class PASManager {
	public:
		explicit PASManager(const ShortestPath &shPath, FPType dirTol, int nbNodes, FPType mu, FPType v);
		~PASManager();
		
		void createNewPAS(DAGraphTapas *dag, StarLink *expLink, int mergingNodeIndex, int iter); // creates new PASes if possible
		//void deletePAS(int index); // deletes PAS if it is unused
		void deleteUnusedPASAndMoveFlow(int iter);
		
		// traversing the set - constant iterators. NULL - is a special value meaning the end of traversal
		PAS* beginPAS() const;
		PAS* getNextPAS() const;
		
		PAS* getRandomPAS() const;
		
		
		//PAS* getPASByIndex(int index) const;
		
		int getNbPAS() const;
		
		//void deleteMarkedPAS();
		
		//static void setRGAP0(FPType value); // TODO: it is not working at the moment
		
		void print() const;
		
	private:
		//FPType *originFlows_;
		const ShortestPath &shPath_; // for traversing the min-cost tree
		std::list<PAS*> listOfPas_; // list for the time being - probably another structure will be more efficient
		mutable std::list<PAS*>::const_iterator curPAS_; // for iterating
		FPType dirTol_;
		const int nbNodes_;
		//static FPType RGAP0_;
		const FPType mu_;
		const FPType v_;
		
		// for sh path
		//std::set<int> setOfNodes_;
		std::tr1::unordered_map<int, int> setOfNodes_;
		
		PAS* pasExist(StarLink* cheapLink, StarLink* expLink);
		bool nodeBelongsToShPath(int nodeIndex, int mergingNodeIndex);
		void createExpSegment(PAS *pas, const std::vector<StarLink*> &checkedLinks, int divergeNode, int mergingNodeIndex, DAGraphTapas *dag);
		void createCheapSegment(PAS *pas, int divergeNode, int mergingNodeIndex);
		void prepareShPathStructure(int mergingNodeIndex);
		//PAS* createUsualPAS(DAGraphTapas *dag, StarLink *expLink, int mergingNodeIndex, FPType reducedCost);
		PAS* createPAS(DAGraphTapas *dag, StarLink *expLink, int mergingNodeIndex, bool (*checkPtr)(FPType originFlow, FPType thr));
		
		FPType calculateReducedCost(StarLink *expLink);
		FPType calcThreshold(int iter);
		
		//bool checkThreshold(FPType originFlow, FPType thr) {return originFlow >= thr;};
		//bool checkThresholdFake(FPType originFlow, FPType thr) {return true;};
		
		/*static bool checkThresholdCall(void* pt2Object, FPType originFlow, FPType thr) {
			PASManager* myself = (PASManager*) Object;
			myself->checkThreshold(originFlow);
		};
		
		static bool checkThresholdCall(void* pt2Object, FPType originFlow, FPType thr) {};*/
};

#endif
