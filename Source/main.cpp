#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cassert>

#include "Error.h"
#include "ParseParams.h"
#include "ObjectManager.h"
#include "Utils.h"

#include "ShPath/ShPathAstarBidirect.h"
#include "ShPath/ShPathInterface.h"
#include "ShPath/ShPathFactory.h"

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
		ParseParams parser(fileParams);
		parser.execute(&params);
		params.print();
		
		/** ObjectManager - creation of necessary objects depending
		  * on configuration file. Also responsible for error handling
		  * related to valid parameters entry and provided files and memory
		  * deallocation
		**/
		ObjectManager manager(&params);
	
		/** Main execution 
		**/
		// to load link flows from file and check convergence
		/*StarNetwork *net = manager.getNet();
		net->loadFromFile("CompareToBestKnown/SiouxFalls.flow");
		net->calculateLinkCosts();
		net->print();
		net->printToFile("tmp.flows");
		ConvMeasure *gap = manager.getConvMeasure();
		gap->isConverged();*/
		
		//StarNetwork *net = manager.getNet();
		/*net->print();
		ODMatrix *mat = manager.getODMatrix();
		mat->print();//*/
		
		StarNetwork *net = manager.getNet();
		DecoratedEqAlgo *algo = manager.getEqAlgo();
		clock_t start, end;
		start = clock();
		int nbIter = algo->execute();
		//algo->execute();
		end = clock();
		
		//net->printToFile("tmp.flows");
		double timePassed = ((double)(end-start))/ (CLOCKS_PER_SEC);
		std::cout << "Run Time: " << timePassed << " s."  << " nbIter = " << nbIter << std::endl;
        std::cout << "MAX = " << Utils::checkFeasibility(net, manager.getODMatrix()) << std::endl;//*/
        //shPath->calculate(0, 37);
        //StarLink *link = shPath->getInComeLink(37);
        //if(link==NULL){
        //    std::cout << "NULL" << std::endl;
        //    return -1;
        //}
        //FPType nextDest = link->getNodeFromIndex();
        //Path path;
        //while (link != NULL) {
        //    path.addLinkToPath(link);
        //    nextDest = link->getNodeFromIndex();
        //    link = shPath->getInComeLink(nextDest);
        //}
        //path.print();
        //for(int i = 0; i < 23; i++){ // using D as number of zone nodes
        //    shPath->calculate(i);
        //    for(int j = 0; j < 23; j++){
        //        //(*initCosts)[i*_nNodes+j] = (*Nodes)[j].dist;
        //        std::cout << shPath->getCost(j) << " ";
        //    }
        //    std::cout << std::endl;
        //}
        //net->print();
        /*FILE * pFile = NULL;
          pFile = fopen("resultsB_v2.txt","a");
          assert(pFile);
          fprintf(pFile, "%s %s %d %4.5f \n", (net->getNetName()).c_str(), (params.getAlgoParams()).c_str(), nbIter, timePassed);
          fclose(pFile); //*/
        /*
        ShortestPath *shPath = manager.getShPath();
        for(int i =0;i < 38;i++){
            for(int j =0;j<38;j++){
                if (i!=j){
                    shPath->calculate(i, j);
                    StarLink *link = shPath->getInComeLink(j);
                    if(link==NULL){
                        std::cout << "NULL" << std::endl;
                        return -1;
                    }
                    FPType nextDest = link->getNodeFromIndex();
                    Path path;
                    while (link != NULL) {
                        path.addLinkToPath(link);
                        nextDest = link->getNodeFromIndex();
                        link = shPath->getInComeLink(nextDest);
                    }
                    //path.print();
                }

            }
        }
        */
        ShPathAstarBidirect<SkewHeap>* shPath = (ShPathAstarBidirect<SkewHeap>*)manager.getShPath();
        shPath->calculate(384, 368);
        StarLink *link = shPath->getInComeLink(368);
        FPType nextDest = link->getNodeFromIndex();
        Path path;
        while (link != NULL) {
            path.addLinkToPath(link);
            nextDest = link->getNodeFromIndex();
            link = shPath->getInComeLink(nextDest);
        }

        std::vector< std::pair<int, int> >& FScanned = *(shPath->getForwardScanned());
        std::vector< std::pair<int, int> >& BScanned = *(shPath->getBackwardScanned());

        std::cout << "forwardtree" << std::endl;
        for(size_t i=0;i<FScanned.size();i++){
            std::cout << FScanned[i].first << " " << FScanned[i].second << std::endl;
        }

        std::cout << "backwardtree" << std::endl;
        for(size_t i=0;i<BScanned.size();i++){
            std::cout << BScanned[i].first << " " << BScanned[i].second << std::endl;
        }

        std::cout << "path" << std::endl;
        path.print();

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
