#ifndef GET_FNAME_FROM_DIR_H
#define GET_FNAME_FROM_DIR_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2024-08-29
 *
 * Run Verifier 
 *
 * Header file for get_fname_from_dir.cpp
 * 
 **********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "boost/filesystem.hpp"
#include "boost/regex.hpp"

void get_fname_from_dir(
			const std::string& directory_path,
			std::vector<std::string>* file_names
			);

void get_fname_from_dir(const std::string& directory_path, 
			std::vector<std::string> *file_names, 
			const std::string& file_name_check
			);

#endif
