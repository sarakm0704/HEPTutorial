void cutstack_ex2(){
    
  TFile * f_data = new TFile("out/cut/hist_data.root");
  TFile * f_dy = new TFile("out/cut/hist_dy.root");
  TFile * f_ttbar = new TFile("out/cut/hist_ttbar.root");
  TFile * f_qcd = new TFile("out/cut/hist_qcd.root");
  TFile * f_wjets = new TFile("out/cut/hist_wjets.root");
  TFile * f_single_top = new TFile("out/cut/hist_single_top.root");
  TFile * f_ww = new TFile("out/cut/hist_ww.root");
  TFile * f_wz = new TFile("out/cut/hist_wz.root");
  TFile * f_zz = new TFile("out/cut/hist_zz.root");

  THStack *h1 = new THStack("h1","jet_multi");
  TH1F * h_jet_multi_ttbar = (TH1F*) f_ttbar->Get("h_jet_multi");
  TH1F * h_jet_multi_wjets = (TH1F*) f_wjets->Get("h_jet_multi");
  TH1F * h_jet_multi_dy = (TH1F*) f_dy->Get("h_jet_multi");
  TH1F * h_jet_multi_ww = (TH1F*) f_ww->Get("h_jet_multi");
  TH1F * h_jet_multi_wz = (TH1F*) f_wz->Get("h_jet_multi");
  TH1F * h_jet_multi_zz = (TH1F*) f_zz->Get("h_jet_multi");
  TH1F * h_jet_multi_qcd = (TH1F*) f_qcd->Get("h_jet_multi");
  TH1F * h_jet_multi_single_top = (TH1F*) f_single_top->Get("h_jet_multi");
  TH1F * h_jet_multi_data = (TH1F*) f_data->Get("h_jet_multi");

  h_jet_multi_ttbar->SetFillColor(kRed);
  h_jet_multi_wjets->SetFillColor(kOrange);
  h_jet_multi_dy->SetFillColor(kBlue);
  h_jet_multi_ww->SetFillColor(kGreen);
  h_jet_multi_wz->SetFillColor(kCyan);
  h_jet_multi_zz->SetFillColor(kYellow);
  h_jet_multi_qcd->SetFillColor(kMagenta);
  h_jet_multi_single_top->SetFillColor(kGray);
  h_jet_multi_data->SetMarkerColor(1);

  h1->Add(h_jet_multi_ttbar);
  h1->Add(h_jet_multi_wjets);
  h1->Add(h_jet_multi_dy);
  h1->Add(h_jet_multi_ww);
  h1->Add(h_jet_multi_wz);
  h1->Add(h_jet_multi_zz);
  h1->Add(h_jet_multi_qcd);
  h1->Add(h_jet_multi_single_top);

  int binmax_jet_multi = h_jet_multi_ttbar->GetMaximumBin();
  float max_jet_multi = h_jet_multi_ttbar->GetXaxis()->GetBinCenter(binmax_jet_multi);

  float jet_multi_signal = h_jet_multi_ttbar->GetBinContent(binmax_jet_multi);
  TH1 *l1 = ((TH1*)(h1->GetStack()->Last()));
  float jet_multi_background = l1->GetBinContent(binmax_jet_multi);

  cout << "jet_multi_ttbar has maximum at: " << max_jet_multi << endl;
 
  cout << "signal: " << jet_multi_signal << endl;
  cout << "background: " << jet_multi_background << endl;

  TCanvas *s1 = new TCanvas("s1","multi",700,600);
  s1->DrawFrame(0,8,10,1000000)->SetTitle("multiplicity of jets");
  h1->GetYaxis()->SetTitle("Events");
  h1->GetXaxis()->SetTitle("Number of Jets"); 
  h1->Draw("histsame");
  TLegend *leg = new TLegend(.75,.55,.9,.9,"");
  leg->AddEntry(h_jet_multi_ttbar,"ttbar","F");
  leg->AddEntry(h_jet_multi_wjets,"wjets","F");
  leg->AddEntry(h_jet_multi_dy,"Drell-Yan","F");
  leg->AddEntry(h_jet_multi_ww,"ww","F");
  leg->AddEntry(h_jet_multi_wz,"wz","F");
  leg->AddEntry(h_jet_multi_zz,"zz","F");
  leg->AddEntry(h_jet_multi_qcd,"qcd","F");
  leg->AddEntry(h_jet_multi_single_top,"single_top","F");
  leg->Draw();
  s1->SetLogy();
  s1->Print("out/cut/STACK_multi_showmaximum.pdf");

  float signal_jet_multi = h_jet_multi_ttbar->Integral();
  
  float background_wjets_jet_multi = h_jet_multi_wjets->Integral();
  float background_dy_jet_multi = h_jet_multi_dy->Integral();
  float background_ww_jet_multi = h_jet_multi_ww->Integral();
  float background_wz_jet_multi = h_jet_multi_wz->Integral();
  float background_zz_jet_multi = h_jet_multi_zz->Integral();
  float background_qcd_jet_multi = h_jet_multi_qcd->Integral();
  float background_single_top_jet_multi = h_jet_multi_single_top->Integral();
  float background_total_jet_multi = background_wjets_jet_multi + background_dy_jet_multi + background_ww_jet_multi + background_wz_jet_multi + background_zz_jet_multi + background_qcd_jet_multi + background_single_top_jet_multi;

  float selection_efficiency_jet_multi = signal_jet_multi/sqrt(background_total_jet_multi);

  cout << "efficiency = " << selection_efficiency_jet_multi << endl;

  THStack *h2 = new THStack("h2","jet1_pt");
  TH1F * h_jet1_pt_ttbar = (TH1F*) f_ttbar->Get("h_jet1_pt");
  TH1F * h_jet1_pt_wjets = (TH1F*) f_wjets->Get("h_jet1_pt");
  TH1F * h_jet1_pt_dy = (TH1F*) f_dy->Get("h_jet1_pt");
  TH1F * h_jet1_pt_ww = (TH1F*) f_ww->Get("h_jet1_pt");
  TH1F * h_jet1_pt_wz = (TH1F*) f_wz->Get("h_jet1_pt");
  TH1F * h_jet1_pt_zz = (TH1F*) f_zz->Get("h_jet1_pt");
  TH1F * h_jet1_pt_qcd = (TH1F*) f_qcd->Get("h_jet1_pt");
  TH1F * h_jet1_pt_single_top = (TH1F*) f_single_top->Get("h_jet1_pt");
  TH1F * h_jet1_pt_data = (TH1F*) f_data->Get("h_jet1_pt");

  h_jet1_pt_ttbar->SetFillColor(kRed);
  h_jet1_pt_wjets->SetFillColor(kOrange);
  h_jet1_pt_dy->SetFillColor(kBlue);
  h_jet1_pt_ww->SetFillColor(kGreen);
  h_jet1_pt_wz->SetFillColor(kCyan);
  h_jet1_pt_zz->SetFillColor(kYellow);
  h_jet1_pt_qcd->SetFillColor(kMagenta);
  h_jet1_pt_single_top->SetFillColor(kGray);
  h_jet1_pt_data->SetMarkerColor(1);

  h2->Add(h_jet1_pt_ttbar);
  h2->Add(h_jet1_pt_wjets);
  h2->Add(h_jet1_pt_dy);
  h2->Add(h_jet1_pt_ww);
  h2->Add(h_jet1_pt_wz);
  h2->Add(h_jet1_pt_zz);
  h2->Add(h_jet1_pt_qcd);
  h2->Add(h_jet1_pt_single_top);

  int binmax_jet1_pt = h_jet1_pt_ttbar->GetMaximumBin();
  float max_jet1_pt = h_jet1_pt_ttbar->GetXaxis()->GetBinCenter(binmax_jet1_pt);

  float jet1_pt_signal = h_jet1_pt_ttbar->GetBinContent(binmax_jet1_pt);
  TH1 *l2 = ((TH1*)(h2->GetStack()->Last()));
  float jet1_pt_background = l2->GetBinContent(binmax_jet1_pt);

  cout << "jet1_pt_ttbar has maximum at: " << max_jet1_pt << endl;
 
  cout << "signal: " << jet1_pt_signal << endl;
  cout << "background: " << jet1_pt_background << endl;
  
  TCanvas *s2 = new TCanvas("s2","jet1_pt",700,600);
  s2->DrawFrame(30,100,100,5000)->SetTitle("pT(GeV)");
  h2->GetYaxis()->SetTitle("Events");
  h2->GetXaxis()->SetTitle("Number of Jets"); 
  h2->Draw("histsame");
  TLegend *leg2 = new TLegend(.75,.55,.9,.9,"");
  leg2->AddEntry(h_jet1_pt_ttbar,"ttbar","F");
  leg2->AddEntry(h_jet1_pt_wjets,"wjets","F");
  leg2->AddEntry(h_jet1_pt_dy,"Drell-Yan","F");
  leg2->AddEntry(h_jet1_pt_ww,"ww","F");
  leg2->AddEntry(h_jet1_pt_wz,"wz","F");
  leg2->AddEntry(h_jet1_pt_zz,"zz","F");
  leg2->AddEntry(h_jet1_pt_qcd,"qcd","F");
  leg2->AddEntry(h_jet1_pt_single_top,"single_top","F");
  leg2->Draw();
  s2->Print("out/cut/STACK_jet1_pt_showmaximum.pdf");

  float signal_jet1_pt = h_jet1_pt_ttbar->Integral();
  
  float background_wjets_jet1_pt = h_jet1_pt_wjets->Integral();
  float background_dy_jet1_pt = h_jet1_pt_dy->Integral();
  float background_ww_jet1_pt = h_jet1_pt_ww->Integral();
  float background_wz_jet1_pt = h_jet1_pt_wz->Integral();
  float background_zz_jet1_pt = h_jet1_pt_zz->Integral();
  float background_qcd_jet1_pt = h_jet1_pt_qcd->Integral();
  float background_single_top_jet1_pt = h_jet1_pt_single_top->Integral();
  float background_total_jet1_pt = background_wjets_jet1_pt + background_dy_jet1_pt + background_ww_jet1_pt + background_wz_jet1_pt + background_zz_jet1_pt + background_qcd_jet1_pt + background_single_top_jet1_pt;

  float selection_efficiency_jet1_pt = signal_jet1_pt/sqrt(background_total_jet1_pt);

  cout << "efficiency = " << selection_efficiency_jet1_pt << endl;

  THStack *c1 = new THStack("c1","cutflow");
  TH1F * h_cutflow_ttbar = (TH1F*) f_ttbar->Get("h_cutflow");
  TH1F * h_cutflow_wjets = (TH1F*) f_wjets->Get("h_cutflow");
  TH1F * h_cutflow_dy = (TH1F*) f_dy->Get("h_cutflow");
  TH1F * h_cutflow_ww = (TH1F*) f_ww->Get("h_cutflow");
  TH1F * h_cutflow_wz = (TH1F*) f_wz->Get("h_cutflow");
  TH1F * h_cutflow_zz = (TH1F*) f_zz->Get("h_cutflow");
  TH1F * h_cutflow_qcd = (TH1F*) f_qcd->Get("h_cutflow");
  TH1F * h_cutflow_single_top = (TH1F*) f_single_top->Get("h_cutflow");
  TH1F * h_cutflow_data = (TH1F*) f_data->Get("h_cutflow");

  h_cutflow_ttbar->SetFillColor(kRed);
  h_cutflow_wjets->SetFillColor(kOrange);
  h_cutflow_dy->SetFillColor(kBlue);
  h_cutflow_ww->SetFillColor(kGreen);
  h_cutflow_wz->SetFillColor(kCyan);
  h_cutflow_zz->SetFillColor(kYellow);
  h_cutflow_qcd->SetFillColor(kMagenta);
  h_cutflow_single_top->SetFillColor(kGray);
  h_cutflow_data->SetMarkerColor(1);

  c1->Add(h_cutflow_ttbar);
  c1->Add(h_cutflow_wjets);
  c1->Add(h_cutflow_dy);
  c1->Add(h_cutflow_ww);
  c1->Add(h_cutflow_wz);
  c1->Add(h_cutflow_zz);
  c1->Add(h_cutflow_qcd);
  c1->Add(h_cutflow_single_top);

  int binmax_cutflow = h_cutflow_ttbar->GetMaximumBin();
  float max_cutflow = h_cutflow_ttbar->GetXaxis()->GetBinCenter(binmax_cutflow);

  float cutflow_signal = h_cutflow_ttbar->GetBinContent(binmax_cutflow);
  TH1 *lc = ((TH1*)(c1->GetStack()->Last()));
  float cutflow_background = lc->GetBinContent(binmax_cutflow);

  cout << "cutflow_ttbar has maximum at: " << max_cutflow << endl;
 
  cout << "signal: " << cutflow_signal << endl;
  cout << "background: " << cutflow_background << endl;
  
  TCanvas *sc = new TCanvas("sc","cutflow",700,600);
  c1->Draw("hist");
  TLegend *legc = new TLegend(.75,.55,.9,.9,"");
  legc->AddEntry(h_cutflow_ttbar,"ttbar","F");
  legc->AddEntry(h_cutflow_wjets,"wjets","F");
  legc->AddEntry(h_cutflow_dy,"Drell-Yan","F");
  legc->AddEntry(h_cutflow_ww,"ww","F");
  legc->AddEntry(h_cutflow_wz,"wz","F");
  legc->AddEntry(h_cutflow_zz,"zz","F");
  legc->AddEntry(h_cutflow_qcd,"qcd","F");
  legc->AddEntry(h_cutflow_single_top,"single_top","F");
  legc->Draw();
  c1->GetYaxis()->SetTitle("Events");
  c1->GetXaxis()->SetTitle("Number of Jets"); 
  sc->Print("out/cut/STACK_cutflow_showmaximum.pdf");

  float signal_cutflow = h_cutflow_ttbar->Integral();
  
  float background_wjets_cutflow = h_cutflow_wjets->Integral();
  float background_dy_cutflow = h_cutflow_dy->Integral();
  float background_ww_cutflow = h_cutflow_ww->Integral();
  float background_wz_cutflow = h_cutflow_wz->Integral();
  float background_zz_cutflow = h_cutflow_zz->Integral();
  float background_qcd_cutflow = h_cutflow_qcd->Integral();
  float background_single_top_cutflow = h_cutflow_single_top->Integral();
  float background_total_cutflow = background_wjets_cutflow + background_dy_cutflow + background_ww_cutflow + background_wz_cutflow + background_zz_cutflow + background_qcd_cutflow + background_single_top_cutflow;

  float selection_efficiency_cutflow = signal_cutflow/sqrt(background_total_cutflow);

  cout << "efficiency = " << selection_efficiency_cutflow << endl;
}
