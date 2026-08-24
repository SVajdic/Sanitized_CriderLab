/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-22
 * LAST EDIT: 2025-04-24
 *
 * GENERICE USE CODE 
 *
 * Provide a sample file, a year (optional), a <string,double>map, and a vector of <int,int>pairs
 * File will be parsed
 * The map will contain the Assay information
 * The vector of pairs will contain the runs used
 * If a year is provided, then only the runs from that particular year
 * will be loaded into the vector
 * The default is to load all runs from all years available
 *         
 * 
 **********************************************************************/
#include "load_sample.h"

void load_sample(
		 const std::string& sample_file,
		 std::map<std::string,std::string> *assay_map,
		 std::vector<std::pair<int,int>> *run_pairs,
		 const std::string& option
		 ) {

  //load the file 
  std::ifstream infile(sample_file.c_str());

  if(!infile.is_open()){
    std::clog << "Problem loading file: " << sample_file << std::endl;
    return;
  }

  std::string line;
  std::string section;
  std::string current_year;

  //first line is header which is the name of the sample
  getline(infile,line);

  //save this in case it is needed later
  (*assay_map)["Sample_Name"]=line;

  std::clog << "Sample name added to map as: " << "Sample_Name " << line << std::endl; 

  //now for the bulk
  while(getline(infile,line)){
    
    // Skip empty lines
    if (line.empty()) {
      continue;
    }
    
    std::istringstream iss(line);
    std::string s;
    
    //if we have a single entry it's probably a section header
    if(iss >> s){
      if(s == "ASSAY"){
	std::clog << std::endl << "Setting section to ASSAY" << std::endl;
	section = "ASSAY";
	continue;
      }
      if(s == "RUNS"){
	std::clog << std::endl << "Setting section to RUNS" << std::endl;
	section = "RUNS";
	continue;
      }
      if(section == "RUNS"){
	if (s.size() == 4 && std::all_of(s.begin(), s.end(), ::isdigit)) {
	  std::clog << "Setting current year to " << s << std::endl;
	  current_year = s;
	  continue;
	}
      }
    }
    
    //parse the assaay section into a map
    if(section == "ASSAY"){
      std::string key;
      std::string value;
      std::istringstream iss2(line);
      if(iss2 >> key >> value){
	std::clog << "Adding entry: "<< key << " " << value << std::endl;
	(*assay_map)[key]=value;
      }
    }
    
    //parse the runs section into a vector
    if(section == "RUNS"){
      int start,end;
      std::istringstream iss2(line);
      if (iss2 >> start >> end) {
	// If the option matches the year or option is "ALL"
	std::clog << "Found run range: " << start << " - " << end << " for year " << current_year << std::endl;
	if (option == "ALL" || option == current_year) {
	  //then fill the vector with a pair
	  
	  run_pairs->push_back({start, end});
	  
	}
      } else {
	std::cerr << "Invalid run pair in line: " << line << std::endl;
      }
    }  
  }
  //close file
  infile.close();
  
  return;
}
