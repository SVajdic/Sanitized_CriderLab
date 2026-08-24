#ifndef FORMAT_HISTO_AXES_H
#define FORMAT_HISTO_AXES_H

/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2025-05-11
 * LAST EDIT: 2025-05-11
 *
 * Generic Use Code 
 *
 * Inline header for setting axes titles and centering them
 * Color handled separately in plotting of canvas
 * 
 **********************************************************************/

#include "TH1.h"

inline void format_histo_axes(
			      TH1D *h,
			      const char* x_label,
			      const char* y_label) {
  
  h->GetXaxis()->SetTitle(x_label);
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->SetTitle(y_label);
  h->GetYaxis()->CenterTitle();
  h->SetLineWidth(2);  

  return;
  
}

#endif
