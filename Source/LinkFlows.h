#ifndef _LINK_FLOWS_
#define _LINK_FLOWS_

#include "InitialiseSolution.h"
#include "LineSearch.h"
#include "ODMatrix.h"
#include "AONAssignment.h"
#include "Derivative.h"
#include "StepSize.h"
#include "DescDirection.h"
#include "ConvMeasure.h"
#include "LinkFncContainer.h"

class LinkFlows : public InitialiseSolution, public DescDirection {
	public:
		LinkFlows(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv);
		//LinkFlows(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv, FPType sparsityPrecision);
		virtual ~LinkFlows();
		
		virtual void initialise();
		void equilibrate();
		bool isConverged();
		FPType getGapValue() const;
		void updateLinkFlows();
		FPType getMinTravelTime() const;
		
		// for InitialiseSolution
	 	void initialiseItself(StarLink* link, PairOD *dest);
	 	
	 	// from DescDirection
	 	virtual FPType* getProjectedDirection();
		FPType getUpperBound();
		FPType* getLinkFlows();
		int getSize();
		int* getIndexes();
		
	protected:
		
		int _nbLinks;
		FPType *_linkFlows;
		FPType *_linkFlowsAux;
		
		
		FPType _stepPrev;
		FPType _stepPrevPrev;
		
		LinkFncContainer *_linkFncCont;
		AONAssignment *_aon;
		FPType _minTravelTime;
		
		virtual const FPType getDiraction(int index) const;
		virtual void calculateDirection();
		void calculateFWAux();
		
	private:
		ODMatrix *_mat;
		
		ConvMeasure *_conv;
		StarNetwork *_net;
		
		StepSize *_stepSize;
		
		int *_indexes;
		
		void initialiseObject(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv);
		
};

#endif
