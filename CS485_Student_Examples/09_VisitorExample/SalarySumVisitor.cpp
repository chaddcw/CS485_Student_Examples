//***************************************************************************
// File name:  SalarySumVisitor.cpp
// Author:     Chadd Williams
// Date:       3/20/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "SalarySumVisitor.h"


//***************************************************************************
// Constructor: SalarySumVisitor
//
// Description: Create object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
SalarySumVisitor::SalarySumVisitor()
{
}

//***************************************************************************
// Function:    visit
//
// Description: Visit the Worker.  Write the worker to the outputstream
//
// Parameters:  rcWorker - the worker to visit
//
// Returned:    None
//***************************************************************************
void SalarySumVisitor::visit (Worker &rcWorker)
{
  mWorkerSum += rcWorker.getSalary ();
}

//***************************************************************************
// Function:    visit
//
// Description: Visit the Manager.  Write the Manager to the outputstream
//
// Parameters:  rcTheMan - the Manager to visit
//
// Returned:    None
//***************************************************************************
void SalarySumVisitor::visit (Manager &rcTheMan)
{
  mManagerSum += rcTheMan.getSalary ();
}

void SalarySumVisitor::displaySums (std::ostream & rcOut) const
{
  rcOut << "Manager: " << mManagerSum << " Worker: " << mWorkerSum;
}
