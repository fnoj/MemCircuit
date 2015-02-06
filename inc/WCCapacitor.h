///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2014                              //
//        John Suárez¹  -  Miguel Castillo²  -  Julian Salamanca³        //
//                                                                       //
//                jfsuarezp@correo.udistrital.edu.co¹                    //
//                    mfcastillo@fis.cinvestav.mx²                       //
//                   jasalamanca@udistrital.edu.co³                      //
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
WCCapacitor.h
Graphical Interface for creation of object Capacitor
 */

#ifndef MEMCIRCUIT_WCCapacitor
#define MEMCIRCUIT_WCCapacitor

#include <TGFrame.h>
#include <TGNumberEntry.h>
#include <TGLabel.h>
#include <TGWindow.h>
#include <RQ_OBJECT.h>

class WCCapacitor{

  RQ_OBJECT("WCCapacitor");

 private:
  TGTransientFrame *fWCCapacitor;
  TGHorizontalFrame *GChC;
  TGNumberEntry *NEkC;

  TGVerticalFrame *GF4;
  TGHorizontalFrame *GButton;

  TGTextButton *TBAdd;

  TGLabel *lkC;
  Double_t fkC;
  
 public:
  WCCapacitor(const TGWindow *p,const TGWindow *main);
  Double_t GetfkC(){return fkC;}
  void TBAddClicked();

  ~WCCapacitor();

  ClassDef(WCCapacitor,0);
  
};
#endif
