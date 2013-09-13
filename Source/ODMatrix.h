#ifndef _OD_MATRIX_
#define _OD_MATRIX_

#include "Origin.h"
#include "StarNetwork.h"

#include <string>
#include <tr1/unordered_map>


class ODMatrix {
	public:
		ODMatrix(int nbNodes);
		~ODMatrix();
		
		//for creation
		void addOrigin(Origin *origin);
		
		//getters
		Origin* beginOrigin();
		Origin* getNextOrigin();
		
		void setIndexes(StarNetwork *net);
		
		void print();
		
		int getNbODPairs() const;
		int getNbOrigins() const;
		
		FPType getDemandByIndex(int originIndex, int destIndex) const;
		
	private:
	
		const int _nbNodes; // number of nodes in the network	
		int _nbODPairs;
		std::list<Origin*> _odMatrix; // internal representation of O-D matrix	
		//int _curOrigin;
		std::list<Origin*>::iterator _curOrigin;
		//int _size;
		std::tr1::unordered_map<std::string, FPType> _demandByIndex;
};

#endif
