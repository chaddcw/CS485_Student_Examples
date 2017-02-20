//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       2/17/2017
// Class:      CS485
// Assignment: Virtual Destructor Examples
// Purpose:    Demonstrate how Polymorphism works with Destructors
//***************************************************************************
#include <iostream>
#include "ChildNoVirtualDtor.h"
#include "ChildWithVirtualDtor.h"

//***************************************************************************
// Function:    main
//
// Description: Point base class pointers at subclasses and see how the
//              destructors get called
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main ()
{
  ParentNoVirtualDtor cParentNoVDtor (1);
  ParentWithVirtualDtor cParentWithVDtor (2);

  ParentNoVirtualDtor *pcParentNoVDtor = nullptr;
  ParentWithVirtualDtor *pcParentWithVDtor = nullptr;

  ChildNoVirtualDtor cChildNoVDtor (3, 'c');
  ChildWithVirtualDtor cChildWithVDtor (4, 'd');

  ChildNoVirtualDtor *pcChildNoVDtor = nullptr;
  ChildWithVirtualDtor *pcChildWithVDtor = nullptr;


  pcChildNoVDtor = new ChildNoVirtualDtor (5, 'e');
  pcChildWithVDtor = new ChildWithVirtualDtor (6, 'f');

  std::cout << "START FIRST DELETES\n";
  delete pcChildNoVDtor;
  std::cout << std::endl;
  delete pcChildWithVDtor;
  std::cout << "\nEND FIRST DELETES\n\n";

  pcChildNoVDtor = nullptr;
  pcChildWithVDtor = nullptr;


  pcChildNoVDtor = new ChildNoVirtualDtor (7, 'g');
  pcChildWithVDtor = new ChildWithVirtualDtor (8, 'h');

  pcParentNoVDtor = pcChildNoVDtor;
  pcParentWithVDtor = pcChildWithVDtor;

  std::cout << "START SECOND DELETES\n";
  delete pcParentNoVDtor;
  std::cout << std::endl;
  delete pcParentWithVDtor;
  std::cout << "\nEND SECOND DELETES\n\n";

  pcParentNoVDtor = nullptr;
  pcParentWithVDtor = nullptr;

  pcChildNoVDtor = nullptr;
  pcChildWithVDtor = nullptr;

  
  std::cout << "END PROGRAM\n\n";
  return EXIT_SUCCESS;
}
