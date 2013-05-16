#ifndef _SH_PATH_FACTORY_
#define _SH_PATH_FACTORY_

#include <iostream>
#include <string>
#include <map>

#include "../StarNetwork.h"

#include "ShPathInterface.h"

#include <boost/heap/fibonacci_heap.hpp>
typedef boost::heap::fibonacci_heap<ValueKey> FibonacciHeap;

#include <boost/heap/d_ary_heap.hpp>
typedef boost::heap::d_ary_heap<ValueKey, boost::heap::arity<2>, boost::heap::mutable_<true> > BinaryHeap;

#include <boost/heap/d_ary_heap.hpp>
typedef boost::heap::d_ary_heap<ValueKey, boost::heap::arity<3>, boost::heap::mutable_<true> > TernaryHeap;

#include <boost/heap/skew_heap.hpp>
typedef boost::heap::skew_heap<ValueKey, boost::heap::mutable_<true> > SkewHeap;

#include <boost/heap/pairing_heap.hpp>
typedef boost::heap::pairing_heap<ValueKey> ParingHeap;

#include <boost/heap/binomial_heap.hpp>
typedef boost::heap::binomial_heap<ValueKey> BinomialHeap;

class ShPathFactory {
    private:
        ShPathFactory();
    public:
        static ShPathFactory* get();

        ShPathInterface* getShPath(const std::string& algo, const std::string& dataStruct, StarNetwork* _netPointer);

};


#endif
