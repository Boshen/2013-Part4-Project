#include "UtilsString.h"
#include "Error.h"

#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <math.h>

void Utils::removeWhiteSpaces(std::string &line){
	line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
}

std::string Utils::getSubString(std::string first, std::string last, std::string line){
	size_t found = line.find(first);
	if (found == std::string::npos) {
		std::string message = first; 
		message.append(" is missing in line: ");
		message.append(line);
		Error er(message);
		throw er;	
	}
	size_t foundEnd = line.find(last);
	if (foundEnd == std::string::npos) {
		std::string message = last; ;
		message.append(" is missing in line: ");
		message.append(line);
		Error er(message);
		throw er;
	}
	if (found > foundEnd) {
		std::string message = "Field name or value is missing in line: ";
		message.append(line);
		Error er(message);
		throw er;
	}
	if (foundEnd - found <= 1) return "";
	return line.substr(found + 1, foundEnd - found - 1);
};

std::string Utils::skipOneLineComment(std::string comment, std::string line){
	size_t found = line.find(comment);
	if (found != std::string::npos) {
		if (found == 0) {
			return "";
		} else {
			return line.substr(0, found - 1);
		}
	}
	return line;
};

void Utils::extractName(const char* filepath, std::string& name){
	
	// Format of file path: "/bla/bla/bla/problemName.someextension"
	// We try to find the interval [begin; end) which contains "problemName"
	const char* end = filepath + strlen(filepath);

	// We rewind "end"
	// Find the position of the last point (filepath if there is no such point)
	while(end > filepath) {
		if(*(end-1) == '.'){
			--end;
			break;
		}
		--end;
	}

	const char* begin = end;

	while(      begin  > filepath
        && *(begin-1) != '/'
		&& *(begin-1) != '\\'){
		--begin;
	}

	name.assign(begin, end);
};

bool Utils::isDigits(const std::string &str){
	bool hasPoint = false;
	int length = str.length();
	for (int i = 0; i < length; ++i) {
		if (!isdigit(str.at(i))) {
			if (str.at(i) == '.' && !hasPoint && i != length-1) {
				hasPoint = true; 
			} else {
				return false;
			}
		}	
	}
	return true;
   
};

bool Utils::isInt(const std::string &str){
	return str.find_first_not_of("0123456789") == std::string::npos;
};
