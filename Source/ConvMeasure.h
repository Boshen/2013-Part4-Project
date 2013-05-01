#ifndef _CONV_MEASURE_
#define _CONV_MEASURE_

#include "UsedTypes.h"

class ConvMeasure {
	public:
		
		virtual ~ConvMeasure() {};
		
		virtual bool isConverged() = 0;
		virtual bool isConverged(FPType minTravelTime) {return isConverged();};
		
		FPType getPrecision() const {return _precision;};
		FPType getGap() const {return _gap;};
	
	protected:
	
		ConvMeasure(FPType precision) : _precision(precision), _gap(0.0) {};
		
		void setGap(FPType gap) {_gap = gap;};
		
	private:
		
		FPType _precision;
		FPType _gap;
};

#endif
