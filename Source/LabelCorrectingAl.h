#ifndef LABEL_CORR_AL
#define LABEL_CORR_AL

#include "StarNetwork.h"
#include "ShortestPath.h"
#include "NodeInfo.h"
#include "OperationCounter.h"

/** This class implements the label correcting algorithm able to find the shortest paths from 
 *  a given origin node to all other nodes of the network. For description of the methods
 *  see source file LabelCarrectingAl.cpp
 */
class LabelCorrectingAl : public ShortestPath, public OperationCounter {
	
	public:
		LabelCorrectingAl(StarNetwork *netPointer, CounterContainer &container);
		~LabelCorrectingAl();
		
		void calculate(int originIndex);
		
		FPType getCost(int destIndex) const;
		StarLink* getInComeLink(int destIndex) const;
		
		int getCurrentOrigin() const;
		
		virtual std::string getCounterValue();
	
	private:
		StarNetwork *_netPointer;
		nodeInfo *_nodeList;
		const int _nbNodes;
		int _originIndex;
		int nbCalls_;	
};

#endif
