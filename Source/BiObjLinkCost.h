#ifndef _BI_OBJ_LINK_COST_
#define _BI_OBJ_LINK_COST_

#include "LinkCost.h"	

class BiObjLinkCost : public LinkCost {
	public:
		BiObjLinkCost() : toll_(0) {};
		~BiObjLinkCost(){};
		
		void setToll(int toll){
			toll_ = toll;
		};
		
		int getToll(){
			return toll_;
		};
		
	private:
		int toll_;
};

#endif
