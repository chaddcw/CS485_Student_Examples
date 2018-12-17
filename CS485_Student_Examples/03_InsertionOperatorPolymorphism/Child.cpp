//***************************************************************************
// File name:  Child.cpp
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Insertion Operator Polymorphism
// Purpose:    Demonstrate how Polymorphism works with <<
//***************************************************************************

#include "Child.h"

//***************************************************************************
// Function:    operator<<
//
// Description: Output the Child to the stream. Call print to resolve to
//              subclass correctly
//
// Parameters:  rcOut - the stream to write to
//              rcData - the data to write to the stream
//
// Returned:    the stream written to
//***************************************************************************

std::ostream& operator<< (std::ostream& rcOut, const Child &rcData)
{
  rcData.print (rcOut);
  return rcOut;
}

//***************************************************************************
// Function:    print
//
// Description: Call the operator<< on the *this object
//
// Parameters:  rcOut - the stream to write to.
//
// Returned:    None
//***************************************************************************

void Child::print (std::ostream& rcOut) const
{
  Parent::print (rcOut);
  rcOut << "#" << mCharVal << "#";
}

