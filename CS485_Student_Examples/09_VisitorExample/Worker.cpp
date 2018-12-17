//***************************************************************************
// File name:  Worker.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************

#include "Worker.h"
#include "IEmployeeVisitor.h"

//***************************************************************************
// Function:    operator<<
//
// Description: Write this Worker to the stream
//
// Parameters:  rcOut - the stream to write to
//              rcWorker - the object to write
//
// Returned:    ostream
//***************************************************************************
std::ostream& operator<<(std::ostream & rcOut, const Worker &rcWorker)
{
  rcOut << static_cast<const Employee&> (rcWorker);
  rcOut << " WORKER ";

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
void Worker::accept (IEmployeeVisitor *pcVisitor)
{
  pcVisitor->visit (*this);
}