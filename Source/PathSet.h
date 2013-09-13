#ifndef _PATH_SET_
#define _PATH_SET_

#include "InitialiseSolution.h"
#include "ODSet.h"
#include "ODMatrix.h"
#include "PathCost.h"
#include "PathBasedFlowMoveWithStep.h"
#include "PathBasedFlowMoveGP.h"

class PathSet : public InitialiseSolution {
	public:
		
		PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, PathBasedFlowMove* flowMove);
		PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, PathBasedFlowMoveWithStep* flowMove);
		PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, PathBasedFlowMoveGP* flowMove);
		//PathSet(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost, FPType zeroFlow, FPType alpha, DescDirectionPath* descDirPath);
		
		virtual ~PathSet();
		
		virtual void initialise();
		
		void initialiseItself(StarLink* link, PairOD *dest, int originIndex);
		
		// iterate through path set
		ODSet* beginSet();
		ODSet* getNextSet();
		
		//bool isConverged() const;
		//FPType getGap() const;
		long int getNbPath();
		
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
		//ConvMeasure *_conv;
		int _size;
		Path *_currPath;
		PathCost *_pathCost;
		
		FPType *_linkFlows;
		FPType *_linkFlowsAux;
		int _nbLinks;
		
		int _currSetIndex;
		
		//LinkFncContainer *_linkFncCont;
		
		void initialiseObject(StarNetwork *net, ODMatrix *mat, ShortestPath *shPath, PathCost *pathCost);
};

#endif
