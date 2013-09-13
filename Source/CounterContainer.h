#ifndef COUNTER_CONTAINER
#define COUNTER_CONTAINER

#include <list>

class OperationCounter;

class CounterContainer {
	public:
		CounterContainer();
		~CounterContainer();
		
		void addCounter(OperationCounter *counter);
		
		void printCounters() const;
		
	private:
		std::list<OperationCounter*> container_;
};

#endif
