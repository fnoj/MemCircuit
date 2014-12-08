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
TCirDevice.cxx
Class for draw any of devices circuits
 */

#include "TCirDevice.h"

TCirDevice::TCirDevice(Double_t x, Double_t y, Char_t Type,Char_t Place){
  fx=x; fy=y; fPlace=Place; fType= Type;
}

void TCirDevice::Draw(){
  switch (fType){
  case 'l':
    if(fPlace=='s'){
      cli = new TCurlyLine(fx-4,fy,fx+4,fy,.01,.01);
      cli->Draw();
      
      l1 = new TLine(fx-4,fy,fx-5,fy);
      l1->Draw();
      fp1 = new TPoints(l1->GetX2(),l1->GetY2());
      
      l1 = new TLine(fx+4,fy,fx+5,fy);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());
    }
    
    if(fPlace=='p'){
      cli = new TCurlyLine(fx,fy-3,fx,fy+2,.01,.01);
      cli->Draw();
      
      l1 = new TLine(fx,fy+2,fx,fy+5);
      l1->Draw();
      fp1 = new TPoints(l1->GetX2(),l1->GetY2());
      
      l1 = new TLine(fx,fy-3,fx,fy-5);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());
    }
    break;

  case 'L':
    if(fPlace=='s'){
      cli = new TCurlyLine(fx-4,fy,fx+4,fy,.01,.01);
      cli->Draw();
      
      l1 = new TLine(fx-4,fy,fx-5,fy);
      l1->Draw();
      fp1 = new TPoints(l1->GetX2(),l1->GetY2());
      
      l1 = new TLine(fx+4,fy,fx+5,fy);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());

      l1 = new TLine(fx-4,fy+0.2,fx+4,fy+0.2);
      l1->Draw();
    }
    
    if(fPlace=='p'){
      cli = new TCurlyLine(fx,fy-3,fx,fy+2,.01,.01);
      cli->Draw();
      
      l1 = new TLine(fx,fy+2,fx,fy+5);
      l1->Draw();
      fp1 = new TPoints(l1->GetX2(),l1->GetY2());
      
      l1 = new TLine(fx,fy-3,fx,fy-5);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());

      l1 = new TLine(fx-0.2,fy+2,fx-0.2,fy-3);
      l1->Draw();
    }
    break;

  case 'c':
    if(fPlace=='s'){
      l2 = new TLine(fx+1,fy+1,fx+1,fy-1);
      l2->Draw();
      
      l2 = new TLine(fx,fy+1,fx,fy-1);
      l2->Draw();
      
      l1 = new TLine(fx-4,fy,fx,fy);
      l1->Draw();
      fp1 = new TPoints(l1->GetX1(),l1->GetY1());
      
      l1 = new TLine(fx+1,fy,fx+5,fy);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());
    }
    
    if(fPlace=='p'){
      l2 = new TLine(fx+1,fy+1,fx-1,fy+1);
      l2->Draw();
      
      l2 = new TLine(fx+1,fy,fx-1,fy);
      l2->Draw();

      l1 = new TLine(fx,fy+1,fx,fy+5);
      l1->Draw();      
      fp1 = new TPoints(l1->GetX2(),l1->GetY2());
      
      l1 = new TLine(fx,fy,fx,fy-5);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());
    }
    break;

  case 'C':
    if(fPlace=='s'){
      l2 = new TLine(fx+1,fy+1,fx+1,fy-1);
      l2->Draw();

      l2 = new TLine(fx,fy+1,fx,fy-1);
      l2->Draw();

      l2 = new TLine(fx+0.5,fy+1,fx+0.5,fy-1);
      l2->Draw();
            
      l1 = new TLine(fx-4,fy,fx,fy);
      l1->Draw();
      fp1 = new TPoints(l1->GetX1(),l1->GetY1());
      
      l1 = new TLine(fx+1,fy,fx+5,fy);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());

    }
    
    if(fPlace=='p'){
      l2 = new TLine(fx+1,fy+1,fx-1,fy+1);
      l2->Draw();

      l2 = new TLine(fx+1,fy+0.5,fx-1,fy+0.5);
      l2->Draw();
      
      l2 = new TLine(fx+1,fy,fx-1,fy);
      l2->Draw();

      l1 = new TLine(fx,fy+1,fx,fy+5);
      l1->Draw();      
      fp1 = new TPoints(l1->GetX2(),l1->GetY2());
      
      l1 = new TLine(fx,fy,fx,fy-5);
      l1->Draw();
      fp2 = new TPoints(l1->GetX2(),l1->GetY2());
    }
    break;

  case 'r':
    if(fPlace=='s'){
      l1 = new TLine(fx-3,fy,fx-2.5,fy-1);
      l1->Draw();
      l1 = new TLine(fx-2.5,fy-1,fx-2,fy+1);
      l1->Draw();
      l1 = new TLine(fx-2,fy+1,fx-1.5,fy-1);
      l1->Draw();
      l1 = new TLine(fx-1.5,fy-1,fx-1,fy+1);
      l1->Draw();
      l1 = new TLine(fx-1,fy+1,fx-0.5,fy-1);
      l1->Draw();
      l1 = new TLine(fx-0.5,fy-1,fx,fy+1);
      l1->Draw();
      l1 = new TLine(fx,fy+1,fx+0.5,fy-1);
      l1->Draw();
      l1 = new TLine(fx+0.5,fy-1,fx+1,fy);
      l1->Draw();
      
      l2 = new TLine(fx-3,fy,fx-5,fy);
      l2->Draw();
      fp1 = new TPoints(l2->GetX2(),l2->GetY2());

      l2 = new TLine(fx+1,fy,fx+3,fy);
      l2->Draw();
      fp2 = new TPoints(l2->GetX2(),l2->GetY2());
    }
    
    if(fPlace=='p'){

      l1 = new TLine(fx,fy-2.5,fx+1,fy-2);
      l1->Draw();
      l1 = new TLine(fx+1,fy-2,fx-1,fy-1.5);
      l1->Draw();
      l1 = new TLine(fx-1,fy-1.5,fx+1,fy-1);
      l1->Draw();
      l1 = new TLine(fx+1,fy-1,fx-1,fy-0.5);
      l1->Draw();
      l1 = new TLine(fx-1,fy-0.5,fx+1,fy);
      l1->Draw();
      l1 = new TLine(fx+1,fy,fx-1,fy+0.5);
      l1->Draw();
      l1 = new TLine(fx-1,fy+0.5,fx+1,fy+1);
      l1->Draw();
      l1 = new TLine(fx+1,fy+1,fx,fy+1.5);
      l1->Draw();
      
      l2 = new TLine(fx,fy+1.5,fx,fy+5);
      l2->Draw();
      fp1 = new TPoints(l2->GetX2(),l2->GetY2());
      
      l2 = new TLine(fx,fy-2.5,fx,fy-5);
      l2->Draw();
      fp2 = new TPoints(l2->GetX2(),l2->GetY2());
    }    
    break;

  case 'R':
    if(fPlace=='s'){
      l1 = new TLine(fx-3,fy,fx-3,fy-1);
      l1->Draw();
      l1 = new TLine(fx-3,fy-1,fx-2,fy-1);
      l1->Draw();
      l1 = new TLine(fx-2,fy-1,fx-2,fy+1);
      l1->Draw();
      l1 = new TLine(fx-2,fy+1,fx-1,fy+1);
      l1->Draw();
      l1 = new TLine(fx-1,fy+1,fx-1,fy-1);
      l1->Draw();
      l1 = new TLine(fx-1,fy-1,fx,fy-1);
      l1->Draw();
      l1 = new TLine(fx,fy-1,fx,fy+1);
      l1->Draw();
      l1 = new TLine(fx,fy+1,fx+1,fy+1);
      l1->Draw();
      l1 = new TLine(fx+1,fy+1,fx+1,fy-1);
      l1->Draw();
      l1 = new TLine(fx+1,fy+1,fx+1,fy-1);
      l1->Draw();
      l1 = new TLine(fx+1,fy-1,fx+2,fy-1);
      l1->Draw();
      l1 = new TLine(fx+2,fy-1,fx+2,fy);
      l1->Draw();
      
      l2 = new TLine(fx-3,fy,fx-6,fy);
      l2->Draw();
      fp1 = new TPoints(l2->GetX2(),l2->GetY2());

      l2 = new TLine(fx+2,fy,fx+5,fy);
      l2->Draw();
      fp2 = new TPoints(l2->GetX2(),l2->GetY2());
    }
    
    if(fPlace=='p'){
      l1 = new TLine(fx,fy-3,fx-1,fy-3);
      l1->Draw();
      l1 = new TLine(fx-1,fy-3,fx-1,fy-2);
      l1->Draw();
      l1 = new TLine(fx-1,fy-2,fx+1,fy-2);
      l1->Draw();
      l1 = new TLine(fx+1,fy-2,fx+1,fy-1);
      l1->Draw();
      l1 = new TLine(fx+1,fy-1,fx-1,fy-1);
      l1->Draw();
      l1 = new TLine(fx-1,fy-1,fx-1,fy);
      l1->Draw();
      l1 = new TLine(fx-1,fy,fx+1,fy);
      l1->Draw();
      l1 = new TLine(fx+1,fy,fx+1,fy+1);
      l1->Draw();
      l1 = new TLine(fx+1,fy+1,fx-1,fy+1);
      l1->Draw();
      l1 = new TLine(fx+1,fy+1,fx-1,fy+1);
      l1->Draw();
      l1 = new TLine(fx-1,fy+1,fx-1,fy+2);
      l1->Draw();
      l1 = new TLine(fx-1,fy+2,fx,fy+2);
      l1->Draw();
      
      l2 = new TLine(fx,fy+2,fx,fy+5);
      l2->Draw();
      fp1 = new TPoints(l2->GetX2(),l2->GetY2());
      
      l2 = new TLine(fx,fy-3,fx,fy-5);
      l2->Draw();
      fp2 = new TPoints(l2->GetX2(),l2->GetY2());
    }    
    break;
  }
}
