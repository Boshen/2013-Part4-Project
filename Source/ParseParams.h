#ifndef _PARSE_PARAMS_
#define _PARSE_PARAMS_

#include "Params.h"

#include <string>

class ParseParams {
	public:
		ParseParams(std::string paramsFile);
		~ParseParams();
		
		void execute(Params *params);
		
	private:
		std::string _fileName;
		bool _longComment;
		
		std::string skipComments(std::string line);
		
};

#endif
