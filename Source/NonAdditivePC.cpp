#include "NonAdditivePC.h"

// TODO: add pointer to indiff curve array
NonAdditivePC::NonAdditivePC(){

};

NonAdditivePC::~NonAdditivePC(){

};

FPType NonAdditivePC::calculate(Path *path) const{
	FPType time = 0.0;
	int toll = 0;
	for (StarLink* link = path->beginLink(); link != NULL; link = path->getNextLink()) {
		time += link->getTime();
		//toll += (link->getCost())->getToll(); //TODO
	}
	// TODO: think how to get indiff curve
	return time + toll;
};
