#ifndef ADD_HOOK_SCREEN_OUT
#define ADD_HOOK_SCREEN_OUT

#include "AddHook.h"

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cassert>

class AddHookScreenOut : public AddHook {
	public:
		
		AddHookScreenOut(int precision = 10) : precision_(precision) {assert(precision >= 1 && precision < 17);}; 
		virtual ~AddHookScreenOut() {};
		
		virtual void produceOut(double timePassed, FPType gap){
			std::cout << std::setprecision(precision_) << timePassed << " " << gap << std::endl;
		};
		
	private:
		int precision_;

};

#endif
