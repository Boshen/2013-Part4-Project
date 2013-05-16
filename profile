Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 52.94     49.82    49.82 110518910     0.00     0.00  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int)
 18.09     66.84    17.02 493185021     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*)
 11.32     77.49    10.65 110518910     0.00     0.00  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int)
  4.82     82.03     4.54 241948806     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&)
  2.14     84.05     2.02 272778726     0.00     0.00  StarLink::getNodeFromIndex() const
  1.63     85.58     1.53   211092     0.01     0.01  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int)
  1.43     86.93     1.35 277006721     0.00     0.00  StarNetwork::getNextLink()
  1.33     88.18     1.26 289113506     0.00     0.00  StarLink::getNodeToIndex() const
  1.03     89.15     0.97 225626151     0.00     0.00  StarNode::getIsZone()
  1.03     90.12     0.97                             boost::heap::detail::d_ary_heap<std::_List_iterator<std::pair<ValueKey, unsigned long> >, boost::parameter::aux::arg_list<boost::heap::allocator<std::allocator<ValueKey> >, boost::parameter::aux::arg_list<boost::heap::compare<boost::heap::detail::priority_queue_mutable_wrapper<boost::heap::detail::d_ary_heap<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::empty_arg_list> >, boost::heap::detail::nop_index_updater> >::indirect_cmp>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::arg_list<boost::heap::stability_counter_type<unsigned long>, boost::parameter::aux::arg_list<boost::heap::stable<false>, boost::parameter::aux::empty_arg_list> > > > >, boost::heap::detail::priority_queue_mutable_wrapper<boost::heap::detail::d_ary_heap<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::empty_arg_list> >, boost::heap::detail::nop_index_updater> >::index_updater>::pop()
  0.74     90.82     0.70 225629413     0.00     0.00  StarNetwork::beginNode(int)
  0.66     91.44     0.62 556969855     0.00     0.00  StarLink::getTime() const
  0.56     91.97     0.53 28984538     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&)
  0.35     92.30     0.33        1   330.01   623.97  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*)
  0.35     92.62     0.33 304388932     0.00     0.00  StarLink::getIndex() const
  0.30     92.90     0.28   783783     0.00     0.00  void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&)
  0.27     93.15     0.25 101390224     0.00     0.00  StarNetwork::beginLink()
  0.22     93.36     0.21   205972     0.00     0.44  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int)
  0.17     93.52     0.16     4100     0.04     0.16  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int)
  0.14     93.65     0.13  9529106     0.00     0.00  StarNetwork::getLink(int)
  0.09     93.74     0.09  1332897     0.00     0.00  StarLink::setFlow(double)
  0.09     93.82     0.08 10798368     0.00     0.00  Path::getNextLink() const
  0.06     93.88     0.06                             ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int)
  0.04     93.92     0.04  1194337     0.00     0.00  StarNode::getID()
  0.04     93.96     0.04   205972     0.00     0.00  ODSet::updateSet()
  0.03     93.99     0.03   442060     0.00     0.00  Path::beginLink() const
  0.01     94.00     0.01   926548     0.00     0.00  StarLink::updateTime()
  0.01     94.01     0.01   919414     0.00     0.00  BprFnc::evaluate(double)
  0.01     94.02     0.01   205972     0.00     0.44  ODSet::improveSet()
  0.01     94.03     0.01    23131     0.00     0.00  ODSet::equilibrate()
  0.01     94.04     0.01    23131     0.00     0.00  ODSet::removeUnusedPaths()
  0.01     94.05     0.01    15721     0.00     0.00  PathDerivative::calculate(Path*, Path*)
  0.01     94.06     0.01    15721     0.00     0.00  Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int)
  0.01     94.07     0.01      929     0.01     0.01  StarNetwork::getNextNode()
  0.01     94.08     0.01        1    10.00    10.03  Parser::parseNetwork(std::string const&, bool)
  0.01     94.09     0.01                             boost::heap::fibonacci_heap<ValueKey, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::marked_heap_node<ValueKey>*, boost::heap::detail::make_fibonacci_heap_base<ValueKey, boost::parameter::aux::empty_arg_list>::type, ValueKey&>)
  0.01     94.10     0.01                             BprFnc::evaluateSecondDerivative(double)
  0.01     94.10     0.01   607045     0.00     0.00  ShPathInterface::getInComeLink(int) const
  0.01     94.11     0.01   427788     0.00     0.00  ShPathInterface::getCost(int) const
  0.01     94.11     0.01        1     5.00     5.00  StarNetwork::beginNode()
  0.00     94.11     0.00  1567900     0.00     0.00  StarLink::getFlow() const
  0.00     94.11     0.00  1252855     0.00     0.00  Path::getFlow() const
  0.00     94.11     0.00  1195932     0.00     0.00  StarLink::getNodeTo() const
  0.00     94.11     0.00  1079079     0.00     0.00  StarLink::addFlow(double)
  0.00     94.11     0.00  1079079     0.00     0.00  Path::getPrevFlow() const
  0.00     94.11     0.00   886667     0.00     0.00  PathAndDirection::getDirectionValue() const
  0.00     94.11     0.00   584206     0.00     0.00  Path::addLinkToPath(StarLink*)
  0.00     94.11     0.00   422186     0.00     0.00  boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear()
  0.00     94.11     0.00   350111     0.00     0.00  StarLink::getLinkFnc() const
  0.00     94.11     0.00   347589     0.00     0.00  BprFnc::evaluateDerivative(double)
  0.00     94.11     0.00   277441     0.00     0.00  std::vector<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, std::allocator<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&> > >::at(unsigned long)
  0.00     94.11     0.00   253504     0.00     0.00  PairOD::getIndex() const
  0.00     94.11     0.00   253504     0.00     0.00  PairOD::getDemand() const
  0.00     94.11     0.00   245582     0.00     0.00  Origin::getNextDest()
  0.00     94.11     0.00   231117     0.00     0.00  Path::setCurrCost(double)
  0.00     94.11     0.00   216200     0.00     0.00  AdditivePC::calculate(Path*) const
  0.00     94.11     0.00   206998     0.00     0.00  OriginBushLUCE::OriginBushLUCE(int, StarNetwork*)
  0.00     94.11     0.00   205972     0.00     0.45  PathBasedAlgo::mainLoop(ODSet*)
  0.00     94.11     0.00   205972     0.00     0.00  EquilibrationI::executeMainLoop(ODSet*)
  0.00     94.11     0.00   205972     0.00     0.00  PathSet::getNextSet()
  0.00     94.11     0.00   191055     0.00     0.00  ODSet::getNbPaths() const
  0.00     94.11     0.00   177675     0.00     0.00  PairOD::getODIndex() const
  0.00     94.11     0.00   169753     0.00     0.00  PathSet::initialiseItself(StarLink*, PairOD*)
  0.00     94.11     0.00   169753     0.00     0.00  ODSet::getDestIndex() const
  0.00     94.11     0.00   165361     0.00     0.00  Path::getCurrCost() const
  0.00     94.11     0.00   125768     0.00     0.00  PathAndDirection::getPath() const
  0.00     94.11     0.00    73138     0.00     0.00  StarNetwork::getNextOnlyLink()
  0.00     94.11     0.00    62884     0.00     0.00  PathAndDirection::setDirection(double)
  0.00     94.11     0.00    62884     0.00     0.00  PathBasedFlowMove::getNextPathDirection()
  0.00     94.11     0.00    48276     0.00     0.00  Path::setPrevFlow(double)
  0.00     94.11     0.00    46262     0.00     0.00  PathAndDirection::PathAndDirection()
  0.00     94.11     0.00    46262     0.00     0.00  PathAndDirection::~PathAndDirection()
  0.00     94.11     0.00    39364     0.00     0.00  Path::setFlow(double)
  0.00     94.11     0.00    31442     0.00     0.00  PathAndDirection::setPath(Path*)
  0.00     94.11     0.00    31442     0.00     0.00  PathBasedFlowMove::beginPathDirection()
  0.00     94.11     0.00    23643     0.00     0.00  ODSet::projectPathFlowOnLinks()
  0.00     94.11     0.00    23131     0.00     0.00  PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&)
  0.00     94.11     0.00    23131     0.00     0.00  DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&)
  0.00     94.11     0.00    23131     0.00     0.00  DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&)
  0.00     94.11     0.00    22839     0.00     0.00  Path::Path()
  0.00     94.11     0.00    22839     0.00     0.00  Path::~Path()
  0.00     94.11     0.00    18924     0.00     0.00  Origin::getIndex() const
  0.00     94.11     0.00    15721     0.00     0.00  PathDerivative::PathDerivative(int)
  0.00     94.11     0.00    15721     0.00     0.00  PathDerivative::~PathDerivative()
  0.00     94.11     0.00    15721     0.00     0.00  PathBasedFlowMovePE::executeFlowMove()
  0.00     94.11     0.00    15721     0.00     0.00  ODSet::updateLinkCostsOfOD()
  0.00     94.11     0.00    15721     0.00     0.00  ODSet::calculateProjectedDirection()
  0.00     94.11     0.00    15721     0.00     0.00  Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int)
  0.00     94.11     0.00     8034     0.00     0.00  StarNetwork::getNodeIndex(int)
  0.00     94.11     0.00     7925     0.00     0.00  StarNetwork::getNbLinks()
  0.00     94.11     0.00     7922     0.00     0.00  PathAlgoCreator::allocateDescDirectionPath()
  0.00     94.11     0.00     7922     0.00     0.00  PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*)
  0.00     94.11     0.00     7922     0.00     0.00  DescDirectionPathPE::DescDirectionPathPE(double)
  0.00     94.11     0.00     7922     0.00     0.00  DescDirectionPathPE::~DescDirectionPathPE()
  0.00     94.11     0.00     7922     0.00     0.00  PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*)
  0.00     94.11     0.00     7922     0.00     0.00  PathBasedFlowMovePE::~PathBasedFlowMovePE()
  0.00     94.11     0.00     7922     0.00     0.00  DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double)
  0.00     94.11     0.00     7922     0.00     0.00  DescDirectionPathScaled::~DescDirectionPathScaled()
  0.00     94.11     0.00     7922     0.00     0.00  ODSet::addPath(Path*)
  0.00     94.11     0.00     7922     0.00     0.00  ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*)
  0.00     94.11     0.00     7922     0.00     0.00  ODSet::~ODSet()
  0.00     94.11     0.00     7922     0.00     0.00  ODSet::~ODSet()
  0.00     94.11     0.00     7922     0.00     0.00  Origin::addDestination(PairOD*)
  0.00     94.11     0.00     7922     0.00     0.00  PairOD::setODIndex(int)
  0.00     94.11     0.00     7922     0.00     0.00  PairOD::setOriginIndex(int)
  0.00     94.11     0.00     7922     0.00     0.00  PairOD::setIndex(int)
  0.00     94.11     0.00     7922     0.00     0.00  PairOD::PairOD(int, double)
  0.00     94.11     0.00     7922     0.00     0.00  PairOD::~PairOD()
  0.00     94.11     0.00     7922     0.00     0.00  PairOD::getID() const
  0.00     94.11     0.00     4534     0.00     0.00  Utils::removeWhiteSpaces(std::string&)
  0.00     94.11     0.00     4410     0.00     0.00  Utils::skipOneLineComment(std::string, std::string)
  0.00     94.11     0.00     3449     0.00     0.00  StarNode::getIndex()
  0.00     94.11     0.00     3410     0.00     0.00  Origin::beginDest()
  0.00     94.11     0.00     3300     0.00     0.00  ODMatrix::getNextOrigin()
  0.00     94.11     0.00     2522     0.00     0.00  StarNetwork::addLink(StarLink*)
  0.00     94.11     0.00     2522     0.00     0.00  BprFnc::BprFnc(double, double, double, double)
  0.00     94.11     0.00     2522     0.00     0.00  BprFnc::~BprFnc()
  0.00     94.11     0.00     2522     0.00     0.00  StarLink::setNodeToIndex(int)
  0.00     94.11     0.00     2522     0.00     0.00  StarLink::setNodeFromIndex(int)
  0.00     94.11     0.00     2522     0.00     0.00  StarLink::setIndex(int)
  0.00     94.11     0.00     2522     0.00     0.00  StarLink::StarLink(int, int, LinkFnc*)
  0.00     94.11     0.00     2522     0.00     0.00  StarLink::~StarLink()
  0.00     94.11     0.00     2285     0.00     0.00  std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&)
  0.00     94.11     0.00     2045     0.00     0.00  StarNetwork::getNbNodes()
  0.00     94.11     0.00      930     0.00     0.00  ObjectManager::getEqAlgo()
  0.00     94.11     0.00      929     0.00     0.00  StarNetwork::addNode(StarNode*)
  0.00     94.11     0.00      929     0.00     0.00  StarNode::setIndex(int)
  0.00     94.11     0.00      929     0.00     0.00  StarNode::StarNode(int, bool)
  0.00     94.11     0.00      929     0.00     0.00  StarNode::~StarNode()
  0.00     94.11     0.00      110     0.00     0.00  Origin::setIndex(int)
  0.00     94.11     0.00      110     0.00     0.00  Origin::Origin(int)
  0.00     94.11     0.00      110     0.00     0.00  Origin::~Origin()
  0.00     94.11     0.00      110     0.00     0.00  ODMatrix::addOrigin(Origin*)
  0.00     94.11     0.00      110     0.00     0.00  Origin::getID() const
  0.00     94.11     0.00       71     0.00     0.00  Utils::getSubString(std::string, std::string, std::string)
  0.00     94.11     0.00       33     0.00     0.00  ParseParams::skipComments(std::string)
  0.00     94.11     0.00       33     0.00     0.00  Params::addParameter(std::string, std::string)
  0.00     94.11     0.00       30     0.00     0.00  ODMatrix::beginOrigin()
  0.00     94.11     0.00       29     0.00     0.00  StarNetwork::beginOnlyLink()
  0.00     94.11     0.00       27     0.00    18.04  RelGap::isConverged()
  0.00     94.11     0.00       27     0.00    18.03  RelGap::getMinTravelTime()
  0.00     94.11     0.00       27     0.00     0.00  PathSet::isConverged() const
  0.00     94.11     0.00       26     0.00     0.00  PathSet::beginSet()
  0.00     94.11     0.00       16     0.00     0.00  Params::getParam(std::string)
  0.00     94.11     0.00        6     0.00     0.00  ObjectManager::getNet()
  0.00     94.11     0.00        5     0.00     0.00  std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*)
  0.00     94.11     0.00        5     0.00     0.00  bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*)
  0.00     94.11     0.00        3     0.00     0.05  StarNetwork::calculateLinkCosts()
  0.00     94.11     0.00        3     0.00     0.00  ObjectManager::getPathAlgoType()
  0.00     94.11     0.00        3     0.00     0.00  Parser::checkEmptyValue(int)
  0.00     94.11     0.00        2     0.00     0.10  ObjectManager::getODMatrix()
  0.00     94.11     0.00        2     0.00     0.00  ObjectManager::getPathAlgoApp()
  0.00     94.11     0.00        2     0.00   311.98  ObjectManager::getShPath()
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10AdditivePCC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10AlgorithmB9zeroFlow_E
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10DerivativeC2EdP16LinkFncContainer
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10FileReaderC2ERKSs
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10FileWriterC2ERKSs
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN10OriginBush15wasInitialised_E
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11DAGraphLUCEC2EP11StarNetworkP8ODMatrixddi
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11DAGraphNodeC2Eid
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11MarginalFncC2EP7LinkFnc
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11ParseParamsC2ESs
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11StarNetworkC2EiiRSs
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN11StepSizeAddC2EP13DescDirectionidP10LineSearchP10Derivative
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN12LinkFlowsBFW14allocateMemoryEv
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN12LinkFlowsCFW14allocateMemoryEv
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13AONAssignmentC2EP8ODMatrixP12ShortestPath
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13NonAdditivePCC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13ObjectManagerC2EP6Params
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13PathBasedAlgoC2EP7PathSetb
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13ShPathFactoryC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN13SpiessFncCombC2EP9SpiessFncS1_
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14EquilibrationIC2EP13PathBasedAlgo
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14OriginBushLUCEC2EiP11StarNetwork
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14PathDerivativeC2Ei
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN14StepSizeNonAddC2EP13DescDirectionidP10LineSearchP10Derivative
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN15EquilibrationIIC2EP13PathBasedAlgo
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN15OriginBasedAlgoC2EP9OriginSet
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN15PathAlgoCreatorC2E12PathAlgoType7PathAppiddd
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16LinkFncContainerC2EP11StarNetwork
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16PathAndDirectionC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16SpiessFncCreatorC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN16StepSizeSparsityC2EP8StepSize
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN17LabelCorrectingAlC2EP11StarNetwork
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN17OnePathDerivativeC2Ed
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN17PathBasedFlowMoveC2EP17DescDirectionPath
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19DescDirectionPathGPC2Ed
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19DescDirectionPathPEC2Ed
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19DescDirectionPathPGC2Ed
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19PathBasedFlowMoveGPC2EddP17DescDirectionPath
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN19PathBasedFlowMovePEC2EP17DescDirectionPath
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN20DescDirectionPathISPC2Eddd
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN23DescDirectionPathScaledC2EP17DescDirectionPathid
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN25PathBasedFlowMoveWithStepC2EP11StepSizeABCP17DescDirectionPath
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN4PathC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN5ODSet16initialiseObjectEiiiP8PathCostP16LinkFncContainerP11StarNetworkP12ShortestPathP11ConvMeasuredPdSA_P15PathAlgoCreator
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN5Utils16getDisjointLinksEP4PathS1_RSt4listIP8StarLinkSaIS4_EEi
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN5Utils17removeWhiteSpacesERSs
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6ArmijoC2EdP10Derivative
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6BprFncC2Edddd
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6FWAlgoC2EP9LinkFlows
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6OriginC2Ei
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6PairODC2Eid
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6ParamsC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6ParserC2Ev
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN6RelGapC2EdP11StarNetworkP8ODMatrixP12ShortestPath
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN7DAGraph4net_E
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN7PathSet16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP11ConvMeasureP8PathCost
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN7QuadAppC2EP10Derivative
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8ConstFncC2Ed
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8ODMatrixC2Ei
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8StarLinkC2EiiP7LinkFnc
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN8StepSizeC2EP13DescDirectionidP10LineSearch
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9BisectionC2EdP10Derivative
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9LinearFncC2Edd
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9LinkFlows16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP10DerivativeP10LineSearchP11ConvMeasure
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9OriginSetC2EP8ODMatrixP11StarNetworkP12ShortestPathP11ConvMeasureddb
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN9SpiessFncC2Eddddd
  0.00     94.11     0.00        1     0.00     0.00  _GLOBAL__sub_I_main
  0.00     94.11     0.00        1     0.00     0.00  AdditivePC::AdditivePC()
  0.00     94.11     0.00        1     0.00     0.00  AdditivePC::~AdditivePC()
  0.00     94.11     0.00        1     0.00     0.00  StarNetwork::createIndexes()
  0.00     94.11     0.00        1     0.00    39.97  StarNetwork::linkNodes()
  0.00     94.11     0.00        1     0.00     0.00  StarNetwork::StarNetwork(int, int, std::string&)
  0.00     94.11     0.00        1     0.00     0.00  StarNetwork::~StarNetwork()
  0.00     94.11     0.00        1     0.00    23.86  AONAssignment::execute(InitialiseSolution*)
  0.00     94.11     0.00        1     0.00     0.00  AONAssignment::AONAssignment(ODMatrix*, ShortestPath*)
  0.00     94.11     0.00        1     0.00     0.00  AONAssignment::~AONAssignment()
  0.00     94.11     0.00        1     0.00     0.00  ObjectManager::getPathSet()
  0.00     94.11     0.00        1     0.00     0.00  ObjectManager::getPathCost()
  0.00     94.11     0.00        1     0.00     0.00  ObjectManager::getConvMeasure()
  0.00     94.11     0.00        1     0.00     0.00  ObjectManager::getPathAlgoCreator()
  0.00     94.11     0.00        1     0.00     0.00  PathBasedAlgo::PathBasedAlgo(PathSet*, bool)
  0.00     94.11     0.00        1     0.00     0.00  PathBasedAlgo::~PathBasedAlgo()
  0.00     94.11     0.00        1     0.00     0.00  ShPathFactory::get()
  0.00     94.11     0.00        1     0.00   623.97  ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*)
  0.00     94.11     0.00        1     0.00     0.00  EquilibrationI::EquilibrationI(PathBasedAlgo*)
  0.00     94.11     0.00        1     0.00     0.00  EquilibrationI::~EquilibrationI()
  0.00     94.11     0.00        1     0.00     0.00  PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double)
  0.00     94.11     0.00        1     0.00     0.00  PathAlgoCreator::~PathAlgoCreator()
  0.00     94.11     0.00        1     0.00     0.00  ShPathInterface::ShPathInterface(StarNetwork*)
  0.00     94.11     0.00        1     0.00     0.00  ShPathInterface::~ShPathInterface()
  0.00     94.11     0.00        1     0.00     0.00  LinkFncContainer::LinkFncContainer(StarNetwork*)
  0.00     94.11     0.00        1     0.00     0.00  LinkFncContainer::~LinkFncContainer()
  0.00     94.11     0.00        1     0.00     0.00  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect()
  0.00     94.11     0.00        1     0.00     0.00  ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect()
  0.00     94.11     0.00        1     0.00     0.00  Utils::extractName(char const*, std::string&)
  0.00     94.11     0.00        1     0.00     0.21  Parser::parseODMatrix(std::string const&, int)
  0.00     94.11     0.00        1     0.00     0.00  Parser::Parser()
  0.00     94.11     0.00        1     0.00     0.00  RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*)
  0.00     94.11     0.00        1     0.00     0.00  RelGap::~RelGap()
  0.00     94.11     0.00        1     0.00    60.64  PathSet::initialise()
  0.00     94.11     0.00        1     0.00     0.00  PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*)
  0.00     94.11     0.00        1     0.00     0.00  PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*)
  0.00     94.11     0.00        1     0.00     0.00  PathSet::~PathSet()
  0.00     94.11     0.00        1     0.00     0.00  PathSet::~PathSet()
  0.00     94.11     0.00        1     0.00     0.00  ODMatrix::setIndexes(StarNetwork*)
  0.00     94.11     0.00        1     0.00     0.00  ODMatrix::ODMatrix(int)
  0.00     94.11     0.00        1     0.00     0.00  ODMatrix::~ODMatrix()
  0.00     94.11     0.00        1     0.00     0.00  ODMatrix::getNbODPairs() const
  0.00     94.11     0.00        1     0.00     0.00  std::vector<bool, std::allocator<bool> >::_M_initialize(unsigned long)
  0.00     94.11     0.00        1     0.00     0.00  std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*)

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


