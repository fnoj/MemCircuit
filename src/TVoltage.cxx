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
TVoltage.cxx
Class for draw the type of signal 
 */

#include "TVoltage.h"

TVoltage::TVoltage(Double_t x, Double_t y, Int_t Signal,Char_t Place, Int_t ID){
  fx=x; fy=y; fSignal=Signal; fPlace=Place; fID=ID;
}

void TVoltage::Draw(){
  Eex = new TEllipse(fx,fy,2);
  Eex->Draw();
  Eex->SetFillColor(1);
  Eex->SetLineWidth(3);
  Ein = new TEllipse(fx,fy,1.9);
  Ein->Draw();


  if(fPlace=='p'){
    l1 = new TLine(fx,fy+2,fx,fy+5);
    l1->Draw();
    fp1 = new TPoints(l1->GetX2(),l1->GetY2());

    l1 = new TLine(fx,fy-2,fx,fy-5);
    l1->Draw();
    fp2 = new TPoints(l1->GetX2(),l1->GetY2());
  }

  if(fPlace=='s'){
    l1 = new TLine(fx+2,fy,fx+3.5,fy);
    l1->Draw();
    fp1 = new TPoints(l1->GetX2(),l1->GetY2());

    l1 = new TLine(fx-3.5,fy,fx-2,fy);
    l1->Draw();
    fp2 = new TPoints(l1->GetX2(),l1->GetY2());
  }



  if(fSignal==0){
    l1 = new TLine(fx-1.5,fy-0.5,fx-0.5,fy+0.5);
    l1->Draw();
    l1 = new TLine(fx-0.5,fy+0.5,fx-0.5,fy-0.5);
    l1->Draw();
    l1 = new TLine(fx-0.5,fy-0.5,fx+0.5,fy+0.5);
    l1->Draw();
    l1 = new TLine(fx+0.5,fy+0.5,fx+0.5,fy-0.5);
    l1->Draw();
    l1 = new TLine(fx+0.5,fy-0.5,fx+1.5,fy+0.5);
    l1->Draw();
    l1 = new TLine(fx+1.5,fy+0.5,fx+1.5,fy-0.5);
    l1->Draw();
  }

  if(fSignal==1){
    l1 = new TLine(fx-1.5,fy-0.5,fx-1,fy-0.5);
    l1->Draw();
    l1 = new TLine(fx-1,fy-0.5,fx-1,fy+0.5);
    l1->Draw();
    l1 = new TLine(fx-1,fy+0.5,fx,fy+0.5);
    l1->Draw();
    l1 = new TLine(fx,fy+0.5,fx,fy-0.5);
    l1->Draw();
    l1 = new TLine(fx,fy-0.5,fx,fy-0.5);
    l1->Draw();
    l1 = new TLine(fx,fy-0.5,fx+1,fy-0.5);
    l1->Draw();
    l1 = new TLine(fx+1,fy-0.5,fx+1,fy+0.5);
    l1->Draw();
  }

  if(fSignal==2){
    Eex = new TEllipse(fx-1,fy,0.5,0,180,0);
    Eex->SetNoEdges(true);
    Eex->SetR2(0.8);
    Eex->Draw();
    Eex = new TEllipse(fx,fy,0.5,0,180);
    Eex->SetNoEdges(true);
    Eex->SetR2(0.8);
    Eex->Draw();
    Eex = new TEllipse(fx+1,fy,0.5,0,180,0);
    Eex->SetNoEdges(true);
    Eex->SetR2(0.8);
    Eex->Draw();
  }
}
