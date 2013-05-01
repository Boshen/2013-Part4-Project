#include "AdditivePC.h"

AdditivePC::AdditivePC(){

};

AdditivePC::~AdditivePC(){

};

FPType AdditivePC::calculate(Path *path) const{
	FPType cost = 0.0;
	for (StarLink* link = path->beginLink(); link != NULL; link = path->getNextLink()) {
		cost += link->getTime();
	}
	return cost;
};
