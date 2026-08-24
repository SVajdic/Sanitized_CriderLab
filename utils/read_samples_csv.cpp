/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2025-04-23
 *
 * Run Verifier 
 *
 * Read a csv file and extract the sample name, start runs, and end runs into vectors
 * Expects 4 lines of header in the csv and columns 2, 3, and 6 to have the information we care about
 * 
 **********************************************************************/

#include "read_samples_csv.h"

void read_samples_csv(const std::string& file_path,
		      std::vector<std::string>* sample_names,
		      std::vector<int>* start_runs,
		      std::vector<int>* end_runs,
		      std::vector<std::string>* start_dates,
		      std::vector<std::string>* daq_types
		      ) {
  
  
  std::ifstream csv_name(file_path);
    if(csv_name.is_open()){
      
      std::string line;
      //first 4 lines are header
      int header_lines=1;
      for(int x=0;x<header_lines;x++){
	getline(csv_name,line);
      }
      
      //read in the lines of the csv
      while(getline(csv_name,line)){
	  
	  std::stringstream ss(line);
	  std::string token;
	  
	  // Sample Name (1st column)
	  std::getline(ss, token, ',');
	  //replace any spaces with underscores
	  std::replace(token.begin(),token.end(),' ','_');
	  sample_names->push_back(token);
	  
	  // Start Run (2nd column)
	  std::getline(ss, token, ',');
	  start_runs->push_back(std::stoi(token));

	  // End Run (3rd column)
	  std::getline(ss, token, ',');
	  end_runs->push_back(std::stoi(token)); 	  

	  // Start Date (4th column)
	  std::getline(ss, token, ',');
	  start_dates->push_back(token);

	  //DAQ Type (5th column)
	  std::getline(ss, token, ',');
	  daq_types->push_back(token);

	  // Skip rest
	  // while (std::getline(ss, token, ',')) {
            // Do nothing, just skip the remaining columns
	  //}
	}
	//close it after we finish
	csv_name.close();
	
    } else {
      std::cerr << "Problem opening csv file: " << file_path << std::endl;
    }
    
    return;
}
