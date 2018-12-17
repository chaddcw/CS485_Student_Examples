//***************************************************************************
// File name:  PrintVisitor.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once

#include "IEmployeeVisitor.h"
#include <iostream>
class PrintVisitor : public IEmployeeVisitor
{
public:

  PrintVisitor (std::ostream &rcOut);
  
  virtual void visit (Worker &rcWorker);
  virtual void visit (Manager &rcTheMan);

private:
  std::ostream &mrcOutputStream;
};