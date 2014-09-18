///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2014                              //
//        John Suárez  -  Miguel Castillo  -  Julian Salamanca           //
//                https://github.com/fnoj/MemCircuit                     //
//                                                                       //
// This program is free software; you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation; either version 2 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details:                          //
//                                                                       //
//          http://www.gnu.org/copyleft/gpl.html                         //
//                                                                       //
///////////////////////////////////////////////////////////////////////////
/*
WCGraphs.cxx
Graphical Interface for creation Windows with results of analysis
 */

#include "WCGraphs.h"

WCGraphs::WCGraphs(const TGWindow *p,const TGWindow *main, Bool_t fWrite, TString SFile){  

  bWrite = fWrite;
  StFile = SFile;

  Sit = "Electric Current vs.Time";
  Svt = "Potencial Difference vs. Time";
  Sqt = "Electric Charge vs. Time";
  Sft = "Flux vs. Time";

  Siv = "Electric Current vs. Potencial Difference"; 
  Svi = "Potencial Difference vs. Electric Current"; 
  
  Sfv = "Flux vs. Potencial Difference";
  Svf = "Potencial Difference vs. Flux";
  
  Sqv = "Electric Charge vs. Potencial Difference";
  Svq = "Potencial Difference vs. Electric Charge";
  
  Sfi = "Flux vs. Electric Current";
  Sif = "Electric Current vs. Flux";
  
  Siq = "Electric Current vs. Electric Charge";
  Sqi = "Electric Charge vs. Electric Current";

  Sfq = "Flux vs. Electric Charge";
  Sqf = "Electric Charge vs. Flux";
  
  Si = "Electric Current [A]";
  St = "Time [s]";
  Sq = "Electric Charge [C]";
  Sf = "Flux [Wb]";
  Sv = "Potencial Difference [V]";
  
  
  fWCGraphs = new TGTransientFrame(p,main);
  fWCGraphs->SetWMSizeHints(1100,650,1100,650,40,40);
  fWCGraphs->SetCleanup(kDeepCleanup);

  GF = new TGVerticalFrame(fWCGraphs,0);

  TGTab *Tabs = new TGTab(GF);
  TGCompositeFrame *Tab_v_t = Tabs->AddTab("v vs. t");
  TGCompositeFrame *Tab_f_t = Tabs->AddTab("f vs. t");
  TGCompositeFrame *Tab_q_t = Tabs->AddTab("q vs. t");
  TGCompositeFrame *Tab_i_t = Tabs->AddTab("i vs. t");
  TGCompositeFrame *Tab_v_i = Tabs->AddTab("v vs. i");
  TGCompositeFrame *Tab_i_v = Tabs->AddTab("i vs. v");
  TGCompositeFrame *Tab_v_f = Tabs->AddTab("v vs. f");
  TGCompositeFrame *Tab_f_v = Tabs->AddTab("f vs. v");
  TGCompositeFrame *Tab_v_q = Tabs->AddTab("v vs. q");
  TGCompositeFrame *Tab_q_v = Tabs->AddTab("q vs. v");
  TGCompositeFrame *Tab_i_f = Tabs->AddTab("i vs. f");
  TGCompositeFrame *Tab_f_i = Tabs->AddTab("f vs. i");
  TGCompositeFrame *Tab_i_q = Tabs->AddTab("i vs. q");
  TGCompositeFrame *Tab_q_i = Tabs->AddTab("q vs. i");
  TGCompositeFrame *Tab_f_q = Tabs->AddTab("f vs. q");
  TGCompositeFrame *Tab_q_f = Tabs->AddTab("q vs. f");

  ECGraph[0] = new TRootEmbeddedCanvas("v vs. t",Tab_v_t,1050,530);
  ECGraph[1] = new TRootEmbeddedCanvas("f vs. t",Tab_f_t,1050,530);
  ECGraph[2] = new TRootEmbeddedCanvas("q vs. t",Tab_q_t,1050,530);
  ECGraph[3] = new TRootEmbeddedCanvas("i vs. t",Tab_i_t,1050,530);
  ECGraph[4] = new TRootEmbeddedCanvas("v vs. i",Tab_v_i,1050,530);
  ECGraph[5] = new TRootEmbeddedCanvas("i vs. v",Tab_i_v,1050,530);
  ECGraph[6] = new TRootEmbeddedCanvas("v vs. f",Tab_v_f,1050,530);
  ECGraph[7] = new TRootEmbeddedCanvas("f vs. v",Tab_f_v,1050,530);
  ECGraph[8] = new TRootEmbeddedCanvas("v vs. q",Tab_v_q,1050,530);
  ECGraph[9] = new TRootEmbeddedCanvas("q vs. v",Tab_q_v,1050,530);
  ECGraph[10] = new TRootEmbeddedCanvas("i vs. f",Tab_i_f,1050,530);
  ECGraph[11] = new TRootEmbeddedCanvas("f vs. i",Tab_f_i,1050,530);
  ECGraph[12] = new TRootEmbeddedCanvas("i vs. q",Tab_i_q,1050,530);
  ECGraph[13] = new TRootEmbeddedCanvas("q vs. i",Tab_q_i,1050,530);
  ECGraph[14] = new TRootEmbeddedCanvas("f vs. q",Tab_f_q,1050,530);
  ECGraph[15] = new TRootEmbeddedCanvas("q vs. f",Tab_q_f,1050,530);

  CGraph[0] = ECGraph[0]->GetCanvas();
  CGraph[1] = ECGraph[1]->GetCanvas();
  CGraph[2] = ECGraph[2]->GetCanvas();
  CGraph[3] = ECGraph[3]->GetCanvas();
  CGraph[4] = ECGraph[4]->GetCanvas();
  CGraph[5] = ECGraph[5]->GetCanvas();
  CGraph[6] = ECGraph[6]->GetCanvas();
  CGraph[7] = ECGraph[7]->GetCanvas();
  CGraph[8] = ECGraph[8]->GetCanvas();
  CGraph[9] = ECGraph[9]->GetCanvas();
  CGraph[10] = ECGraph[10]->GetCanvas();
  CGraph[11] = ECGraph[11]->GetCanvas();
  CGraph[12] = ECGraph[12]->GetCanvas();
  CGraph[13] = ECGraph[13]->GetCanvas();
  CGraph[14] = ECGraph[14]->GetCanvas();
  CGraph[15] = ECGraph[15]->GetCanvas();

  Tab_v_t->AddFrame(ECGraph[0], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_f_t->AddFrame(ECGraph[1], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_q_t->AddFrame(ECGraph[2], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_i_t->AddFrame(ECGraph[3], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_v_i->AddFrame(ECGraph[4], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_i_v->AddFrame(ECGraph[5], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_v_f->AddFrame(ECGraph[6], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_f_v->AddFrame(ECGraph[7], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_v_q->AddFrame(ECGraph[8], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_q_v->AddFrame(ECGraph[9], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_i_f->AddFrame(ECGraph[10], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_f_i->AddFrame(ECGraph[11], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_i_q->AddFrame(ECGraph[12], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_q_i->AddFrame(ECGraph[13], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_f_q->AddFrame(ECGraph[14], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  Tab_q_f->AddFrame(ECGraph[15], new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));


  TBClose = new TGTextButton(GF,"&Close");
  TBClose->Connect("Clicked()","WCGraphs",this,"Close()");

  GF->AddFrame(Tabs, new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,10));
  GF->AddFrame(TBClose, new TGLayoutHints(kLHintsCenterX,10,10,10,10));

  for (Int_t i=0; i<=15;i++){
    mg[i] = new TMultiGraph();
  }

  lg=new TLegend(0.8,0.8,1,1);

  //   TLegend* leg = new TLegend(0.2, 0.2, .8, .8);

  fWCGraphs->AddFrame(GF,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCGraphs->MapSubwindows();
}

void WCGraphs::Draw(Int_t Color){
  ifstream infile;
  sprintf(LabelGraph,"f:%4.2f[Hz] V:%4.2f[V]",ff,fV); 
  infile.open("dtest.dat");
  
  Int_t j=0;
  while(!infile.eof()){
    j++;
    infile >> x0[j];
    infile >> x1[j];
    infile >> x2[j];
    infile >> x3[j];
    infile >> x4[j];
    infile >> x5[j];
    infile >> x6[j];
    infile >> x7[j];
    infile >> x8[j];
  }

  gStyle->SetLabelFont(12,"xy");
  gStyle->SetLabelSize(0.06,"xy");
  gStyle->SetGridStyle(2);
  gStyle->SetGridWidth(1);
  gStyle->SetTitleFontSize(0.07);
  gStyle->SetTitleXSize(0.05);
  gStyle->SetTitleYSize(0.05);

  CGraph[0]->cd();
  CGraph[0]->SetGrid(); 
  gr[0]= new TGraph(fNPoints,x0,x2);
  gr[0]->SetLineColor(Color);
  mg[0]->SetTitle(Svt);  
  mg[0]->Add(gr[0]);
  mg[0]->Draw("ALC");
  mg[0]->GetYaxis()->SetTitle(Sv);
  mg[0]->GetXaxis()->SetTitle(St);
  lg->AddEntry(gr[0],LabelGraph, "l");
  lg->Draw();
  CGraph[0]->Update();

  CGraph[1]->cd();   
  CGraph[1]->SetGrid();   
  gr[1]=new TGraph(fNPoints,x0,x4);  
  gr[1]->SetLineColor(Color);   
  mg[1]->SetTitle(Sft);  
  mg[1]->Add(gr[1]);
  mg[1]->Draw("ALC");
  mg[1]->GetYaxis()->SetTitle(Sf);
  mg[1]->GetXaxis()->SetTitle(St);         
  lg->Draw();
  CGraph[1]->Update();

  CGraph[2]->cd();  
  CGraph[2]->SetGrid();   
  gr[2]= new TGraph(fNPoints,x0,x6); 
  gr[2]->SetLineColor(Color);  
  mg[2]->SetTitle(Sqt);   
  mg[2]->Add(gr[2]);
  mg[2]->Draw("ALC");
  mg[2]->GetYaxis()->SetTitle(Sq);
  mg[2]->GetXaxis()->SetTitle(St);
  lg->Draw();
  CGraph[2]->Update();
  
  CGraph[3]->cd();  
  CGraph[3]->SetGrid();   
  gr[3]= new TGraph(fNPoints,x0,x8);   
  gr[3]->SetLineColor(Color);  
  mg[3]->SetTitle(Sit);   
  mg[3]->Add(gr[3]);
  mg[3]->Draw("ACL");
  mg[3]->GetYaxis()->SetTitle(Si);     
  mg[3]->GetXaxis()->SetTitle(St);         
  lg->Draw();
  CGraph[3]->Update();

  CGraph[4]->cd();  
  CGraph[4]->SetGrid();   
  gr[4]= new TGraph(fNPoints,x8,x2);   
  gr[4]->SetLineColor(Color);  
  mg[4]->SetTitle(Svi);   
  mg[4]->Add(gr[4]);
  mg[4]->Draw("ACL");
  mg[4]->GetYaxis()->SetTitle(Sv);     
  mg[4]->GetXaxis()->SetTitle(Si);       
  lg->Draw();
  CGraph[4]->Update();

  CGraph[5]->cd();  
  CGraph[5]->SetGrid();   
  gr[5]= new TGraph(fNPoints,x2,x8);   
  gr[5]->SetLineColor(Color);  
  mg[5]->SetTitle(Siv);   
  mg[5]->Add(gr[5]);
  mg[5]->Draw("ACL");
  mg[5]->GetYaxis()->SetTitle(Si);     
  mg[5]->GetXaxis()->SetTitle(Sv);         
  lg->Draw();
  CGraph[5]->Update();

  CGraph[6]->cd();  
  CGraph[6]->SetGrid();   
  gr[6]= new TGraph(fNPoints,x4,x2);   
  gr[6]->SetLineColor(Color); 
  mg[6]->SetTitle(Svf);   
  mg[6]->Add(gr[6]);
  mg[6]->Draw("ACL");
  mg[6]->GetYaxis()->SetTitle(Sv);     
  mg[6]->GetXaxis()->SetTitle(Sf);         
  lg->Draw();
  CGraph[6]->Update();

  CGraph[7]->cd(); 
  CGraph[7]->SetGrid();   
  gr[7]= new TGraph(fNPoints,x2,x4);   
  gr[7]->SetLineColor(Color); 
  mg[7]->SetTitle(Sfv);   
  mg[7]->Add(gr[7]);
  mg[7]->Draw("ACL");
  mg[7]->GetYaxis()->SetTitle(Sf);     
  mg[7]->GetXaxis()->SetTitle(Sv);         
  lg->Draw();
  CGraph[7]->Update();

  CGraph[8]->cd();  
  CGraph[8]->SetGrid();   
  gr[8]= new TGraph(fNPoints,x6,x2);   
  gr[8]->SetLineColor(Color);  
  mg[8]->SetTitle(Svq);   
  mg[8]->Add(gr[8]);
  mg[8]->Draw("ACL");
  mg[8]->GetYaxis()->SetTitle(Sv);     
  mg[8]->GetXaxis()->SetTitle(Sq);         
  lg->Draw();
  CGraph[8]->Update();

  CGraph[9]->cd();  
  CGraph[9]->SetGrid();   
  gr[9]= new TGraph(fNPoints,x2,x6);    
  gr[9]->SetLineColor(Color);  
  mg[9]->SetTitle(Sqv);  
  mg[9]->Add(gr[9]);
  mg[9]->Draw("ACL");
  mg[9]->GetYaxis()->SetTitle(Sq);     
  mg[9]->GetXaxis()->SetTitle(Sv);         
  lg->Draw();
  CGraph[9]->Update();

  CGraph[10]->cd();  
  CGraph[10]->SetGrid();   
  gr[10]= new TGraph(fNPoints,x4,x8);  
  gr[10]->SetLineColor(Color); 
  mg[10]->SetTitle(Sif);   
  mg[10]->Add(gr[10]);
  mg[10]->Draw("ACL");
  mg[10]->GetYaxis()->SetTitle(Si);     
  mg[10]->GetXaxis()->SetTitle(Sf);         
  lg->Draw();
  CGraph[10]->Update();

  CGraph[11]->cd();  
  CGraph[11]->SetGrid();   
  gr[11]= new TGraph(fNPoints,x8,x4);   
  gr[11]->SetLineColor(Color);  
  mg[11]->SetTitle(Sfi);   
  mg[11]->Add(gr[11]);
  mg[11]->Draw("ACL");
  mg[11]->GetYaxis()->SetTitle(Sf);     
  mg[11]->GetXaxis()->SetTitle(Si);         
  lg->Draw();
  CGraph[11]->Update();

  CGraph[12]->cd();  
  CGraph[12]->SetGrid();   
  gr[12]= new TGraph(fNPoints,x6,x8);   
  gr[12]->SetLineColor(Color);  
  mg[12]->SetTitle(Siq);   
  mg[12]->Add(gr[12]);
  mg[12]->Draw("ACL");
  mg[12]->GetYaxis()->SetTitle(Si);    
  mg[12]->GetXaxis()->SetTitle(Sq);         
  lg->Draw();
  CGraph[12]->Update();

  CGraph[13]->cd();  
  CGraph[13]->SetGrid();   
  gr[13]= new TGraph(fNPoints,x8,x6);   
  gr[13]->SetLineColor(Color);  
  mg[13]->SetTitle(Sqi);   
  mg[13]->Add(gr[13]);
  mg[13]->Draw("ACL");
  mg[13]->GetYaxis()->SetTitle(Sq);     
  mg[13]->GetXaxis()->SetTitle(Si);         
  lg->Draw();
  CGraph[13]->Update();

  CGraph[14]->cd();  
  CGraph[14]->SetGrid();   
  gr[14]= new TGraph(fNPoints,x6,x4);   
  gr[14]->SetLineColor(Color);  
  mg[14]->SetTitle(Sfq);   
  mg[14]->Add(gr[14]);
  mg[14]->Draw("ACL");
  mg[14]->GetYaxis()->SetTitle(Sf);     
  mg[14]->GetXaxis()->SetTitle(Sq);     
  lg->Draw();
  CGraph[14]->Update();
  
  CGraph[15]->cd();  
  CGraph[15]->SetGrid();   
  gr[15]= new TGraph(fNPoints,x4,x6);   
  gr[15]->SetLineColor(Color);  
  mg[15]->SetTitle(Sqf);  
  mg[15]->Add(gr[15]);
  mg[15]->Draw("ACL");
  mg[15]->GetYaxis()->SetTitle(Sq);     
  mg[15]->GetXaxis()->SetTitle(Sf);         
  lg->Draw();
  CGraph[15]->Update();


  if(bWrite==true){
    File = new TFile(StFile,"RECREATE");
    CGraph[0]->Write(Svt);
    CGraph[1]->Write(Sft);
    CGraph[2]->Write(Sqt);
    CGraph[3]->Write(Sit);
    CGraph[4]->Write(Svi);
    CGraph[5]->Write(Siv);
    CGraph[6]->Write(Svf);
    CGraph[7]->Write(Sfv);
    CGraph[8]->Write(Svq);
    CGraph[9]->Write(Sqv);
    CGraph[10]->Write(Sif);
    CGraph[11]->Write(Sfi);
    CGraph[12]->Write(Siq);
    CGraph[13]->Write(Sqi);
    CGraph[14]->Write(Sfq);
    CGraph[15]->Write(Sqf);
  }

}

void WCGraphs::SetHidden(Bool_t Opt){
  if(Opt){ fWCGraphs->UnmapWindow(); }
  else { fWCGraphs->MapWindow(); }
}

void WCGraphs::Close(){
  fWCGraphs->CloseWindow();
}

WCGraphs::~WCGraphs(){
  delete fWCGraphs;
}
