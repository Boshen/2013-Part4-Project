#include "RelGap.h"

#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <math.h>
#include <limits>

#include "Path.h"

RelGap::RelGap(FPType precision, StarNetwork *net, ODMatrix *mat, ShortestPath *shPath) : ConvMeasure(precision),
										_net(net), _mat(mat), _shPath(shPath) {

};

RelGap::~RelGap(){

};

FPType RelGap::getMinTravelTime(){
	FPType minTravelTime = 0.0;
	int destIndex = -1;
	FPType demand = 0.0;
	
	for (Origin *origin = _mat->beginOrigin(); origin != NULL; origin = _mat->getNextOrigin()){
		_shPath->calculate(origin->getIndex());
		//std::cout << "Origin = " << origin->getIndex() << " ";
		for (PairOD *dest = origin->beginDest(); dest != NULL; dest = origin->getNextDest()){
			destIndex = dest->getIndex();
			demand = dest->getDemand();
			minTravelTime += demand * _shPath->getCost(destIndex); 
			/*std::cout << "dest = " << destIndex << " minTravelTime = " << minTravelTime << " demand = " << demand << " shPath = " << _shPath->getCost(destIndex) << " ";
			StarLink *link = _shPath->getInComeLink(destIndex); //3 - destination node index
			int nextDest = link->getNodeFromIndex();
			Path path;
			while (link != NULL) {
				path.addLinkToPath(link);
				//std::cout << "current link index = " << link->getIndex() << " travel time = " << link->getTime() << std::endl;
				nextDest = link->getNodeFromIndex();
				link = _shPath->getInComeLink(nextDest);
			}
			path.print();*/
		}
	}
	//std::cout << std::endl;
	//std::cout << "minTravelTime = " << minTravelTime << std::endl;
	return minTravelTime;
};

FPType RelGap::getTotalTravelTime() {
	FPType totalTravelTime = 0.0;
	FPType totalFlow = 0.0;
	bool t = true;
	for (StarLink *link = _net->beginOnlyLink(); link != NULL; link = _net->getNextOnlyLink()) {
		totalTravelTime += link->getFlow() * link->getTime();
		if (totalTravelTime != totalTravelTime && t) {
			std::cout << "totalTravelTime = " << totalTravelTime << " flow = " << link->getFlow() << " time = " << link->getTime() << std::endl;
			t = false;
		}
		totalFlow += link->getFlow();
	}
	//std::cout << "totalTravelTime = " << totalTravelTime << std::endl;
	return totalTravelTime;
};

/** relative gap = 1 - sum_i (_demand[i] * _shPath[i]) / sum_a (_linkFlow[a] * _linkCost[a])
 */
bool RelGap::checkConvergence(FPType minTravelTime, FPType totalTravelTime) {
	//std::cout << "minTravelTime = " << minTravelTime << " totalTravelTime = " << totalTravelTime << std::endl;
	if (fabs(totalTravelTime) <= 1e-10) {
		setGap(std::numeric_limits<FPType>::max( ));
		return false;
	}
	FPType gap = 1.0 - minTravelTime /totalTravelTime;
	setGap(gap);
	//std::cout << "RGAP = " << gap << std::endl;
	return gap <= getPrecision();
};


bool RelGap::isConverged(){
	
	return checkConvergence(getMinTravelTime(), getTotalTravelTime());
};

bool RelGap::isConverged(FPType minTravelTime) {
	
	return checkConvergence(minTravelTime, getTotalTravelTime());
};

