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
TCirDevice.h
Class for draw any of devices circuits
 */


#ifndef MEMCIRCUIT_TCirDevice
#define MEMCIRCUIT_TCirDevice

#ifndef ROOT_TPoints
#include "TPoints.h"
#endif

#ifndef ROOT_TLine
#include "TLine.h"
#endif

#ifndef ROOT_TCurlyLine
#include "TCurlyLine.h"
#endif

#ifndef ROOT_TObject
#include "TObject.h"
#endif

class TCirDevice{

 public:
  TCirDevice(Double_t x, Double_t y, Char_t Type,Char_t Place);
  TPoints* GetP1(){return fp1;}
  TPoints* GetP2(){return fp2;}
  Int_t GetN(){return fDevice;}
  Char_t GetPlace(){return fPlace;}
  void Draw();

  //void Add(){fDevice+1;}

 private:
  Int_t fDevice;
  TLine *l1, *l2;
  TCurlyLine *cli;
  Double_t fx;
  Double_t fy;
  Char_t fPlace;
  Char_t fType;
  TPoints *fp1, *fp2;

  ClassDef(TCirDevice,0);
};
#endif
