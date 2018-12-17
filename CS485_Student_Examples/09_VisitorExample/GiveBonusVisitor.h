//***************************************************************************
// File name:  GiveBonusVisitor.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once

#include "IEmployeeVisitor.h"

class GiveBonusVisitor : public IEmployeeVisitor
{
public:
  virtual void visit (Worker &rcWorker);
  virtual void visit (Manager &rcTheMan);
};