//***************************************************************************
// File name:  Manager.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "Manager.h"
#include "IEmployeeVisitor.h"

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

//***************************************************************************
// Function:    accept
//
// Description: Invoke visit on this object
//
// Parameters:  pcVisitor   - The visitor object
//
// Returned:    None
//***************************************************************************
void Manager::accept (IEmployeeVisitor *pcVisitor)
{
  pcVisitor->visit (*this);
}