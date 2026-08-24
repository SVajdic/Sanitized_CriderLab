#ifndef COPY_OBJ_TO_ROOTFILE_H
#define COPY_OBJ_TO_ROOTFILE_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2024-08-21
 * LAST EDIT: 2024-08-21
 *
 * Generic Use Code 
 *
 * Header file for copy_obj_to_rootfile.cpp
 * 
 **********************************************************************/
#include <string>
#include <iostream>

#include "TFile.h"
#include "TObject.h"
#include "TKey.h"
#include "TClass.h"

void copy_obj_to_rootfile(
			  const std::string& object_name, 
			  const std::string& root_file_src, 
			  const std::string& root_file_dest
			  );



#endif
