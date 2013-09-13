#ifndef ADD_HOOK_SCREEN_AND_STORE
#define ADD_HOOK_SCREEN_AND_STORE

#include "AddHookStoreOut.h"
#include "AddHookScreenOut.h"

class AddHookScreenAndStore : public AddHookStoreOut, public AddHookScreenOut {
	public:
		AddHookScreenAndStore(){};
		~AddHookScreenAndStore(){};
		
		virtual void produceOut(double timePassed, FPType gap) {
			AddHookScreenOut::produceOut(timePassed, gap);
			AddHookStoreOut::produceOut(timePassed, gap);
		};
};

#endif