granularity: each sample hit covers 2 byte(s) for 0.01% of 94.11 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     98.2    0.00   92.39                 PathBasedAlgo::execute() [1]
                0.00   91.84  205972/205972      PathBasedAlgo::mainLoop(ODSet*) [2]
                0.00    0.49      27/27          RelGap::isConverged() [23]
                0.00    0.06       1/1           PathSet::initialise() [35]
                0.00    0.00  205972/205972      PathSet::getNextSet() [92]
                0.00    0.00  205972/205972      EquilibrationI::executeMainLoop(ODSet*) [91]
                0.00    0.00      27/27          PathSet::isConverged() const [163]
                0.00    0.00      26/26          PathSet::beginSet() [164]
-----------------------------------------------
                0.00   91.84  205972/205972      PathBasedAlgo::execute() [1]
[2]     97.6    0.00   91.84  205972         PathBasedAlgo::mainLoop(ODSet*) [2]
                0.01   91.56  205972/205972      ODSet::improveSet() [3]
                0.04    0.06  205972/205972      ODSet::updateSet() [31]
                0.00    0.07   15721/23643       ODSet::projectPathFlowOnLinks() [30]
                0.01    0.05   23131/23131       ODSet::equilibrate() [34]
                0.00    0.03   15721/15721       ODSet::updateLinkCostsOfOD() [44]
                0.01    0.00   23131/23131       ODSet::removeUnusedPaths() [51]
                0.00    0.00  191055/191055      ODSet::getNbPaths() const [93]
                0.00    0.00   15721/15721       PathBasedFlowMovePE::executeFlowMove() [113]
-----------------------------------------------
                0.01   91.56  205972/205972      PathBasedAlgo::mainLoop(ODSet*) [2]
[3]     97.3    0.01   91.56  205972         ODSet::improveSet() [3]
                0.21   91.34  205972/205972      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.01    0.00  414453/9529106     StarNetwork::getLink(int) [29]
                0.00    0.00  429370/607045      ShPathInterface::getInComeLink(int) const [56]
                0.00    0.00  429370/272778726     StarLink::getNodeFromIndex() const [9]
                0.00    0.00  205972/427788      ShPathInterface::getCost(int) const [57]
                0.00    0.00  414453/584206      Path::addLinkToPath(StarLink*) [82]
                0.00    0.00   29834/165361      Path::getCurrCost() const [96]
                0.00    0.00   14917/22839       Path::Path() [108]
                0.00    0.00   14917/231117      Path::setCurrCost(double) [89]
-----------------------------------------------
                0.21   91.34  205972/205972      ODSet::improveSet() [3]
[4]     97.3    0.21   91.34  205972         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
               49.82   14.17 110518910/110518910     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
               10.65   14.71 110518910/110518910     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                1.49    0.30  205972/211092      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [10]
                0.12    0.00 8944900/9529106     StarNetwork::getLink(int) [29]
                0.05    0.00 11934510/289113506     StarLink::getNodeToIndex() const [13]
                0.01    0.00 1482840/272778726     StarLink::getNodeFromIndex() const [9]
                0.00    0.00 4472450/556969855     StarLink::getTime() const [22]
                0.00    0.00 4472450/304388932     StarLink::getIndex() const [25]
                0.00    0.00  205972/206998      OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [90]
-----------------------------------------------
               49.82   14.17 110518910/110518910     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[5]     68.0   49.82   14.17 110518910         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                2.22    4.06 118119988/241948806     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                3.81    0.00 110518910/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                1.98    0.00 268606935/272778726     StarLink::getNodeFromIndex() const [9]
                0.31    0.53 16815190/28984538     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [11]
                0.48    0.00 110518910/225626151     StarNode::getIsZone() [14]
                0.34    0.00 110518910/225629413     StarNetwork::beginNode(int) [16]
                0.30    0.00 268606935/556969855     StarLink::getTime() const [22]
                0.14    0.00 135086341/304388932     StarLink::getIndex() const [25]
-----------------------------------------------
               10.65   14.71 110518910/110518910     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[6]     26.9   10.65   14.71 110518910         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                2.23    4.09 118820161/241948806     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                3.81    0.00 110518910/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                1.31    0.00 268019841/277006721     StarNetwork::getNextLink() [12]
                1.16    0.00 268019841/289113506     StarLink::getNodeToIndex() const [13]
                0.22    0.37 11831385/28984538     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [11]
                0.48    0.00 110518910/225626151     StarNode::getIsZone() [14]
                0.34    0.00 110518910/225629413     StarNetwork::beginNode(int) [16]
                0.30    0.00 268019841/556969855     StarLink::getTime() const [22]
                0.24    0.00 98102734/101390224     StarNetwork::beginLink() [28]
                0.16    0.00 153991480/304388932     StarLink::getIndex() const [25]
-----------------------------------------------
                             937443315             boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                0.03    0.00  863132/493185021     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.13    0.00 3728461/493185021     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.92    0.00 26513086/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [11]
                3.81    0.00 110518910/493185021     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                3.81    0.00 110518910/493185021     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                8.32    0.00 241042522/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
[7]     18.1   17.02    0.00 493185021+937443315 boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                             937443315             boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
-----------------------------------------------
                0.01    0.01  422184/241948806     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [10]
                0.02    0.03  862112/241948806     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.07    0.13 3724361/241948806     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                2.22    4.06 118119988/241948806     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                2.23    4.09 118820161/241948806     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[8]     13.7    4.54    8.32 241948806         boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                8.32    0.00 241042522/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
-----------------------------------------------
                0.00    0.00    2522/272778726     Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00  177675/272778726     AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00  429370/272778726     ODSet::improveSet() [3]
                0.01    0.00 1482840/272778726     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.02    0.00 2079384/272778726     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                1.98    0.00 268606935/272778726     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[9]      2.1    2.02    0.00 272778726         StarLink::getNodeFromIndex() const [9]
-----------------------------------------------
                0.01    0.00    1020/211092      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.03    0.01    4100/211092      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                1.49    0.30  205972/211092      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[10]     1.9    1.53    0.30  211092         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [10]
                0.00    0.28  422184/422186      boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [27]
                0.01    0.01  422184/241948806     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
-----------------------------------------------
                0.00    0.00   60522/28984538     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.01    0.01  277441/28984538     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.22    0.37 11831385/28984538     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.31    0.53 16815190/28984538     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[11]     1.5    0.53    0.92 28984538         boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [11]
                0.92    0.00 26513086/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
-----------------------------------------------
                0.00    0.00    2522/277006721     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.04    0.00 8984358/277006721     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                1.31    0.00 268019841/277006721     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[12]     1.4    1.35    0.00 277006721         StarNetwork::getNextLink() [12]
-----------------------------------------------
                0.00    0.00    2522/289113506     Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00    2522/289113506     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.00    0.00  169753/289113506     PathSet::initialiseItself(StarLink*, PairOD*) [59]
                0.04    0.00 8984358/289113506     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.05    0.00 11934510/289113506     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                1.16    0.00 268019841/289113506     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[13]     1.3    1.26    0.00 289113506         StarLink::getNodeToIndex() const [13]
