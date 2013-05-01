#ifndef _SH_PATH_DIRECT_
#define _SH_PATH_DIRECT_

#include "StarNetwork.h"
#include "LabelSettingAl.h"

class ReverseStarLink : public StarLink{
    public:
	ReverseStarLink(int nodeFrom, int nodeTo, LinkFnc *fnc):
        StarLink(nodeFrom, nodeTo, fnc){}
        
};

class ShPathBidirect : public LabelSettingAl {
    public:
        static LabelSettingAl* create(StarNetwork *netPointer){
            return new ShPathBidirect(netPointer);
        }

        ShPathBidirect(StarNetwork *netPointer);
        ~ShPathBidirect();

        void calculate(int originIndex);
        void calculate(int originIndex, int destIndex);

        FPType getCost(int destIndex) const{
            return LabelSettingAl::getCost(destIndex);
        }

        StarLink* getInComeLink(int destIndex) const{
            return LabelSettingAl::getInComeLink(destIndex);
        }

    private:
        StarNetwork *_netPointerBack;
        ShPathDijkstraHeap *forwardAlgo;
        ShPathDijkstraHeap *backwardAlgo;

};
#endif
