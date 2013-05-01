#ifndef _UTILS_STRING_
#define _UTILS_STRING_

#include <stdlib.h>
#include <list>
#include <string>

namespace Utils {
	std::string getSubString(std::string first, std::string last, std::string line);

	void extractName(const char* filepath, std::string& name);

	std::string skipOneLineComment(std::string comment, std::string line);

	void removeWhiteSpaces(std::string &line);

	bool isDigits(const std::string &str);
	
	bool isInt(const std::string &str);

}

#endif