-----------------------------------------------
                0.00    0.00  863970/225626151     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.02    0.00 3724361/225626151     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.48    0.00 110518910/225626151     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.48    0.00 110518910/225626151     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[14]     1.0    0.97    0.00 225626151         StarNode::getIsZone() [14]
-----------------------------------------------
                                                 <spontaneous>
[15]     1.0    0.97    0.00                 boost::heap::detail::d_ary_heap<std::_List_iterator<std::pair<ValueKey, unsigned long> >, boost::parameter::aux::arg_list<boost::heap::allocator<std::allocator<ValueKey> >, boost::parameter::aux::arg_list<boost::heap::compare<boost::heap::detail::priority_queue_mutable_wrapper<boost::heap::detail::d_ary_heap<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::empty_arg_list> >, boost::heap::detail::nop_index_updater> >::indirect_cmp>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::arg_list<boost::heap::stability_counter_type<unsigned long>, boost::parameter::aux::arg_list<boost::heap::stable<false>, boost::parameter::aux::empty_arg_list> > > > >, boost::heap::detail::priority_queue_mutable_wrapper<boost::heap::detail::d_ary_heap<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::empty_arg_list> >, boost::heap::detail::nop_index_updater> >::index_updater>::pop() [15]
-----------------------------------------------
                0.00    0.00  863132/225629413     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.01    0.00 3728461/225629413     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.34    0.00 110518910/225629413     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.34    0.00 110518910/225629413     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[16]     0.7    0.70    0.00 225629413         StarNetwork::beginNode(int) [16]
-----------------------------------------------
                0.00    0.01     110/4100        AONAssignment::execute(InitialiseSolution*) [46]
                0.04    0.13    1020/4100        ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.12    0.37    2970/4100        RelGap::getMinTravelTime() [24]
[17]     0.7    0.16    0.51    4100         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.07    0.13 3724361/241948806     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                0.13    0.00 3728461/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                0.04    0.00 8984358/277006721     StarNetwork::getNextLink() [12]
                0.04    0.00 8984358/289113506     StarLink::getNodeToIndex() const [13]
                0.03    0.01    4100/211092      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [10]
                0.02    0.00 3724361/225626151     StarNode::getIsZone() [14]
                0.01    0.01  277441/28984538     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [11]
                0.01    0.00 3728461/225629413     StarNetwork::beginNode(int) [16]
                0.01    0.00 8984358/556969855     StarLink::getTime() const [22]
                0.01    0.00 3286561/101390224     StarNetwork::beginLink() [28]
                0.00    0.00 4001802/304388932     StarLink::getIndex() const [25]
                0.00    0.00  277441/277441      std::vector<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, std::allocator<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&> > >::at(unsigned long) [85]
-----------------------------------------------
                                   1             ObjectManager::getConvMeasure() <cycle 1> [247]
                                   1             ObjectManager::getPathSet() <cycle 1> [66]
[19]     0.7    0.00    0.62       2         ObjectManager::getShPath() <cycle 1> [19]
                0.00    0.62       1/1           ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [20]
                0.00    0.00       2/16          Params::getParam(std::string) [165]
                0.00    0.00       1/1           ShPathFactory::get() [251]
                                   1             ObjectManager::getNet() <cycle 1> [166]
-----------------------------------------------
                0.00    0.62       1/1           ObjectManager::getShPath() <cycle 1> [19]
[20]     0.7    0.00    0.62       1         ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [20]
                0.33    0.29       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.00    0.00       5/5           bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*) [168]
-----------------------------------------------
                0.33    0.29       1/1           ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [20]
[21]     0.7    0.33    0.29       1         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.04    0.13    1020/4100        ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.02    0.03  862112/241948806     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [8]
                0.03    0.00  863132/493185021     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [7]
                0.02    0.00 2079384/272778726     StarLink::getNodeFromIndex() const [9]
                0.01    0.00     929/929         StarNetwork::getNextNode() [52]
                0.01    0.00    1020/211092      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [10]
                0.01    0.00       1/1           StarNetwork::beginNode() [58]
                0.00    0.00  863970/225626151     StarNode::getIsZone() [14]
                0.00    0.00   60522/28984538     boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) [11]
                0.00    0.00  863132/225629413     StarNetwork::beginNode(int) [16]
                0.00    0.00 2079384/556969855     StarLink::getTime() const [22]
                0.00    0.00  922634/304388932     StarLink::getIndex() const [25]
                0.00    0.00       1/3           StarNetwork::calculateLinkCosts() [62]
                0.00    0.00    2522/277006721     StarNetwork::getNextLink() [12]
                0.00    0.00    2522/289113506     StarLink::getNodeToIndex() const [13]
                0.00    0.00     929/101390224     StarNetwork::beginLink() [28]
                0.00    0.00    2285/2285        std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&) [147]
                0.00    0.00    1026/206998      OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [90]
                0.00    0.00     929/3449        StarNode::getIndex() [137]
                0.00    0.00       1/1           ShPathInterface::ShPathInterface(StarNetwork*) [256]
                0.00    0.00       1/1           std::vector<bool, std::allocator<bool> >::_M_initialize(unsigned long) [271]
-----------------------------------------------
                0.00    0.00   68094/556969855     RelGap::isConverged() [23]
                0.00    0.00 2079384/556969855     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.00    0.00 4472450/556969855     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.01    0.00 4738793/556969855     AdditivePC::calculate(Path*) const [37]
                0.01    0.00 8984358/556969855     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.30    0.00 268019841/556969855     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
                0.30    0.00 268606935/556969855     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
[22]     0.7    0.62    0.00 556969855         StarLink::getTime() const [22]
-----------------------------------------------
                0.00    0.49      27/27          PathBasedAlgo::execute() [1]
[23]     0.5    0.00    0.49      27         RelGap::isConverged() [23]
                0.00    0.49      27/27          RelGap::getMinTravelTime() [24]
                0.00    0.00   68094/556969855     StarLink::getTime() const [22]
                0.00    0.00  136188/1567900     StarLink::getFlow() const [76]
                0.00    0.00   68094/73138       StarNetwork::getNextOnlyLink() [98]
                0.00    0.00      27/29          StarNetwork::beginOnlyLink() [162]
-----------------------------------------------
                0.00    0.49      27/27          RelGap::isConverged() [23]
[24]     0.5    0.00    0.49      27         RelGap::getMinTravelTime() [24]
                0.12    0.37    2970/4100        ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.00    0.00  213894/427788      ShPathInterface::getCost(int) const [57]
                0.00    0.00  213894/253504      PairOD::getIndex() const [86]
                0.00    0.00  213894/253504      PairOD::getDemand() const [87]
                0.00    0.00  213894/245582      Origin::getNextDest() [88]
                0.00    0.00    2970/18924       Origin::getIndex() const [110]
                0.00    0.00    2970/3410        Origin::beginDest() [138]
                0.00    0.00    2970/3300        ODMatrix::getNextOrigin() [139]
                0.00    0.00      27/30          ODMatrix::beginOrigin() [161]
-----------------------------------------------
                0.00    0.00    2522/304388932     LinkFncContainer::LinkFncContainer(StarNetwork*) [67]
                0.00    0.00  855225/304388932     Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.00    0.00  922634/304388932     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.00    0.00 1109043/304388932     ODSet::calculateProjectedDirection() [48]
                0.00    0.00 1281641/304388932     Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [45]
                0.00    0.00 2665794/304388932     ODSet::projectPathFlowOnLinks() [30]
                0.00    0.00 4001802/304388932     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.00    0.00 4472450/304388932     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
                0.14    0.00 135086341/304388932     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [5]
                0.16    0.00 153991480/304388932     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[25]     0.3    0.33    0.00 304388932         StarLink::getIndex() const [25]
-----------------------------------------------
                             2290664             void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [26]
                0.28    0.00  783783/783783      boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [27]
[26]     0.3    0.28    0.00  783783+2290664 void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [26]
                             2290664             void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [26]
-----------------------------------------------
                0.00    0.00       2/422186      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [69]
                0.00    0.28  422184/422186      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [10]
[27]     0.3    0.00    0.28  422186         boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [27]
                0.28    0.00  783783/783783      void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [26]
-----------------------------------------------
                0.00    0.00     929/101390224     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.01    0.00 3286561/101390224     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.24    0.00 98102734/101390224     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [6]
[28]     0.3    0.25    0.00 101390224         StarNetwork::beginLink() [28]
-----------------------------------------------
                0.00    0.00  169753/9529106     AONAssignment::execute(InitialiseSolution*) [46]
                0.01    0.00  414453/9529106     ODSet::improveSet() [3]
                0.12    0.00 8944900/9529106     ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[29]     0.1    0.13    0.00 9529106         StarNetwork::getLink(int) [29]
-----------------------------------------------
                0.00    0.04    7922/23643       PathSet::initialise() [35]
                0.00    0.07   15721/23643       PathBasedAlgo::mainLoop(ODSet*) [2]
[30]     0.1    0.00    0.11   23643         ODSet::projectPathFlowOnLinks() [30]
                0.09    0.00 1332897/1332897     StarLink::setFlow(double) [32]
                0.02    0.00 2158158/10798368     Path::getNextLink() const [33]
                0.01    0.00   82490/442060      Path::beginLink() const [43]
                0.00    0.00 2665794/304388932     StarLink::getIndex() const [25]
                0.00    0.00 1079079/1079079     Path::getPrevFlow() const [80]
                0.00    0.00 1079079/1567900     StarLink::getFlow() const [76]
                0.00    0.00 1079079/1252855     Path::getFlow() const [77]
                0.00    0.00 1079079/1079079     StarLink::addFlow(double) [79]
-----------------------------------------------
                0.04    0.06  205972/205972      PathBasedAlgo::mainLoop(ODSet*) [2]
[31]     0.1    0.04    0.06  205972         ODSet::updateSet() [31]
                0.00    0.06  216200/216200      AdditivePC::calculate(Path*) const [37]
                0.00    0.00  216200/231117      Path::setCurrCost(double) [89]
-----------------------------------------------
                0.09    0.00 1332897/1332897     ODSet::projectPathFlowOnLinks() [30]
[32]     0.1    0.09    0.00 1332897         StarLink::setFlow(double) [32]
-----------------------------------------------
                0.01    0.00  855225/10798368     Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.01    0.00  855225/10798368     ODSet::calculateProjectedDirection() [48]
                0.01    0.00  909326/10798368     ODSet::updateLinkCostsOfOD() [44]
                0.01    0.00 1281641/10798368     Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [45]
                0.02    0.00 2158158/10798368     ODSet::projectPathFlowOnLinks() [30]
                0.04    0.00 4738793/10798368     AdditivePC::calculate(Path*) const [37]
[33]     0.1    0.08    0.00 10798368         Path::getNextLink() const [33]
-----------------------------------------------
                0.01    0.05   23131/23131       PathBasedAlgo::mainLoop(ODSet*) [2]
[34]     0.1    0.01    0.05   23131         ODSet::equilibrate() [34]
                0.00    0.03   23131/23131       PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [40]
                0.00    0.02   15721/15721       ODSet::calculateProjectedDirection() [48]
                0.00    0.00   96552/1252855     Path::getFlow() const [77]
                0.00    0.00   48276/48276       Path::setPrevFlow(double) [101]
-----------------------------------------------
                0.00    0.06       1/1           PathBasedAlgo::execute() [1]
[35]     0.1    0.00    0.06       1         PathSet::initialise() [35]
                0.00    0.04    7922/23643       ODSet::projectPathFlowOnLinks() [30]
                0.00    0.02       1/1           AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00       2/3           StarNetwork::calculateLinkCosts() [62]
                0.00    0.00       1/1           AONAssignment::AONAssignment(ODMatrix*, ShortestPath*) [244]
                0.00    0.00       1/1           AONAssignment::~AONAssignment() [245]
-----------------------------------------------
                                                 <spontaneous>
[36]     0.1    0.06    0.00                 ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [36]
-----------------------------------------------
                0.00    0.06  216200/216200      ODSet::updateSet() [31]
[37]     0.1    0.00    0.06  216200         AdditivePC::calculate(Path*) const [37]
                0.04    0.00 4738793/10798368     Path::getNextLink() const [33]
                0.01    0.00  216200/442060      Path::beginLink() const [43]
                0.01    0.00 4738793/556969855     StarLink::getTime() const [22]
-----------------------------------------------
                0.00    0.00     929/1194337     StarNetwork::addNode(StarNode*) <cycle 1> [63]
                0.04    0.00 1193408/1194337     StarNetwork::linkNodes() <cycle 1> [39]
[38]     0.0    0.04    0.00 1194337         StarNode::getID() [38]
-----------------------------------------------
                                   1             ObjectManager::getNet() <cycle 1> [166]
[39]     0.0    0.00    0.04       1         StarNetwork::linkNodes() <cycle 1> [39]
                0.04    0.00 1193408/1194337     StarNode::getID() [38]
                0.00    0.00 1193410/1195932     StarLink::getNodeTo() const [78]
                0.00    0.00    2522/2522        StarLink::setNodeToIndex(int) [143]
                0.00    0.00    2520/3449        StarNode::getIndex() [137]
                0.00    0.00       2/8034        StarNetwork::getNodeIndex(int) [114]
                                   1             StarNetwork::createIndexes() <cycle 1> [241]
-----------------------------------------------
                0.00    0.03   23131/23131       ODSet::equilibrate() [34]
[40]     0.0    0.00    0.03   23131         PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [40]
                0.00    0.03   23131/23131       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
                0.00    0.00   24918/46262       PathAndDirection::~PathAndDirection() [103]
-----------------------------------------------
                0.00    0.03   23131/23131       PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [40]
[41]     0.0    0.00    0.03   23131         DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
                0.01    0.02   15721/15721       PathDerivative::calculate(Path*, Path*) [42]
                0.00    0.00   31442/125768      PathAndDirection::getPath() const [97]
                0.00    0.00   31442/62884       PathAndDirection::setDirection(double) [99]
                0.00    0.00   23131/23131       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [107]
                0.00    0.00   15721/15721       PathDerivative::PathDerivative(int) [111]
                0.00    0.00   15721/886667      PathAndDirection::getDirectionValue() const [81]
                0.00    0.00   15721/15721       PathDerivative::~PathDerivative() [112]
-----------------------------------------------
                0.01    0.02   15721/15721       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
[42]     0.0    0.01    0.02   15721         PathDerivative::calculate(Path*, Path*) [42]
                0.01    0.01   15721/15721       Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [45]
                0.00    0.00  347589/350111      StarLink::getLinkFnc() const [83]
                0.00    0.00  347589/1567900     StarLink::getFlow() const [76]
                0.00    0.00  347589/347589      BprFnc::evaluateDerivative(double) [84]
-----------------------------------------------
                0.00    0.00   31442/442060      Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.00    0.00   31442/442060      ODSet::calculateProjectedDirection() [48]
                0.00    0.00   33323/442060      ODSet::updateLinkCostsOfOD() [44]
                0.00    0.00   47163/442060      Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [45]
                0.01    0.00   82490/442060      ODSet::projectPathFlowOnLinks() [30]
                0.01    0.00  216200/442060      AdditivePC::calculate(Path*) const [37]
