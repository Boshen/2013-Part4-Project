#ifndef _EQ_TYPE_
#define _EQ_TYPE_

#include "ODSet.h"

#include <stdlib.h>
#include <iostream>

class EquilibrationType {
	public:
		virtual ~EquilibrationType(){};
		virtual void executeMainLoop(ODSet *odSet) = 0; 
		
	protected:
		EquilibrationType() {}; 
};
#endif
