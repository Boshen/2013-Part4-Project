#include <stdlib.h>
#include <iostream>

#include "ObjectManager.h"
#include "UtilsString.h"
#include "Error.h"
#include "FWAlgo.h"
#include "RelGap.h"
#include "LabelCorrectingAl.h"
#include "Bisection.h"
#include "Armijo.h"
#include "QuadApp.h"
#include "PathBasedAlgo.h"
#include "EquilibrationII.h"
#include "AdditivePC.h"
#include "NonAdditivePC.h"
#include "LinkFlowsCFW.h"
#include "LinkFlowsBFW.h"
#include "OriginBasedAlgo.h"

#include "ShPathFactory.h"

ObjectManager::ObjectManager(Params *params){
    _params = params;

    _isAdditive = -1;
    _useSparsity = -1;

    //initialise all pointers
    _net = NULL;
    _odMatrix = NULL;
    _algo = NULL;
    _linkFnc = NULL;
    _linkFlows = NULL;
    _lineSearch = NULL;
    _convMeasure = NULL;
    _shPath = NULL;
    _der = NULL;
    _pathSet = NULL;
    _pathCost = NULL;
    _algoType = Nothing;
    _algoApp = AppNothing;
    _pAlgoCreator = NULL;
    _originSet = NULL;
};

ObjectManager::~ObjectManager(){

    // deallocate all objects

    delete _net;
    delete _odMatrix;
    delete _algo;
    delete _linkFnc;
    delete _linkFlows;
    delete _lineSearch;
    delete _convMeasure;
    delete _shPath;
    delete _der;
    delete _pathSet;
    delete _pathCost;
    delete _pAlgoCreator;
    delete _originSet;

    // set to NULL - so it is safe to delete it twice and error will occur if someone dereferences NULL pointer
    _net = NULL;
    _odMatrix = NULL;
    _algo = NULL;
    _linkFnc = NULL;
    _linkFlows = NULL;
    _lineSearch = NULL;
    _convMeasure = NULL;
    _shPath = NULL;
    _der = NULL;
    _pathSet = NULL;
    _pathCost = NULL;
    _pAlgoCreator = NULL;
    _originSet = NULL;

    //std::cout << "all data freed" << std::endl;
};

PathCost* ObjectManager::getPathCost(){
    if (_pathCost == NULL){
        if (getIfAdditive()) {
            _pathCost = new AdditivePC();
        } else {
            _pathCost = new NonAdditivePC();
        }
    }
    return _pathCost; 
};

bool ObjectManager::getIfAdditive(){
    if (_isAdditive == -1) {
        std::string tmp = _params->getParam("INDIFF_CURVE");
        Utils::removeWhiteSpaces(tmp);
        _isAdditive = tmp.empty();
    }
    return _isAdditive;
};

FPType ObjectManager::getFloatValue(std::string paramName){
    if (paramName == "") return 0.0;
    FPType value = 0.0;
    try {
        value = atof(_params->getParam(paramName).c_str());
    } catch (...) {
        std::string message = "Unexpected value of parameter <";
        message.append(paramName);
        message.append(">"); 
        throw Error(message);
    }
    return value;
};

StarNetwork* ObjectManager::getNet(){
    if (_net == NULL) {
        std::string parserType = _params->getParam("PARSER");
        if (parserType == "DEFAULT") {
            _net = _parser.parseNetwork(_params->getParam("NETWORK"), getIfAdditive());
        } else if (parserType == "ART2") {
            std::string fileNodes = _params->getParam("NODES_ART2"); //"Data/Instances/ART_Data/ART2/art2.nodes";
            std::string fileLinks = _params->getParam("NETWORK"); //"Data/Instances/ART_Data/ART2/art2.links";
            std::string fileFnc = _params->getParam("FNC_ART2"); //"Data/Instances/ART_Data/ART2/art2.fnc";
            _net = _parser.parseARTNetwork(fileNodes, fileLinks, fileFnc, getIfAdditive());//*/
        } else {
            throw Error("Unexpected parser type.");
        }
        _net->linkNodes();
    }
    return _net;
};

