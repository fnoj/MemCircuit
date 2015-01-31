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
VSave.h
Class for the control of variables and functions
 */

#ifndef MEMCIRCUIT_VSave
#define MEMCIRCUIT_VSave

#include <TString.h>

class VSave{

 public:

  VSave();
  void Clear();

  TString RmFlux;           //Dependece of Flux with charge

  TString RmFunc1;           //Función1    x(1)
  TString RmFunc2;           //Función2    x(1),x(2)
  TString RmFunc3;           //Función1    x(2)

  TString LmFunc1;           //Función1    x(1)
  TString LmFunc2;           //Función2    x(1),x(2)
  TString LmFunc3;           //Función1    x(2)

  TString CmFunc1;           //Función1    x(1)
  TString CmFunc2;           //Función2    x(1),x(2)
  TString CmFunc3;           //Función1    x(2)
  
  Double_t GetfaRm(Int_t kId){return faRm[kId];}
  Double_t GetfbRm(Int_t kId){return fbRm[kId];}
  Double_t GetfcRm(Int_t kId){return fcRm[kId];}

  Double_t GetfaLm(Int_t kId){return faLm[kId];}
  Double_t GetfbLm(Int_t kId){return fbLm[kId];}
  Double_t GetfcLm(Int_t kId){return fcLm[kId];}

  Double_t GetfaCm(Int_t kId){return faCm[kId];}
  Double_t GetfbCm(Int_t kId){return fbCm[kId];}
  Double_t GetfcCm(Int_t kId){return fcCm[kId];}

  Double_t GetfkR(Int_t kId){return fkR[kId];}
  Double_t GetfkL(Int_t kId){return fkL[kId];}
  Double_t GetfkC(Int_t kId){return fkC[kId];}

  Double_t GetfkIdRm(){return kIdRm;}
  Double_t GetfkIdCm(){return kIdCm;}
  Double_t GetfkIdLm(){return kIdLm;}
  Double_t GetfkIdR(){return kIdR;}
  Double_t GetfkIdC(){return kIdC;}
  Double_t GetfkIdL(){return kIdL;}
 
  Double_t Getff0(){return ff0;}
  Double_t GetfV0(){return fV0;}
  Double_t Getfff(){return fff;}
  Double_t GetfVf(){return fVf;}
  Int_t GetfStepF(){return fStepF;}
  Int_t GetfStepV(){return fStepV;}
  Double_t GetfDeltaF(){return fDeltaF;}
  Double_t GetfDeltaV(){return fDeltaV;}

  Double_t Getfq0(){return fq0;}
  Double_t Getft0(){return ft0;}
  Double_t Getftf(){return ftf;}
  Double_t Getff(){return ff;}
  Double_t Getfv(){return fv;}
  Int_t GetfnPoints(){return fnPoints;}

  /* Double_t GetfRmF(Int_t Id); */
  /* Double_t GetfLmf(Int_t Id); */
  /* Double_t GetfCmf(Int_t Id); */

  void SetfaRm(Double_t a,Int_t Id){faRm[Id]=a;}  
  void SetfbRm(Double_t b,Int_t Id){fbRm[Id]=b;}       
  void SetfcRm(Double_t c,Int_t Id){fcRm[Id]=c;}  

  void SetfaLm(Double_t a,Int_t Id){faLm[Id]=a;}  
  void SetfbLm(Double_t b,Int_t Id){fbLm[Id]=b;}       
  void SetfcLm(Double_t c,Int_t Id){fcLm[Id]=c;}  

  void SetfaCm(Double_t a,Int_t Id){faCm[Id]=a;}  
  void SetfbCm(Double_t b,Int_t Id){fbCm[Id]=b;}       
  void SetfcCm(Double_t c,Int_t Id){fcCm[Id]=c;}  

  void SetfkR(Double_t R,Int_t Id){fkR[Id]=R;}  
  void SetfkL(Double_t L,Int_t Id){fkL[Id]=L;}  
  void SetfkC(Double_t C,Int_t Id){fkC[Id]=C;}  
     
  void SetfkIdRm(Int_t id){kIdRm=id;}
  void SetfkIdCm(Int_t id){kIdCm=id;}
  void SetfkIdLm(Int_t id){kIdLm=id;}
  void SetfkIdR(Int_t id){kIdR=id;}
  void SetfkIdC(Int_t id){kIdC=id;}
  void SetfkIdL(Int_t id){kIdL=id;}

  void Setff0(Double_t f0){ff0=f0;}  
  void SetfV0(Double_t V0){fV0=V0;}
  void Setfff(Double_t ff){fff=ff;}  
  void SetfVf(Double_t Vf){fVf=Vf;}
  void SetfStepF(Double_t StepF){fStepF=StepF;}
  void SetfStepV(Double_t StepV){fStepV=StepV;}
  void SetfDeltaF(Double_t DeltaF){fDeltaF=DeltaF;}
  void SetfDeltaV(Double_t DeltaV){fDeltaV=DeltaV;}

  void Setfq0(Double_t q0){fq0=q0;}
  void Setft0(Double_t t0){ft0=t0;}
  void Setftf(Double_t tf){ftf=tf;}
  void Setff(Double_t f){ff=f;}
  void Setfv(Double_t v){fv=v;}
  void SetfnPoints(Int_t nPoints){fnPoints=nPoints;}
  
  void AddMemristor(Int_t MRFunction,Double_t,Double_t,Double_t,Int_t);
  void AddMeminductor(Int_t MIFunction,Double_t,Double_t,Double_t,Int_t);
  void AddMemcapacitor(Int_t MCFunction,Double_t,Double_t,Double_t,Int_t);

  void AddResistor(Double_t function,Int_t);
  void AddInductor(Double_t function,Int_t);
  void AddCapacitor(Double_t function,Int_t);  

  ~VSave();    

 private:     
  Double_t faRm[10];
  Double_t fbRm[10];         
  Double_t fcRm[10];      

  Double_t faLm[10];
  Double_t fbLm[10];         
  Double_t fcLm[10];      

  Double_t faCm[10];
  Double_t fbCm[10];         
  Double_t fcCm[10];      

  Double_t fkR[10];
  Double_t fkL[10];
  Double_t fkC[10];

  Int_t kIdL, kIdC, kIdR, kIdRm, kIdLm, kIdCm;
  
  Double_t ff0;           //Initial Frequence
  Double_t fV0;           //Initial Voltage 
  Double_t fff;           //Final Frequence 
  Double_t fVf;           //Final Voltage 

  Int_t fStepF;           //Frequence Steps
  Int_t fStepV;           //Voltage Steps

  Double_t fDeltaF;       //Frequence Delta
  Double_t fDeltaV;       //Voltage Delta

  Double_t fq0;           //Condition Intial of Charge
  Double_t ft0;           //Initial Time
  Double_t ftf;           //Final Time
  Double_t ff;            //Frequence
  Double_t fv;            //Voltage 
  Double_t fi;            //Current 

  Int_t fnPoints;         //Number of Poitns
  Int_t fRmF;             //ID Function Rm
  Int_t fLmF;             //ID Function Lm
  Int_t fCmF;             //ID Function Cm

  ClassDef(VSave,0);
};
#endif
