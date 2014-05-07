#include "VSave.h"

VSave::VSave(){ 
  for(Int_t i=0; i<=9; i++){
    faRm[i]=0; fbRm[i]=0; fcRm[i]=0; 
    faLm[i]=0; fbLm[i]=0; fcLm[i]=0; 
    faCm[i]=0; fbCm[i]=0; fcCm[i]=0; 
    fkR[i]=0;  fkL[i]=0;  fkC[i]=0; 
  }
  ff0=0;  fV0=0; fff=0; fVf=0;  fStepF=0;  fStepV=0;  fDeltaF=0; fDeltaV=0; 
  fq0=0;
  ft0=0; ftf=0; ff=0;  fv=0;  fi=0;
  kIdL=0;
  kIdC=0; 
  kIdR=0;
  kIdRm=0;
  kIdLm=0;
  kIdCm=0;
}    

void VSave::AddMemristor(Int_t MRFunction, Double_t a, Double_t b, Double_t c,Int_t kRm){
  kIdRm++;
  TString memEq=" ", memEq2=" ", memEq3=" ";
  faRm[kIdRm]=a;   
  fbRm[kIdRm]=b;   
  fcRm[kIdRm]=c; 
  Char_t IntStr[2];
  sprintf(IntStr,"%d",kRm);
  TString StrIdRm(IntStr);

  if(MRFunction==0){
    memEq="+aRm"+StrIdRm+"*exp(bRm"+StrIdRm+"*q(1))"; 
    memEq2="+aRm"+StrIdRm+"*bRm"+StrIdRm+"*q(2)*exp(bRm"+StrIdRm+"*q(1))"; 
    memEq3="+aRm"+StrIdRm+"*exp(bRm"+StrIdRm+"*q(2))";
    if(b==0){
      RmFlux = RmFlux+"+0";
    }
    else{
      RmFlux = RmFlux+"+(aRm"+StrIdRm+"/bRm"+StrIdRm+")*(exp(bRm"+StrIdRm+"*q(1)) - exp(bRm"+StrIdRm+"*q0))";
    }
  }

  if(MRFunction==1){
    memEq="+aRm"+StrIdRm+" + bRm"+StrIdRm+"*q(1)^2"; 
    memEq2="+2*bRm"+StrIdRm+"*q(1)*q(2)"; 
    memEq3="+aRm"+StrIdRm+" + bRm"+StrIdRm+"*q(2)^2";
    if(b==0){
      RmFlux = RmFlux+"+0";
    }
    else{
      RmFlux=RmFlux+"+(aRm"+StrIdRm+"*q(1))+(bRm"+StrIdRm+"*(q(1)^3)/3) - ((aRm"+StrIdRm+"*q0)+(bRm"+StrIdRm+"*(q0^3)/3)) ";
    }
  }

  if(MRFunction==2){
    memEq="+aRm"+StrIdRm+" + bRm"+StrIdRm+"*q(1)"; 
    memEq2="+bRm"+StrIdRm+"*q(2)"; 
    memEq3="+aRm"+StrIdRm+" + bRm"+StrIdRm+"*q(2)";
    if(b==0){
      RmFlux = RmFlux+"+0";
    }
    else{
      RmFlux=RmFlux+"+(aRm"+StrIdRm+"*q(1))+(bRm"+StrIdRm+"*(q(1)^2)/2) - ((aRm"+StrIdRm+"*q0)+(bRm"+StrIdRm+"*(q0^2)/2)) ";
    }
  }

  if(MRFunction==3){
    memEq="+aRm"+StrIdRm+" + bRm"+StrIdRm+"*q(1)^2 + cRm"+StrIdRm+"*q(1)^4"; 
    memEq2="+2*q(2)*(bRm"+StrIdRm+" + 2*cRm"+StrIdRm+"*q(1))"; 
    memEq3="+aRm"+StrIdRm+" + bRm"+StrIdRm+"*q(2)^2 + cRm"+StrIdRm+"*q(2)^4";
    if(b==0 && c==0){
      RmFlux = RmFlux+"+0";
    }
    else{
      RmFlux=RmFlux+"+(aRm"+StrIdRm+"*q(1))+(bRm"+StrIdRm+"*(q(1)^3)/3) + (cRm"+StrIdRm+"*(q(1)^5)/5) - ((aRm"+StrIdRm+"*q0)+(bRm"+StrIdRm+"*(q0^2)/2) + (cRm"+StrIdRm+"*(q(1)^5)/5))";
    }
  }

  if(MRFunction==4){
    memEq="+aRm"+StrIdRm+""; 
    memEq2="+0"; 
    memEq3="+aRm"+StrIdRm+"";
    RmFlux=RmFlux+"+(aRm"+StrIdRm+")";
  }

  RmFunc1=RmFunc1+memEq;
  RmFunc2=RmFunc2+memEq2;
  RmFunc3=RmFunc3+memEq3;
}

