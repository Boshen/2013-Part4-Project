#include <stdlib.h>
#include <iostream>

#include "Params.h"
#include "Error.h"

Params::Params(){
	
};

Params::~Params(){

};

std::string Params::getParam(std::string name){
	 std::map<std::string, std::string>::iterator it = _paramDict.find(name);
	 if (it != _paramDict.end()) return it->second;
	 return "";
	 
};

void Params::addParameter(std::string field, std::string value){
	if ((_paramDict.insert(std::pair<std::string, std::string>(field, value))).second == false ) {
		std::string message = "Field: ";
		message.append(field);
		message.append(" was already added with value: ");
		message.append(value);
		Error er(message);
		throw er;
	}
};

void Params::print(){
	//std::map<std::string, std::string>::iterator it = _paramDict.begin();
    std::cout << "Network: " << _paramDict["NETWORK"] << std::endl;
    std::cout << "Algo   : " << _paramDict["ShPathAlgo"] << std::endl;
    std::cout << "Data   : " << _paramDict["ShPathDataStruct"] << std::endl;
	//for(; it != _paramDict.end(); it++) {
	//	std::cout << "Field: " << it->first << " Value: " << it->second << std::endl;
	//}
};

std::string Params::getAlgoParams(){
	return getParam("SPARSITY") + " " + getParam("LINE_SEARCH") + " " + getParam("ALGORITHM") + " " + getParam("EQUILIBRATION") + " " + getParam("APPROACH");
};
