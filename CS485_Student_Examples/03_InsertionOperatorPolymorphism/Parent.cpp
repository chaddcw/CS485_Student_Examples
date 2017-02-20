//***************************************************************************
// File name:  Parent.cpp
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Insertion Operator Polymorphism
// Purpose:    Demonstrate how Polymorphism works with <<
//***************************************************************************

#include "Parent.h"

//***************************************************************************
// Function:    operator<<
//
// Description: Output the Parent to the stream.
//
// Parameters:  rcOut - the stream to write to
//              rcData - the data to write to the stream
//
// Returned:    the stream written to
//***************************************************************************

std::ostream& operator<< (std::ostream& rcOut, const Parent &rcData)
{
  rcOut << ">" <<rcData.mIntVal << "<";
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
void Parent::print (std::ostream& rcOut) const
{
  rcOut << *this;
}
