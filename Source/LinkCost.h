#ifndef _LINK_COST_
#define _LINK_COST_

class LinkCost {
	public:
		
		virtual ~LinkCost(){};
		
		void setTime(FPType time){
			_time = time;
		};
		
		FPType getTime() const{
			return _time;
		};
		
		// for bi-objective toll
		virtual int getToll() const{
			return 0;
		};
		
		virtual void setToll(int toll) {};
		
	protected:
		LinkCost() : _time(0.0){};
		
		FPType _time;
};

#endif
