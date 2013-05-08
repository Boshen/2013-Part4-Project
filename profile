Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 47.57     12.54    12.54 32302428     0.00     0.00  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int)
 21.06     18.09     5.55 145897067     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*)
  7.66     20.11     2.02 32302428     0.00     0.00  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int)
  6.07     21.71     1.60   205972     0.01     0.01  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int)
  5.73     23.22     1.51 77688544     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&)
  1.54     23.63     0.41 82712365     0.00     0.00  StarLink::getNodeFromIndex() const
  1.18     23.94     0.31                             boost::heap::fibonacci_heap<ValueKey, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::consolidate()
  1.18     24.25     0.31 87438819     0.00     0.00  StarNetwork::getNextLink()
  1.12     24.54     0.30 67682791     0.00     0.00  StarNetwork::beginNode(int)
  0.82     24.76     0.22 98803196     0.00     0.00  StarLink::getNodeToIndex() const
  0.74     24.95     0.20 176574565     0.00     0.00  StarLink::getTime() const
  0.72     25.14     0.19  3077935     0.00     0.00  void std::__adjust_heap<__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize>(__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize)
  0.68     25.32     0.18 67642742     0.00     0.00  StarNode::getIsZone()
  0.68     25.50     0.18   821627     0.00     0.00  void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&)
  0.64     25.67     0.17     3080     0.06     0.14  ShPathDijkstraSTL::calculate(int, int)
  0.34     25.76     0.09 98004999     0.00     0.00  StarLink::getIndex() const
  0.32     25.85     0.09 15260894     0.00     0.00  StarNetwork::getLink(int)
  0.27     25.92     0.07 10670635     0.00     0.00  Path::getNextLink() const
  0.27     25.99     0.07  4516627     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&)
  0.23     26.05     0.06   205972     0.00     0.12  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int)
  0.23     26.11     0.06 31981907     0.00     0.00  StarNetwork::beginLink()
  0.15     26.15     0.04   205972     0.00     0.00  ODSet::updateSet()
  0.11     26.18     0.03   437009     0.00     0.00  Path::beginLink() const
  0.08     26.20     0.02  1194337     0.00     0.00  StarNode::getID()
  0.08     26.22     0.02    15389     0.00     0.00  ODSet::calculateProjectedDirection()
  0.06     26.23     0.02  1058472     0.00     0.00  StarLink::addFlow(double)
  0.04     26.24     0.01  1307691     0.00     0.00  StarLink::setFlow(double)
  0.04     26.25     0.01  1195932     0.00     0.00  StarLink::getNodeTo() const
  0.04     26.26     0.01   896285     0.00     0.00  BprFnc::evaluate(double)
  0.04     26.27     0.01   340569     0.00     0.00  BprFnc::evaluateDerivative(double)
  0.04     26.28     0.01   253504     0.00     0.00  PairOD::getIndex() const
  0.04     26.29     0.01   245582     0.00     0.00  Origin::getNextDest()
  0.04     26.30     0.01    23311     0.00     0.00  ODSet::projectPathFlowOnLinks()
  0.04     26.31     0.01    23274     0.00     0.00  PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&)
  0.04     26.32     0.01    15389     0.00     0.00  PathBasedFlowMovePE::executeFlowMove()
  0.04     26.33     0.01    15389     0.00     0.00  Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int)
  0.04     26.34     0.01                             BprFnc::~BprFnc()
  0.02     26.35     0.01  6618133     0.00     0.00  ShPathInterface::getInComeLink(int) const
  0.02     26.35     0.01  3569388     0.00     0.00  ShPathInterface::getCost(int) const
  0.02     26.36     0.01     2522     0.00     0.00  StarLink::setNodeFromIndex(int)
  0.02     26.36     0.01     2522     0.00     0.00  StarLink::setIndex(int)
  0.00     26.36     0.00  1540273     0.00     0.00  StarLink::getFlow() const
  0.00     26.36     0.00  1232181     0.00     0.00  Path::getFlow() const
  0.00     26.36     0.00  1058472     0.00     0.00  Path::getPrevFlow() const
  0.00     26.36     0.00   903419     0.00     0.00  StarLink::updateTime()
  0.00     26.36     0.00   869785     0.00     0.00  PathAndDirection::getDirectionValue() const
  0.00     26.36     0.00   592142     0.00     0.00  Path::addLinkToPath(StarLink*)
  0.00     26.36     0.00   343091     0.00     0.00  StarLink::getLinkFnc() const
  0.00     26.36     0.00   253504     0.00     0.00  PairOD::getDemand() const
  0.00     26.36     0.00   231088     0.00     0.00  Path::setCurrCost(double)
  0.00     26.36     0.00   215939     0.00     0.00  AdditivePC::calculate(Path*) const
  0.00     26.36     0.00   207011     0.00     0.00  OriginBushLUCE::OriginBushLUCE(int, StarNetwork*)
  0.00     26.36     0.00   205972     0.00     0.12  PathBasedAlgo::mainLoop(ODSet*)
  0.00     26.36     0.00   205972     0.00     0.00  EquilibrationI::executeMainLoop(ODSet*)
  0.00     26.36     0.00   205972     0.00     0.12  ODSet::improveSet()
  0.00     26.36     0.00   205972     0.00     0.00  PathSet::getNextSet()
  0.00     26.36     0.00   190823     0.00     0.00  ODSet::getNbPaths() const
  0.00     26.36     0.00   177675     0.00     0.00  PairOD::getODIndex() const
  0.00     26.36     0.00   169753     0.00     0.00  PathSet::initialiseItself(StarLink*, PairOD*)
  0.00     26.36     0.00   169753     0.00     0.00  ODSet::getDestIndex() const
  0.00     26.36     0.00   166196     0.00     0.00  Path::getCurrCost() const
  0.00     26.36     0.00   123112     0.00     0.00  PathAndDirection::getPath() const
  0.00     26.36     0.00    73138     0.00     0.00  StarNetwork::getNextOnlyLink()
  0.00     26.36     0.00    61556     0.00     0.00  PathAndDirection::setDirection(double)
  0.00     26.36     0.00    61556     0.00     0.00  PathBasedFlowMove::getNextPathDirection()
  0.00     26.36     0.00    48390     0.00     0.00  Path::setPrevFlow(double)
  0.00     26.36     0.00    46548     0.00     0.00  PathAndDirection::PathAndDirection()
  0.00     26.36     0.00    46548     0.00     0.00  PathAndDirection::~PathAndDirection()
  0.00     26.36     0.00    38700     0.00     0.00  Path::setFlow(double)
  0.00     26.36     0.00    30778     0.00     0.00  PathAndDirection::setPath(Path*)
  0.00     26.36     0.00    30778     0.00     0.00  PathBasedFlowMove::beginPathDirection()
  0.00     26.36     0.00    23274     0.00     0.00  DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&)
  0.00     26.36     0.00    23274     0.00     0.00  DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&)
  0.00     26.36     0.00    23274     0.00     0.00  ODSet::equilibrate()
  0.00     26.36     0.00    23274     0.00     0.00  ODSet::removeUnusedPaths()
  0.00     26.36     0.00    23071     0.00     0.00  Path::Path()
  0.00     26.36     0.00    23071     0.00     0.00  Path::~Path()
  0.00     26.36     0.00    18924     0.00     0.00  Origin::getIndex() const
  0.00     26.36     0.00    15389     0.00     0.00  PathDerivative::calculate(Path*, Path*)
  0.00     26.36     0.00    15389     0.00     0.00  PathDerivative::PathDerivative(int)
  0.00     26.36     0.00    15389     0.00     0.00  PathDerivative::~PathDerivative()
  0.00     26.36     0.00    15389     0.00     0.00  ODSet::updateLinkCostsOfOD()
  0.00     26.36     0.00    15389     0.00     0.00  Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int)
  0.00     26.36     0.00     8034     0.00     0.00  StarNetwork::getNodeIndex(int)
  0.00     26.36     0.00     7925     0.00     0.00  StarNetwork::getNbLinks()
  0.00     26.36     0.00     7922     0.00     0.00  PathAlgoCreator::allocateDescDirectionPath()
  0.00     26.36     0.00     7922     0.00     0.00  PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*)
  0.00     26.36     0.00     7922     0.00     0.00  DescDirectionPathPE::DescDirectionPathPE(double)
  0.00     26.36     0.00     7922     0.00     0.00  DescDirectionPathPE::~DescDirectionPathPE()
  0.00     26.36     0.00     7922     0.00     0.00  PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*)
  0.00     26.36     0.00     7922     0.00     0.00  PathBasedFlowMovePE::~PathBasedFlowMovePE()
  0.00     26.36     0.00     7922     0.00     0.00  DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double)
  0.00     26.36     0.00     7922     0.00     0.00  DescDirectionPathScaled::~DescDirectionPathScaled()
  0.00     26.36     0.00     7922     0.00     0.00  ODSet::addPath(Path*)
  0.00     26.36     0.00     7922     0.00     0.00  ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*)
  0.00     26.36     0.00     7922     0.00     0.00  ODSet::~ODSet()
  0.00     26.36     0.00     7922     0.00     0.00  ODSet::~ODSet()
  0.00     26.36     0.00     7922     0.00     0.00  Origin::addDestination(PairOD*)
  0.00     26.36     0.00     7922     0.00     0.00  PairOD::setODIndex(int)
  0.00     26.36     0.00     7922     0.00     0.00  PairOD::setOriginIndex(int)
  0.00     26.36     0.00     7922     0.00     0.00  PairOD::setIndex(int)
  0.00     26.36     0.00     7922     0.00     0.00  PairOD::PairOD(int, double)
  0.00     26.36     0.00     7922     0.00     0.00  PairOD::~PairOD()
  0.00     26.36     0.00     7922     0.00     0.00  PairOD::getID() const
  0.00     26.36     0.00     4533     0.00     0.00  Utils::removeWhiteSpaces(std::string&)
  0.00     26.36     0.00     4410     0.00     0.00  Utils::skipOneLineComment(std::string, std::string)
  0.00     26.36     0.00     3449     0.00     0.00  StarNode::getIndex()
  0.00     26.36     0.00     3410     0.00     0.00  Origin::beginDest()
  0.00     26.36     0.00     3300     0.00     0.00  ODMatrix::getNextOrigin()
  0.00     26.36     0.00     3080     0.00     0.00  ShPathDijkstraSTL::calculate(int)
  0.00     26.36     0.00     3080     0.00     0.16  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int)
  0.00     26.36     0.00     2522     0.00     0.00  StarNetwork::addLink(StarLink*)
  0.00     26.36     0.00     2522     0.00     0.00  BprFnc::BprFnc(double, double, double, double)
  0.00     26.36     0.00     2522     0.00     0.00  BprFnc::~BprFnc()
  0.00     26.36     0.00     2522     0.00     0.00  StarLink::setNodeToIndex(int)
  0.00     26.36     0.00     2522     0.00     0.00  StarLink::StarLink(int, int, LinkFnc*)
  0.00     26.36     0.00     2522     0.00     0.00  StarLink::~StarLink()
  0.00     26.36     0.00     2285     0.00     0.00  std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&)
  0.00     26.36     0.00     2046     0.00     0.00  StarNetwork::getNbNodes()
  0.00     26.36     0.00      930     0.00     0.00  ObjectManager::getEqAlgo()
  0.00     26.36     0.00      929     0.00     0.00  StarNetwork::getNextNode()
  0.00     26.36     0.00      929     0.00     0.00  StarNetwork::addNode(StarNode*)
  0.00     26.36     0.00      929     0.00     0.00  StarNode::setIndex(int)
  0.00     26.36     0.00      929     0.00     0.00  StarNode::StarNode(int, bool)
  0.00     26.36     0.00      929     0.00     0.00  StarNode::~StarNode()
  0.00     26.36     0.00      110     0.00     0.00  Origin::setIndex(int)
  0.00     26.36     0.00      110     0.00     0.00  Origin::Origin(int)
  0.00     26.36     0.00      110     0.00     0.00  Origin::~Origin()
  0.00     26.36     0.00      110     0.00     0.00  ODMatrix::addOrigin(Origin*)
  0.00     26.36     0.00      110     0.00     0.00  Origin::getID() const
  0.00     26.36     0.00       71     0.00     0.00  Utils::getSubString(std::string, std::string, std::string)
  0.00     26.36     0.00       33     0.00     0.00  ParseParams::skipComments(std::string)
  0.00     26.36     0.00       33     0.00     0.00  Params::addParameter(std::string, std::string)
  0.00     26.36     0.00       30     0.00     0.00  ODMatrix::beginOrigin()
  0.00     26.36     0.00       29     0.00     0.00  StarNetwork::beginOnlyLink()
  0.00     26.36     0.00       27     0.00    17.96  RelGap::isConverged()
  0.00     26.36     0.00       27     0.00    17.95  RelGap::getMinTravelTime()
  0.00     26.36     0.00       27     0.00     0.00  PathSet::isConverged() const
  0.00     26.36     0.00       26     0.00     0.00  PathSet::beginSet()
  0.00     26.36     0.00       16     0.00     0.00  Params::getParam(std::string)
  0.00     26.36     0.00        6     0.00     0.00  ObjectManager::getNet()
  0.00     26.36     0.00        6     0.00     0.00  bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*)
  0.00     26.36     0.00        5     0.00     0.00  std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*)
  0.00     26.36     0.00        3     0.00     0.00  ObjectManager::getPathAlgoType()
  0.00     26.36     0.00        3     0.00     0.00  Parser::checkEmptyValue(int)
  0.00     26.36     0.00        2     0.00     0.03  StarNetwork::calculateLinkCosts()
  0.00     26.36     0.00        2     0.00     0.37  ObjectManager::getODMatrix()
  0.00     26.36     0.00        2     0.00     0.00  ObjectManager::getPathAlgoApp()
  0.00     26.36     0.00        2     0.00     0.01  ObjectManager::getShPath()
  0.00     26.36     0.00        2     0.00     0.00  ShPathInterface::ShPathInterface(StarNetwork*)
  0.00     26.36     0.00        2     0.00     0.00  ShPathInterface::~ShPathInterface()
  0.00     26.36     0.00        2     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear()
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10AdditivePCC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10AlgorithmB9zeroFlow_E
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10DerivativeC2EdP16LinkFncContainer
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10FileReaderC2ERKSs
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10FileWriterC2ERKSs
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10OriginBush15wasInitialised_E
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11DAGraphLUCEC2EP11StarNetworkP8ODMatrixddi
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11DAGraphNodeC2Eid
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11MarginalFncC2EP7LinkFnc
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11ParseParamsC2ESs
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11StarNetworkC2EiiRSs
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11StepSizeAddC2EP13DescDirectionidP10LineSearchP10Derivative
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN12LinkFlowsBFW14allocateMemoryEv
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN12LinkFlowsCFW14allocateMemoryEv
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13AONAssignmentC2EP8ODMatrixP12ShortestPath
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13NonAdditivePCC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13ObjectManagerC2EP6Params
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13PathBasedAlgoC2EP7PathSetb
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13ShPathFactoryC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13SpiessFncCombC2EP9SpiessFncS1_
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14EquilibrationIC2EP13PathBasedAlgo
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14OriginBushLUCEC2EiP11StarNetwork
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14PathDerivativeC2Ei
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14StepSizeNonAddC2EP13DescDirectionidP10LineSearchP10Derivative
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN15EquilibrationIIC2EP13PathBasedAlgo
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN15OriginBasedAlgoC2EP9OriginSet
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN15PathAlgoCreatorC2E12PathAlgoType7PathAppiddd
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16LinkFncContainerC2EP11StarNetwork
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16PathAndDirectionC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16SpiessFncCreatorC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16StepSizeSparsityC2EP8StepSize
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN17LabelCorrectingAlC2EP11StarNetwork
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN17OnePathDerivativeC2Ed
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN17PathBasedFlowMoveC2EP17DescDirectionPath
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19DescDirectionPathGPC2Ed
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19DescDirectionPathPEC2Ed
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19DescDirectionPathPGC2Ed
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19PathBasedFlowMoveGPC2EddP17DescDirectionPath
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19PathBasedFlowMovePEC2EP17DescDirectionPath
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN20DescDirectionPathISPC2Eddd
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN23DescDirectionPathScaledC2EP17DescDirectionPathid
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN25PathBasedFlowMoveWithStepC2EP11StepSizeABCP17DescDirectionPath
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN4PathC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN5ODSet16initialiseObjectEiiiP8PathCostP16LinkFncContainerP11StarNetworkP12ShortestPathP11ConvMeasuredPdSA_P15PathAlgoCreator
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN5Utils16getDisjointLinksEP4PathS1_RSt4listIP8StarLinkSaIS4_EEi
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN5Utils17removeWhiteSpacesERSs
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6ArmijoC2EdP10Derivative
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6BprFncC2Edddd
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6FWAlgoC2EP9LinkFlows
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6OriginC2Ei
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6PairODC2Eid
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6ParamsC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6ParserC2Ev
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6RelGapC2EdP11StarNetworkP8ODMatrixP12ShortestPath
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN7DAGraph4net_E
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN7PathSet16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP11ConvMeasureP8PathCost
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN7QuadAppC2EP10Derivative
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8ConstFncC2Ed
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8ODMatrixC2Ei
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8StarLinkC2EiiP7LinkFnc
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8StepSizeC2EP13DescDirectionidP10LineSearch
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9BisectionC2EdP10Derivative
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9LinearFncC2Edd
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9LinkFlows16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP10DerivativeP10LineSearchP11ConvMeasure
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9OriginSetC2EP8ODMatrixP11StarNetworkP12ShortestPathP11ConvMeasureddb
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9SpiessFncC2Eddddd
  0.00     26.36     0.00        1     0.00     0.00  _GLOBAL__sub_I_main
  0.00     26.36     0.00        1     0.00     0.00  AdditivePC::AdditivePC()
  0.00     26.36     0.00        1     0.00     0.00  AdditivePC::~AdditivePC()
  0.00     26.36     0.00        1     0.00     0.02  StarNetwork::createIndexes()
  0.00     26.36     0.00        1     0.00     0.00  StarNetwork::beginNode()
  0.00     26.36     0.00        1     0.00    29.96  StarNetwork::linkNodes()
  0.00     26.36     0.00        1     0.00     0.00  StarNetwork::StarNetwork(int, int, std::string&)
  0.00     26.36     0.00        1     0.00     0.00  StarNetwork::~StarNetwork()
  0.00     26.36     0.00        1     0.00    20.58  AONAssignment::execute(InitialiseSolution*)
  0.00     26.36     0.00        1     0.00     0.00  AONAssignment::AONAssignment(ODMatrix*, ShortestPath*)
  0.00     26.36     0.00        1     0.00     0.00  AONAssignment::~AONAssignment()
  0.00     26.36     0.00        1     0.00     0.64  ObjectManager::getPathSet()
  0.00     26.36     0.00        1     0.00     0.00  ObjectManager::getPathCost()
  0.00     26.36     0.00        1     0.00     0.00  ObjectManager::getConvMeasure()
  0.00     26.36     0.00        1     0.00     0.00  ObjectManager::getPathAlgoCreator()
  0.00     26.36     0.00        1     0.00     0.00  PathBasedAlgo::PathBasedAlgo(PathSet*, bool)
  0.00     26.36     0.00        1     0.00     0.00  PathBasedAlgo::~PathBasedAlgo()
  0.00     26.36     0.00        1     0.00     0.00  ShPathFactory::get()
  0.00     26.36     0.00        1     0.00     0.02  ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*)
  0.00     26.36     0.00        1     0.00     0.00  EquilibrationI::EquilibrationI(PathBasedAlgo*)
  0.00     26.36     0.00        1     0.00     0.00  EquilibrationI::~EquilibrationI()
  0.00     26.36     0.00        1     0.00     0.00  PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double)
  0.00     26.36     0.00        1     0.00     0.00  PathAlgoCreator::~PathAlgoCreator()
  0.00     26.36     0.00        1     0.00     0.00  LinkFncContainer::LinkFncContainer(StarNetwork*)
  0.00     26.36     0.00        1     0.00     0.00  LinkFncContainer::~LinkFncContainer()
  0.00     26.36     0.00        1     0.00     0.00  ShPathDijkstraSTL::ShPathDijkstraSTL(StarNetwork*)
  0.00     26.36     0.00        1     0.00     0.00  ShPathDijkstraSTL::~ShPathDijkstraSTL()
  0.00     26.36     0.00        1     0.00     0.02  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*)
  0.00     26.36     0.00        1     0.00     0.00  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect()
  0.00     26.36     0.00        1     0.00     0.00  ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect()
  0.00     26.36     0.00        1     0.00     0.00  Utils::extractName(char const*, std::string&)
  0.00     26.36     0.00        1     0.00    10.03  Parser::parseNetwork(std::string const&, bool)
  0.00     26.36     0.00        1     0.00     0.11  Parser::parseODMatrix(std::string const&, int)
  0.00     26.36     0.00        1     0.00     0.00  Parser::Parser()
  0.00     26.36     0.00        1     0.00     0.00  RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*)
  0.00     26.36     0.00        1     0.00     0.00  RelGap::~RelGap()
  0.00     26.36     0.00        1     0.00    39.96  PathSet::initialise()
  0.00     26.36     0.00        1     0.00     0.00  PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*)
  0.00     26.36     0.00        1     0.00     0.64  PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*)
  0.00     26.36     0.00        1     0.00     0.00  PathSet::~PathSet()
  0.00     26.36     0.00        1     0.00     0.00  PathSet::~PathSet()
  0.00     26.36     0.00        1     0.00     0.64  ODMatrix::setIndexes(StarNetwork*)
  0.00     26.36     0.00        1     0.00     0.00  ODMatrix::ODMatrix(int)
  0.00     26.36     0.00        1     0.00     0.00  ODMatrix::~ODMatrix()
  0.00     26.36     0.00        1     0.00     0.00  ODMatrix::getNbODPairs() const
  0.00     26.36     0.00        1     0.00     0.00  std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*)

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.
 
 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this 
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 0.04% of 26.36 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     98.6    0.00   26.00                 PathBasedAlgo::execute() [1]
                0.00   25.47  205972/205972      PathBasedAlgo::mainLoop(ODSet*) [2]
                0.00    0.48      27/27          RelGap::isConverged() [10]
                0.00    0.04       1/1           PathSet::initialise() [34]
                0.00    0.00  205972/205972      PathSet::getNextSet() [95]
                0.00    0.00  205972/205972      EquilibrationI::executeMainLoop(ODSet*) [94]
                0.00    0.00      27/27          PathSet::isConverged() const [165]
                0.00    0.00      26/26          PathSet::beginSet() [166]
