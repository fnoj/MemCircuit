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
TVoltage.h
Class for draw the type of signal 
 */

#ifndef MEMCIRCUIT_TVoltage
#define MEMCIRCUIT_TVoltage


#ifndef ROOT_TPoints
#include "TPoints.h"
#endif

#ifndef ROOT_TLine
#include "TLine.h"
#endif

#ifndef ROOT_TEllipse
#include "TEllipse.h"
#endif

#ifndef ROOT_TObject
#include "TObject.h"
#endif

class TVoltage{

 public:
  TVoltage(Double_t x, Double_t y, Int_t Signal,Char_t Place, Int_t ID);
  void SetSignal(Int_t Signal){fSignal=Signal;}
  TPoints* GetP1(){return fp1;}
  TPoints* GetP2(){return fp2;}
  Int_t GetID(){return fID;}
  Char_t GetPlace(){return fPlace;}
  void Draw();

 private:
  TLine *l1;
  TEllipse *Eex, *Ein;
  Double_t fx;
  Double_t fy;
  Int_t fID;
  Int_t fSignal;
  Char_t fPlace;
  TPoints *fp1, *fp2;

  ClassDef(TVoltage,0);
};
#endif
