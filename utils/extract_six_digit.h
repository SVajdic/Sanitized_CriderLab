#ifndef EXTRACT_SIX_DIGIT_H
#define EXTRACT_SIX_DIGIT_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-07-08
 * LAST EDIT: 2025-04-23
 *
 * Run Verifier 
 *
 * Takes a string and returns the first instance of 6 digits from it
 * 
 **********************************************************************/
#include <iostream>
#include <string>
#include <boost/regex.hpp>

int extract_six_digit(const std::string &s){

  try {
    boost::regex pattern(R"(\d{6,})");
    boost::smatch match;
    
    // Search for the pattern in the input string
    if (boost::regex_search(s, match, pattern)) {
      try {
	return std::stoi(match.str(0)); // Use match.str(0) to get the full match
      } catch (const std::invalid_argument& e) {
	std::cerr << "Invalid argument: " << e.what() << std::endl;
      } catch (const std::out_of_range& e) {
	std::cerr << "Out of range: " << e.what() << std::endl;
      }
    }
  } catch (const boost::regex_error& e) {
    std::cerr << "Regex error: " << e.what() << std::endl;
  }
  
  std::clog << "String: " << s << " does not contain 6 or more digits" << std::endl; 
  return -1;
  
}



#endif
