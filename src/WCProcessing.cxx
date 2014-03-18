#include "WCProcessing.h"

WCProcessing::WCProcessing(const TGWindow *p,const TGWindow *main){
  
  fWCProcessing = new TGTransientFrame(p,main);
  fWCProcessing->SetWMSizeHints(120,40,120,40,0,0);
  fWCProcessing->SetCleanup(kDeepCleanup);

  GF = new TGHorizontalFrame(fWCProcessing,0); 
  TLProcessing = new TGLabel(GF,"Processing ..."); 

  GF->AddFrame(TLProcessing, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY,1,1,1,1)); 

  fWCProcessing->AddFrame(GF,new TGLayoutHints(kLHintsCenterX,3,3,3,3));
  fWCProcessing->MapSubwindows();
  fWCProcessing->MapWindow();
}

void WCProcessing::Close(){
  fWCProcessing->CloseWindow();
}

WCProcessing::~WCProcessing(){
  delete fWCProcessing;
}
