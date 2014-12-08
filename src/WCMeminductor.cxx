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
WCMeminductor.cxx
Graphical Interface for creation of object Meminductor
 */

#include "WCMeminductor.h"

WCMeminductor::WCMeminductor(const TGWindow *p,const TGWindow *main){

  fWCMeminductor = new TGTransientFrame(p,main);
  fWCMeminductor->SetWMSizeHints(300,180,300,180,0,0);
  fWCMeminductor->SetWindowName("Add Meminductor");
  fWCMeminductor->SetCleanup(kDeepCleanup);
  fWCMeminductor->SetIconPixmap("../icons/memristor.png");    

  GF4 = new TGVerticalFrame(fWCMeminductor,0); 

  VBGMem = new TGVButtonGroup(GF4, "Meminductor Group"); 
  RBMeminductor[0] = new TGRadioButton(VBGMem,"a*exp(b*q)",0);  
  RBMeminductor[0]->Connect("Clicked()","WCMeminductor",this,"RBMemClicked()");   
  RBMeminductor[1] = new TGRadioButton(VBGMem,"a + b*q^2",1);  
  RBMeminductor[1]->Connect("Clicked()","WCMeminductor",this,"RBMemClicked()");   
  RBMeminductor[2] = new TGRadioButton(VBGMem,"a + b*q",2);  
  RBMeminductor[2]->Connect("Clicked()","WCMeminductor",this,"RBMemClicked()");   
  RBMeminductor[3] = new TGRadioButton(VBGMem,"a + b*q^2 + c*q^4 ...",3);  
  RBMeminductor[3]->Connect("Clicked()","WCMeminductor",this,"RBMemClicked()");   
  RBMeminductor[4] = new TGRadioButton(VBGMem,"a",4);  
  RBMeminductor[4]->Connect("Clicked()","WCMeminductor",this,"RBMemClicked()");   
  
  GChCoe = new TGHorizontalFrame(VBGMem,0);  
  
  GCha = new TGHorizontalFrame(GChCoe,0);  
  la = new TGLabel(GCha,"a"); 
  NEa = new TGNumberEntry(GCha,0.5);  
  NEa->SetState(true); 
  NEa->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GCha->AddFrame(la, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GCha->AddFrame(NEa, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  
  GChb = new TGHorizontalFrame(GChCoe,0);  
  lb = new TGLabel(GChb,"b"); 
  NEb = new TGNumberEntry(GChb,0.5);  
  NEb->SetState(true); 
  NEb->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChb->AddFrame(lb, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChb->AddFrame(NEb, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  
  GChc = new TGHorizontalFrame(GChCoe,0);  
  lc = new TGLabel(GChc,"c"); 
  NEc = new TGNumberEntry(GChc,0.5);  
  NEc->SetState(false); 
  NEc->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChc->AddFrame(lc, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChc->AddFrame(NEc, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  
  GChCoe->AddFrame(GCha, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  GChCoe->AddFrame(GChb, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  GChCoe->AddFrame(GChc, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  
  VBGMem->AddFrame(GChCoe, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  VBGMem->Show(); 
  VBGMem->SetExclusive(true); 
  VBGMem->SetBorderDrawn(false); 

  GButton = new TGHorizontalFrame(GF4,0);  

  TBAdd = new TGTextButton(GButton,"&Add",1);
  TBAdd->Connect("Clicked()","WCMeminductor",this,"TBAddClicked()");

  //  TBCancel = new TGTextButton(GButton,"&Cancel",2);
  //  TBCancel->Connect("Clicked()","WCMeminductor",this,"TBCancelClicked()");
  
  GButton->AddFrame(TBAdd, new TGLayoutHints(kLHintsCenterX,2,2,2,2));
  //  GButton->AddFrame(TBCancel, new TGLayoutHints(kLHintsCenterX,2,2,2,2));

  GF4->AddFrame(VBGMem, new TGLayoutHints(kLHintsLeft,1,1,1,1));
  GF4->AddFrame(GButton,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  fWCMeminductor->AddFrame(GF4,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCMeminductor->MapSubwindows();
  fWCMeminductor->MapWindow();

  kId=1000;

  gClient->WaitFor(fWCMeminductor);
}


void WCMeminductor::RBMemClicked(){
  TGButton *btn1 = (TGButton *) gTQSender;
  kId = btn1->WidgetId();
  if (kId == 0){ NEc->SetState(false); NEc->SetNumber(0); NEa->SetState(true); NEb->SetState(true);}
  if (kId == 1){ NEc->SetState(false); NEc->SetNumber(0); NEa->SetState(true); NEb->SetState(true);}
  if (kId == 2){ NEc->SetNumber(0); NEa->SetState(true); NEb->SetState(true); NEc->SetState(false);}
  if (kId == 3){ NEa->SetState(true); NEb->SetState(true); NEc->SetState(true); }
  if (kId == 4){ NEc->SetNumber(0); NEb->SetNumber(0); NEa->SetState(true); NEb->SetState(false); NEc->SetState(false); }
}

void WCMeminductor::TBAddClicked(){
  faML= (double)NEa->GetNumber();
  fbML= (double)NEb->GetNumber();
  fcML= (double)NEc->GetNumber();
  if(kId!=1000){
    fWCMeminductor->CloseWindow();
  }
}

WCMeminductor::~WCMeminductor(){
  delete fWCMeminductor;
}
