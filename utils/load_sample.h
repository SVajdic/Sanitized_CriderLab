#ifndef LOAD_SAMPLE_H
#define LOAD_SAMPLE_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-22
 * LAST EDIT: 2025-04-12
 *
 * GENERIC USE CODE 
 *
 * Header file for load_sample.cpp
 * 
 **********************************************************************/
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>  // For std::all_of
#include <cctype>     // For std::isdigit

void load_sample(
		 const std::string& sample_file,
		 std::map<std::string,std::string> *assay_map,
		 std::vector<std::pair<int,int>> *run_pairs,
		 const std::string& option = "ALL"
		 );



#endif
