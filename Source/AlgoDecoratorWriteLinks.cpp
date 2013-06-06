#include "AlgoDecoratorWriteLinks.h"

AlgoDecoratorWriteLinks::AlgoDecoratorWriteLinks(DecoratedEqAlgo *algo, StarNetwork *net, const std::string &fileName, Timer &timer) : 
				component_(algo), net_(net), fileName_(fileName), timer_(timer) {

}; 

AlgoDecoratorWriteLinks::~AlgoDecoratorWriteLinks() {
	delete component_;
}; 

int AlgoDecoratorWriteLinks::execute(){
	int nbIter = component_->execute();
	timer_.stop();
	net_->printToFile(fileName_);
	return nbIter;
};

