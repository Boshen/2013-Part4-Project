#ifndef _OD_SET_
#define _OD_SET_

#include "DescDirection.h"
#include "PathCost.h"
#include "LinkFncContainer.h"
#include "StarNetwork.h"
#include "ShortestPath.h"
#include "ConvMeasure.h"
#include "PathBasedFlowMove.h"
#include "DescDirectionPath.h"
#include "Derivative.h"
#include "LineSearch.h"
#include "StepSizeABC.h"
#include "Constants.h"
#include "PathAlgoCreator.h"

#include <stdlib.h>
#include <list>

class ODSet : public DescDirection {
	public:
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, Derivative *der, FPType *linkFlows, FPType *linkFlowsAux, LineSearch *lineSearch, PathAlgoCreator *algoCreator);
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, Derivative *der, FPType *linkFlows, FPType *linkFlowsAux, LineSearch *lineSearch, FPType sparsityPrecision, PathAlgoCreator *algoCreator);
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType *linkFlows, FPType *linkFlowsAux, FPType zeroFlow, PathAlgoCreator *algoCreator);
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType *linkFlows, FPType *linkFlowsAux, FPType zeroFlow, FPType alpha, FPType demand, PathAlgoCreator *algoCreator);
		~ODSet();
		
		int getIndex() const;
		int getDestIndex() const;
		int getOriginIndex() const;
		int getNbPaths() const;
		
		void addPath(Path *path);
		
		// iterate through paths
		Path* beginPath();
		Path* getNextPath();
		
		// for PathBasedAlgo
		void updateSet();
		bool improveSet();
		void removeUnusedPaths();
		bool equilibrate();
		void updateLinkCostsOfOD();
		void projectPathFlowOnLinks();
		
		void print();
		
		// from DescDirection
		FPType* getProjectedDirection();
		FPType getUpperBound();
		FPType* getLinkFlows();
		
		//for debugging
		FPType getFirstDirVal();
		
	private:
		StarNetwork *_net;
		LinkFncContainer *_linkFncCont;
		ShortestPath *_shPath;
		ConvMeasure *_conv;
		
		int _index;
		int _destIndex;
		int _originIndex;
		PathCost *_pathCost;
		FPType _minDist;
		FPType _maxDist;
		FPType _zeroFlow;
		
		PathBasedFlowMove *_flowMove;
		StepSizeABC *_stepSize;
		DescDirectionPath *_pathDirAlgo;

		std::list<Path*> _allPaths;
		std::list<Path*>::iterator _it;
		int _size;
		
		FPType *_linkFlows;
		FPType *_linkFlowsAux;
		int _nbLinks;
		
		std::list<StarLink*> _commonLinks;
		
		void initialiseObject(int index, int destIndex, int originIndex, PathCost *pathCost, LinkFncContainer *linkFncCont, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv,  FPType zeroFlow, FPType *linkFlows, FPType *linkFlowsAux, PathAlgoCreator *algoCreator);
		void calculateProjectedDirection();
		
};

#endif
