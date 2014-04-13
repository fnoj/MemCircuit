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
WCProcessing.h
Window with message "Processing..."
 */

#ifndef MEMCIRCUIT_WCProcessing
#define MEMCIRCUIT_WCProcessing

#include <TGFrame.h>
#include <TGLabel.h>
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
  TGLabel *TLProcessing;
  void Close();
  ~WCProcessing();

  ClassDef(WCProcessing,0);
};
#endif