[43]     0.0    0.03    0.00  442060         Path::beginLink() const [43]
-----------------------------------------------
                0.00    0.03   15721/15721       PathBasedAlgo::mainLoop(ODSet*) [2]
[44]     0.0    0.00    0.03   15721         ODSet::updateLinkCostsOfOD() [44]
                0.01    0.01  909326/926548      StarLink::updateTime() [47]
                0.01    0.00  909326/10798368     Path::getNextLink() const [33]
                0.00    0.00   33323/442060      Path::beginLink() const [43]
-----------------------------------------------
                0.01    0.01   15721/15721       PathDerivative::calculate(Path*, Path*) [42]
[45]     0.0    0.01    0.01   15721         Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [45]
                0.01    0.00 1281641/10798368     Path::getNextLink() const [33]
                0.00    0.00   47163/442060      Path::beginLink() const [43]
                0.00    0.00 1281641/304388932     StarLink::getIndex() const [25]
-----------------------------------------------
                0.00    0.02       1/1           PathSet::initialise() [35]
[46]     0.0    0.00    0.02       1         AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.01     110/4100        ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
                0.00    0.00  169753/9529106     StarNetwork::getLink(int) [29]
                0.00    0.00  177675/607045      ShPathInterface::getInComeLink(int) const [56]
                0.00    0.00  177675/272778726     StarLink::getNodeFromIndex() const [9]
                0.00    0.00  169753/169753      PathSet::initialiseItself(StarLink*, PairOD*) [59]
                0.00    0.00    7922/427788      ShPathInterface::getCost(int) const [57]
                0.00    0.00  169753/584206      Path::addLinkToPath(StarLink*) [82]
                0.00    0.00   15844/253504      PairOD::getIndex() const [86]
                0.00    0.00    7922/253504      PairOD::getDemand() const [87]
                0.00    0.00    7922/245582      Origin::getNextDest() [88]
                0.00    0.00     110/18924       Origin::getIndex() const [110]
                0.00    0.00     110/3410        Origin::beginDest() [138]
                0.00    0.00     110/3300        ODMatrix::getNextOrigin() [139]
                0.00    0.00       1/30          ODMatrix::beginOrigin() [161]
-----------------------------------------------
                0.00    0.00    7566/926548      StarNetwork::calculateLinkCosts() [62]
                0.00    0.00    9656/926548      Parser::parseODMatrix(std::string const&, int) [61]
                0.01    0.01  909326/926548      ODSet::updateLinkCostsOfOD() [44]
[47]     0.0    0.01    0.01  926548         StarLink::updateTime() [47]
                0.01    0.00  916892/919414      BprFnc::evaluate(double) [50]
-----------------------------------------------
                0.00    0.02   15721/15721       ODSet::equilibrate() [34]
[48]     0.0    0.00    0.02   15721         ODSet::calculateProjectedDirection() [48]
                0.00    0.01   15721/15721       Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.01    0.00  855225/10798368     Path::getNextLink() const [33]
                0.00    0.00   31442/442060      Path::beginLink() const [43]
                0.00    0.00 1109043/304388932     StarLink::getIndex() const [25]
                0.00    0.00  855225/886667      PathAndDirection::getDirectionValue() const [81]
                0.00    0.00   31442/125768      PathAndDirection::getPath() const [97]
                0.00    0.00   31442/62884       PathBasedFlowMove::getNextPathDirection() [100]
                0.00    0.00   15721/31442       PathBasedFlowMove::beginPathDirection() [106]
-----------------------------------------------
                                   1             ObjectManager::getNet() <cycle 1> [166]
[49]     0.0    0.01    0.00       1         Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
                0.00    0.00    2522/2522        StarLink::StarLink(int, int, LinkFnc*) [65]
                0.00    0.00    2530/4410        Utils::skipOneLineComment(std::string, std::string) [136]
                0.00    0.00    2530/4534        Utils::removeWhiteSpaces(std::string&) [135]
                0.00    0.00    2522/2522        BprFnc::BprFnc(double, double, double, double) [141]
                0.00    0.00    2522/2522        StarNetwork::addLink(StarLink*) [140]
                0.00    0.00     929/929         StarNode::StarNode(int, bool) [151]
                0.00    0.00       5/71          Utils::getSubString(std::string, std::string, std::string) [158]
                0.00    0.00       3/3           Parser::checkEmptyValue(int) [170]
                0.00    0.00       1/1           Utils::extractName(char const*, std::string&) [259]
                0.00    0.00       1/1           StarNetwork::StarNetwork(int, int, std::string&) [242]
                                 929             StarNetwork::addNode(StarNode*) <cycle 1> [63]
-----------------------------------------------
                0.00    0.00    2522/919414      StarLink::StarLink(int, int, LinkFnc*) [65]
                0.01    0.00  916892/919414      StarLink::updateTime() [47]
[50]     0.0    0.01    0.00  919414         BprFnc::evaluate(double) [50]
-----------------------------------------------
                0.01    0.00   23131/23131       PathBasedAlgo::mainLoop(ODSet*) [2]
[51]     0.0    0.01    0.00   23131         ODSet::removeUnusedPaths() [51]
                0.00    0.00   45782/1252855     Path::getFlow() const [77]
                0.00    0.00   14353/22839       Path::~Path() [109]
-----------------------------------------------
                0.01    0.00     929/929         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
[52]     0.0    0.01    0.00     929         StarNetwork::getNextNode() [52]
-----------------------------------------------
                                                 <spontaneous>
[53]     0.0    0.01    0.00                 boost::heap::fibonacci_heap<ValueKey, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::marked_heap_node<ValueKey>*, boost::heap::detail::make_fibonacci_heap_base<ValueKey, boost::parameter::aux::empty_arg_list>::type, ValueKey&>) [53]
-----------------------------------------------
                                                 <spontaneous>
[54]     0.0    0.01    0.00                 BprFnc::evaluateSecondDerivative(double) [54]
-----------------------------------------------
                0.00    0.01   15721/15721       ODSet::calculateProjectedDirection() [48]
[55]     0.0    0.00    0.01   15721         Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.01    0.00  855225/10798368     Path::getNextLink() const [33]
                0.00    0.00   31442/442060      Path::beginLink() const [43]
                0.00    0.00  855225/304388932     StarLink::getIndex() const [25]
                0.00    0.00   31442/125768      PathAndDirection::getPath() const [97]
                0.00    0.00   31442/62884       PathBasedFlowMove::getNextPathDirection() [100]
                0.00    0.00   15721/31442       PathBasedFlowMove::beginPathDirection() [106]
-----------------------------------------------
                0.00    0.00  177675/607045      AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00  429370/607045      ODSet::improveSet() [3]
[56]     0.0    0.01    0.00  607045         ShPathInterface::getInComeLink(int) const [56]
-----------------------------------------------
                0.00    0.00    7922/427788      AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00  205972/427788      ODSet::improveSet() [3]
                0.00    0.00  213894/427788      RelGap::getMinTravelTime() [24]
[57]     0.0    0.01    0.00  427788         ShPathInterface::getCost(int) const [57]
-----------------------------------------------
                0.01    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
[58]     0.0    0.01    0.00       1         StarNetwork::beginNode() [58]
-----------------------------------------------
                0.00    0.00  169753/169753      AONAssignment::execute(InitialiseSolution*) [46]
[59]     0.0    0.00    0.00  169753         PathSet::initialiseItself(StarLink*, PairOD*) [59]
                0.00    0.00  169753/289113506     StarLink::getNodeToIndex() const [13]
                0.00    0.00  169753/177675      PairOD::getODIndex() const [94]
                0.00    0.00  169753/169753      ODSet::getDestIndex() const [95]
                0.00    0.00    7922/22839       Path::Path() [108]
                0.00    0.00    7922/39364       Path::setFlow(double) [104]
                0.00    0.00    7922/253504      PairOD::getDemand() const [87]
                0.00    0.00    7922/7922        ODSet::addPath(Path*) [124]
-----------------------------------------------
                                   1             ObjectManager::getConvMeasure() <cycle 1> [247]
                                   1             ObjectManager::getPathSet() <cycle 1> [66]
[60]     0.0    0.00    0.00       2         ObjectManager::getODMatrix() <cycle 1> [60]
                0.00    0.00       1/1           Parser::parseODMatrix(std::string const&, int) [61]
                0.00    0.00       2/16          Params::getParam(std::string) [165]
                0.00    0.00       1/2045        StarNetwork::getNbNodes() [148]
                0.00    0.00       1/1           ODMatrix::setIndexes(StarNetwork*) [267]
                                   1             ObjectManager::getNet() <cycle 1> [166]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getODMatrix() <cycle 1> [60]
[61]     0.0    0.00    0.00       1         Parser::parseODMatrix(std::string const&, int) [61]
                0.00    0.00    9656/926548      StarLink::updateTime() [47]
                0.00    0.00    7922/7922        Origin::addDestination(PairOD*) [128]
                0.00    0.00    7922/7922        PairOD::PairOD(int, double) [132]
                0.00    0.00    1880/4410        Utils::skipOneLineComment(std::string, std::string) [136]
                0.00    0.00    1880/4534        Utils::removeWhiteSpaces(std::string&) [135]
                0.00    0.00     110/110         Origin::Origin(int) [154]
                0.00    0.00     110/110         ODMatrix::addOrigin(Origin*) [156]
                0.00    0.00       1/1           ODMatrix::ODMatrix(int) [268]
-----------------------------------------------
                0.00    0.00       1/3           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.00    0.00       2/3           PathSet::initialise() [35]
[62]     0.0    0.00    0.00       3         StarNetwork::calculateLinkCosts() [62]
                0.00    0.00    7566/926548      StarLink::updateTime() [47]
-----------------------------------------------
                                 929             Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[63]     0.0    0.00    0.00     929         StarNetwork::addNode(StarNode*) <cycle 1> [63]
                0.00    0.00     929/1194337     StarNode::getID() [38]
                0.00    0.00     929/929         StarNode::setIndex(int) [150]
                                 929             ObjectManager::getEqAlgo() <cycle 1> [149]
-----------------------------------------------
                                                 <spontaneous>
[64]     0.0    0.00    0.00                 Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00    2522/272778726     StarLink::getNodeFromIndex() const [9]
                0.00    0.00    2522/289113506     StarLink::getNodeToIndex() const [13]
                0.00    0.00   15844/253504      PairOD::getDemand() const [87]
                0.00    0.00    7922/18924       Origin::getIndex() const [110]
                0.00    0.00    7922/253504      PairOD::getIndex() const [86]
                0.00    0.00    7922/245582      Origin::getNextDest() [88]
                0.00    0.00    5044/1567900     StarLink::getFlow() const [76]
                0.00    0.00    2522/73138       StarNetwork::getNextOnlyLink() [98]
                0.00    0.00    2043/2045        StarNetwork::getNbNodes() [148]
                0.00    0.00     110/3410        Origin::beginDest() [138]
                0.00    0.00     110/3300        ODMatrix::getNextOrigin() [139]
                0.00    0.00       1/30          ODMatrix::beginOrigin() [161]
                0.00    0.00       1/29          StarNetwork::beginOnlyLink() [162]
-----------------------------------------------
                0.00    0.00    2522/2522        Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[65]     0.0    0.00    0.00    2522         StarLink::StarLink(int, int, LinkFnc*) [65]
                0.00    0.00    2522/919414      BprFnc::evaluate(double) [50]
-----------------------------------------------
                                   1             ObjectManager::getEqAlgo() <cycle 1> [149]
[66]     0.0    0.00    0.00       1         ObjectManager::getPathSet() <cycle 1> [66]
                0.00    0.00       1/1           LinkFncContainer::LinkFncContainer(StarNetwork*) [67]
                0.00    0.00       1/2           ObjectManager::getPathAlgoApp() [171]
                0.00    0.00       1/3           ObjectManager::getPathAlgoType() [169]
                0.00    0.00       1/1           ObjectManager::getPathCost() [246]
                0.00    0.00       1/5           std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [167]
                0.00    0.00       1/1           PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                                   2             ObjectManager::getNet() <cycle 1> [166]
                                   1             ObjectManager::getODMatrix() <cycle 1> [60]
                                   1             ObjectManager::getShPath() <cycle 1> [19]
                                   1             ObjectManager::getConvMeasure() <cycle 1> [247]
                                   1             ObjectManager::getPathAlgoCreator() <cycle 1> [248]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathSet() <cycle 1> [66]
[67]     0.0    0.00    0.00       1         LinkFncContainer::LinkFncContainer(StarNetwork*) [67]
                0.00    0.00    2522/304388932     StarLink::getIndex() const [25]
                0.00    0.00    2522/73138       StarNetwork::getNextOnlyLink() [98]
                0.00    0.00    2522/350111      StarLink::getLinkFnc() const [83]
                0.00    0.00       1/7925        StarNetwork::getNbLinks() [115]
                0.00    0.00       1/29          StarNetwork::beginOnlyLink() [162]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[68]     0.0    0.00    0.00       1         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [68]
                0.00    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [69]
-----------------------------------------------
                0.00    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [68]
[69]     0.0    0.00    0.00       1         ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [69]
                0.00    0.00       2/422186      boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [27]
                0.00    0.00       1/1           std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [272]
                0.00    0.00       1/1           ShPathInterface::~ShPathInterface() [257]
-----------------------------------------------
                                                 <spontaneous>
[70]     0.0    0.00    0.00                 ObjectManager::~ObjectManager() [70]
                0.00    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [68]
                0.00    0.00       1/1           StarNetwork::~StarNetwork() [243]
                0.00    0.00       1/1           ODMatrix::~ODMatrix() [269]
                0.00    0.00       1/1           PathBasedAlgo::~PathBasedAlgo() [250]
                0.00    0.00       1/1           LinkFncContainer::~LinkFncContainer() [258]
                0.00    0.00       1/1           RelGap::~RelGap() [262]
                0.00    0.00       1/1           PathSet::~PathSet() [265]
                0.00    0.00       1/1           AdditivePC::~AdditivePC() [240]
                0.00    0.00       1/1           PathAlgoCreator::~PathAlgoCreator() [255]
-----------------------------------------------
                0.00    0.00    5044/1567900     Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00  136188/1567900     RelGap::isConverged() [23]
                0.00    0.00  347589/1567900     PathDerivative::calculate(Path*, Path*) [42]
                0.00    0.00 1079079/1567900     ODSet::projectPathFlowOnLinks() [30]
[76]     0.0    0.00    0.00 1567900         StarLink::getFlow() const [76]
-----------------------------------------------
                0.00    0.00   31442/1252855     PathBasedFlowMovePE::executeFlowMove() [113]
                0.00    0.00   45782/1252855     ODSet::removeUnusedPaths() [51]
                0.00    0.00   96552/1252855     ODSet::equilibrate() [34]
                0.00    0.00 1079079/1252855     ODSet::projectPathFlowOnLinks() [30]
