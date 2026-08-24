#ifndef GET_RUNS_FROM_FNAMES_H
#define GET_RUNS_FROM_FNAMES_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2025-04-23
 *
 * Run Verifier 
 *
 * Takes the file names as a vector of strings and retrieves the 6+ digit run numbers from them
 * Note the regex pattern only retrieves the first instance of 6+ digits so don't alter the naming scheme
 * Also don't store other things with 6+ digits in the name in your process runs folders. Make new folders
 * 
 **********************************************************************/
#include <iostream>
#include <string>
#include <vector>

#include "extract_six_digit.h"

inline void get_runs_from_fnames(
				 std::vector<int>* run_numbers, 
				 std::vector<std::string>* filenames
				 ){
  //raw data files have pieces like run_123_001, run_123_002 ...
  //only add unique runs to the vector
  int last_number=0;

  for(const auto& filename : *filenames){
    int run_number = extract_six_digit(filename);
    if (run_number != -1 && run_number!=last_number){
      run_numbers->push_back(run_number);
      last_number=run_number;
    }
  }
  
  return;
}



#endif
