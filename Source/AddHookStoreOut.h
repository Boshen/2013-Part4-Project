#ifndef ADD_HOOK_STORE_OUT
#define ADD_HOOK_STORE_OUT

#include "AddHookScreenOut.h"
#include "FileWriter.h"

#include <vector>
#include <sstream>

class AddHookStoreOut : public AddHookScreenOut {
		public:
			AddHookStoreOut(){};
			virtual ~AddHookStoreOut(){};
			
			void produceOut(double timePassed, FPType gap) {
				times_.push_back(timePassed);
				gaps_.push_back(gap);
			};
			
			void printToFile(const std::string &fileName) {
				std::cout << "Writing convergence to file: " << fileName << std::endl;
				FileWriter wfile(fileName);
				int size = gaps_.size();
				std::string line("");
				for (int i = 0; i < size; ++i){
					std::ostringstream strs;
					strs << times_[i] << " " << gaps_[i] << "\n";
					line = strs.str();
					wfile.writeLine(line);
				}
			};
			
		private:
			std::vector<double> times_;
			std::vector<FPType> gaps_;
};

#endif
