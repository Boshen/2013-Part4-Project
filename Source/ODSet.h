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
		ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows, PathBasedFlowMove* flowMove);
		//ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType *linkFlows, FPType zeroFlow, DescDirectionPath* descDirPath);
		//ODSet(int index, int destIndex, int originIndex, PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType *linkFlows, FPType zeroFlow, FPType alpha, FPType demand, DescDirectionPath* descDirPath);
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
		virtual void deallocProjectedDirection() {}; // does nothing by default - hook method for algos with step size
		
		
		FPType *_linkFlows;
		const int _nbLinks;
		
		const int _destIndex;
		const int _originIndex;
			
	private:
		static StarNetwork *_net;
		static ShortestPath *_shPath;
		
		const int _index;
		
		static PathCost *_pathCost;
		FPType _minDist;
		static FPType _zeroFlow;
		
		std::list<Path*> _allPaths;
		mutable std::list<Path*>::const_iterator _it;
		int _size;
		
		static PathBasedFlowMove *_flowMove;
		
		//std::list<FPType> prevFlows_;
		
		//void initialiseObject(PathCost *pathCost, StarNetwork *net, ShortestPath *shPath, FPType zeroFlow, FPType *linkFlows);
		
};

#endif
