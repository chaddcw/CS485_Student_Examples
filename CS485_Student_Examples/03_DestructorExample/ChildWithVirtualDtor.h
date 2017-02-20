//***************************************************************************
// File name:  ChildNoVirtualDtor.h
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Virtual Destructor Examples
// Purpose:    Demonstrate how Polymorphism works with Destructors
//***************************************************************************

#pragma once
#include "ParentWithVirtualDtor.h"

#include <iostream>

class ChildWithVirtualDtor : public ParentWithVirtualDtor
{
public:

  // inline the constructors
  ChildWithVirtualDtor () {};
  ChildWithVirtualDtor (int x, char c) : ParentWithVirtualDtor (x)
  {
    mpCharVal = new char;
    *mpCharVal = c;
  };

  virtual ~ChildWithVirtualDtor ()
  {
    std::cout << "ChildWithVirtualDtor::dtor(" << *mpCharVal << ")\n";

    delete mpCharVal;
  }

private:
  char* mpCharVal = nullptr;
};