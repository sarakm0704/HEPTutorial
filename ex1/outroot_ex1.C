void outroot_ex1(string inputFile){

  TFile fileIn(Form("%s",inputFile.c_str()));
  TTree* theTree = nullptr;
  TTreeReader theReader("events",&fileIn);
  TTreeReaderArray<Float_t> Muon_Px(theReader, "Muon_Px");
  TTreeReaderArray<Float_t> Muon_Py(theReader, "Muon_Py");
  TTreeReaderArray<Float_t> Muon_Pz(theReader, "Muon_Pz");
  TTreeReaderArray<Float_t> Muon_E(theReader, "Muon_E");
  TTreeReaderArray<Float_t> Muon_Iso(theReader, "Muon_Iso");
  TTreeReaderValue<Float_t> EventWeight(theReader, "EventWeight");
  TTreeReaderArray<Int_t> Muon_Charge(theReader, "Muon_Charge");
  TTreeReaderValue<Int_t> NMuon(theReader, "NMuon");
  TTreeReaderValue<Bool_t> Muon_trigger(theReader, "triggerIsoMu24");
  
  TH1F * h_muon1_px = new TH1F("h_muon1_px","h_muon1_px",100,-100,100);
  TH1F * h_muon1_py = new TH1F("h_muon1_py","h_muon1_py",100,-100,100);
  TH1F * h_muon1_pz = new TH1F("h_muon1_pz","h_muon1_pz",100,-100,100);
  TH1F * h_muon1_pt = new TH1F("h_muon1_pt","h_muon1_pt",100,0,100);
  TH1F * h_muon2_px = new TH1F("h_muon2_px","h_muon2_px",100,-100,100);
  TH1F * h_muon2_py = new TH1F("h_muon2_py","h_muon2_py",100,-100,100);
  TH1F * h_muon2_pz = new TH1F("h_muon2_pz","h_muon2_pz",100,-100,100);
  TH1F * h_muon2_pt = new TH1F("h_muon2_pt","h_muon2_pt",100,0,100);
 
  TH1F * h_muon1_iso = new TH1F("h_muon1_iso","h_muon1_iso",100,0,0.5);
  TH1F * h_muon2_iso = new TH1F("h_muon2_iso","h_muon2_iso",100,0,0.5);
  TH1F * h_trigger_iso = new TH1F("h_trigger_iso","h_trigger_iso",100,0,0.5);

  TH1F * h_muon_multi = new TH1F("h_muon_multi","h_muon_multi",10,0,10);
  TH1F * h_invmass = new TH1F("h_invmass","h_invmass",120,60,120);
 
  int nevents = 0;
  while(theReader.Next()){
   
    float w = *EventWeight;
 
    int nmuon = *NMuon;
    h_muon_multi->Fill(nmuon,w);

    if(nmuon <= 1) continue;
//if(nmuon < 1) continue;
    float muon1_px = Muon_Px[0]; 
    float muon1_py = Muon_Py[0]; 
    float muon1_pz = Muon_Pz[0]; 
    float muon1_e = Muon_E[0]; 
    int muon1_charge = Muon_Charge[0];

    float muon2_px = Muon_Px[1]; 
    float muon2_py = Muon_Py[1]; 
    float muon2_pz = Muon_Pz[1]; 
    float muon2_e = Muon_E[1]; 
    int muon2_charge = Muon_Charge[1];
    
    int muon1_iso = Muon_Iso[0];
    int muon2_iso = Muon_Iso[1];
    bool muon_tri = *Muon_trigger;

    h_muon1_iso->Fill(muon1_iso,w);
    h_muon2_iso->Fill(muon2_iso,w);
    if(muon1_iso > 0.1) continue;
    if(muon2_iso > 0.1) continue;
    if(muon1_charge * muon2_charge == 1) continue;
    if(muon_tri == false) continue;
    
    h_muon1_px->Fill(muon1_px,w);
    h_muon1_py->Fill(muon1_py,w);
    h_muon1_pz->Fill(muon1_pz,w);

    h_muon2_px->Fill(muon2_px,w);
    h_muon2_py->Fill(muon2_py,w);
    h_muon2_pz->Fill(muon2_pz,w);

    TLorentzVector P1;
    TLorentzVector P2;
    P1.SetPxPyPzE(muon1_px, muon1_py, muon1_pz, muon1_e);
    P2.SetPxPyPzE(muon2_px, muon2_py, muon2_pz, muon2_e);
    
    float muon1_pt = P1.Pt();
    float muon2_pt = P2.Pt();

    //if(P1.Pt() < 25) continue;
    //if(P2.Pt() < 25) continue;
 
    float dimuon_invmass = (P1 + P2).M();

    h_muon1_pt->Fill(muon1_pt,w);
    h_muon2_pt->Fill(muon2_pt,w); 

    h_invmass->Fill(dimuon_invmass,w);
 

    nevents++;

  }
 
  TFile * f_out = new TFile(Form("out/ex1/hist_%s",inputFile.c_str()),"RECREATE");
  h_muon_multi->Write();
  h_invmass->Write();
  h_muon1_iso->Write();
  h_muon2_iso->Write();
  h_muon1_px->Write();
  h_muon1_py->Write();
  h_muon1_pz->Write();
  h_muon1_pt->Write();
  f_out->Close();  
}
