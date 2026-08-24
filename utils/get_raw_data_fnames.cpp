/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2023-09-11
 * LAST EDIT: 2024-07-11
 *
 * Run Verifier 
 *
 * Retrieves filenames from symbolically linked directories in specified directory
 * 
 **********************************************************************/

#include "get_raw_data_fnames.h"

void get_raw_data_fnames(
				     const std::string& directory_path,
				     std::vector<std::string> *file_names
				     ){
  namespace fs = boost::filesystem;

  fs::path dirPath(directory_path);
  
  //temp storage for symlinked directories
  std::vector<std::string> *symlinked_directories=new std::vector<std::string>();


  //first retrieve all the symlinked_directories in the folder
  if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
    for (fs::directory_iterator it(dirPath); it != fs::directory_iterator(); ++it) {
      if (fs::is_symlink(it->path())) {
                fs::path symPath = fs::read_symlink(it->path());
                if (fs::is_directory(symPath)) {
		  symlinked_directories->push_back(it->path().string());
                }
      }
    }
  } else {
    std::cerr << "Directory does not exist or is not a directory: " << directory_path << std::endl;
  }

  //for each of the linked directories, retrieve the file names
  for (const auto& symlink : *symlinked_directories) {
    get_fname_from_dir(symlink, file_names);
  }
  
  //delete this helper vector now that we are finished
  delete symlinked_directories;

  return;
}
  

