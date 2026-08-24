#ifndef READ_SAMPLES_CSV_H
#define READ_SAMPLES_CSV_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2025-03-27
 *
 * Run Verifier 
 *
 * Header file for read_samples_csv.cpp
 * 
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

void read_samples_csv(
		      const std::string& file_path,
		      std::vector<std::string>* sample_name,
		      std::vector<int>* start_runs,
		      std::vector<int>* end_runs,
		      std::vector<std::string>* start_dates,
		      std::vector<std::string>* daq_types
		      );



#endif