-----------------------------------------------
                0.00   25.47  205972/205972      PathBasedAlgo::execute() [1]
[2]     96.6    0.00   25.47  205972         PathBasedAlgo::mainLoop(ODSet*) [2]
                0.00   25.24  205972/205972      ODSet::improveSet() [3]
                0.04    0.05  205972/205972      ODSet::updateSet() [24]
                0.00    0.08   23274/23274       ODSet::equilibrate() [27]
                0.01    0.03   15389/23311       ODSet::projectPathFlowOnLinks() [30]
                0.00    0.02   15389/15389       ODSet::updateLinkCostsOfOD() [43]
                0.01    0.00   15389/15389       PathBasedFlowMovePE::executeFlowMove() [52]
                0.00    0.00  190823/190823      ODSet::getNbPaths() const [96]
                0.00    0.00   23274/23274       ODSet::removeUnusedPaths() [111]
-----------------------------------------------
                0.00   25.24  205972/205972      PathBasedAlgo::mainLoop(ODSet*) [2]
[3]     95.7    0.00   25.24  205972         ODSet::improveSet() [3]
                0.06   25.17  205972/205972      ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.00    0.00  422389/15260894     StarNetwork::getLink(int) [26]
                0.00    0.00  437538/82712365     StarLink::getNodeFromIndex() const [14]
                0.00    0.00  437538/6618133     ShPathInterface::getInComeLink(int) const [57]
                0.00    0.00  205972/3569388     ShPathInterface::getCost(int) const [58]
                0.00    0.00  422389/592142      Path::addLinkToPath(StarLink*) [89]
                0.00    0.00   30298/166196      Path::getCurrCost() const [99]
                0.00    0.00   15149/23071       Path::Path() [112]
                0.00    0.00   15149/231088      Path::setCurrCost(double) [92]
-----------------------------------------------
                0.06   25.17  205972/205972      ODSet::improveSet() [3]
[4]     95.7    0.06   25.17  205972         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
               12.54    4.30 32302428/32302428     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                2.02    4.42 32302428/32302428     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                1.60    0.20  205972/205972      ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [9]
                0.05    0.00 8946112/15260894     StarNetwork::getLink(int) [26]
                0.02    0.00 11192102/98803196     StarLink::getNodeToIndex() const [19]
                0.01    0.00 2227066/82712365     StarLink::getNodeFromIndex() const [14]
                0.00    0.00 4473056/176574565     StarLink::getTime() const [20]
                0.00    0.00 4473056/98004999     StarLink::getIndex() const [25]
                0.00    0.00  205972/207011      OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [93]
-----------------------------------------------
               12.54    4.30 32302428/32302428     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[5]     63.9   12.54    4.30 32302428         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                0.75    1.45 38658418/77688544     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                1.23    0.00 32302428/145897067     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                0.39    0.00 79867564/82712365     StarLink::getNodeFromIndex() const [14]
                0.14    0.00 32302428/67682791     StarNetwork::beginNode(int) [17]
                0.03    0.08 2234260/4516627     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [18]
                0.09    0.00 79867564/176574565     StarLink::getTime() const [20]
                0.09    0.00 32302428/67642742     StarNode::getIsZone() [22]
                0.04    0.00 40892678/98004999     StarLink::getIndex() const [25]
-----------------------------------------------
                2.02    4.42 32302428/32302428     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[6]     24.4    2.02    4.42 32302428         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.75    1.45 38618182/77688544     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                1.23    0.00 32302428/145897067     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                0.28    0.00 79881216/87438819     StarNetwork::getNextLink() [16]
                0.17    0.00 79881216/98803196     StarLink::getNodeToIndex() const [19]
                0.14    0.00 32302428/67682791     StarNetwork::beginNode(int) [17]
                0.04    0.09 2282367/4516627     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [18]
                0.09    0.00 79881216/176574565     StarLink::getTime() const [20]
                0.09    0.00 32264530/67642742     StarNode::getIsZone() [22]
                0.05    0.00 29241848/31981907     StarNetwork::beginLink() [29]
                0.04    0.00 40900549/98004999     StarLink::getIndex() const [25]
-----------------------------------------------
                             398952364             boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                0.17    0.00 4500251/145897067     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [18]
                1.23    0.00 32302428/145897067     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                1.23    0.00 32302428/145897067     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                2.92    0.00 76791960/145897067     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
[7]     21.1    5.55    0.00 145897067+398952364 boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                             398952364             boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
-----------------------------------------------
                0.01    0.02  411944/77688544     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [9]
                0.75    1.45 38618182/77688544     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.75    1.45 38658418/77688544     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[8]     16.8    1.51    2.92 77688544         boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                2.92    0.00 76791960/145897067     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
-----------------------------------------------
                1.60    0.20  205972/205972      ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[9]      6.8    1.60    0.20  205972         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [9]
                0.18    0.00  821623/821627      void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [23]
                0.01    0.02  411944/77688544     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
-----------------------------------------------
                0.00    0.48      27/27          PathBasedAlgo::execute() [1]
[10]     1.8    0.00    0.48      27         RelGap::isConverged() [10]
                0.00    0.48      27/27          RelGap::getMinTravelTime() [11]
                0.00    0.00   68094/176574565     StarLink::getTime() const [20]
                0.00    0.00  136188/1540273     StarLink::getFlow() const [85]
                0.00    0.00   68094/73138       StarNetwork::getNextOnlyLink() [101]
                0.00    0.00      27/29          StarNetwork::beginOnlyLink() [164]
-----------------------------------------------
                0.00    0.48      27/27          RelGap::isConverged() [10]
