//***************************************************************************
// File name:  AbstractTemplate.h
// Author:     Chadd Williams
// Date:       2/27/2017
// Class:      CS485
// Assignment: Template Method Design Pattern example
// Purpose:    Demonstrate the structure of the Template Method Design Pattern
//***************************************************************************
#pragma once
#include <iostream>

class AbstractTemplate
{
public:

  void templateMethod ();

private:
  virtual void operation1 ();
  virtual void operation2 ();

};