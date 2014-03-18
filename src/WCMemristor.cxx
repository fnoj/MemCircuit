#include "WCMemristor.h"

WCMemristor::WCMemristor(const TGWindow *p,const TGWindow *main){

  fWCMemristor = new TGTransientFrame(p,main);
  fWCMemristor->SetWMSizeHints(300,180,300,180,0,0);
  fWCMemristor->SetWindowName("Add Memristor");
  fWCMemristor->SetCleanup(kDeepCleanup);
  fWCMemristor->SetIconPixmap("../icons/memristor.png");    

  GF4 = new TGVerticalFrame(fWCMemristor,0); 

  VBGMem = new TGVButtonGroup(GF4, "Memristor Group"); 
  RBMemristor[0] = new TGRadioButton(VBGMem,"a*exp(b*q)",0);  
  RBMemristor[0]->Connect("Clicked()","WCMemristor",this,"RBMemClicked()");   
  RBMemristor[1] = new TGRadioButton(VBGMem,"a + b*q^2",1);  
  RBMemristor[1]->Connect("Clicked()","WCMemristor",this,"RBMemClicked()");   
  RBMemristor[2] = new TGRadioButton(VBGMem,"a + b*q",2);  
  RBMemristor[2]->Connect("Clicked()","WCMemristor",this,"RBMemClicked()");   
  RBMemristor[3] = new TGRadioButton(VBGMem,"a + b*q^2 + c*q^4 ...",3);  
  RBMemristor[3]->Connect("Clicked()","WCMemristor",this,"RBMemClicked()");   
  RBMemristor[4] = new TGRadioButton(VBGMem,"a",4);  
  RBMemristor[4]->Connect("Clicked()","WCMemristor",this,"RBMemClicked()");   
  
  GChCoe = new TGHorizontalFrame(VBGMem,0);  
  
  GCha = new TGHorizontalFrame(GChCoe,0);  
  la = new TGLabel(GCha,"a"); 
  NEa = new TGNumberEntry(GCha,0.5);  
  NEa->SetState(true); 
  NEa->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GCha->AddFrame(la, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GCha->AddFrame(NEa, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  
  GChb = new TGHorizontalFrame(GChCoe,0);  
  lb = new TGLabel(GChb,"b"); 
  NEb = new TGNumberEntry(GChb,0.5);  
  NEb->SetState(true); 
  NEb->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChb->AddFrame(lb, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChb->AddFrame(NEb, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  
  GChc = new TGHorizontalFrame(GChCoe,0);  
  lc = new TGLabel(GChc,"c"); 
  NEc = new TGNumberEntry(GChc,0.5);  
  NEc->SetState(false); 
  NEc->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChc->AddFrame(lc, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChc->AddFrame(NEc, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  
  GChCoe->AddFrame(GCha, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  GChCoe->AddFrame(GChb, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  GChCoe->AddFrame(GChc, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  
  VBGMem->AddFrame(GChCoe, new TGLayoutHints(kLHintsCenterY | kLHintsExpandX,3,3,3,3));   
  VBGMem->Show(); 
  VBGMem->SetExclusive(true); 
  VBGMem->SetBorderDrawn(false); 

  GButton = new TGHorizontalFrame(GF4,0);  

  TBAdd = new TGTextButton(GButton,"&Add",1);
  TBAdd->Connect("Clicked()","WCMemristor",this,"TBAddClicked()");

  //  TBCancel = new TGTextButton(GButton,"&Cancel",2);
  //  TBCancel->Connect("Clicked()","WCMemristor",this,"TBCancelClicked()");
  
  GButton->AddFrame(TBAdd, new TGLayoutHints(kLHintsCenterX,2,2,2,2));
  //  GButton->AddFrame(TBCancel, new TGLayoutHints(kLHintsCenterX,2,2,2,2));

  GF4->AddFrame(VBGMem, new TGLayoutHints(kLHintsLeft,1,1,1,1));
  GF4->AddFrame(GButton,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  fWCMemristor->AddFrame(GF4,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCMemristor->MapSubwindows();
  fWCMemristor->MapWindow();

  kId=1000;

  gClient->WaitFor(fWCMemristor);
}


void WCMemristor::RBMemClicked(){
  TGButton *btn1 = (TGButton *) gTQSender;
  kId = btn1->WidgetId();
  if (kId == 0){ NEc->SetState(false); NEc->SetNumber(0); NEa->SetState(true); NEb->SetState(true);}
  if (kId == 1){ NEc->SetState(false); NEc->SetNumber(0); NEa->SetState(true); NEb->SetState(true);}
  if (kId == 2){ NEc->SetNumber(0); NEa->SetState(true); NEb->SetState(true); NEc->SetState(false);}
  if (kId == 3){ NEa->SetState(true); NEb->SetState(true); NEc->SetState(true); }
  if (kId == 4){ NEc->SetNumber(0); NEb->SetNumber(0); NEa->SetState(true); NEb->SetState(false); NEc->SetState(false); }
}

void WCMemristor::TBAddClicked(){
  faMR= (double)NEa->GetNumber();
  fbMR= (double)NEb->GetNumber();
  fcMR= (double)NEc->GetNumber();
  if(kId!=1000){
    fWCMemristor->CloseWindow();
  }
}

WCMemristor::~WCMemristor(){
  delete fWCMemristor;
}