[11]     1.8    0.00    0.48      27         RelGap::getMinTravelTime() [11]
                0.00    0.47    2970/3080        ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
                0.01    0.00  213894/245582      Origin::getNextDest() [51]
                0.01    0.00  213894/253504      PairOD::getIndex() const [50]
                0.00    0.00  213894/3569388     ShPathInterface::getCost(int) const [58]
                0.00    0.00  213894/253504      PairOD::getDemand() const [91]
                0.00    0.00    2970/18924       Origin::getIndex() const [114]
                0.00    0.00    2970/3410        Origin::beginDest() [141]
                0.00    0.00    2970/3300        ODMatrix::getNextOrigin() [142]
                0.00    0.00      27/30          ODMatrix::beginOrigin() [163]
-----------------------------------------------
                0.00    0.02     110/3080        AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.47    2970/3080        RelGap::getMinTravelTime() [11]
[12]     1.8    0.00    0.48    3080         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
                0.17    0.27    3080/3080        ShPathDijkstraSTL::calculate(int, int) [13]
                0.03    0.00 5722640/15260894     StarNetwork::getLink(int) [26]
                0.00    0.00 6002920/6618133     ShPathInterface::getInComeLink(int) const [57]
                0.00    0.00 3141600/3569388     ShPathInterface::getCost(int) const [58]
                0.00    0.00 2861320/98004999     StarLink::getIndex() const [25]
                0.00    0.00    3080/3080        ShPathDijkstraSTL::calculate(int) [143]
-----------------------------------------------
                0.17    0.27    3080/3080        ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
[13]     1.7    0.17    0.27    3080         ShPathDijkstraSTL::calculate(int, int) [13]
                0.19    0.00 3077935/3077935     void std::__adjust_heap<__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize>(__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize) [21]
                0.03    0.00 7555081/87438819     StarNetwork::getNextLink() [16]
                0.02    0.00 7555081/98803196     StarLink::getNodeToIndex() const [19]
                0.01    0.00 3077935/67682791     StarNetwork::beginNode(int) [17]
                0.01    0.00 7555081/176574565     StarLink::getTime() const [20]
                0.01    0.00 3074855/67642742     StarNode::getIsZone() [22]
                0.01    0.00 2739130/31981907     StarNetwork::beginLink() [29]
                0.00    0.00 3074855/98004999     StarLink::getIndex() const [25]
                0.00    0.00      19/207011      OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [93]
-----------------------------------------------
                0.00    0.00    2522/82712365     Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00  177675/82712365     AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00  437538/82712365     ODSet::improveSet() [3]
                0.01    0.00 2227066/82712365     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.39    0.00 79867564/82712365     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[14]     1.5    0.41    0.00 82712365         StarLink::getNodeFromIndex() const [14]
-----------------------------------------------
                                                 <spontaneous>
[15]     1.2    0.31    0.00                 boost::heap::fibonacci_heap<ValueKey, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::consolidate() [15]
-----------------------------------------------
                0.00    0.00    2522/87438819     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.03    0.00 7555081/87438819     ShPathDijkstraSTL::calculate(int, int) [13]
                0.28    0.00 79881216/87438819     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[16]     1.2    0.31    0.00 87438819         StarNetwork::getNextLink() [16]
-----------------------------------------------
                0.01    0.00 3077935/67682791     ShPathDijkstraSTL::calculate(int, int) [13]
                0.14    0.00 32302428/67682791     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.14    0.00 32302428/67682791     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[17]     1.1    0.30    0.00 67682791         StarNetwork::beginNode(int) [17]
-----------------------------------------------
                0.03    0.08 2234260/4516627     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                0.04    0.09 2282367/4516627     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[18]     0.9    0.07    0.17 4516627         boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [18]
                0.17    0.00 4500251/145897067     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
-----------------------------------------------
                0.00    0.00    2522/98803196     Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00    2522/98803196     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.00    0.00  169753/98803196     PathSet::initialiseItself(StarLink*, PairOD*) [66]
                0.02    0.00 7555081/98803196     ShPathDijkstraSTL::calculate(int, int) [13]
                0.02    0.00 11192102/98803196     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.17    0.00 79881216/98803196     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[19]     0.8    0.22    0.00 98803196         StarLink::getNodeToIndex() const [19]
-----------------------------------------------
                0.00    0.00   68094/176574565     RelGap::isConverged() [10]
                0.00    0.00 4473056/176574565     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.01    0.00 4729554/176574565     AdditivePC::calculate(Path*) const [31]
                0.01    0.00 7555081/176574565     ShPathDijkstraSTL::calculate(int, int) [13]
                0.09    0.00 79867564/176574565     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                0.09    0.00 79881216/176574565     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[20]     0.7    0.20    0.00 176574565         StarLink::getTime() const [20]
-----------------------------------------------
                0.19    0.00 3077935/3077935     ShPathDijkstraSTL::calculate(int, int) [13]
[21]     0.7    0.19    0.00 3077935         void std::__adjust_heap<__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize>(__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize) [21]
-----------------------------------------------
                0.00    0.00     929/67642742     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.01    0.00 3074855/67642742     ShPathDijkstraSTL::calculate(int, int) [13]
                0.09    0.00 32264530/67642742     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.09    0.00 32302428/67642742     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[22]     0.7    0.18    0.00 67642742         StarNode::getIsZone() [22]
-----------------------------------------------
                             1424578             void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [23]
                0.00    0.00       4/821627      boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [76]
                0.18    0.00  821623/821627      ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [9]
[23]     0.7    0.18    0.00  821627+1424578 void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [23]
                             1424578             void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [23]
-----------------------------------------------
                0.04    0.05  205972/205972      PathBasedAlgo::mainLoop(ODSet*) [2]
[24]     0.3    0.04    0.05  205972         ODSet::updateSet() [24]
                0.00    0.05  215939/215939      AdditivePC::calculate(Path*) const [31]
                0.00    0.00  215939/231088      Path::setCurrCost(double) [92]
-----------------------------------------------
                0.00    0.00    2522/98004999     LinkFncContainer::LinkFncContainer(StarNetwork*) [75]
                0.00    0.00  839007/98004999     Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.00    0.00 1088226/98004999     ODSet::calculateProjectedDirection() [35]
                0.00    0.00 1257404/98004999     Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [40]
                0.00    0.00 2615382/98004999     ODSet::projectPathFlowOnLinks() [30]
                0.00    0.00 2861320/98004999     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
                0.00    0.00 3074855/98004999     ShPathDijkstraSTL::calculate(int, int) [13]
                0.00    0.00 4473056/98004999     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.04    0.00 40892678/98004999     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                0.04    0.00 40900549/98004999     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[25]     0.3    0.09    0.00 98004999         StarLink::getIndex() const [25]
-----------------------------------------------
                0.00    0.00  169753/15260894     AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00  422389/15260894     ODSet::improveSet() [3]
                0.03    0.00 5722640/15260894     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
                0.05    0.00 8946112/15260894     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[26]     0.3    0.09    0.00 15260894         StarNetwork::getLink(int) [26]
-----------------------------------------------
                0.00    0.08   23274/23274       PathBasedAlgo::mainLoop(ODSet*) [2]
[27]     0.3    0.00    0.08   23274         ODSet::equilibrate() [27]
                0.01    0.03   23274/23274       PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [32]
                0.02    0.02   15389/15389       ODSet::calculateProjectedDirection() [35]
                0.00    0.00   96780/1232181     Path::getFlow() const [86]
                0.00    0.00   48390/48390       Path::setPrevFlow(double) [104]
-----------------------------------------------
                0.01    0.00  839007/10670635     Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.01    0.00  839007/10670635     ODSet::calculateProjectedDirection() [35]
                0.01    0.00  888719/10670635     ODSet::updateLinkCostsOfOD() [43]
                0.01    0.00 1257404/10670635     Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [40]
                0.01    0.00 2116944/10670635     ODSet::projectPathFlowOnLinks() [30]
                0.03    0.00 4729554/10670635     AdditivePC::calculate(Path*) const [31]
[28]     0.3    0.07    0.00 10670635         Path::getNextLink() const [28]
-----------------------------------------------
                0.00    0.00     929/31981907     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.01    0.00 2739130/31981907     ShPathDijkstraSTL::calculate(int, int) [13]
                0.05    0.00 29241848/31981907     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[29]     0.2    0.06    0.00 31981907         StarNetwork::beginLink() [29]
-----------------------------------------------
                0.00    0.02    7922/23311       PathSet::initialise() [34]
                0.01    0.03   15389/23311       PathBasedAlgo::mainLoop(ODSet*) [2]
[30]     0.2    0.01    0.05   23311         ODSet::projectPathFlowOnLinks() [30]
                0.02    0.00 1058472/1058472     StarLink::addFlow(double) [44]
                0.01    0.00 2116944/10670635     Path::getNextLink() const [28]
                0.01    0.00 1307691/1307691     StarLink::setFlow(double) [46]
                0.01    0.00   80846/437009      Path::beginLink() const [38]
                0.00    0.00 2615382/98004999     StarLink::getIndex() const [25]
                0.00    0.00 1058472/1058472     Path::getPrevFlow() const [87]
                0.00    0.00 1058472/1540273     StarLink::getFlow() const [85]
                0.00    0.00 1058472/1232181     Path::getFlow() const [86]
-----------------------------------------------
                0.00    0.05  215939/215939      ODSet::updateSet() [24]
[31]     0.2    0.00    0.05  215939         AdditivePC::calculate(Path*) const [31]
                0.03    0.00 4729554/10670635     Path::getNextLink() const [28]
                0.01    0.00  215939/437009      Path::beginLink() const [38]
                0.01    0.00 4729554/176574565     StarLink::getTime() const [20]
-----------------------------------------------
                0.01    0.03   23274/23274       ODSet::equilibrate() [27]
[32]     0.2    0.01    0.03   23274         PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [32]
                0.00    0.03   23274/23274       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
                0.00    0.00   24470/46548       PathAndDirection::~PathAndDirection() [106]
-----------------------------------------------
                0.00    0.04       1/1           PathBasedAlgo::execute() [1]
[34]     0.2    0.00    0.04       1         PathSet::initialise() [34]
                0.00    0.02       1/1           AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.02    7922/23311       ODSet::projectPathFlowOnLinks() [30]
                0.00    0.00       2/2           StarNetwork::calculateLinkCosts() [68]
                0.00    0.00       1/1           AONAssignment::AONAssignment(ODMatrix*, ShortestPath*) [248]
                0.00    0.00       1/1           AONAssignment::~AONAssignment() [249]
-----------------------------------------------
                0.02    0.02   15389/15389       ODSet::equilibrate() [27]
[35]     0.1    0.02    0.02   15389         ODSet::calculateProjectedDirection() [35]
                0.00    0.01   15389/15389       Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.01    0.00  839007/10670635     Path::getNextLink() const [28]
                0.00    0.00   30778/437009      Path::beginLink() const [38]
                0.00    0.00 1088226/98004999     StarLink::getIndex() const [25]
                0.00    0.00  839007/869785      PathAndDirection::getDirectionValue() const [88]
                0.00    0.00   30778/123112      PathAndDirection::getPath() const [100]
                0.00    0.00   30778/61556       PathBasedFlowMove::getNextPathDirection() [103]
                0.00    0.00   15389/30778       PathBasedFlowMove::beginPathDirection() [109]
-----------------------------------------------
                0.00    0.03   23274/23274       PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [32]
[36]     0.1    0.00    0.03   23274         DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
                0.00    0.03   15389/15389       PathDerivative::calculate(Path*, Path*) [37]
                0.00    0.00   30778/123112      PathAndDirection::getPath() const [100]
                0.00    0.00   30778/61556       PathAndDirection::setDirection(double) [102]
                0.00    0.00   23274/23274       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [110]
                0.00    0.00   15389/15389       PathDerivative::PathDerivative(int) [115]
                0.00    0.00   15389/869785      PathAndDirection::getDirectionValue() const [88]
                0.00    0.00   15389/15389       PathDerivative::~PathDerivative() [116]
-----------------------------------------------
                0.00    0.03   15389/15389       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
[37]     0.1    0.00    0.03   15389         PathDerivative::calculate(Path*, Path*) [37]
                0.01    0.01   15389/15389       Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [40]
                0.01    0.00  340569/340569      BprFnc::evaluateDerivative(double) [49]
                0.00    0.00  340569/343091      StarLink::getLinkFnc() const [90]
                0.00    0.00  340569/1540273     StarLink::getFlow() const [85]
-----------------------------------------------
                0.00    0.00   30778/437009      Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.00    0.00   30778/437009      ODSet::calculateProjectedDirection() [35]
                0.00    0.00   32501/437009      ODSet::updateLinkCostsOfOD() [43]
                0.00    0.00   46167/437009      Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [40]
                0.01    0.00   80846/437009      ODSet::projectPathFlowOnLinks() [30]
                0.01    0.00  215939/437009      AdditivePC::calculate(Path*) const [31]
[38]     0.1    0.03    0.00  437009         Path::beginLink() const [38]
-----------------------------------------------
                                   1             ObjectManager::getNet() <cycle 1> [168]
[39]     0.1    0.00    0.03       1         StarNetwork::linkNodes() <cycle 1> [39]
                0.02    0.00 1193408/1194337     StarNode::getID() [42]
                0.01    0.00 1193410/1195932     StarLink::getNodeTo() const [47]
                0.00    0.00    2522/2522        StarLink::setNodeToIndex(int) [146]
                0.00    0.00    2520/3449        StarNode::getIndex() [140]
                0.00    0.00       2/8034        StarNetwork::getNodeIndex(int) [117]
                                   1             StarNetwork::createIndexes() <cycle 1> [70]
-----------------------------------------------
                0.01    0.01   15389/15389       PathDerivative::calculate(Path*, Path*) [37]
[40]     0.1    0.01    0.01   15389         Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [40]
                0.01    0.00 1257404/10670635     Path::getNextLink() const [28]
                0.00    0.00   46167/437009      Path::beginLink() const [38]
                0.00    0.00 1257404/98004999     StarLink::getIndex() const [25]
-----------------------------------------------
                0.00    0.02       1/1           PathSet::initialise() [34]
