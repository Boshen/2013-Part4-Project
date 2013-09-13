#include <stdlib.h> #include <iostream>

#include "ObjectManager.h"
#include "UtilsString.h"
#include "Error.h"
#include "FWAlgo.h"
#include "RelGap.h"
#include "LabelCorrectingAl.h"
#include "Astar.h"
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
#include "OriginBasedAlgoTapas.h"
#include "OriginBasedAlgoEQII.h"
#include "AddHookScreenAndStore.h"
#include "AlgoDecorator.h"
#include "AlgoDecoratorWriteLinks.h"
#include "PathBasedFlowMovePE.h"

ObjectManager::ObjectManager(Params *params, Timer &timer) : timer_(timer), counters_(){
	_params = params;
	
	_isAdditive = -1;
	
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
	//_pAlgoCreator = NULL;
	_originSet = NULL;
	_addHook = NULL;
	_addHookStore = NULL;
	_pasManager = NULL;
	_descDirPath = NULL;
	_flowMove = NULL;
	_stepSize = NULL;
	_stepSizeAdd = NULL;
	_flowMoveWithStep = NULL;
	_flowMoveGP = NULL;
	counters_ = NULL;
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
	//delete _pAlgoCreator;
	
	delete _originSet;
	delete _addHook;
	delete _pasManager;
	delete _descDirPath;
	delete _flowMove;
	delete _stepSize;
	delete counters_;
	
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
	_addHook = NULL;
	_pasManager = NULL;
	_descDirPath = NULL;
	_flowMove = NULL;
	_stepSize = NULL;
	_stepSizeAdd = NULL;
	_flowMoveWithStep = NULL;
	_flowMoveGP = NULL;
	counters_ = NULL;
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
		std::string tmp = _params->getParamWoSpaces("INDIFF_CURVE");
		//Utils::removeWhiteSpaces(tmp);
		_isAdditive = tmp.empty();
	}
	return _isAdditive;
};

FPType ObjectManager::getFloatValue(std::string paramName){
	if (paramName == "") return 0.0;
	FPType value = 0.0;
	try {
		std::string tmp = _params->getParamWoSpaces(paramName);
		//std::cout << "TMP =  " << tmp << std::endl;
		if (tmp.empty()) throw Error("");
		value = atof(tmp.c_str());
	
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
		std::cout << "Creating network" << std::endl;
		std::string parserType = _params->getParamWoSpaces("PARSER");
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
		std::cout << "Network created " << std::endl;
	}
	return _net;
};

ODMatrix* ObjectManager::getODMatrix(){
	if (_odMatrix == NULL) {
		std::cout << "Creating OD matrix" << std::endl;
		std::string parserType = _params->getParamWoSpaces("PARSER");
		if (parserType == "DEFAULT") {
			_odMatrix = _parser.parseODMatrix(_params->getParam("OD_MATRIX"), getNet());
		} else if (parserType == "ART2") {
			std::string file = _params->getParam("OD_MATRIX"); //"Data/Instances/ART_Data/ART2/art2.demand";
			_odMatrix = _parser.parseARTODMatrix(file,  getNet());//*/
		} else {
			throw Error("Unexpected parser type.");
		}
		_odMatrix->setIndexes(_net);
		std::cout << "OD matrix created" << std::endl;
	}
	return _odMatrix;
};

ShortestPath* ObjectManager::getShPath(){
	if (_shPath == NULL) {
        if (getIfAdditive()) {
            std::cout << "Creating shortest path" << std::endl;
            //_shPath = new LabelCorrectingAl(getNet());
            std::string algo = _params->getParamWoSpaces("ShPathAlgo");
            if( algo == "LC"){
                _shPath = new LabelCorrectingAl(getNet(), *getCounterContainer());
            }
            if( algo == "Astar"){
                _shPath = new Astar(getNet(), getODMatrix());
            }
            std::cout << "Shortest path created" << std::endl;
        } else {
            // non-additive shortest path will be here
        }
    }
    return _shPath;
};

Derivative* ObjectManager::getDerivative(){
    if (_der == NULL){
        std::cout << "Creating derivative" << std::endl;
        _der = new Derivative(getFloatValue("ZERO_FLOW"), getLinkFncCont());
        std::cout << "Derivative created" << std::endl;
    }	
    return _der;
};

LineSearch* ObjectManager::getLineSearch(){
    if (_lineSearch == NULL) {
        // line search, possible values: BISEC, ARMIJO, QUAD_APP
        std::cout << "Creating line search" << std::endl;
        std::string tmp = _params->getParamWoSpaces("LINE_SEARCH");
        //Utils::removeWhiteSpaces(tmp);
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
        std::cout << "Line search created" << std::endl;

    }
    return _lineSearch;
};

