#ifndef _PARSE_PARAMS_
#define _PARSE_PARAMS_

#include "Params.h"

#include <string>

class ParseParams {
	public:
		explicit ParseParams();
		~ParseParams();
		
		void execute(const std::string &fileName, Params *params);
		
	private:
		bool _longComment;
		
		std::string skipComments(std::string line);
		
};

#endif
