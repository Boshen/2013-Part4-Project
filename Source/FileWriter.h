#ifndef FILE_WRITER
#define FILE_WRITER

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

class FileWriter {
	public:
		explicit FileWriter(const std::string& fileName);
		~FileWriter();
		
		void writeLine(const std::string& line);
		void addEmptyLine();
		
		std::string getName() const;
		
	private:
		const std::string name_;
		std::ofstream file_;
};

#endif

