//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       2/27/2017
// Class:      CS485
// Assignment: Template Method Design Pattern example
// Purpose:    Demonstrate the structure of the Template Method Design Pattern
//***************************************************************************
#include "ConcreteTemplate.h"

//***************************************************************************
// Function:    main
//
// Description: Allocate various AbstractTemplate and ConcreteTemplate objects
//              to determine how operation1() and operation2() are resolved.
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  AbstractTemplate *pcAbsTemp = new ConcreteTemplate;
  ConcreteTemplate cConTemp;
  AbstractTemplate cAbsTemp;

  pcAbsTemp->templateMethod ();
  cConTemp.templateMethod ();

  cAbsTemp.templateMethod ();

  delete pcAbsTemp;
  return EXIT_SUCCESS;
}
