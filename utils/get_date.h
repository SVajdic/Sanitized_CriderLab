#ifndef GET_DATE_H
#define GET_DATE_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2025-04-23
 *
 * Generic Use Code 
 *
 * Returns a string as the date in the format YYYY_MM_DD
 * 
 **********************************************************************/

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

inline std::string get_date(){

  auto now = std::chrono::system_clock::now();
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);
  std::tm now_tm = *std::localtime(&now_c);
  
  char buffer[11]; // YYYY-MM-DD is 10 characters + null terminator
  std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &now_tm);
  
  return std::string(buffer);
  
}

#endif
