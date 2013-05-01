#include "LinkFncContainer.h"

#include <cassert>
#include <stdlib.h>
#include <iostream>

LinkFncContainer::LinkFncContainer(StarNetwork *net) : _count(0), _curFnc(0){
	_nbLinks = net->getNbLinks();
	_links = new LinkFnc*[_nbLinks];
	for (int i = 0; i < _nbLinks; i++) {
		_links[i] = NULL;
	}
	for (StarLink *link = net->beginOnlyLink(); link != NULL; link = net->getNextOnlyLink()){
		_links[link->getIndex()] = link->getLinkFnc();
	}
};

LinkFncContainer::~LinkFncContainer(){
	delete[] _links;
};

void LinkFncContainer::addLinkFnc(LinkFnc *fnc){
	assert(_count < _nbLinks);
	_links[_count] = fnc;
	_count++;
};

LinkFnc* LinkFncContainer::begin(){
	_curFnc = 0;
	return _links[0];
};

LinkFnc* LinkFncContainer::next(){
	_curFnc++;
	if (_curFnc == _nbLinks) return NULL;
	return _links[_curFnc];
};

LinkFnc* LinkFncContainer::getLinkFnc(int index){
	assert((index >= 0) && (index < _nbLinks));
	return _links[index];
};
