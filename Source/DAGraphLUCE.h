#ifndef DAGRAPH_LUCE
#define DAGRAPH_LUCE

#include "DAGraph.h"

#include <vector>

class DAGraphLUCE : public DAGraph {
	public:
		DAGraphLUCE(StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol, int originIndex);
		~DAGraphLUCE();
		
		bool moveFlow(int iter);
		
		void update();
		void postUpdateCall(); // when topological order is known
		
	private:
		
		const int nbNodes_;
		const int nbLinks_;
		std::vector<FPType> derivatives_;
		//std::vector<FPType> flowPortions_;
		//std::vector<FPType> nodeFlows_;
		std::vector<FPType> nodeFlowsInv_;
		std::vector<FPType> flowPortionsInv_;
		
		void calcFlowPortions();
		
		//for direction of descent
		void computeAvCosts(std::vector<FPType> &C, std::vector<FPType> &G);
		void computeDirection(std::vector<FPType> &e_links, const std::vector<FPType> &C, const std::vector<FPType> &G);
		FPType computeStepSize(const std::vector<FPType> &e_links);
		void assignNewFlow(FPType stepSize, const std::vector<FPType> &e_links);

};

#endif
