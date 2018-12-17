//***************************************************************************
// File name:  CharHolder.cpp
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: File reading example with >>
// Purpose:    Demonstrate how to detect EOF
//***************************************************************************
#include "CharHolder.h"

//***************************************************************************
// Function:    operator >>
//
// Description: Read in the CharHolder from a stream
//
// Parameters:  rcIn - the stream to read from
//              rcData - the object to read into
//
// Returned:    the stream
//***************************************************************************
std::istream& operator >> (std::istream &rcIn, CharHolder &rcData)
{
  rcIn >> rcData.mTheChar;
  return rcIn;
}

//***************************************************************************
// Function:    operator <<
//
// Description: Write the CharHolder to the stream
//
// Parameters:  rcOut - the stream to write to
//              rcData - the object to write
//
// Returned:    the stream
//***************************************************************************
std::ostream& operator << (std::ostream &rcOut, const CharHolder &rcData)
{
  rcOut << rcData.mTheChar;
  return rcOut;

}