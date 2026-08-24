/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-07-18
 * LAST EDIT: 2025-04-24
 *
 * Proton Scalers
 *
 * Returns the integer number of the specified bin of the specified histogram in the specified root file
 * Returns -1 if the file doesn't exist or if the histogram is not in the file
 * 
 **********************************************************************/
#include "get_proton_scalers.h"

int get_proton_scalers(
		       const std::string& root_file_name,
		       const std::string& histo_name,
		       int bin) {

  
  // Some variables
  TFile *run_file = TFile::Open(root_file_name.c_str());
  TH1I *hScaler = nullptr;
  int proton_scalers = -1;
  
  // Make sure the file is actually open
  if (run_file && run_file->IsOpen()) {
    //std::cout << "Successfully opened file: " << root_file_name << std::endl;
    
    // Set the current directory to the file's directory
    run_file->cd();
    
    // Print all objects in the current directory for debugging
    //gDirectory->ls();
    
    // Directly get the histogram
    TObject *obj = gDirectory->Get(histo_name.c_str());
    if (obj) {
      //std::cout << "Found object: " << obj->GetName() << ", Type: " << obj->ClassName() << std::endl;
      hScaler = dynamic_cast<TH1I*>(obj);
      if (hScaler) {
	// Get the scalers bin content
	proton_scalers = hScaler->GetBinContent(bin);
	//std::cout << "Found histogram: " << histo_name << ", Bin content: " << proton_scalers << std::endl;
      } else {
	std::cerr << "Object is not of type TH1I." << std::endl;
      }
    } else {
      std::cerr << "Cannot find specified histogram: \"" << histo_name << "\" in file: " << root_file_name << std::endl;
    }
    
    // Close the file
    run_file->Close();
  } else {
    std::cerr << "Problem opening file: " << root_file_name << std::endl;
  }
  
  return proton_scalers;
}
