//***************************************************************************
// File name:  LogFunctor.h
// Author:     Chadd Williams
// Date:       3/18/2019
// Class:      CS485
// Assignment: Functor Example
// Purpose:    Demonstrate how the a functor can be used
//***************************************************************************
#pragma once
#include <string>

class LogFunctor {

  public:
    LogFunctor (std::string prefix) : mPrefix (prefix) {};

    std::string operator() (std::string msg) const
    {
      return mPrefix + ": " + msg;
    }

  private:
    std::string mPrefix;
};