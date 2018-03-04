void stack_ex2(){

  TFile * f_data = new TFile("out/ex2/hist_data.root");
  TFile * f_dy = new TFile("out/ex2/hist_dy.root");
  TFile * f_ttbar = new TFile("out/ex2/hist_ttbar.root");
  TFile * f_qcd = new TFile("out/ex2/hist_qcd.root");
  TFile * f_wjets = new TFile("out/ex2/hist_wjets.root");
  TFile * f_single_top = new TFile("out/ex2/hist_single_top.root");
  TFile * f_ww = new TFile("out/ex2/hist_ww.root");
  TFile * f_wz = new TFile("out/ex2/hist_wz.root");
  TFile * f_zz = new TFile("out/ex2/hist_zz.root");

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
  //float max_jet_multi = h_jet_multi_ttbar->GetXaxis()->GetBinCenter(binmax_jet_multi);

  float jet_multi_signal = h_jet_multi_ttbar->GetBinContent(binmax_jet_multi);
  TH1 *l = ((TH1*)(h1->GetStack()->Last()));
  float jet_multi_background = l->GetBinContent(binmax_jet_multi);

  cout << "jet_multi_ttbar has maximum at: " << binmax_jet_multi << endl;

  cout << "signal: " << jet_multi_signal << endl;
  cout << "background: " << jet_multi_background << endl;

  TCanvas *s1 = new TCanvas("s1","multi",700,600);
 // h_jet_multi_data->SetMarkerStyle(20);
//  h_jet_multi_data->SetLineColor(1);
//  h_jet_multi_data->SetMarkerSize(0.8);
  s1->DrawFrame(0,8,10,1000000)->SetTitle("multiplicity of jets");
  h1->GetYaxis()->SetTitle("Events");
  h1->GetXaxis()->SetTitle("Number of Jets"); 
  h1->Draw("histsame");
//  h_jet_multi_data->Draw("psame");
  TLegend *leg = new TLegend(.75,.55,.9,.9,"");
//  leg->AddEntry(h_jet_multi_data,"data","p");
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
  s1->Print("out/ex2/STACK_multi.pdf");

  THStack *h2 = new THStack("h2","jet_pt");
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
 // h_jet1_pt_data->SetMarkerColor(1);

  h2->Add(h_jet1_pt_ttbar);
  h2->Add(h_jet1_pt_wjets);
  h2->Add(h_jet1_pt_dy);
  h2->Add(h_jet1_pt_ww);
  h2->Add(h_jet1_pt_wz);
  h2->Add(h_jet1_pt_zz);
  h2->Add(h_jet1_pt_qcd);
  h2->Add(h_jet1_pt_single_top);

  int binmax_jet1_pt = h_jet1_pt_ttbar->GetMaximumBin();
//  float max_jet1_pt = h_jet1_pt_ttbar->GetXaxis()->GetBinCenter(binmax_jet1_pt);

  cout << "jet1_pt_ttbar has maximum at: " << binmax_jet1_pt << endl;

  float jet1_pt_signal = h_jet1_pt_ttbar->GetBinContent(binmax_jet1_pt);
  TH1 *l1 = ((TH1*)(h2->GetStack()->Last()));
  float jet1_pt_background = l1->GetBinContent(binmax_jet1_pt);

  cout << "signal: " << jet1_pt_signal << endl;
  cout << "background: " << jet1_pt_background << endl;
 
  TCanvas *s2 = new TCanvas("s2","jet1_pt",700,600);
//  h_jet1_pt_data->SetMarkerStyle(20);
//  h_jet1_pt_data->SetMarkerSize(0.8);
//  h_jet1_pt_data->SetLineColor(1);
  h2->Draw("hist");
//  h_jet1_pt_data->Draw("epsame");
  TLegend *leg2 = new TLegend(.75,.55,.9,.9,"");
 // leg2->AddEntry(h_jet1_pt_data,"data","p");
  leg2->AddEntry(h_jet1_pt_ttbar,"ttbar","F");
  leg2->AddEntry(h_jet1_pt_dy,"Drell-Yan","F");
  leg2->AddEntry(h_jet1_pt_wjets,"wjets","F");
  leg2->AddEntry(h_jet1_pt_qcd,"qcd","F");
  leg2->AddEntry(h_jet1_pt_ww,"ww","F");
  leg2->AddEntry(h_jet1_pt_wz,"wz","F");
  leg2->AddEntry(h_jet1_pt_zz,"zz","F");
  leg2->AddEntry(h_jet1_pt_single_top,"single_top","F");
  leg2->Draw();
  s2->SetLogy();
  h2->GetYaxis()->SetTitle("Events");
//  h_jet1_pt_data->SetAxisRange(30,200,"X");
  h2->GetXaxis()->SetTitle("pT(GeV)"); 
  s2->Print("out/ex2/STACK_jet1_pt.pdf");

  THStack *h2a = new THStack("h2a","jet2_pt");
  TH1F * h_jet2_pt_ttbar = (TH1F*) f_ttbar->Get("h_jet2_pt");
  TH1F * h_jet2_pt_wjets = (TH1F*) f_wjets->Get("h_jet2_pt");
  TH1F * h_jet2_pt_dy = (TH1F*) f_dy->Get("h_jet2_pt");
  TH1F * h_jet2_pt_ww = (TH1F*) f_ww->Get("h_jet2_pt");
  TH1F * h_jet2_pt_wz = (TH1F*) f_wz->Get("h_jet2_pt");
  TH1F * h_jet2_pt_zz = (TH1F*) f_zz->Get("h_jet2_pt");
  TH1F * h_jet2_pt_qcd = (TH1F*) f_qcd->Get("h_jet2_pt");
  TH1F * h_jet2_pt_single_top = (TH1F*) f_single_top->Get("h_jet2_pt");
  TH1F * h_jet2_pt_data = (TH1F*) f_data->Get("h_jet2_pt");

  h_jet2_pt_ttbar->SetFillColor(kRed);
  h_jet2_pt_wjets->SetFillColor(kOrange);
  h_jet2_pt_dy->SetFillColor(kBlue);
  h_jet2_pt_ww->SetFillColor(kGreen);
  h_jet2_pt_wz->SetFillColor(kCyan);
  h_jet2_pt_zz->SetFillColor(kYellow);
  h_jet2_pt_qcd->SetFillColor(kMagenta);
  h_jet2_pt_single_top->SetFillColor(kGray);
  h_jet2_pt_data->SetMarkerColor(1);

  h2a->Add(h_jet2_pt_ttbar);
  h2a->Add(h_jet2_pt_wjets);
  h2a->Add(h_jet2_pt_dy);
  h2a->Add(h_jet2_pt_ww);
  h2a->Add(h_jet2_pt_wz);
  h2a->Add(h_jet2_pt_zz);
  h2a->Add(h_jet2_pt_qcd);
  h2a->Add(h_jet2_pt_single_top);

  int binmax_jet2_pt = h_jet2_pt_ttbar->GetMaximumBin();
//  float max_jet2_pt = h_jet2_pt_ttbar->GetXaxis()->GetBinCenter(binmax_jet2_pt);

  cout << "jet2_pt_ttbar has maximum at: " << binmax_jet2_pt << endl;

  float jet2_pt_signal = h_jet2_pt_ttbar->GetBinContent(binmax_jet2_pt);
  TH1 *l2 = ((TH1*)(h2a->GetStack()->Last()));
  float jet2_pt_background = l2->GetBinContent(binmax_jet2_pt);

  cout << "signal: " << jet2_pt_signal << endl;
  cout << "background: " << jet2_pt_background << endl;

  TCanvas *s2a = new TCanvas("s2a","jet2_pt",700,600);
 // h_jet2_pt_data->SetMarkerStyle(20);
//  h_jet2_pt_data->SetLineColor(1);
//  h_jet2_pt_data->SetMarkerSize(0.8);
  h2a->Draw("hist");
//  h_jet2_pt_data->Draw("psame");
  TLegend *leg2a = new TLegend(.75,.55,.9,.9,"");
//  leg2a->AddEntry(h_jet2_pt_data,"data","p");
  leg2a->AddEntry(h_jet2_pt_ttbar,"ttbar","F");
  leg2a->AddEntry(h_jet2_pt_wjets,"wjets","F");
  leg2a->AddEntry(h_jet2_pt_dy,"Drell-Yan","F");
  leg2a->AddEntry(h_jet2_pt_ww,"ww","F");
  leg2a->AddEntry(h_jet2_pt_wz,"wz","F");
  leg2a->AddEntry(h_jet2_pt_zz,"zz","F");
  leg2a->AddEntry(h_jet2_pt_qcd,"qcd","F");
  leg2a->AddEntry(h_jet2_pt_single_top,"single_top","F");
  leg2a->Draw();
  s2a->SetLogy();
//  h_jet2_pt_data->SetAxisRange(0,0.2,"X");
  h2a->GetYaxis()->SetTitle("Events");
  h2a->GetXaxis()->SetTitle("pT(GeV)"); 
  s2a->Print("out/ex2/STACK_jet2_pt.pdf");

  THStack *h2b = new THStack("h2b","jet3_pt");
  TH1F * h_jet3_pt_ttbar = (TH1F*) f_ttbar->Get("h_jet3_pt");
  TH1F * h_jet3_pt_wjets = (TH1F*) f_wjets->Get("h_jet3_pt");
  TH1F * h_jet3_pt_dy = (TH1F*) f_dy->Get("h_jet3_pt");
  TH1F * h_jet3_pt_ww = (TH1F*) f_ww->Get("h_jet3_pt");
  TH1F * h_jet3_pt_wz = (TH1F*) f_wz->Get("h_jet3_pt");
  TH1F * h_jet3_pt_zz = (TH1F*) f_zz->Get("h_jet3_pt");
  TH1F * h_jet3_pt_qcd = (TH1F*) f_qcd->Get("h_jet3_pt");
  TH1F * h_jet3_pt_single_top = (TH1F*) f_single_top->Get("h_jet3_pt");
  TH1F * h_jet3_pt_data = (TH1F*) f_data->Get("h_jet3_pt");

  h_jet3_pt_ttbar->SetFillColor(kRed);
  h_jet3_pt_wjets->SetFillColor(kOrange);
  h_jet3_pt_dy->SetFillColor(kBlue);
  h_jet3_pt_ww->SetFillColor(kGreen);
  h_jet3_pt_wz->SetFillColor(kCyan);
  h_jet3_pt_zz->SetFillColor(kYellow);
  h_jet3_pt_qcd->SetFillColor(kMagenta);
  h_jet3_pt_single_top->SetFillColor(kGray);
  h_jet3_pt_data->SetMarkerColor(1);
  
  h2b->Add(h_jet3_pt_ttbar);
  h2b->Add(h_jet3_pt_wjets);
  h2b->Add(h_jet3_pt_dy);
  h2b->Add(h_jet3_pt_ww);
  h2b->Add(h_jet3_pt_wz);
  h2b->Add(h_jet3_pt_zz);
  h2b->Add(h_jet3_pt_qcd);
  h2b->Add(h_jet3_pt_single_top);

  int binmax_jet3_pt = h_jet3_pt_ttbar->GetMaximumBin();
//  float max_jet3_pt = h_jet3_pt_ttbar->GetXaxis()->GetBinCenter(binmax_jet3_pt);

  cout << "jet3_pt_ttbar has maximum at: " << binmax_jet3_pt << endl;

  float jet3_pt_signal = h_jet3_pt_ttbar->GetBinContent(binmax_jet3_pt);
  TH1 *l3 = ((TH1*)(h2b->GetStack()->Last()));
  float jet3_pt_background = l3->GetBinContent(binmax_jet3_pt);

  cout << "signal: " << jet3_pt_signal << endl;
  cout << "background: " << jet3_pt_background << endl;
  
  TCanvas *s2b = new TCanvas("s2b","jet3_pt",700,600);
 // h_jet3_pt_data->SetMarkerStyle(20);
//  h_jet3_pt_data->SetLineColor(1);
//  h_jet3_pt_data->SetMarkerSize(0.8);
  h2b->Draw("hist");
//  h_jet3_pt_data->Draw("psame");
  TLegend *leg2b = new TLegend(.75,.55,.9,.9,"");
//  leg2b->AddEntry(h_jet3_pt_data,"data","p");
  leg2b->AddEntry(h_jet3_pt_ttbar,"ttbar","F");
  leg2b->AddEntry(h_jet3_pt_wjets,"wjets","F");
  leg2b->AddEntry(h_jet3_pt_dy,"Drell-Yan","F");
  leg2b->AddEntry(h_jet3_pt_ww,"ww","F");
  leg2b->AddEntry(h_jet3_pt_wz,"wz","F");
  leg2b->AddEntry(h_jet3_pt_zz,"zz","F");
  leg2b->AddEntry(h_jet3_pt_qcd,"qcd","F");
  leg2b->AddEntry(h_jet3_pt_single_top,"single_top","F");
  leg2b->Draw();
  s2b->SetLogy();
//  h_jet3_pt_data->SetAxisRange(0,0.2,"X");
  h2b->GetYaxis()->SetTitle("Events");
  h2b->GetXaxis()->SetTitle("pT(GeV)"); 
  s2b->Print("out/ex2/STACK_jet3_pt.pdf");

  THStack *h3 = new THStack("h3","met");
  TH1F * h_met_ttbar = (TH1F*) f_ttbar->Get("h_met");
  TH1F * h_met_wjets = (TH1F*) f_wjets->Get("h_met");
  TH1F * h_met_dy = (TH1F*) f_dy->Get("h_met");
  TH1F * h_met_ww = (TH1F*) f_ww->Get("h_met");
  TH1F * h_met_wz = (TH1F*) f_wz->Get("h_met");
  TH1F * h_met_zz = (TH1F*) f_zz->Get("h_met");
  TH1F * h_met_qcd = (TH1F*) f_qcd->Get("h_met");
  TH1F * h_met_single_top = (TH1F*) f_single_top->Get("h_met");
  TH1F * h_met_data = (TH1F*) f_data->Get("h_met");

  h_met_ttbar->SetFillColor(kRed);
  h_met_wjets->SetFillColor(kOrange);
  h_met_dy->SetFillColor(kBlue);
  h_met_ww->SetFillColor(kGreen);
  h_met_wz->SetFillColor(kCyan);
  h_met_zz->SetFillColor(kYellow);
  h_met_qcd->SetFillColor(kMagenta);
  h_met_single_top->SetFillColor(kGray);
//  h_met_data->SetMarkerColor(1);

  h3->Add(h_met_ttbar);
  h3->Add(h_met_wjets);
  h3->Add(h_met_dy);
  h3->Add(h_met_ww);
  h3->Add(h_met_wz);
  h3->Add(h_met_zz);
  h3->Add(h_met_qcd);
  h3->Add(h_met_single_top);
   
  int binmax_met = h_met_ttbar->GetMaximumBin();
//  float max_met = h_met_ttbar->GetXaxis()->GetBinCenter(binmax_met);

  cout << "met_ttbar has maximum at: " << binmax_met << endl;

  float met_signal = h_met_ttbar->GetBinContent(binmax_met);
  TH1 *l4 = ((TH1*)(h3->GetStack()->Last()));
  float met_background = l4->GetBinContent(binmax_met);

  cout << "signal: " << met_signal << endl;
  cout << "background: " << met_background << endl;
  
  TCanvas *s3 = new TCanvas("s3","met",700,600);
  h_met_data->SetMarkerStyle(20);
  h_met_data->SetMarkerSize(0.8);
  h_met_data->SetLineColor(1);
  h3->Draw("hist");
//  h_met_data->Draw("epsame");
  TLegend *leg3 = new TLegend(.75,.55,.9,.9,"");
//  leg3->AddEntry(h_met_data,"data","p");
  leg3->AddEntry(h_met_ttbar,"ttbar","F");
  leg3->AddEntry(h_met_dy,"Drell-Yan","F");
  leg3->AddEntry(h_met_wjets,"wjets","F");
  leg3->AddEntry(h_met_qcd,"qcd","F");
  leg3->AddEntry(h_met_ww,"ww","F");
  leg3->AddEntry(h_met_wz,"wz","F");
  leg3->AddEntry(h_met_zz,"zz","F");
  leg3->AddEntry(h_met_single_top,"single_top","F");
  leg3->Draw();
  s3->SetLogy();
  h3->GetYaxis()->SetTitle("Events");
  h_met_data->SetAxisRange(0,200,"X");
  h3->GetXaxis()->SetTitle("MET(GeV)"); 
  s3->Print("out/ex2/STACK_met.pdf");
  
  THStack *h4 = new THStack("h4","muon_pt");
  TH1F * h_muon_pt_ttbar = (TH1F*) f_ttbar->Get("h_muon_pt");
  TH1F * h_muon_pt_wjets = (TH1F*) f_wjets->Get("h_muon_pt");
  TH1F * h_muon_pt_dy = (TH1F*) f_dy->Get("h_muon_pt");
  TH1F * h_muon_pt_ww = (TH1F*) f_ww->Get("h_muon_pt");
  TH1F * h_muon_pt_wz = (TH1F*) f_wz->Get("h_muon_pt");
  TH1F * h_muon_pt_zz = (TH1F*) f_zz->Get("h_muon_pt");
  TH1F * h_muon_pt_qcd = (TH1F*) f_qcd->Get("h_muon_pt");
  TH1F * h_muon_pt_single_top = (TH1F*) f_single_top->Get("h_muon_pt");
  TH1F * h_muon_pt_data = (TH1F*) f_data->Get("h_muon_pt");

  h_muon_pt_ttbar->SetFillColor(kRed);
  h_muon_pt_wjets->SetFillColor(kOrange);
  h_muon_pt_dy->SetFillColor(kBlue);
  h_muon_pt_ww->SetFillColor(kGreen);
  h_muon_pt_wz->SetFillColor(kCyan);
  h_muon_pt_zz->SetFillColor(kYellow);
  h_muon_pt_qcd->SetFillColor(kMagenta);
  h_muon_pt_single_top->SetFillColor(kGray);
//  h_muon_pt_data->SetMarkerColor(1);
  
  h4->Add(h_muon_pt_ttbar);
  h4->Add(h_muon_pt_wjets);
  h4->Add(h_muon_pt_dy);
  h4->Add(h_muon_pt_ww);
  h4->Add(h_muon_pt_wz);
  h4->Add(h_muon_pt_zz);
  h4->Add(h_muon_pt_qcd);
  h4->Add(h_muon_pt_single_top);
 
  int binmax_muon_pt = h_muon_pt_ttbar->GetMaximumBin();
//  float max_muon_pt = h_muon_pt_ttbar->GetXaxis()->GetBinCenter(binmax_muon_pt);

  cout << "muon_pt_ttbar has maximum at: " << binmax_muon_pt << endl;

  float muon_pt_signal = h_muon_pt_ttbar->GetBinContent(binmax_muon_pt);
  TH1 *l5 = ((TH1*)(h4->GetStack()->Last()));
  float muon_pt_background = l5->GetBinContent(binmax_muon_pt);

  cout << "signal: " << muon_pt_signal << endl;
  cout << "background: " << muon_pt_background << endl;
  
  TCanvas *s4 = new TCanvas("s4","muon_pt",700,600);
//  h_muon_pt_data->SetMarkerStyle(20);
//  h_muon_pt_data->SetMarkerSize(0.8);
//  h_muon_pt_data->SetLineColor(1);
  h4->Draw("hist");
//  h_muon_pt_data->Draw("epsame");
  TLegend *leg4 = new TLegend(.75,.55,.9,.9,"");
//  leg4->AddEntry(h_muon_pt_data,"data","p");
  leg4->AddEntry(h_muon_pt_ttbar,"ttbar","F");
  leg4->AddEntry(h_muon_pt_dy,"Drell-Yan","F");
  leg4->AddEntry(h_muon_pt_wjets,"wjets","F");
  leg4->AddEntry(h_muon_pt_qcd,"qcd","F");
  leg4->AddEntry(h_muon_pt_ww,"ww","F");
  leg4->AddEntry(h_muon_pt_wz,"wz","F");
  leg4->AddEntry(h_muon_pt_zz,"zz","F");
  leg4->AddEntry(h_muon_pt_single_top,"single_top","F");
  leg4->Draw();
  s4->SetLogy();
  h4->GetYaxis()->SetTitle("Events");
  h_muon_pt_data->SetAxisRange(30,200,"X");
  h4->GetXaxis()->SetTitle("pT(GeV)"); 
  s4->Print("out/ex2/STACK_muon_pt.pdf");
  
  THStack *h5 = new THStack("h5","electron_pt");
  TH1F * h_electron_pt_ttbar = (TH1F*) f_ttbar->Get("h_electron_pt");
  TH1F * h_electron_pt_wjets = (TH1F*) f_wjets->Get("h_electron_pt");
  TH1F * h_electron_pt_dy = (TH1F*) f_dy->Get("h_electron_pt");
  TH1F * h_electron_pt_ww = (TH1F*) f_ww->Get("h_electron_pt");
  TH1F * h_electron_pt_wz = (TH1F*) f_wz->Get("h_electron_pt");
  TH1F * h_electron_pt_zz = (TH1F*) f_zz->Get("h_electron_pt");
  TH1F * h_electron_pt_qcd = (TH1F*) f_qcd->Get("h_electron_pt");
  TH1F * h_electron_pt_single_top = (TH1F*) f_single_top->Get("h_electron_pt");
  TH1F * h_electron_pt_data = (TH1F*) f_data->Get("h_electron_pt");

  h_electron_pt_ttbar->SetFillColor(kRed);
  h_electron_pt_wjets->SetFillColor(kOrange);
  h_electron_pt_dy->SetFillColor(kBlue);
  h_electron_pt_ww->SetFillColor(kGreen);
  h_electron_pt_wz->SetFillColor(kCyan);
  h_electron_pt_zz->SetFillColor(kYellow);
  h_electron_pt_qcd->SetFillColor(kMagenta);
  h_electron_pt_single_top->SetFillColor(kGray);
  h_electron_pt_data->SetMarkerColor(1);

  h5->Add(h_electron_pt_ttbar);
  h5->Add(h_electron_pt_wjets);
  h5->Add(h_electron_pt_dy);
  h5->Add(h_electron_pt_ww);
  h5->Add(h_electron_pt_wz);
  h5->Add(h_electron_pt_zz);
  h5->Add(h_electron_pt_qcd);
  h5->Add(h_electron_pt_single_top);
  
  int binmax_electron_pt = h_electron_pt_ttbar->GetMaximumBin();
//  float max_electron_pt = h_electron_pt_ttbar->GetXaxis()->GetBinCenter(binmax_electron_pt);

  cout << "electron_pt_ttbar has maximum at: " << binmax_electron_pt << endl;

  float electron_pt_signal = h_electron_pt_ttbar->GetBinContent(binmax_electron_pt);
  TH1 *l6 = ((TH1*)(h5->GetStack()->Last()));
  float electron_pt_background = l6->GetBinContent(binmax_electron_pt);

  cout << "signal: " << electron_pt_signal << endl;
  cout << "background: " << electron_pt_background << endl;
  
  TCanvas *s5 = new TCanvas("s5","electron_pt",700,600);
  h_electron_pt_data->SetMarkerStyle(20);
  h_electron_pt_data->SetMarkerSize(0.8);
  h_electron_pt_data->SetLineColor(1);
  h5->Draw("hist");
//  h_electron_pt_data->Draw("epsame");
  TLegend *leg5 = new TLegend(.75,.55,.9,.9,"");
//  leg5->AddEntry(h_electron_pt_data,"data","p");
  leg5->AddEntry(h_electron_pt_ttbar,"ttbar","F");
  leg5->AddEntry(h_electron_pt_dy,"Drell-Yan","F");
  leg5->AddEntry(h_electron_pt_wjets,"wjets","F");
  leg5->AddEntry(h_electron_pt_qcd,"qcd","F");
  leg5->AddEntry(h_electron_pt_ww,"ww","F");
  leg5->AddEntry(h_electron_pt_wz,"wz","F");
  leg5->AddEntry(h_electron_pt_zz,"zz","F");
  leg5->AddEntry(h_electron_pt_single_top,"single_top","F");
  leg5->Draw();
  s5->SetLogy();
  h_electron_pt_data->SetAxisRange(30,200,"X");
  h5->GetYaxis()->SetTitle("Events");
  h5->GetXaxis()->SetTitle("pT(GeV)"); 
  s5->Print("out/ex2/STACK_electron_pt.pdf");
  
  THStack *h6 = new THStack("h6","jet_eta");
  TH1F * h_jet_eta_ttbar = (TH1F*) f_ttbar->Get("h_jet_eta");
  TH1F * h_jet_eta_wjets = (TH1F*) f_wjets->Get("h_jet_eta");
  TH1F * h_jet_eta_dy = (TH1F*) f_dy->Get("h_jet_eta");
  TH1F * h_jet_eta_ww = (TH1F*) f_ww->Get("h_jet_eta");
  TH1F * h_jet_eta_wz = (TH1F*) f_wz->Get("h_jet_eta");
  TH1F * h_jet_eta_zz = (TH1F*) f_zz->Get("h_jet_eta");
  TH1F * h_jet_eta_qcd = (TH1F*) f_qcd->Get("h_jet_eta");
  TH1F * h_jet_eta_single_top = (TH1F*) f_single_top->Get("h_jet_eta");
  TH1F * h_jet_eta_data = (TH1F*) f_data->Get("h_jet_eta");

  h_jet_eta_ttbar->SetFillColor(kRed);
  h_jet_eta_wjets->SetFillColor(kOrange);
  h_jet_eta_dy->SetFillColor(kBlue);
  h_jet_eta_ww->SetFillColor(kGreen);
  h_jet_eta_wz->SetFillColor(kCyan);
  h_jet_eta_zz->SetFillColor(kYellow);
  h_jet_eta_qcd->SetFillColor(kMagenta);
  h_jet_eta_single_top->SetFillColor(kGray);
//  h_jet_eta_data->SetMarkerColor(1);

  h6->Add(h_jet_eta_ttbar);
  h6->Add(h_jet_eta_wjets);
  h6->Add(h_jet_eta_dy);
  h6->Add(h_jet_eta_ww);
  h6->Add(h_jet_eta_wz);
  h6->Add(h_jet_eta_zz);
  h6->Add(h_jet_eta_qcd);
  h6->Add(h_jet_eta_single_top);
 
  int binmax_jet_eta = h_jet_eta_ttbar->GetMaximumBin();
//  float max_jet_eta = h_jet_eta_ttbar->GetXaxis()->GetBinCenter(binmax_jet_eta);

  cout << "jet_eta_ttbar has maximum at: " << binmax_jet_eta << endl;

  float jet_eta_signal = h_jet_eta_ttbar->GetBinContent(binmax_jet_eta);
  TH1 *l7 = ((TH1*)(h6->GetStack()->Last()));
  float jet_eta_background = l7->GetBinContent(binmax_jet_eta);

  cout << "signal: " << jet_eta_signal << endl;
  cout << "background: " << jet_eta_background << endl;

  TCanvas *s6 = new TCanvas("s6","jet_eta",700,600);
  h_jet_eta_data->SetMarkerStyle(20);
  h_jet_eta_data->SetLineColor(1);
  h_jet_eta_data->SetMarkerSize(0.8);
  h6->Draw("hist");
//  h_jet_eta_data->Draw("psame");
  TLegend *leg6 = new TLegend(.75,.55,.9,.9,"");
//  leg6->AddEntry(h_jet_eta_data,"data","p");
  leg6->AddEntry(h_jet_eta_ttbar,"ttbar","F");
  leg6->AddEntry(h_jet_eta_dy,"Drell-Yan","F");
  leg6->AddEntry(h_jet_eta_wjets,"wjets","F");
  leg6->AddEntry(h_jet_eta_qcd,"qcd","F");
  leg6->AddEntry(h_jet_eta_ww,"ww","F");
  leg6->AddEntry(h_jet_eta_wz,"wz","F");
  leg6->AddEntry(h_jet_eta_zz,"zz","F");
  leg6->AddEntry(h_jet_eta_single_top,"single_top","F");
  leg6->Draw();
  s6->SetLogy();
  h6->GetYaxis()->SetTitle("Events");
  h6->GetXaxis()->SetTitle("#eta"); 
  s6->Print("out/ex2/STACK_jet_eta.pdf");

  THStack *h7 = new THStack("h7","muon_eta");
  TH1F * h_muon_eta_ttbar = (TH1F*) f_ttbar->Get("h_muon_eta");
  TH1F * h_muon_eta_wjets = (TH1F*) f_wjets->Get("h_muon_eta");
  TH1F * h_muon_eta_dy = (TH1F*) f_dy->Get("h_muon_eta");
  TH1F * h_muon_eta_ww = (TH1F*) f_ww->Get("h_muon_eta");
  TH1F * h_muon_eta_wz = (TH1F*) f_wz->Get("h_muon_eta");
  TH1F * h_muon_eta_zz = (TH1F*) f_zz->Get("h_muon_eta");
  TH1F * h_muon_eta_qcd = (TH1F*) f_qcd->Get("h_muon_eta");
  TH1F * h_muon_eta_single_top = (TH1F*) f_single_top->Get("h_muon_eta");
  TH1F * h_muon_eta_data = (TH1F*) f_data->Get("h_muon_eta");

  h_muon_eta_ttbar->SetFillColor(kRed);
  h_muon_eta_wjets->SetFillColor(kOrange);
  h_muon_eta_dy->SetFillColor(kBlue);
  h_muon_eta_ww->SetFillColor(kGreen);
  h_muon_eta_wz->SetFillColor(kCyan);
  h_muon_eta_zz->SetFillColor(kYellow);
  h_muon_eta_qcd->SetFillColor(kMagenta);
  h_muon_eta_single_top->SetFillColor(kGray);
  h_muon_eta_data->SetMarkerColor(1);

  h7->Add(h_muon_eta_ttbar);
  h7->Add(h_muon_eta_wjets);
  h7->Add(h_muon_eta_dy);
  h7->Add(h_muon_eta_ww);
  h7->Add(h_muon_eta_wz);
  h7->Add(h_muon_eta_zz);
  h7->Add(h_muon_eta_qcd);
  h7->Add(h_muon_eta_single_top);
 
  int binmax_muon_eta = h_muon_eta_ttbar->GetMaximumBin();
//  float max_muon_eta = h_muon_eta_ttbar->GetXaxis()->GetBinCenter(binmax_muon_eta);

  cout << "muon_eta_ttbar has maximum at: " << binmax_muon_eta << endl;

  float muon_eta_signal = h_muon_eta_ttbar->GetBinContent(binmax_muon_eta);
  TH1 *l8 = ((TH1*)(h7->GetStack()->Last()));
  float muon_eta_background = l8->GetBinContent(binmax_muon_eta);

  cout << "signal: " << muon_eta_signal << endl;
  cout << "background: " << muon_eta_background << endl;
  
  TCanvas *s7 = new TCanvas("s7","muon_eta",700,600);
  h_muon_eta_data->SetMarkerStyle(20);
  h_muon_eta_data->SetLineColor(1);
  h_muon_eta_data->SetMarkerSize(0.8);
  h7->Draw("hist");
//  h_muon_eta_data->Draw("psame");
  TLegend *leg7 = new TLegend(.75,.55,.9,.9,"");
//  leg7->AddEntry(h_muon_eta_data,"data","p");
  leg7->AddEntry(h_muon_eta_ttbar,"ttbar","F");
  leg7->AddEntry(h_muon_eta_dy,"Drell-Yan","F");
  leg7->AddEntry(h_muon_eta_wjets,"wjets","F");
  leg7->AddEntry(h_muon_eta_qcd,"qcd","F");
  leg7->AddEntry(h_muon_eta_ww,"ww","F");
  leg7->AddEntry(h_muon_eta_wz,"wz","F");
  leg7->AddEntry(h_muon_eta_zz,"zz","F");
  leg7->AddEntry(h_muon_eta_single_top,"single_top","F");
  leg7->Draw();
  s7->SetLogy();
  h7->GetYaxis()->SetTitle("Events");
  h7->GetXaxis()->SetTitle("#eta"); 
  s7->Print("out/ex2/STACK_muon_eta.pdf");

  THStack *h8 = new THStack("h8","electron_eta");
  TH1F * h_electron_eta_ttbar = (TH1F*) f_ttbar->Get("h_electron_eta");
  TH1F * h_electron_eta_wjets = (TH1F*) f_wjets->Get("h_electron_eta");
  TH1F * h_electron_eta_dy = (TH1F*) f_dy->Get("h_electron_eta");
  TH1F * h_electron_eta_ww = (TH1F*) f_ww->Get("h_electron_eta");
  TH1F * h_electron_eta_wz = (TH1F*) f_wz->Get("h_electron_eta");
  TH1F * h_electron_eta_zz = (TH1F*) f_zz->Get("h_electron_eta");
  TH1F * h_electron_eta_qcd = (TH1F*) f_qcd->Get("h_electron_eta");
  TH1F * h_electron_eta_single_top = (TH1F*) f_single_top->Get("h_electron_eta");
  TH1F * h_electron_eta_data = (TH1F*) f_data->Get("h_electron_eta");

  h_electron_eta_ttbar->SetFillColor(kRed);
  h_electron_eta_wjets->SetFillColor(kOrange);
  h_electron_eta_dy->SetFillColor(kBlue);
  h_electron_eta_ww->SetFillColor(kGreen);
  h_electron_eta_wz->SetFillColor(kCyan);
  h_electron_eta_zz->SetFillColor(kYellow);
  h_electron_eta_qcd->SetFillColor(kMagenta);
  h_electron_eta_single_top->SetFillColor(kGray);
//  h_electron_eta_data->SetMarkerColor(1);  

  h8->Add(h_electron_eta_ttbar);
  h8->Add(h_electron_eta_wjets);
  h8->Add(h_electron_eta_dy);
  h8->Add(h_electron_eta_ww);
  h8->Add(h_electron_eta_wz);
  h8->Add(h_electron_eta_zz);
  h8->Add(h_electron_eta_qcd);
  h8->Add(h_electron_eta_single_top);
   
  int binmax_electron_eta = h_electron_eta_ttbar->GetMaximumBin();
//  float max_electron_eta = h_electron_eta_ttbar->GetXaxis()->GetBinCenter(binmax_electron_eta);

  cout << "electron_eta_ttbar has maximum at: " << binmax_electron_eta << endl;

  float electron_eta_signal = h_electron_eta_ttbar->GetBinContent(binmax_electron_eta);
  TH1 *l9 = ((TH1*)(h8->GetStack()->Last()));
  float electron_eta_background = l9->GetBinContent(binmax_electron_eta);

  cout << "signal: " << electron_eta_signal << endl;
  cout << "background: " << electron_eta_background << endl;

  TCanvas *s8 = new TCanvas("s8","electron_eta",700,600);
//  h_electron_eta_data->SetMarkerStyle(20);
 // h_electron_eta_data->SetLineColor(1);
 // h_electron_eta_data->SetMarkerSize(0.8);
  h8->Draw("hist");
 // h_electron_eta_data->Draw("psame");
  TLegend *leg8 = new TLegend(.75,.55,.9,.9,"");
//  leg8->AddEntry(h_electron_eta_data,"data","p");
  leg8->AddEntry(h_electron_eta_ttbar,"ttbar","F");
  leg8->AddEntry(h_electron_eta_dy,"Drell-Yan","F");
  leg8->AddEntry(h_electron_eta_wjets,"wjets","F");
  leg8->AddEntry(h_electron_eta_qcd,"qcd","F");
  leg8->AddEntry(h_electron_eta_ww,"ww","F");
  leg8->AddEntry(h_electron_eta_wz,"wz","F");
  leg8->AddEntry(h_electron_eta_zz,"zz","F");
  leg8->AddEntry(h_electron_eta_single_top,"single_top","F");
  leg8->Draw();
  s8->SetLogy();
  h8->GetYaxis()->SetTitle("Events");
  h8->GetXaxis()->SetTitle("#eta"); 
  s8->Print("out/ex2/STACK_electron_eta.pdf");

  THStack *h9 = new THStack("h9","muon_iso");
  TH1F * h_muon_iso_ttbar = (TH1F*) f_ttbar->Get("h_muon_iso");
  TH1F * h_muon_iso_wjets = (TH1F*) f_wjets->Get("h_muon_iso");
  TH1F * h_muon_iso_dy = (TH1F*) f_dy->Get("h_muon_iso");
  TH1F * h_muon_iso_ww = (TH1F*) f_ww->Get("h_muon_iso");
  TH1F * h_muon_iso_wz = (TH1F*) f_wz->Get("h_muon_iso");
  TH1F * h_muon_iso_zz = (TH1F*) f_zz->Get("h_muon_iso");
  TH1F * h_muon_iso_qcd = (TH1F*) f_qcd->Get("h_muon_iso");
  TH1F * h_muon_iso_single_top = (TH1F*) f_single_top->Get("h_muon_iso");
  TH1F * h_muon_iso_data = (TH1F*) f_data->Get("h_muon_iso");

  h_muon_iso_ttbar->SetFillColor(kRed);
  h_muon_iso_wjets->SetFillColor(kOrange);
  h_muon_iso_dy->SetFillColor(kBlue);
  h_muon_iso_ww->SetFillColor(kGreen);
  h_muon_iso_wz->SetFillColor(kCyan);
  h_muon_iso_zz->SetFillColor(kYellow);
  h_muon_iso_qcd->SetFillColor(kMagenta);
  h_muon_iso_single_top->SetFillColor(kGray);
  h_muon_iso_data->SetMarkerColor(1);
    
  h9->Add(h_muon_iso_ttbar);
  h9->Add(h_muon_iso_wjets);
  h9->Add(h_muon_iso_dy);
  h9->Add(h_muon_iso_ww);
  h9->Add(h_muon_iso_wz);
  h9->Add(h_muon_iso_zz);
  h9->Add(h_muon_iso_qcd);
  h9->Add(h_muon_iso_single_top);

  int binmax_muon_iso = h_muon_iso_ttbar->GetMaximumBin();
//  float max_muon_iso = h_muon_iso_ttbar->GetXaxis()->GetBinCenter(binmax_muon_iso);

  cout << "muon_iso_ttbar has maximum at: " << binmax_muon_iso << endl;

  float muon_iso_signal = h_muon_iso_ttbar->GetBinContent(binmax_muon_iso);
  TH1 *l10 = ((TH1*)(h9->GetStack()->Last()));
  float muon_iso_background = l10->GetBinContent(binmax_muon_iso);

  cout << "signal: " << muon_iso_signal << endl;
  cout << "background: " << muon_iso_background << endl;

  TCanvas *s9 = new TCanvas("s9","muon_iso",700,600);
 // h_muon_iso_data->SetMarkerStyle(20);
//  h_muon_iso_data->SetLineColor(1);
//  h_muon_iso_data->SetMarkerSize(0.8);
  h9->Draw("hist");
//  h_muon_iso_data->Draw("psame");
  TLegend *leg9 = new TLegend(.75,.55,.9,.9,"");
//  leg9->AddEntry(h_muon_iso_data,"data","p");
  leg9->AddEntry(h_muon_iso_ttbar,"ttbar","F");
  leg9->AddEntry(h_muon_iso_wjets,"wjets","F");
  leg9->AddEntry(h_muon_iso_dy,"Drell-Yan","F");
  leg9->AddEntry(h_muon_iso_ww,"ww","F");
  leg9->AddEntry(h_muon_iso_wz,"wz","F");
  leg9->AddEntry(h_muon_iso_zz,"zz","F");
  leg9->AddEntry(h_muon_iso_qcd,"qcd","F");
  leg9->AddEntry(h_muon_iso_single_top,"single_top","F");
  leg9->Draw();
//  s9->SetLogy();
//  h_muon_iso_data->SetAxisRange(0,0.2,"X");
  h9->GetYaxis()->SetTitle("Events");
  h9->GetXaxis()->SetTitle("muon iso"); 
  s9->Print("out/ex2/STACK_muon_iso.pdf");

  THStack *h10 = new THStack("h10","electron_iso");
  TH1F * h_electron_iso_ttbar = (TH1F*) f_ttbar->Get("h_electron_iso");
  TH1F * h_electron_iso_wjets = (TH1F*) f_wjets->Get("h_electron_iso");
  TH1F * h_electron_iso_dy = (TH1F*) f_dy->Get("h_electron_iso");
  TH1F * h_electron_iso_ww = (TH1F*) f_ww->Get("h_electron_iso");
  TH1F * h_electron_iso_wz = (TH1F*) f_wz->Get("h_electron_iso");
  TH1F * h_electron_iso_zz = (TH1F*) f_zz->Get("h_electron_iso");
  TH1F * h_electron_iso_qcd = (TH1F*) f_qcd->Get("h_electron_iso");
  TH1F * h_electron_iso_single_top = (TH1F*) f_single_top->Get("h_electron_iso");
  TH1F * h_electron_iso_data = (TH1F*) f_data->Get("h_electron_iso");

  h_electron_iso_ttbar->SetFillColor(kRed);
  h_electron_iso_wjets->SetFillColor(kOrange);
  h_electron_iso_dy->SetFillColor(kBlue);
  h_electron_iso_ww->SetFillColor(kGreen);
  h_electron_iso_wz->SetFillColor(kCyan);
  h_electron_iso_zz->SetFillColor(kYellow);
  h_electron_iso_qcd->SetFillColor(kMagenta);
  h_electron_iso_single_top->SetFillColor(kGray);
  h_electron_iso_data->SetMarkerColor(1);

  h10->Add(h_electron_iso_ttbar);
  h10->Add(h_electron_iso_wjets);
  h10->Add(h_electron_iso_dy);
  h10->Add(h_electron_iso_ww);
  h10->Add(h_electron_iso_wz);
  h10->Add(h_electron_iso_zz);
  h10->Add(h_electron_iso_qcd);
  h10->Add(h_electron_iso_single_top);
 
  int binmax_electron_iso = h_electron_iso_ttbar->GetMaximumBin();
//  float max_electron_iso = h_electron_iso_ttbar->GetXaxis()->GetBinCenter(binmax_electron_iso);

  cout << "electron_iso_ttbar has maximum at: " << binmax_electron_iso << endl;

  float electron_iso_signal = h_electron_iso_ttbar->GetBinContent(binmax_electron_iso);
  TH1 *l11 = ((TH1*)(h10->GetStack()->Last()));
  float electron_iso_background = l11->GetBinContent(binmax_electron_iso);

  cout << "signal: " << electron_iso_signal << endl;
  cout << "background: " << electron_iso_background << endl;
  
  TCanvas *s10 = new TCanvas("s10","electron_iso",700,600);
 // h_electron_iso_data->SetMarkerStyle(20);
//  h_electron_iso_data->SetLineColor(1);
//  h_electron_iso_data->SetMarkerSize(0.8);
  h10->Draw("hist");
//  h_electron_iso_data->Draw("psame");
  TLegend *leg10 = new TLegend(.75,.55,.9,.9,"");
//  leg10->AddEntry(h_electron_iso_data,"data","p");
  leg10->AddEntry(h_electron_iso_ttbar,"t#bar{t}","F");
  leg10->AddEntry(h_electron_iso_wjets,"wjets","F");
  leg10->AddEntry(h_electron_iso_dy,"Drell-Yan","F");
  leg10->AddEntry(h_electron_iso_ww,"ww","F");
  leg10->AddEntry(h_electron_iso_wz,"wz","F");
  leg10->AddEntry(h_electron_iso_zz,"zz","F");
  leg10->AddEntry(h_electron_iso_qcd,"qcd","F");
  leg10->AddEntry(h_electron_iso_single_top,"single_top","F");
  leg10->Draw();
//  s10->SetLogy();
//  h_electron_iso_data->SetAxisRange(0,0.2,"X");
  h10->GetYaxis()->SetTitle("Events");
  h10->GetXaxis()->SetTitle("electron isolation"); 
  s10->Print("out/ex2/STACK_electron_iso.pdf");
  
  THStack *h11 = new THStack("h11","bjet");
  TH1F * h_bjet_ttbar = (TH1F*) f_ttbar->Get("h_bjet");
  TH1F * h_bjet_wjets = (TH1F*) f_wjets->Get("h_bjet");
  TH1F * h_bjet_dy = (TH1F*) f_dy->Get("h_bjet");
  TH1F * h_bjet_ww = (TH1F*) f_ww->Get("h_bjet");
  TH1F * h_bjet_wz = (TH1F*) f_wz->Get("h_bjet");
  TH1F * h_bjet_zz = (TH1F*) f_zz->Get("h_bjet");
  TH1F * h_bjet_qcd = (TH1F*) f_qcd->Get("h_bjet");
  TH1F * h_bjet_single_top = (TH1F*) f_single_top->Get("h_bjet");
  TH1F * h_bjet_data = (TH1F*) f_data->Get("h_bjet");

  h_bjet_ttbar->SetFillColor(kRed);
  h_bjet_wjets->SetFillColor(kOrange);
  h_bjet_dy->SetFillColor(kBlue);
  h_bjet_ww->SetFillColor(kGreen);
  h_bjet_wz->SetFillColor(kCyan);
  h_bjet_zz->SetFillColor(kYellow);
  h_bjet_qcd->SetFillColor(kMagenta);
  h_bjet_single_top->SetFillColor(kGray);
  h_bjet_data->SetMarkerColor(1);

  h11->Add(h_bjet_ttbar);
  h11->Add(h_bjet_wjets);
  h11->Add(h_bjet_dy);
  h11->Add(h_bjet_ww);
  h11->Add(h_bjet_wz);
  h11->Add(h_bjet_zz);
  h11->Add(h_bjet_qcd);
  h11->Add(h_bjet_single_top);
 
  int binmax_bjet = h_bjet_ttbar->GetMaximumBin();
//  float max_bjet = h_bjet_ttbar->GetXaxis()->GetBinCenter(binmax_bjet);

  cout << "bjet_ttbar has maximum at: " << binmax_bjet << endl;

  float bjet_signal = h_bjet_ttbar->GetBinContent(binmax_bjet);
  TH1 *l12 = ((TH1*)(h11->GetStack()->Last()));
  float bjet_background = l12->GetBinContent(binmax_bjet);

  cout << "signal: " << bjet_signal << endl;
  cout << "background: " << bjet_background << endl;
  
  TCanvas *s11 = new TCanvas("s11","bjet",700,600);
 // h_bjet_data->SetMarkerStyle(20);
//  h_bjet_data->SetLineColor(1);
//  h_bjet_data->SetMarkerSize(0.8);
  s11->DrawFrame(0,100,8,1000000)->SetTitle("bjet");
  h11->GetYaxis()->SetTitle("Events");
  h11->GetXaxis()->SetTitle("Number of Jets"); 
  h11->Draw("histsame");
//  h_bjet_data->Draw("psame");
  TLegend *leg11 = new TLegend(.75,.55,.9,.9,"");
//  leg11->AddEntry(h_bjet_data,"data","p");
  leg11->AddEntry(h_bjet_ttbar,"t#bar{t}","F");
  leg11->AddEntry(h_bjet_wjets,"wjets","F");
  leg11->AddEntry(h_bjet_dy,"Drell-Yan","F");
  leg11->AddEntry(h_bjet_ww,"ww","F");
  leg11->AddEntry(h_bjet_wz,"wz","F");
  leg11->AddEntry(h_bjet_zz,"zz","F");
  leg11->AddEntry(h_bjet_qcd,"qcd","F");
  leg11->AddEntry(h_bjet_single_top,"single_top","F");
  leg11->Draw();
  s11->SetLogy();
  h11->GetYaxis()->SetTitle("Events");
  h11->GetXaxis()->SetTitle("Number of Jets"); 
  s11->Print("out/ex2/STACK_bjet.pdf");

  printf("GlobalMaximum: %f\n", h11->GetMaximum());

}
