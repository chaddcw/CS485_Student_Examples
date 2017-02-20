//***************************************************************************
// File name:  Parent.h
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Insertion Operator Polymorphism
// Purpose:    Demonstrate how Polymorphism works with <<
//***************************************************************************


#pragma once
#include <iostream>

class Parent
{
public:

  // inline the constructors
  Parent () {};
  Parent (int x) : mIntVal (x) {};

  virtual void print (std::ostream& rcOut) const;

  friend std::ostream& operator<< (std::ostream& rcOut, const Parent &rcData);

private:
  int mIntVal;
};