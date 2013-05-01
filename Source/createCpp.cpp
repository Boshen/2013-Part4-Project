#include <stdlib.h>
#include <iostream>
#include <string>
#include <cassert>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

#include "FileReader.h"
#include "FileWriter.h"
#include "Error.h"
#include "UtilsString.h"

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

std::string extractClassName(const std::string& line, size_t posClass){
	int len = line.length();
	if (posClass + 5 >= len) throw Error("Class must have a name.");
	char ch;
	std::string className("");
	bool firstCharFound(false);
	for (int i = posClass + 6; i < len; ++i) {
		ch = line.at(i);
		if (!isspace(ch)) {
			className.push_back(ch);
			firstCharFound = true;
		} else if (firstCharFound) {
			break;
		}
	}
	return className;
};

std::string createCppFileName(const std::string& line) {
	size_t posDot = line.find(".");
	int len = line.length();
	if (posDot + 1 >= len) {
		std::string message("Cannot find a file extension in line: ");
		message.append(line);
		throw Error(message);
	}
	std::string newName = line.substr(0, posDot + 1);
	newName.append("cpp");
	return newName;
};

void makePrettySpaces(std::string& line){
	//std::cout << "Making pretty: |" << line << "|" << std::endl;
	int len = line.length();
	assert(len > 0);
	char prev = line.at(0);
	char cur;
	for(int i = 1; i < len; ++i){
		cur = line.at(i);
		//std::cout << "cur = (" << cur << ") prev = (" << prev << ")" << std::endl;
		if (cur == '(' || cur == ')') {
			if (isspace(prev)) {
				line.erase(i-1, 1);
				//std::cout << "prev is deleted line: " << line << std::endl;
				--len;
				--i;
			}
		} else if (isspace(cur)) {
			if (prev == ')' || prev == '(') {
				line.erase(i, 1);
				//std::cout << "cur is deleted line: " << line  << std::endl;
				--len;
				--i;
				cur = line.at(i);
			}
		}
		prev = cur;
	}
};

std::string writeAllRemainingTokens(tokenizer::iterator tok_iter, const tokenizer& tokens, bool incrementFirst = true){
	std::string result("");
	if (incrementFirst) ++tok_iter;
	std::string tmp("");
	for(; tok_iter != tokens.end(); ++tok_iter){
		tmp = *tok_iter;
		result.append(tmp);
		result.append(" ");
	}
	makePrettySpaces(result);
	//std::cout << "Generated line: " << result << std::endl;
	return result;
};

bool generateLine(const std::string& className, const std::string& baseLine, std::string& result){
	
	boost::char_separator<char> sep(" ;\t\n", "()~"); 
	tokenizer tokens(baseLine, sep);
	std::string prevToken("");
	std::string prevPrevToken("");
	std::string prevPrevPrevToken("");
	for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
	      //  std::cout << "<" << *tok_iter << "> " << std::endl;
	     	std::string tmp = *tok_iter;
	     	if (tmp != "virtual" || tmp != "static") { // skip these words
	     		if (tmp == "~") { // distructor
	     			result.append(className);
	     			result.append("::~");
	     			result.append(writeAllRemainingTokens(tok_iter, tokens));
	     			result.append(" {\n");
	     			//std::cout << "In total generated line: " << result << std::endl;
	     			return false;
	     		} else if (tmp == className) { // constructor
	     			result.append(className);
	     			result.append("::");
	     			result.append(className);
	     			result.append(writeAllRemainingTokens(tok_iter, tokens));
	     			result.append(" {\n");
	     			//std::cout << "In total generated line: " << result << std::endl;
	     			return false;
	     		} else if (tmp == "(") {
	     			assert(!prevPrevToken.empty());
	     			assert(!prevToken.empty());
	     			if (prevPrevPrevToken == "const") {
	     				result.append(prevPrevPrevToken);
	     				result.append(" ");
	     			}
	     			result.append(prevPrevToken);
	     			result.append(" ");
	     			result.append(className);
	     			result.append("::");
	     			result.append(prevToken);
	     			result.append(writeAllRemainingTokens(tok_iter, tokens, false));
	     			result.append(" {\n");
	     			//std::cout << "In total generated line: " << result << std::endl;
	     			if (prevPrevToken == "void") {
	     				return false;
	     			} else {
	     				return true;
	     			}
	     		}//*/
	     	}
	     	prevPrevPrevToken = prevPrevToken;
	     	prevPrevToken = prevToken;
	     	prevToken = tmp;
     	}
	return false;
};

int main(int argc, char **argv){
	try {
		if (argc != 2) {
			throw Error("There must be one input poarameter - path to a header file.");
		}
		std::string fileName = argv[1];
		FileReader readFile(fileName);
		std::string fileNameWrite = createCppFileName(fileName);
		FileWriter writeFile(fileNameWrite);
		
		std::string line("");
		std::string className("");
		line = "#include \"";
		std::string tmp("");
		Utils::extractName(fileName.c_str(), tmp);
		line.append(tmp);
		line.append(".h\"\n");
		//std::cout << "First line: " << line << std::endl;
		writeFile.writeLine(line);
		writeFile.addEmptyLine();
		bool addReturn(false);
		while (readFile.isGood()){
			line = readFile.getNextLine();
			std::string newLine = line; 
			Utils::removeWhiteSpaces(newLine);
			if (!newLine.empty()){
				size_t posClass = line.find("class");
				if (posClass != std::string::npos){
					className = extractClassName(line, posClass);
					//std::cout << "class name = " << className << std::endl;
				} else {
					size_t posBrace = line.find("(");
					if (posBrace != std::string::npos){
						assert(!className.empty());
						//std::cout << "Creating method: " << line << std::endl;
						tmp.clear();
						addReturn = generateLine(className, line, tmp);
						writeFile.writeLine(tmp);
						if (addReturn) {
							writeFile.writeLine("\t return ;\n");
						} else {
							writeFile.addEmptyLine();
						}
						writeFile.writeLine("}; \n");
						writeFile.addEmptyLine();
						
					} // everything else is ignored
				}
			}
		}
		return 0;
	} catch (Error error) {
		std::cout << "Error has occured during execution: " << error.getMessage() << std::endl;
		return 1;
	}
};

