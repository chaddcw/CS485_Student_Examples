//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how and why to use constexpr
//***************************************************************************

#include "ExampleClass.h"
#include <iostream>

//***************************************************************************
// Function:    foo
//
// Description: return the constant int 1
//
// Parameters:  None
//
// Returned:    1
//***************************************************************************
int foo ()
{
  return 1;
}

//***************************************************************************
// Function:    constExprFoo
//
// Description: return the constexpr int 1
//
// Parameters:  None
//
// Returned:    1
//***************************************************************************
constexpr int constExprFoo ()
{
  return 1;
}

//***************************************************************************
// Function:    incrementer
//
// Description: return x + 1, marked as a constexpr
//
// Parameters:  x - the number to add one to
//
// Returned:    x+1
//***************************************************************************
constexpr int incrementer (int x)
{
  return x + 1;
}

//***************************************************************************
// Function:    decrementer
//
// Description: return x - 1, marked as a constexpr. Also demonstrates
//              the statements that can and cannot be in a constexpr function
//
// Parameters:  x - the number to subtract one from
//
// Returned:    x - 1
//***************************************************************************
constexpr int decrementer (int x)
{

  // C++11
  // C++14 allows more statements.
  // constexpr functions can only have one executable statement:
  // a single return
  // (plus some declarative statements)
  // this encourages usage of ? : and recursion.

  // const int value = 1; // illegal
  // int value = 1; // illegal

  //  constexpr int value = 1;

  ; // empty statements are allowed

  return x - 1;
}

//***************************************************************************
// Function:    main
//
// Description: demonstrate many uses of constexpr
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  int size = 9;

  // int aSize[size];  // illegal

  // int aFoo[foo ()]; // illegal

  int aConstexprFoo[constExprFoo ()]; // legal


  int x = 4;

  const int y = x;

  // int aY[y]; // illegal

  // constexpr int yy = x; // illegal

  constexpr int z = 4;

  int aZ[z];

  int aIncrementer[incrementer (1)];
  int aIncrementerZ[incrementer (z)];

  // a constexpr function is not constexpr if called
  // with non-constexpr parameters!
  // int aIncrementerY[incrementer (y)]; // illegal

  // int aIncrementerFoo[incrementer (foo())]; // illegal

  int aIncrementerDogFood[incrementer (incrementer (z))];

  constexpr ExampleClass cExClass (2, 100);

  int aExampleClassSum[cExClass.sum ()];

  // int aExampleClassAvg[cExClass.average ()]; // illegal

  cExClass.printAll (std::cout);

  return EXIT_SUCCESS;
}

