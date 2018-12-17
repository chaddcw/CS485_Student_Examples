//***************************************************************************
// File name:  IntHolder.cpp
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: File reading example with >>
// Purpose:    Demonstrate how to detect EOF
//***************************************************************************
#include "IntHolder.h"

//***************************************************************************
// Function:    operator >>
//
// Description: Read in the IntHolder from a stream
//
// Parameters:  rcIn - the stream to read from
//              rcData - the object to read into
//
// Returned:    the stream
//***************************************************************************
std::istream& operator >> (std::istream &rcIn, IntHolder &rcData)
{
  rcIn >> rcData.mTheInt;
  return rcIn;
}

//***************************************************************************
// Function:    operator <<
//
// Description: Write the IntHolder to the stream
//
// Parameters:  rcOut - the stream to write to
//              rcData - the object to write
//
// Returned:    the stream
//***************************************************************************
std::ostream& operator << (std::ostream &rcOut, const IntHolder &rcData)
{
  rcOut << rcData.mTheInt;
  return rcOut;

}
