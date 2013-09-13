#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <sstream>

#include "Error.h"
#include "ParseParams.h"
#include "ObjectManager.h"
#include "Utils.h"
#include "FileWriter.h"

void writeResults(const std::string &name, const std::string &fileName, int nbIter, double timePassed){
	FileWriter flWrite(fileName, true);
	std::ostringstream s;
	s << name << " " << nbIter << " " << timePassed << "\n";
	std::string line = s.str();
	flWrite.writeLine(line);
	//fprintf(pFile, "%s %s %d %4.5f \n", (net->getNetName()).c_str(), (params.getAlgoParams()).c_str(), nbIter, timePassed);
};

#define NB_INPUT_PARAMS 2
/** Input: ./ta input.params 
 *	input.params - path to the file with parameters
 **/
int main(int argc, char *argv[]) {
	try {
		/** Check if the number of input parameters is correct
		 **/
		if (argc != NB_INPUT_PARAMS) {
			Error er("Number of input parameters is not correct.");
			throw er;
		}
		std::string fileParams = argv[1];
		
		/** Parse file with parameters 
		 **/
		Params params;
		ParseParams parser;
		parser.execute(fileParams, &params);
		params.print();
		
		/** For registering time of calculation and object creation
		 **/
		Timer timer;
		timer.start();
		
		/** ObjectManager - creation of necessary objects depending
		  * on configuration file. Also responsible for error handling
		  * related to valid parameters entry and provided files and memory
		  * deallocation
		**/
		std::cout << "*********************************" << std::endl;
		ObjectManager manager(&params, timer);
		std::cout << "*********************************" << std::endl;
		//ODMatrix* mat = manager.getODMatrix();
	
		/** Main execution 
		**/
		/*// to load link flows from file and check convergence
		StarNetwork *net = manager.getNet(); // load network from file - path to file must be specified in input.params <NETWORK>
		net->loadFromFile("SiouxFalls.flow"); // loads link flows from file SiouxFalls.flow: 
							// file MUST contain 4 columns: nodeFrom nodeTo linkFlow anyValue
							// only first three values are considered, however 4th column must be present as well
		net->calculateLinkCosts(); // calculate travel times for new link flows
		ConvMeasure *gap = manager.getConvMeasure(); // creates convergence measure - relative gap
		gap->isConverged(); // calculates relative gap
		std::cout << "gap = " << gap->getGap() << std::endl;// prints the value of the gap on the screen*/
		
		std::cout << "******ALGORITHM***************************" << std::endl;
		DecoratedEqAlgo *algo = manager.getEqAlgo();
		
		int nbIter = algo->execute();
		timer.stop(); //will stop only if it was not stopped before
		
		StarNetwork *net = manager.getNet();
		//net->print();
		//net->printToFile("tmp.flows");
		std::cout << "Time: " << timer.getTimePassed() << " s."  << " nbIter = " << nbIter << std::endl;
		std::cout << "MAX = " << Utils::checkFeasibility(net, manager.getODMatrix()) << std::endl;//*/
		manager.printCounters();
		
		//writeResults(params.getAutoFileName(' '), "test2All.res", nbIter, timer.getTimePassed());
		 
	} catch (Error error) {
		std::cout << "Error has occured during execution: " << error.getMessage() << std::endl;
		return 1;
	}
	/*catch (...) {
		std::cout << "Unxpected error has occured during execution." << std::endl;
		return 1;
	}*/
	return 0;
};