[41]     0.1    0.00    0.02       1         AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.02     110/3080        ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
                0.00    0.00  169753/15260894     StarNetwork::getLink(int) [26]
                0.00    0.00  177675/82712365     StarLink::getNodeFromIndex() const [14]
                0.00    0.00   15844/253504      PairOD::getIndex() const [50]
                0.00    0.00  169753/169753      PathSet::initialiseItself(StarLink*, PairOD*) [66]
                0.00    0.00    7922/245582      Origin::getNextDest() [51]
                0.00    0.00  177675/6618133     ShPathInterface::getInComeLink(int) const [57]
                0.00    0.00    7922/3569388     ShPathInterface::getCost(int) const [58]
                0.00    0.00  169753/592142      Path::addLinkToPath(StarLink*) [89]
                0.00    0.00    7922/253504      PairOD::getDemand() const [91]
                0.00    0.00     110/18924       Origin::getIndex() const [114]
                0.00    0.00     110/3410        Origin::beginDest() [141]
                0.00    0.00     110/3300        ODMatrix::getNextOrigin() [142]
                0.00    0.00       1/30          ODMatrix::beginOrigin() [163]
-----------------------------------------------
                0.00    0.00     929/1194337     StarNetwork::addNode(StarNode*) <cycle 1> [74]
                0.02    0.00 1193408/1194337     StarNetwork::linkNodes() <cycle 1> [39]
[42]     0.1    0.02    0.00 1194337         StarNode::getID() [42]
-----------------------------------------------
                0.00    0.02   15389/15389       PathBasedAlgo::mainLoop(ODSet*) [2]
[43]     0.1    0.00    0.02   15389         ODSet::updateLinkCostsOfOD() [43]
                0.00    0.01  888719/903419      StarLink::updateTime() [55]
                0.01    0.00  888719/10670635     Path::getNextLink() const [28]
                0.00    0.00   32501/437009      Path::beginLink() const [38]
-----------------------------------------------
                0.02    0.00 1058472/1058472     ODSet::projectPathFlowOnLinks() [30]
[44]     0.1    0.02    0.00 1058472         StarLink::addFlow(double) [44]
-----------------------------------------------
                                   1             ObjectManager::getNet() <cycle 1> [168]
[45]     0.0    0.00    0.01       1         Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
                0.00    0.01    2522/2522        StarNetwork::addLink(StarLink*) [53]
                0.00    0.00    2522/2522        StarLink::StarLink(int, int, LinkFnc*) [69]
                0.00    0.00    2530/4410        Utils::skipOneLineComment(std::string, std::string) [139]
                0.00    0.00    2530/4533        Utils::removeWhiteSpaces(std::string&) [138]
                0.00    0.00    2522/2522        BprFnc::BprFnc(double, double, double, double) [144]
                0.00    0.00     929/929         StarNode::StarNode(int, bool) [153]
                0.00    0.00       5/71          Utils::getSubString(std::string, std::string, std::string) [160]
                0.00    0.00       3/3           Parser::checkEmptyValue(int) [172]
                0.00    0.00       1/1           Utils::extractName(char const*, std::string&) [263]
                0.00    0.00       1/1           StarNetwork::StarNetwork(int, int, std::string&) [246]
                                 929             StarNetwork::addNode(StarNode*) <cycle 1> [74]
-----------------------------------------------
                0.01    0.00 1307691/1307691     ODSet::projectPathFlowOnLinks() [30]
[46]     0.0    0.01    0.00 1307691         StarLink::setFlow(double) [46]
-----------------------------------------------
                0.00    0.00    2522/1195932     StarNetwork::createIndexes() <cycle 1> [70]
                0.01    0.00 1193410/1195932     StarNetwork::linkNodes() <cycle 1> [39]
[47]     0.0    0.01    0.00 1195932         StarLink::getNodeTo() const [47]
-----------------------------------------------
                0.00    0.00    2522/896285      StarLink::StarLink(int, int, LinkFnc*) [69]
                0.01    0.00  893763/896285      StarLink::updateTime() [55]
[48]     0.0    0.01    0.00  896285         BprFnc::evaluate(double) [48]
-----------------------------------------------
                0.01    0.00  340569/340569      PathDerivative::calculate(Path*, Path*) [37]
[49]     0.0    0.01    0.00  340569         BprFnc::evaluateDerivative(double) [49]
-----------------------------------------------
                0.00    0.00    7922/253504      ODMatrix::setIndexes(StarNetwork*) [65]
                0.00    0.00    7922/253504      Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00    7922/253504      PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.00    0.00   15844/253504      AONAssignment::execute(InitialiseSolution*) [41]
                0.01    0.00  213894/253504      RelGap::getMinTravelTime() [11]
[50]     0.0    0.01    0.00  253504         PairOD::getIndex() const [50]
-----------------------------------------------
                0.00    0.00    7922/245582      ODMatrix::setIndexes(StarNetwork*) [65]
                0.00    0.00    7922/245582      Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00    7922/245582      AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00    7922/245582      PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.01    0.00  213894/245582      RelGap::getMinTravelTime() [11]
[51]     0.0    0.01    0.00  245582         Origin::getNextDest() [51]
-----------------------------------------------
                0.01    0.00   15389/15389       PathBasedAlgo::mainLoop(ODSet*) [2]
[52]     0.0    0.01    0.00   15389         PathBasedFlowMovePE::executeFlowMove() [52]
                0.00    0.00   30778/123112      PathAndDirection::getPath() const [100]
                0.00    0.00   30778/1232181     Path::getFlow() const [86]
                0.00    0.00   30778/38700       Path::setFlow(double) [107]
                0.00    0.00   15389/869785      PathAndDirection::getDirectionValue() const [88]
-----------------------------------------------
                0.00    0.01    2522/2522        Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[53]     0.0    0.00    0.01    2522         StarNetwork::addLink(StarLink*) [53]
                0.01    0.00    2522/2522        StarLink::setIndex(int) [60]
                0.01    0.00    2522/2522        StarLink::setNodeFromIndex(int) [59]
-----------------------------------------------
                                                 <spontaneous>
[54]     0.0    0.01    0.00                 BprFnc::~BprFnc() [54]
-----------------------------------------------
                0.00    0.00    5044/903419      StarNetwork::calculateLinkCosts() [68]
                0.00    0.00    9656/903419      Parser::parseODMatrix(std::string const&, int) [67]
                0.00    0.01  888719/903419      ODSet::updateLinkCostsOfOD() [43]
[55]     0.0    0.00    0.01  903419         StarLink::updateTime() [55]
                0.01    0.00  893763/896285      BprFnc::evaluate(double) [48]
-----------------------------------------------
                0.00    0.01   15389/15389       ODSet::calculateProjectedDirection() [35]
[56]     0.0    0.00    0.01   15389         Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.01    0.00  839007/10670635     Path::getNextLink() const [28]
                0.00    0.00   30778/437009      Path::beginLink() const [38]
                0.00    0.00  839007/98004999     StarLink::getIndex() const [25]
                0.00    0.00   30778/123112      PathAndDirection::getPath() const [100]
                0.00    0.00   30778/61556       PathBasedFlowMove::getNextPathDirection() [103]
                0.00    0.00   15389/30778       PathBasedFlowMove::beginPathDirection() [109]
-----------------------------------------------
                0.00    0.00  177675/6618133     AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00  437538/6618133     ODSet::improveSet() [3]
                0.00    0.00 6002920/6618133     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
[57]     0.0    0.01    0.00 6618133         ShPathInterface::getInComeLink(int) const [57]
-----------------------------------------------
                0.00    0.00    7922/3569388     AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00  205972/3569388     ODSet::improveSet() [3]
                0.00    0.00  213894/3569388     RelGap::getMinTravelTime() [11]
                0.00    0.00 3141600/3569388     ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
[58]     0.0    0.01    0.00 3569388         ShPathInterface::getCost(int) const [58]
-----------------------------------------------
                0.01    0.00    2522/2522        StarNetwork::addLink(StarLink*) [53]
[59]     0.0    0.01    0.00    2522         StarLink::setNodeFromIndex(int) [59]
-----------------------------------------------
                0.01    0.00    2522/2522        StarNetwork::addLink(StarLink*) [53]
[60]     0.0    0.01    0.00    2522         StarLink::setIndex(int) [60]
-----------------------------------------------
                                   1             ObjectManager::getConvMeasure() <cycle 1> [251]
                                   1             ObjectManager::getPathSet() <cycle 1> [63]
[61]     0.0    0.00    0.00       2         ObjectManager::getODMatrix() <cycle 1> [61]
                0.00    0.00       1/1           ODMatrix::setIndexes(StarNetwork*) [65]
                0.00    0.00       1/1           Parser::parseODMatrix(std::string const&, int) [67]
                0.00    0.00       2/16          Params::getParam(std::string) [167]
                0.00    0.00       1/2046        StarNetwork::getNbNodes() [149]
                                   1             ObjectManager::getNet() <cycle 1> [168]
-----------------------------------------------
                                                 <spontaneous>
[62]     0.0    0.00    0.00                 Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00    7922/245582      Origin::getNextDest() [51]
                0.00    0.00    7922/253504      PairOD::getIndex() const [50]
                0.00    0.00    2522/82712365     StarLink::getNodeFromIndex() const [14]
                0.00    0.00    2522/98803196     StarLink::getNodeToIndex() const [19]
                0.00    0.00   15844/253504      PairOD::getDemand() const [91]
                0.00    0.00    7922/18924       Origin::getIndex() const [114]
                0.00    0.00    5044/1540273     StarLink::getFlow() const [85]
                0.00    0.00    2522/73138       StarNetwork::getNextOnlyLink() [101]
                0.00    0.00    2043/2046        StarNetwork::getNbNodes() [149]
                0.00    0.00     110/3410        Origin::beginDest() [141]
                0.00    0.00     110/3300        ODMatrix::getNextOrigin() [142]
                0.00    0.00       1/30          ODMatrix::beginOrigin() [163]
                0.00    0.00       1/29          StarNetwork::beginOnlyLink() [164]
-----------------------------------------------
                                   1             ObjectManager::getEqAlgo() <cycle 1> [150]
[63]     0.0    0.00    0.00       1         ObjectManager::getPathSet() <cycle 1> [63]
                0.00    0.00       1/1           PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.00    0.00       1/1           LinkFncContainer::LinkFncContainer(StarNetwork*) [75]
                0.00    0.00       1/2           ObjectManager::getPathAlgoApp() [173]
                0.00    0.00       1/3           ObjectManager::getPathAlgoType() [171]
                0.00    0.00       1/1           ObjectManager::getPathCost() [250]
                0.00    0.00       1/5           std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [170]
                                   2             ObjectManager::getNet() <cycle 1> [168]
                                   1             ObjectManager::getODMatrix() <cycle 1> [61]
                                   1             ObjectManager::getShPath() <cycle 1> [71]
                                   1             ObjectManager::getConvMeasure() <cycle 1> [251]
                                   1             ObjectManager::getPathAlgoCreator() <cycle 1> [252]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathSet() <cycle 1> [63]
[64]     0.0    0.00    0.00       1         PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.00    0.00    7922/245582      Origin::getNextDest() [51]
                0.00    0.00    7922/253504      PairOD::getIndex() const [50]
                0.00    0.00    7922/177675      PairOD::getODIndex() const [97]
                0.00    0.00    7922/18924       Origin::getIndex() const [114]
                0.00    0.00    7922/7922        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [128]
                0.00    0.00     110/3410        Origin::beginDest() [141]
                0.00    0.00     110/3300        ODMatrix::getNextOrigin() [142]
                0.00    0.00       1/30          ODMatrix::beginOrigin() [163]
                0.00    0.00       1/1           PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [267]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getODMatrix() <cycle 1> [61]
[65]     0.0    0.00    0.00       1         ODMatrix::setIndexes(StarNetwork*) [65]
                0.00    0.00    7922/245582      Origin::getNextDest() [51]
                0.00    0.00    7922/253504      PairOD::getIndex() const [50]
                0.00    0.00    8032/8034        StarNetwork::getNodeIndex(int) [117]
                0.00    0.00    7922/7922        PairOD::getID() const [137]
                0.00    0.00    7922/7922        PairOD::setIndex(int) [134]
                0.00    0.00    7922/7922        PairOD::setODIndex(int) [132]
                0.00    0.00    7922/7922        PairOD::setOriginIndex(int) [133]
                0.00    0.00    7922/253504      PairOD::getDemand() const [91]
                0.00    0.00     110/110         Origin::getID() const [159]
                0.00    0.00     110/3410        Origin::beginDest() [141]
                0.00    0.00     110/110         Origin::setIndex(int) [155]
-----------------------------------------------
                0.00    0.00  169753/169753      AONAssignment::execute(InitialiseSolution*) [41]
[66]     0.0    0.00    0.00  169753         PathSet::initialiseItself(StarLink*, PairOD*) [66]
                0.00    0.00  169753/98803196     StarLink::getNodeToIndex() const [19]
                0.00    0.00  169753/177675      PairOD::getODIndex() const [97]
                0.00    0.00  169753/169753      ODSet::getDestIndex() const [98]
                0.00    0.00    7922/23071       Path::Path() [112]
                0.00    0.00    7922/38700       Path::setFlow(double) [107]
                0.00    0.00    7922/253504      PairOD::getDemand() const [91]
                0.00    0.00    7922/7922        ODSet::addPath(Path*) [127]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getODMatrix() <cycle 1> [61]
[67]     0.0    0.00    0.00       1         Parser::parseODMatrix(std::string const&, int) [67]
                0.00    0.00    9656/903419      StarLink::updateTime() [55]
                0.00    0.00    7922/7922        Origin::addDestination(PairOD*) [131]
                0.00    0.00    7922/7922        PairOD::PairOD(int, double) [135]
                0.00    0.00    1880/4410        Utils::skipOneLineComment(std::string, std::string) [139]
                0.00    0.00    1880/4533        Utils::removeWhiteSpaces(std::string&) [138]
                0.00    0.00     110/110         Origin::Origin(int) [156]
                0.00    0.00     110/110         ODMatrix::addOrigin(Origin*) [158]
                0.00    0.00       1/1           ODMatrix::ODMatrix(int) [270]
-----------------------------------------------
                0.00    0.00       2/2           PathSet::initialise() [34]
[68]     0.0    0.00    0.00       2         StarNetwork::calculateLinkCosts() [68]
                0.00    0.00    5044/903419      StarLink::updateTime() [55]
-----------------------------------------------
                0.00    0.00    2522/2522        Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[69]     0.0    0.00    0.00    2522         StarLink::StarLink(int, int, LinkFnc*) [69]
                0.00    0.00    2522/896285      BprFnc::evaluate(double) [48]
