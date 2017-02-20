//***************************************************************************
// File name:  Child.h
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Insertion Operator Polymorphism
// Purpose:    Demonstrate how Polymorphism works with <<
//***************************************************************************

#pragma once
#include "Parent.h"

#include <iostream>

class Child: public Parent
{
public:

  // inline the constructors
  Child () {};
  Child (int x, char c) : Parent (x), mCharVal(c) {};

  virtual void print (std::ostream& rcOut) const override;

  friend std::ostream& operator<< (std::ostream& rcOut, const Child &rcData);

private:
  char mCharVal;
};