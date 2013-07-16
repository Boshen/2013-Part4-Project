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

#include "ShPath/ShPathInterface.h"
#include "LabelCorrectingAl.h"
//void writeResults(const std::string &name, const std::string &fileName, int nbIter, double timePassed){
//    FileWriter flWrite(fileName, true);
//    std::ostringstream s;
//    s << name << " " << nbIter << " " << timePassed << "\n";
//    std::string line = s.str();
//    flWrite.writeLine(line);
//    //fprintf(pFile, "%s %s %d %4.5f \n", (net->getNetName()).c_str(), (params.getAlgoParams()).c_str(), nbIter, timePassed);
//};


inline double distance(long x1, long y1, long x2, long y2){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

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

        //StarNetwork *net = manager.getNet();
        /*
           net->print();
           ODMatrix *mat = manager.getODMatrix();
           mat->print();//*/
        DecoratedEqAlgo *algo = manager.getEqAlgo();


        int nbIter = algo->execute();
        //end = clock();
        timer.stop(); //will stop only if it was not stopped before

        //net->printToFile("tmp.flows");
        //double timePassed = ((double)(end-start))/ (CLOCKS_PER_SEC);
        StarNetwork *net = manager.getNet();
        std::cout << std::fixed << timer.getTimePassed() << " | "  <<  nbIter << std::endl;
        //std::cout << "MAX = " << Utils::checkFeasibility(net, manager.getODMatrix()) << std::endl;//*/
        //net->print();

        //writeResults(params.getAutoFileName(' '), "test.res", nbIter, timer.getTimePassed());

        ShortestPath *shPath = manager.getShPath();
        LabelCorrectingAl* tmp = (LabelCorrectingAl*)shPath;
        shPath->calculate(384, 368);
        tmp->printScanned();
        std::cout << "path" << std::endl;
        StarLink *link = shPath->getInComeLink(368);
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

        /*
           std::vector<std::pair<long, long> > nodeCoords(net->getNbNodes());

           std::ifstream infile("Data/Instances/ChicagoSketch_node.txt");

           std::string line;
           infile >> line >> line >> line >> line;

           long tmp, x, y;
           char tmp2;
           for(int i = 0; i < net->getNbNodes(); i++){
           infile >> tmp >> x >> y >> tmp2;
           nodeCoords[i] = std::make_pair(x, y);
           }

           infile.close();

           ShortestPath *shPath = manager.getShPath();
           for(int i =0;i < net->getNbNodes();i++){
           for(int j =0;j<net->getNbNodes();j++){
           if (i!=j){
           timer.stop();
           timer.start();
           shPath->calculate(i, j);
           timer.stop();
           std::cout << distance(nodeCoords[i].first, nodeCoords[i].second, nodeCoords[j].first, nodeCoords[j].second) << " " << timer.getTimePassed() << std::endl;

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
