#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "StarNetwork.h"
#include "Error.h"
#include "FileWriter.h"

StarNetwork::StarNetwork(int nbNodes, int nbLinks, std::string &netName) : _netName(netName), _nbNodes(nbNodes), _nbLinks(nbLinks),  _size(0), _sizeLinks(0), 
										_curNode(-1), _curLink(-1), _curOnlyLink(-1), _linkAdded(true) {
	_nodes = new StarNode*[nbNodes];
	_pointers = new int[nbNodes + 1];
	for (int i = 0; i < nbNodes; ++i) { 
		_nodes[i] = NULL;
		_pointers[i] = -1;
	}
	_pointers[nbNodes] = -1;
	
	_links = new StarLink*[nbLinks];
	for (int i = 0; i < nbLinks; ++i) {
		_links[i] = NULL;
	}
};

StarNetwork::~StarNetwork(){
	for (int i = 0; i < _size; ++i) delete _nodes[i];
	for (int i = 0; i < _nbLinks; ++i) delete _links[i];
	delete[] _nodes;
	delete[] _links;
	delete[] _pointers;
};

void StarNetwork::linkNodes(){
	assert(_size > 0);
	if (_pointers[_size - 1] == _sizeLinks) throw Error("Last added node does not have out-going links.");
	createIndexes();
	bool nodeToFound = false;
	for (StarLink *link = beginOnlyLink(); link != NULL; link = getNextOnlyLink())  {
		nodeToFound = false;
		for (StarNode *node = beginNode(); node != NULL; node = getNextNode()) {
			if (link->getNodeTo() == node->getID()){
				link->setNodeToIndex(node->getIndex());
				nodeToFound = true;
				break;
			}	
		}
		if (!nodeToFound){
			link->setNodeToIndex(getNodeIndex(link->getNodeTo()));
		}
	}
};
void StarNetwork::createIndexes(){
	std::tr1::unordered_map<int, int>::const_iterator got;
	int id = -1;
	int count = _size;
	for (StarLink *link = beginOnlyLink(); link != NULL; link = getNextOnlyLink()){
		id = link->getNodeTo(); // only nodeTo is considered because all nodes with out-going links were added during construction
		got = _idMap.find(id);
		if (got == _idMap.end()) {
			_idMap.insert(std::make_pair<int, int>(id, count));
			++count;
			assert(count <= _nbLinks);
		}
	}
};

void StarNetwork::addNode(StarNode *node){
	assert(_size < _nbNodes);
	if (!_linkAdded) throw Error("Two nodes were added in a row. Only nodes with out-going links can be added");
	node->setIndex(_size);
	_nodes[_size] = node;
	_idMap.insert(std::make_pair<int, int>(node->getID(), _size)); 
	_pointers[_size] = _sizeLinks;
	++_size;
	_pointers[_size] = _nbLinks;
	
	_linkAdded = false;
};

void StarNetwork::addLink(StarLink *link){
	assert(_sizeLinks < _nbLinks);
	_links[_sizeLinks] = link;
	link->setIndex(_sizeLinks);
	link->setNodeFromIndex(_size - 1);
	++_sizeLinks;
	_linkAdded = true;
};
		
std::string StarNetwork::getNetName(){
	return _netName;
};

int StarNetwork::getNbNodes(){
	return _nbNodes;
};

int StarNetwork::getNbLinks(){
	return _nbLinks;
};

StarNode* StarNetwork::beginNode(){
	_curNode = 0;
	_curLink = _pointers[_curNode];
	return _nodes[_curNode];
};

StarLink* StarNetwork::getLink(int linkIndex){
	assert((linkIndex >= 0) && (linkIndex < _nbLinks));
	return _links[linkIndex];
};

StarNode* StarNetwork::beginNode(int index){
	assert((index >= 0) && (index < _nbNodes));
	if (index >= _size) return NULL;
	_curNode = index; 
	_curLink = _pointers[_curNode];
	return _nodes[_curNode];
};

StarNode* StarNetwork::getNextNode(){
	++_curNode;
	if (_curNode == _size) {
		_curLink = -1;
		return NULL;
	}
	_curLink = _pointers[_curNode];
	return _nodes[_curNode];
};

StarLink* StarNetwork::beginLink(){
	return _links[_curLink];
};

StarLink* StarNetwork::getNextLink(){
	++_curLink;
	if (_curLink == _pointers[_curNode + 1]) {
		return NULL;
	}
	return _links[_curLink];	
};

