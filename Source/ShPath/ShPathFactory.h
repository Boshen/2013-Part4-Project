#ifndef _SH_PATH_FACTORY_
#define _SH_PATH_FACTORY_

#include <iostream>
#include <string>
#include <map>

#include "../StarNetwork.h"
#include "../ODMatrix.h"

#include "ShPathInterface.h"

#include <boost/heap/fibonacci_heap.hpp>
typedef boost::heap::fibonacci_heap<ShPath::ValueKey> FibonacciHeap;

#include <boost/heap/d_ary_heap.hpp>
typedef boost::heap::d_ary_heap<ShPath::ValueKey, boost::heap::arity<2>, boost::heap::mutable_<true> > BinaryHeap;

#include <boost/heap/d_ary_heap.hpp>
typedef boost::heap::d_ary_heap<ShPath::ValueKey, boost::heap::arity<3>, boost::heap::mutable_<true> > TernaryHeap;

#include <boost/heap/skew_heap.hpp>
typedef boost::heap::skew_heap<ShPath::ValueKey, boost::heap::mutable_<true> > SkewHeap;

#include <boost/heap/pairing_heap.hpp>
typedef boost::heap::pairing_heap<ShPath::ValueKey> ParingHeap;

#include <boost/heap/binomial_heap.hpp>
typedef boost::heap::binomial_heap<ShPath::ValueKey> BinomialHeap;

class ShPathFactory {
    private:
        ShPathFactory();
    public:
        static ShPathFactory* get();

        ShPathInterface* getShPath(const std::string& algo, const std::string& dataStruct, StarNetwork* _netPointer, ODMatrix* _odMatrix);

};


#endif
