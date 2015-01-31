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
WCInductor.cxx
Graphical Interface for creation of object Inductor
 */

#include "WCInductor.h"

WCInductor::WCInductor(const TGWindow *p,const TGWindow *main){

  fWCInductor = new TGTransientFrame(p,main);
  fWCInductor->SetWMSizeHints(120,70,120,70,0,0);
  fWCInductor->SetWindowName("Add Inductor");
  fWCInductor->SetCleanup(kDeepCleanup);
  fWCInductor->SetIconPixmap("../icons/inductor.png");    

  GF4 = new TGVerticalFrame(fWCInductor,0);   

  GChL = new TGHorizontalFrame(GF4,0);  
  lkL = new TGLabel(GChL,"L[H]"); 
  NEkL = new TGNumberEntry(GChL,0.5);  
  NEkL->SetState(true); 
  NEkL->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChL->AddFrame(lkL, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChL->AddFrame(NEkL, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 

  GButton = new TGHorizontalFrame(GF4,0);  

  TBAdd = new TGTextButton(GButton,"&Add",1);
  TBAdd->Connect("Clicked()","WCInductor",this,"TBAddClicked()");
  
  GButton->AddFrame(TBAdd, new TGLayoutHints(kLHintsCenterX,2,2,2,2));

  GF4->AddFrame(GChL, new TGLayoutHints(kLHintsLeft,1,1,1,1));
  GF4->AddFrame(GButton,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  fWCInductor->AddFrame(GF4,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCInductor->MapSubwindows();
  fWCInductor->MapWindow();

  kId=1000;

  gClient->WaitFor(fWCInductor);
}

void WCInductor::TBAddClicked(){
  fkL= (double)NEkL->GetNumber();
  fWCInductor->CloseWindow();
}

WCInductor::~WCInductor(){
  delete fWCInductor;
}
