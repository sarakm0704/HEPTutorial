void stack_ex1(){

  TFile * f_data = new TFile("out/hist_data.root");
  TFile * f_dy = new TFile("out/hist_dy.root");
  TFile * f_ttbar = new TFile("out/hist_ttbar.root");
  TFile * f_qcd = new TFile("out/hist_qcd.root");
  TFile * f_wjets = new TFile("out/hist_wjets.root");
  TFile * f_single_top = new TFile("out/hist_single_top.root");
  TFile * f_ww = new TFile("out/hist_ww.root");
  TFile * f_wz = new TFile("out/hist_wz.root");
  TFile * f_zz = new TFile("out/hist_zz.root");

  THStack *sh = new THStack("sh","multi");
  TH1F * h_muon_multi_ttbar = (TH1F*) f_ttbar->Get("h_muon_multi");
  TH1F * h_muon_multi_dy = (TH1F*) f_dy->Get("h_muon_multi");
  TH1F * h_muon_multi_qcd = (TH1F*) f_qcd->Get("h_muon_multi");
  TH1F * h_muon_multi_wjets = (TH1F*) f_wjets->Get("h_muon_multi");
  TH1F * h_muon_multi_ww = (TH1F*) f_ww->Get("h_muon_multi");
  TH1F * h_muon_multi_wz = (TH1F*) f_wz->Get("h_muon_multi");
  TH1F * h_muon_multi_zz = (TH1F*) f_zz->Get("h_muon_multi");
  TH1F * h_muon_multi_single_top = (TH1F*) f_single_top->Get("h_muon_multi");
  TH1F * h_muon_multi_data = (TH1F*) f_data->Get("h_muon_multi");

  h_muon_multi_ttbar->SetFillColor(kRed);
  h_muon_multi_wjets->SetFillColor(kOrange);
  h_muon_multi_dy->SetFillColor(kBlue);
  h_muon_multi_ww->SetFillColor(kGreen);
  h_muon_multi_wz->SetFillColor(kCyan);
  h_muon_multi_zz->SetFillColor(kYellow);
  h_muon_multi_qcd->SetFillColor(kMagenta);
  h_muon_multi_single_top->SetFillColor(kGray);
  h_muon_multi_data->SetMarkerColor(1);

  sh->Add(h_muon_multi_ttbar);
  sh->Add(h_muon_multi_wjets);
  sh->Add(h_muon_multi_dy);
  sh->Add(h_muon_multi_ww);
  sh->Add(h_muon_multi_wz);
  sh->Add(h_muon_multi_zz);
  sh->Add(h_muon_multi_qcd);
  sh->Add(h_muon_multi_single_top);

  TCanvas *fstack = new TCanvas("fstack","multi",700,600);
  h_muon_multi_data->SetMarkerStyle(20);
  h_muon_multi_data->SetLineColor(1);
  h_muon_multi_data->SetMarkerSize(0.8);
  fstack->DrawFrame(0,0.5,7,1000000)->SetTitle("muon multiplicity");  
  sh->GetYaxis()->SetTitle("Events");
  sh->GetXaxis()->SetTitle("Number of Muon"); 
  sh->Draw("histsame");
  h_muon_multi_data->Draw("psame");
  TLegend *leg = new TLegend(.75,.55,.9,.9,"");
  leg->AddEntry(h_muon_multi_ttbar,"ttbar","F");
  leg->AddEntry(h_muon_multi_wjets,"wjets","F");
  leg->AddEntry(h_muon_multi_dy,"Drell-Yan","F");
  leg->AddEntry(h_muon_multi_ww,"ww","F");
  leg->AddEntry(h_muon_multi_wz,"wz","F");
  leg->AddEntry(h_muon_multi_zz,"zz","F");
  leg->AddEntry(h_muon_multi_qcd,"qcd","F");
  leg->AddEntry(h_muon_multi_single_top,"single_top","F");
  leg->AddEntry(h_muon_multi_data,"data","p");
  leg->Draw();
  fstack->SetLogy();
  fstack->Print("out/STACK_multi.pdf");

  THStack *hs = new THStack("hs","invariant mass");
  TH1F * h_invmass_ttbar = (TH1F*) f_ttbar->Get("h_invmass");
  TH1F * h_invmass_dy = (TH1F*) f_dy->Get("h_invmass");
  TH1F * h_invmass_qcd = (TH1F*) f_qcd->Get("h_invmass");
  TH1F * h_invmass_wjets = (TH1F*) f_wjets->Get("h_invmass");
  TH1F * h_invmass_ww = (TH1F*) f_ww->Get("h_invmass");
  TH1F * h_invmass_wz = (TH1F*) f_wz->Get("h_invmass");
  TH1F * h_invmass_zz = (TH1F*) f_zz->Get("h_invmass");
  TH1F * h_invmass_single_top = (TH1F*) f_single_top->Get("h_invmass");
  TH1F * h_invmass_data = (TH1F*) f_data->Get("h_invmass");

  h_invmass_ttbar->SetFillColor(kRed);
  h_invmass_wjets->SetFillColor(kOrange);
  h_invmass_dy->SetFillColor(kBlue);
  h_invmass_ww->SetFillColor(kGreen);
  h_invmass_wz->SetFillColor(kCyan);
  h_invmass_zz->SetFillColor(kYellow);
  h_invmass_qcd->SetFillColor(kMagenta);
  h_invmass_single_top->SetFillColor(kGray);
  h_invmass_data->SetMarkerColor(1);

  hs->Add(h_invmass_ttbar);
  hs->Add(h_invmass_wjets);
  hs->Add(h_invmass_dy);
  hs->Add(h_invmass_ww);
  hs->Add(h_invmass_wz);
  hs->Add(h_invmass_zz);
  hs->Add(h_invmass_qcd);
  hs->Add(h_invmass_single_top);
 
  TCanvas *sstack = new TCanvas("sstack","invmass",700,600);
  h_invmass_data->SetMarkerStyle(20);
  h_invmass_data->SetMarkerSize(0.8);
  h_invmass_data->SetLineColor(1);
  hs->Draw("hist");
  h_invmass_data->Draw("epsame");
  hs->GetYaxis()->SetTitle("Events");
  hs->GetXaxis()->SetTitle("Muon(GeV)"); 
  TLegend *leg2 = new TLegend(.75,.55,.9,.9,"");
  leg2->AddEntry(h_invmass_ttbar,"ttbar","F");
  leg2->AddEntry(h_invmass_wjets,"wjets","F");
  leg2->AddEntry(h_invmass_dy,"Drell-Yan","F");
  leg2->AddEntry(h_invmass_ww,"ww","F");
  leg2->AddEntry(h_invmass_wz,"wz","F");
  leg2->AddEntry(h_invmass_zz,"zz","F");
  leg2->AddEntry(h_invmass_qcd,"qcd","F");
  leg2->AddEntry(h_invmass_single_top,"single_top","F");
  leg2->AddEntry(h_invmass_data,"data","p");
  leg2->Draw();
  sstack->SetLogy();
  sstack->Print("out/STACK_invmass.pdf");

  }
