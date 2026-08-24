#ifndef LOAD_ENDF_H
#define LOAD_ENDF_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2025-05-08
 * LAST EDIT: 2025-05-09
 *
 * Generic Use Code 
 *
 * Header file for load_endf.cpp
 * 
 **********************************************************************/
#include <string>
#include <iostream>
#include <map>

#include "TGraph.h"

#include "/home/sv572/DANCE/CriderLab_DANCE_Creations/Generic_Use_Code/load_two_column.h"

TGraph* load_endf(const std::string& filename);



#endif
