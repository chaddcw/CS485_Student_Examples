//***************************************************************************
// File name:  ConcreteTemplate.cpp
// Author:     Chadd Williams
// Date:       2/27/2017
// Class:      CS485
// Assignment: Template Method Design Pattern example
// Purpose:    Demonstrate the structure of the Template Method Design Pattern
//***************************************************************************
#include "ConcreteTemplate.h"

//***************************************************************************
// Function:    operation1
//
// Description: Print simple message to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void ConcreteTemplate::operation1 ()
{ 
  std::cout << "ConcreteTemplate::op1()\n"; 
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
void ConcreteTemplate::operation2 ()
{
  std::cout << "ConcreteTemplate::op2()\n";
}