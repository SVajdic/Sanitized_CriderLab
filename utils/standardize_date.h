#ifndef STANDARDIZE_DATE_H
#define STANDARDIZE_DATE_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-22
 * LAST EDIT: 2025-04-23
 *
 * GENERIC USE CODE 
 *
 * Standardizes dates to MM/DD/YYYY format
 * 
 **********************************************************************/
#include <string>
#include <sstream>
#include <iomanip>  // For std::setfill and std::setw

inline std::string standardize_date(const std::string& date){
  int month, day, year;
  char delimiter1, delimiter2;
  
  std::istringstream iss(date);
  iss >> month >> delimiter1 >> day >> delimiter2 >> year;
  
  std::ostringstream oss;
  oss << std::setfill('0') << std::setw(2) << month << '/'
      << std::setfill('0') << std::setw(2) << day << '/'
      << year;
  
  return oss.str();
}



#endif
