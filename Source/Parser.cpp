#include "Parser.h"
#include "UtilsString.h"
#include "Utils.h"
#include "BiObjLinkCost.h"
#include "Error.h"
#include "BprFnc.h"
#include "FileReader.h"

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
#include <tr1/unordered_map>

/** Internal utility structure.
*/ 
struct ParamsLine{
	int origin;
	int dest;
	FPType capacity;
	FPType length;
	FPType freeFlowTime;
	FPType b;
	FPType power;
	FPType speed;
	FPType toll;
	int type;
};

Parser::Parser(){

};

Parser::~Parser(){

};

/** It is assumed that all links are SORTED according to acsending order of head nodes
 **/
StarNetwork* Parser::parseNetwork(const std::string &fileName, bool isAdditive){
	
	// open file
	std::ifstream netFile(fileName.c_str());
	if (netFile.is_open()) {
		
		std::string netName = "";
		Utils::extractName(fileName.c_str(), netName);
		
		// read attributes
		std::string line = "";
		std::string field = "";
		std::string value = "";
		int nbNodes = 0;
		int nbLinks = 0;
		int firstNode = 0;
		while (line.find("<END OF METADATA>") == std::string::npos) {
			getline(netFile, line);
			line = Utils::skipOneLineComment("~", line);
			
			std::string newLine = line;
			// remove all white spaces
			Utils::removeWhiteSpaces(newLine);
			if (!newLine.empty()){
				field = Utils::getSubString("<", ">", line);
				value = line.substr(line.find(">") + 1);
				if (field == "NUMBER OF NODES"){
					nbNodes = atoi(value.c_str());
				} else if (field == "NUMBER OF LINKS") { 
					nbLinks = atoi(value.c_str());
				} else if (field == "FIRST THRU NODE") {
					firstNode = atoi(value.c_str());
				}
			}
			if (netFile.eof()) {
				std::string message = "<END OF METADATA> is missing in file: ";
				message.append(fileName);
				Error er(message);
				throw er;
			}
		}
		checkEmptyValue(nbNodes);
		checkEmptyValue(nbLinks);
		checkEmptyValue(firstNode); 
		
		// read network
		StarNetwork* net = new StarNetwork(nbNodes, nbLinks, netName);
		char semic;
		std::stringstream strLine;
		ParamsLine params;
		int originPrev = -1;
		StarNode *node = NULL;
		StarLink *link = NULL;
		LinkFnc *fnc = NULL;
		bool isZone = false;
		while ( netFile.good() ) {
			getline(netFile, line);
			line = Utils::skipOneLineComment("~", line);
			std::string newLine = line;
			// remove all white spaces
			//newLine.erase(std::remove_if(newLine.begin(), newLine.end(), isspace), newLine.end());
			Utils::removeWhiteSpaces(newLine);
			if (!newLine.empty()){
				strLine.clear();
	    			strLine.str(line);
	    			//std::cout << "Parsing line: " << line << std::endl;
				strLine >> params.origin >> params.dest >> params.capacity >> params.length >> params.freeFlowTime >> params.b >> params.power >> params.speed >> params.toll >> params.type >> semic;
				
				if (originPrev != params.origin) {
					
					if (params.origin < firstNode) {
						isZone = true;
					} else {
						isZone = false;
					}
					node = new StarNode(params.origin, isZone);
					net->addNode(node);
					//std::cout << "Node " << params.origin << " is added" << std::endl;
					
					originPrev = params.origin;
				}
				
				// creating link cost functions
				fnc = new BprFnc(params.freeFlowTime, params.b, params.capacity, params.power);
				
				link = new StarLink(params.origin, params.dest, fnc);
				net->addLink(link);
				
				// IMPORTANT: links and link cost functions must be added in the same order 
				//		to ensure that they correspond to each other!!!!
				
			}
		}
		
		// close file
		netFile.close();
		return net;
	} else {
		std::string message = "Unable to open a file: ";
		message.append(fileName);
		Error er(message);
		throw er;
	}	
};

