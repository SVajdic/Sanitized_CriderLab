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
 * Note: only works on strings, double, and ints
 * 
 **********************************************************************/
#include "sort_vector_via_map.h"

void sort_vector_via_map(
			 std::vector<int> *sort_vector
			 ) {
  
  std::map<int,int> sort_map;
  
  //Sort with the map
  for(size_t i=0; i<sort_vector->size();i++){
    sort_map[sort_vector->at(i)]=1;
  }
  
  sort_vector->clear();
  
  for(const auto& p : sort_map){
    sort_vector->push_back(p.first);
  }
  
  return;
}

void sort_vector_via_map(
			 std::vector<double> *sort_vector
			 ){
  
  std::map<double,int> sort_map;
  
  //Sort with the map
  for(size_t i=0; i<sort_vector->size();i++){
    sort_map[sort_vector->at(i)]=1;
  }
  
  sort_vector->clear();
  
  for(const auto& p : sort_map){
    sort_vector->push_back(p.first);
  }
  
  return;
}

void sort_vector_via_map(
			 std::vector<std::string> *sort_vector
			 ){
  
  std::map<std::string,int> sort_map;
  
  //Sort with the map
  for(size_t i=0; i<sort_vector->size();i++){
    sort_map[sort_vector->at(i)]=1;
  }
  
  sort_vector->clear();
  
  for(const auto& p : sort_map){
    sort_vector->push_back(p.first);
  }
  
  return;
}