[77]     0.0    0.00    0.00 1252855         Path::getFlow() const [77]
-----------------------------------------------
                0.00    0.00    2522/1195932     StarNetwork::createIndexes() <cycle 1> [241]
                0.00    0.00 1193410/1195932     StarNetwork::linkNodes() <cycle 1> [39]
[78]     0.0    0.00    0.00 1195932         StarLink::getNodeTo() const [78]
-----------------------------------------------
                0.00    0.00 1079079/1079079     ODSet::projectPathFlowOnLinks() [30]
[79]     0.0    0.00    0.00 1079079         StarLink::addFlow(double) [79]
-----------------------------------------------
                0.00    0.00 1079079/1079079     ODSet::projectPathFlowOnLinks() [30]
[80]     0.0    0.00    0.00 1079079         Path::getPrevFlow() const [80]
-----------------------------------------------
                0.00    0.00   15721/886667      DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
                0.00    0.00   15721/886667      PathBasedFlowMovePE::executeFlowMove() [113]
                0.00    0.00  855225/886667      ODSet::calculateProjectedDirection() [48]
[81]     0.0    0.00    0.00  886667         PathAndDirection::getDirectionValue() const [81]
-----------------------------------------------
                0.00    0.00  169753/584206      AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00  414453/584206      ODSet::improveSet() [3]
[82]     0.0    0.00    0.00  584206         Path::addLinkToPath(StarLink*) [82]
-----------------------------------------------
                0.00    0.00    2522/350111      LinkFncContainer::LinkFncContainer(StarNetwork*) [67]
                0.00    0.00  347589/350111      PathDerivative::calculate(Path*, Path*) [42]
[83]     0.0    0.00    0.00  350111         StarLink::getLinkFnc() const [83]
-----------------------------------------------
                0.00    0.00  347589/347589      PathDerivative::calculate(Path*, Path*) [42]
[84]     0.0    0.00    0.00  347589         BprFnc::evaluateDerivative(double) [84]
-----------------------------------------------
                0.00    0.00  277441/277441      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [17]
[85]     0.0    0.00    0.00  277441         std::vector<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, std::allocator<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&> > >::at(unsigned long) [85]
-----------------------------------------------
                0.00    0.00    7922/253504      ODMatrix::setIndexes(StarNetwork*) [267]
                0.00    0.00    7922/253504      Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00    7922/253504      PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                0.00    0.00   15844/253504      AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00  213894/253504      RelGap::getMinTravelTime() [24]
[86]     0.0    0.00    0.00  253504         PairOD::getIndex() const [86]
-----------------------------------------------
                0.00    0.00    7922/253504      ODMatrix::setIndexes(StarNetwork*) [267]
                0.00    0.00    7922/253504      AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00    7922/253504      PathSet::initialiseItself(StarLink*, PairOD*) [59]
                0.00    0.00   15844/253504      Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00  213894/253504      RelGap::getMinTravelTime() [24]
[87]     0.0    0.00    0.00  253504         PairOD::getDemand() const [87]
-----------------------------------------------
                0.00    0.00    7922/245582      ODMatrix::setIndexes(StarNetwork*) [267]
                0.00    0.00    7922/245582      Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00    7922/245582      AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00    7922/245582      PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                0.00    0.00  213894/245582      RelGap::getMinTravelTime() [24]
[88]     0.0    0.00    0.00  245582         Origin::getNextDest() [88]
-----------------------------------------------
                0.00    0.00   14917/231117      ODSet::improveSet() [3]
                0.00    0.00  216200/231117      ODSet::updateSet() [31]
[89]     0.0    0.00    0.00  231117         Path::setCurrCost(double) [89]
-----------------------------------------------
                                1020             OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [90]
                0.00    0.00    1026/206998      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.00    0.00  205972/206998      ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [4]
[90]     0.0    0.00    0.00  206998+1020    OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [90]
                                1020             OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [90]
-----------------------------------------------
                0.00    0.00  205972/205972      PathBasedAlgo::execute() [1]
[91]     0.0    0.00    0.00  205972         EquilibrationI::executeMainLoop(ODSet*) [91]
-----------------------------------------------
                0.00    0.00  205972/205972      PathBasedAlgo::execute() [1]
[92]     0.0    0.00    0.00  205972         PathSet::getNextSet() [92]
-----------------------------------------------
                0.00    0.00  191055/191055      PathBasedAlgo::mainLoop(ODSet*) [2]
[93]     0.0    0.00    0.00  191055         ODSet::getNbPaths() const [93]
-----------------------------------------------
                0.00    0.00    7922/177675      PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                0.00    0.00  169753/177675      PathSet::initialiseItself(StarLink*, PairOD*) [59]
[94]     0.0    0.00    0.00  177675         PairOD::getODIndex() const [94]
-----------------------------------------------
                0.00    0.00  169753/169753      PathSet::initialiseItself(StarLink*, PairOD*) [59]
[95]     0.0    0.00    0.00  169753         ODSet::getDestIndex() const [95]
-----------------------------------------------
                0.00    0.00   15844/165361      ODSet::addPath(Path*) [124]
                0.00    0.00   29834/165361      ODSet::improveSet() [3]
                0.00    0.00  119683/165361      DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [107]
[96]     0.0    0.00    0.00  165361         Path::getCurrCost() const [96]
-----------------------------------------------
                0.00    0.00   31442/125768      Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.00    0.00   31442/125768      ODSet::calculateProjectedDirection() [48]
                0.00    0.00   31442/125768      DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
                0.00    0.00   31442/125768      PathBasedFlowMovePE::executeFlowMove() [113]
[97]     0.0    0.00    0.00  125768         PathAndDirection::getPath() const [97]
-----------------------------------------------
                0.00    0.00    2522/73138       Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00    2522/73138       LinkFncContainer::LinkFncContainer(StarNetwork*) [67]
                0.00    0.00   68094/73138       RelGap::isConverged() [23]
[98]     0.0    0.00    0.00   73138         StarNetwork::getNextOnlyLink() [98]
-----------------------------------------------
                0.00    0.00   31442/62884       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [107]
                0.00    0.00   31442/62884       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
[99]     0.0    0.00    0.00   62884         PathAndDirection::setDirection(double) [99]
-----------------------------------------------
                0.00    0.00   31442/62884       Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.00    0.00   31442/62884       ODSet::calculateProjectedDirection() [48]
[100]    0.0    0.00    0.00   62884         PathBasedFlowMove::getNextPathDirection() [100]
-----------------------------------------------
                0.00    0.00   48276/48276       ODSet::equilibrate() [34]
[101]    0.0    0.00    0.00   48276         Path::setPrevFlow(double) [101]
-----------------------------------------------
                0.00    0.00   46262/46262       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [107]
[102]    0.0    0.00    0.00   46262         PathAndDirection::PathAndDirection() [102]
-----------------------------------------------
                0.00    0.00    6524/46262       DescDirectionPathScaled::~DescDirectionPathScaled() [123]
                0.00    0.00   14820/46262       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [107]
                0.00    0.00   24918/46262       PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [40]
[103]    0.0    0.00    0.00   46262         PathAndDirection::~PathAndDirection() [103]
-----------------------------------------------
                0.00    0.00    7922/39364       PathSet::initialiseItself(StarLink*, PairOD*) [59]
                0.00    0.00   31442/39364       PathBasedFlowMovePE::executeFlowMove() [113]
[104]    0.0    0.00    0.00   39364         Path::setFlow(double) [104]
-----------------------------------------------
                0.00    0.00   31442/31442       DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [107]
[105]    0.0    0.00    0.00   31442         PathAndDirection::setPath(Path*) [105]
-----------------------------------------------
                0.00    0.00   15721/31442       Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [55]
                0.00    0.00   15721/31442       ODSet::calculateProjectedDirection() [48]
[106]    0.0    0.00    0.00   31442         PathBasedFlowMove::beginPathDirection() [106]
-----------------------------------------------
                0.00    0.00   23131/23131       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
[107]    0.0    0.00    0.00   23131         DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [107]
                0.00    0.00  119683/165361      Path::getCurrCost() const [96]
                0.00    0.00   46262/46262       PathAndDirection::PathAndDirection() [102]
                0.00    0.00   31442/31442       PathAndDirection::setPath(Path*) [105]
                0.00    0.00   31442/62884       PathAndDirection::setDirection(double) [99]
                0.00    0.00   14820/46262       PathAndDirection::~PathAndDirection() [103]
-----------------------------------------------
                0.00    0.00    7922/22839       PathSet::initialiseItself(StarLink*, PairOD*) [59]
                0.00    0.00   14917/22839       ODSet::improveSet() [3]
[108]    0.0    0.00    0.00   22839         Path::Path() [108]
-----------------------------------------------
                0.00    0.00    8486/22839       ODSet::~ODSet() [127]
                0.00    0.00   14353/22839       ODSet::removeUnusedPaths() [51]
[109]    0.0    0.00    0.00   22839         Path::~Path() [109]
-----------------------------------------------
                0.00    0.00     110/18924       AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00    2970/18924       RelGap::getMinTravelTime() [24]
                0.00    0.00    7922/18924       Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00    7922/18924       PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
[110]    0.0    0.00    0.00   18924         Origin::getIndex() const [110]
-----------------------------------------------
                0.00    0.00   15721/15721       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
[111]    0.0    0.00    0.00   15721         PathDerivative::PathDerivative(int) [111]
-----------------------------------------------
                0.00    0.00   15721/15721       DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [41]
[112]    0.0    0.00    0.00   15721         PathDerivative::~PathDerivative() [112]
-----------------------------------------------
                0.00    0.00   15721/15721       PathBasedAlgo::mainLoop(ODSet*) [2]
[113]    0.0    0.00    0.00   15721         PathBasedFlowMovePE::executeFlowMove() [113]
                0.00    0.00   31442/125768      PathAndDirection::getPath() const [97]
                0.00    0.00   31442/1252855     Path::getFlow() const [77]
                0.00    0.00   31442/39364       Path::setFlow(double) [104]
                0.00    0.00   15721/886667      PathAndDirection::getDirectionValue() const [81]
-----------------------------------------------
                0.00    0.00       2/8034        StarNetwork::linkNodes() <cycle 1> [39]
                0.00    0.00    8032/8034        ODMatrix::setIndexes(StarNetwork*) [267]
[114]    0.0    0.00    0.00    8034         StarNetwork::getNodeIndex(int) [114]
-----------------------------------------------
                0.00    0.00       1/7925        ObjectManager::getPathAlgoCreator() <cycle 1> [248]
                0.00    0.00       1/7925        LinkFncContainer::LinkFncContainer(StarNetwork*) [67]
                0.00    0.00       1/7925        PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [263]
                0.00    0.00    7922/7925        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [125]
[115]    0.0    0.00    0.00    7925         StarNetwork::getNbLinks() [115]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [125]
[116]    0.0    0.00    0.00    7922         PathAlgoCreator::allocateDescDirectionPath() [116]
                0.00    0.00    7922/7922        DescDirectionPathPE::DescDirectionPathPE(double) [118]
                0.00    0.00    7922/7922        DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double) [122]
-----------------------------------------------
                0.00    0.00    7922/7922        PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [120]
[117]    0.0    0.00    0.00    7922         PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*) [117]
-----------------------------------------------
                0.00    0.00    7922/7922        PathAlgoCreator::allocateDescDirectionPath() [116]
[118]    0.0    0.00    0.00    7922         DescDirectionPathPE::DescDirectionPathPE(double) [118]
-----------------------------------------------
                0.00    0.00    7922/7922        DescDirectionPathScaled::~DescDirectionPathScaled() [123]
[119]    0.0    0.00    0.00    7922         DescDirectionPathPE::~DescDirectionPathPE() [119]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [125]
[120]    0.0    0.00    0.00    7922         PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [120]
                0.00    0.00    7922/7922        PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*) [117]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::~ODSet() [127]
[121]    0.0    0.00    0.00    7922         PathBasedFlowMovePE::~PathBasedFlowMovePE() [121]
-----------------------------------------------
                0.00    0.00    7922/7922        PathAlgoCreator::allocateDescDirectionPath() [116]
[122]    0.0    0.00    0.00    7922         DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double) [122]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::~ODSet() [127]
[123]    0.0    0.00    0.00    7922         DescDirectionPathScaled::~DescDirectionPathScaled() [123]
                0.00    0.00    7922/7922        DescDirectionPathPE::~DescDirectionPathPE() [119]
                0.00    0.00    6524/46262       PathAndDirection::~PathAndDirection() [103]
-----------------------------------------------
                0.00    0.00    7922/7922        PathSet::initialiseItself(StarLink*, PairOD*) [59]
[124]    0.0    0.00    0.00    7922         ODSet::addPath(Path*) [124]
                0.00    0.00   15844/165361      Path::getCurrCost() const [96]
-----------------------------------------------
                0.00    0.00    7922/7922        PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
[125]    0.0    0.00    0.00    7922         ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [125]
                0.00    0.00    7922/7925        StarNetwork::getNbLinks() [115]
                0.00    0.00    7922/7922        PathAlgoCreator::allocateDescDirectionPath() [116]
                0.00    0.00    7922/7922        PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [120]
-----------------------------------------------
                0.00    0.00    7922/7922        PathSet::~PathSet() [266]
[126]    0.0    0.00    0.00    7922         ODSet::~ODSet() [126]
                0.00    0.00    7922/7922        ODSet::~ODSet() [127]
-----------------------------------------------
                0.00    0.00    7922/7922        ODSet::~ODSet() [126]
[127]    0.0    0.00    0.00    7922         ODSet::~ODSet() [127]
                0.00    0.00    8486/22839       Path::~Path() [109]
                0.00    0.00    7922/7922        PathBasedFlowMovePE::~PathBasedFlowMovePE() [121]
                0.00    0.00    7922/7922        DescDirectionPathScaled::~DescDirectionPathScaled() [123]
-----------------------------------------------
                0.00    0.00    7922/7922        Parser::parseODMatrix(std::string const&, int) [61]
[128]    0.0    0.00    0.00    7922         Origin::addDestination(PairOD*) [128]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [267]
[129]    0.0    0.00    0.00    7922         PairOD::setODIndex(int) [129]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [267]
[130]    0.0    0.00    0.00    7922         PairOD::setOriginIndex(int) [130]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [267]
[131]    0.0    0.00    0.00    7922         PairOD::setIndex(int) [131]
-----------------------------------------------
                0.00    0.00    7922/7922        Parser::parseODMatrix(std::string const&, int) [61]
[132]    0.0    0.00    0.00    7922         PairOD::PairOD(int, double) [132]
-----------------------------------------------
                0.00    0.00    7922/7922        Origin::~Origin() [155]
[133]    0.0    0.00    0.00    7922         PairOD::~PairOD() [133]
-----------------------------------------------
                0.00    0.00    7922/7922        ODMatrix::setIndexes(StarNetwork*) [267]
