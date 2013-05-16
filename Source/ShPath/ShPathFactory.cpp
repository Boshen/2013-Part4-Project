#include "ShPathFactory.h"
#include "ShPathInterface.h"
#include "ShPathDijkstra.h"
#include "ShPathDijkstraSTL.h"
#include "ShPathAstar.h"
#include "ShPathAstarSTL.h"
#include "ShPathAstarBidirect.h"
#include "ShPathDijkstraBidirectSTL.h"
#include "ShPathDijkstraBidirect.h"

ShPathFactory::ShPathFactory(){}

ShPathFactory* ShPathFactory::get(){
    static ShPathFactory instance;
    return &instance;
}

ShPathInterface* ShPathFactory::getShPath(const std::string& algo, const std::string& dataStruct, StarNetwork* _netPointer){
    if ( algo == "Astar" && dataStruct == "FibonacciHeap")
        return new ShPathAstar<FibonacciHeap>(_netPointer);
    if ( algo == "Astar" && dataStruct == "BinaryHeap")
        return new ShPathAstar<BinaryHeap>(_netPointer);
    if ( algo == "Astar" && dataStruct == "TernaryHeap")
        return new ShPathAstar<TernaryHeap>(_netPointer);
    if ( algo == "Astar" && dataStruct == "SkewHeap")
        return new ShPathAstar<SkewHeap>(_netPointer);
    if ( algo == "Astar" && dataStruct == "PairingHeap")
        return new ShPathAstar<ParingHeap>(_netPointer);
    if ( algo == "Astar" && dataStruct == "BinomialHeap")
        return new ShPathAstar<BinomialHeap>(_netPointer);

    if ( algo == "Dijkstra" && dataStruct == "FibonacciHeap")
        return new ShPathDijkstra<FibonacciHeap>(_netPointer);
    if ( algo == "Dijkstra" && dataStruct == "BinaryHeap")
        return new ShPathDijkstra<BinaryHeap>(_netPointer);
    if ( algo == "Dijkstra" && dataStruct == "TernaryHeap")
        return new ShPathDijkstra<TernaryHeap>(_netPointer);
    if ( algo == "Dijkstra" && dataStruct == "SkewHeap")
        return new ShPathDijkstra<SkewHeap>(_netPointer);
    if ( algo == "Dijkstra" && dataStruct == "PairingHeap")
        return new ShPathDijkstra<ParingHeap>(_netPointer);
    if ( algo == "Dijkstra" && dataStruct == "BinomialHeap")
        return new ShPathDijkstra<BinomialHeap>(_netPointer);

    if ( algo == "DijkstraSTL")
        return new ShPathDijkstraSTL(_netPointer);

    if ( algo == "AstarSTL")
        return new ShPathAstarSTL(_netPointer);

    if ( algo == "AstarBidirect")
        return new ShPathAstarBidirect<SkewHeap>(_netPointer);

    if ( algo == "DijkstraBidirect")
        return new ShPathDijkstraBidirect<SkewHeap>(_netPointer);

    if ( algo == "DijkstraBidirectSTL")
        return new ShPathDijkstraBidirectSTL(_netPointer);

    std::cout << "No algorithm or data structure found ... Abort" << std::endl;
    exit(-1);
}