-----------------------------------------------
                                   1             StarNetwork::linkNodes() <cycle 1> [39]
[70]     0.0    0.00    0.00       1         StarNetwork::createIndexes() <cycle 1> [70]
                0.00    0.00    2522/1195932     StarLink::getNodeTo() const [47]
                                   1             ObjectManager::getEqAlgo() <cycle 1> [150]
-----------------------------------------------
                                   1             ObjectManager::getConvMeasure() <cycle 1> [251]
                                   1             ObjectManager::getPathSet() <cycle 1> [63]
[71]     0.0    0.00    0.00       2         ObjectManager::getShPath() <cycle 1> [71]
                0.00    0.00       1/1           ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [72]
                0.00    0.00       2/16          Params::getParam(std::string) [167]
                0.00    0.00       1/1           ShPathFactory::get() [255]
                                   1             ObjectManager::getNet() <cycle 1> [168]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getShPath() <cycle 1> [71]
[72]     0.0    0.00    0.00       1         ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [72]
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.00    0.00       6/6           bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*) [169]
-----------------------------------------------
                0.00    0.00       1/1           ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [72]
[73]     0.0    0.00    0.00       1         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.00    0.00    2522/87438819     StarNetwork::getNextLink() [16]
                0.00    0.00    2522/98803196     StarLink::getNodeToIndex() const [19]
                0.00    0.00     929/67642742     StarNode::getIsZone() [22]
                0.00    0.00     929/31981907     StarNetwork::beginLink() [29]
                0.00    0.00    2285/2285        std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&) [148]
                0.00    0.00    1020/207011      OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [93]
                0.00    0.00     929/3449        StarNode::getIndex() [140]
                0.00    0.00     929/929         StarNetwork::getNextNode() [151]
                0.00    0.00       1/2           ShPathInterface::ShPathInterface(StarNetwork*) [174]
                0.00    0.00       1/1           ShPathDijkstraSTL::ShPathDijkstraSTL(StarNetwork*) [261]
                0.00    0.00       1/1           StarNetwork::beginNode() [245]
-----------------------------------------------
                                 929             Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[74]     0.0    0.00    0.00     929         StarNetwork::addNode(StarNode*) <cycle 1> [74]
                0.00    0.00     929/1194337     StarNode::getID() [42]
                0.00    0.00     929/929         StarNode::setIndex(int) [152]
                                 929             ObjectManager::getEqAlgo() <cycle 1> [150]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathSet() <cycle 1> [63]
[75]     0.0    0.00    0.00       1         LinkFncContainer::LinkFncContainer(StarNetwork*) [75]
                0.00    0.00    2522/98004999     StarLink::getIndex() const [25]
                0.00    0.00    2522/73138       StarNetwork::getNextOnlyLink() [101]
                0.00    0.00    2522/343091      StarLink::getLinkFnc() const [90]
                0.00    0.00       1/7925        StarNetwork::getNbLinks() [118]
                0.00    0.00       1/29          StarNetwork::beginOnlyLink() [164]
-----------------------------------------------
                0.00    0.00       2/2           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [78]
[76]     0.0    0.00    0.00       2         boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [76]
                0.00    0.00       4/821627      void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [23]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[77]     0.0    0.00    0.00       1         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [77]
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [78]
-----------------------------------------------
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [77]
[78]     0.0    0.00    0.00       1         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [78]
                0.00    0.00       2/2           boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [76]
                0.00    0.00       1/1           std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [273]
                0.00    0.00       1/1           ShPathDijkstraSTL::~ShPathDijkstraSTL() [262]
                0.00    0.00       1/2           ShPathInterface::~ShPathInterface() [175]
-----------------------------------------------
                                                 <spontaneous>
[79]     0.0    0.00    0.00                 ObjectManager::~ObjectManager() [79]
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [77]
                0.00    0.00       1/1           StarNetwork::~StarNetwork() [247]
                0.00    0.00       1/1           ODMatrix::~ODMatrix() [271]
                0.00    0.00       1/1           PathBasedAlgo::~PathBasedAlgo() [254]
                0.00    0.00       1/1           LinkFncContainer::~LinkFncContainer() [260]
                0.00    0.00       1/1           RelGap::~RelGap() [266]
                0.00    0.00       1/1           PathSet::~PathSet() [268]
                0.00    0.00       1/1           AdditivePC::~AdditivePC() [244]
                0.00    0.00       1/1           PathAlgoCreator::~PathAlgoCreator() [259]
-----------------------------------------------
                0.00    0.00    5044/1540273     Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00  136188/1540273     RelGap::isConverged() [10]
                0.00    0.00  340569/1540273     PathDerivative::calculate(Path*, Path*) [37]
                0.00    0.00 1058472/1540273     ODSet::projectPathFlowOnLinks() [30]
[85]     0.0    0.00    0.00 1540273         StarLink::getFlow() const [85]
-----------------------------------------------
                0.00    0.00   30778/1232181     PathBasedFlowMovePE::executeFlowMove() [52]
                0.00    0.00   46151/1232181     ODSet::removeUnusedPaths() [111]
                0.00    0.00   96780/1232181     ODSet::equilibrate() [27]
                0.00    0.00 1058472/1232181     ODSet::projectPathFlowOnLinks() [30]
[86]     0.0    0.00    0.00 1232181         Path::getFlow() const [86]
-----------------------------------------------
                0.00    0.00 1058472/1058472     ODSet::projectPathFlowOnLinks() [30]
[87]     0.0    0.00    0.00 1058472         Path::getPrevFlow() const [87]
-----------------------------------------------
                0.00    0.00   15389/869785      DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
                0.00    0.00   15389/869785      PathBasedFlowMovePE::executeFlowMove() [52]
                0.00    0.00  839007/869785      ODSet::calculateProjectedDirection() [35]
[88]     0.0    0.00    0.00  869785         PathAndDirection::getDirectionValue() const [88]
-----------------------------------------------
                0.00    0.00  169753/592142      AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00  422389/592142      ODSet::improveSet() [3]
[89]     0.0    0.00    0.00  592142         Path::addLinkToPath(StarLink*) [89]
-----------------------------------------------
                0.00    0.00    2522/343091      LinkFncContainer::LinkFncContainer(StarNetwork*) [75]
                0.00    0.00  340569/343091      PathDerivative::calculate(Path*, Path*) [37]
[90]     0.0    0.00    0.00  343091         StarLink::getLinkFnc() const [90]
-----------------------------------------------
                0.00    0.00    7922/253504      ODMatrix::setIndexes(StarNetwork*) [65]
                0.00    0.00    7922/253504      AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00    7922/253504      PathSet::initialiseItself(StarLink*, PairOD*) [66]
                0.00    0.00   15844/253504      Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00  213894/253504      RelGap::getMinTravelTime() [11]
[91]     0.0    0.00    0.00  253504         PairOD::getDemand() const [91]
-----------------------------------------------
                0.00    0.00   15149/231088      ODSet::improveSet() [3]
                0.00    0.00  215939/231088      ODSet::updateSet() [24]
[92]     0.0    0.00    0.00  231088         Path::setCurrCost(double) [92]
-----------------------------------------------
                0.00    0.00      19/207011      ShPathDijkstraSTL::calculate(int, int) [13]
                0.00    0.00    1020/207011      ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.00    0.00  205972/207011      ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[93]     0.0    0.00    0.00  207011         OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [93]
-----------------------------------------------
                0.00    0.00  205972/205972      PathBasedAlgo::execute() [1]
[94]     0.0    0.00    0.00  205972         EquilibrationI::executeMainLoop(ODSet*) [94]
-----------------------------------------------
                0.00    0.00  205972/205972      PathBasedAlgo::execute() [1]
[95]     0.0    0.00    0.00  205972         PathSet::getNextSet() [95]
-----------------------------------------------
                0.00    0.00  190823/190823      PathBasedAlgo::mainLoop(ODSet*) [2]
[96]     0.0    0.00    0.00  190823         ODSet::getNbPaths() const [96]
-----------------------------------------------
                0.00    0.00    7922/177675      PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.00    0.00  169753/177675      PathSet::initialiseItself(StarLink*, PairOD*) [66]
[97]     0.0    0.00    0.00  177675         PairOD::getODIndex() const [97]
-----------------------------------------------
                0.00    0.00  169753/169753      PathSet::initialiseItself(StarLink*, PairOD*) [66]
[98]     0.0    0.00    0.00  169753         ODSet::getDestIndex() const [98]
-----------------------------------------------
                0.00    0.00   15844/166196      ODSet::addPath(Path*) [127]
                0.00    0.00   30298/166196      ODSet::improveSet() [3]
                0.00    0.00  120054/166196      DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [110]
[99]     0.0    0.00    0.00  166196         Path::getCurrCost() const [99]
-----------------------------------------------
                0.00    0.00   30778/123112      Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.00    0.00   30778/123112      ODSet::calculateProjectedDirection() [35]
                0.00    0.00   30778/123112      DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
                0.00    0.00   30778/123112      PathBasedFlowMovePE::executeFlowMove() [52]
[100]    0.0    0.00    0.00  123112         PathAndDirection::getPath() const [100]
-----------------------------------------------
                0.00    0.00    2522/73138       Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00    2522/73138       LinkFncContainer::LinkFncContainer(StarNetwork*) [75]
                0.00    0.00   68094/73138       RelGap::isConverged() [10]
[101]    0.0    0.00    0.00   73138         StarNetwork::getNextOnlyLink() [101]
-----------------------------------------------
                0.00    0.00   30778/61556       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [110]
                0.00    0.00   30778/61556       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
[102]    0.0    0.00    0.00   61556         PathAndDirection::setDirection(double) [102]
-----------------------------------------------
                0.00    0.00   30778/61556       Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.00    0.00   30778/61556       ODSet::calculateProjectedDirection() [35]
[103]    0.0    0.00    0.00   61556         PathBasedFlowMove::getNextPathDirection() [103]
-----------------------------------------------
                0.00    0.00   48390/48390       ODSet::equilibrate() [27]
[104]    0.0    0.00    0.00   48390         Path::setPrevFlow(double) [104]
-----------------------------------------------
                0.00    0.00   46548/46548       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [110]
[105]    0.0    0.00    0.00   46548         PathAndDirection::PathAndDirection() [105]
-----------------------------------------------
                0.00    0.00    6308/46548       DescDirectionPathScaled::~DescDirectionPathScaled() [126]
                0.00    0.00   15770/46548       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [110]
                0.00    0.00   24470/46548       PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [32]
[106]    0.0    0.00    0.00   46548         PathAndDirection::~PathAndDirection() [106]
-----------------------------------------------
                0.00    0.00    7922/38700       PathSet::initialiseItself(StarLink*, PairOD*) [66]
                0.00    0.00   30778/38700       PathBasedFlowMovePE::executeFlowMove() [52]
[107]    0.0    0.00    0.00   38700         Path::setFlow(double) [107]
-----------------------------------------------
                0.00    0.00   30778/30778       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [110]
[108]    0.0    0.00    0.00   30778         PathAndDirection::setPath(Path*) [108]
-----------------------------------------------
                0.00    0.00   15389/30778       Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [56]
                0.00    0.00   15389/30778       ODSet::calculateProjectedDirection() [35]
[109]    0.0    0.00    0.00   30778         PathBasedFlowMove::beginPathDirection() [109]
-----------------------------------------------
                0.00    0.00   23274/23274       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
[110]    0.0    0.00    0.00   23274         DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [110]
                0.00    0.00  120054/166196      Path::getCurrCost() const [99]
                0.00    0.00   46548/46548       PathAndDirection::PathAndDirection() [105]
                0.00    0.00   30778/30778       PathAndDirection::setPath(Path*) [108]
                0.00    0.00   30778/61556       PathAndDirection::setDirection(double) [102]
                0.00    0.00   15770/46548       PathAndDirection::~PathAndDirection() [106]
-----------------------------------------------
                0.00    0.00   23274/23274       PathBasedAlgo::mainLoop(ODSet*) [2]
[111]    0.0    0.00    0.00   23274         ODSet::removeUnusedPaths() [111]
                0.00    0.00   46151/1232181     Path::getFlow() const [86]
                0.00    0.00   14612/23071       Path::~Path() [113]
-----------------------------------------------
                0.00    0.00    7922/23071       PathSet::initialiseItself(StarLink*, PairOD*) [66]
                0.00    0.00   15149/23071       ODSet::improveSet() [3]
[112]    0.0    0.00    0.00   23071         Path::Path() [112]
-----------------------------------------------
                0.00    0.00    8459/23071       ODSet::~ODSet() [130]
                0.00    0.00   14612/23071       ODSet::removeUnusedPaths() [111]
[113]    0.0    0.00    0.00   23071         Path::~Path() [113]
-----------------------------------------------
                0.00    0.00     110/18924       AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00    2970/18924       RelGap::getMinTravelTime() [11]
                0.00    0.00    7922/18924       Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00    7922/18924       PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
[114]    0.0    0.00    0.00   18924         Origin::getIndex() const [114]
-----------------------------------------------
                0.00    0.00   15389/15389       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
[115]    0.0    0.00    0.00   15389         PathDerivative::PathDerivative(int) [115]
-----------------------------------------------
                0.00    0.00   15389/15389       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [36]
[116]    0.0    0.00    0.00   15389         PathDerivative::~PathDerivative() [116]
-----------------------------------------------
                0.00    0.00       2/8034        StarNetwork::linkNodes() <cycle 1> [39]
                0.00    0.00    8032/8034        ODMatrix::setIndexes(StarNetwork*) [65]
[117]    0.0    0.00    0.00    8034         StarNetwork::getNodeIndex(int) [117]
-----------------------------------------------
                0.00    0.00       1/7925        ObjectManager::getPathAlgoCreator() <cycle 1> [252]
                0.00    0.00       1/7925        LinkFncContainer::LinkFncContainer(StarNetwork*) [75]
                0.00    0.00       1/7925        PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [267]
                0.00    0.00    7922/7925        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [128]
[118]    0.0    0.00    0.00    7925         StarNetwork::getNbLinks() [118]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [128]
[119]    0.0    0.00    0.00    7922         PathAlgoCreator::allocateDescDirectionPath() [119]
                0.00    0.00    7922/7922        DescDirectionPathPE::DescDirectionPathPE(double) [121]
                0.00    0.00    7922/7922        DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double) [125]
