#ifndef PLOT_OBJECTS_H
#define PLOT_OBJECTS_H



/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2025-04-28
 * LAST EDIT: 2025-05-11
 *
 * Generic Use Code 
 *
 * Header file for plot_objects.cpp
 * 
 **********************************************************************/
#include <string> 
#include <vector>
#include <iostream>
#include <sstream>

#include "TH1.h"
#include "TF1.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TPaveText.h"

void plot_objects(
		 TCanvas *c,
		 std::vector<TObject*> *objs,
		 std::vector<Color_t> *colors,
		 const std::string &mode,
		 bool is_preliminary,
		 const std::string &message = ""
);



#endif