void Parser::checkEmptyValue(int value){
	if (value == 0) {
		std::string message = "Some values of attributes are missing";
		Error er(message);
		throw er;
	}
};

ODMatrix* Parser::parseODMatrix(const std::string& fileName, int nbNodes){
	// open file
	std::ifstream matFile(fileName.c_str());
	if (matFile.is_open()) {
		// skip metadata
		std::string line = "";
		while (line.find("<END OF METADATA>") == std::string::npos) {
			getline(matFile, line);
			
			if (matFile.eof()) {
				std::string message = "<END OF METADATA> is missing in file: ";
				message.append(fileName);
				Error er(message);
				throw er;
			}
		}
		// read O-D matrix
		size_t found;
		int originID = -1;
		int destID = -1;
		FPType demand = 0.0;
		Origin *origin = NULL;
		PairOD *dest = NULL;
		ODMatrix *mat = new ODMatrix(nbNodes);
		std::string newLine = "";
		//int prevNbPairs = 0;
		//int odIndex = -1;
		while ( matFile.good() ) {
			getline(matFile, line);
			line = Utils::skipOneLineComment("~", line);
			std::string newLine = line;
			// remove all white spaces
			Utils::removeWhiteSpaces(newLine);
			if (!newLine.empty()){
				// check if it is a new origin
				found = line.find("Origin");
				if (found != std::string::npos) {
					//if (origin != NULL) prevNbPairs = origin->getNbDest();
					originID = atoi((line.substr(found + 7)).c_str());
					origin = new Origin(originID);
					mat->addOrigin(origin);	
				}
				assert(origin != NULL);
				// get all destinations from current line
				size_t pos = extractDestination(0, line, destID, demand);
				
				while (pos != std::string::npos){
					if ((destID != originID) && (demand != 0.0)) {
						//odIndex = origin->getIndex() * prevNbPairs + origin->getNbDest();
						//std::cout << "odIndex = " << odIndex << " origin->getIndex()  = " << origin->getIndex()  << " prevNbPairs  = " << prevNbPairs <<  " origin->getNbDest() = " << origin->getNbDest() << std::endl; 
						dest = new PairOD(destID, demand);
						origin->addDestination(dest);
					}
					pos = extractDestination(pos, line, destID, demand);
				}
				
			}
			
		}
		
		// close file
		matFile.close();
		return mat;
	} else {
		std::string message = "Unable to open a file: ";
		message.append(fileName);
		Error er(message);
		throw er;
	}
};

size_t Parser::extractDestination(size_t posFrom, const std::string& line, int &destID, FPType &demand) const{
	size_t pos1 = line.find(":", posFrom);
	if (pos1 != std::string::npos) {
		size_t pos2 = line.find(";", pos1);
		if (pos2 != std::string::npos) {
			destID = atoi((line.substr(posFrom, pos1 - posFrom - 1)).c_str());
			demand = atof((line.substr(pos1+1, pos2 - pos1 - 1)).c_str());
			return pos2 + 1;
		}
		return std::string::npos;
	}
	return std::string::npos;
};

size_t Parser::extractARTDestination(size_t posFrom, const std::string &line, int &destID, FPType &demand) const{
	std::cout << "Parsing line: " << line << " ------- from position = " << posFrom << std::endl;
	size_t pos1 = line.find(":", posFrom);
	size_t len = line.length();
	if (pos1 + 1 == len) throw Error("Demand value must be specified after : .");
	if (pos1 - 1 < 0) throw Error("Destination id must be specified before : .");
	if (pos1 != std::string::npos) {
		size_t returnPos;
		demand = extractNumber(line, pos1 + 1, returnPos);
		
		char ch;
		std::string num("");
		for (int i = pos1 - 1; i != 0; --i) {
			ch = line.at(i);
			if (!isdigit(ch)) break;
			num.insert(0, 1, ch);
		}
		destID = atoi(num.c_str());
		std::cout << "demand = " << demand << " destID = " << destID << std::endl;
		return returnPos;
	}
	return std::string::npos;
};

