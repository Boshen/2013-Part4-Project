#include "OnePathDerivative.h"

OnePathDerivative::OnePathDerivative(FPType slope) : _slope(slope) {

};

OnePathDerivative::~OnePathDerivative(){

};
		
FPType OnePathDerivative::calculate(Path *path){
	FPType der = 0.0;
	FPType flow = 0.0;
	for (StarLink* link = path->beginLink(); link != NULL; link = path->getNextLink()) {
		flow = link->getFlow();
		if (flow < _slope) {
			flow = _slope;
		} 
		der +=  (link->getLinkFnc())->evaluateDerivative(flow);
	}
	return der;
};
