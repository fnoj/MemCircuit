///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2014                              //
//        John Suárez¹  -  Miguel Castillo²  -  Julian Salamanca³        //
//                                                                       //
//                jfsuarezp@correo.udistrital.edu.co¹                    //
//                    mfcastillo@fis.cinvestav.mx²                       //
//               jasalamanca@correo.udistrital.edu.co³                   //
//                                                                       //
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
WCCapacitor.cxx
Graphical Interface for creation of object Capacitor
 */

#include "WCCapacitor.h"

WCCapacitor::WCCapacitor(const TGWindow *p,const TGWindow *main){

  fWCCapacitor = new TGTransientFrame(p,main);
  fWCCapacitor->SetWMSizeHints(120,70,120,70,0,0);
  fWCCapacitor->SetWindowName("Add Capacitor");
  fWCCapacitor->SetCleanup(kDeepCleanup);
  fWCCapacitor->SetIconPixmap("../icons/capacitor.png");    

  GF4 = new TGVerticalFrame(fWCCapacitor,0);   

  GChC = new TGHorizontalFrame(GF4,0);  
  lkC = new TGLabel(GChC,"C[mF]"); 
  NEkC = new TGNumberEntry(GChC,0.5);  
  NEkC->SetState(true); 
  NEkC->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChC->AddFrame(lkC, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChC->AddFrame(NEkC, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 

  GButton = new TGHorizontalFrame(GF4,0);  

  TBAdd = new TGTextButton(GButton,"&Add",1);
  TBAdd->Connect("Clicked()","WCCapacitor",this,"TBAddClicked()");
  
  GButton->AddFrame(TBAdd, new TGLayoutHints(kLHintsCenterX,2,2,2,2));

  GF4->AddFrame(GChC, new TGLayoutHints(kLHintsLeft,1,1,1,1));
  GF4->AddFrame(GButton,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  fWCCapacitor->AddFrame(GF4,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCCapacitor->MapSubwindows();
  fWCCapacitor->MapWindow();

  gClient->WaitFor(fWCCapacitor);
}

void WCCapacitor::TBAddClicked(){
  fkC= (double)NEkC->GetNumber()/1000;
  fWCCapacitor->CloseWindow();
}

WCCapacitor::~WCCapacitor(){
  delete fWCCapacitor; 
}
