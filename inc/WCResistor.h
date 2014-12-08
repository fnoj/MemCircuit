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
WCResistor.h
Graphical Interface for creation of object Resistor
 */

#ifndef MEMCIRCUIT_WCResistor
#define MEMCIRCUIT_WCResistor

#include <TGFrame.h>
#include <TGNumberEntry.h>
#include <TGLabel.h>
#include <TGWindow.h>
#include <RQ_OBJECT.h>

class WCResistor{

  RQ_OBJECT("WCResistor");
   
 private:
  TGTransientFrame *fWCResistor;
  TGHorizontalFrame *GChR;
  TGNumberEntry *NEkR;

  TGVerticalFrame *GF4;
  TGHorizontalFrame *GButton;

  TGTextButton *TBAdd;

  TGLabel *lkR;
  Double_t fkR;
  
 public:
  WCResistor(const TGWindow *p,const TGWindow *main);
  Double_t GetfkR(){return fkR;}
  void TBAddClicked();

  ~WCResistor();  

  ClassDef(WCResistor,0);
};
#endif
