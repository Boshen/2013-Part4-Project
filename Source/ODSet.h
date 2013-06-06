#ifndef _OD_SET_
#define _OD_SET_

//#include "DescDirection.h"
#include "PathCost.h"
#include "LinkFncContainer.h"
#include "StarNetwork.h"
#include "ShortestPath.h"
#include "ConvMeasure.h"
#include "PathBasedFlowMove.h"
#include "DescDirectionPath.h"
#include "Constants.h"
#include "PathAlgoCreator.h"

#include <stdlib.h>
#include <list>

class ODSet { 
	public:
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType zeroFlow, FPType *linkFlows, PathAlgoCreator *algoCreator);
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType *linkFlows, FPType zeroFlow, PathAlgoCreator *algoCreator);
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType *linkFlows, FPType zeroFlow, FPType alpha, FPType demand, PathAlgoCreator *algoCreator);
		virtual ~ODSet();
		
		int getIndex() const;
		int getDestIndex() const;
		int getOriginIndex() const;
		int getNbPaths() const;
		
		void addPath(Path *path);
		
		// iterate through paths
		Path* beginPath() const;
		Path* getNextPath() const;
		
		// for PathBasedAlgo
		void updateSet();
		bool improveSet();
		void removeUnusedPaths();
		bool equilibrate();
		void updateLinkCostsOfOD();
		void projectPathFlowOnLinks();
		
		void print() const;
		
		//for debugging
		//FPType getFirstDirVal();
		
	protected:
		
		virtual void calculateProjectedDirection() {}; // does nothing by default - hook method for algos with step size
		
		PathBasedFlowMove *_flowMove;
		FPType *_linkFlows;
		int _nbLinks;
		std::list<StarLink*> _commonLinks;
			
	private:
		StarNetwork *_net;
		ShortestPath *_shPath;
		ConvMeasure *_conv;
		
		int _index;
		int _destIndex;
		int _originIndex;
		PathCost *_pathCost;
		FPType _minDist;
		FPType _zeroFlow;
		
		std::list<Path*> _allPaths;
		mutable std::list<Path*>::const_iterator _it;
		int _size;
		
		void initialiseObject(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv,  FPType zeroFlow, FPType *linkFlows, PathAlgoCreator *algoCreator);
		
};

#endif
