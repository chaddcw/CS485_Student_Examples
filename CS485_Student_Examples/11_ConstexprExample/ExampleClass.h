//***************************************************************************
// File name:  ExampleClass.h
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how to use constexpr with objects
//***************************************************************************
#pragma once
#include <initializer_list>
#include <vector>
#include <iostream>

class ExampleClass
{
public:

  // constexpr functions must be defined where
  // they are declared


  // constexpr ctor
  constexpr ExampleClass (int x, int y) :mX (x), mY (y) {};

  // constexpr member function
  constexpr int sum () const { return mX + mY;};


  // non constexpr member funtions
  void printAll (std::ostream &rcOut) const;

  int average () const { return (mX + mY) / 2; };

private:

  int mX, mY;

}; 