FPType Parser::extractNumber(const std::string& line, size_t pos, size_t &nextPos) const{
	int len = line.length();
	int i = pos;
	char ch;
	bool dotAdded = false;
	for (; i < len; ++i) {
		ch = line.at(i);
		if (isdigit(ch) || (ch == '.')) {
			if (ch == '.') dotAdded = true;
			break;
		}
	}
	if (i == len) throw Error("Current line does not contain number.");
	std::string num(1, line.at(i));
	
	int j = i + 1;
	for (; j < len; ++j) {
		ch = line.at(j);
		if (ch == '.') {
			if (dotAdded) {
				break;
			} else {
				dotAdded = true;
			}
		} else if (!isdigit(ch)) {
			break;
		}
		num.push_back(ch);
	}
	nextPos = j;
	return atof(num.c_str());
};

int Parser::extractInt(const std::string& line, size_t pos) const{
	int len = line.length();
	int i = pos;
	for (; i < len; ++i) {
		if (isdigit(line.at(i))) break;
	}
	if (i == len) throw Error("Current line does not contain integers.");
	std::string num(1, line.at(i));
	char ch;
	for (int j = i + 1; j < len; ++j) {
		ch = line.at(j);
		if (!isdigit(ch)) break;
		num.push_back(ch);
	}
	return atoi(num.c_str());
};
		
size_t Parser::findSecondSpiessFnc(const std::string &str) const{
	int countBraces = 0;
	bool firstBrace = false;
	size_t len = str.length();
	for (size_t i = 0; i < len; ++i){
		if (str.at(i) == '(') {
			++countBraces;
			firstBrace = true;
		} else if (str.at(i) == ')') {
			--countBraces;
		}
		if (countBraces == 0 && firstBrace) return i;
	}
	std::string message("Expression can not be parsed: ");
	message.append(str);
	throw Error(message);
};

