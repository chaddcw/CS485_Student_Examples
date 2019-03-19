//***************************************************************************
// File name:  StreamFunctor.h
// Author:     Chadd Williams
// Date:       3/18/2019
// Class:      CS485
// Assignment: Functor Example
// Purpose:    Demonstrate how the a functor can be used
//***************************************************************************
#pragma once
#include <string>
#include <ostream>
#include "LogFunctor.h"

class StreamFunctor {

public:
  StreamFunctor (std::ostream& rcOut, LogFunctor cLogFunc) 
    : mrcOut(rcOut), mcPrefixLog(cLogFunc) {};

  void operator() (std::string msg) const
  {
    mrcOut <<  mcPrefixLog(msg) << std::endl;
  }

private:
  std::ostream &mrcOut;
  LogFunctor mcPrefixLog;
     
}; 
