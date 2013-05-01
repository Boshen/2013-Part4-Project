#include "EquilibrationII.h"

EquilibrationII::EquilibrationII(PathBasedAlgo *algo) : _algo(algo) {

}; 

EquilibrationII::~EquilibrationII(){

};

void EquilibrationII::executeMainLoop(ODSet *odSet){
	bool isEquilibrated = false;
	while (!isEquilibrated) {
		isEquilibrated = _algo->mainLoop(odSet);
	}
};