StarNetwork* Parser::parseARTNetwork(const std::string& fileNodes, const std::string& fileLinks, const std::string& fileLinkFnc, bool isAdditive){
	FileReader readNodes(fileNodes);
	// read nodes and save zones 
	std::string line;
	std::set<int> zones;
  	char currChar;
  	std::string nodeID = "";
  	int nbNodes = 0;
	while (readNodes.isGood()){
		line = readNodes.getNextLine();
		size_t pos = line.find("a*");
		if (pos != std::string::npos) { // it is a zone node
			pos += 2;
			++nbNodes;
			if (pos >= line.length()) {
				std::string message = "Error occupied during parsing file: ";
				message.append(fileNodes);
				message.append(". Unexpected value on line: ");
				message.append(line);
				throw Error(message);
			}
			currChar = line.at(pos);
			while (isspace(currChar)) {
				++pos;
				currChar = line.at(pos);
			}
			nodeID.clear();
			while (isdigit(currChar)) {
				++pos;
				nodeID.push_back(currChar);
				currChar = line.at(pos);
			}
			if (nodeID == "") {
				std::string message = "Error occupied during parsing file: ";
				message.append(fileNodes);
				message.append(". Unexpected value on line: ");
				message.append(line);
				throw Error(message);
			}
			//std::cout << "NodeID = " << nodeID << " ";
			zones.insert(atoi(nodeID.c_str()));
		} else if (line.find("a") != std::string::npos) ++nbNodes;
	}
	if (nbNodes == 0) throw Error("Failed to parse file with nodes.");
	//std::cout << std::endl;
	std::set<int>::iterator it;
	for (it = zones.begin(); it != zones.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	FileReader readFnc(fileLinkFnc);
	// read link cost functions and create mapping function id <-> SpiessFncReator
	std::tr1::unordered_map<int, SpiessFncCreator> fncMap;
	SpiessFncCreator spCreator;
	int id = -1;
	std::string prevLine = "";
	while (readFnc.isGood()){
		// read several lines beloning to one function and concatinate them
		line = readFnc.getNextLine();
		//std::cout << "Reading LINE: " << line << std::endl;
		std::string input(prevLine);
		//std::cout << "Input: " << input << std::endl;
		while (true) {
			if (line.find("=") == std::string::npos || prevLine == "") {
				input.append(line);
				//std::cout << "Input: " << input << std::endl;
			} else {
				prevLine = line;
				break;	
			}
			line = readFnc.getNextLine();
			//std::cout << "Reading LINE: " << line << std::endl;
			if (line.find("=") != std::string::npos) {
				prevLine = line;
				break; //
			} 
			if (!readFnc.isGood()) break;
			
		}
		
		
		size_t fdPos = input.find("fd");
		if (fdPos != std::string::npos) { // consider only fd functions
			//std::cout << "FNC: " << input << std::endl;
			if (input.find("get(2)") != std::string::npos) {
				// divide into 2, parse each, combine
				size_t posBegin = findSecondSpiessFnc(input);
				std::string input1 = input.substr(0, posBegin+1);
				//std::cout << "input1 = " << input1 << std::endl;
				SpiessFncCreator spCreator1;
				id = Utils::parseSpiessFnc(input1, spCreator1);
				++posBegin;
				assert(posBegin < input.length() );
				for (;;) {
					if (isdigit(input.at(posBegin)) || input.at(posBegin) == '.') break;
					++posBegin;
					if (posBegin == input.length()){
						throw Error("Error occupied during parsing link cost function");
					}
				}
				std::string input2 = input.substr(posBegin, input.length() - posBegin);
				size_t eqPos = input.find("=");
				assert(eqPos > fdPos);
				std::string input2tmp = input.substr(fdPos, eqPos - fdPos + 1) + " ( " + input2;
				//std::cout << "input2tmp = " << input2tmp << std::endl;
				SpiessFncCreator spCreator2;
				id = Utils::parseSpiessFnc(input2tmp, spCreator2);
				spCreator.setParams(spCreator1, spCreator2);
				if (id != -1) fncMap.insert(std::make_pair<int, SpiessFncCreator>(id, spCreator));
			} else if (input.find("get(1)") != std::string::npos) {
				id = Utils::parseSpiessFnc(input, spCreator);
				if (id != -1) fncMap.insert(std::make_pair<int, SpiessFncCreator>(id, spCreator));
			} else {
				id = Utils::parseSpiessFnc(input, spCreator, true);
				if (id != -1) fncMap.insert(std::make_pair<int, SpiessFncCreator>(id, spCreator));
			}
			
		}
	}
	/*std::cout << "mymap contains:" << std::endl;
  	for ( std::tr1::unordered_map<int, SpiessFncCreator>::iterator  jt = fncMap.begin(); jt != fncMap.end(); ++jt ){
    		std::cout << "id =  " << jt->first << std::endl;
    		(jt->second).print();
    	}
  	std::cout << std::endl;*/
	// read links and create network
	FileReader readLinks(fileLinks);
	int nbLinks = 0;
	std::list<StarLink*> links;
	std::vector<std::pair<StarNode*, int> > nodes(nbNodes);
	for (int i = 0; i < nbNodes; ++i) {
		nodes[i] = std::make_pair((StarNode*)NULL, -1);
	}
	int countNodeLinks = 0;
	std::stringstream ss;
	int nbParams = 11;
	std::string params[nbParams];
	StarNode *node = NULL;
	StarLink *link = NULL;
	LinkFnc *fnc = NULL; 
	int prevNode = -1;
	int nodesCount = 0;
	while (readLinks.isGood()) {
		line = readLinks.getNextLine();
		std::string newLine = line;
			// remove all white spaces
			//newLine.erase(std::remove_if(newLine.begin(), newLine.end(), isspace), newLine.end());
		Utils::removeWhiteSpaces(newLine);
		if (!newLine.empty()){
			
			ss.clear();
			ss.str(line);
			for (int i = 0; i < nbParams; ++i) {
				ss >> params[i];
				//std::cout << "<" << params[i] << ">";
			}
			//std::cout << std::endl;
			
			if (params[4].find("a") != std::string::npos){  // link has automobile mode
				++nbLinks;
				std::cout << "Line: " << line << std::endl;
				int nodeID = atoi(params[1].c_str());
				if (prevNode != nodeID) {
					
					node = new StarNode(nodeID, zones.find(nodeID) != zones.end());
					nodes[nodesCount] = std::make_pair(node, -1);
					if (nodesCount > 0) nodes[nodesCount - 1].second = countNodeLinks;
					countNodeLinks = 0;
					++nodesCount;
					std::cout << "Node " << nodeID << " isZone = " << node->getIsZone() << std::endl;
					prevNode = nodeID;
				}
				
				// creating link cost functions
				FPType length = atof(params[3].c_str());
				int lanes = atoi(params[6].c_str());
				int fncID = atoi(params[7].c_str());
				// look for a link cost function
				std::tr1::unordered_map<int, SpiessFncCreator>::iterator got = fncMap.find(fncID);

				if ( got == fncMap.end() ) {
				    	throw Error("Cannot find link cost function.");
				} else {
					fnc = (got->second).create(length, lanes);
					fnc->print();
				}
				
				link = new StarLink(nodeID, atoi(params[2].c_str()), fnc);
				std::cout << "link: [" << link->getNodeFrom() << ", " << link->getNodeTo() << "]" << std::endl;
				links.push_back(link);
				++countNodeLinks;
			}
		}
	}
	nodes[nodesCount - 1].second = countNodeLinks;
	
	std::string netName = "";
	Utils::extractName(fileLinks.c_str(), netName);
	StarNetwork* net = new StarNetwork(nbNodes, nbLinks, netName);
	std::list<StarLink*>::iterator itLinks = links.begin();
	// filling the network
	std::cout << "nbNodes =  " << nbNodes << std::endl;
	for(int i = 0; i < nbNodes; ++i){
		if (nodes[i].second != -1) {
			//std::cout << "Adding node " << nodes[i].first->getID() << std::endl;
			net->addNode(nodes[i].first);
			for (int j = 0; j < nodes[i].second; ++j) {
				net->addLink(*itLinks);
				//std::cout << "Adding link " << (*itLinks)->getIndex() << std::endl;
				++itLinks;
			}
		}
	}
	return net;
};

ODMatrix* Parser::parseARTODMatrix(const std::string &fileName, int nbNodes){
	FileReader fileMat(fileName);
	std::string line;
	Origin *origin = NULL;
	PairOD *dest = NULL;
	FPType demand = 0.0;
	int destID = -1;
	int prevOrigin = -1;
	int originID = -1;
	ODMatrix *mat = new ODMatrix(nbNodes);
	while (fileMat.isGood()){
		line = fileMat.getNextLine();
		std::string newLine = line;
		Utils::removeWhiteSpaces(newLine);
		if (!newLine.empty()){
			originID = extractInt(line, 0);
			if (prevOrigin != originID) {
				origin = new Origin(originID);
				mat->addOrigin(origin);	
				prevOrigin = originID;
			}
			assert(origin != NULL);
			// get all destinations from current line
			size_t pos = extractARTDestination(0, line, destID, demand);
				
			while (pos != std::string::npos){
				if ((destID != originID) && (demand != 0.0)) {
					dest = new PairOD(destID, demand);
					origin->addDestination(dest);
				}
				pos = extractARTDestination(pos, line, destID, demand);
			}
		}
	}
	return mat;
};

