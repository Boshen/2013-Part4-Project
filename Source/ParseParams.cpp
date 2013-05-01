#include "ParseParams.h"
#include "Error.h"
#include "UtilsString.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>

ParseParams::ParseParams(std::string paramsFile){
	_fileName = paramsFile;
	_longComment = false;
};

ParseParams::~ParseParams(){

};

void ParseParams::execute(Params *params){
	// open file
	std::ifstream paramsFile(_fileName.c_str());
	if (paramsFile.is_open()) {
		
		// parse all fields
		std::string line = "";
		std::string field = "";
		std::string value = "";
		while ( paramsFile.good() ) {
			getline(paramsFile, line);
			line = skipComments(line);
			std::string newLine = line;
			// remove all white spaces
			Utils::removeWhiteSpaces(newLine);
			if (!newLine.empty()){
				field = Utils::getSubString("<", ">", line); // First entry of form <FIELD NAME> will be treated.
				value = Utils::getSubString("{", "}", line); // First entry of form {VALUE} will be treated.
				params->addParameter(field, value);
			}
		}
		
		// close file
		paramsFile.close();
	} else {
		std::string message = "Unable to open a file: ";
		message.append(_fileName);
		Error er(message);
		throw er;
	}
	
};

// Supported comments: /*, //
std::string ParseParams::skipComments(std::string line){
	size_t found;
	if (_longComment) {
		found = line.find("*/");
		if (found != std::string::npos) {
			_longComment = false;
			return line.substr(found+2);
		}
		return "";	
	}
	found = line.find("//");
	std::string resLine = line;
	if (found != std::string::npos) {
		resLine = line.substr(0, found);
	}
	found = resLine.find("/*");
	if (found != std::string::npos) {
		_longComment = true;
		resLine = resLine.substr(0, found);
	}
	return resLine;
};
