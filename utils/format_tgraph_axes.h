#ifndef FORMAT_TGRAPH_AXES_H
#define FORMAT_TGRAPH_AXES_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2025-05-11
 * LAST EDIT: 2025-05-12
 *
 * Generic Use Code 
 *
 * Uses the SetTitle function to label axes of a TGraph
 * Centers the axes titles
 * 
 **********************************************************************/
#include "TGraph.h"


inline void format_tgraph_axes(
			       TGraph* graph,
			       const char* title) {
  graph->SetTitle(title);
  graph->GetXaxis()->CenterTitle();
  graph->GetYaxis()->CenterTitle();
  
  return;
}


#endif
