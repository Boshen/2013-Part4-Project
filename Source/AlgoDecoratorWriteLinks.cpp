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
	std::cout << "Writing link flows to file: " << fileName_ << std::endl;
	net_->printToFile(fileName_); //"Results/Test2/LinkFlows/" + 
	return nbIter;
};

