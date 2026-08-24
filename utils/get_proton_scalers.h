#ifndef GET_PROTON_SCALERS_H
#define GET_PROTON_SCALERS_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-07-18
 * LAST EDIT: 2024-07-19
 *
 * Proton Scalers 
 *
 * Header file for get_proton_scalers.cpp
 * 
 **********************************************************************/
#include <string>
#include <iostream>

#include "TFile.h"
#include "TH1.h"

int get_proton_scalers(
		       const std::string& root_file_name,
		       const std::string& histo_name, 
		       int bin);



#endif
