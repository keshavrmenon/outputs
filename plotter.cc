#include<TH1.h>
#include<TFile.h>
#include<TLatex.h>
#include<TLegend.h>

void plotter(){
  char s[30]="demo/phi_y";
  TFile *f1, *f2, *f3;
  f1 = new TFile("nmssm_pythia_m300.root");
  f2 = new TFile("spin0_pythia_m300.root");
  f3 = new TFile("spin2_pythia_m300.root");
  
  TH1F *h1 = (TH1F*) f1->Get(s);
  TH1F *h2 = (TH1F*) f2->Get(s);
  TH1F *h3 = (TH1F*) f3->Get(s);
  h1->SetTitle("NMSSM");
  h2->SetTitle("Radion");
  h3->SetTitle("Graviton");
  TCanvas *c = new TCanvas();
  TLegend *l;
  h1->SetLineColor(600);
  h2->SetLineColor(418);
  h3->SetLineColor(625);
  h1->SetLineWidth(1);
  h2->SetLineWidth(1);
  h3->SetLineWidth(1);
  h1->Scale(1/(h1->GetEntries()));
  h2->Scale(1/(h2->GetEntries()));
  h3->Scale(1/(h3->GetEntries()));
  h2->SetMaximum(1.2*h2->GetMaximum());
  h2->Draw("hist");
  h1->Draw("hist&same");
  h3->Draw("hist&same");
  l=c->BuildLegend(0.75, 0.4, 0.9, 0.5);
}