-----------------------------------------------
                0.00    0.00    7922/7922        PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [123]
[120]    0.0    0.00    0.00    7922         PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*) [120]
-----------------------------------------------
                0.00    0.00    7922/7922        PathAlgoCreator::allocateDescDirectionPath() [119]
[121]    0.0    0.00    0.00    7922         DescDirectionPathPE::DescDirectionPathPE(double) [121]
-----------------------------------------------
                0.00    0.00    7922/7922        DescDirectionPathScaled::~DescDirectionPathScaled() [126]
[122]    0.0    0.00    0.00    7922         DescDirectionPathPE::~DescDirectionPathPE() [122]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [128]
[123]    0.0    0.00    0.00    7922         PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [123]
                0.00    0.00    7922/7922        PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*) [120]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::~ODSet() [130]
[124]    0.0    0.00    0.00    7922         PathBasedFlowMovePE::~PathBasedFlowMovePE() [124]
-----------------------------------------------
                0.00    0.00    7922/7922        PathAlgoCreator::allocateDescDirectionPath() [119]
[125]    0.0    0.00    0.00    7922         DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double) [125]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::~ODSet() [130]
[126]    0.0    0.00    0.00    7922         DescDirectionPathScaled::~DescDirectionPathScaled() [126]
                0.00    0.00    7922/7922        DescDirectionPathPE::~DescDirectionPathPE() [122]
                0.00    0.00    6308/46548       PathAndDirection::~PathAndDirection() [106]
-----------------------------------------------
                0.00    0.00    7922/7922        PathSet::initialiseItself(StarLink*, PairOD*) [66]
[127]    0.0    0.00    0.00    7922         ODSet::addPath(Path*) [127]
                0.00    0.00   15844/166196      Path::getCurrCost() const [99]
-----------------------------------------------
                0.00    0.00    7922/7922        PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
[128]    0.0    0.00    0.00    7922         ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [128]
                0.00    0.00    7922/7925        StarNetwork::getNbLinks() [118]
                0.00    0.00    7922/7922        PathAlgoCreator::allocateDescDirectionPath() [119]
                0.00    0.00    7922/7922        PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [123]
-----------------------------------------------
                0.00    0.00    7922/7922        PathSet::~PathSet() [269]
[129]    0.0    0.00    0.00    7922         ODSet::~ODSet() [129]
                0.00    0.00    7922/7922        ODSet::~ODSet() [130]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::~ODSet() [129]
[130]    0.0    0.00    0.00    7922         ODSet::~ODSet() [130]
                0.00    0.00    8459/23071       Path::~Path() [113]
                0.00    0.00    7922/7922        PathBasedFlowMovePE::~PathBasedFlowMovePE() [124]
                0.00    0.00    7922/7922        DescDirectionPathScaled::~DescDirectionPathScaled() [126]
-----------------------------------------------
                0.00    0.00    7922/7922        Parser::parseODMatrix(std::string const&, int) [67]
[131]    0.0    0.00    0.00    7922         Origin::addDestination(PairOD*) [131]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [65]
[132]    0.0    0.00    0.00    7922         PairOD::setODIndex(int) [132]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [65]
[133]    0.0    0.00    0.00    7922         PairOD::setOriginIndex(int) [133]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [65]
[134]    0.0    0.00    0.00    7922         PairOD::setIndex(int) [134]
-----------------------------------------------
                0.00    0.00    7922/7922        Parser::parseODMatrix(std::string const&, int) [67]
[135]    0.0    0.00    0.00    7922         PairOD::PairOD(int, double) [135]
-----------------------------------------------
                0.00    0.00    7922/7922        Origin::~Origin() [157]
[136]    0.0    0.00    0.00    7922         PairOD::~PairOD() [136]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [65]
[137]    0.0    0.00    0.00    7922         PairOD::getID() const [137]
-----------------------------------------------
                0.00    0.00       1/4533        ObjectManager::getNet() <cycle 1> [168]
                0.00    0.00       1/4533        ObjectManager::getPathAlgoType() [171]
                0.00    0.00       1/4533        ObjectManager::getPathAlgoApp() [173]
                0.00    0.00       2/4533        ObjectManager::getEqAlgo() <cycle 1> [150]
                0.00    0.00     118/4533        ParseParams::execute(Params*) [338]
                0.00    0.00    1880/4533        Parser::parseODMatrix(std::string const&, int) [67]
                0.00    0.00    2530/4533        Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[138]    0.0    0.00    0.00    4533         Utils::removeWhiteSpaces(std::string&) [138]
-----------------------------------------------
                0.00    0.00    1880/4410        Parser::parseODMatrix(std::string const&, int) [67]
                0.00    0.00    2530/4410        Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[139]    0.0    0.00    0.00    4410         Utils::skipOneLineComment(std::string, std::string) [139]
-----------------------------------------------
                0.00    0.00     929/3449        ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
                0.00    0.00    2520/3449        StarNetwork::linkNodes() <cycle 1> [39]
[140]    0.0    0.00    0.00    3449         StarNode::getIndex() [140]
-----------------------------------------------
                0.00    0.00     110/3410        ODMatrix::setIndexes(StarNetwork*) [65]
                0.00    0.00     110/3410        Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00     110/3410        AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00     110/3410        PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.00    0.00    2970/3410        RelGap::getMinTravelTime() [11]
[141]    0.0    0.00    0.00    3410         Origin::beginDest() [141]
-----------------------------------------------
                0.00    0.00     110/3300        Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00     110/3300        AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00     110/3300        PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.00    0.00    2970/3300        RelGap::getMinTravelTime() [11]
[142]    0.0    0.00    0.00    3300         ODMatrix::getNextOrigin() [142]
-----------------------------------------------
                0.00    0.00    3080/3080        ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [12]
[143]    0.0    0.00    0.00    3080         ShPathDijkstraSTL::calculate(int) [143]
-----------------------------------------------
                0.00    0.00    2522/2522        Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[144]    0.0    0.00    0.00    2522         BprFnc::BprFnc(double, double, double, double) [144]
-----------------------------------------------
                0.00    0.00    2522/2522        StarLink::~StarLink() [147]
[145]    0.0    0.00    0.00    2522         BprFnc::~BprFnc() [145]
-----------------------------------------------
                0.00    0.00    2522/2522        StarNetwork::linkNodes() <cycle 1> [39]
[146]    0.0    0.00    0.00    2522         StarLink::setNodeToIndex(int) [146]
-----------------------------------------------
                0.00    0.00    2522/2522        StarNetwork::~StarNetwork() [247]
[147]    0.0    0.00    0.00    2522         StarLink::~StarLink() [147]
                0.00    0.00    2522/2522        BprFnc::~BprFnc() [145]
-----------------------------------------------
                0.00    0.00    2285/2285        ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
[148]    0.0    0.00    0.00    2285         std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&) [148]
-----------------------------------------------
                0.00    0.00       1/2046        ObjectManager::getODMatrix() <cycle 1> [61]
                0.00    0.00       2/2046        ShPathInterface::ShPathInterface(StarNetwork*) [174]
                0.00    0.00    2043/2046        Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
[149]    0.0    0.00    0.00    2046         StarNetwork::getNbNodes() [149]
-----------------------------------------------
                                   1             StarNetwork::createIndexes() <cycle 1> [70]
                                 929             StarNetwork::addNode(StarNode*) <cycle 1> [74]
[150]    0.0    0.00    0.00     930         ObjectManager::getEqAlgo() <cycle 1> [150]
                0.00    0.00       2/16          Params::getParam(std::string) [167]
                0.00    0.00       2/4533        Utils::removeWhiteSpaces(std::string&) [138]
                0.00    0.00       1/3           ObjectManager::getPathAlgoType() [171]
                0.00    0.00       1/1           PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [253]
                                   1             ObjectManager::getPathSet() <cycle 1> [63]
-----------------------------------------------
                0.00    0.00     929/929         ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
[151]    0.0    0.00    0.00     929         StarNetwork::getNextNode() [151]
-----------------------------------------------
                0.00    0.00     929/929         StarNetwork::addNode(StarNode*) <cycle 1> [74]
[152]    0.0    0.00    0.00     929         StarNode::setIndex(int) [152]
-----------------------------------------------
                0.00    0.00     929/929         Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[153]    0.0    0.00    0.00     929         StarNode::StarNode(int, bool) [153]
-----------------------------------------------
                0.00    0.00     929/929         StarNetwork::~StarNetwork() [247]
[154]    0.0    0.00    0.00     929         StarNode::~StarNode() [154]
-----------------------------------------------
                0.00    0.00     110/110         ODMatrix::setIndexes(StarNetwork*) [65]
[155]    0.0    0.00    0.00     110         Origin::setIndex(int) [155]
-----------------------------------------------
                0.00    0.00     110/110         Parser::parseODMatrix(std::string const&, int) [67]
[156]    0.0    0.00    0.00     110         Origin::Origin(int) [156]
-----------------------------------------------
                0.00    0.00     110/110         ODMatrix::~ODMatrix() [271]
[157]    0.0    0.00    0.00     110         Origin::~Origin() [157]
                0.00    0.00    7922/7922        PairOD::~PairOD() [136]
-----------------------------------------------
                0.00    0.00     110/110         Parser::parseODMatrix(std::string const&, int) [67]
[158]    0.0    0.00    0.00     110         ODMatrix::addOrigin(Origin*) [158]
-----------------------------------------------
                0.00    0.00     110/110         ODMatrix::setIndexes(StarNetwork*) [65]
[159]    0.0    0.00    0.00     110         Origin::getID() const [159]
-----------------------------------------------
                0.00    0.00       5/71          Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
                0.00    0.00      66/71          ParseParams::execute(Params*) [338]
[160]    0.0    0.00    0.00      71         Utils::getSubString(std::string, std::string, std::string) [160]
-----------------------------------------------
                                  33             ParseParams::skipComments(std::string) [161]
                0.00    0.00      33/33          Params::addParameter(std::string, std::string) [162]
[161]    0.0    0.00    0.00      33+33      ParseParams::skipComments(std::string) [161]
                                  33             ParseParams::skipComments(std::string) [161]
-----------------------------------------------
                0.00    0.00      33/33          ParseParams::execute(Params*) [338]
[162]    0.0    0.00    0.00      33         Params::addParameter(std::string, std::string) [162]
                0.00    0.00      33/33          ParseParams::skipComments(std::string) [161]
-----------------------------------------------
                0.00    0.00       1/30          Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00       1/30          AONAssignment::execute(InitialiseSolution*) [41]
                0.00    0.00       1/30          PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
                0.00    0.00      27/30          RelGap::getMinTravelTime() [11]
[163]    0.0    0.00    0.00      30         ODMatrix::beginOrigin() [163]
-----------------------------------------------
                0.00    0.00       1/29          Utils::checkFeasibility(StarNetwork*, ODMatrix*) [62]
                0.00    0.00       1/29          LinkFncContainer::LinkFncContainer(StarNetwork*) [75]
                0.00    0.00      27/29          RelGap::isConverged() [10]
[164]    0.0    0.00    0.00      29         StarNetwork::beginOnlyLink() [164]
-----------------------------------------------
                0.00    0.00      27/27          PathBasedAlgo::execute() [1]
[165]    0.0    0.00    0.00      27         PathSet::isConverged() const [165]
-----------------------------------------------
                0.00    0.00      26/26          PathBasedAlgo::execute() [1]
[166]    0.0    0.00    0.00      26         PathSet::beginSet() [166]
-----------------------------------------------
                0.00    0.00       1/16          ObjectManager::getPathAlgoType() [171]
                0.00    0.00       1/16          ObjectManager::getPathAlgoApp() [173]
                0.00    0.00       2/16          ObjectManager::getODMatrix() <cycle 1> [61]
                0.00    0.00       2/16          ObjectManager::getShPath() <cycle 1> [71]
                0.00    0.00       2/16          ObjectManager::getEqAlgo() <cycle 1> [150]
                0.00    0.00       3/16          ObjectManager::getNet() <cycle 1> [168]
                0.00    0.00       5/16          std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [170]
[167]    0.0    0.00    0.00      16         Params::getParam(std::string) [167]
-----------------------------------------------
                                   1             ObjectManager::getODMatrix() <cycle 1> [61]
                                   1             ObjectManager::getShPath() <cycle 1> [71]
                                   1             ObjectManager::getConvMeasure() <cycle 1> [251]
                                   1             ObjectManager::getPathAlgoCreator() <cycle 1> [252]
                                   2             ObjectManager::getPathSet() <cycle 1> [63]
[168]    0.0    0.00    0.00       6         ObjectManager::getNet() <cycle 1> [168]
                0.00    0.00       3/16          Params::getParam(std::string) [167]
                0.00    0.00       1/4533        Utils::removeWhiteSpaces(std::string&) [138]
                                   1             Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
                                   1             StarNetwork::linkNodes() <cycle 1> [39]
-----------------------------------------------
                0.00    0.00       6/6           ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [72]
[169]    0.0    0.00    0.00       6         bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*) [169]
-----------------------------------------------
                0.00    0.00       1/5           ObjectManager::getConvMeasure() <cycle 1> [251]
                0.00    0.00       1/5           ObjectManager::getPathSet() <cycle 1> [63]
                0.00    0.00       3/5           ObjectManager::getPathAlgoCreator() <cycle 1> [252]
[170]    0.0    0.00    0.00       5         std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [170]
                0.00    0.00       5/16          Params::getParam(std::string) [167]
-----------------------------------------------
                0.00    0.00       1/3           ObjectManager::getPathAlgoCreator() <cycle 1> [252]
                0.00    0.00       1/3           ObjectManager::getPathSet() <cycle 1> [63]
                0.00    0.00       1/3           ObjectManager::getEqAlgo() <cycle 1> [150]
[171]    0.0    0.00    0.00       3         ObjectManager::getPathAlgoType() [171]
                0.00    0.00       1/16          Params::getParam(std::string) [167]
                0.00    0.00       1/4533        Utils::removeWhiteSpaces(std::string&) [138]
-----------------------------------------------
                0.00    0.00       3/3           Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[172]    0.0    0.00    0.00       3         Parser::checkEmptyValue(int) [172]
-----------------------------------------------
                0.00    0.00       1/2           ObjectManager::getPathAlgoCreator() <cycle 1> [252]
                0.00    0.00       1/2           ObjectManager::getPathSet() <cycle 1> [63]
