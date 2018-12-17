//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: Singleton Example
// Purpose:    Demonstrate Meyer's Singleton Example in C++11
//***************************************************************************

#include "Singleton.h"
#include <iostream>


//***************************************************************************
// Function:    useSingletonInFunction
//
// Description: Use a singleton in a function. Notice no dtor is called and
//              updates to the singleton's private data members persist
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void useSingletonInFunction ()
{
  Singleton &cSingleton = Singleton::Instance ();

  cSingleton.incrCount ();
  std::cout << "\t" << cSingleton;
  std::cout << std::endl;
}

//***************************************************************************
// Function:    main
//
// Description: Demonstrate the use of a Singleton object
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  Singleton &cSingleton = Singleton::Instance ();
  Singleton &cSingletonTwo = Singleton::Instance ();

  std::cout << cSingleton;
  std::cout << std::endl;

  cSingleton.incrCount ();

  std::cout << cSingletonTwo;
  std::cout << std::endl;

  useSingletonInFunction ();

  Singleton::Instance ().incrCount ();

  std::cout << cSingletonTwo;
  std::cout << std::endl;

  // delete &Singleton::Instance (); // illegal
  // delete &cSingleton;  // illegal

  return EXIT_SUCCESS;
}