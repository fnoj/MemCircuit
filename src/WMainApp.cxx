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
WMainApp.cxx
Main Graphical Interface of aplication MemCircuit
 */

#include "WMainApp.h"

using namespace std;

WMainApp::WMainApp(const TGWindow *p,UInt_t w,UInt_t h): script("/tmp/mem.m"), variables("/tmp/var.mat"){
  
  Cil1 = new TGLayoutHints(kLHintsExpandX | kLHintsExpandY ,2,2,2,2);
  Cil2 = new TGLayoutHints(kLHintsCenterX | kLHintsCenterY ,2,2,2,2);

  TMF1 = new TGMainFrame(p,w,h);
  TMF1->SetWindowName("MemCircuit");
  TMF1->SetCleanup(kDeepCleanup);
  TMF1->SetIconPixmap("/usr/share/memcircuit/icon_memcircuit.png");
  TMF1->SetIconName("MemCircuit");
  TMF1->SetWMSizeHints(w,h,w,h,1,1);
    
  //Create Frames ________________________________________________________________________________
  VFMain = new TGHorizontalFrame(TMF1,0,0,0);

  HF = new TGHorizontalFrame(VFMain,0,0,0);
  VFPar = new TGVerticalFrame(VFMain,0,0,0);

  VFO = new TGVerticalFrame(HF,0,0,0);
  
  //\begin{CanvasCircuit}=======================================================================
  CiVFO1 = new TGVerticalFrame(HF,0,0,0);
  CiGF1 = new TGGroupFrame(CiVFO1,"Devices",kVerticalFrame); 

  CiVFDevices = new TGVerticalFrame(CiGF1,0,0,0);
  CiHFDevClas = new TGHorizontalFrame(CiVFDevices,0,0,0);
  CiHFDevMod = new TGHorizontalFrame(CiVFDevices,0,0,0);

  CiPBR = new TGPictureButton(CiHFDevClas, gClient->GetPicture("/usr/share/memcircuit/resistor.png"),0);
  CiPBR->Connect("Clicked()","WMainApp",this,"CiDraw()");
  CiHFDevClas->AddFrame(CiPBR,new TGLayoutHints(kLHintsExpandX,3,3,3,3));
  
  CiPBL = new TGPictureButton(CiHFDevClas,gClient->GetPicture("/usr/share/memcircuit/inductor.png"),1);   
  CiPBL->SetState(kButtonDisabled);
  CiPBL->Connect("Clicked()","WMainApp",this,"CiDraw()");
  CiHFDevClas->AddFrame(CiPBL,new TGLayoutHints(kLHintsCenterX,3,3,3,3));  

  CiPBC = new TGPictureButton(CiHFDevClas,gClient->GetPicture("/usr/share/memcircuit/capacitor.png"),2);  
  CiPBC->SetState(kButtonDisabled);
  CiPBC->Connect("Clicked()","WMainApp",this,"CiDraw()");
  CiHFDevClas->AddFrame(CiPBC,new TGLayoutHints(kLHintsCenterX,3,3,3,3));  

  CiPBMR = new TGPictureButton(CiHFDevMod,gClient->GetPicture("/usr/share/memcircuit/memristor.png"),3);   
  CiPBMR->Connect("Clicked()","WMainApp",this,"CiDraw()");
  CiHFDevMod->AddFrame(CiPBMR,new TGLayoutHints(kLHintsCenterX,3,3,3,3));  

  CiPBML = new TGPictureButton(CiHFDevMod,gClient->GetPicture("/usr/share/memcircuit/meminductor.png"),4);  
  CiPBML->SetState(kButtonDisabled);
  CiPBML->Connect("Clicked()","WMainApp",this,"CiDraw()");
  CiHFDevMod->AddFrame(CiPBML,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 

  CiPBMC = new TGPictureButton(CiHFDevMod,gClient->GetPicture("/usr/share/memcircuit/memcapacitor.png"),5);  
  CiPBMC->SetState(kButtonDisabled);
  CiPBMC->Connect("Clicked()","WMainApp",this,"CiDraw()");
  CiHFDevMod->AddFrame(CiPBMC,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 

  CiVFDevices->AddFrame(CiHFDevClas,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,5,5,5,5)); 
  CiVFDevices->AddFrame(CiHFDevMod,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,5,5,5,5)); 

  /*  CiHFOrient = new TGHorizontalFrame(CiGF1);
  CiRB1 = new TGRadioButton(CiHFOrient,"Serie",0); 
  CiRB1->SetState(kButtonDown,kFALSE); 
  CiRB1->Connect("Clicked()","WMainApp",this,"CiRBPlaceClicked()");    
  CiRB2 = new TGRadioButton(CiHFOrient,"Parallel",1); 
  CiRB2->Connect("Clicked()","WMainApp",this,"CiRBPlaceClicked()");    
 
  CiHFOrient->AddFrame(CiRB1,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,4,4,4,4)); 
  CiHFOrient->AddFrame(CiRB2,new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,4,4,4,4)); */

  CiGF1->AddFrame(CiVFDevices, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,5,5,5,5)); 
  //  CiGF1->AddFrame(CiHFOrient, new TGLayoutHints(kLHintsBottom | kLHintsCenterX,5,5,5,5)); 

  CiGChSignal = new TGHorizontalFrame(CiVFO1); 
  CiRBSignal[0] = new TGRadioButton(CiGChSignal,"",0);//RBSignal0   -> Signal DS 
  CiRBSignal[0]->SetState(kButtonDown,kFALSE);  
  CiRBSignal[0]->Connect("Clicked()","WMainApp",this,"SignalTypeSelect()");   
  CiRBSignal[1] = new TGRadioButton(CiGChSignal,"",1); //RBSignal1   -> Signal Square 
  CiRBSignal[1]->Connect("Clicked()","WMainApp",this,"SignalTypeSelect()");   
  CiRBSignal[2] = new TGRadioButton(CiGChSignal,"",2); //RBSignal2   -> Signal Sinuidal 
  CiRBSignal[2]->Connect("Clicked()","WMainApp",this,"SignalTypeSelect()");   
  CiISignal_DS = new TGIcon(CiGChSignal,"/usr/share/memcircuit/signal_ds.png"); 
  CiISignal_S = new TGIcon(CiGChSignal,"/usr/share/memcircuit/signal_square.png"); 
  CiISignal_Sin = new TGIcon(CiGChSignal,"/usr/share/memcircuit/signal_sin.png"); 

  CiGChSignal->AddFrame(CiRBSignal[0],new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  CiGChSignal->AddFrame(CiISignal_DS,new TGLayoutHints(kLHintsCenterX,3,10,3,3)); 
  CiGChSignal->AddFrame(CiRBSignal[1],new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  CiGChSignal->AddFrame(CiISignal_S,new TGLayoutHints(kLHintsCenterX,3,10,3,3)); 
  CiGChSignal->AddFrame(CiRBSignal[2],new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  CiGChSignal->AddFrame(CiISignal_Sin,new TGLayoutHints(kLHintsCenterX,3,10,3,3)); 

  ///Options
  CiGF2 = new TGGroupFrame(CiVFO1,"Options",kVerticalFrame);
  CiTGBRun = new TGTextButton(CiGF2,"&Run");
  CiTGBRun->SetState(kButtonDisabled);
  CiTGBRun->Connect("Clicked()","WMainApp",this,"Run()");
  
  CiTGBClear = new TGTextButton(CiGF2,"&Clear");
  CiTGBClear->Connect("Clicked()","WMainApp",this,"CiClear()");

  CiTGBExit = new TGTextButton(CiGF2,"&Exit","gApplication->Terminate(0)");

  CiTGBOpen= new TGTextButton(CiGF2,"&Open");
  CiTGBOpen->Connect("Clicked()","WMainApp",this,"CiOpen()");
  
  CiGF2->AddFrame(CiTGBRun,new TGLayoutHints(kLHintsExpandX | kLHintsCenterY ,50,50,2,2));
  CiGF2->AddFrame(CiTGBClear,new TGLayoutHints(kLHintsExpandX | kLHintsCenterY ,50,50,2,2));
  CiGF2->AddFrame(CiTGBOpen,new TGLayoutHints(kLHintsExpandX | kLHintsCenterY ,50,50,2,2)); 
  CiGF2->AddFrame(CiTGBExit,new TGLayoutHints(kLHintsExpandX | kLHintsCenterY ,50,50,2,2));
    
  CiVFO1->AddFrame(CiGF1, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY)); 
  CiVFO1->AddFrame(CiGChSignal, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY)); 
  CiVFO1->AddFrame(CiGF2, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));

  CiVFO2 = new TGVerticalFrame(HF,3,3,3,3);         
  EC2 = new TRootEmbeddedCanvas("EC2",CiVFO2,400,250); 
  CCircuit = EC2->GetCanvas();
  CCircuit->Range(-30,-20,30,20);
  CCircuit->SetEditable(false);
  CiVFO2->AddFrame(EC2,new TGLayoutHints(kLHintsNormal,0,0,0));
  //\end{PadCircuit}=======================================================================  */

  //Group Frames 
  GFDraw = new TGHorizontalFrame(VFPar,1,1,1); 
  
  GF2 = new TGGroupFrame(VFPar,"Parameters",kHorizontalFrame);  
  GF2->SetTitlePos(TGGroupFrame::kLeft); 
  
  GF1 = new TGGroupFrame(VFPar,"Frequence [Hz]",kHorizontalFrame); 
  GF1->SetTitlePos(TGGroupFrame::kLeft); 
  
  GF3 = new TGGroupFrame(VFPar,"Voltage [V]",kHorizontalFrame); 
  GF3->SetTitlePos(TGGroupFrame::kLeft); 
    
  //NumberBox Physcis Variables_________________________________________________________________ 
    
  GChVc = new TGHorizontalFrame(GF3,0); 
  lVc = new TGLabel(GChVc,"Vo"); 
  NEV0 = new TGNumberEntry(GChVc,1); 
  NEV0->SetNumStyle(TGNumberFormat::kNESRealOne); 
  NEV0->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  GChVc->AddFrame(lVc, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GChVc->AddFrame(NEV0, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 

  GChVf = new TGHorizontalFrame(GF3,0); 
  lVf = new TGLabel(GChVf,"Vf"); 
  NEVf = new TGNumberEntry(GChVf,1); 
  NEVf->SetNumStyle(TGNumberFormat::kNESRealOne); 
  NEVf->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  GChVf->AddFrame(lVf, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GChVf->AddFrame(NEVf, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  
  GChVd = new TGHorizontalFrame(GF3,0); 
  ldV = new TGLabel(GChVd,"Steps"); 
  NESV = new TGNumberEntry(GChVd,2); 
  NESV->SetNumStyle(TGNumberFormat::kNESInteger); 
  NESV->SetNumAttr(TGNumberFormat::kNEANonNegative);
  NESV->SetNumLimits(TGNumberFormat::kNELLimitMinMax); 
  NESV->SetLimitValues(2,5); 
  GChVd->AddFrame(ldV, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GChVd->AddFrame(NESV, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  
  GChfc = new TGHorizontalFrame(GF1,0); 
  lfc = new TGLabel(GChfc,"fo"); 
  NEf0 = new TGNumberEntry(GChfc,1); 
  NEf0->SetNumStyle(TGNumberFormat::kNESRealOne); 
  NEf0->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  GChfc->AddFrame(lfc, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GChfc->AddFrame(NEf0, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 

  GChff = new TGHorizontalFrame(GF1,0); 
  lff = new TGLabel(GChff,"ff"); 
  NEff = new TGNumberEntry(GChff,1); 
  NEff->SetNumStyle(TGNumberFormat::kNESRealOne); 
  NEff->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  GChff->AddFrame(lff, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GChff->AddFrame(NEff, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  
  GChfd = new TGHorizontalFrame(GF1,0); 
  ldf = new TGLabel(GChfd,"Steps"); 
  NESF = new TGNumberEntry(GChfd,2); 
  NESF->SetNumStyle(TGNumberFormat::kNESInteger); 
  NESF->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  NESF->SetNumLimits(TGNumberFormat::kNELLimitMinMax); 
  NESF->SetLimitValues(2,5);
  GChfd->AddFrame(ldf, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GChfd->AddFrame(NESF, new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  
  GCht0 = new TGHorizontalFrame(GF2,0); 
  lt0 = new TGLabel(GCht0,"t0"); 
  NEt0 = new TGNumberEntry(GCht0,0.0); 
  NEt0->SetNumStyle(TGNumberFormat::kNESRealOne); 
  NEt0->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  GCht0->AddFrame(lt0,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  GCht0->AddFrame(NEt0,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  
  GChtf = new TGHorizontalFrame(GF2,0); 
  ltf  = new TGLabel(GChtf,"tf"); 
  NEtf = new TGNumberEntry(GChtf,2.5); 
  NEtf->SetNumStyle(TGNumberFormat::kNESRealOne); 
  NEtf->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  GChtf->AddFrame(ltf,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  GChtf->AddFrame(NEtf,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  
  GChiC = new TGHorizontalFrame(GF2,0); 
  liC = new TGLabel(GChiC,"q0"); 
  NEiC = new TGNumberEntry(GChiC,0.1); 
  NEiC->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  NEiC->SetNumStyle(TGNumberFormat::kNESRealOne); 
  GChiC->AddFrame(liC,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  GChiC->AddFrame(NEiC,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  
  GChnd = new TGHorizontalFrame(GF2,0); 
  lnd = new TGLabel(GChnd,"n_r"); 
  NEnd = new TGNumberEntry(GChnd,1000); 
  NEnd->SetNumStyle(TGNumberFormat::kNESReal); 
  NEnd->SetNumAttr(TGNumberFormat::kNEANonNegative); 
  NEnd->SetNumLimits(TGNumberFormat::kNELLimitMinMax); 
  NEnd->SetLimitValues(500,2000);
  GChnd->AddFrame(lnd,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  GChnd->AddFrame(NEnd,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 

  GChSave = new TGHorizontalFrame(VFPar,0); 
  CBSave= new TGCheckButton(GChSave,"Save");
  CBSave->Connect("Clicked()","WMainApp",this,"SaveClicked()");
  TESave = new TGTextEntry(GChSave);
  TESave->SetDefaultSize(250,20);
  TESave->SetEnabled(false);
  GChSave->AddFrame(CBSave);
  GChSave->AddFrame(TESave);
    
  //Add sons and parents________________________________________________________________________
  GF3->AddFrame(GChVc, new TGLayoutHints(kLHintsCenterX,10,2,2,2)); 
  GF3->AddFrame(GChVf, new TGLayoutHints(kLHintsCenterX,10,2,2,2)); 
  GF3->AddFrame(GChVd, new TGLayoutHints(kLHintsCenterX,10,2,2,2)); 
  GF1->AddFrame(GChfc, new TGLayoutHints(kLHintsCenterX,10,2,2,2)); 
  GF1->AddFrame(GChff, new TGLayoutHints(kLHintsCenterX,10,2,2,2)); 
  GF1->AddFrame(GChfd, new TGLayoutHints(kLHintsCenterX,10,2,2,2)); 
   
  GF2->AddFrame(GCht0,new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GF2->AddFrame(GChtf,new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GF2->AddFrame(GChiC,new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  GF2->AddFrame(GChnd,new TGLayoutHints(kLHintsCenterX,2,2,2,2)); 
  
  VFPar->AddFrame(GF3,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  VFPar->AddFrame(GF1,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  VFPar->AddFrame(GF2,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  VFPar->AddFrame(GChSave,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 

  HF->AddFrame(CiVFO1,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  HF->AddFrame(CiVFO2,new TGLayoutHints(kLHintsCenterX,3,3,3,3)); 
  HF->AddFrame(VFO,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  kMesh=0;
  kDevice=0;
  kWire=0;
  kParel=1000;
  kUDPa=false;
  kR=0;
  kC=0;
  kL=0;
  kRm=0;
  kCm=0;
  kLm=0;

  voltage = new TVoltage(-20,0,WMainApp::GetSignal(),'p',0);
  CCircuit->SetEditable(true);
  voltage->Draw();
  CCircuit->SetEditable(false);
  save = new VSave();
  Count = new TTimer(0.1,true);
  WScript = new TTimer(0.1,true);
  Count->Connect("Timeout()","WMainApp",this,"CreateScript()");
 
  VFMain->AddFrame(HF,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  VFMain->AddFrame(VFPar,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  TMF1->AddFrame(VFMain,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  TMF1->MapSubwindows();
  TMF1->Resize(TMF1->GetDefaultSize());
  TMF1->MapWindow();
}

void WMainApp::SignalTypeSelect(){
  CCircuit->cd();
  TGButton *btn2 = (TGButton *) gTQSender;
  Int_t id = btn2->WidgetId();
  if (id == 0){ CiRBSignal[1]->SetState(kButtonUp); CiRBSignal[2]->SetState(kButtonUp);}
  if (id == 1){ CiRBSignal[0]->SetState(kButtonUp); CiRBSignal[2]->SetState(kButtonUp);}
  if (id == 2){ CiRBSignal[0]->SetState(kButtonUp); CiRBSignal[1]->SetState(kButtonUp);}
  CCircuit->SetEditable(true);
  voltage->SetSignal(WMainApp::GetSignal());
  voltage->Draw();
  CCircuit->Update();
  CCircuit->SetEditable(false);
}

Int_t WMainApp::GetSignal(){ 
  if(CiRBSignal[0]->GetState()==true){kIDSignal=0;}
  if(CiRBSignal[1]->GetState()==true){kIDSignal=1;}
  if(CiRBSignal[2]->GetState()==true){kIDSignal=2;}
  return kIDSignal;
}

void WMainApp::SaveVariables(){
  save->Setff0(double(NEf0->GetNumber())); 
  save->SetfV0(double(NEV0->GetNumber())); 
  save->Setfff(double(NEff->GetNumber())); 
  save->SetfVf(double(NEVf->GetNumber())); 
  save->SetfStepF(double(NESF->GetNumber())); 
  save->SetfStepV(double(NESV->GetNumber())); 
  save->SetfDeltaF(double((NEff->GetNumber()- NEf0->GetNumber())/(NESF->GetNumber()-1))); 
  save->SetfDeltaV(double((NEVf->GetNumber()- NEV0->GetNumber())/(NESV->GetNumber()-1))); 
  save->Setfq0(double(NEiC->GetNumber()));
  save->Setft0(double(NEt0->GetNumber())); 
  save->Setftf(double(NEtf->GetNumber())); 
  save->Setff(double(NEf0->GetNumber())); 
  save->Setfv(double(NEV0->GetNumber())); 
  save->SetfnPoints(NEnd->GetNumber()); 
}

/*
void WMainApp::CiRBPlaceClicked(){
  TGButton *btn1 = (TGButton *) gTQSender;
  int id = btn1->WidgetId();
  if (id == 0){ CiRB2->SetState(kButtonUp);}
  if (id == 1){ CiRB1->SetState(kButtonUp);}
  }*/

void WMainApp::CiDraw(){
  CCircuit->SetEditable(true);
  TGButton *btn = (TGButton *) gTQSender;
  kIDDev = btn->WidgetId();

  //MESH_REVIEW
  /* TPTMesh = new TPaveText(-0.5,.5,2.5,3.5); */
  /* TPTMesh->AddText("1"); */
  /* TPTMesh->Draw(); */
    
  CCircuit->cd();
  Char_t Device;
  
  if(kIDDev==0){
    kR++;
    Device ='r';
    Double_t fkR;
    WCResistor *WRes = new WCResistor(gClient->GetRoot(),TMF1); 
    fkR= WRes->GetfkR();
    save->AddResistor(fkR,kR);
    variables << "#name: R"<<kR<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfkR(kR) << endl;
    CiPBC->SetEnabled(true);
    CiPBMC->SetEnabled(true);
    CiPBL->SetEnabled(true);
    CiPBML->SetEnabled(true);
  };

  if(kIDDev==1){ 
    kL++;
    Device ='l';
    Double_t fkL;
    WCInductor *WInd = new WCInductor(gClient->GetRoot(),TMF1);
    fkL= WInd->GetfkL();
    save->AddInductor(fkL,kL);
    variables << "#name: L"<<kL<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfkL(kL) << ";" << endl;
    //    variables << "Xl=" << 2*PI*f*save->GetfkL(kL) << ";" << endl;  // Reactancia Inductiva
  }

  if(kIDDev==2){
    kC++;
    Device ='c';
    Double_t fkC;
    WCCapacitor *WCap = new WCCapacitor(gClient->GetRoot(),TMF1);
    fkC= WCap->GetfkC();
    save->AddCapacitor(fkC,kC);
    variables << "#name: C"<<kC<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfkC(kC) << ";" << endl;
    /*
    if(save->GetfkC()==0){
      variables << "Xc=" << 0 << ";" << endl;
    }
    else{
      variables << "Xc=" << - 1/(2*PI*f*save->GetfkC()) << ";" << endl;
    }
    */   //Reactancia Capacitiva
  }

  if(kIDDev==3){
    kRm++;
    Device ='R'; 
    Double_t fa,fb,fc;
    WCMemristor *WMemris = new WCMemristor(gClient->GetRoot(),TMF1); 
    fa= WMemris->GetfaMR();
    fb= WMemris->GetfbMR();
    fc= WMemris->GetfcMR();
    save->AddMemristor(WMemris->GetIDSelect(),fa,fb,fc,kRm);
    variables << "#name: aRm"<<kRm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfaRm(kRm)<<endl;
    variables << "#name: bRm"<<kRm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfbRm(kRm)<<endl;
    variables << "#name: cRm"<<kRm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfcRm(kRm)<<endl;
    CiPBC->SetEnabled(true);
    CiPBMC->SetEnabled(true);
    CiPBL->SetEnabled(true);
    CiPBML->SetEnabled(true);
  }

  if(kIDDev==4){
    kLm++;
    Device ='L'; 
    Double_t fa,fb,fc; 
    WCMeminductor *WMemind = new WCMeminductor(gClient->GetRoot(),TMF1);  
    fa= WMemind->GetfaML(); 
    fb= WMemind->GetfbML(); 
    fc= WMemind->GetfcML(); 
    save->AddMeminductor(WMemind->GetIDSelect(),fa,fb,fc,kLm); 
    variables << "#name: aLm"<<kLm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfaLm(kLm)<<endl;
    variables << "#name: bLm"<<kLm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfbLm(kLm)<<endl;
    variables << "#name: cLm"<<kLm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfcLm(kLm)<<endl;
  }

  if(kIDDev==5){
    kCm++;
    Device ='C';
    Double_t fa,fb,fc;
    WCMemcapacitor *WMemcap = new WCMemcapacitor(gClient->GetRoot(),TMF1); 
    fa= WMemcap->GetfaMC();
    fb= WMemcap->GetfbMC();
    fc= WMemcap->GetfcMC();
    save->AddMemcapacitor(WMemcap->GetIDSelect(),fa,fb,fc,kCm);
    variables << "#name: aCm"<<kCm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfaCm(kCm)<<endl;
    variables << "#name: bCm"<<kCm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfbCm(kCm)<<endl;
    variables << "#name: cCm"<<kCm<<endl;
    variables << "#type: scalar"<<endl;
    variables << save->GetfcCm(kCm)<<endl;
    CiPBMR->SetState(kButtonDisabled);
  }

  //cout<<"Mesh: "<<kMesh<<endl;
  //cout<<"Device: "<<kDevice<<endl;

  //  if( CiRB1->IsDown() ){ 
  if(true){
    if(kDevice==0){
      dev[kDevice][kMesh]= new TCirDevice(voltage->GetP1()->GetX()+7,-5,Device,'s');
      dev[kDevice][kMesh]->Draw();
      kDevice++;
      wire[kWire]= new TWire(dev[kDevice-1][kMesh],voltage);
      kWire++;	  
      wire[kWire]= new TWire(voltage,dev[kDevice-1][kMesh]);
      kWire++;
      CiResize(dev[kDevice-1][kMesh]->GetP2()->GetX());
      CiTGBRun->SetEnabled(true);
    }
    else{
      if(kUDPa==true){ //kParel!=1000
   	//sprintf(Label,"M%i",kDevice+1);
   	//CBDev->AddEntry(Label,kDevice+1);
   	dev[kDevice][kMesh]= new TCirDevice(dev[kDevice-1][kMesh]->GetP2()->GetX()+7,dev[kDevice-1][kMesh]->GetP2()->GetY(),Device,'s');
   	dev[kDevice][kMesh]->Draw();  
   	kDevice++;
	wire[kWire]= new TWire(dev[kDevice-2][kMesh],dev[kDevice-1][kMesh]);
	kWire++;    
	wire[kWire]= new TWire(dev[kDevice-1][kMesh],dev[kDevice-2][kMesh]);
	kWire++;
	CiResize(dev[kDevice-1][kMesh]->GetP2()->GetX()+10);
      }
      else{
   	dev[kDevice][kMesh]= new TCirDevice(dev[kDevice-1][kMesh]->GetP2()->GetX()+7,dev[kDevice-1][kMesh]->GetP2()->GetY(),Device,'s');
    	dev[kDevice][kMesh]->Draw();  
   	//sprintf(Label,"M%i",kDevice+1);
   	//CBDev->AddEntry(Label,kDevice+1);
   	kDevice++;
	delete  wire[kWire-1];
	wire[kWire]= new TWire(dev[kDevice-2][kMesh],dev[kDevice-1][kMesh]);
	kWire++;    
	wire[kWire]= new TWire(voltage,dev[kDevice-1][kMesh]);
	kWire++;
     	CiResize(dev[kDevice-2][kMesh]->GetP2()->GetX()+10);
      }
    }
    kUDPa=false;
  }
  
  //  if(CiRB2->IsDown()){
  if(false){
    if(kParel==1000){
      kDevMesh[kMesh]= kDevice+1;
    }
    else{
      kDevMesh[kMesh]= kDevice-kParel+1;
    }
    kUDPa=true;
    cout<<"MeshClose"<<endl;
    cout<<"N. Mesh: "<<kDevMesh[kMesh]<<endl;
    kMesh++;
    kParel=kDevice;
    if(kDevice==0){
      dev[kDevice][kMesh]= new TCirDevice(voltage->GetP1()->GetX()+7,0,Device,'p');
      dev[kDevice][kMesh]->Draw();
      kDevice++;
      wire[kWire]= new TWire(dev[kDevice-1][kMesh],voltage);
      kWire++;
      wire[kWire]= new TWire(voltage,dev[kDevice-1][kMesh]);
      kWire++;
    } 
    else{
      dev[kDevice][kMesh]= new TCirDevice(dev[kDevice-1][kMesh-1]->GetP2()->GetX()+7,0,Device,'p');  
      dev[kDevice][kMesh]->Draw();  
      kDevice++;
      if(dev[kDevice-2][kMesh-1]->GetPlace()=='s'){
	delete wire[kWire-1];
	wire[kWire]= new TWire(dev[kDevice-1][kMesh],voltage); 
	kWire++;  
	wire[kWire]= new TWire(dev[kDevice-1][kMesh],dev[kDevice-2][kMesh-1]); 
	kWire++;	   
      }
      else{
	wire[kWire]= new TWire(dev[kDevice-1][kMesh],voltage); 
	kWire++;  
	wire[kWire]= new TWire(dev[kDevice-2][kMesh-1],dev[kDevice-1][kMesh]); 
	kWire++;	   
      }
      CiResize(dev[kDevice-1][kMesh]->GetP2()->GetX());
    }
  }
  CCircuit->Update();
  CCircuit->SetEditable(false);
}
 
void WMainApp::CiResize(Int_t X){
  Int_t Max_x = CCircuit->GetXsizeReal();
  if(X>Max_x){
    CCircuit->Range(-30,-20,X+10,20);
    CCircuit->Update();
  }
}

void WMainApp::CiOpen(){
  cout<<"Open TBrowser"<<endl;
  TB1 = new TBrowser();
}

void WMainApp::ClearScript(){
  script.close();
  //  script.open("mem.m");
}

void WMainApp::CiClear(){
  WMainApp::ClearScript();
  variables.close();
  variables.open("/tmp/var.mat"); 
  CCircuit->SetEditable(true);
  kDevice=0;
  kMesh=0;
  kWire=0;
  kUDPa=false;
  kParel=1000;
  kColor=1;
  kR=0;
  kL=0;
  kC=0;
  kRm=0;
  kLm=0;
  kCm=0;
  for(Int_t i=0;i<=20;i++)  kDevMesh[i]=0;
  save->Clear();
  CCircuit->Clear();
  CCircuit->Range(-30,-20,30,20);
  CCircuit->Update();
  save->SetfkIdR(0);
  save->SetfkIdC(0);
  save->SetfkIdL(0);
  save->SetfkIdRm(0);
  save->SetfkIdCm(0);
  save->SetfkIdLm(0);
  voltage->SetSignal(WMainApp::GetSignal());
  voltage->Draw();
  CCircuit->Update();
  CCircuit->SetEditable(false);
  CiPBC->SetEnabled(false);
  CiPBMC->SetEnabled(false);
  CiPBL->SetEnabled(false);
  CiPBML->SetEnabled(false);
  CiPBMR->SetEnabled(true);
  CiTGBRun->SetState(kButtonDisabled);
}

void WMainApp::Run(){
  if(kDevice==0){cout<<"You didn't included Devices to Pad."<<endl;}
  else{
    kColor=1;
    WCPro = new WCProcessing(gClient->GetRoot(),TMF1);
    WMainApp::SaveVariables(); 
    f = save->Getfff(); 
    V = save->GetfVf();   
    script << "load /tmp/var.mat;"<<endl;
    WMainApp::CreateScript();
  }
}

void WMainApp::CreateScript(){  
  Count->TurnOn();
  script << "f=" << f << ";" << endl;
  script << "V=" << V << ";" << endl;
  script << "t0=" << save->Getft0() << ";" << endl;
  script << "tf=" << save->Getftf() << ";" << endl;
  script << "q0=" << save->Getfq0() << ";" << endl;
  script << "omega=2*pi*f;" << endl;
  script << "t = linspace(t0,tf," << save->GetfnPoints() << "); s=t';" << endl;
  
  if(kIDSignal==2){// Sin Signal
    //V
    script<<"v = @(x,t)[x(2),omega*V*cos(omega*t)];"<<endl;
    script<<"y = lsode(v,[q0 0],t);"<<endl;
    script<<"w=[s,y];"<<endl;
    //////////////////////////////////////////////////////
    //fi
    script<<"fi = @(fi,t)[fi(1),V*sin(omega*t)];"<<endl;//    
    script<<"y = lsode(fi,[q0 0],t);"<<endl;
    script<<"w=[w,y];"<<endl;
    //////////////////////////////////////////////////////
    //q
    if(save->GetfkIdLm()==0 && save->GetfkIdL()==0 && save->GetfkIdCm()==0 && save->GetfkIdC()==0){  //Rm-S
      script<<"q = @(q,t)[q(2),V*sin(omega*t)/("<<save->RmFunc3<<")];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()==0 && save->GetfkIdC()==0)){ //Rm-Lm-S
      script<<"q = @(q,t)[q(2),(-1/("<<save->LmFunc1<<"))*("<<save->RmFunc1<<")*q(2)+V*sin(omega*t)/"<<save->LmFunc1<<"];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()==0 && save->GetfkIdL()==0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ //Rm-Cm-S
      script<<"q = @(q,t)[q(1),(V*sin(omega*t)/("<<save->RmFunc1<<"))-( q(1)/(("<<save->CmFunc1<<")*("<<save->RmFunc1<<")))];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ //Memcapacitor-Memductor-Memristor-Source
      script<<"q = @(q,t)[q(2),(-1/("<<save->LmFunc3<<"))*("<<save->RmFunc1<<")*q(2)-(q(1)/(("<<save->LmFunc1<<")*("<<save->CmFunc1<<")))+V*sin(omega*t)/("<<save->LmFunc3<<")];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    /////////////////////////////////////////////////////
    //i =   dq/dt  
    if(save->GetfkIdLm()==0 && save->GetfkIdL()==0 && save->GetfkIdCm()==0 && save->GetfkIdC()==0){ // Rm-S
      script<<"ic = @(q,t)[q(2),(V*omega*cos(omega*t)/("<<save->RmFunc1<< "))-(V*sin(omega*t)*("<<save->RmFunc2<<")/(("<<save->RmFunc1<<")^2))];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()==0 && save->GetfkIdC()==0)){ // RmLm
      script<<"ic = @(q,t)[q(2),(1/("<<save->LmFunc1<<")^2)*((V*sin(omega*t)*("<<save->LmFunc2<<"))+(q(2)*("<<save->RmFunc1<<")*("<<save->LmFunc2<<")))+(1/("<<save->LmFunc1<<"))*(omega*V*cos(omega*t)-q(2)*("<<save->RmFunc2<<")- q(2)*("<</*Cambiar el anterior q(2) por q(3)*/save->RmFunc1<<"))];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()==0 && save->GetfkIdL()==0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ // RmCm
      script<<"ic = @(q,t)[q(2),((-V*sin(omega*t)*("<<save->RmFunc2<<"))/("<<save->RmFunc1<<")^2) + (omega*V*cos(omega*t)/("<<save->RmFunc1<<")) + (q(1)*( ("<<save->CmFunc2<<")*("<<save->RmFunc1<<") + ("<<save->CmFunc1<<")*("<<save->RmFunc2<<") )/(("<<save->CmFunc1<<")*("<<save->RmFunc1<<"))^2) - (q(2)/( ("<<save->RmFunc1<<")*("<<save->CmFunc1<<"))) ];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){//  RmCmLm
       script<<"ic = @(q,t)[q(2),(1/("<<save->LmFunc1<<")^2)*((V*sin(omega*t)*("<<save->LmFunc2<<"))+(q(2)*("<<save->RmFunc1<<")*("<<save->LmFunc2<<")))+(1/("<<save->LmFunc1<<"))*(omega*V*cos(omega*t)-q(2)*("<<save->RmFunc2<<")- q(2)*("<</*Cambiar el anterior q(2) por q(3)*/save->RmFunc1<<")) ];"<<endl;
      // - (q(2)*("<<save->LmFunc1<<")*("<<save->CmFunc1<<") - q(1)( ("<<save->LmFunc2<<")*("<<save->CmFunc1<<") +  ("<<save->LmFunc1<<")*("<<save->CmFunc2<<")  ))/(("<<save->LmFunc1<<")*("<<save->CmFunc1<<"))^2
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    //////////////////////////////////////////////////////
  }
  
  if(kIDSignal==1){ //Cuadrado
    //V
    script << "v = @(x,t)[x(1),(4*omega*V/(pi))*(0";
    for(int j=1;j<=50;j=j+2){
      script<<"+cos("<<j<<"*omega*t)";
    }
    script << ")];" << endl;
    script << "y= lsode(v,[q0 0],t);" << endl;
    script << "w=[s,y];" << endl;
    //////////////////////////////////////////////////////
    //fi
    script << "fi = @(fi,t)[fi(1),(4*V/(pi))*(0";
    for(int j=1;j<=50;j+=j+2){
      script<< "+sin("<<j<<"*omega*t)/"<<j;
    }
    script<<")];" << endl;
    script << "y = lsode(fi,[q0 0],t);" << endl;
    script << "w=[w,y];" << endl;
    //////////////////////////////////////////////////////
    //q
    if(save->GetfkIdLm()==0 && save->GetfkIdL()==0 && save->GetfkIdCm()==0 && save->GetfkIdC()==0){   //Rm-S
      script << "q =@(q,t)[q(2),V*(4/(pi)*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script << "))/("<<save->RmFunc3<<")];" << endl;
      script << "y = lsode(q,[q0 0],t);" << endl;
      script << "w=[w,y];" << endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()==0 && save->GetfkIdC()==0)){   //Rm-Lm-S
      script<<"q = @(q,t)[q(2),(-1/("<<save->LmFunc1<<"))*("<<save->RmFunc1<<")*q(2)+V*(4/(pi)*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script<<"))/("<<save->LmFunc1<<")];" << endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()==0 && save->GetfkIdL()==0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ // Cm-Rm-S
      script<<"q = @(q,t)[q(1),(V*(4/(pi)*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script<<"))/("<<save->RmFunc1<<"))-(q(1)/(("<<save->CmFunc1<<")*("<<save->RmFunc1<<")))];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ //Memcapacitor-Memductor-Memristor-Source
      script<<"q = @(q,t)[q(2),(-1/("<<save->LmFunc3<<"))*("<<save->RmFunc1<<")*q(2)-(q(1)/(("<<save->LmFunc1<<")*("<<save->CmFunc1<<")))+V*(4/(pi)*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script<<"))/("<<save->LmFunc3<<")];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    //////////////////////////////////////////////////////
    //i
    if(save->GetfkIdLm()==0 && save->GetfkIdL()==0 && save->GetfkIdCm()==0 && save->GetfkIdC()==0){ //Rm-S  
      script<<"ic = @(q,t)[q(2),(4*omega*V/(pi))*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)";
      }
      script <<")/("<<save->RmFunc1<< ")-(V*(4/(pi)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script <<")*("<<save->RmFunc2<<"))/(("<<save->RmFunc1<< ")^2))];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()==0 && save->GetfkIdC()==0)){// RmLm
      script<<"ic = @(q,t)[q(2),(1/("<<save->LmFunc1<<")^2)*(V*(4/(pi)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script <<")*("<<save->LmFunc2<<"))+(q(2)*("<<save->RmFunc1<<")*("<<save->LmFunc2<<")))+(1/("<<save->LmFunc1<<"))*(4*omega*V/(pi))*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)";
      }
      script <<")-q(2)*("<<save->RmFunc2<<")- q(2)*("<</*Cambiar el anterior q(2) por q(3)*/save->RmFunc1<<")];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()==0 && save->GetfkIdL()==0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ // RmCm
      script<<"ic = @(q,t)[q(2),(-V*4/(pi)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script <<")*("<<save->RmFunc2<<")/("<<save->RmFunc1<<")^2) + (4*omega*V/(pi))*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)";
      }
      script <<")/("<<save->RmFunc1<<") + (q(1)*( ("<<save->CmFunc2<<")*("<<save->RmFunc1<<") + ("<<save->CmFunc1<<")*("<<save->RmFunc2<<") )/(("<<save->CmFunc1<<")*("<<save->RmFunc1<<"))^2) - (q(2)/( ("<<save->RmFunc1<<")*("<<save->CmFunc1<<"))) ];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){//  RmCmLm
      script<<"ic = @(q,t)[q(2),(1/("<<save->LmFunc1<<")^2)*((V*4/(pi)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+sin("<<j<<"*omega*t)/("<<j<<")";
      }
      script <<")*("<<save->LmFunc2<<"))+(q(2)*("<<save->RmFunc1<<")*("<<save->LmFunc2<<")))+(1/("<<save->LmFunc1<<"))*((4*omega*V/(pi))*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)";
      }
      script <<")-q(2)*("<<save->RmFunc2<<")- q(2)*("<</*Cambiar el anterior q(2) por q(3)*/save->RmFunc1<<")) ];"<<endl;
      // - (q(2)*("<<save->LmFunc1<<")*("<<save->CmFunc1<<") - q(1)( ("<<save->LmFunc2<<")*("<<save->CmFunc1<<") +  ("<<save->LmFunc1<<")*("<<save->CmFunc2<<")  ))/(("<<save->LmFunc1<<")*("<<save->CmFunc1<<"))^2
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
  }
 ///////////=====================================================================================================================

  if(kIDSignal==0){//Diente de Sierra
    //V
    script << "v = @(x,t)[x(1),(2*omega*V)*(0";
    for(int j=1;j<=50;j=j+2){
      script<<"+cos(omega*"<<j<<"*t)-cos("<<j+1<<"*omega*t)";
    }
    script<<")];" << endl;
    script << "y = lsode(v,[q0 0],t);" << endl;
    script << "w=[s,y];" << endl;
    //////////////////////////////////////////////////////
    //fi
    int k=0;
    script << "fi =@(x,t)[x(2),V*(0";
    for(int j=1;j<=50;j=j+2){
      k++;
      script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-sin(2*"<<k<<"*omega*t)/"<<k; 
    }
    script<<")];" << endl;
    script << "y = lsode(fi,[q0 0],t);" << endl;
    script << "w=[w,y];" << endl;
    //////////////////////////////////////////////////////
    //q
    if(save->GetfkIdLm()==0 && save->GetfkIdL()==0 && save->GetfkIdCm()==0 && save->GetfkIdC()==0){ //Rm-S
      script << "q =@(q,t)[q(2),V*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")/("<<save->RmFunc3<<")];" << endl;
      script << "y = lsode(q,[q0 0],t);" << endl;
      script << "w=[w,y];" << endl;     
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()==0 && save->GetfkIdC()==0)){ //Lm-Rm
      script<<"q = @(q,t)[q(2),(-1/("<<save->LmFunc1<<"))*("<<save->RmFunc1<<")*q(2)+V*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")/"<<save->LmFunc1<<"];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()==0 && save->GetfkIdL()==0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ //Cm-Rm
      script<<"q = @(q,t)[q(1),(V*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")/("<<save->RmFunc1<<"))-(q(1)/(("<<save->CmFunc1<<")*("<<save->RmFunc1<<")))];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ //Cm-Lm-Rm
      script<<"q = @(q,t)[q(2),(-1/("<<save->LmFunc3<<"))*("<<save->RmFunc1<<")*q(2)-(q(1)/(("<<save->LmFunc1<<")*("<<save->CmFunc1<<")))+V*(0";
      for(Int_t j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")/("<<save->LmFunc3<<")];"<<endl;
      script<<"y = lsode(q,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    //////////////////////////////////////////////////////
    //i
    if(save->GetfkIdLm()==0 && save->GetfkIdL()==0 && save->GetfkIdCm()==0 && save->GetfkIdC()==0){ // Rm-S
      script<<"ic = @(q,t)[q(2),((2*omega*V)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)-cos("<<j+1<<"*omega*t)";
      }
      script << ")/("<<save->RmFunc1<< "))-(V*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")*"<<save->RmFunc2<<"/(("<<save->RmFunc1<< ")^2))];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()==0 && save->GetfkIdC()==0)){ // RmLm
      script<<"ic = @(q,t)[q(2),(1/("<<save->LmFunc1<<")^2)*(V*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")*("<<save->LmFunc2<<")+(q(2)*("<<save->RmFunc1<<")*("<<save->LmFunc2<<")))+(1/("<<save->LmFunc1<<"))*((2*omega*V)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)-cos("<<j+1<<"*omega*t)";
      }
      script << ")-q(2)*("<<save->RmFunc2<<")- q(2)*("<</*Cambiar el anterior q(2) por q(3)*/save->RmFunc1<<"))];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()==0 && save->GetfkIdL()==0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){ // CmRm
      script<<"ic = @(q,t)[q(2),(-V*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")*("<<save->RmFunc2<<")/("<<save->RmFunc1<<")^2) + (2*omega*V)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)-cos("<<j+1<<"*omega*t)";
      }
      script << ")/("<<save->RmFunc1<<") + (q(1)*( ("<<save->CmFunc2<<")*("<<save->RmFunc1<<") + ("<<save->CmFunc1<<")*("<<save->RmFunc2<<") )/(("<<save->CmFunc1<<")*("<<save->RmFunc1<<"))^2) - (q(2)/( ("<<save->RmFunc1<<")*("<<save->CmFunc1<<"))) ];"<<endl;
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
    if((save->GetfkIdLm()!=0 || save->GetfkIdL()!=0) && (save->GetfkIdCm()!=0 || save->GetfkIdC()!=0)){//  RmCmLm
      script<<"ic = @(q,t)[q(2),(1/("<<save->LmFunc1<<")^2)*((V*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+2*sin("<<j<<"*omega*t)/("<<j<<")-2*sin("<<j+1<<"*omega*t)/("<<j+1<<")";
      }
      script << ")*("<<save->LmFunc2<<"))+(q(2)*("<<save->RmFunc1<<")*("<<save->LmFunc2<<")))+(1/("<<save->LmFunc1<<"))*((2*omega*V)*(0";
      for(int j=1;j<=50;j=j+2){
	script<<"+cos("<<j<<"*omega*t)-cos("<<j+1<<"*omega*t)";
      }
      script << ")-q(2)*("<<save->RmFunc2<<")- q(2)*("<</*Cambiar el anterior q(2) por q(3)*/save->RmFunc1<<")) ];"<<endl;
      // - (q(2)*("<<save->LmFunc1<<")*("<<save->CmFunc1<<") - q(1)( ("<<save->LmFunc2<<")*("<<save->CmFunc1<<") +  ("<<save->LmFunc1<<")*("<<save->CmFunc2<<")  ))/(("<<save->LmFunc1<<")*("<<save->CmFunc1<<"))^2
      script<<"y = lsode(ic,[q0 0],t);"<<endl;
      script<<"w=[w,y];"<<endl;
    }
  }
  script << " delete /tmp/dtest.dat"<<endl;
  script << "dlmwrite('/tmp/dtest.dat',w,' ');\n"<<endl;
  system("octave -q /tmp/mem.m");  //Execute Script Octave */


  if(kColor==1){
    TString SFile = TESave->GetDisplayText()+".root";
    if(CBSave->IsOn()==true){
      Graphs = new WCGraphs(gClient->GetRoot(),TMF1,true,SFile);
    }
    else{
      Graphs = new WCGraphs(gClient->GetRoot(),TMF1,false,SFile);
    }
  }

  Graphs->SetN(save->GetfnPoints());
  Graphs->SetV(V);
  Graphs->Setf(f);
  Graphs->Draw(kColor);

  kColor++;  
  if(V > save->GetfV0()){
    V = V - save->GetfDeltaV();
  }
  else{
    if(f > save->Getff0()){
      f= f - save->GetfDeltaF();
      V=save->GetfVf();
    }  
    else{
      WCPro->Close();
      Graphs->SetHidden(false);
      WMainApp::ClearScript();
      Count->TurnOff();
      CBSave->SetDown(false);
      TESave->SetEnabled(false);
    }
  }
}

void WMainApp::SaveClicked(){
  if(CBSave->IsOn()==true){
    CBSave->SetDown(true); 
    TESave->SetEnabled(true);
  }
  if(CBSave->IsOn()==false){
    CBSave->SetDown(false);
    TESave->SetEnabled(false);
  }
}

void WMainApp::Stop(){
  Count->TurnOff();
  Count->Reset();
}

WMainApp::~WMainApp(){
  delete TMF1;
}

