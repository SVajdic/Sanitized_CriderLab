#ifndef FIND_MATCHING_FILES_H
#define FIND_MATCHING_FILES_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-22
 * LAST EDIT: 2025-04-23
 *
 * Generic Use Code
 *
 * Matches an input string with a list of file names
 * Returns all files that contain the string
 * 
 **********************************************************************/

#include <string>
#include <vector>
#include <regex>

inline void find_matching_files(
				const std::string& sample_name, 
				const std::vector<std::string>* filenames,
				std::vector<std::string>* file_matches
				){

  std::regex pattern(".*" + sample_name + ".*");
  for (const auto& filename : *filenames) {
    if (std::regex_match(filename, pattern)) {
      file_matches->push_back(filename);
    }
  }
  return;
}

#endif
