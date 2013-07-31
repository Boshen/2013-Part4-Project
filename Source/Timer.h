#ifndef TIMER_
#define TIMER_

#include <ctime>
//#include <sys/time.h>

class Timer {
	public:
		Timer();
		~Timer();
		
		void start();
		void stop();
		
		double getTimePassed() const;
		
	private:
		clock_t start_;
		clock_t end_;
        //timeval start_;
        //timeval end_;
		bool stopCalled_;
		
};

#endif
