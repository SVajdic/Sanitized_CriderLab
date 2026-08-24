/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2025-03-27
 *
 * Run Verifier 
 *
 * Retrieves the list of filenames from a directory and stores them in a vector
 * Optional: Add a filter so that only filenames with the filter string are added
 *           to the vector
 * 
 **********************************************************************/

#include "get_fname_from_dir.h"

void get_fname_from_dir(const std::string& directory_path, std::vector<std::string> *file_names){
  
  namespace fs = boost::filesystem;

  fs::path dirPath(directory_path);
  
  if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
    for (fs::directory_iterator it(dirPath); it!= fs::directory_iterator(); it++) {
      if (fs::is_regular_file(it->path())) {
	// Get the canonical path to resolve any symbolic links
	fs::path canonicalPath = fs::canonical(it->path());
	file_names->push_back(canonicalPath.string());
      }
    }
  } else {
    std::cerr << "Directory does not exist or is not a directory: " << directory_path << std::endl;
  }
  
  return;
}

void get_fname_from_dir(const std::string& directory_path, 
			std::vector<std::string> *file_names, 
			const std::string& file_name_check){
  
  namespace fs = boost::filesystem;

  fs::path dirPath(directory_path);
  boost::regex filter(file_name_check);
  
  if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
    for (fs::directory_iterator it(dirPath); it!= fs::directory_iterator(); it++) {
      if (fs::is_regular_file(it->path())) {
	// Get the canonical path to resolve any symbolic links
	fs::path canonicalPath = fs::canonical(it->path());
        auto fname = canonicalPath.string();
	if(boost::regex_search(fname,filter)){
	  file_names->push_back(fname);
	}
      }
    }
  } else {
    std::cerr << "Directory does not exist or is not a directory: " << directory_path << std::endl;
  }
  
  return;
}
