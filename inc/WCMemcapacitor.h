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
WCMemcapacitor.h
Graphical Interface for creation of object Memcapacitor
 */

#ifndef MEMCIRCUIT_WCMemcapacitor
#define MEMCIRCUIT_WCMemcapacitor

#include <TGFrame.h>
#include <TGNumberEntry.h>
#include <TGLabel.h>
#include <TGWindow.h>
#include <TGButton.h>
#include <TGButtonGroup.h>
#include <RQ_OBJECT.h>

class WCMemcapacitor{

  RQ_OBJECT("WCMemcapacitor");

 private:
  TGTransientFrame *fWCMemcapacitor;
  TGHorizontalFrame *GChCoe, *GCha, *GChb, *GChc;                          // Coeficients a,b,c
  TGNumberEntry *NEa, *NEb,  *NEc;                                         // Coeficients a,b,c
  TGCheckButton *CB1, *CB2, *CB3, *CB4;                        // Funciones para el Memcapacitor

  TGRadioButton *RBMemcapacitor[5];

  TGVerticalFrame *GF4;
  TGHorizontalFrame *GButton;
  TGVButtonGroup *VBGMem;

  TGTextButton *TBAdd, *TBCancel;

  TGLabel *la,*lb,*lc,*lu;
  Int_t kId;  
  Double_t faMC, fbMC, fcMC;
  
  void SaveCoef(Int_t &a, Int_t &b, Int_t &c);

 public:
  WCMemcapacitor(const TGWindow *p,const TGWindow *main);
  Int_t GetIDSelect(){return kId;}
  Double_t GetfaMC(){return faMC;}
  Double_t GetfbMC(){return fbMC;}
  Double_t GetfcMC(){return fcMC;}
  void TBAddClicked();
  void RBMemClicked();

  ~WCMemcapacitor();

  ClassDef(WCMemcapacitor,0);  
};
#endif