[173]    0.0    0.00    0.00       2         ObjectManager::getPathAlgoApp() [173]
                0.00    0.00       1/16          Params::getParam(std::string) [167]
                0.00    0.00       1/4533        Utils::removeWhiteSpaces(std::string&) [138]
-----------------------------------------------
                0.00    0.00       1/2           ShPathDijkstraSTL::ShPathDijkstraSTL(StarNetwork*) [261]
                0.00    0.00       1/2           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
[174]    0.0    0.00    0.00       2         ShPathInterface::ShPathInterface(StarNetwork*) [174]
                0.00    0.00       2/2046        StarNetwork::getNbNodes() [149]
-----------------------------------------------
                0.00    0.00       1/2           ShPathDijkstraSTL::~ShPathDijkstraSTL() [262]
                0.00    0.00       1/2           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [78]
[175]    0.0    0.00    0.00       2         ShPathInterface::~ShPathInterface() [175]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[176]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10AdditivePCC2Ev [176]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[177]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10AlgorithmB9zeroFlow_E [177]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[178]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10DerivativeC2EdP16LinkFncContainer [178]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[179]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10FileReaderC2ERKSs [179]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[180]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10FileWriterC2ERKSs [180]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[181]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10OriginBush15wasInitialised_E [181]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[182]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11DAGraphLUCEC2EP11StarNetworkP8ODMatrixddi [182]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[183]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11DAGraphNodeC2Eid [183]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[184]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11MarginalFncC2EP7LinkFnc [184]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[185]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11ParseParamsC2ESs [185]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[186]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11StarNetworkC2EiiRSs [186]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[187]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11StepSizeAddC2EP13DescDirectionidP10LineSearchP10Derivative [187]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[188]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN12LinkFlowsBFW14allocateMemoryEv [188]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[189]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN12LinkFlowsCFW14allocateMemoryEv [189]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[190]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13AONAssignmentC2EP8ODMatrixP12ShortestPath [190]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[191]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13NonAdditivePCC2Ev [191]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[192]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13ObjectManagerC2EP6Params [192]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[193]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13PathBasedAlgoC2EP7PathSetb [193]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[194]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13ShPathFactoryC2Ev [194]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[195]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13SpiessFncCombC2EP9SpiessFncS1_ [195]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[196]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14EquilibrationIC2EP13PathBasedAlgo [196]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[197]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14OriginBushLUCEC2EiP11StarNetwork [197]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[198]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14PathDerivativeC2Ei [198]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[199]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14StepSizeNonAddC2EP13DescDirectionidP10LineSearchP10Derivative [199]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[200]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN15EquilibrationIIC2EP13PathBasedAlgo [200]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[201]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN15OriginBasedAlgoC2EP9OriginSet [201]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[202]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN15PathAlgoCreatorC2E12PathAlgoType7PathAppiddd [202]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[203]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16LinkFncContainerC2EP11StarNetwork [203]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[204]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16PathAndDirectionC2Ev [204]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[205]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16SpiessFncCreatorC2Ev [205]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[206]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16StepSizeSparsityC2EP8StepSize [206]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[207]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN17LabelCorrectingAlC2EP11StarNetwork [207]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[208]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN17OnePathDerivativeC2Ed [208]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[209]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN17PathBasedFlowMoveC2EP17DescDirectionPath [209]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[210]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19DescDirectionPathGPC2Ed [210]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[211]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19DescDirectionPathPEC2Ed [211]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[212]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19DescDirectionPathPGC2Ed [212]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[213]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19PathBasedFlowMoveGPC2EddP17DescDirectionPath [213]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[214]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19PathBasedFlowMovePEC2EP17DescDirectionPath [214]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[215]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN20DescDirectionPathISPC2Eddd [215]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[216]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN23DescDirectionPathScaledC2EP17DescDirectionPathid [216]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[217]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN25PathBasedFlowMoveWithStepC2EP11StepSizeABCP17DescDirectionPath [217]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[218]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN4PathC2Ev [218]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[219]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN5ODSet16initialiseObjectEiiiP8PathCostP16LinkFncContainerP11StarNetworkP12ShortestPathP11ConvMeasuredPdSA_P15PathAlgoCreator [219]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[220]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN5Utils16getDisjointLinksEP4PathS1_RSt4listIP8StarLinkSaIS4_EEi [220]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[221]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN5Utils17removeWhiteSpacesERSs [221]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[222]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6ArmijoC2EdP10Derivative [222]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[223]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6BprFncC2Edddd [223]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[224]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6FWAlgoC2EP9LinkFlows [224]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[225]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6OriginC2Ei [225]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[226]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6PairODC2Eid [226]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[227]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6ParamsC2Ev [227]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[228]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6ParserC2Ev [228]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[229]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6RelGapC2EdP11StarNetworkP8ODMatrixP12ShortestPath [229]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[230]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN7DAGraph4net_E [230]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[231]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN7PathSet16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP11ConvMeasureP8PathCost [231]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[232]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN7QuadAppC2EP10Derivative [232]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[233]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8ConstFncC2Ed [233]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[234]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8ODMatrixC2Ei [234]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[235]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8StarLinkC2EiiP7LinkFnc [235]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[236]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8StepSizeC2EP13DescDirectionidP10LineSearch [236]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[237]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9BisectionC2EdP10Derivative [237]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[238]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9LinearFncC2Edd [238]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[239]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9LinkFlows16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP10DerivativeP10LineSearchP11ConvMeasure [239]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[240]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9OriginSetC2EP8ODMatrixP11StarNetworkP12ShortestPathP11ConvMeasureddb [240]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[241]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9SpiessFncC2Eddddd [241]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [815]
[242]    0.0    0.00    0.00       1         _GLOBAL__sub_I_main [242]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathCost() [250]
[243]    0.0    0.00    0.00       1         AdditivePC::AdditivePC() [243]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[244]    0.0    0.00    0.00       1         AdditivePC::~AdditivePC() [244]
-----------------------------------------------
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
[245]    0.0    0.00    0.00       1         StarNetwork::beginNode() [245]
-----------------------------------------------
                0.00    0.00       1/1           Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[246]    0.0    0.00    0.00       1         StarNetwork::StarNetwork(int, int, std::string&) [246]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[247]    0.0    0.00    0.00       1         StarNetwork::~StarNetwork() [247]
                0.00    0.00    2522/2522        StarLink::~StarLink() [147]
                0.00    0.00     929/929         StarNode::~StarNode() [154]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::initialise() [34]
[248]    0.0    0.00    0.00       1         AONAssignment::AONAssignment(ODMatrix*, ShortestPath*) [248]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::initialise() [34]
[249]    0.0    0.00    0.00       1         AONAssignment::~AONAssignment() [249]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathSet() <cycle 1> [63]
[250]    0.0    0.00    0.00       1         ObjectManager::getPathCost() [250]
                0.00    0.00       1/1           AdditivePC::AdditivePC() [243]
-----------------------------------------------
                                   1             ObjectManager::getPathSet() <cycle 1> [63]
[251]    0.0    0.00    0.00       1         ObjectManager::getConvMeasure() <cycle 1> [251]
                0.00    0.00       1/5           std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [170]
                0.00    0.00       1/1           RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*) [265]
                                   1             ObjectManager::getNet() <cycle 1> [168]
                                   1             ObjectManager::getODMatrix() <cycle 1> [61]
                                   1             ObjectManager::getShPath() <cycle 1> [71]
-----------------------------------------------
                                   1             ObjectManager::getPathSet() <cycle 1> [63]
[252]    0.0    0.00    0.00       1         ObjectManager::getPathAlgoCreator() <cycle 1> [252]
                0.00    0.00       3/5           std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [170]
                0.00    0.00       1/3           ObjectManager::getPathAlgoType() [171]
                0.00    0.00       1/7925        StarNetwork::getNbLinks() [118]
                0.00    0.00       1/2           ObjectManager::getPathAlgoApp() [173]
                0.00    0.00       1/1           PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double) [258]
                                   1             ObjectManager::getNet() <cycle 1> [168]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getEqAlgo() <cycle 1> [150]
[253]    0.0    0.00    0.00       1         PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [253]
                0.00    0.00       1/1           EquilibrationI::EquilibrationI(PathBasedAlgo*) [256]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[254]    0.0    0.00    0.00       1         PathBasedAlgo::~PathBasedAlgo() [254]
                0.00    0.00       1/1           EquilibrationI::~EquilibrationI() [257]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getShPath() <cycle 1> [71]
[255]    0.0    0.00    0.00       1         ShPathFactory::get() [255]
-----------------------------------------------
                0.00    0.00       1/1           PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [253]
[256]    0.0    0.00    0.00       1         EquilibrationI::EquilibrationI(PathBasedAlgo*) [256]
-----------------------------------------------
                0.00    0.00       1/1           PathBasedAlgo::~PathBasedAlgo() [254]
[257]    0.0    0.00    0.00       1         EquilibrationI::~EquilibrationI() [257]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathAlgoCreator() <cycle 1> [252]
[258]    0.0    0.00    0.00       1         PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double) [258]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[259]    0.0    0.00    0.00       1         PathAlgoCreator::~PathAlgoCreator() [259]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[260]    0.0    0.00    0.00       1         LinkFncContainer::~LinkFncContainer() [260]
-----------------------------------------------
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [73]
[261]    0.0    0.00    0.00       1         ShPathDijkstraSTL::ShPathDijkstraSTL(StarNetwork*) [261]
                0.00    0.00       1/2           ShPathInterface::ShPathInterface(StarNetwork*) [174]
-----------------------------------------------
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [78]
[262]    0.0    0.00    0.00       1         ShPathDijkstraSTL::~ShPathDijkstraSTL() [262]
                0.00    0.00       1/2           ShPathInterface::~ShPathInterface() [175]
-----------------------------------------------
                0.00    0.00       1/1           Parser::parseNetwork(std::string const&, bool) <cycle 1> [45]
[263]    0.0    0.00    0.00       1         Utils::extractName(char const*, std::string&) [263]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::ObjectManager(Params*) [431]
[264]    0.0    0.00    0.00       1         Parser::Parser() [264]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getConvMeasure() <cycle 1> [251]
[265]    0.0    0.00    0.00       1         RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*) [265]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[266]    0.0    0.00    0.00       1         RelGap::~RelGap() [266]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [64]
[267]    0.0    0.00    0.00       1         PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [267]
                0.00    0.00       1/1           ODMatrix::getNbODPairs() const [272]
                0.00    0.00       1/7925        StarNetwork::getNbLinks() [118]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[268]    0.0    0.00    0.00       1         PathSet::~PathSet() [268]
                0.00    0.00       1/1           PathSet::~PathSet() [269]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::~PathSet() [268]
[269]    0.0    0.00    0.00       1         PathSet::~PathSet() [269]
                0.00    0.00    7922/7922        ODSet::~ODSet() [129]
-----------------------------------------------
                0.00    0.00       1/1           Parser::parseODMatrix(std::string const&, int) [67]
[270]    0.0    0.00    0.00       1         ODMatrix::ODMatrix(int) [270]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [79]
[271]    0.0    0.00    0.00       1         ODMatrix::~ODMatrix() [271]
                0.00    0.00     110/110         Origin::~Origin() [157]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [267]
[272]    0.0    0.00    0.00       1         ODMatrix::getNbODPairs() const [272]
-----------------------------------------------
                                  55             std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [273]
                0.00    0.00       1/1           ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [78]
[273]    0.0    0.00    0.00       1+55      std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [273]
                                  55             std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [273]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.


