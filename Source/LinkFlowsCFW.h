#ifndef _LINK_FLOWS_CFW_
#define _LINK_FLOWS_CFW_

#include "LinkFlows.h"

class LinkFlowsCFW : public LinkFlows {
	
	public:
		LinkFlowsCFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, StepSize* stepSize, ConvMeasure *conv);
		//LinkFlowsCFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv, FPType sparsityPrecision);
		virtual ~LinkFlowsCFW();
		
		virtual void initialise();
		FPType* getProjectedDirection();
		
	protected:
		
		static const FPType _delta = 1e-10;
		static const FPType _zeroTol = 1e-16;
		FPType *_linkFlowsCFW;
		FPType *_direction;
		
		const FPType getDiraction(int index) const;
		virtual void calculateDirection();
		FPType calculateAlpha();
		
	private:
	
		int _nbCalls;
		//void allocateMemory();
};

#endif
