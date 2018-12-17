//***************************************************************************
// File name:  ConcreteTemplate.h
// Author:     Chadd Williams
// Date:       2/27/2017
// Class:      CS485
// Assignment: Template Method Design Pattern example
// Purpose:    Demonstrate the structure of the Template Method Design Pattern
//***************************************************************************


#pragma once

#include <iostream>
#include "AbstractTemplate.h"

class ConcreteTemplate: public AbstractTemplate
{
public:



private:
  virtual void operation1 () override;
  virtual void operation2 () override;

};