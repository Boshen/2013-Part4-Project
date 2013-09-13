#ifndef _FWALGO_
#define _FWALGO_

#include "EqAlgo.h"
#include "LinkFlows.h"

/** This class implements Frank-Wolf algorithm.
 */
class FWAlgo : public EqAlgo{
	
	public:
	
		FWAlgo(LinkFlows *linkFlows, AddHook *component); //, StarNetwork *net);
		~FWAlgo();
	
		int execute();
		
	private:
		LinkFlows *_linkFlows;
		//StarNetwork *_net;
};

#endif
