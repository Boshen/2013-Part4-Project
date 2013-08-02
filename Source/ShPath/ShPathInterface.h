#ifndef _SH_PATH_INTERFACE_
#define _SH_PATH_INTERFACE_

#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <cassert>
#include <algorithm>
#include <map>
#include "../ShortestPath.h"

#include "../StarNetwork.h"
#include "../NodeInfo.h"

namespace ShPath {
    const FPType FPType_Max = std::numeric_limits<FPType>::max();

    typedef std::pair<FPType, int> PQPair;

    class Prioritize{
        public:
            bool operator() ( const PQPair& p1, const PQPair& p2){
                return p1.first > p2.first;
            }
    };

    typedef std::priority_queue<PQPair, std::vector<PQPair>, Prioritize > PriorityQueue;

    struct ValueKey {
        FPType d; // dist
        int u; // node
        ValueKey(FPType _d, int _u) : d(_d), u(_u){}
        // The relation establishes the order in the PriorityQueue
        bool operator<(ValueKey const & rhs) const {
            return d < rhs.d;
        }
    };


}

class ShPathInterface : public ShortestPath {

    protected:
        enum Label { UNREACHED, SCANNED, LABELED };

        int _nNodes;
        std::vector<FPType> *LabelVector;
        std::vector<int> *Predecessors;
        std::vector<Label> *Labels;
        StarNetwork *_netPointer;

        std::vector<std::pair<int,int> > *fScanned;
        std::vector<std::pair<int,int> > *bScanned;
        /*
        std::map<std::pair<int, int>, std::vector<int>* > *sp_tree; // <<o,d>, tree>
        std::map<std::pair<int, int>, int> *sp_tree_changed;
        std::map<std::pair<int, int>, int> *iter;

        std::map<std::pair<int, int>, FPType > *LabelVector_Cache; 
        std::map<std::pair<int, int>, std::vector<int>* > *Predecessors_Cache; 
        */

        inline void initNodes(){
            std::fill(LabelVector->begin(), LabelVector->end(),  ShPath::FPType_Max);
            std::fill(Predecessors->begin(), Predecessors->end(),  -1);

            //fScanned->clear();
            //bScanned->clear();
        }

    public:
        ShPathInterface(StarNetwork *netPointer) : _netPointer(netPointer) {
            _nNodes = _netPointer->getNbNodes();

            LabelVector = new std::vector<FPType>(_nNodes);
            Predecessors = new std::vector<int>(_nNodes);
            Labels = new std::vector<Label>(_nNodes);

            /*
            fScanned = new std::vector<std::pair<int,int> >();
            bScanned = new std::vector<std::pair<int,int> >();
            */

            //LabelVector_Cache = new std::map<std::pair<int, int>, FPType >();
            //Predecessors_Cache = new std::map<std::pair<int, int>, std::vector<int>* >();

            /*
            sp_tree = new std::map<std::pair<int, int>, std::vector<int>* >(); // <<o,d>, link indices>
            sp_tree_changed = new std::map<std::pair<int, int>, int>(); // <<o,d>, dist>
            */

            //iter = new std::map<std::pair<int, int>, int>(); // <<o,d>, dist>
            //
            //for(int i=0;i<_nNodes;i++){
            //    for(int j=0;j<_nNodes;j++){
            //        LabelVector_Cache->insert(std::make_pair(std::make_pair(i,j), new std::vector<FPType>()));
            //        Predecessors_Cache->insert(std::make_pair(std::make_pair(i,j), new std::vector<int>()));
            //        //sp_tree_changed->insert(std::make_pair(std::make_pair(i,j), 0));
            //    }
            //}

        };

        ~ShPathInterface(){
            /*
            std::map<std::pair<int,int>, std::vector<int>* >::iterator it;
            for(it=Predecessors_Cache->begin();it!=Predecessors_Cache->end();it++){
                std::cout << it->first.first << " " << it->first.second << " ";
                for( size_t i = 0; i < it->second->size(); i++){
                 
                    std::cout << it->second->at(i) << " ";
                }
                std::cout << std::endl;
            }
            */

            delete LabelVector;
            delete Predecessors;
            delete Labels;

            /*
            delete fScanned;
            delete bScanned;
            */

            //std::map<std::pair<int,int>, FPType >::iterator it1;
            //for(it1=LabelVector_Cache->begin();it1!=LabelVector_Cache->end();it1++){
            //    delete it1->second;
            //}
            //std::map<std::pair<int,int>, std::vector<int>* >::iterator it2;
            //for(it2=Predecessors_Cache->begin();it2!=Predecessors_Cache->end();it2++){
            //    delete it2->second;
            //}

            //delete LabelVector_Cache;
            //delete Predecessors_Cache;

            /*
            delete sp_tree;
            delete sp_tree_changed;
            */
            //delete iter;
        }

        virtual void calculate(int originIndex) =0;
        virtual void calculate(int originIndex, int destIndex) =0;

        FPType getCost(int destIndex) const{
            assert((destIndex >= 0) && (destIndex < _nNodes));
            return (*LabelVector)[destIndex];
        }

        StarLink* getInComeLink(int destIndex) const{
            assert((destIndex >= 0) && (destIndex < _nNodes));
            int linkIndex = (*Predecessors)[destIndex];
            return  linkIndex == -1 ?  NULL :  _netPointer->getLink(linkIndex);
        }

        /*
        void printScanned() {

            std::cout << "forwardtree" << std::endl;
            for (size_t i = 0; i < fScanned->size(); i++){
                std::cout << fScanned->at(i).first << " " << fScanned->at(i).second << std::endl;
            }

            //std::cout << "backwardtree" << std::endl;
            //for (size_t i = 0; i < bScanned->size(); i++){
            //    std::cout << bScanned->at(i).first << " " << bScanned->at(i).second << std::endl;
            //}

        }
        */


};

#endif
