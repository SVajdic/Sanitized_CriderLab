#ifndef SORT_VECTOR_VIA_MAP_H
#define SORT_VECTOR_VIA_MAP_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-07-25
 * LAST EDIT: 2024-07-25
 *
 * Generic Use Code 
 *
 * Takes a vector as an argument
 * Put the vector into a map which autosorts it based on the key
 * Returns the vector which is now sorted
 * Note: only works on things the map knows how to sort (ints, doubles, strings, etc.)
 * 
 **********************************************************************/

#include <vector>
#include <map>
#include <string>


void sort_vector_via_map(
			 std::vector<int> *sort_vector
			 );

void sort_vector_via_map(
			 std::vector<double> *sort_vector
			 );

void sort_vector_via_map(
			 std::vector<std::string> *sort_vector
			 );

#endif
