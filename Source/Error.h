#ifndef _ERROR_
#define _ERROR_
#include <string>

class Error {
	public:
		Error(std::string message);
		~Error();
		
		std::string getMessage();
	
	private:
		std::string _errMessage;
};

#endif