Index by function name

 [176] _GLOBAL__sub_I__ZN10AdditivePCC2Ev (AdditivePC.cpp) [248] AONAssignment::AONAssignment(ODMatrix*, ShortestPath*) [49] BprFnc::evaluateDerivative(double)
 [177] _GLOBAL__sub_I__ZN10AlgorithmB9zeroFlow_E (AlgorithmB.cpp) [249] AONAssignment::~AONAssignment() [48] BprFnc::evaluate(double)
 [178] _GLOBAL__sub_I__ZN10DerivativeC2EdP16LinkFncContainer (Derivative.cpp) [63] ObjectManager::getPathSet() [144] BprFnc::BprFnc(double, double, double, double)
 [179] _GLOBAL__sub_I__ZN10FileReaderC2ERKSs (FileReader.cpp) [61] ObjectManager::getODMatrix() [145] BprFnc::~BprFnc()
 [180] _GLOBAL__sub_I__ZN10FileWriterC2ERKSs (FileWriter.cpp) [250] ObjectManager::getPathCost() [54] BprFnc::~BprFnc()
 [181] _GLOBAL__sub_I__ZN10OriginBush15wasInitialised_E (OriginBush.cpp) [251] ObjectManager::getConvMeasure() [51] Origin::getNextDest()
 [182] _GLOBAL__sub_I__ZN11DAGraphLUCEC2EP11StarNetworkP8ODMatrixddi (DAGraphLUCE.cpp) [173] ObjectManager::getPathAlgoApp() [131] Origin::addDestination(PairOD*)
 [183] _GLOBAL__sub_I__ZN11DAGraphNodeC2Eid (DAGraphNode.cpp) [171] ObjectManager::getPathAlgoType() [155] Origin::setIndex(int)
 [184] _GLOBAL__sub_I__ZN11MarginalFncC2EP7LinkFnc (MarginalFnc.cpp) [252] ObjectManager::getPathAlgoCreator() [141] Origin::beginDest()
 [185] _GLOBAL__sub_I__ZN11ParseParamsC2ESs (ParseParams.cpp) [168] ObjectManager::getNet() [156] Origin::Origin(int)
 [186] _GLOBAL__sub_I__ZN11StarNetworkC2EiiRSs (StarNetwork.cpp) [150] ObjectManager::getEqAlgo() [157] Origin::~Origin()
 [187] _GLOBAL__sub_I__ZN11StepSizeAddC2EP13DescDirectionidP10LineSearchP10Derivative (StepSizeAdd.cpp) [71] ObjectManager::getShPath() [132] PairOD::setODIndex(int)
 [188] _GLOBAL__sub_I__ZN12LinkFlowsBFW14allocateMemoryEv (LinkFlowsBFW.cpp) [2] PathBasedAlgo::mainLoop(ODSet*) [133] PairOD::setOriginIndex(int)
 [189] _GLOBAL__sub_I__ZN12LinkFlowsCFW14allocateMemoryEv (LinkFlowsCFW.cpp) [253] PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [134] PairOD::setIndex(int)
 [190] _GLOBAL__sub_I__ZN13AONAssignmentC2EP8ODMatrixP12ShortestPath (AONAssignment.cpp) [254] PathBasedAlgo::~PathBasedAlgo() [135] PairOD::PairOD(int, double)
 [191] _GLOBAL__sub_I__ZN13NonAdditivePCC2Ev (NonAdditivePC.cpp) [255] ShPathFactory::get() [136] PairOD::~PairOD()
 [192] _GLOBAL__sub_I__ZN13ObjectManagerC2EP6Params (ObjectManager.cpp) [72] ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [162] Params::addParameter(std::string, std::string)
 [193] _GLOBAL__sub_I__ZN13PathBasedAlgoC2EP7PathSetb (PathBasedAlgo.cpp) [94] EquilibrationI::executeMainLoop(ODSet*) [167] Params::getParam(std::string)
 [194] _GLOBAL__sub_I__ZN13ShPathFactoryC2Ev (ShPathFactory.cpp) [256] EquilibrationI::EquilibrationI(PathBasedAlgo*) [45] Parser::parseNetwork(std::string const&, bool)
 [195] _GLOBAL__sub_I__ZN13SpiessFncCombC2EP9SpiessFncS1_ (SpiessFncComb.cpp) [257] EquilibrationI::~EquilibrationI() [67] Parser::parseODMatrix(std::string const&, int)
 [196] _GLOBAL__sub_I__ZN14EquilibrationIC2EP13PathBasedAlgo (EquilibrationI.cpp) [93] OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [172] Parser::checkEmptyValue(int)
 [197] _GLOBAL__sub_I__ZN14OriginBushLUCEC2EiP11StarNetwork (OriginBushLUCE.cpp) [37] PathDerivative::calculate(Path*, Path*) [264] Parser::Parser()
 [198] _GLOBAL__sub_I__ZN14PathDerivativeC2Ei (PathDerivative.cpp) [115] PathDerivative::PathDerivative(int) [10] RelGap::isConverged()
 [199] _GLOBAL__sub_I__ZN14StepSizeNonAddC2EP13DescDirectionidP10LineSearchP10Derivative (StepSizeNonAdd.cpp) [116] PathDerivative::~PathDerivative() [11] RelGap::getMinTravelTime()
 [200] _GLOBAL__sub_I__ZN15EquilibrationIIC2EP13PathBasedAlgo (EquilibrationII.cpp) [119] PathAlgoCreator::allocateDescDirectionPath() [265] RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*)
 [201] _GLOBAL__sub_I__ZN15OriginBasedAlgoC2EP9OriginSet (OriginBasedAlgo.cpp) [258] PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double) [266] RelGap::~RelGap()
 [202] _GLOBAL__sub_I__ZN15PathAlgoCreatorC2E12PathAlgoType7PathAppiddd (PathAlgoCreator.cpp) [259] PathAlgoCreator::~PathAlgoCreator() [95] PathSet::getNextSet()
 [203] _GLOBAL__sub_I__ZN16LinkFncContainerC2EP11StarNetwork (LinkFncContainer.cpp) [174] ShPathInterface::ShPathInterface(StarNetwork*) [34] PathSet::initialise()
 [204] _GLOBAL__sub_I__ZN16PathAndDirectionC2Ev (PathAndDirection.cpp) [175] ShPathInterface::~ShPathInterface() [66] PathSet::initialiseItself(StarLink*, PairOD*)
 [205] _GLOBAL__sub_I__ZN16SpiessFncCreatorC2Ev (SpiessFncCreator.cpp) [75] LinkFncContainer::LinkFncContainer(StarNetwork*) [267] PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*)
 [206] _GLOBAL__sub_I__ZN16StepSizeSparsityC2EP8StepSize (StepSizeSparsity.cpp) [260] LinkFncContainer::~LinkFncContainer() [166] PathSet::beginSet()
 [207] _GLOBAL__sub_I__ZN17LabelCorrectingAlC2EP11StarNetwork (LabelCorrectingAl.cpp) [102] PathAndDirection::setDirection(double) [64] PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*)
 [208] _GLOBAL__sub_I__ZN17OnePathDerivativeC2Ed (OnePathDerivative.cpp) [108] PathAndDirection::setPath(Path*) [268] PathSet::~PathSet()
 [209] _GLOBAL__sub_I__ZN17PathBasedFlowMoveC2EP17DescDirectionPath (PathBasedFlowMove.cpp) [105] PathAndDirection::PathAndDirection() [269] PathSet::~PathSet()
 [210] _GLOBAL__sub_I__ZN19DescDirectionPathGPC2Ed (DescDirectionPathGP.cpp) [106] PathAndDirection::~PathAndDirection() [65] ODMatrix::setIndexes(StarNetwork*)
 [211] _GLOBAL__sub_I__ZN19DescDirectionPathPEC2Ed (DescDirectionPathPE.cpp) [109] PathBasedFlowMove::beginPathDirection() [163] ODMatrix::beginOrigin()
 [212] _GLOBAL__sub_I__ZN19DescDirectionPathPGC2Ed (DescDirectionPathPG.cpp) [103] PathBasedFlowMove::getNextPathDirection() [142] ODMatrix::getNextOrigin()
 [213] _GLOBAL__sub_I__ZN19PathBasedFlowMoveGPC2EddP17DescDirectionPath (PathBasedFlowMoveGP.cpp) [32] PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [158] ODMatrix::addOrigin(Origin*)
 [214] _GLOBAL__sub_I__ZN19PathBasedFlowMovePEC2EP17DescDirectionPath (PathBasedFlowMovePE.cpp) [120] PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*) [270] ODMatrix::ODMatrix(int)
 [215] _GLOBAL__sub_I__ZN20DescDirectionPathISPC2Eddd (DescDirectionPathISP.cpp) [143] ShPathDijkstraSTL::calculate(int) [271] ODMatrix::~ODMatrix()
 [216] _GLOBAL__sub_I__ZN23DescDirectionPathScaledC2EP17DescDirectionPathid (DescDirectionPathScaled.cpp) [13] ShPathDijkstraSTL::calculate(int, int) [55] StarLink::updateTime()
 [217] _GLOBAL__sub_I__ZN25PathBasedFlowMoveWithStepC2EP11StepSizeABCP17DescDirectionPath (PathBasedFlowMoveWithStep.cpp) [261] ShPathDijkstraSTL::ShPathDijkstraSTL(StarNetwork*) [146] StarLink::setNodeToIndex(int)
 [218] _GLOBAL__sub_I__ZN4PathC2Ev (Path.cpp) [262] ShPathDijkstraSTL::~ShPathDijkstraSTL() [59] StarLink::setNodeFromIndex(int)
 [219] _GLOBAL__sub_I__ZN5ODSet16initialiseObjectEiiiP8PathCostP16LinkFncContainerP11StarNetworkP12ShortestPathP11ConvMeasuredPdSA_P15PathAlgoCreator (ODSet.cpp) [110] DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [44] StarLink::addFlow(double)
 [220] _GLOBAL__sub_I__ZN5Utils16getDisjointLinksEP4PathS1_RSt4listIP8StarLinkSaIS4_EEi (Utils.cpp) [121] DescDirectionPathPE::DescDirectionPathPE(double) [46] StarLink::setFlow(double)
 [221] _GLOBAL__sub_I__ZN5Utils17removeWhiteSpacesERSs (UtilsString.cpp) [122] DescDirectionPathPE::~DescDirectionPathPE() [60] StarLink::setIndex(int)
 [222] _GLOBAL__sub_I__ZN6ArmijoC2EdP10Derivative (Armijo.cpp) [52] PathBasedFlowMovePE::executeFlowMove() [69] StarLink::StarLink(int, int, LinkFnc*)
 [223] _GLOBAL__sub_I__ZN6BprFncC2Edddd (BprFnc.cpp) [123] PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [147] StarLink::~StarLink()
 [224] _GLOBAL__sub_I__ZN6FWAlgoC2EP9LinkFlows (FWAlgo.cpp) [124] PathBasedFlowMovePE::~PathBasedFlowMovePE() [42] StarNode::getID()
 [225] _GLOBAL__sub_I__ZN6OriginC2Ei (Origin.cpp) [9] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [140] StarNode::getIndex()
 [226] _GLOBAL__sub_I__ZN6PairODC2Eid (PairOD.cpp) [5] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [152] StarNode::setIndex(int)
 [227] _GLOBAL__sub_I__ZN6ParamsC2Ev (Params.cpp) [6] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [22] StarNode::getIsZone()
 [228] _GLOBAL__sub_I__ZN6ParserC2Ev (Parser.cpp) [12] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [153] StarNode::StarNode(int, bool)
 [229] _GLOBAL__sub_I__ZN6RelGapC2EdP11StarNetworkP8ODMatrixP12ShortestPath (RelGap.cpp) [4] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [154] StarNode::~StarNode()
 [230] _GLOBAL__sub_I__ZN7DAGraph4net_E (DAGraph.cpp) [73] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathDijkstraBidirect(StarNetwork*) [31] AdditivePC::calculate(Path*) const
 [231] _GLOBAL__sub_I__ZN7PathSet16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP11ConvMeasureP8PathCost (PathSet.cpp) [77] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [57] ShPathInterface::getInComeLink(int) const
 [232] _GLOBAL__sub_I__ZN7QuadAppC2EP10Derivative (QuadApp.cpp) [78] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathDijkstraBidirect() [58] ShPathInterface::getCost(int) const
 [233] _GLOBAL__sub_I__ZN8ConstFncC2Ed (ConstFnc.cpp) [36] DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [88] PathAndDirection::getDirectionValue() const
 [234] _GLOBAL__sub_I__ZN8ODMatrixC2Ei (ODMatrix.cpp) [125] DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double) [100] PathAndDirection::getPath() const
 [235] _GLOBAL__sub_I__ZN8StarLinkC2EiiP7LinkFnc (StarLink.cpp) [126] DescDirectionPathScaled::~DescDirectionPathScaled() [99] Path::getCurrCost() const
 [236] _GLOBAL__sub_I__ZN8StepSizeC2EP13DescDirectionidP10LineSearch (StepSize.cpp) [92] Path::setCurrCost(double) [28] Path::getNextLink() const
 [237] _GLOBAL__sub_I__ZN9BisectionC2EdP10Derivative (Bisection.cpp) [104] Path::setPrevFlow(double) [87] Path::getPrevFlow() const
 [238] _GLOBAL__sub_I__ZN9LinearFncC2Edd (LinearFnc.cpp) [89] Path::addLinkToPath(StarLink*) [86] Path::getFlow() const
 [239] _GLOBAL__sub_I__ZN9LinkFlows16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP10DerivativeP10LineSearchP11ConvMeasure (LinkFlows.cpp) [107] Path::setFlow(double) [38] Path::beginLink() const
 [240] _GLOBAL__sub_I__ZN9OriginSetC2EP8ODMatrixP11StarNetworkP12ShortestPathP11ConvMeasureddb (OriginSet.cpp) [112] Path::Path() [96] ODSet::getNbPaths() const
 [241] _GLOBAL__sub_I__ZN9SpiessFncC2Eddddd (SpiessFnc.cpp) [113] Path::~Path() [98] ODSet::getDestIndex() const
 [242] _GLOBAL__sub_I_main (main.cpp) [3] ODSet::improveSet() [159] Origin::getID() const
 [243] AdditivePC::AdditivePC() [27] ODSet::equilibrate() [114] Origin::getIndex() const
 [244] AdditivePC::~AdditivePC() [111] ODSet::removeUnusedPaths() [97] PairOD::getODIndex() const
 [161] ParseParams::skipComments(std::string) [43] ODSet::updateLinkCostsOfOD() [137] PairOD::getID() const
 [118] StarNetwork::getNbLinks() [30] ODSet::projectPathFlowOnLinks() [50] PairOD::getIndex() const
 [149] StarNetwork::getNbNodes() [35] ODSet::calculateProjectedDirection() [91] PairOD::getDemand() const
  [16] StarNetwork::getNextLink() [127] ODSet::addPath(Path*) [165] PathSet::isConverged() const
 [151] StarNetwork::getNextNode() [24] ODSet::updateSet() [272] ODMatrix::getNbODPairs() const
 [117] StarNetwork::getNodeIndex(int) [128] ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [90] StarLink::getLinkFnc() const
 [164] StarNetwork::beginOnlyLink() [129] ODSet::~ODSet() [19] StarLink::getNodeToIndex() const
  [70] StarNetwork::createIndexes() [130] ODSet::~ODSet() [14] StarLink::getNodeFromIndex() const
 [101] StarNetwork::getNextOnlyLink() [263] Utils::extractName(char const*, std::string&) [85] StarLink::getFlow() const
  [68] StarNetwork::calculateLinkCosts() [160] Utils::getSubString(std::string, std::string, std::string) [20] StarLink::getTime() const
  [53] StarNetwork::addLink(StarLink*) [56] Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [25] StarLink::getIndex() const
  [74] StarNetwork::addNode(StarNode*) [40] Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [47] StarLink::getNodeTo() const
  [26] StarNetwork::getLink(int) [138] Utils::removeWhiteSpaces(std::string&) [148] std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&)
  [29] StarNetwork::beginLink() [139] Utils::skipOneLineComment(std::string, std::string) [170] std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*)
  [17] StarNetwork::beginNode(int) [15] boost::heap::fibonacci_heap<ValueKey, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::consolidate() [273] std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*)
 [245] StarNetwork::beginNode() [23] void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [21] void std::__adjust_heap<__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize>(__gnu_cxx::__normal_iterator<std::pair<int, double>*, std::vector<std::pair<int, double>, std::allocator<std::pair<int, double> > > >, long, long, std::pair<int, double>, ShPathDijkstraSTL::Prioritize)
  [39] StarNetwork::linkNodes() [7] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [169] bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*)
 [246] StarNetwork::StarNetwork(int, int, std::string&) [8] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) (33) <cycle 1>
 [247] StarNetwork::~StarNetwork() [76] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear()
  [41] AONAssignment::execute(InitialiseSolution*) [18] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&)
