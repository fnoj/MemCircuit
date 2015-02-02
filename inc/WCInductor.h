///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2014                              //
//        John Suárez¹  -  Miguel Castillo²  -  Julian Salamanca³        //
//                                                                       //
//                jfsuarezp@correo.udistrital.edu.co¹                    //
//                    mfcastillo@fis.cinvestav.mx²                       //
//                   jusalamanca@udistrital.edu.co³                      //
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
WCInductor.h
Graphical Interface for creation of object Inductor
 */

#ifndef MEMCIRCUIT_WCInductor
#define MEMCIRCUIT_WCInductor

#include <TGFrame.h>
#include <TGNumberEntry.h>
#include <TGLabel.h>
#include <TGWindow.h>
#include <RQ_OBJECT.h>

class WCInductor{

  RQ_OBJECT("WCIndcutor");

 private:
  TGTransientFrame *fWCInductor;
  TGHorizontalFrame *GChL;
  TGNumberEntry *NEkL;
  
  TGVerticalFrame *GF4;
  TGHorizontalFrame *GButton;

  TGTextButton *TBAdd;

  TGLabel *lkL;
  Int_t kId;  
  Double_t fkL;
  
  void SaveCoef(Int_t &a);

 public:
  WCInductor(const TGWindow *p,const TGWindow *main);
  Int_t GetIDSelect(){return kId;}
  Double_t GetfkL(){return fkL;}
  void TBAddClicked();

  ~WCInductor();

  ClassDef(WCInductor,0);
  
};
#endif
