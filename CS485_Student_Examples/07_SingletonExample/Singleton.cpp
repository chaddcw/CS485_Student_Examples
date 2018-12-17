//***************************************************************************
// File name:  Singleton.cpp
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: Singleton Example
// Purpose:    Demonstrate Meyer's Singleton Example in C++11
//***************************************************************************

#include "Singleton.h"

//***************************************************************************
// Constructor: Singleton
//
// Description: Initialize Singleton - nothing to do here
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Singleton::Singleton ()
{

}

//***************************************************************************
// Function:    Instance
//
// Description: static method to retreive a reference to a Singleton
//
// Parameters:  None
//
// Returned:    reference to a static Singleton
//***************************************************************************
Singleton& Singleton::Instance ()
{
  static Singleton theSingleton;
  return theSingleton;
}

//***************************************************************************
// Destructor:  Singleton
//
// Description: Destroy the Singleton, just print a message indicating
//              the dtor ran.
//
// Parameters:  
//
// Returned:    None
//***************************************************************************
Singleton::~Singleton ()
{
  std::cout << "dtor Singleton!" << std::endl;
}

//***************************************************************************
// Function:    incrCount
//
// Description: Increment the Singleton counters
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Singleton::incrCount ()
{
  mCounter++;
}

//***************************************************************************
// Function:    operator<<
//
// Description: Stream out put operator for Singleton
//
// Parameters:  rcOut - the stream to write to
//              rcData - the data to write
//
// Returned:    the output stream
//***************************************************************************
std::ostream& operator<<(std::ostream &rcOut, const Singleton &rcData)
{
  rcOut << rcData.mCounter;
  return rcOut;
}
