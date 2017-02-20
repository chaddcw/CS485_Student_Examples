//***************************************************************************
// File name:  ChildNoVirtualDtor.h
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Virtual Destructor Examples
// Purpose:    Demonstrate how Polymorphism works with Destructors
//***************************************************************************

#pragma once
#include "ParentNoVirtualDtor.h"

#include <iostream>

class ChildNoVirtualDtor : public ParentNoVirtualDtor
{
public:

  // inline the constructors
  ChildNoVirtualDtor () {};
  ChildNoVirtualDtor (int x, char c) : ParentNoVirtualDtor (x)
  {
    mpCharVal = new char;
    *mpCharVal = c;
  };

  ~ChildNoVirtualDtor ()
  {
    std::cout << "ChildNoVirtualDtor::dtor(" << *mpCharVal << ")\n";

    delete mpCharVal;
  }


private:
  char* mpCharVal=nullptr;
};