#include "FileReader.h"
#include "FileWriter.h"
#include "UtilsString.h"

#include <list>
#include <iostream> 
#include <string>
#include <cassert>
#include <stdlib.h>
#include <sstream>
#include <limits>

#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

typedef std::pair<double, long double> dPair;
double getTime(const std::string &input){
    	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    	boost::char_separator<char> sep(" "); 
    	tokenizer tokens(input, sep);
    	tokenizer::iterator tok_iter = tokens.begin(); 
     	return std::stod(*tok_iter);
};

long double getGap(const std::string &input){
    	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    	boost::char_separator<char> sep(" "); 
    	tokenizer tokens(input, sep);
    	tokenizer::iterator tok_iter = tokens.begin();
    	++tok_iter; 
     	return std::stold(*tok_iter);
};

void readFile(const std::string &name, std::list<dPair> &mymap){
	FileReader readf(name);
	std::string line;
	dPair mypair(0.0, 0.0);
	while (readf.isGood()){
		line = readf.getNextLine();
		std::string tmp = line;
		Utils::removeWhiteSpaces(tmp);
		if (!tmp.empty()){
			std::cout << line << std::endl;
			mypair.first = getTime(line);
			mypair.second = getGap(line);
			if (mypair.first <= 6) mymap.push_back(mypair);
		} 
	}
};

void getMinPair(std::list<dPair> &mymap, dPair &minPair, long double lb, long double ub){
	std::list<dPair> elems;
	minPair.first = -1;
	minPair.second = -1;
	for (std::list<dPair>::iterator kt = mymap.begin(); kt != mymap.end(); ++kt){
		//std::cout << "lb = " << lb << " ub = " << ub << " elem = " << kt->second << std::endl;
		if ((kt->second >= lb) && (kt->second <= ub)) {
			//std::cout << "lb = " << lb << " ub = " << ub << " elem = " << kt->first << std::endl;
			elems.push_back(*kt);
		}
	}
	
	long double minElem = std::numeric_limits<long double>::max();
	for (std::list<dPair>::iterator kt = elems.begin(); kt != elems.end(); ++kt) {
		if (kt->second < minElem) {
			minElem = kt->second;
			minPair.first = kt->first;
			minPair.second = kt->second;
		}
	}
};

void processMap(std::list<dPair> &newMap, std::list<dPair> &mymap){
	long double inters[8] = {1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1.0}; //{0.0, 1e-12, 1e-10, 1e-8, 1e-6, 1e-4, 1e-3, 1e-2, 1e-1, 1.0};
	int n = sizeof(inters) / sizeof (long double);
	dPair minPair(0.0, 0.0);
	for (int i = 0; i < n-1; ++i) {
		std::cout << "Processing interval: [" << inters[i] << ", " << inters[i+1] << "]" << std::endl;
		getMinPair(mymap, minPair, inters[i], inters[i+1]);
		std::cout << "minPair: [" << minPair.first << ", " << minPair.second << "]" << std::endl;
		if (minPair.first > -1) newMap.push_back(minPair);
	}
};

int main(int argc, char** argv){
	assert(argc == 2);
	std::list<dPair> mymap;
	std::string name = argv[1];
	readFile(name, mymap);
	
	std::list<dPair> newMap;
	processMap(newMap, mymap);
	
	for (std::list<dPair>::iterator it = newMap.begin(); it != newMap.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	/*FileWriter wFile("tmp.inter");
	std::stringstream ss;
	std::string line;
	for (std::list<dPair>::iterator it = newMap.begin(); it != newMap.end(); ++it) {
		ss.str("");
		ss << it->first << " " << it->second << "\n";
		line = ss.str();
		wFile.writeLine(line);
	}*/
	return 0;
};
