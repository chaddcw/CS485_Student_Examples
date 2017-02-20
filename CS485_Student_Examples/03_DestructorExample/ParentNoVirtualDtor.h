//***************************************************************************
// File name:  ParentNoVirtualDtor.h
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Virtual Destructor Examples
// Purpose:    Demonstrate how Polymorphism works with Destructors
//***************************************************************************


#pragma once
#include <iostream>

class ParentNoVirtualDtor
{
public:

  // inline the constructors
  ParentNoVirtualDtor () {};
  ParentNoVirtualDtor (int x) 
  {
    mpIntVal = new int;
    *mpIntVal = x;
  };

  ~ParentNoVirtualDtor ()
  {
    std::cout << "ParentNoVirtualDtor::dtor(" << *mpIntVal << ")\n";

    delete mpIntVal;
  }

private:
  int* mpIntVal = nullptr;
}; 

