#ifndef _PATH_SET_
#define _PATH_SET_

#include "InitialiseSolution.h"
#include "ODSet.h"
#include "ODMatrix.h"
#include "PathCost.h"
#include "Derivative.h"
#include "LineSearch.h"

class PathSet : public InitialiseSolution {
	public:
		
		PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, Derivative *der, LineSearch *lineSearch, PathAlgoCreator *algoCreator);
		//PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, Derivative *der, LineSearch *lineSearch, FPType sparsityPrecision, PathAlgoCreator *algoCreator);
		PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, FPType zeroFlow, PathAlgoCreator *algoCreator);
		PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost, FPType zeroFlow, FPType alpha, PathAlgoCreator *algoCreator);
		
		virtual ~PathSet();
		
		virtual void initialise();
		
		void initialiseItself(StarLink* link, PairOD *dest);
		
		// iterate through path set
		ODSet* beginSet();
		ODSet* getNextSet();
		
		bool isConverged() const;
		FPType getGap() const;
		
		void print();
		
		//void updateLinkCosts();
		
		//FPType getMaxDiff();
		void printNet();
		
	protected: //KR
		StarNetwork *_net;
		ODMatrix *_mat;
		ShortestPath *_shPath;
	private:
		ODSet **_odSetList;
		ConvMeasure *_conv;
		int _size;
		Path *_currPath;
		PathCost *_pathCost;
		
		FPType *_linkFlows;
		FPType *_linkFlowsAux;
		int _nbLinks;
		
		int _currSetIndex;
		
		//LinkFncContainer *_linkFncCont;
		
		void initialiseObject(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, ConvMeasure *conv, PathCost *pathCost);
};

#endif
