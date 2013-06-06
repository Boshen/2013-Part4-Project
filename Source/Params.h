#ifndef _PARAMS_
#define _PARAMS_

#include <string>
#include <map>

class Params {
	public:
		Params();
		~Params();
		
		std::string getParam(const std::string &name);
		std::string getParamWoSpaces(const std::string &name);
		void addParameter(const std::string &field, const std::string &value);
		void print();
		std::string getAlgoParams();
		// format: NetName_Algorithm_Equilibration_Approach_LineSearch
		std::string getAutoFileName(char del = '_');
		
	private:
		std::map<std::string, std::string> _paramDict;
};

#endif
