#ifndef OPERATION_COUNTER
#define OPERATION_COUNTER

#include <string>
#include <list>

#include "CounterContainer.h"

class OperationCounter {
	public:
		virtual ~OperationCounter() {};
		virtual std::string getCounterValue() = 0; // string format <Counter name>: {Counter value};
		
	protected:
		OperationCounter(CounterContainer &container) {container.addCounter(this);}; // every class that implements OperationCounter will be attached to a list that will be used after to write all counters to the file
	
};

#endif
