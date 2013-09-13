#ifndef _STAR_LINK_
#define _STAR_LINK_

#include "LinkFnc.h"

class StarLink {
	public:
		StarLink(int nodeFrom, int nodeTo, LinkFnc *fnc);
		~StarLink();
		
		int getNodeFrom() const;
		int getNodeTo() const;
		FPType getTime() const;
		LinkFnc* getLinkFnc() const;
		
		int getNodeFromIndex() const;
		int getNodeToIndex() const;
		
		void setNodeToIndex(int index);
		void setNodeFromIndex(int index);
		
		FPType getFlow() const;
		void setFlow(FPType flow);
		void setFlowToZero();
		void addFlow(FPType flow);
		
		int getIndex() const;
		void setIndex(int index);
		
		void updateTime();
		std::string toString() const;
		
		//FPType getDerivative() const;
		
	private:
		int _index;
		const int _nodeFrom;
		const int _nodeTo;
		int _nodeFromIndex;
		int _nodeToIndex;
		FPType _flow;
		FPType _time;
		LinkFnc *_fnc;
		//FPType _der;
};
#endif
