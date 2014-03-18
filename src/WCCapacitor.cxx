#include "WCCapacitor.h"

WCCapacitor::WCCapacitor(const TGWindow *p,const TGWindow *main){

  fWCCapacitor = new TGTransientFrame(p,main);
  fWCCapacitor->SetWMSizeHints(120,70,120,70,0,0);
  fWCCapacitor->SetWindowName("Add Capacitor");
  fWCCapacitor->SetCleanup(kDeepCleanup);
  fWCCapacitor->SetIconPixmap("../icons/capacitor.png");    

  GF4 = new TGVerticalFrame(fWCCapacitor,0);   

  GChC = new TGHorizontalFrame(GF4,0);  
  lkC = new TGLabel(GChC,"C[mF]"); 
  NEkC = new TGNumberEntry(GChC,0.5);  
  NEkC->SetState(true); 
  NEkC->SetNumAttr(TGNumberFormat::kNEANonNegative);  
  GChC->AddFrame(lkC, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 
  GChC->AddFrame(NEkC, new TGLayoutHints(kLHintsLeft,2,2,2,2)); 

  GButton = new TGHorizontalFrame(GF4,0);  

  TBAdd = new TGTextButton(GButton,"&Add",1);
  TBAdd->Connect("Clicked()","WCCapacitor",this,"TBAddClicked()");
  
  GButton->AddFrame(TBAdd, new TGLayoutHints(kLHintsCenterX,2,2,2,2));

  GF4->AddFrame(GChC, new TGLayoutHints(kLHintsLeft,1,1,1,1));
  GF4->AddFrame(GButton,new TGLayoutHints(kLHintsCenterX,3,3,3,3));

  fWCCapacitor->AddFrame(GF4,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCCapacitor->MapSubwindows();
  fWCCapacitor->MapWindow();

  gClient->WaitFor(fWCCapacitor);
}

void WCCapacitor::TBAddClicked(){
  fkC= (double)NEkC->GetNumber()/1000;
  fWCCapacitor->CloseWindow();
}

WCCapacitor::~WCCapacitor(){
  delete fWCCapacitor; 
}
