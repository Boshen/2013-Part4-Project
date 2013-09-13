#include <stdlib.h>
#include <iostream>

#include "Params.h"
#include "Error.h"
#include "UtilsString.h"

Params::Params(){
	
};

Params::~Params(){

};

std::string Params::getParam(const std::string &name){
	 std::map<std::string, std::string>::iterator it = _paramDict.find(name);
	 if (it != _paramDict.end()) return it->second;
	 return "";
	 
};

std::string Params::getParamWoSpaces(const std::string &name){
	std::string retVal = getParam(name);
	Utils::removeWhiteSpaces(retVal);
	return retVal;
};

void Params::addParameter(const std::string &field, const std::string &value){
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
	std::map<std::string, std::string>::iterator it = _paramDict.begin();
	for(; it != _paramDict.end(); it++) {
		std::cout << "Field: " << it->first << " Value: " << it->second << std::endl;
	}
};

std::string Params::getAlgoParams(){
	return getParam("LINE_SEARCH") + " " + getParam("ALGORITHM") + " " + getParam("EQUILIBRATION") + " " + getParam("APPROACH");
};

// format: NetName_Algorithm_Equilibration_Approach_LineSearch
std::string Params::getAutoFileName(char del){
	std::string netName;
	Utils::extractName(getParam("NETWORK").c_str(), netName);
	std::string sg = getParamWoSpaces("NEWTON_STEPS");
	if (sg != "") return netName + del + getParam("ALGORITHM") + del + getParam("EQUILIBRATION") + del + getParam("APPROACH") + del + getParam("LINE_SEARCH") + del + sg + del + getParam("ShPathAlgo");
	return netName + del + getParam("ALGORITHM") + del + getParam("EQUILIBRATION") + del + getParam("APPROACH") + del + getParam("LINE_SEARCH") + del + getParam("ShPathAlgo");
};
