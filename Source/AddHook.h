#ifndef ADD_HOOK_
#define ADD_HOOK_

#include "UsedTypes.h"

class AddHook {
	public:
		
		AddHook(){};
		virtual ~AddHook(){};
		
		virtual void produceOut(double timePassed, FPType gap) {};
		
};

#endif
