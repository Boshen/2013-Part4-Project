#ifndef _STAR_NETWORK_
#define _STAR_NETWORK_

#include "StarNode.h"
#include "StarLink.h"

#include <string>
#include <tr1/unordered_map>

class StarNetwork {
	public:
		StarNetwork(int nbNodes, int nbLinks, std::string &netName);
		~StarNetwork();
		
		//setters to fill info
		void addNode(StarNode *node);
		void addLink(StarLink *link);
		
		// fills indexes in links
		void linkNodes();
		
		// getters provide interface for shortest path algorithm
		std::string getNetName();
		int getNbNodes();
		int getNbLinks();
		
		// to iterate through network
		StarNode* beginNode();
		StarNode* beginNode(int index); // index is a number from 0 to nbNodes-1
		StarNode* getNextNode();
		StarLink* beginLink();
		StarLink* getNextLink();
		
		// to iterate only links
		StarLink* beginOnlyLink();
		StarLink* getNextOnlyLink();
		
		// to get link by index
		StarLink* getLink(int linkIndex);
		StarNode* getNodeWithLinks(int index);
		
		// to get mapped index
		// AVOID calling this function as much as possible. It has log(n) complexity.
		int getNodeIndex(int id); // returns a number from 0 to nbNodes-1
		
		void print();
		void printToFile(const std::string& fileName);
		void loadFromFile(const std::string& fileName);
		void calculateLinkCosts();
		
	private:
		std::string _netName;
		int _nbNodes;
		int _nbLinks;
		StarNode **_nodes;
		StarLink **_links;
		int *_pointers;
		int _size;
		int _sizeLinks;
		int _curNode;
		int _curLink;
		int _curOnlyLink;
		std::tr1::unordered_map<int, int> _idMap;
		bool _linkAdded;
		
		// creates table of mapping between node ID and node indexes
		void createIndexes();
		bool assignLinkFlow(int nodeFrom, int nodeTo, FPType flow);
};

#endif
