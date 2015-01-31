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
WCProcessing.h
Window with message "Processing..."
 */

#ifndef MEMCIRCUIT_WCProcessing
#define MEMCIRCUIT_WCProcessing

#include <TGFrame.h>
#include <TGLabel.h>
#include <TBenchmark.h>
#include <TGClient.h>
#include <TGWindow.h>
#include <RQ_OBJECT.h>

class WCProcessing{

  RQ_OBJECT("WCProcessing");
   
 private:
  TGHorizontalFrame *GF;

 public:
  WCProcessing(const TGWindow *p,const TGWindow *main);
  TGTransientFrame *fWCProcessing;
  TGTextButton  *TBStop;
  TBenchmark *TBCpu;
  TGLabel *TLProcessing;
  void Close();
  ~WCProcessing();

  ClassDef(WCProcessing,0);
};
#endif
