/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-07-11
 * LAST EDIT: 2024-07-11
 *
 * Run Verifier 
 *
 * Takes a vector with sequential numbers and converts them
 * to start and end values for visual clarity
 * 
 **********************************************************************/
#include "seq_condenser.h"

void seq_condenser(std::vector<int> *missing_runs,std::vector<int> *start_runs, std::vector<int> *end_runs) {

  int previous = 0;
  
  for (auto it = missing_runs->begin(); it != missing_runs->end(); it++) {
    int run = *it;
    
    // if this is the very first sequence record the start run
    if (it == missing_runs->begin()) {
      previous = run;
      start_runs->push_back(run);
    } else if (run == previous+1) {
      // if our run value is equal to the previous value,
      // then increment previous and keep going
      previous=run;
    } else {
      //a non-consecutive number indicates the end of the current sequence
      end_runs->push_back(previous);
      //start a new sequence
      start_runs->push_back(run);
      previous = run;
    }

    // the very last run in missing_runs is the last end_run
    if(it == missing_runs->end() - 1){
      end_runs->push_back(run);
    }
  }

return;
}
