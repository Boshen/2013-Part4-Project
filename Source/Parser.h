#ifndef _PARSER_
#define _PARSER_

#include "StarNetwork.h"
#include "ODMatrix.h"

class Parser {
	public:
		Parser();
		~Parser();
		StarNetwork* parseNetwork(const std::string& fileName, bool isAdditive);
		ODMatrix* parseODMatrix(const std::string& fileName, int nbNodes);
		
		// for ART network
		StarNetwork* parseARTNetwork(const std::string& fileNodes, const std::string& fileLinks, const std::string& fileLinkFnc, bool isAdditive);
		ODMatrix* parseARTODMatrix(const std::string& fileName, int nbNodes);
		
	private:
		void checkEmptyValue(int value);
		size_t extractDestination(size_t posFrom, const std::string &line, int &destID, FPType &demand) const;
		size_t extractARTDestination(size_t posFrom, const std::string &line, int &destID, FPType &demand) const;
		int extractInt(const std::string& line, size_t pos) const;
		FPType extractNumber(const std::string& line, size_t pos, size_t &nextPos) const;
		size_t findSecondSpiessFnc(const std::string &str) const;
};

#endif
