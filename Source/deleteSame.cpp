#include "FileReader.h"
#include "FileWriter.h"
#include "UtilsString.h"

#include <map>
#include <iostream> 
#include <string>
#include <cassert>
#include <stdlib.h>
#include <sstream>

#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

double getTime(const std::string &input){
    	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    	boost::char_separator<char> sep(" "); 
    	tokenizer tokens(input, sep);
    	tokenizer::iterator tok_iter = tokens.begin(); 
     	return std::stod(*tok_iter);
};

std::string getGap(const std::string &input){
    	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    	boost::char_separator<char> sep(" "); 
    	tokenizer tokens(input, sep);
    	tokenizer::iterator tok_iter = tokens.begin();
    	++tok_iter; 
     	return *tok_iter;
};

int main(int argc, char** argv){
	assert(argc == 2);
	std::string name = argv[1];
	FileReader readf(name);
	std::string line;
	double time = 0.0;
	std::string gap;
	std::map<double, std::string> mymap;
	std::string linePr;
	int count = 1;
	while (readf.isGood()){
		linePr = line;
		line = readf.getNextLine();
		std::string tmp = line;
		Utils::removeWhiteSpaces(tmp);
		if (!tmp.empty()){
			std::cout << line << std::endl;
			time = getTime(line);
			gap = getGap(line);
			if (count % 20 == 0) mymap.insert(std::pair<double, std::string>(time, gap));
			++count;
		} 
	}
	FileWriter wFile("tmp.conv");
	std::stringstream ss;
	for (std::map<double, std::string>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
		ss.str("");
		ss << it->first << " " << it->second << "\n";
		line = ss.str();
		//if (it->first <= 830) 
		wFile.writeLine(line);
	}
	wFile.writeLine(linePr);
	return 0;
};
