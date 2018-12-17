//***************************************************************************
// File name:  Manager.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Double Dispatch Example
// Purpose:    Demonstrate how double dispatch can be implemented in C++
//             inspired by: 
// https://en.wikipedia.org/wiki/Double_dispatch#Double_dispatch_in_C.2B.2B
//***************************************************************************
#include "Manager.h"
#include "BonusGiver.h"

//***************************************************************************
// Function:    operator<<
//
// Description: Write this Manager to the stream
//
// Parameters:  rcOut - the stream to write to
//              rcWorker - the object to write
//
// Returned:    ostream
//***************************************************************************
std::ostream& operator<<(std::ostream & rcOut, const Manager &rcTheMan)
{
  rcOut << static_cast<const Employee&> (rcTheMan);
  rcOut << " THE MAN ";

  return rcOut;
}

void Manager::getBonus (BonusGiver &rcBG)
{
  rcBG.giveBonus (*this);
}
