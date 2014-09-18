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
WCGraphs.h
Graphical Interface for creation Windows with results of analysis
 */

#ifndef MEMCIRCUIT_WCGraphs
#define MEMCIRCUIT_WCGraphs

#include <TGFrame.h>
#include <TFile.h>
#include <TGWindow.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TMultiGraph.h>
#include <TGTab.h>
#include <TGButton.h>
#include <TRootEmbeddedCanvas.h>
#include <RQ_OBJECT.h>
#include <fstream>

using namespace std;

class WCGraphs{
   
  RQ_OBJECT("WCGraphs");

 private:
  TGTransientFrame *fWCGraphs;
  TGTab *Tab;
  TGVerticalFrame *GF;

  TCanvas *CGraph[16];
  TRootEmbeddedCanvas *ECGraph[16];

  TLegend *lg;
  TGTextButton *TBClose;
  Int_t fNPoints;
  Double_t ff,fV;
  Double_t x0[2001], x1[2001], x2[2001], x3[2001], x4[2001], x5[2001], x6[2001], x7[2001], x8[2001], x9[2001];
  
 public:
  WCGraphs(const TGWindow *p,const TGWindow *main, Bool_t fWrite, TString SFile);
  void SetN(Int_t NPoints){fNPoints=NPoints;}
  void Setf(Double_t f){ff=f;}
  void SetV(Double_t V){fV=V;}
  void Draw(Int_t Color);
  void Close();
  void SetHidden(Bool_t Opt);
  TMultiGraph *mg[16];
  TGraph *gr[16];
  Char_t LabelGraph[20];
  TFile *File;

  Bool_t bWrite;
  TString StFile;

  const char *Sp;
  const char *Svt;
  const char *Sft;
  const char *Sqt;
  const char *Sit;

  const char *Siv; 
  const char *Svi; 
  
  const char *Sfv;
  const char *Svf;
  
  const char *Sqv;
  const char *Svq;
  
  const char *Sfi;
  const char *Sif;
  
  const char *Siq;
  const char *Sqi;

  const char *Sfq;
  const char *Sqf;
  
  const char *Si;
  const char *St;
  const char *Sq;
  const char *Sf;
  const char *Sv;


  ~WCGraphs();

  ClassDef(WCGraphs,0);

};
#endif
