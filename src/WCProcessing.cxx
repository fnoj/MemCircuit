///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2014                              //
//        John Suárez¹  -  Miguel Castillo²  -  Julian Salamanca³        //
//      ¹²³Grupo de Física e Informática (FISINFOR) Universidad          //
//                  Distrital Francisco José de Caldas                   //
//                                                                       //
//                                                                       //
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
//               http://www.gnu.org/copyleft/gpl.html                    //
//                                                                       //
///////////////////////////////////////////////////////////////////////////
/*
WCProcessing.cxx
Window with message "Processing..."
 */

#include "WCProcessing.h"
//#include "WMainApp.h"

WCProcessing::WCProcessing(const TGWindow *p,const TGWindow *main){
  
  fWCProcessing = new TGTransientFrame(p,main);
  fWCProcessing->SetWMSizeHints(120,40,120,40,0,0);
  fWCProcessing->SetCleanup(kDeepCleanup);

  GF = new TGHorizontalFrame(fWCProcessing,0); 
  TLProcessing = new TGLabel(GF,"Processing ..."); 
  //TBStop =new TGTextButton(fWCProcessing,"Stop");
  //TBStop->Connect("Clicked()","WMainApp",this,"Stop()");

  GF->AddFrame(TLProcessing, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY,1,1,1,1)); 
  //GF->AddFrame(TBStop, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY,1,1,1,1)); 

  fWCProcessing->AddFrame(GF,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCProcessing->MapSubwindows();
  fWCProcessing->MapWindow();
  TBCpu = new TBenchmark();
  TBCpu->Start("mc");
}

void WCProcessing::Close(){
  TBCpu->Show("mc");
  fWCProcessing->CloseWindow();
}

WCProcessing::~WCProcessing(){
  delete fWCProcessing;
}
