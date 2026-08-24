/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-21
 * LAST EDIT: 2025-04-23
 *
 * Generic Use Code 
 *
 * Takes an object from a source ROOT file and copies it to a destination ROOT file
 * 
 **********************************************************************/
#include "copy_obj_to_rootfile.h"

void copy_obj_to_rootfile(
			  const std::string& object_name, 
			  const std::string& root_file_src, 
			  const std::string& root_file_dest) {

      // Open the source file
    TFile* src_file = TFile::Open(root_file_src.c_str(), "READ");
    if (!src_file || src_file->IsZombie()) {
        std::cerr << "Error: Could not open source file " << root_file_src << std::endl;
        return;
    }

    // Get the object from the source file
    TObject* obj = src_file->Get(object_name.c_str());
    if (!obj) {
        std::cerr << "Error: Object " << object_name << " not found in source file " << root_file_src << std::endl;
        src_file->Close();
        return;
    }

    // Open the destination file
    TFile* dest_file = TFile::Open(root_file_dest.c_str(), "UPDATE");
    if (!dest_file || dest_file->IsZombie()) {
        std::cerr << "Error: Could not open destination file " << root_file_dest << std::endl;
        src_file->Close();
        return;
    }

    // Write the object to the destination file
    dest_file->cd();
    std::clog << "Copying: " << object_name << " from " << root_file_src << " to " << root_file_dest << std::endl; 
    obj->Write();

    // Clean up
    dest_file->Close();
    src_file->Close();
  

  return;

}