ODMatrix* ObjectManager::getODMatrix(){
    if (_odMatrix == NULL) {
        getNet();
        std::string parserType = _params->getParam("PARSER");
        if (parserType == "DEFAULT") {
            _odMatrix = _parser.parseODMatrix(_params->getParam("OD_MATRIX"), _net->getNbNodes());
        } else if (parserType == "ART2") {
            std::string file = _params->getParam("OD_MATRIX"); //"Data/Instances/ART_Data/ART2/art2.demand";
            _odMatrix = _parser.parseARTODMatrix(file,  _net->getNbNodes());//*/
        } else {
            throw Error("Unexpected parser type.");
        }
        _odMatrix->setIndexes(_net);
    }
    return _odMatrix;
};

ShortestPath* ObjectManager::getShPath(){
    if (_shPath == NULL) {
        if (getIfAdditive()) {
            std::string algo = _params->getParam("ShPathAlgo");
            std::string datastruct = _params->getParam("ShPathDataStruct");
            if( algo == "LabelCorrectingAl"){
                _shPath = new LabelCorrectingAl(getNet());
            }else{
                _shPath = ShPathFactory::get()->getShPath(algo, datastruct, getNet());
            }
        } else {
            // non-additive shortest path will be here
        }
    }
    return _shPath;
};

Derivative* ObjectManager::getDerivative(){
    if (_der == NULL){
        _der = new Derivative(getFloatValue("ZERO_FLOW"), getLinkFncCont());
    }	
    return _der;
};

LineSearch* ObjectManager::getLineSearch(){
    if (_lineSearch == NULL) {
        // line search, possible values: BISEC, ARMIJO, QUAD_APP
        std::string tmp = _params->getParam("LINE_SEARCH");
        Utils::removeWhiteSpaces(tmp);
        if (tmp == "BISEC") {
            FPType pr = getFloatValue("LS_PRECISION");
            if (pr <= 0.0) throw Error("Line search precision must be positive");
            _lineSearch = new Bisection(pr, getDerivative());
        } else if (tmp == "ARMIJO") {
            FPType dec = getFloatValue("ARMIJO_DEC");
            if (dec <= 0.0) throw Error("Decriment for Armijo search must be positive");
            _lineSearch = new Armijo(dec, getDerivative());
        } else if (tmp == "QUAD_APP") {
            _lineSearch = new QuadApp(getDerivative());
        } else {
            throw Error("Unexpected value of parameter <LINE_SEARCH>");
        }

    }
    return _lineSearch;
};

ConvMeasure* ObjectManager::getConvMeasure(){
    if (_convMeasure == NULL) {
        _convMeasure = new RelGap(getFloatValue("PRECISION"), getNet(), getODMatrix(), getShPath());
    }
    return _convMeasure;
};

bool ObjectManager::getSparsity(){
    if (_useSparsity == -1) {
        std::string tmp = _params->getParam("SPARSITY");
        Utils::removeWhiteSpaces(tmp);
        if (tmp == "1") {
            _useSparsity = 1;
        } else if (tmp == "0") {
            _useSparsity = 0;
        } else {
            throw Error("Unexpected value of parameter <SPARSITY>");
        }
    }
    return _useSparsity;
};

PathAlgoType ObjectManager::getPathAlgoType(){
    if (_algoType == Nothing) {
        std::string tmp = _params->getParam("ALGORITHM");
        Utils::removeWhiteSpaces(tmp);
        //std::cout << "Algo = " << tmp << std::endl;
        if (tmp == "PE") {
            _algoType = PE;
        } else if (tmp == "GP") {
            _algoType = GP;
        } else if (tmp == "PG") {
            _algoType = PG;
        } else if (tmp == "ISP"){
            _algoType = ISP;
        }// else {
        //	throw Error("Unexpected path-based algorithm type");
        //}
    }
    return _algoType;
};

PathApp ObjectManager::getPathAlgoApp(){
    if (_algoApp == AppNothing) {
        std::string tmp = _params->getParam("APPROACH");
        Utils::removeWhiteSpaces(tmp);
        //std::cout << "Algo = " << tmp << std::endl;
        if (tmp == "APP1") {
            _algoApp = APP1;
        } else if (tmp == "APP2") {
            _algoApp = APP2;
        } else if (tmp == "APP3") {
            _algoApp = APP3;
        } else if (tmp == "") {
            _algoApp = APP1; // default value if not defined
        } else {
            throw Error("Unexpected approach type");
        }
    }
    return _algoApp;
};

