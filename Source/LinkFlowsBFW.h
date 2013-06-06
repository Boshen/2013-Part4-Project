#ifndef _LINK_FLOWS_BFW_
#define _LINK_FLOWS_BFW_

#include "LinkFlowsCFW.h"

class LinkFlowsBFW : public LinkFlowsCFW {

	public:
		LinkFlowsBFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv);
		//LinkFlowsBFW(StarNetwork *net, ODMatrix *mat, LinkFncContainer *linkFncCont, ShortestPath *shPath, Derivative *der, LineSearch *lineSearch, ConvMeasure *conv, FPType sparsityPrecision);
		virtual ~LinkFlowsBFW();
		
		void initialise();
		
	protected:
		void calculateDirection();
		
	private:
		int _tmp;
		FPType *_linkFlowsBFW;
		
		//void allocateMemory();
		
		void calcCoeff(FPType &beta0, FPType &beta1, FPType &beta2);
		FPType changeCoeff(FPType beta);

};

#endif
