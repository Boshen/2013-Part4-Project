#ifndef _PARAMS_
#define _PARAMS_

#include <string>
#include <map>

class Params {
	public:
		Params();
		~Params();
		
		std::string getParam(std::string name);
		void addParameter(std::string field, std::string value);
		void print();
		std::string getAlgoParams();
		
	private:
		std::map<std::string, std::string> _paramDict;
};

#endif
