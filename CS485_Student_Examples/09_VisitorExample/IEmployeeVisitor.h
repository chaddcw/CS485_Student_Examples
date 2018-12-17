//***************************************************************************
// File name:  IEmployeeVisitor.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once
#include "Manager.h"
#include "Worker.h"

class IEmployeeVisitor
{
public:
  
  virtual void visit (Worker &rcWorker) = 0;
  virtual void visit (Manager &rcTheMan) = 0;
};