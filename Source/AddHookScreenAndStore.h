#ifndef ADD_HOOK_SCREEN_AND_STORE
#define ADD_HOOK_SCREEN_AND_STORE

#include "AddHookStoreOut.h"

class AddHookScreenAndStore : public AddHookStoreOut {
	public:
		AddHookScreenAndStore(){};
		~AddHookScreenAndStore(){};
		
		void produceOut(double timePassed, FPType gap) {
			AddHookScreenOut::produceOut(timePassed, gap);
			AddHookStoreOut::produceOut(timePassed, gap);
		};
};

#endif
