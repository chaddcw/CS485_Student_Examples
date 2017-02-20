#include "Child.h"
//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Insertion Operator Polymorphism
// Purpose:    Demonstrate how Polymorphism works with <<
//***************************************************************************

#include <iostream>

//***************************************************************************
// Function:    main
//
// Description: Allocate a Child, try to use << via a Parent pointer
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main ()
{
  Parent *pcParent;
  Child *pcChild;

  pcChild = new Child (1, 'a');

  pcParent = pcChild;

  std::cout << *pcChild;
  std::cout << std::endl << std::endl;

  std::cout << *pcParent;
  std::cout << std::endl << std::endl;


  pcChild->print (std::cout);
  std::cout << std::endl << std::endl;
  pcParent->print (std::cout);
  std::cout << std::endl << std::endl;

  delete pcParent;
  pcParent = nullptr;
  pcChild = nullptr;

  return EXIT_SUCCESS;
}
