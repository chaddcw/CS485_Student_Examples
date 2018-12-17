//***************************************************************************
// File name:  SalarySumVisitor.h
// Author:     Chadd Williams
// Date:       3/20/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once

#include "IEmployeeVisitor.h"
#include <iostream>
class SalarySumVisitor : public IEmployeeVisitor
{
public:

  SalarySumVisitor ();

  virtual void visit (Worker &rcWorker);
  virtual void visit (Manager &rcTheMan);

  void displaySums (std::ostream &rcOut) const;

private:
  unsigned long long mWorkerSum = 0;
  unsigned long long mManagerSum = 0;
}; 
