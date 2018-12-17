//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Initialize List Example
// Purpose:    Demonstrate how to use std::initializer_list
//***************************************************************************
#include "ExampleClass.h"

//***************************************************************************
// Function:    main
//
// Description: print all the items in the private vector to rcOut
//
// Parameters:  rcOut - the out stream to write to
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  ExampleClass cTheClass{ 1,2,3,4,5,6 };

  ExampleClass cTheClass2{ 0 };

  cTheClass.printAll (std::cout);

  std::cout << std::endl;
  cTheClass2.printAll (std::cout);
  std::cout << std::endl;

  return EXIT_SUCCESS;
}