StarLink* StarNetwork::beginOnlyLink(){
	_curOnlyLink = 0;
	return _links[_curOnlyLink];
};

StarLink* StarNetwork::getNextOnlyLink(){
	++_curOnlyLink;
	if (_curOnlyLink == _nbLinks) return NULL;
	return _links[_curOnlyLink];
};
		
void StarNetwork::print(){
	std::cout << "network name: " << getNetName() << " nbNodes = " << _nbNodes << " nbLinks = " << _nbLinks	 << std::endl;
	for (StarNode *node = beginNode(); node != NULL; node = getNextNode()){
	  std::cout << "Node ID = " << node->getID()  << " node index = " << node->getIndex() << std::endl;
		for (StarLink *link = beginLink(); link != NULL; link = getNextLink()) {
			
		  std::cout << " link " << link->getIndex() << "  (" << link->getNodeFromIndex() << ", " << link->getNodeToIndex() << ") cost-> (" << link->getTime() << ") flow = " << link->getFlow() << std::endl;
			//if (link->getFlow() > 0.0) std::cout <<  link->getIndex() << " " << link->getNodeFrom() << " " << link->getNodeTo() << " (" << link->getNodeFromIndex()  << ", " << link->getNodeToIndex() << ") " << " " << link->getFlow() << " " << link->getTime() << std::endl;
			//" (" << link->getNodeFromIndex()  << ", " << link->getNodeToIndex() << ") "
		}
	}//*/
	
	/*std::cout << "***************** only links" << std::endl;
	for (StarLink *link = beginOnlyLink(); link != NULL; link = getNextOnlyLink()) {
			if (link->getNodeFrom() == 5055 || link->getNodeFrom() == 5056) {
				std::cout << "**************** link->getNodeFrom() = " << link->getNodeFrom() << " " << link->getNodeTo() << std::endl;
				link->getLinkFnc()->print();
				}
	}*/
};

int StarNetwork::getNodeIndex(int id){
	std::tr1::unordered_map<int, int>::const_iterator got = _idMap.find(id);
	if (got == _idMap.end()) {
		std::stringstream str;
		str << "Cannot find id = " << id;
		throw Error(str.str());//return -1;
	}
	return got->second;
};

void StarNetwork::printToFile(const std::string &fileName){
	
	FileWriter fw(fileName);
	std::string line;
	std::ostringstream strs;
					
	for (StarLink *link = beginOnlyLink(); link != NULL; link = getNextOnlyLink()) {
		//fprintf (pFile, "%u %u %21.15e %21.15e \n", link->getNodeFrom(), link->getNodeTo(), link->getFlow(), link->getTime());
		strs.str("");
		strs << link->getNodeFromIndex() << " " << link->getNodeToIndex() << " " <<  std::setprecision(16) << link->getFlow() << " " << link->getTime() << "\n";
		line = strs.str();
		fw.writeLine(line);
	}	
	
};

bool StarNetwork::assignLinkFlow(int nodeFrom, int nodeTo, FPType flow){
	for (StarLink *link = beginOnlyLink(); link != NULL; link = getNextOnlyLink()) {
		if ((link->getNodeFrom() == nodeFrom) && (link->getNodeTo() == nodeTo)){
			link->setFlow(flow);
			return true;
		}
	}
	return false;
};

void StarNetwork::loadFromFile(const std::string& fileName){
	std::ifstream myfile(fileName.c_str());
	int nodeFrom = -1;
	int nodeTo = 1;
	FPType flow = 0.0;
	FPType tmp = 0.0;
	if (myfile.is_open()) {
		while ( myfile.good() ){
	      		myfile >> nodeFrom >> nodeTo >> flow >> tmp;
	      		std::cout << nodeFrom << " " << nodeTo << " " << flow << std::endl;
	      		if (!assignLinkFlow(nodeFrom, nodeTo, flow)) throw Error("This link does not exist in the network");
	    	}
		myfile.close();
	} else {
		throw Error("Unable to open file: " + fileName); 
	}
};

void StarNetwork::calculateLinkCosts(){
	for (StarLink *link = beginOnlyLink(); link != NULL; link = getNextOnlyLink()) {
		link->updateTime();
	}
};

StarNode* StarNetwork::getNodeWithLinks(int index){
	assert(index >= 0);
	if (index >= _size) return NULL; // it means that this node does not have out-going links
	return _nodes[index];
};