PathAlgoCreator* ObjectManager::getPathAlgoCreator(){
    if (_pAlgoCreator == NULL) {
        StarNetwork *net = getNet();
        _pAlgoCreator = new PathAlgoCreator(getPathAlgoType(), getPathAlgoApp(), net->getNbLinks(), getFloatValue("DIR_TOLERANCE"), getFloatValue("SLOPE"), getFloatValue("ISP_SCALE"));
    }
    return _pAlgoCreator;
};

PathSet* ObjectManager::getPathSet(){
    if (_pathSet == NULL) {
        PathApp app = getPathAlgoApp();
        if (app == APP3) {
            PathAlgoType algo = getPathAlgoType();
            if (algo == PE) {
                _pathSet = new PathSet(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getConvMeasure(), getPathCost(), getFloatValue("ZERO_FLOW"), getPathAlgoCreator());
            } else if (algo == GP) {
                _pathSet = new PathSet(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getConvMeasure(), getPathCost(), getFloatValue("ZERO_FLOW"), getFloatValue("ALPHA"), getPathAlgoCreator());
            } else {
                throw Error("Approach 3 is not implemented for this algorithm");
            }
        } else {
            if (getSparsity()) {
                _pathSet = new PathSet(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getConvMeasure(), getPathCost(), getDerivative(), getLineSearch(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")), getPathAlgoCreator());
            } else {
                _pathSet = new PathSet(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getConvMeasure(), getPathCost(), getDerivative(), getLineSearch(), getPathAlgoCreator());
            }
        }
    }
    return _pathSet;
};

DecoratedEqAlgo* ObjectManager::getEqAlgo(){
    if (_algo == NULL) {
        std::string tmp = _params->getParam("ALGORITHM");
        Utils::removeWhiteSpaces(tmp);
        //std::cout << "Algo = " << tmp << std::endl;
        if ((tmp == "FW") || (tmp == "CFW") || (tmp == "BFW")) {
            if (_linkFlows == NULL) {
                if (getSparsity()) {
                    if (tmp == "CFW") {
                        _linkFlows = new LinkFlowsCFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")));
                    } else if (tmp == "BFW") {
                        _linkFlows = new LinkFlowsBFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")));
                    } else {
                        _linkFlows = new LinkFlows(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")));
                    }
                } else {
                    if (tmp == "CFW") {
                        _linkFlows = new LinkFlowsCFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure());
                    } else if (tmp == "BFW") {
                        _linkFlows = new LinkFlowsBFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure());
                    } else {
                        _linkFlows = new LinkFlows(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure());
                    }
                }
            }
            _algo = new FWAlgo(_linkFlows);
        } else if (getPathAlgoType() != Nothing){
            std::string tmp = _params->getParam("EQUILIBRATION");
            Utils::removeWhiteSpaces(tmp);
            //std::cout << "EQ = " << tmp << std::endl;
            if (tmp == "EQI") {
                _algo = new PathBasedAlgo(getPathSet(), true);
            } else if (tmp == "EQII") {
                //_eqII = new EquilibrationII();
                _algo = new PathBasedAlgo(getPathSet(), false);
            } else {
                throw Error("Unexpected value of parameter <EQUILIBRATION>");
            }
        } else if (tmp == "B" || tmp == "LUCE") {
            _algo = new OriginBasedAlgo(getOriginSet());
        } else {
            throw Error("Unexpected value of parameter <ALGORITHM>");
        }
    }
    return _algo;
};

LinkFncContainer* ObjectManager::getLinkFncCont(){
    if (_linkFnc == NULL) {
        _linkFnc = new LinkFncContainer(getNet());
    }
    return _linkFnc;
};

OriginSet* ObjectManager::getOriginSet(){
    if (_originSet == NULL) {
        std::string tmp = _params->getParam("ALGORITHM");
        Utils::removeWhiteSpaces(tmp);
        if (tmp == "B") {
            _originSet = new OriginSet(getODMatrix(), getNet(), getShPath(), getConvMeasure(), getFloatValue("ZERO_FLOW"), getFloatValue("DIR_TOLERANCE"), false);
        } else {
            _originSet = new OriginSet(getODMatrix(), getNet(), getShPath(), getConvMeasure(), getFloatValue("ZERO_FLOW"), getFloatValue("DIR_TOLERANCE"), true);
        }
    }
    return _originSet;
};