void VSave::AddMeminductor(Int_t MLFunction, Double_t a, Double_t b, Double_t c,Int_t kLm){
  kIdLm++;
  TString memEq=" ", memEq2=" ", memEq3=" ";
  faLm[kIdLm]=a;   fbLm[kIdLm]=b;   fcLm[kIdLm]=c;
  Char_t IntStr[2];
  sprintf(IntStr,"%d",kLm);
  TString StrIdLm(IntStr);
  if(MLFunction==0){memEq="+aLm"+StrIdLm+"*exp(bLm"+StrIdLm+"*q(1))"; memEq2="+aLm"+StrIdLm+"*bLm"+StrIdLm+"*q(2)*exp(bLm"+StrIdLm+"*q(1))"; memEq3="+aLm"+StrIdLm+"*exp(bLm"+StrIdLm+"*q(2))";}
  if(MLFunction==1){memEq="+aLm"+StrIdLm+" + bLm"+StrIdLm+"*q(1)^2"; memEq2="+2*bLm"+StrIdLm+"*q(1)*q(2)"; memEq3="+aLm"+StrIdLm+" + bLm"+StrIdLm+"*q(2)^2";}
  if(MLFunction==2){memEq="+aLm"+StrIdLm+" + bLm"+StrIdLm+"*q(1)"; memEq2="+bLm"+StrIdLm+"*q(2)"; memEq3="+aLm"+StrIdLm+" + bLm"+StrIdLm+"*q(2)";}
  if(MLFunction==3){memEq="+aLm"+StrIdLm+" + bLm"+StrIdLm+"*q(1)^2 + cLm"+StrIdLm+"*q(1)^4"; memEq2="+2*q(2)*(bLm"+StrIdLm+" + 2*cLm"+StrIdLm+"*q(1))"; memEq3="+aLm"+StrIdLm+" + bLm"+StrIdLm+"*q(2)^2 + cLm"+StrIdLm+"*q(2)^4";}
  if(MLFunction==4){memEq="+aLm"+StrIdLm+""; memEq2="+0"; memEq3="+aLm"+StrIdLm+"";}
  LmFunc1=LmFunc1+memEq;
  LmFunc2=LmFunc2+memEq2;
  LmFunc3=LmFunc3+memEq3;
}

