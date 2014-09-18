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
TWire.h
Class for draw the connection between the devices 
 */

#include "TWire.h"

TWire::TWire(TCirDevice *d1, TCirDevice *d2){//--------------------------------------------> Device Device
  fP1D1 = d1->GetP1();
  fx1d1=fP1D1->GetX();
  fy1d1=fP1D1->GetY();
  
  fP2D1 = d1->GetP2();
  fx2d1=fP2D1->GetX();
  fy2d1=fP2D1->GetY();

  fP1D2 = d2->GetP1();
  fx1d2=fP1D2->GetX();
  fy1d2=fP1D2->GetY();
  
  fP2D2 = d2->GetP2();
  fx2d2=fP2D2->GetX();
  fy2d2=fP2D2->GetY();

  if(d1->GetPlace()=='p' && d2->GetPlace()=='s'){  
    if(fx1d1<fx1d2){
      if(fy1d1<=fy1d2){ 
	l1 = new TLine(fx1d1,fy1d1,fx1d1,fy1d2);
	l1->Draw();
	l2 = new TLine(fx1d1,fy1d2,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1d1>fy1d2){ 
	l1 = new TLine(fx2d1,fy2d1,fx1d2,fy2d1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy2d1,fx1d2,fy1d2);
	l2->Draw();
      }
    }
    if(fx1d1>fx1d2){
      if(fy1d2<=fy1d1){ 
	l1 = new TLine(fx2d1,fy2d1,fx2d2,fy2d1);
	l1->Draw();
	l2 = new TLine(fx2d2,fy2d1,fx2d2,fy2d2);
	l2->Draw();
      }
      if(fy1d2>fy1d1){ 
	l1 = new TLine(fx1d1,fy1d1,fx2d1,fy1d2);
	l1->Draw();
	l2 = new TLine(fx2d1,fy1d2,fx2d2,fy2d2);
	l2->Draw();
      }
    }
  }

  if(d1->GetPlace()=='s' && d2->GetPlace()=='p'){
    if(fx1d1<fx1d2){
      if(fy1d1<=fy1d2){ 
	l1 = new TLine(fx1d1,fy1d1,fx1d1,fy1d2);
	l1->Draw();
	l2 = new TLine(fx1d1,fy1d2,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1d1>fy1d2){ 
	l1 = new TLine(fx1d1,fy1d1,fx1d1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx1d1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
    }
    if(fx1d1>fx1d2){
      if(fy1d2<=fy1d1){ 
	l1 = new TLine(fx2d1,fy2d1,fx2d1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx2d1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
      if(fy1d2>fy1d1){ 
	l1 = new TLine(fx2d1,fy2d1,fx2d1,fy1d2);
	l1->Draw();
	l2 = new TLine(fx2d1,fy1d2,fx1d2,fy1d2);
	l2->Draw();
      }
    }
  }

  
  if( (d1->GetPlace()=='p' && d2->GetPlace()=='p')){  
    if(fx1d1<fx1d2){
      if(fy1d1<=fy1d2){ 
	l1 = new TLine(fx2d1,fy2d1,fx1d2,fy2d1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy2d1,fx2d2,fy2d2);
	l2->Draw();
      }
      if(fy1d1>fy1d2){
	l1 = new TLine(fx1d1,fy1d1,fx1d2,fy1d1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy1d1,fx1d2,fy1d2);
	l2->Draw();
      }
    }
    
    if(fx1d1>fx1d2){
      if(fy1d2<=fy1d1){ 
	l1 = new TLine(fx1d1,fy1d1,fx1d2,fy1d1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy1d1,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1d2>fy1d1){
	l1 = new TLine(fx2d1,fy2d1,fx1d2,fy2d1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy2d1,fx2d2,fy2d2);
	l2->Draw();
      }
    }
  }   

  if( (d1->GetPlace()=='s' && d2->GetPlace()=='s')){  
    if(fx1d1<fx1d2){
      if(fy1d1<fy1d2){ 
	l1 = new TLine(fx1d1,fy1d1,fx1d1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx1d1,fy2d2,fx1d2,fy1d2);
       	l2->Draw();
      }
      if(fy1d1>fy1d2){ 
	l1 = new TLine(fx2d1,fy2d1,fx2d1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx2d1,fy2d2,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1d1==fy1d2){ 
	l1 = new TLine(fx2d1,fy2d1,fx1d2,fy1d2);
	l1->Draw();
      }
    }
    
    if(fx1d1>fx1d2){
      if(fy1d2<fy1d1){ 
	l1 = new TLine(fx2d1,fy2d1,fx2d1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx2d1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
      if(fy1d2>=fy1d1){ 
	l1 = new TLine(fx2d1,fy2d1,fx2d1,fy1d2+5);
	l1->Draw();
	l2 = new TLine(fx2d1,fy1d2+5,fx1d2,fy1d2+5);
	l2->Draw();
	l2 = new TLine(fx1d2,fy1d2+5,fx1d2,fy1d2);
	l2->Draw();
      }
    }
    
  }   
}

TWire::TWire(TVoltage *v1, TCirDevice *d2){//--------------------------------------------> Voltage Device
  fP1V1 = v1->GetP1();
  fx1v1=fP1V1->GetX();
  fy1v1=fP1V1->GetY();
  
  fP2V1 = v1->GetP2();
  fx2v1=fP2V1->GetX();
  fy2v1=fP2V1->GetY();

  fP1D2 = d2->GetP1();
  fx1d2=fP1D2->GetX();
  fy1d2=fP1D2->GetY();

  fP2D2 = d2->GetP2();
  fx2d2=fP2D2->GetX();
  fy2d2=fP2D2->GetY();

  /* if(v1->GetPlace()=='s' && d2->GetPlace()=='s'){ */
  /*   if(fx1v1<fx1d2){ */
  /*     if(fy1v1<=fy1d2){  */
  /* 	l1 = new TLine(fx1v1,fy1v1,fx1d2,fy1d2); */
  /* 	l1->Draw(); */
  /*     } */
  /*     if(fy1v1>fy1d2){  */
  /* 	l1 = new TLine(fx1v1,fy1v1,fx1d2,fy2d2); */
  /* 	l1->Draw(); */
  /*     } */
  /*     if(fy1v1<fy1d2 && fy1v1>fy1d2){  */
  /* 	l1 = new TLine(fx1v1,fy1v1,fx1d2,fy1d2); */
  /* 	l1->Draw(); */
  /*     } */
  /*   } */
  /* } */

  /* if(v1->GetPlace()=='s' && d2->GetPlace()=='p'){ */
  /*   if(fx1v1<fx1d2){ */
  /*     l1 = new TLine(fx1v1,fy1v1,fx1d2,fy1d2); */
  /*     l1->Draw(); */
  /*   } */
  /*   if(fx1v1>fx1d2){  */
  /*     l1 = new TLine(fx1v1,fy1v1,fx2d2,fy2d2); */
  /*     l1->Draw(); */
  /*   } */
  /* } */

  if(v1->GetPlace()=='p' && d2->GetPlace()=='s'){
    if(fx1v1<fx1d2){
      if(fy1v1<fy1d2){ 
	l1 = new TLine(fx1v1,fy1v1,fx1v1,fy1d2);
	l1->Draw();
	l2 = new TLine(fx1v1,fy1d2,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1v1>fy1d2){ 
	l1 = new TLine(fx1v1,fy1v1,fx2d2,fy1v1);
	l1->Draw();
	l2 = new TLine(fx2d2,fy1v1,fx2d2,fy2d2);
	l2->Draw();
      }
    }

    if(fx1v1>fx1d2){ 
      if(fy1d2<=fy1v1){ 
	l1 = new TLine(fx1d2,fy1d2,fx1d2,fy1v1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy1v1,fx1v1,fy1v1);
	l2->Draw();
      }
      if(fy1d2>fy1v1){ 
	l1 = new TLine(fx1d2,fy1d2,fx1d2,fy2v1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy2v1,fx2v1,fy2v1);
	l2->Draw();
      }
    }
  }

  if(v1->GetPlace()=='p' && d2->GetPlace()=='p'){
    if(fx1v1<fx1d2){
      if(fy1v1<=fy1d2){ 
	l1 = new TLine(fx2v1,fy2v1,fx2v1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx2v1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
      if(fy1v1>fy1d2){
	l1 = new TLine(fx1v1,fy2v1,fx1v1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx1v1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
    }
    
    if(fx1v1>fx1d2){
      if(fy1d2<=fy1v1){ 
	l1 = new TLine(fx1v1,fy1v1,fx1d2,fy1v1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy1v1,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1d2>fy1v1){
	l1 = new TLine(fx1v1,fy1v1,fx2v1,fy1d2);
	l1->Draw();
	l2 = new TLine(fx2v1,fy1d2,fx1d2,fy1d2);
	l2->Draw();
      }
    }
  }
}


TWire::TWire(TCirDevice *d2,TVoltage *v1){//--------------------------------------------> Device Voltage
  fP1V1 = v1->GetP1();
  fx1v1=fP1V1->GetX();
  fy1v1=fP1V1->GetY();
  
  fP2V1 = v1->GetP2();
  fx2v1=fP2V1->GetX();
  fy2v1=fP2V1->GetY();

  fP1D2 = d2->GetP1();
  fx1d2=fP1D2->GetX();
  fy1d2=fP1D2->GetY();

  fP2D2 = d2->GetP2();
  fx2d2=fP2D2->GetX();
  fy2d2=fP2D2->GetY();

  if(v1->GetPlace()=='p' && d2->GetPlace()=='s'){
    if(fx1v1<fx1d2){
      if(fy1d2<=fy1v1){ 
	l1 = new TLine(fx2v1,fy2v1,fx1d2,fy2v1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy2v1,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1d2>fy1v1){ 
	l1 = new TLine(fx2d2,fy2d2,fx2d2,fy2v1);
	l1->Draw();
	l2 = new TLine(fx2d2,fy2v1,fx2v1,fy2v1);
	l2->Draw();
      }
    }
    if(fx1v1>fx1d2){ 
      if(fy1d2<=fy1v1){ 
	l1 = new TLine(fx2d2,fy2d2,fx2d2,fy2v1);
	l1->Draw();
	l2 = new TLine(fx2d2,fy2v1,fx2v1,fy2v1);
	l2->Draw();
      }
      if(fy1d2>fy1v1){ 

	l1 = new TLine(fx1v1,fy1v1,fx1v1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx1v1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
    }
  }

  if(v1->GetPlace()=='p' && d2->GetPlace()=='p'){
    if(fx1v1<fx1d2){
      if(fy1v1<fy1d2){ 
	l1 = new TLine(fx2v1,fy2v1,fx2v1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx2v1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
      if(fy1v1>fy1d2){
	l1 = new TLine(fx1v1,fy1v1,fx1d2,fy1v1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy1v1,fx1d2,fy1d2);
	l2->Draw();
      }
      if(fy1v1==fy1d2){

	l1 = new TLine(fx1v1,fy1v1,fx1d2,fy1v1);
	l1->Draw();
	l2 = new TLine(fx1d2,fy1v1,fx1d2,fy1d2);
	l2->Draw();
      }
    }

    if(fx1v1>fx1d2){
      if(fy1d2<fy1v1){ 
	l1 = new TLine(fx2v1,fy2v1,fx2v1,fy2d2);
	l1->Draw();
	l2 = new TLine(fx2v1,fy2d2,fx2d2,fy2d2);
	l2->Draw();
      }
      if(fy1d2>fy1v1){
	l1 = new TLine(fx2d2,fy2d2,fx2d2,fy2v1);
	l1->Draw();
	l2 = new TLine(fx2d2,fy2v1,fx2v1,fy2v1);
	l2->Draw();
      }
    }
  }
}

TWire::~TWire(){
  delete l1;
  delete l2;
}
