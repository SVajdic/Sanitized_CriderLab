/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2025-05-08
 * LAST EDIT: 2025-05-14
 *
 * Generic Use Code 
 *
 * Creates a TGraph from an ENDF file which is just a two cloumn
 * with a header
 * 
 * Note the map will auto sort the values by key but this is fine
 * 
 **********************************************************************/
#include "load_endf.h"

TGraph* load_endf(const std::string& filename) {
  
  std::clog << "Building TGraph from file: " << filename << std::endl;

  std::map<double,double> values_map = load_two_column<double,double>(filename);
  
  std::clog << "File loaded. Building TGraph from values map" << std::endl;

  //initialize empty graph
  TGraph *endf_graph = new TGraph();
  
  endf_graph->SetName(filename.c_str());
    
  //build graph one point at a time
  for(auto& pair : values_map){
      endf_graph->SetPoint(endf_graph->GetN(),pair.first,pair.second);
  }

  std::clog << "Finished building TGraph" << std::endl;

  return endf_graph;

}
