#include "Timer.h"

Timer::Timer() : stopCalled_(false) {

}; 

Timer::~Timer() {

}; 

void Timer::start() {
	start_ = clock();
    //gettimeofday(&start_, NULL);
	stopCalled_ = false;
}; 

void Timer::stop() {
	
	// time is stoped once
	if (stopCalled_ == false) {
		end_ = clock();
        //gettimeofday(&end_, NULL);
		stopCalled_ = true;
	}
}; 

double Timer::getTimePassed() const {
	if (stopCalled_ == false) return 0.0;	
	return ((double)(end_ - start_))/ (CLOCKS_PER_SEC);
	//return (double)(end_ - start_);
   // return (end_.tv_sec-start_.tv_sec)*1000+(end_.tv_usec-start_.tv_usec)/1000.0;
}; 

