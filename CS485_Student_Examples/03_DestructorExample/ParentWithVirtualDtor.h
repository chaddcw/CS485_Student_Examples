//***************************************************************************
// File name:  ParentWithVirtualDtor.h
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Virtual Destructor Examples
// Purpose:    Demonstrate how Polymorphism works with Destructors
//***************************************************************************


#pragma once
#include <iostream>

class ParentWithVirtualDtor
{
public:

  // inline the constructors
  ParentWithVirtualDtor () {};
  ParentWithVirtualDtor (int x)
  {
    mpIntVal = new int;
    *mpIntVal = x;
  };

  virtual ~ParentWithVirtualDtor ()
  {
    std::cout << "ParentWithVirtualDtor::dtor(" << *mpIntVal << ")\n";
    delete mpIntVal;
  }


private:
  int* mpIntVal = nullptr;
};
