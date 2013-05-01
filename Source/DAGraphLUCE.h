#ifndef DAGRAPH_LUCE
#define DAGRAPH_LUCE

#include "DAGraph.h"

#include <vector>

class DAGraphLUCE : public DAGraph {
	public:
		DAGraphLUCE(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex);
		~DAGraphLUCE();
		
		bool moveFlow();
		
		void update();
		
	private:
		
		const int nbNodes_;
		const int nbLinks_;
		std::vector<FPType> derivatives_;
		std::vector<FPType> flowPortions_;
		std::vector<FPType> nodeFlows_;
		
		void calcFlowPortions();
		
		//for direction of descent
		void computeAvCosts(std::vector<FPType> &C, std::vector<FPType> &G);
		void computeDirection(std::vector<FPType> &e_links, const std::vector<FPType> &C, const std::vector<FPType> &G);
		FPType computeStepSize(const std::vector<FPType> &e_links);
		void assignNewFlow(FPType stepSize, const std::vector<FPType> &e_links);
};

#endif
