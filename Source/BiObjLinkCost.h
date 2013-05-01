#ifndef _BI_OBJ_LINK_COST_
#define _BI_OBJ_LINK_COST_

#include "LinkCost.h"	

class BiObjLinkCost : public LinkCost {
	public:
		BiObjLinkCost(){};
		~BiObjLinkCost(){};
		
		void setToll(int toll){
			_toll = toll;
		};
		
		int getToll(){
			return _toll;
		};
		
	private:
		int _toll;
};

#endif
