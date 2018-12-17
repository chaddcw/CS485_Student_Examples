//***************************************************************************
// File name:  ExampleClass.h
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how to use constexpr with objects
//***************************************************************************
#pragma once
#include <iostream>


void runnew ();

class ExampleClass
{
public:

  ExampleClass (int x, int y) :mX (x), mY (y)
  {
    std::cout << "ctor2\n";
  };

  ExampleClass (int x, int y, int z) :mX (x), mY (y)
  {
    std::cout << "ctor3\n";
    pInt = new int;
    runnew();
    *pInt = z;
    
  };

  ExampleClass (const ExampleClass &rcObj);

  ExampleClass (ExampleClass &&rcObj);

  ~ExampleClass () { delete pInt; };

  ExampleClass & operator=(const ExampleClass &rcObj);

  ExampleClass & operator=(ExampleClass &&rcObj);

  ExampleClass operator+(const ExampleClass &rcObj);

  void printAll (std::ostream &rcOut) const;

private:

  int mX, mY;

  int *pInt = nullptr;

};

