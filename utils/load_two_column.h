#ifndef LOAD_PROTON_SCALERS_H
#define LOAD_PROTON_SCALERS_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-21
 * LAST EDIT: 2024-08-22
 *
 * Generic Use Code 
 *
 * Header file for load_two_column.cpp
 * 
 **********************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

template <typename KeyType, typename ValueType>
  std::map<KeyType, ValueType> load_two_column(const std::string& filename);

#endif
