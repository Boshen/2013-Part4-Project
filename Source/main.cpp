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

//void writeResults(const std::string &name, const std::string &fileName, int nbIter, double timePassed){
//    FileWriter flWrite(fileName, true);
//    std::ostringstream s;
//    s << name << " " << nbIter << " " << timePassed << "\n";
//    std::string line = s.str();
//    flWrite.writeLine(line);
//    //fprintf(pFile, "%s %s %d %4.5f \n", (net->getNetName()).c_str(), (params.getAlgoParams()).c_str(), nbIter, timePassed);
//};

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
        //params.print();

        /** For registering time of calculation and object creation
         **/
        Timer timer;
        timer.start();

        /** ObjectManager - creation of necessary objects depending
         * on configuration file. Also responsible for error handling
         * related to valid parameters entry and provided files and memory
         * deallocation
         **/
        ObjectManager manager(&params, timer);

        /** Main execution 
         **/
        // to load link flows from file and check convergence
        /*
           net->loadFromFile("CompareToBestKnown/SiouxFalls.flow");
           net->calculateLinkCosts();
        //net->printToFile("tmp.flows");
        ConvMeasure *gap = manager.getConvMeasure();
        gap->isConverged();
        */

        /*StarNetwork *net = manager.getNet();
          net->print();
          ODMatrix *mat = manager.getODMatrix();
          mat->print();//*/
        DecoratedEqAlgo *algo = manager.getEqAlgo();


        int nbIter = algo->execute();
        //end = clock();
        timer.stop(); //will stop only if it was not stopped before

        //net->printToFile("tmp.flows");
        //double timePassed = ((double)(end-start))/ (CLOCKS_PER_SEC);
        //StarNetwork *net = manager.getNet();
        std::cout << std::fixed << timer.getTimePassed() << " | "  <<  nbIter << std::endl;
        //std::cout << "MAX = " << Utils::checkFeasibility(net, manager.getODMatrix()) << std::endl;//*/
        //net->print();

        //writeResults(params.getAutoFileName(' '), "test.res", nbIter, timer.getTimePassed());

        /*
        ShortestPath *shPath = manager.getShPath();
        for(int i =0;i < net->getNbNodes();i++){
            for(int j =0;j<net->getNbNodes();j++){
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
                    path.print();
                }

            }
        }
        */

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
