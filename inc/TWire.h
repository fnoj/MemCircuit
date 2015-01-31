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
TWire.h
Class for draw the connection between the devices 
 */

#ifndef MEMCIRCUIT_TWire
#define MEMCIRCUIT_TWire

#ifndef ROOT_TPoints
#include "TPoints.h"
#endif

#ifndef ROOT_TLine
#include "TLine.h"
#endif

#ifndef MEMCIRCUIT_TVoltage
#include "TVoltage.h"
#endif

#ifndef MEMCIRCUIT_TCirDevice
#include "TCirDevice.h"
#endif

#ifndef ROOT_TObject
#include "TObject.h"
#endif

class TWire{
 
 public:
  TWire(TCirDevice *d1, TCirDevice *d2);
  TWire(TVoltage *d1, TCirDevice *d2);
  TWire(TCirDevice *d1, TVoltage *d2);
  //  TWire(TVoltage *d1, TCirDevice *d2, Int_t);

  TPoints* GetP1D1(){return fP1D1;}
  TPoints* GetP2D1(){return fP2D1;}
  TPoints* GetP1D2(){return fP1D2;}
  TPoints* GetP2D2(){return fP2D2;}

  ~TWire();
  
 private:
  TPoints *fP1D1, *fP2D1, *fP1D2, *fP2D2, *fP1V1, *fP2V1;
  TLine *l1,*l2;
  Double_t fx1d1,fx2d1,fy1d1,fy2d1;
  Double_t fx1v1,fx2v1,fy1v1,fy2v1;
  Double_t fx1d2,fx2d2,fy1d2,fy2d2;

  ClassDef(TWire,0);
};
#endif
