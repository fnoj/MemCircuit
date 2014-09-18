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
WCResistor.cxx
Graphical Interface for creation of object Resistor
 */

#include "WCResistor.h"

WCResistor::WCResistor(const TGWindow *p,const TGWindow *main){

  fWCResistor = new TGTransientFrame(p,main);
  fWCResistor->SetWMSizeHints(120,70,120,70,0,0);
  fWCResistor->SetWindowName("Add Resistor");
  fWCResistor->SetCleanup(kDeepCleanup);
  fWCResistor->SetIconPixmap("../icons/resistor.png");    

  GF4 = new TGVerticalFrame(fWCResistor,0);   

  GChR = new TGHorizontalFrame(GF4,0);  
  lkR = new TGLabel(GChR,"R[Ohm]"); 
  NEkR = new TGNumberEntry(GChR,0.5);  
  NEkR->SetState(true); 
  NEkR->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChR->AddFrame(lkR, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChR->AddFrame(NEkR, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 

  GButton = new TGHorizontalFrame(GF4,0);  

  TBAdd = new TGTextButton(GButton,"&Add",1);
  TBAdd->Connect("Clicked()","WCResistor",this,"TBAddClicked()");
  
  GButton->AddFrame(TBAdd, new TGLayoutHints(kLHintsCenterX,2,2,2,2));

  GF4->AddFrame(GChR, new TGLayoutHints(kLHintsLeft,1,1,1,1));
  GF4->AddFrame(GButton,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  fWCResistor->AddFrame(GF4,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCResistor->MapSubwindows();
  fWCResistor->MapWindow();

  gClient->WaitFor(fWCResistor);
}

void WCResistor::TBAddClicked(){
  fkR= (double)NEkR->GetNumber();
  fWCResistor->CloseWindow();
}

WCResistor::~WCResistor(){
  delete fWCResistor;
}
