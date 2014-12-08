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
WCMeminductor.h
Graphical Interface for creation of object Meminductor
 */

#ifndef MEMCIRCUIT_WCMeminductor
#define MEMCIRCUIT_WCMeminductor

#include <TGFrame.h>
#include <TGNumberEntry.h>
#include <TGLabel.h>
#include <TGWindow.h>
#include <TGButton.h>
#include <TGButtonGroup.h>
#include <RQ_OBJECT.h>

class WCMeminductor{
   
  RQ_OBJECT("WCMeminductor");

 private:
  TGTransientFrame *fWCMeminductor;
  TGHorizontalFrame *GChCoe, *GCha, *GChb, *GChc;                          // Coeficients a,b,c
  TGNumberEntry *NEa, *NEb,  *NEc;                                         // Coeficients a,b,c
  TGCheckButton *CB1, *CB2, *CB3, *CB4;                        // Funciones para el Meminductor
  TGButtonGroup *VBGMem;

  TGRadioButton *RBMeminductor[5];

  TGVerticalFrame *GF4;
  TGHorizontalFrame *GButton;

  TGTextButton *TBAdd, *TBCancel;

  TGLabel *la,*lb,*lc;
  Int_t kId;  
  Double_t faML, fbML, fcML;
  
  void SaveCoef(Int_t &a, Int_t &b, Int_t &c);

 public:
  WCMeminductor(const TGWindow *p,const TGWindow *main);
  Int_t GetIDSelect(){return kId;}
  Double_t GetfaML(){return faML;}
  Double_t GetfbML(){return fbML;}
  Double_t GetfcML(){return fcML;}
  void RBMemClicked();
  void TBAddClicked();

  ~WCMeminductor();
  ClassDef(WCMeminductor,0);  
};
#endif
