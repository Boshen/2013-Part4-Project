#ifndef _STAR_NODE_
#define _STAR_NODE_

class StarNode {
	public:
		StarNode(int id, bool isZone);
		~StarNode();
		
		//getters
		int getID();
		bool getIsZone();
		int getIndex();
		
		//setters
		void setIndex(int index);
		
	private:
		int _id;
		int _index;
		bool _isZone;

};

#endif
