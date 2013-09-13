#include "CounterContainer.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>

#include "OperationCounter.h"

CounterContainer::CounterContainer() : container_() {

}; 

CounterContainer::~CounterContainer() {

}; 

void CounterContainer::addCounter(OperationCounter *counter) {
	assert(counter != NULL);
	container_.push_back(counter);
}; 

void CounterContainer::printCounters() const {
	for (std::list<OperationCounter*>::const_iterator it = container_.begin(); it != container_.end(); ++it) {
		std::cout << (*it)->getCounterValue() << " ";
	}
	std::cout << std::endl;
}; 

