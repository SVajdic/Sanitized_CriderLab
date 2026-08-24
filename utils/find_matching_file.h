#ifndef FIND_MATCHING_FILE_H
#define FIND_MATCHING_FILE_H



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
 * Used for finding a unique match or first match in the list
 * Returns an empty string if there is no match
 * 
 **********************************************************************/

#include <vector>
#include <string>
#include <regex>

inline std::string find_matching_file(
				      const std::string& sample_name, 
				      const std::vector<std::string>* filenames
				      ){

  std::regex pattern(".*" + sample_name + ".*");
  for (const auto& filename : *filenames) {
    if (std::regex_match(filename, pattern)) {
      return filename;
    }
  }
  return "";  // Return an empty string if no match is found
}

#endif
