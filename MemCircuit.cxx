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


#ifndef __CINT__
#ifndef ROOT_TApplication
#include "TApplication.h"
#endif
#include "WMainApp.h"
#endif


#ifdef __CINT__
#include "inc/LoadMemTypes.h"
#endif

int MemCircuit(){
  WMainApp *App = new WMainApp(gClient->GetRoot(),1000,290);
  return 0;
}

#ifndef __CINT__
int main(int argc, char** argv){
  TApplication MemCircuitApp("MemCircuitApp", &argc, argv);
  int retVal = MemCircuit();
  MemCircuitApp.Run();
  return retVal;
}
#endif
