void outroot_ex2(string inputfile){

  TFile fileIn(Form("files/%s",inputfile.c_str()));
  TTreeReader theReader("events",&fileIn);
  TTreeReaderArray<Float_t> Jet_Px(theReader, "Jet_Px");
  TTreeReaderArray<Float_t> Jet_Py(theReader, "Jet_Py");
  TTreeReaderArray<Float_t> Jet_Pz(theReader, "Jet_Pz");
  TTreeReaderArray<Float_t> Jet_E(theReader, "Jet_E");
  TTreeReaderValue<Int_t> NJet(theReader, "NJet");
  TTreeReaderValue<Float_t> Jet_btag(theReader, "Jet_btag");
  TTreeReaderValue<Bool_t> Jet_ID(theReader, "Jet_ID");
 
  TTreeReaderArray<Float_t> Muon_Px(theReader, "Muon_Px");
  TTreeReaderArray<Float_t> Muon_Py(theReader, "Muon_Py");
  TTreeReaderArray<Float_t> Muon_Pz(theReader, "Muon_Pz");
  TTreeReaderArray<Float_t> Muon_E(theReader, "Muon_E");
  TTreeReaderArray<Float_t> Muon_Iso(theReader, "Muon_Iso"); 
  TTreeReaderValue<Int_t> NMuon(theReader, "NMuon");
 
  TTreeReaderArray<Float_t> Electron_Px(theReader, "Electron_Px");
  TTreeReaderArray<Float_t> Electron_Py(theReader, "Electron_Py");
  TTreeReaderArray<Float_t> Electron_Pz(theReader, "Electron_Pz");
  TTreeReaderArray<Float_t> Electron_E(theReader, "Electron_E"); 
  TTreeReaderArray<Float_t> Electron_Iso(theReader, "Electron_Iso"); 

  TTreeReaderArray<Float_t> MET_px(theReader, "MET_px");
  TTreeReaderArray<Float_t> MET_py(theReader, "MET_py");
  TTreeReaderValue<Float_t> EventWeight(theReader, "EventWeight");

  TH1F * h_jet1_px = new TH1F("h_jet1_px","h_jet1_px",100,-100,100);
  TH1F * h_jet1_py = new TH1F("h_jet1_py","h_jet1_py",100,-100,100);
  TH1F * h_jet1_pz = new TH1F("h_jet1_pz","h_jet1_pz",100,-100,100);
  TH1F * h_jet1_pt = new TH1F("h_jet1_pt","h_jet1_pt",100,0,250);
  TH1F * h_jet2_pt = new TH1F("h_jet2_pt","h_jet2_pt",100,0,250);
  TH1F * h_jet3_pt = new TH1F("h_jet3_pt","h_jet3_pt",100,0,250);
  TH1F * h_jet_multi = new TH1F("h_jet_multi","h_jet_multi",10,0,10);
  TH1F * h_bjet = new TH1F("h_bjet","h_bjet",10,0,10);
  TH1F * h_jet_eta = new TH1F("h_jet_eta","h_jet_eta",100,-4,4);

//  TH1F * test_jet[i]_pt = new TH1F("test","test",100,0,250);
  
  TH1F * h_electron_px = new TH1F("h_electron_px","h_electron_px",100,-100,100);
  TH1F * h_electron_py = new TH1F("h_electron_py","h_electron_py",100,-100,100);
  TH1F * h_electron_pz = new TH1F("h_electron_pz","h_electron_pz",100,-100,100);
  TH1F * h_electron_pt = new TH1F("h_electron_pt","h_electron_pt",200,0,100);
  TH1F * h_electron_iso = new TH1F("h_electron_iso","h_electron_iso",100,0,5); 
  TH1F * h_electron_eta = new TH1F("h_electron_eta","h_electron_eta",100,-4,4);
  
  TH1F * h_muon_px = new TH1F("h_muon_px","h_muon_px",100,-100,100);
  TH1F * h_muon_py = new TH1F("h_muon_py","h_muon_py",100,-100,100);
  TH1F * h_muon_pz = new TH1F("h_muon_pz","h_muon_pz",100,-100,100);
  TH1F * h_muon_pt = new TH1F("h_muon_pt","h_muon_pt",200,0,100); 
  TH1F * h_muon_iso = new TH1F("h_muon_iso","h_muon_iso",100,0,5); 
  TH1F * h_muon_eta = new TH1F("h_muon_eta","h_muon_eta",100,-4,4);

  TH1F * h_met = new TH1F("h_met","h_met",100,0,100);

  TH1F * cutflow = new TH1F("cutflow","cutflow",2,0,2);

  int prenevents = 0;
  int nevents = 0;
  while(theReader.Next()){
  
    float w = *EventWeight;

    float muon_iso = Muon_Iso[0];
   // cout << "muon isolation = " << muon_iso << endl; 
//    h_muon_iso->Fill(muon_iso);

    float electron_iso = Electron_Iso[0];
//    h_electron_iso->Fill(electron_iso);
    
//    if(muon_iso > 0.2) continue;
//    if(electron_iso > 0.2) continue;

    h_muon_iso->Fill(muon_iso);
    h_electron_iso->Fill(electron_iso);
    
    float b_tag = *Jet_btag;
    //if(b_tag > 1) continue;
    h_bjet->Fill(b_tag,w);

    prenevents++;     

    bool id = *Jet_ID;
    if(id == false) continue;  //preselection 

    int nmuon = *NMuon;
    int njet = *NJet;
    //if (njet >= 2) 
    h_jet_multi->Fill(njet,w);

    //if(nmuon >= 1) continue;
    
    float met_px = MET_px[0];
    float met_py = MET_py[0];
  
    float met = sqrt(met_px * met_px + met_py * met_py);
    h_met->Fill(met,w);

//    for(Float_t i = 0; i < 4; i++){
//      TLorentzVector P[i];
//      P[i].SetPxPyPzE(Jet_Px[i],Jet_Py[i],Jet_Pz[i],Jet_E[i];
//      test_jet[i]_pt->Fill(P[i].Pt(),w);

//    }

    float jet1_px = Jet_Px[0];
    float jet1_py = Jet_Py[0];
    float jet1_pz = Jet_Pz[0];
    float jet1_e = Jet_E[0];
    
    float jet2_px = Jet_Px[1];
    float jet2_py = Jet_Py[1];
    float jet2_pz = Jet_Pz[1];
    float jet2_e = Jet_E[1];
    
    float jet3_px = Jet_Px[2];
    float jet3_py = Jet_Py[2];
    float jet3_pz = Jet_Pz[2];
    float jet3_e = Jet_E[2];
   
    h_jet1_px->Fill(jet1_px,w);
    h_jet1_py->Fill(jet1_py,w);
    h_jet1_pz->Fill(jet1_pz,w);
    
    TLorentzVector P1;
    P1.SetPxPyPzE(jet1_px, jet1_py, jet1_pz, jet1_e);
    float jet1_pt = P1.Pt(); 
    h_jet1_pt->Fill(jet1_pt,w);

    TLorentzVector P2;
    P2.SetPxPyPzE(jet2_px, jet2_py, jet2_pz, jet2_e);
    float jet2_pt = P2.Pt(); 
    h_jet2_pt->Fill(jet2_pt,w);
    
    TLorentzVector P3;
    P3.SetPxPyPzE(jet3_px, jet3_py, jet3_pz, jet3_e);
    float jet3_pt = P3.Pt(); 
    h_jet3_pt->Fill(jet3_pt,w);
   
     float jet_eta = P1.PseudoRapidity();
    h_jet_eta->Fill(jet_eta,w);
 
    float muon_px = Muon_Px[0];
    float muon_py = Muon_Py[0];
    float muon_pz = Muon_Pz[0];
    float muon_e = Muon_E[0];
    
    h_muon_px->Fill(muon_px,w);
    h_muon_py->Fill(muon_py,w);
    h_muon_pz->Fill(muon_pz,w);
   
    TLorentzVector P4;
    P4.SetPxPyPzE(muon_px, muon_py, muon_pz, muon_e);
    float muon_pt = P4.Pt();
    h_muon_pt->Fill(muon_pt,w);
    
    float muon_eta = P4.PseudoRapidity();
    h_muon_eta->Fill(muon_eta,w);

    float electron_px = Electron_Px[0];
    float electron_py = Electron_Py[0];
    float electron_pz = Electron_Pz[0];
    float electron_e = Electron_E[0];
    
    h_electron_px->Fill(electron_px,w);
    h_electron_py->Fill(electron_py,w);
    h_electron_pz->Fill(electron_pz,w);
   
    TLorentzVector P5;
    P5.SetPxPyPzE(electron_px, electron_py, electron_pz, electron_e);
    float electron_pt = P5.Pt();
    h_electron_pt->Fill(electron_pt,w);
    
    float electron_eta = P5.PseudoRapidity();
    h_electron_eta->Fill(electron_eta,w);
    
    nevents++; 
  
  }

  cutflow->SetBinContent(1,prenevents);
  cutflow->SetBinContent(2,nevents);
//  cout << " num. of sig. / sqrt(num. of. back.) " << << endl;

  TFile * f_out = new TFile(Form("out/ex2/hist_%s",inputfile.c_str()),"RECREATE");
  h_muon_iso->Write();
  h_electron_iso->Write();
  h_jet_multi->Write();
  h_jet1_px->Write();
  h_jet1_py->Write();
  h_jet1_pz->Write();
  h_jet1_pt->Write();
  h_jet2_pt->Write();
  h_jet3_pt->Write();
//  test_jet[i]_pt->Write();
  h_jet_eta->Write();
  h_muon_px->Write();
  h_muon_py->Write();
  h_muon_pz->Write();
  h_muon_pt->Write();
  h_muon_eta->Write();
  h_electron_px->Write();
  h_electron_py->Write();
  h_electron_pz->Write();
  h_electron_pt->Write();
  h_electron_eta->Write();
  h_met->Write();
  h_bjet->Write();
  f_out->Close();
}

