/**********************************************************************
 * CRIDER LAB GROUP
 *
 *    AUTHOR: Stephan Vajdic
 *   CREATED: 2025-04-28
 * LAST EDIT: 2025-05-13
 *
 * Generic Use Code 
 *
 * Plots histograms, fits, and graphs on a canvas
 * Objects should be formatted before submission to this function
 * Options:
 * modes indicate whether a canvas has certain axes set to log scale
 * bool set to true prints red text showing the plots are prelimnary
 * message text to be placed in a textbox on the right middle below the
 * legend
 *
 * 
 **********************************************************************/
#include "plot_objects.h"

void plot_objects(
		  TCanvas *c,
		  std::vector<TObject*> *objs,
		  std::vector<Color_t> *colors,
		  const std::string &mode,
		  bool is_preliminary,
		  const std::string &message
		  ){
  //make sure there are histos to plot
  if(objs->empty()){
    std::cerr << "TObject* vector is empty when given to plot_objs" << std::endl;
    return;
  }

  if(colors->size() < objs->size()){
        std::cerr << "Need more colors in the colors vector! (colors<objects) = ("
                  << colors->size() << " < " << objs->size() << ")" << std::endl;
        return;
  }
  
  //clean pad before use
  gPad->Clear();
  //counts are always log scale
  gPad->SetLogy();
  //neutron energy uses log scale
  if(mode == "En"){
    gPad->SetLogx();
  }
  //transmission factors do not want log y
  if(mode == "Tr"){
    gPad->SetLogy(0);
    gPad->SetLogx();
  }
  //doesn't seem to work
  //gStyle->SetOptStat(0);

  //each plot needs a legend
  auto *legend = new TLegend(0.75,0.75,0.94,0.94);
  legend->SetHeader("Legend","C");
  legend->SetBorderSize(0);
  legend->SetFillStyle(0);
  
  // draw a white box behind the text:
  legend->SetFillColor(kWhite);     // white background
  legend->SetFillStyle(1001);       // 1001 = solid fill
  legend->SetBorderSize(1);         // draw a thin black border

  for (size_t i = 0; i < objs->size(); ++i) {
    TObject* obj = objs->at(i);
    if (!obj) continue;

    //TH1 (histograms)
    if (auto* h = dynamic_cast<TH1*>(obj)) {
      h->SetLineColor(colors->at(i));
      h->SetStats(false);
      h->Draw(i == 0 ? "hist" : "histsame");
      legend->AddEntry(h, h->GetTitle(), "l");
    }
    //TGraph
    else if (auto* g = dynamic_cast<TGraph*>(obj)) {
      g->SetLineColor(colors->at(i));
      g->SetMarkerColor(colors->at(i));
      g->SetMarkerStyle(21);
      g->Draw(i == 0 ? "AP" : "P same");
      //TGraphs come with the option to label axes with SetTitle
      std::string full = g->GetTitle();  // e.g. "title;xtitle;ytitle;"
      auto pos = full.find(';');
      std::string legend_label = (pos==std::string::npos ? full : full.substr(0,pos));
      
      legend->AddEntry(g,legend_label.c_str(), "p");
    }
    // TF1
    else if (auto* f = dynamic_cast<TF1*>(obj)) {
      f->SetLineColor(colors->at(i));
      f->SetLineWidth(2);
      f->Draw(i == 0 ? "" : "same");
      legend->AddEntry(f, f->GetName(), "l");
    }
    else {
      std::cerr << "Unknown object type: " << obj->ClassName() << std::endl;
    }
  }

  legend->Draw();

  gPad->SetTopMargin(0.12);
  gPad->SetBottomMargin(0.12);

  if(is_preliminary){
    TLatex latex;
    latex.SetNDC();                    // use normalized coordinates
    latex.SetTextSize(0.04);           // relative to pad height
    latex.SetTextFont(42);
    latex.SetTextColor(kRed);
    latex.SetTextAlign(11);            // left-bottom
    latex.DrawLatex(0.12, 0.94, "Preliminary Plot");
  }
  
  if(!message.empty()){
    
    // coords in NDC: (x1,y1) lower-left -> (x2,y2) upper-right
    constexpr double x1 = 0.75, y1 = 0.60;
    constexpr double x2 = 0.94, y2 = 0.70;

    auto *pt = new TPaveText(x1, y1, x2, y2, "NDC");

    pt->SetFillColor(kWhite);
    pt->SetFillStyle(1001);   // solid white background
    pt->SetBorderSize(1);     // thin border
    pt->SetTextAlign(12);     // left-justify text within the box

    // split on '\n' and add each line separately
    std::istringstream iss(message);
    std::string line;
    while (std::getline(iss, line)) {
      pt->AddText(line.c_str());
    }

    pt->Draw();
  }
  
  c->Modified();
  c->Update();
  
  return;
}
