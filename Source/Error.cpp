#include "Error.h"

Error::Error(std::string message) : _errMessage(message){

};

Error::~Error(){

};

std::string Error::getMessage(){
	return _errMessage;
};
