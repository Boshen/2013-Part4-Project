#ifndef FILE_READER
#define FILE_READER

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>

class FileReader {
	public:
		FileReader(const std::string& fileName);
		~FileReader();
		
		bool isGood() const;
		std::string getNextLine(); 
		
	private:
		std::ifstream file_;
		std::string name_;
};

#endif
