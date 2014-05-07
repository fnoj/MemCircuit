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