[134]    0.0    0.00    0.00    7922         PairOD::getID() const [134]
-----------------------------------------------
                0.00    0.00       1/4534        ObjectManager::getNet() <cycle 1> [166]
                0.00    0.00       1/4534        ObjectManager::getPathAlgoType() [169]
                0.00    0.00       1/4534        ObjectManager::getPathAlgoApp() [171]
                0.00    0.00       2/4534        ObjectManager::getEqAlgo() <cycle 1> [149]
                0.00    0.00     119/4534        ParseParams::execute(Params*) [337]
                0.00    0.00    1880/4534        Parser::parseODMatrix(std::string const&, int) [61]
                0.00    0.00    2530/4534        Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[135]    0.0    0.00    0.00    4534         Utils::removeWhiteSpaces(std::string&) [135]
-----------------------------------------------
                0.00    0.00    1880/4410        Parser::parseODMatrix(std::string const&, int) [61]
                0.00    0.00    2530/4410        Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[136]    0.0    0.00    0.00    4410         Utils::skipOneLineComment(std::string, std::string) [136]
-----------------------------------------------
                0.00    0.00     929/3449        ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
                0.00    0.00    2520/3449        StarNetwork::linkNodes() <cycle 1> [39]
[137]    0.0    0.00    0.00    3449         StarNode::getIndex() [137]
-----------------------------------------------
                0.00    0.00     110/3410        ODMatrix::setIndexes(StarNetwork*) [267]
                0.00    0.00     110/3410        Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00     110/3410        AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00     110/3410        PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                0.00    0.00    2970/3410        RelGap::getMinTravelTime() [24]
[138]    0.0    0.00    0.00    3410         Origin::beginDest() [138]
-----------------------------------------------
                0.00    0.00     110/3300        Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00     110/3300        AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00     110/3300        PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                0.00    0.00    2970/3300        RelGap::getMinTravelTime() [24]
[139]    0.0    0.00    0.00    3300         ODMatrix::getNextOrigin() [139]
-----------------------------------------------
                0.00    0.00    2522/2522        Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[140]    0.0    0.00    0.00    2522         StarNetwork::addLink(StarLink*) [140]
                0.00    0.00    2522/2522        StarLink::setIndex(int) [145]
                0.00    0.00    2522/2522        StarLink::setNodeFromIndex(int) [144]
-----------------------------------------------
                0.00    0.00    2522/2522        Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[141]    0.0    0.00    0.00    2522         BprFnc::BprFnc(double, double, double, double) [141]
-----------------------------------------------
                0.00    0.00    2522/2522        StarLink::~StarLink() [146]
[142]    0.0    0.00    0.00    2522         BprFnc::~BprFnc() [142]
-----------------------------------------------
                0.00    0.00    2522/2522        StarNetwork::linkNodes() <cycle 1> [39]
[143]    0.0    0.00    0.00    2522         StarLink::setNodeToIndex(int) [143]
-----------------------------------------------
                0.00    0.00    2522/2522        StarNetwork::addLink(StarLink*) [140]
[144]    0.0    0.00    0.00    2522         StarLink::setNodeFromIndex(int) [144]
-----------------------------------------------
                0.00    0.00    2522/2522        StarNetwork::addLink(StarLink*) [140]
[145]    0.0    0.00    0.00    2522         StarLink::setIndex(int) [145]
-----------------------------------------------
                0.00    0.00    2522/2522        StarNetwork::~StarNetwork() [243]
[146]    0.0    0.00    0.00    2522         StarLink::~StarLink() [146]
                0.00    0.00    2522/2522        BprFnc::~BprFnc() [142]
-----------------------------------------------
                0.00    0.00    2285/2285        ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
[147]    0.0    0.00    0.00    2285         std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&) [147]
-----------------------------------------------
                0.00    0.00       1/2045        ObjectManager::getODMatrix() <cycle 1> [60]
                0.00    0.00       1/2045        ShPathInterface::ShPathInterface(StarNetwork*) [256]
                0.00    0.00    2043/2045        Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
[148]    0.0    0.00    0.00    2045         StarNetwork::getNbNodes() [148]
-----------------------------------------------
                                   1             StarNetwork::createIndexes() <cycle 1> [241]
                                 929             StarNetwork::addNode(StarNode*) <cycle 1> [63]
[149]    0.0    0.00    0.00     930         ObjectManager::getEqAlgo() <cycle 1> [149]
                0.00    0.00       2/16          Params::getParam(std::string) [165]
                0.00    0.00       2/4534        Utils::removeWhiteSpaces(std::string&) [135]
                0.00    0.00       1/3           ObjectManager::getPathAlgoType() [169]
                0.00    0.00       1/1           PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [249]
                                   1             ObjectManager::getPathSet() <cycle 1> [66]
-----------------------------------------------
                0.00    0.00     929/929         StarNetwork::addNode(StarNode*) <cycle 1> [63]
[150]    0.0    0.00    0.00     929         StarNode::setIndex(int) [150]
-----------------------------------------------
                0.00    0.00     929/929         Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[151]    0.0    0.00    0.00     929         StarNode::StarNode(int, bool) [151]
-----------------------------------------------
                0.00    0.00     929/929         StarNetwork::~StarNetwork() [243]
[152]    0.0    0.00    0.00     929         StarNode::~StarNode() [152]
-----------------------------------------------
                0.00    0.00     110/110         ODMatrix::setIndexes(StarNetwork*) [267]
[153]    0.0    0.00    0.00     110         Origin::setIndex(int) [153]
-----------------------------------------------
                0.00    0.00     110/110         Parser::parseODMatrix(std::string const&, int) [61]
[154]    0.0    0.00    0.00     110         Origin::Origin(int) [154]
-----------------------------------------------
                0.00    0.00     110/110         ODMatrix::~ODMatrix() [269]
[155]    0.0    0.00    0.00     110         Origin::~Origin() [155]
                0.00    0.00    7922/7922        PairOD::~PairOD() [133]
-----------------------------------------------
                0.00    0.00     110/110         Parser::parseODMatrix(std::string const&, int) [61]
[156]    0.0    0.00    0.00     110         ODMatrix::addOrigin(Origin*) [156]
-----------------------------------------------
                0.00    0.00     110/110         ODMatrix::setIndexes(StarNetwork*) [267]
[157]    0.0    0.00    0.00     110         Origin::getID() const [157]
-----------------------------------------------
                0.00    0.00       5/71          Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
                0.00    0.00      66/71          ParseParams::execute(Params*) [337]
[158]    0.0    0.00    0.00      71         Utils::getSubString(std::string, std::string, std::string) [158]
-----------------------------------------------
                                  33             ParseParams::skipComments(std::string) [159]
                0.00    0.00      33/33          Params::addParameter(std::string, std::string) [160]
[159]    0.0    0.00    0.00      33+33      ParseParams::skipComments(std::string) [159]
                                  33             ParseParams::skipComments(std::string) [159]
-----------------------------------------------
                0.00    0.00      33/33          ParseParams::execute(Params*) [337]
[160]    0.0    0.00    0.00      33         Params::addParameter(std::string, std::string) [160]
                0.00    0.00      33/33          ParseParams::skipComments(std::string) [159]
-----------------------------------------------
                0.00    0.00       1/30          Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00       1/30          AONAssignment::execute(InitialiseSolution*) [46]
                0.00    0.00       1/30          PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                0.00    0.00      27/30          RelGap::getMinTravelTime() [24]
[161]    0.0    0.00    0.00      30         ODMatrix::beginOrigin() [161]
-----------------------------------------------
                0.00    0.00       1/29          Utils::checkFeasibility(StarNetwork*, ODMatrix*) [64]
                0.00    0.00       1/29          LinkFncContainer::LinkFncContainer(StarNetwork*) [67]
                0.00    0.00      27/29          RelGap::isConverged() [23]
[162]    0.0    0.00    0.00      29         StarNetwork::beginOnlyLink() [162]
-----------------------------------------------
                0.00    0.00      27/27          PathBasedAlgo::execute() [1]
[163]    0.0    0.00    0.00      27         PathSet::isConverged() const [163]
-----------------------------------------------
                0.00    0.00      26/26          PathBasedAlgo::execute() [1]
[164]    0.0    0.00    0.00      26         PathSet::beginSet() [164]
-----------------------------------------------
                0.00    0.00       1/16          ObjectManager::getPathAlgoType() [169]
                0.00    0.00       1/16          ObjectManager::getPathAlgoApp() [171]
                0.00    0.00       2/16          ObjectManager::getODMatrix() <cycle 1> [60]
                0.00    0.00       2/16          ObjectManager::getShPath() <cycle 1> [19]
                0.00    0.00       2/16          ObjectManager::getEqAlgo() <cycle 1> [149]
                0.00    0.00       3/16          ObjectManager::getNet() <cycle 1> [166]
                0.00    0.00       5/16          std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [167]
[165]    0.0    0.00    0.00      16         Params::getParam(std::string) [165]
-----------------------------------------------
                                   1             ObjectManager::getODMatrix() <cycle 1> [60]
                                   1             ObjectManager::getShPath() <cycle 1> [19]
                                   1             ObjectManager::getConvMeasure() <cycle 1> [247]
                                   1             ObjectManager::getPathAlgoCreator() <cycle 1> [248]
                                   2             ObjectManager::getPathSet() <cycle 1> [66]
[166]    0.0    0.00    0.00       6         ObjectManager::getNet() <cycle 1> [166]
                0.00    0.00       3/16          Params::getParam(std::string) [165]
                0.00    0.00       1/4534        Utils::removeWhiteSpaces(std::string&) [135]
                                   1             Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
                                   1             StarNetwork::linkNodes() <cycle 1> [39]
-----------------------------------------------
                0.00    0.00       1/5           ObjectManager::getConvMeasure() <cycle 1> [247]
                0.00    0.00       1/5           ObjectManager::getPathSet() <cycle 1> [66]
                0.00    0.00       3/5           ObjectManager::getPathAlgoCreator() <cycle 1> [248]
[167]    0.0    0.00    0.00       5         std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [167]
                0.00    0.00       5/16          Params::getParam(std::string) [165]
-----------------------------------------------
                0.00    0.00       5/5           ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [20]
[168]    0.0    0.00    0.00       5         bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*) [168]
-----------------------------------------------
                0.00    0.00       1/3           ObjectManager::getPathAlgoCreator() <cycle 1> [248]
                0.00    0.00       1/3           ObjectManager::getPathSet() <cycle 1> [66]
                0.00    0.00       1/3           ObjectManager::getEqAlgo() <cycle 1> [149]
[169]    0.0    0.00    0.00       3         ObjectManager::getPathAlgoType() [169]
                0.00    0.00       1/16          Params::getParam(std::string) [165]
                0.00    0.00       1/4534        Utils::removeWhiteSpaces(std::string&) [135]
-----------------------------------------------
                0.00    0.00       3/3           Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[170]    0.0    0.00    0.00       3         Parser::checkEmptyValue(int) [170]
-----------------------------------------------
                0.00    0.00       1/2           ObjectManager::getPathAlgoCreator() <cycle 1> [248]
                0.00    0.00       1/2           ObjectManager::getPathSet() <cycle 1> [66]
[171]    0.0    0.00    0.00       2         ObjectManager::getPathAlgoApp() [171]
                0.00    0.00       1/16          Params::getParam(std::string) [165]
                0.00    0.00       1/4534        Utils::removeWhiteSpaces(std::string&) [135]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[172]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10AdditivePCC2Ev [172]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[173]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10AlgorithmB9zeroFlow_E [173]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[174]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10DerivativeC2EdP16LinkFncContainer [174]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[175]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10FileReaderC2ERKSs [175]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[176]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10FileWriterC2ERKSs [176]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[177]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN10OriginBush15wasInitialised_E [177]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[178]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11DAGraphLUCEC2EP11StarNetworkP8ODMatrixddi [178]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[179]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11DAGraphNodeC2Eid [179]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[180]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11MarginalFncC2EP7LinkFnc [180]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[181]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11ParseParamsC2ESs [181]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[182]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11StarNetworkC2EiiRSs [182]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[183]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN11StepSizeAddC2EP13DescDirectionidP10LineSearchP10Derivative [183]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[184]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN12LinkFlowsBFW14allocateMemoryEv [184]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[185]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN12LinkFlowsCFW14allocateMemoryEv [185]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[186]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13AONAssignmentC2EP8ODMatrixP12ShortestPath [186]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[187]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13NonAdditivePCC2Ev [187]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[188]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13ObjectManagerC2EP6Params [188]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[189]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13PathBasedAlgoC2EP7PathSetb [189]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[190]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13ShPathFactoryC2Ev [190]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[191]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN13SpiessFncCombC2EP9SpiessFncS1_ [191]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[192]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14EquilibrationIC2EP13PathBasedAlgo [192]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[193]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14OriginBushLUCEC2EiP11StarNetwork [193]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[194]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14PathDerivativeC2Ei [194]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[195]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN14StepSizeNonAddC2EP13DescDirectionidP10LineSearchP10Derivative [195]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[196]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN15EquilibrationIIC2EP13PathBasedAlgo [196]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[197]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN15OriginBasedAlgoC2EP9OriginSet [197]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[198]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN15PathAlgoCreatorC2E12PathAlgoType7PathAppiddd [198]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[199]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16LinkFncContainerC2EP11StarNetwork [199]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[200]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16PathAndDirectionC2Ev [200]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[201]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16SpiessFncCreatorC2Ev [201]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[202]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN16StepSizeSparsityC2EP8StepSize [202]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[203]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN17LabelCorrectingAlC2EP11StarNetwork [203]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[204]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN17OnePathDerivativeC2Ed [204]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[205]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN17PathBasedFlowMoveC2EP17DescDirectionPath [205]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[206]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19DescDirectionPathGPC2Ed [206]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[207]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19DescDirectionPathPEC2Ed [207]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[208]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19DescDirectionPathPGC2Ed [208]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[209]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19PathBasedFlowMoveGPC2EddP17DescDirectionPath [209]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[210]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN19PathBasedFlowMovePEC2EP17DescDirectionPath [210]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[211]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN20DescDirectionPathISPC2Eddd [211]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[212]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN23DescDirectionPathScaledC2EP17DescDirectionPathid [212]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[213]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN25PathBasedFlowMoveWithStepC2EP11StepSizeABCP17DescDirectionPath [213]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[214]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN4PathC2Ev [214]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[215]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN5ODSet16initialiseObjectEiiiP8PathCostP16LinkFncContainerP11StarNetworkP12ShortestPathP11ConvMeasuredPdSA_P15PathAlgoCreator [215]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[216]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN5Utils16getDisjointLinksEP4PathS1_RSt4listIP8StarLinkSaIS4_EEi [216]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[217]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN5Utils17removeWhiteSpacesERSs [217]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[218]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6ArmijoC2EdP10Derivative [218]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[219]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6BprFncC2Edddd [219]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[220]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6FWAlgoC2EP9LinkFlows [220]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[221]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6OriginC2Ei [221]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[222]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6PairODC2Eid [222]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[223]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6ParamsC2Ev [223]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[224]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6ParserC2Ev [224]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[225]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN6RelGapC2EdP11StarNetworkP8ODMatrixP12ShortestPath [225]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[226]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN7DAGraph4net_E [226]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[227]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN7PathSet16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP11ConvMeasureP8PathCost [227]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[228]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN7QuadAppC2EP10Derivative [228]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[229]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8ConstFncC2Ed [229]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[230]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8ODMatrixC2Ei [230]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[231]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8StarLinkC2EiiP7LinkFnc [231]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[232]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN8StepSizeC2EP13DescDirectionidP10LineSearch [232]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[233]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9BisectionC2EdP10Derivative [233]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[234]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9LinearFncC2Edd [234]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[235]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9LinkFlows16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP10DerivativeP10LineSearchP11ConvMeasure [235]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[236]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9OriginSetC2EP8ODMatrixP11StarNetworkP12ShortestPathP11ConvMeasureddb [236]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[237]    0.0    0.00    0.00       1         _GLOBAL__sub_I__ZN9SpiessFncC2Eddddd [237]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [807]
