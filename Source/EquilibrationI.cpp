#include "EquilibrationI.h"

EquilibrationI::EquilibrationI(PathBasedAlgo *algo) : _algo(algo) {

};

EquilibrationI::~EquilibrationI(){

};

void EquilibrationI::executeMainLoop(ODSet *odSet){
	_algo->mainLoop(odSet);
};
