#ifndef TIMER_
#define TIMER_

#include <ctime>

class Timer {
	public:
		Timer();
		~Timer();
		
		void start();
		void stop();
		void stopAnyway();
		
		double getTimePassed() const;
		
	private:
		clock_t start_;
		clock_t end_;
		bool stopCalled_;
		
};

#endif