[238]    0.0    0.00    0.00       1         _GLOBAL__sub_I_main [238]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathCost() [246]
[239]    0.0    0.00    0.00       1         AdditivePC::AdditivePC() [239]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[240]    0.0    0.00    0.00       1         AdditivePC::~AdditivePC() [240]
-----------------------------------------------
                                   1             StarNetwork::linkNodes() <cycle 1> [39]
[241]    0.0    0.00    0.00       1         StarNetwork::createIndexes() <cycle 1> [241]
                0.00    0.00    2522/1195932     StarLink::getNodeTo() const [78]
                                   1             ObjectManager::getEqAlgo() <cycle 1> [149]
-----------------------------------------------
                0.00    0.00       1/1           Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[242]    0.0    0.00    0.00       1         StarNetwork::StarNetwork(int, int, std::string&) [242]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[243]    0.0    0.00    0.00       1         StarNetwork::~StarNetwork() [243]
                0.00    0.00    2522/2522        StarLink::~StarLink() [146]
                0.00    0.00     929/929         StarNode::~StarNode() [152]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::initialise() [35]
[244]    0.0    0.00    0.00       1         AONAssignment::AONAssignment(ODMatrix*, ShortestPath*) [244]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::initialise() [35]
[245]    0.0    0.00    0.00       1         AONAssignment::~AONAssignment() [245]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathSet() <cycle 1> [66]
[246]    0.0    0.00    0.00       1         ObjectManager::getPathCost() [246]
                0.00    0.00       1/1           AdditivePC::AdditivePC() [239]
-----------------------------------------------
                                   1             ObjectManager::getPathSet() <cycle 1> [66]
[247]    0.0    0.00    0.00       1         ObjectManager::getConvMeasure() <cycle 1> [247]
                0.00    0.00       1/5           std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [167]
                0.00    0.00       1/1           RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*) [261]
                                   1             ObjectManager::getNet() <cycle 1> [166]
                                   1             ObjectManager::getODMatrix() <cycle 1> [60]
                                   1             ObjectManager::getShPath() <cycle 1> [19]
-----------------------------------------------
                                   1             ObjectManager::getPathSet() <cycle 1> [66]
[248]    0.0    0.00    0.00       1         ObjectManager::getPathAlgoCreator() <cycle 1> [248]
                0.00    0.00       3/5           std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*) [167]
                0.00    0.00       1/3           ObjectManager::getPathAlgoType() [169]
                0.00    0.00       1/7925        StarNetwork::getNbLinks() [115]
                0.00    0.00       1/2           ObjectManager::getPathAlgoApp() [171]
                0.00    0.00       1/1           PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double) [254]
                                   1             ObjectManager::getNet() <cycle 1> [166]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getEqAlgo() <cycle 1> [149]
[249]    0.0    0.00    0.00       1         PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [249]
                0.00    0.00       1/1           EquilibrationI::EquilibrationI(PathBasedAlgo*) [252]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[250]    0.0    0.00    0.00       1         PathBasedAlgo::~PathBasedAlgo() [250]
                0.00    0.00       1/1           EquilibrationI::~EquilibrationI() [253]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getShPath() <cycle 1> [19]
[251]    0.0    0.00    0.00       1         ShPathFactory::get() [251]
-----------------------------------------------
                0.00    0.00       1/1           PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [249]
[252]    0.0    0.00    0.00       1         EquilibrationI::EquilibrationI(PathBasedAlgo*) [252]
-----------------------------------------------
                0.00    0.00       1/1           PathBasedAlgo::~PathBasedAlgo() [250]
[253]    0.0    0.00    0.00       1         EquilibrationI::~EquilibrationI() [253]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathAlgoCreator() <cycle 1> [248]
[254]    0.0    0.00    0.00       1         PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double) [254]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[255]    0.0    0.00    0.00       1         PathAlgoCreator::~PathAlgoCreator() [255]
-----------------------------------------------
                0.00    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
[256]    0.0    0.00    0.00       1         ShPathInterface::ShPathInterface(StarNetwork*) [256]
                0.00    0.00       1/2045        StarNetwork::getNbNodes() [148]
-----------------------------------------------
                0.00    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [69]
[257]    0.0    0.00    0.00       1         ShPathInterface::~ShPathInterface() [257]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[258]    0.0    0.00    0.00       1         LinkFncContainer::~LinkFncContainer() [258]
-----------------------------------------------
                0.00    0.00       1/1           Parser::parseNetwork(std::string const&, bool) <cycle 1> [49]
[259]    0.0    0.00    0.00       1         Utils::extractName(char const*, std::string&) [259]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::ObjectManager(Params*) [419]
[260]    0.0    0.00    0.00       1         Parser::Parser() [260]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getConvMeasure() <cycle 1> [247]
[261]    0.0    0.00    0.00       1         RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*) [261]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[262]    0.0    0.00    0.00       1         RelGap::~RelGap() [262]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
[263]    0.0    0.00    0.00       1         PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [263]
                0.00    0.00       1/1           ODMatrix::getNbODPairs() const [270]
                0.00    0.00       1/7925        StarNetwork::getNbLinks() [115]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getPathSet() <cycle 1> [66]
[264]    0.0    0.00    0.00       1         PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*) [264]
                0.00    0.00    7922/177675      PairOD::getODIndex() const [94]
                0.00    0.00    7922/18924       Origin::getIndex() const [110]
                0.00    0.00    7922/253504      PairOD::getIndex() const [86]
                0.00    0.00    7922/7922        ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [125]
                0.00    0.00    7922/245582      Origin::getNextDest() [88]
                0.00    0.00     110/3410        Origin::beginDest() [138]
                0.00    0.00     110/3300        ODMatrix::getNextOrigin() [139]
                0.00    0.00       1/30          ODMatrix::beginOrigin() [161]
                0.00    0.00       1/1           PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [263]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[265]    0.0    0.00    0.00       1         PathSet::~PathSet() [265]
                0.00    0.00       1/1           PathSet::~PathSet() [266]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::~PathSet() [265]
[266]    0.0    0.00    0.00       1         PathSet::~PathSet() [266]
                0.00    0.00    7922/7922        ODSet::~ODSet() [126]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::getODMatrix() <cycle 1> [60]
[267]    0.0    0.00    0.00       1         ODMatrix::setIndexes(StarNetwork*) [267]
                0.00    0.00    8032/8034        StarNetwork::getNodeIndex(int) [114]
                0.00    0.00    7922/7922        PairOD::getID() const [134]
                0.00    0.00    7922/7922        PairOD::setIndex(int) [131]
                0.00    0.00    7922/7922        PairOD::setODIndex(int) [129]
                0.00    0.00    7922/7922        PairOD::setOriginIndex(int) [130]
                0.00    0.00    7922/253504      PairOD::getIndex() const [86]
                0.00    0.00    7922/253504      PairOD::getDemand() const [87]
                0.00    0.00    7922/245582      Origin::getNextDest() [88]
                0.00    0.00     110/110         Origin::getID() const [157]
                0.00    0.00     110/3410        Origin::beginDest() [138]
                0.00    0.00     110/110         Origin::setIndex(int) [153]
-----------------------------------------------
                0.00    0.00       1/1           Parser::parseODMatrix(std::string const&, int) [61]
[268]    0.0    0.00    0.00       1         ODMatrix::ODMatrix(int) [268]
-----------------------------------------------
                0.00    0.00       1/1           ObjectManager::~ObjectManager() [70]
[269]    0.0    0.00    0.00       1         ODMatrix::~ODMatrix() [269]
                0.00    0.00     110/110         Origin::~Origin() [155]
-----------------------------------------------
                0.00    0.00       1/1           PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*) [263]
[270]    0.0    0.00    0.00       1         ODMatrix::getNbODPairs() const [270]
-----------------------------------------------
                0.00    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [21]
[271]    0.0    0.00    0.00       1         std::vector<bool, std::allocator<bool> >::_M_initialize(unsigned long) [271]
-----------------------------------------------
                                  55             std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [272]
                0.00    0.00       1/1           ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [69]
