CC = g++
#-DDOUBLE_COST_1 -pedantic -W -Wall 
#-O3 #for optimization
CFLAGS = -Wall -O3 #-O3 #-pg # for profile
LDFLAGS = -Wall -Wextra -O3 # -O3 # -pg

BOOST_DIR = /usr/include/boost_1_53_0 # /usr/local/include/boost
SHPATH_DIR = Source/ShPath/

DIR = Source

.PHONY: clean ShPath

PROG = ta

HEADERS = Error.h DecoratedEqAlgo.h EqAlgo.h AlgoDecorator.h ParseParams.h Params.h ObjectManager.h StarNetwork.h ODMatrix.h StarNode.h StarLink.h \
		LinkCost.h BiObjLinkCost.h Parser.h Utils.h Origin.h PairOD.h LinkFncContainer.h LinkFnc.h LinearFnc.h BprFnc.h MarginalFnc.h FWAlgo.h \
		LinkFlows.h LineSearch.h ConvMeasure.h RelGap.h ShortestPath.h AONAssignment.h NodeInfo.h LabelCorrectingAl.h Derivative.h Armijo.h \
		Bisection.h QuadApp.h PathBasedAlgo.h EquilibrationType.h EquilibrationII.h PathSet.h ODSet.h Path.h PathCost.h AdditivePC.h NonAdditivePC.h \
		InitialiseSolution.h StepSize.h StepSizeAdd.h StepSizeNonAdd.h DescDirection.h PathBasedFlowMove.h \
		PathAndDirection.h DescDirectionPath.h DescDirectionPathPE.h PathBasedFlowMoveWithStep.h DescDirectionPathGP.h DescDirectionPathPG.h \
		Constants.h DescDirectionPathScaled.h PathDerivative.h PathAlgoCreator.h PathBasedFlowMovePE.h PathBasedFlowMoveGP.h OnePathDerivative.h \
		DescDirectionPathISP.h LinkFlowsCFW.h LinkFlowsBFW.h OriginBasedAlgo.h OriginSet.h OriginBush.h DAGraph.h EquilibrationI.h DAGraphNode.h \
		DAGraphNode.h SpiessFnc.h SpiessFncCreator.h FileReader.h ConstFnc.h SpiessFncComb.h FileWriter.h \
		UtilsString.h DAGraphLUCE.h DAGraphB.h OriginBushLUCE.h PlusLinearFnc.h PAS.h PASManager.h DAGraphTapas.h OriginBasedAlgoTapas.h OriginBushTapas.h \
		OriginBushB.h  OriginBasedAlgoEQII.h ODSetWithStep.h AddHookScreenOut.h AddHook.h AddHookStoreOut.h AddHookScreenAndStore.h AlgoDecoratorWriteLinks.h \
		Timer.h

SOURCES = Error.cpp main.cpp AlgoDecorator.cpp ParseParams.cpp Params.cpp ObjectManager.cpp StarNetwork.cpp ODMatrix.cpp StarNode.cpp StarLink.cpp \
		Parser.cpp Utils.cpp Origin.cpp PairOD.cpp LinkFncContainer.cpp LinearFnc.cpp BprFnc.cpp MarginalFnc.cpp FWAlgo.cpp LinkFlows.cpp \
		RelGap.cpp  AONAssignment.cpp LabelCorrectingAl.cpp Derivative.cpp Armijo.cpp Bisection.cpp QuadApp.cpp PathBasedAlgo.cpp EquilibrationII.cpp \
		PathSet.cpp ODSet.cpp Path.cpp AdditivePC.cpp NonAdditivePC.cpp StepSize.cpp StepSizeAdd.cpp StepSizeNonAdd.cpp \
		PathBasedFlowMove.cpp PathAndDirection.cpp DescDirectionPathPE.cpp PathBasedFlowMoveWithStep.cpp DescDirectionPathGP.cpp \
		DescDirectionPathPG.cpp DescDirectionPathScaled.cpp PathDerivative.cpp PathAlgoCreator.cpp PathBasedFlowMovePE.cpp PathBasedFlowMoveGP.cpp\
		OnePathDerivative.cpp DescDirectionPathISP.cpp LinkFlowsCFW.cpp LinkFlowsBFW.cpp OriginBasedAlgo.cpp OriginSet.cpp OriginBush.cpp DAGraph.cpp \
		EquilibrationI.cpp DAGraphNode.cpp SpiessFnc.cpp SpiessFncCreator.cpp FileReader.cpp ConstFnc.cpp SpiessFncComb.cpp \
		FileWriter.cpp UtilsString.cpp DAGraphLUCE.cpp OriginBushLUCE.cpp PlusLinearFnc.cpp PAS.cpp PASManager.cpp DAGraphTapas.cpp OriginBasedAlgoTapas.cpp \
		OriginBushTapas.cpp DAGraphB.cpp OriginBushB.cpp OriginBasedAlgoEQII.cpp ODSetWithStep.cpp AlgoDecoratorWriteLinks.cpp \
		Timer.cpp

OBJECTS = $(SOURCES:.cpp=.o)

OBJS = $(patsubst %,$(DIR)/%,$(OBJECTS))
SRCS = $(patsubst %,$(DIR)/%,$(SOURCES))
HDRS = $(patsubst %,$(DIR)/%,$(HEADERS))

ShPathObjects = $(DIR)/ShPath/ShPathFactory.o
EXTRA_FLAGS =
$(DIR)/Utils.o: EXTRA_FLAGS=-I $(BOOST_DIR)
$(DIR)/ObjectManager.o: EXTRA_FLAGS=-I $(BOOST_DIR) -I Source/ShPath/

all: ShPath $(PROG) 

$(PROG) : $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^ $(ShPathObjects)

$(DIR)/%.o : $(DIR)/%.cpp $(DIR)/%.h
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -c -o $@ $<

$(DIR)/main.o : $(DIR)/main.cpp
		$(CC) $(CFLAGS) $(EXTRA_FLAGS) -c -o $@ $<

ShPath:
	$(MAKE) -C $(SHPATH_DIR)

clean : 
	rm -f core $(PROG) $(OBJS)
	$(MAKE) clean -C $(SHPATH_DIR)

TAGS : $(SRCS) $(HDRS)
	etags -t $(SRCS) $(HDRS)  
