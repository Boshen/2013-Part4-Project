#ifndef _DAGRAPH_NODE_
#define _DAGRAPH_NODE_

#include "StarLink.h"

#include <list>

class DAGraphNode {
	public:
		
		DAGraphNode(int index, FPType demand);
		~DAGraphNode();
		
		int getIndex() const;
		int getPre() const;
		int getPost() const;
		FPType getMinDist() const;
		FPType getMaxDist() const;
		FPType getDemand() const;
		
		void setPre(int pre);
		void setPost(int post);
		void setMinDist(FPType minDist);
		void setMaxDist(FPType maxDist);
		void setMinLink(StarLink* link);
		void setMaxLink(StarLink* link);
		
		StarLink* getMinLink() const;
		StarLink* getMaxLink() const;
		
		// are public to make the access easier
		std::list<StarLink*> incomeLinks;
		std::list<StarLink*> outLinks;
		
	private:
		StarLink* minLink_;
		StarLink* maxLink_;
		FPType demand_;
		int nodeIndex_;
		int pre_;
		int post_;
		FPType minDist_;
		FPType maxDist_;
};

#endif
