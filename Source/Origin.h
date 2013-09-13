#ifndef ORIGIN_H
#define ORIGIN_H

#include "PairOD.h"

#include <list>

/** This class is used to represent the container of destination nodes corresponding
 *  for one origin.
 */
class Origin {
	
	public:
	
		explicit Origin(int index);
		~Origin();
	
		void addDestination(PairOD *dest);
	
		PairOD* beginDest();
		PairOD* getNextDest();
	
		//int getID() const;
		int getIndex() const;
		bool isEmpty() const;
		int getNbDest() const;
	
		//void setIndex(int index);
	
	private:
	
		//const int _id;
		int _index;
		//bool _isEmpty;
		//int _nbDest;
		std::list<PairOD*>::iterator _it;
		std::list<PairOD*> _destList;	
};

#endif
