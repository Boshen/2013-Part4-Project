#ifndef _LINK_FNC_CONTAINER_
#define _LINK_FNC_CONTAINER_

#include "LinkFnc.h"
#include "StarNetwork.h"

class LinkFncContainer {
	public:
		LinkFncContainer(StarNetwork *net);
		~LinkFncContainer();
		
		//to iterate link functions
		LinkFnc* begin();
		LinkFnc* next();
		
		//get link fnc by index
		LinkFnc* getLinkFnc(int index);
		
	private:
		int _nbLinks;
		int _count;
		LinkFnc **_links;
		int _curFnc;
		
		void addLinkFnc(LinkFnc *fnc);
};

#endif
