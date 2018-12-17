//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "Worker.h"
#include "Manager.h"
#include "PrintVisitor.h"
#include "GiveBonusVisitor.h"
#include <iostream>
#include "SimpleContainer.h"
#include "SalarySumVisitor.h"

#include "vld.h"

//***************************************************************************
// Function:    main
//
// Description: Add Employees to a container and use visitors to display and
//              update those employees
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main ()
{

  EmpContainer::SimpleContainer cTheContainer;
  PrintVisitor cPrintVisitor(std::cout);
  GiveBonusVisitor cGiveBonusVisitor;
  SalarySumVisitor cSalarySumVisitor;

  cTheContainer.addEmployee (new Worker ("Bob", "Bib", 1000001));
  cTheContainer.addEmployee (new Worker ("Sally", "Silly", 1500000));
  cTheContainer.addEmployee (new Manager ("Jim", "Jam", 2500003));
  cTheContainer.addEmployee (new Manager ("Mable", "Table", 3500000));

  std::cout << std::endl;
  
  EmpContainer::applyVisitor (cTheContainer, &cPrintVisitor);
  std::cout << std::endl;
  std::cout << std::endl;

  EmpContainer::applyVisitor (cTheContainer, &cGiveBonusVisitor);
  std::cout << std::endl;
  std::cout << std::endl;

  EmpContainer::applyVisitor (cTheContainer, &cPrintVisitor);
  std::cout << std::endl;
  std::cout << std::endl;

  EmpContainer::applyVisitor (cTheContainer, &cSalarySumVisitor);
  cSalarySumVisitor.displaySums (std::cout);

  std::cout << std::endl;
  std::cout << std::endl;
  return EXIT_SUCCESS;
}