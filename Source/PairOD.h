#ifndef _OD_PAIR_
#define _OD_PAIR_

#include "UsedTypes.h"

class PairOD {
	
	public:
	
	PairOD(int index, FPType demand); //int originIndex,
	~PairOD();
	
	void print();
	
	FPType getDemand() const;
	//int getID() const;
	int getIndex() const;
	int getODIndex() const;
	//int getOriginIndex() const;
	
	//void setIndex(int index);
	void setODIndex(int index);
	//void setOriginIndex(int index);
	
	private:
	
	//const int _destID; // actual id of the destination node 
	int _index;
	const FPType _demand; // demand corresponding to this O-D pair
	int _odIndex;
	//int _originIndex;
};

#endif
