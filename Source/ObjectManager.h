#ifndef _OBJECT_MANAGER_
#define _OBJECT_MANAGER_

#include "Params.h"
#include "StarNetwork.h"
#include "ODMatrix.h"
#include "DecoratedEqAlgo.h"
#include "Parser.h"
#include "LinkFncContainer.h"
#include "LinkFlows.h"
#include "LineSearch.h"
#include "ConvMeasure.h"
#include "ShortestPath.h"
#include "Derivative.h"
#include "PathSet.h"
#include "PathCost.h"
#include "Constants.h"
#include "PathAlgoCreator.h"
#include "OriginSet.h"
#include "AddHook.h"
#include "AddHookStoreOut.h"
#include "Timer.h"
#include "PASManager.h"
#include "StepSizeAdd.h"
#include "PathBasedFlowMoveGP.h"
#include "OperationCounter.h"

class ObjectManager {
	public:
		ObjectManager(Params *params, Timer &timer);
		~ObjectManager();
		
		// getters for all objects
		StarNetwork* getNet();
		ODMatrix* getODMatrix();
		DecoratedEqAlgo* getEqAlgo();
		LinkFncContainer* getLinkFncCont();
		LineSearch* getLineSearch();
		ConvMeasure* getConvMeasure();
		ShortestPath* getShPath();
		Derivative* getDerivative();
		PathSet* getPathSet();
		PathCost* getPathCost();
		OriginSet* getOriginSet();
		PASManager* getPASManager();
		
		CounterContainer* getCounterContainer();
		
		void printCounters() const;
		
		// for now
		bool getIfAdditive();
		PathAlgoType getPathAlgoType();
		PathApp getPathAlgoApp();
				
	private:
		Params *_params;
		Parser _parser;
		
		int _isAdditive;
		PathAlgoType _algoType;
		PathApp _algoApp;
		
		//pointers to all objects
		StarNetwork *_net;
		ODMatrix *_odMatrix;
		DecoratedEqAlgo *_algo;
		LinkFncContainer *_linkFnc;
		LinkFlows *_linkFlows;
		LineSearch *_lineSearch;
		ConvMeasure *_convMeasure;
		ShortestPath *_shPath;
		Derivative *_der;
		PathSet *_pathSet;
		PathCost *_pathCost;
		//EquilibrationII *_eqII;
		PathAlgoCreator *_pAlgoCreator;
		OriginSet *_originSet;
		AddHook *_addHook;
		AddHookStoreOut *_addHookStore; // just a copy of _addHook, but explicit time is specified
		PASManager* _pasManager;
		DescDirectionPath* _descDirPath;
		PathBasedFlowMove* _flowMove;
		StepSize* _stepSize;
		StepSizeAdd* _stepSizeAdd;
		PathBasedFlowMoveWithStep* _flowMoveWithStep;
		PathBasedFlowMoveGP* _flowMoveGP;
		
		Timer &timer_;
		CounterContainer *counters_;
		
		FPType getFloatValue(std::string paramName);
		//PathAlgoCreator* getPathAlgoCreator();
		DescDirectionPath* getDescDirectionPath();
		AddHook* getAddHook();
		PathBasedFlowMove* getPathBasedFlowMove();
		PathBasedFlowMoveWithStep* getPathBasedFlowMoveWithStep();
		PathBasedFlowMoveGP* getPathBasedFlowMoveGP();
		StepSize* getStepSize();
		StepSizeAdd* getStepSizeAdd();
};

#endif