void VSave::AddMemcapacitor(Int_t MCFunction, Double_t a, Double_t b, Double_t c,Int_t kCm){
  kIdCm++;
  TString memEq=" ", memEq2=" ", memEq3=" ";
  faCm[kIdCm]=a;   fbCm[kIdCm]=b;   fcCm[kIdCm]=c;
  Char_t IntStr[2];
  sprintf(IntStr,"%d",kCm);
  TString StrIdCm(IntStr);
  if(MCFunction==0){
    memEq="+aCm"+StrIdCm+"*exp(bCm"+StrIdCm+"*("+RmFlux+"))"; 
    memEq2="+aCm"+StrIdCm+"*bCm"+StrIdCm+"*("+RmFunc1+")*exp(bCm"+StrIdCm+"*("+RmFlux+"))"; 
    memEq3="+aCm"+StrIdCm+"*exp(bCm"+StrIdCm+"*("+RmFunc1+"))";
  }
  if(MCFunction==1){
    memEq="+aCm"+StrIdCm+" + bCm"+StrIdCm+"*("+RmFlux+")^2"; 
    memEq2="+2*bCm"+StrIdCm+"*("+RmFlux+")*("+RmFunc1+")"; 
    memEq3="+aCm"+StrIdCm+" + bCm"+StrIdCm+"*("+RmFunc1+")^2";
  }
  if(MCFunction==2){
    memEq="+aCm"+StrIdCm+" + bCm"+StrIdCm+"*("+RmFlux+")"; 
    memEq2="+bCm"+StrIdCm+"*("+RmFunc1+")"; 
    memEq3="+aCm"+StrIdCm+" + bCm"+StrIdCm+"*("+RmFunc1+")";
  }
  if(MCFunction==3){
    memEq="+aCm"+StrIdCm+" + bCm"+StrIdCm+"*("+RmFlux+")^2 + cCm"+StrIdCm+"*"+RmFlux+"^4"; 
    memEq2="+2*("+RmFunc1+")*(bCm"+StrIdCm+" + 2*cCm"+StrIdCm+"*("+RmFlux+"))"; 
    memEq3="+aCm"+StrIdCm+" + bCm"+StrIdCm+"*("+RmFunc1+")^2 + cCm"+StrIdCm+"*("+RmFunc1+")^4";
  }
  if(MCFunction==4){
    memEq="+aCm"+StrIdCm+""; 
    memEq2="+0"; 
    memEq3="+aCm"+StrIdCm+"";
  }
  CmFunc1=CmFunc1+memEq;
  CmFunc2=CmFunc2+memEq2;
  CmFunc3=CmFunc3+memEq3;
}

void VSave::AddResistor(Double_t R, Int_t kR){
  kIdR++;
  TString resEq=" ", resEq2=" ", resEq3=" ";
  fkR[kIdR]=R;
  Char_t IntStr[2];
  sprintf(IntStr,"%d",kR);
  TString StrIdR(IntStr);
  resEq="+R"+StrIdR; resEq2="+0"; resEq3="+R"+StrIdR;
  RmFunc1=RmFunc1+resEq;
  RmFunc2=RmFunc2+resEq2;
  RmFunc3=RmFunc3+resEq3;
  RmFlux=RmFlux+"(R"+StrIdR+")";
}

void VSave::AddCapacitor(Double_t C, Int_t kC){
  kIdC++;
  TString capEq=" ", capEq2=" ", capEq3=" ";
  fkC[kIdC] = C;
  Char_t IntStr[2];
  sprintf(IntStr,"%d",kC);
  TString StrIdC(IntStr);
  capEq="+C"+StrIdC; capEq2="+0"; capEq3="+C"+StrIdC;
  CmFunc1=CmFunc1+capEq;
  CmFunc2=CmFunc2+capEq2;
  CmFunc3=CmFunc3+capEq3;
}

void VSave::AddInductor(Double_t L,Int_t kL){
  kIdL++;
  TString indEq=" ", indEq2=" ", indEq3=" ";
  fkL[kIdL] = L;
  Char_t IntStr[2];
  sprintf(IntStr,"%d",kL);
  TString StrIdL(IntStr);
  indEq="+L"+StrIdL; indEq2="+0"; indEq3="+L"+StrIdL;
  LmFunc1=LmFunc1+indEq;
  LmFunc2=LmFunc2+indEq2;
  LmFunc3=LmFunc3+indEq3;
}

void VSave::Clear(){
  LmFunc1=" ";
  LmFunc2=" ";
  LmFunc3=" ";
  RmFunc1=" ";
  RmFunc2=" ";
  RmFunc3=" ";
  CmFunc1=" ";
  CmFunc2=" ";
  CmFunc3=" ";
  RmFlux=" ";
}

VSave::~VSave(){
}
