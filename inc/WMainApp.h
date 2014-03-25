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
WMainApp.h
Main Graphical Interface of aplication MemCircuit
 */

#include "VSave.h"
#include "TCirDevice.h"
#include "TVoltage.h"
#include "TWire.h"

#include <RQ_OBJECT.h>
#include <TGFrame.h>
#include <TBrowser.h>
#include <TGFileDialog.h>
#include <TGNumberEntry.h>
#include <TRootEmbeddedCanvas.h>
#include <TCanvas.h>
#include <TString.h>
#include <TFile.h>
#include <TGTextEntry.h>
#include <TGIcon.h>
#include <TGClient.h>
#include <TApplication.h>
#include <TBenchmark.h>
#include <TPaveText.h>
#include <fstream>
#include <stdlib.h>
#include <TTimer.h>

#include "WCMemristor.h"
#include "WCMemcapacitor.h"
#include "WCMeminductor.h"
#include "WCResistor.h"
#include "WCCapacitor.h"
#include "WCInductor.h"
#include "WCProcessing.h"
#include "WCGraphs.h"

using namespace std;

#ifndef MEMCIRCUIT_WMainApp
#define MEMCIRCUIT_WMainApp

class WMainApp{
  
  RQ_OBJECT("WMainApp");

 public:  
  WMainApp(const TGWindow *p,UInt_t w,UInt_t h);
  //  void CiRBPlaceClicked();
  void CiDraw();
  void CiClear();
  void Run();
  void SignalTypeSelect();
  void CreateScript();
  void CiOpen();
  void SaveClicked();
  TTimer *Count; 

 private:
  
  TGMainFrame *TMF1;
  TGHorizontalFrame *HF, *VFMain;
  TGVerticalFrame *VFO, *VFPar;
  TGHorizontalFrame *GChVc, *GChfc, *GChVd, *GChfd;                        // Childs TGGroupFrame Voltage, Frequence
  TGHorizontalFrame *GChiC, *GCht0, *GChtf, *GChnd, *GChl;                 // Childs TGGroupFrame ICurrent, t0, tf, number_repeats, Steps
  TGHorizontalFrame *GChSave;                                              // Childs TGGroupFrame Option Save   

  TGGroupFrame *GF1, *GF2, *GF3;                                                 // Main TGGroupFrame 
  
  TGNumberEntry *NEV0, *NEf0;                                              //Initial Voltage, Initial Frquence
  TGNumberEntry *NEVf, *NEff;                                              //Final Voltage, Final Frquence
  TGNumberEntry *NESF, *NESV;                                              //Steps Frequence, Steps Voltage
  TGNumberEntry *NEiC, *NEt0, *NEtf;                                       //Initial Charge, Initial Time, Final Time
  TGNumberEntry  *NEnd;                                                    //Number_Points 

  TGHorizontalFrame *GFDraw, *GChVf, *GChff, *CiGChSignal;

  TGVButtonGroup *VBGMem;
  TGCheckButton *CBSave;
  TGTextEntry *TESave;
  
  TGLabel *ldl, *ldV, *lVc, *lfc, *liC, *lt0, *ltf, *ll, *lnd, *la, *lb, *lc, *lVf, *lff, *ldf;
  
  TGFileDialog *fiInfo;

  TBrowser *TB1; 
  Int_t MemFunction;
  Int_t kIDSignal; //Id Pulse Select
  VSave *save;

  //=====================================================\begin{PAD CIRCUIT}
  TGLayoutHints *Cil1, *Cil2;

  TRootEmbeddedCanvas *EC2;
  TCanvas *CCircuit;
  TGHorizontalFrame  *GChSignal, *CiHFDevClas, *CiHFDevMod;// *CiHFOrient; 
  
  //  TGRadioButton *CiRB1,*CiRB2;
  
  TGVerticalFrame  *CiVFO1, *CiVFO2, *CiVFDevices;
  
  TGTextButton  *CiTGBClear, *CiTGBExit, *CiTGBRun;
  TGTextButton  *CiTGBOpen;
  TGGroupFrame  *CiGF1, *CiGF2;             
  TGRadioButton *CiRBSignal[3];

  TGIcon *CiISignal_DS, *CiISignal_S, *CiISignal_Sin; 

  TGPictureButton *CiPBR, * CiPBL, *CiPBC, *CiPBMR, *CiPBML, *CiPBMC;

  TVoltage *voltage;
  TCirDevice *dev[40][20];
  TWire *wire[40];
 
  Int_t kDevice;
  Int_t kWire;
  Int_t kParel;
  Int_t kIDDev;
  Int_t kColor;
  Int_t kMesh;
  Int_t kDevMesh[20];
  Bool_t kUDPa;  //UltimateDevice is Parallel
  Int_t kR;
  Int_t kC;
  Int_t kL;
  Int_t kRm;
  Int_t kCm;
  Int_t kLm;

  TPaveText *TPTMesh;

  void CiResize(Int_t);
  void DrawWMainApp();
  Int_t GetSignal();
  void SaveVariables();

  //========================================================\end{ PAD CIRCUIT}

  //========================================================\begin{Run}
  Double_t f,V;
  //========================================================\end{Run}

  WCProcessing *WCPro;
  WCGraphs *Graphs;

  ofstream script;
  ofstream variables;
  ~WMainApp();  

  ClassDef(WMainApp,0);
};
#endif