ConvMeasure* ObjectManager::getConvMeasure(){
    if (_convMeasure == NULL) {
        std::cout << "Creating relative gap" << std::endl;
        _convMeasure = new RelGap(getFloatValue("PRECISION"), getNet(), getODMatrix(), getShPath());//; //new LabelCorrectingAl(getNet())
        std::cout << "RGAP created" << std::endl;
    }
    return _convMeasure;
};

PathAlgoType ObjectManager::getPathAlgoType(){
    if (_algoType == Nothing) {
        std::string tmp = _params->getParamWoSpaces("ALGORITHM");
        //Utils::removeWhiteSpaces(tmp);
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
        std::string tmp = _params->getParamWoSpaces("APPROACH");
        //Utils::removeWhiteSpaces(tmp);
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

/*PathAlgoCreator* ObjectManager::getPathAlgoCreator(){
  if (_pAlgoCreator == NULL) {
  std::cout << "Creating path algo creator" << std::endl;
  StarNetwork *net = getNet();
  _pAlgoCreator = new PathAlgoCreator(getPathAlgoType(), getPathAlgoApp(), net->getNbLinks(), getFloatValue("DIR_TOLERANCE"), getFloatValue("SLOPE"), getFloatValue("ISP_SCALE"));
  std::cout << "Path algo creator created" << std::endl;
  }

  return _pAlgoCreator;
  };*/

DescDirectionPath* ObjectManager::getDescDirectionPath(){
    if (_descDirPath == NULL) {
        std::cout << "Creating Desc direction" << std::endl;
        StarNetwork *net = getNet();
        PathAlgoCreator pAlgoCreator;
        _descDirPath = pAlgoCreator.allocateDescDirectionPath(getPathAlgoType(), getPathAlgoApp(), net->getNbLinks(), getFloatValue("DIR_TOLERANCE"), getFloatValue("SLOPE"), getFloatValue("ISP_SCALE"));
        std::cout << "descDirection created" << std::endl;
    }
    return _descDirPath;
};

PathSet* ObjectManager::getPathSet(){
    if (_pathSet == NULL) {
        std::cout << "Creating path set" << std::endl;
        PathApp app = getPathAlgoApp();

        if (app == APP3) {
            PathAlgoType algo = getPathAlgoType();
            if (algo == PE ) {
                _pathSet = new PathSet(getNet(), getODMatrix(), getShPath(), getPathCost(), getFloatValue("ZERO_FLOW"), getPathBasedFlowMove());
            } else if (algo == GP) {
                _pathSet = new PathSet(getNet(), getODMatrix(), getShPath(), getPathCost(), getFloatValue("ZERO_FLOW"), getPathBasedFlowMoveGP());
            } else {
                throw Error("Approach 3 is not implemented for this algorithm");
            }
        } else {
            //if (getSparsity()) {
            //	_pathSet = new PathSet(getNet(), getODMatrix(), getShPath(), getConvMeasure(), getPathCost(), getDerivative(), getLineSearch(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")), getPathAlgoCreator());
            //} else {
            _pathSet = new PathSet(getNet(), getODMatrix(), getShPath(), getPathCost(), getFloatValue("ZERO_FLOW"), getPathBasedFlowMoveWithStep());
            //}
        }
        std::cout << "Path set created" << std::endl;
    }
    return _pathSet;
};

DecoratedEqAlgo* ObjectManager::getEqAlgo(){
    if (_algo == NULL) {
        std::cout << "Creating algo" << std::endl;
        std::string tmp = _params->getParamWoSpaces("ALGORITHM");
        //Utils::removeWhiteSpaces(tmp);
        //std::cout << "Algo = " << tmp << std::endl;
        if ((tmp == "FW") || (tmp == "CFW") || (tmp == "BFW")) {
            if (_linkFlows == NULL) {
                /*if (getSparsity()) {
                  if (tmp == "CFW") {
                  _linkFlows = new LinkFlowsCFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")));
                  } else if (tmp == "BFW") {
                  _linkFlows = new LinkFlowsBFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")));
                  } else {
                  _linkFlows = new LinkFlows(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getDerivative(), getLineSearch(), getConvMeasure(), getFloatValue(_params->getParam("SPARSITY_TOLERANCE")));
                  }
                  } else {*/
                if (tmp == "CFW") {
                    _linkFlows = new LinkFlowsCFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getStepSize(), getConvMeasure());
                } else if (tmp == "BFW") {
                    _linkFlows = new LinkFlowsBFW(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getStepSize(), getConvMeasure());
                } else {
                    _linkFlows = new LinkFlows(getNet(), getODMatrix(), getLinkFncCont(), getShPath(), getStepSize(), getConvMeasure());
                }
                //}
            }
            _algo = new FWAlgo(_linkFlows, getAddHook()); //, getNet());
        } else if (getPathAlgoType() != Nothing){
            std::string tmp = _params->getParamWoSpaces("EQUILIBRATION");
            //Utils::removeWhiteSpaces(tmp);
            std::cout << "EQ = " << tmp << std::endl;
            if (tmp == "EQI") {
                _algo = new PathBasedAlgo(getPathSet(), true, getAddHook(), getConvMeasure()); //, getNet(), getODMatrix());
            } else if (tmp == "EQII") {
                //_eqII = new EquilibrationII();
                _algo = new PathBasedAlgo(getPathSet(), false, getAddHook(), getConvMeasure()); //, getNet(), getODMatrix());
            } else {
                throw Error("Unexpected value of parameter <EQUILIBRATION>");
            }
        } else if (tmp == "B") {
            std::string tmp = _params->getParamWoSpaces("EQUILIBRATION");
            //Utils::removeWhiteSpaces(tmp);
            std::cout << "EQ = " << tmp << std::endl;
            if (tmp == "EQI") {
                _algo = new OriginBasedAlgo(getOriginSet(), getODMatrix(), getNet(), getAddHook());
            } else if (tmp == "EQII") {
                _algo = new OriginBasedAlgoEQII(getOriginSet(), getODMatrix(), getNet(), getAddHook());
            } else {
                throw Error("Unexpected value of parameter <EQUILIBRATION>");
            }
        } else if (tmp == "LUCE") {
            _algo = new OriginBasedAlgo(getOriginSet(), getODMatrix(), getNet(), getAddHook());
        } else if (tmp == "TAPAS") {
            _algo = new OriginBasedAlgoTapas(getOriginSet(), getODMatrix(), getNet(), getPASManager(), getAddHook());
        } else {
            throw Error("Unexpected value of parameter <ALGORITHM>");
        }

        std::cout << "Adding decorations" << std::endl;
        // add decoration if necessary
        tmp = _params->getParamWoSpaces("CONVERGENCE");
        //Utils::removeWhiteSpaces(tmp);
        if (tmp != "") {
            // add write convergence to file
            getAddHook();
            assert(_addHookStore != NULL);
            if (tmp == "AUTO") {
                tmp = _params->getAutoFileName() + ".conv";
            }
            _algo = new AlgoDecorator(_algo, _addHookStore, tmp, timer_);
        }
        tmp = _params->getParamWoSpaces("LINK_FLOWS");
        //Utils::removeWhiteSpaces(tmp);
        if (tmp != "") {
            if (tmp == "AUTO") {
                tmp = _params->getAutoFileName() + ".flows";
            }
            _algo = new AlgoDecoratorWriteLinks(_algo, getNet(), tmp, timer_);
        }
        std::cout << "Algo created" << std::endl;
    }
    return _algo;
};

LinkFncContainer* ObjectManager::getLinkFncCont(){
    if (_linkFnc == NULL) {
        std::cout << "Creating linkFncContainer" << std::endl;
        _linkFnc = new LinkFncContainer(getNet());
        std::cout << "linkFncContainer created" << std::endl;
    }
    return _linkFnc;
};

OriginSet* ObjectManager::getOriginSet(){
    if (_originSet == NULL) {
        std::cout << "Creating origin set" << std::endl;
        std::string tmp = _params->getParamWoSpaces("ALGORITHM");
        //Utils::removeWhiteSpaces(tmp);
        std::string steps = _params->getParamWoSpaces("NEWTON_STEPS");
        //Utils::removeWhiteSpaces(steps);
        bool useMulti = true;
        if (steps == "SINGLE") {
            useMulti = false;
        } else if (steps == "MULTI") {
            useMulti = true;
        } else {
            throw Error("Unexpected value of parameter <NEWTON_STEPS>");
        } 
        if (tmp == "B") {
            _originSet = new OriginSet(getODMatrix(), getNet(), getShPath(), getConvMeasure(), getFloatValue("ZERO_FLOW"), getFloatValue("DIR_TOLERANCE"), false, useMulti);
        } else if (tmp == "LUCE") {
            _originSet = new OriginSet(getODMatrix(), getNet(), getShPath(), getConvMeasure(), getFloatValue("ZERO_FLOW"), getFloatValue("DIR_TOLERANCE"), true, useMulti);
        } else if (tmp == "TAPAS") {
            _originSet = new OriginSet(getODMatrix(), getNet(), getShPath(), getConvMeasure(), getFloatValue("ZERO_FLOW"), getFloatValue("DIR_TOLERANCE"), getPASManager());
        } else {
            throw Error("Unexpected algorithm value");
        }
        std::cout << "origin set created" << std::endl;
    }
    return _originSet;
};

AddHook* ObjectManager::getAddHook(){
    if (_addHook == NULL) {
        std::cout << "Creating AddHook" << std::endl;
        std::string onScreen = _params->getParamWoSpaces("SHOW_CONVERGENCE");
        //Utils::removeWhiteSpaces(onScreen);
        std::string toFile = _params->getParamWoSpaces("CONVERGENCE");
        //Utils::removeWhiteSpaces(toFile);
        if (onScreen != "") {
            if (toFile != "") {
                _addHookStore = new AddHookScreenAndStore();
                _addHook = _addHookStore;
            } else {
                _addHook = new AddHookScreenOut();
            }
        } else if (toFile != "") {
            _addHookStore = new AddHookStoreOut();
            _addHook = _addHookStore;
        } else {
            _addHook = new AddHook();
        }
        std::cout << "AddHook created" << std::endl;	
    }
    return _addHook;
};


PASManager* ObjectManager::getPASManager(){
    if (_pasManager == NULL) {
        std::cout << "Creating PASManager" << std::endl;
        _pasManager = new PASManager(*getShPath(), getFloatValue("DIR_TOLERANCE"), getNet()->getNbLinks(), getFloatValue("MU"), getFloatValue("V"));
        std::cout << "PASManager created" << std::endl;
    }
    return _pasManager;
};

PathBasedFlowMove* ObjectManager::getPathBasedFlowMove(){
    if (_flowMove == NULL) {
        std::cout << "Creating PathBasedFlowMove" << std::endl;
        PathAlgoType algo = getPathAlgoType();
        assert(algo != Nothing);
        PathApp app = getPathAlgoApp();
        if (app == APP3) {
            if (algo == PE) {
                _flowMove = new PathBasedFlowMovePE(getDescDirectionPath());
            } else if (algo == GP) {
                _flowMoveGP = new PathBasedFlowMoveGP(getFloatValue("ALPHA"), getDescDirectionPath()); 
                _flowMove = _flowMoveGP;
            } else {
                throw Error("Approach 3 is not implemented for this algorithm");
            }
        } else {
            _flowMoveWithStep = new PathBasedFlowMoveWithStep(getStepSizeAdd(), getDescDirectionPath(), getFloatValue("ZERO_FLOW"));
            _flowMove = _flowMoveWithStep;
        }
        std::cout << "PathBasedFlowMove created" << std::endl;
    }	
    return _flowMove;
};

StepSize* ObjectManager::getStepSize(){
    if (_stepSize == NULL) {
        std::cout << "Creating StepSize" << std::endl;
        _stepSizeAdd = new StepSizeAdd(getLineSearch(), getDerivative()); // so far only additive step size 
        _stepSize = _stepSizeAdd;
        std::cout << "StepSize created" << std::endl;
    } 
    return _stepSize;
};

StepSizeAdd* ObjectManager::getStepSizeAdd(){
    if (_stepSizeAdd == NULL) {
        std::cout << "Creating StepSizeAdd" << std::endl;
        _stepSizeAdd = new StepSizeAdd(getLineSearch(), getDerivative()); // so far only additive step size 
        _stepSize = _stepSizeAdd;
        std::cout << "StepSizeAdd created" << std::endl;
    } 
    return _stepSizeAdd;
};

PathBasedFlowMoveWithStep* ObjectManager::getPathBasedFlowMoveWithStep(){
    if (_flowMoveWithStep == NULL) {
        std::cout << "Creating PathBasedFlowMoveWithStep" << std::endl;
        _flowMoveWithStep = new PathBasedFlowMoveWithStep(getStepSizeAdd(), getDescDirectionPath(), getFloatValue("ZERO_FLOW"));
        _flowMove = _flowMoveWithStep;
        std::cout << "PathBasedFlowMoveWithStep created" << std::endl;
    }
    return _flowMoveWithStep;
};

PathBasedFlowMoveGP* ObjectManager::getPathBasedFlowMoveGP(){
    if (_flowMoveGP == NULL) {
        std::cout << "Creating PathBasedFlowMoveGP" << std::endl;
        _flowMoveGP = new PathBasedFlowMoveGP(getFloatValue("ALPHA"), getDescDirectionPath()); 
        _flowMove = _flowMoveGP;
        std::cout << "PathBasedFlowMoveGP created" << std::endl;
    }
    return _flowMoveGP;
};

void ObjectManager::printCounters() const{
    counters_->printCounters();
};

CounterContainer* ObjectManager::getCounterContainer(){
    if (counters_ == NULL) {
        counters_ = new CounterContainer();
    }
    return counters_;
};
