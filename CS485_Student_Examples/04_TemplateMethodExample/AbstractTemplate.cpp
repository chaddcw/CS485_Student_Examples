//***************************************************************************
// File name:  AbstractTemplate.cpp
// Author:     Chadd Williams
// Date:       2/27/2017
// Class:      CS485
// Assignment: Template Method Design Pattern example
// Purpose:    Demonstrate the structure of the Template Method Design Pattern
//***************************************************************************
#include "AbstractTemplate.h"

//***************************************************************************
// Function:    operation1
//
// Description: Print simple message to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void AbstractTemplate::operation1 ()
{
  std::cout << "AbstractTemplate::op1()\n";
}

//***************************************************************************
// Function:    operation2
//
// Description: Print simple message to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void AbstractTemplate::operation2 ()
{
  std::cout << "AbstractTemplate::op2()\n";
}

//***************************************************************************
// Function:    templateMethod
//
// Description: The Template Method. Invoke operation1() and operation2()
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void AbstractTemplate::templateMethod ()
{
  operation1 (); 
  operation2 ();
}