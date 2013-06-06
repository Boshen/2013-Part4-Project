#include "OriginBushTapas.h"

OriginBushTapas::OriginBushTapas(int index, StarNetwork *net) : OriginBush(index, net), dag_(NULL) {

};

OriginBushTapas::~OriginBushTapas(){

};
		
DAGraph* OriginBushTapas::createNewDAG(int index, StarNetwork *net, ODMatrix *mat, FPType zeroFlow, FPType dirTol){
	dag_ = NULL; //new DAGraphTapas(net, mat, zeroFlow, dirTol, index); // TODO
	return dag_; //setDagPointer(dag_);
};