[272]    0.0    0.00    0.00       1+55      std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [272]
                                  55             std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*) [272]
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

 [172] _GLOBAL__sub_I__ZN10AdditivePCC2Ev (AdditivePC.cpp) [46] AONAssignment::execute(InitialiseSolution*) [84] BprFnc::evaluateDerivative(double)
 [173] _GLOBAL__sub_I__ZN10AlgorithmB9zeroFlow_E (AlgorithmB.cpp) [244] AONAssignment::AONAssignment(ODMatrix*, ShortestPath*) [54] BprFnc::evaluateSecondDerivative(double)
 [174] _GLOBAL__sub_I__ZN10DerivativeC2EdP16LinkFncContainer (Derivative.cpp) [245] AONAssignment::~AONAssignment() [50] BprFnc::evaluate(double)
 [175] _GLOBAL__sub_I__ZN10FileReaderC2ERKSs (FileReader.cpp) [66] ObjectManager::getPathSet() [141] BprFnc::BprFnc(double, double, double, double)
 [176] _GLOBAL__sub_I__ZN10FileWriterC2ERKSs (FileWriter.cpp) [60] ObjectManager::getODMatrix() [142] BprFnc::~BprFnc()
 [177] _GLOBAL__sub_I__ZN10OriginBush15wasInitialised_E (OriginBush.cpp) [246] ObjectManager::getPathCost() [88] Origin::getNextDest()
 [178] _GLOBAL__sub_I__ZN11DAGraphLUCEC2EP11StarNetworkP8ODMatrixddi (DAGraphLUCE.cpp) [247] ObjectManager::getConvMeasure() [128] Origin::addDestination(PairOD*)
 [179] _GLOBAL__sub_I__ZN11DAGraphNodeC2Eid (DAGraphNode.cpp) [171] ObjectManager::getPathAlgoApp() [153] Origin::setIndex(int)
 [180] _GLOBAL__sub_I__ZN11MarginalFncC2EP7LinkFnc (MarginalFnc.cpp) [169] ObjectManager::getPathAlgoType() [138] Origin::beginDest()
 [181] _GLOBAL__sub_I__ZN11ParseParamsC2ESs (ParseParams.cpp) [248] ObjectManager::getPathAlgoCreator() [154] Origin::Origin(int)
 [182] _GLOBAL__sub_I__ZN11StarNetworkC2EiiRSs (StarNetwork.cpp) [166] ObjectManager::getNet() [155] Origin::~Origin()
 [183] _GLOBAL__sub_I__ZN11StepSizeAddC2EP13DescDirectionidP10LineSearchP10Derivative (StepSizeAdd.cpp) [149] ObjectManager::getEqAlgo() [129] PairOD::setODIndex(int)
 [184] _GLOBAL__sub_I__ZN12LinkFlowsBFW14allocateMemoryEv (LinkFlowsBFW.cpp) [19] ObjectManager::getShPath() [130] PairOD::setOriginIndex(int)
 [185] _GLOBAL__sub_I__ZN12LinkFlowsCFW14allocateMemoryEv (LinkFlowsCFW.cpp) [2] PathBasedAlgo::mainLoop(ODSet*) [131] PairOD::setIndex(int)
 [186] _GLOBAL__sub_I__ZN13AONAssignmentC2EP8ODMatrixP12ShortestPath (AONAssignment.cpp) [249] PathBasedAlgo::PathBasedAlgo(PathSet*, bool) [132] PairOD::PairOD(int, double)
 [187] _GLOBAL__sub_I__ZN13NonAdditivePCC2Ev (NonAdditivePC.cpp) [250] PathBasedAlgo::~PathBasedAlgo() [133] PairOD::~PairOD()
 [188] _GLOBAL__sub_I__ZN13ObjectManagerC2EP6Params (ObjectManager.cpp) [251] ShPathFactory::get() [160] Params::addParameter(std::string, std::string)
 [189] _GLOBAL__sub_I__ZN13PathBasedAlgoC2EP7PathSetb (PathBasedAlgo.cpp) [20] ShPathFactory::getShPath(std::string const&, std::string const&, StarNetwork*) [165] Params::getParam(std::string)
 [190] _GLOBAL__sub_I__ZN13ShPathFactoryC2Ev (ShPathFactory.cpp) [91] EquilibrationI::executeMainLoop(ODSet*) [49] Parser::parseNetwork(std::string const&, bool)
 [191] _GLOBAL__sub_I__ZN13SpiessFncCombC2EP9SpiessFncS1_ (SpiessFncComb.cpp) [252] EquilibrationI::EquilibrationI(PathBasedAlgo*) [61] Parser::parseODMatrix(std::string const&, int)
 [192] _GLOBAL__sub_I__ZN14EquilibrationIC2EP13PathBasedAlgo (EquilibrationI.cpp) [253] EquilibrationI::~EquilibrationI() [170] Parser::checkEmptyValue(int)
 [193] _GLOBAL__sub_I__ZN14OriginBushLUCEC2EiP11StarNetwork (OriginBushLUCE.cpp) [90] OriginBushLUCE::OriginBushLUCE(int, StarNetwork*) [260] Parser::Parser()
 [194] _GLOBAL__sub_I__ZN14PathDerivativeC2Ei (PathDerivative.cpp) [42] PathDerivative::calculate(Path*, Path*) [23] RelGap::isConverged()
 [195] _GLOBAL__sub_I__ZN14StepSizeNonAddC2EP13DescDirectionidP10LineSearchP10Derivative (StepSizeNonAdd.cpp) [111] PathDerivative::PathDerivative(int) [24] RelGap::getMinTravelTime()
 [196] _GLOBAL__sub_I__ZN15EquilibrationIIC2EP13PathBasedAlgo (EquilibrationII.cpp) [112] PathDerivative::~PathDerivative() [261] RelGap::RelGap(double, StarNetwork*, ODMatrix*, ShortestPath*)
 [197] _GLOBAL__sub_I__ZN15OriginBasedAlgoC2EP9OriginSet (OriginBasedAlgo.cpp) [116] PathAlgoCreator::allocateDescDirectionPath() [262] RelGap::~RelGap()
 [198] _GLOBAL__sub_I__ZN15PathAlgoCreatorC2E12PathAlgoType7PathAppiddd (PathAlgoCreator.cpp) [254] PathAlgoCreator::PathAlgoCreator(PathAlgoType, PathApp, int, double, double, double) [92] PathSet::getNextSet()
 [199] _GLOBAL__sub_I__ZN16LinkFncContainerC2EP11StarNetwork (LinkFncContainer.cpp) [255] PathAlgoCreator::~PathAlgoCreator() [35] PathSet::initialise()
 [200] _GLOBAL__sub_I__ZN16PathAndDirectionC2Ev (PathAndDirection.cpp) [256] ShPathInterface::ShPathInterface(StarNetwork*) [59] PathSet::initialiseItself(StarLink*, PairOD*)
 [201] _GLOBAL__sub_I__ZN16SpiessFncCreatorC2Ev (SpiessFncCreator.cpp) [257] ShPathInterface::~ShPathInterface() [263] PathSet::initialiseObject(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*)
 [202] _GLOBAL__sub_I__ZN16StepSizeSparsityC2EP8StepSize (StepSizeSparsity.cpp) [67] LinkFncContainer::LinkFncContainer(StarNetwork*) [164] PathSet::beginSet()
 [203] _GLOBAL__sub_I__ZN17LabelCorrectingAlC2EP11StarNetwork (LabelCorrectingAl.cpp) [258] LinkFncContainer::~LinkFncContainer() [264] PathSet::PathSet(StarNetwork*, ODMatrix*, LinkFncContainer*, ShortestPath*, ConvMeasure*, PathCost*, double, PathAlgoCreator*)
 [204] _GLOBAL__sub_I__ZN17OnePathDerivativeC2Ed (OnePathDerivative.cpp) [99] PathAndDirection::setDirection(double) [265] PathSet::~PathSet()
 [205] _GLOBAL__sub_I__ZN17PathBasedFlowMoveC2EP17DescDirectionPath (PathBasedFlowMove.cpp) [105] PathAndDirection::setPath(Path*) [266] PathSet::~PathSet()
 [206] _GLOBAL__sub_I__ZN19DescDirectionPathGPC2Ed (DescDirectionPathGP.cpp) [102] PathAndDirection::PathAndDirection() [267] ODMatrix::setIndexes(StarNetwork*)
 [207] _GLOBAL__sub_I__ZN19DescDirectionPathPEC2Ed (DescDirectionPathPE.cpp) [103] PathAndDirection::~PathAndDirection() [161] ODMatrix::beginOrigin()
 [208] _GLOBAL__sub_I__ZN19DescDirectionPathPGC2Ed (DescDirectionPathPG.cpp) [106] PathBasedFlowMove::beginPathDirection() [139] ODMatrix::getNextOrigin()
 [209] _GLOBAL__sub_I__ZN19PathBasedFlowMoveGPC2EddP17DescDirectionPath (PathBasedFlowMoveGP.cpp) [100] PathBasedFlowMove::getNextPathDirection() [156] ODMatrix::addOrigin(Origin*)
 [210] _GLOBAL__sub_I__ZN19PathBasedFlowMovePEC2EP17DescDirectionPath (PathBasedFlowMovePE.cpp) [40] PathBasedFlowMove::calculatePathDirection(std::list<Path*, std::allocator<Path*> > const&) [268] ODMatrix::ODMatrix(int)
 [211] _GLOBAL__sub_I__ZN20DescDirectionPathISPC2Eddd (DescDirectionPathISP.cpp) [117] PathBasedFlowMove::PathBasedFlowMove(DescDirectionPath*) [269] ODMatrix::~ODMatrix()
 [212] _GLOBAL__sub_I__ZN23DescDirectionPathScaledC2EP17DescDirectionPathid (DescDirectionPathScaled.cpp) [107] DescDirectionPathPE::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [47] StarLink::updateTime()
 [213] _GLOBAL__sub_I__ZN25PathBasedFlowMoveWithStepC2EP11StepSizeABCP17DescDirectionPath (PathBasedFlowMoveWithStep.cpp) [118] DescDirectionPathPE::DescDirectionPathPE(double) [143] StarLink::setNodeToIndex(int)
 [214] _GLOBAL__sub_I__ZN4PathC2Ev (Path.cpp) [119] DescDirectionPathPE::~DescDirectionPathPE() [144] StarLink::setNodeFromIndex(int)
 [215] _GLOBAL__sub_I__ZN5ODSet16initialiseObjectEiiiP8PathCostP16LinkFncContainerP11StarNetworkP12ShortestPathP11ConvMeasuredPdSA_P15PathAlgoCreator (ODSet.cpp) [113] PathBasedFlowMovePE::executeFlowMove() [79] StarLink::addFlow(double)
 [216] _GLOBAL__sub_I__ZN5Utils16getDisjointLinksEP4PathS1_RSt4listIP8StarLinkSaIS4_EEi (Utils.cpp) [120] PathBasedFlowMovePE::PathBasedFlowMovePE(DescDirectionPath*) [32] StarLink::setFlow(double)
 [217] _GLOBAL__sub_I__ZN5Utils17removeWhiteSpacesERSs (UtilsString.cpp) [121] PathBasedFlowMovePE::~PathBasedFlowMovePE() [145] StarLink::setIndex(int)
 [218] _GLOBAL__sub_I__ZN6ArmijoC2EdP10Derivative (Armijo.cpp) [10] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::initialise(int, int) [65] StarLink::StarLink(int, int, LinkFnc*)
 [219] _GLOBAL__sub_I__ZN6BprFncC2Edddd (BprFnc.cpp) [5] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::bIterate(int, int) [146] StarLink::~StarLink()
 [220] _GLOBAL__sub_I__ZN6FWAlgoC2EP9LinkFlows (FWAlgo.cpp) [6] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::fIterate(int, int) [38] StarNode::getID()
 [221] _GLOBAL__sub_I__ZN6OriginC2Ei (Origin.cpp) [17] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int) [137] StarNode::getIndex()
 [222] _GLOBAL__sub_I__ZN6PairODC2Eid (PairOD.cpp) [4] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [150] StarNode::setIndex(int)
 [223] _GLOBAL__sub_I__ZN6ParamsC2Ev (Params.cpp) [21] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::ShPathAstarBidirect(StarNetwork*) [14] StarNode::getIsZone()
 [224] _GLOBAL__sub_I__ZN6ParserC2Ev (Parser.cpp) [68] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [151] StarNode::StarNode(int, bool)
 [225] _GLOBAL__sub_I__ZN6RelGapC2EdP11StarNetworkP8ODMatrixP12ShortestPath (RelGap.cpp) [69] ShPathAstarBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::~ShPathAstarBidirect() [152] StarNode::~StarNode()
 [226] _GLOBAL__sub_I__ZN7DAGraph4net_E (DAGraph.cpp) [36] ShPathDijkstraBidirect<boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_> >::calculate(int, int) [37] AdditivePC::calculate(Path*) const
 [227] _GLOBAL__sub_I__ZN7PathSet16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP11ConvMeasureP8PathCost (PathSet.cpp) [41] DescDirectionPathScaled::createPathDirection(int&, std::list<Path*, std::allocator<Path*> > const&, bool&) [56] ShPathInterface::getInComeLink(int) const
 [228] _GLOBAL__sub_I__ZN7QuadAppC2EP10Derivative (QuadApp.cpp) [122] DescDirectionPathScaled::DescDirectionPathScaled(DescDirectionPath*, int, double) [57] ShPathInterface::getCost(int) const
 [229] _GLOBAL__sub_I__ZN8ConstFncC2Ed (ConstFnc.cpp) [123] DescDirectionPathScaled::~DescDirectionPathScaled() [81] PathAndDirection::getDirectionValue() const
 [230] _GLOBAL__sub_I__ZN8ODMatrixC2Ei (ODMatrix.cpp) [89] Path::setCurrCost(double) [97] PathAndDirection::getPath() const
 [231] _GLOBAL__sub_I__ZN8StarLinkC2EiiP7LinkFnc (StarLink.cpp) [101] Path::setPrevFlow(double) [96] Path::getCurrCost() const
 [232] _GLOBAL__sub_I__ZN8StepSizeC2EP13DescDirectionidP10LineSearch (StepSize.cpp) [82] Path::addLinkToPath(StarLink*) [33] Path::getNextLink() const
 [233] _GLOBAL__sub_I__ZN9BisectionC2EdP10Derivative (Bisection.cpp) [104] Path::setFlow(double) [80] Path::getPrevFlow() const
 [234] _GLOBAL__sub_I__ZN9LinearFncC2Edd (LinearFnc.cpp) [108] Path::Path() [77] Path::getFlow() const
 [235] _GLOBAL__sub_I__ZN9LinkFlows16initialiseObjectEP11StarNetworkP8ODMatrixP16LinkFncContainerP12ShortestPathP10DerivativeP10LineSearchP11ConvMeasure (LinkFlows.cpp) [109] Path::~Path() [43] Path::beginLink() const
 [236] _GLOBAL__sub_I__ZN9OriginSetC2EP8ODMatrixP11StarNetworkP12ShortestPathP11ConvMeasureddb (OriginSet.cpp) [3] ODSet::improveSet() [93] ODSet::getNbPaths() const
 [237] _GLOBAL__sub_I__ZN9SpiessFncC2Eddddd (SpiessFnc.cpp) [34] ODSet::equilibrate() [95] ODSet::getDestIndex() const
 [238] _GLOBAL__sub_I_main (main.cpp) [51] ODSet::removeUnusedPaths() [157] Origin::getID() const
 [239] AdditivePC::AdditivePC() [44] ODSet::updateLinkCostsOfOD() [110] Origin::getIndex() const
 [240] AdditivePC::~AdditivePC() [30] ODSet::projectPathFlowOnLinks() [94] PairOD::getODIndex() const
 [159] ParseParams::skipComments(std::string) [48] ODSet::calculateProjectedDirection() [134] PairOD::getID() const
 [115] StarNetwork::getNbLinks() [124] ODSet::addPath(Path*) [86] PairOD::getIndex() const
 [148] StarNetwork::getNbNodes() [31] ODSet::updateSet()  [87] PairOD::getDemand() const
  [12] StarNetwork::getNextLink() [125] ODSet::ODSet(int, int, int, PathCost*, LinkFncContainer*, StarNetwork*, ShortestPath*, ConvMeasure*, double*, double*, double, PathAlgoCreator*) [163] PathSet::isConverged() const
  [52] StarNetwork::getNextNode() [126] ODSet::~ODSet()  [270] ODMatrix::getNbODPairs() const
 [114] StarNetwork::getNodeIndex(int) [127] ODSet::~ODSet() [83] StarLink::getLinkFnc() const
 [162] StarNetwork::beginOnlyLink() [259] Utils::extractName(char const*, std::string&) [13] StarLink::getNodeToIndex() const
 [241] StarNetwork::createIndexes() [158] Utils::getSubString(std::string, std::string, std::string) [9] StarLink::getNodeFromIndex() const
  [98] StarNetwork::getNextOnlyLink() [55] Utils::getCommonLinks(PathBasedFlowMove*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [76] StarLink::getFlow() const
  [62] StarNetwork::calculateLinkCosts() [45] Utils::getDisjointLinks(Path*, Path*, std::list<StarLink*, std::allocator<StarLink*> >&, int) [22] StarLink::getTime() const
 [140] StarNetwork::addLink(StarLink*) [135] Utils::removeWhiteSpaces(std::string&) [25] StarLink::getIndex() const
  [63] StarNetwork::addNode(StarNode*) [136] Utils::skipOneLineComment(std::string, std::string) [78] StarLink::getNodeTo() const
  [29] StarNetwork::getLink(int) [53] boost::heap::fibonacci_heap<ValueKey, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::marked_heap_node<ValueKey>*, boost::heap::detail::make_fibonacci_heap_base<ValueKey, boost::parameter::aux::empty_arg_list>::type, ValueKey&>) [85] std::vector<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, std::allocator<boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&> > >::at(unsigned long)
  [28] StarNetwork::beginLink() [15] boost::heap::detail::d_ary_heap<std::_List_iterator<std::pair<ValueKey, unsigned long> >, boost::parameter::aux::arg_list<boost::heap::allocator<std::allocator<ValueKey> >, boost::parameter::aux::arg_list<boost::heap::compare<boost::heap::detail::priority_queue_mutable_wrapper<boost::heap::detail::d_ary_heap<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::empty_arg_list> >, boost::heap::detail::nop_index_updater> >::indirect_cmp>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::arg_list<boost::heap::stability_counter_type<unsigned long>, boost::parameter::aux::arg_list<boost::heap::stable<false>, boost::parameter::aux::empty_arg_list> > > > >, boost::heap::detail::priority_queue_mutable_wrapper<boost::heap::detail::d_ary_heap<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::arg_list<boost::heap::arity<2u>, boost::parameter::aux::empty_arg_list> >, boost::heap::detail::nop_index_updater> >::index_updater>::pop() [147] std::vector<StarLink*, std::allocator<StarLink*> >::_M_insert_aux(__gnu_cxx::__normal_iterator<StarLink**, std::vector<StarLink*, std::allocator<StarLink*> > >, StarLink* const&)
  [16] StarNetwork::beginNode(int) [26] void boost::heap::detail::skew_heap_node<ValueKey, true>::clear_subtree<std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> > >(std::allocator<boost::heap::detail::skew_heap_node<ValueKey, true> >&) [271] std::vector<bool, std::allocator<bool> >::_M_initialize(unsigned long)
  [58] StarNetwork::beginNode() [7] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::merge_nodes(boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::skew_heap_node<ValueKey, true>*) [167] std::_Rb_tree<std::string, std::pair<std::string const, std::string>, std::_Select1st<std::pair<std::string const, std::string> >, std::less<std::string>, std::allocator<std::pair<std::string const, std::string> > >::_M_erase(std::_Rb_tree_node<std::pair<std::string const, std::string> >*)
  [39] StarNetwork::linkNodes() [8] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::push(ValueKey const&) [272] std::_Rb_tree<int, std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*>, std::_Select1st<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >, std::less<int>, std::allocator<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> > >::_M_erase(std::_Rb_tree_node<std::pair<int const, std::vector<StarLink*, std::allocator<StarLink*> >*> >*)
 [242] StarNetwork::StarNetwork(int, int, std::string&) [27] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::clear() [168] bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*)
 [243] StarNetwork::~StarNetwork() [11] boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true>, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_, boost::parameter::void_>::increase(boost::heap::detail::node_handle<boost::heap::detail::skew_heap_node<ValueKey, true>*, boost::heap::detail::make_skew_heap_base<ValueKey, boost::parameter::aux::arg_list<boost::heap::mutable_<true>, boost::parameter::aux::empty_arg_list> >::type, ValueKey&>, ValueKey const&) (18) <cycle 1>
