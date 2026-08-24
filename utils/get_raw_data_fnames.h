#ifndef GET_RAW_DATA_FNAMES_H
#define GET_RAW_DATA_FNAMES_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2024-07-11
 *
 * Run Verifier 
 *
 * Header file for get_raw_data_fnames.cpp
 * 
 **********************************************************************/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

#include "get_fname_from_dir.h"

void get_raw_data_fnames(
			 const std::string& directory_path,
			 std::vector<std::string> *file_names
			 );



#endif
