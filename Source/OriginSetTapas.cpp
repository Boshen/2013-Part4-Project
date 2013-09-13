#include "OriginSetTapas.h"

OriginSetTapas::OriginSetTapas(ODMatrix *mat, StarNetwork *net, ShortestPath *shPath, ConvMeasure *conv, FPType zeroFlow, FPType dirTol, PASManager *pasManager) : OriginSet(mat, net, shPath, conv, zeroFlow, dirTol, pasManager), pasManager_(pasManager) {

}; 

OriginSetTapas::~OriginSetTapas() {

}; 

bool OriginSetTapas::isConverged() {
	bool val = OriginSet::isConverged();
	pasManager_->setRGAP0(conv_->getGap());
	return val;
}; 

