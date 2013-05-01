#ifndef _DECOR_EQ_ALGO_
#define _DECOR_EQ_ALGO_

class DecoratedEqAlgo {
	public:
		virtual ~DecoratedEqAlgo() {};
		virtual int execute() = 0;
		
	protected:
		DecoratedEqAlgo(){};
};

#endif
