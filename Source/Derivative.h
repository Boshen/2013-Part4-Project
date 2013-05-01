#ifndef _DERIVATIVE_
#define _DERIVATIVE_

#include "LinkFncContainer.h"
#include "UsedTypes.h"

class Derivative {
	public:
		Derivative(FPType zeroFlow, LinkFncContainer *fnc);
		~Derivative();
		
		FPType calculate(FPType alpha);
		
		void setDataPointers(int size, FPType *x, FPType *y, int *indexes);
		FPType getZeroFlow() const;
		
		// getters for quad.app
		int getSize() const;
		FPType getX(int index) const;
		FPType getY(int index) const;
		LinkFnc* getLinkFnc(int index) const;
		
	private:
		int _size;
		FPType *_x;
		FPType *_y;
		int *_indexes;
		FPType _zeroFlow;
		
		LinkFncContainer *_fnc;
};

#endif
