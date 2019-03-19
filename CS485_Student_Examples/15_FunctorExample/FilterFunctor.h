//***************************************************************************
// File name:  FilterFunctor.h
// Author:     Chadd Williams
// Date:       3/18/2019
// Class:      CS485
// Assignment: Functor Example
// Purpose:    Demonstrate how the a functor can be used
//***************************************************************************
#pragma once
#include <string>
#include <functional>

class FilterFunctor {

public:
  FilterFunctor (std::string prefix, 
    std::function<bool (std::string, std::string)> compare )
    : mPrefix (prefix), mCompare(compare)
  {};

  bool operator() (std::string msg) const
  {
    return mCompare(msg,mPrefix);
  }

private:
  std::string mPrefix;
  std::function<bool (std::string, std::string)> mCompare;
};