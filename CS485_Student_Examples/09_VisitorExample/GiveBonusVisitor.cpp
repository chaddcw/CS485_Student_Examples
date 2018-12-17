//***************************************************************************
// File name:  GiveBonusVisitor.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "GiveBonusVisitor.h"

//***************************************************************************
// Function:    visit
//
// Description: Visit the Worker.  Give a bonus of 50000
//
// Parameters:  rcWorker - the worker to visit
//
// Returned:    None
//***************************************************************************
void GiveBonusVisitor::visit (Worker &rcWorker)
{
  rcWorker.giveBonus (50000);
}

//***************************************************************************
// Function:    visit
//
// Description: Visit the Manager.  Give a bonus of 5000000
//
// Parameters:  rcTheMan - the Manager to visit
//
// Returned:    None
//***************************************************************************
void GiveBonusVisitor::visit (Manager &rcTheMan)
{
  rcTheMan.giveBonus (5000000);
}