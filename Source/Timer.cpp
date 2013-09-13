#include "Timer.h"

Timer::Timer() : stopCalled_(false) {

}; 

Timer::~Timer() {

}; 

void Timer::stopAnyway(){
	end_ = clock();
	stopCalled_ = true;
};


void Timer::start() {
	start_ = clock();
	stopCalled_ = false;
}; 

// TODO: if stop is called without start - not gona work
void Timer::stop() {
	
	// time is stoped once
	if (stopCalled_ == false) {
		end_ = clock();
		stopCalled_ = true;
	}
}; 

double Timer::getTimePassed() const {
	if (stopCalled_ == false) return 0.0;	
	return ((double)(end_ - start_))/ (CLOCKS_PER_SEC);
}; 

