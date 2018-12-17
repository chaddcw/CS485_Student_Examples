//***************************************************************************
// File name:  PrintVisitor.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "PrintVisitor.h"


//***************************************************************************
// Constructor: PrintVisitor
//
// Description: Set the output stream
//
// Parameters:  rcOut - the output stream to write to
//
// Returned:    None
//***************************************************************************
PrintVisitor::PrintVisitor (std::ostream &rcOut) : mrcOutputStream(rcOut)
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
void PrintVisitor::visit (Worker &rcWorker)
{
  mrcOutputStream << rcWorker << std::endl;
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
void PrintVisitor::visit (Manager &rcTheMan)
{
  mrcOutputStream << rcTheMan << std::endl;
}