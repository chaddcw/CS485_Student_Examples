//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Double Dispatch Example
// Purpose:    Demonstrate how double dispatch can be implemented in C++
//             inspired by: 
// https://en.wikipedia.org/wiki/Double_dispatch#Double_dispatch_in_C.2B.2B
//***************************************************************************
#include "Manager.h"
#include "DoubleBonusGiver.h"
#include <iostream>

#include "vld.h"

//***************************************************************************
// Function:    main
//
// Description: Demonstrate Double Dispatch
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main ()
{
  // Not double dispatch
  BonusGiver cBonusGiver;
  DoubleBonusGiver cDblBonusGiver;
  BonusGiver& rcBonusGiver = cDblBonusGiver; 
  Employee cEmp;
  Manager cMang;

  Employee &rcEmp = cMang;

  std::cout << "\n\ncBonusGiver.giveBonus (cEmp)\n";
  cBonusGiver.giveBonus (cEmp);

  std::cout << "\ncBonusGiver.giveBonus (cMang);\n";
  cBonusGiver.giveBonus (cMang);


  std::cout << "\ncDblBonusGiver.giveBonus (cEmp);\n";
  cDblBonusGiver.giveBonus (cEmp);

  std::cout << "\ncDblBonusGiver.giveBonus (cMang);\n";
  cDblBonusGiver.giveBonus (cMang);

  std::cout << "\nrcEmp = cMang; cBonusGiver.giveBonus (rcEmp);\n";
  cBonusGiver.giveBonus (rcEmp);

  std::cout << "\nrcEmp = cMang; cDblBonusGiver.giveBonus (rcEmp);\n";
  cDblBonusGiver.giveBonus (rcEmp);

  std::cout << "\nrcEmp = cMang; rcBonusGiver = cDblBonusGiver;";
  std::cout <<" rcBonusGiver.giveBonus (rcEmp); \n";
  rcBonusGiver.giveBonus (rcEmp);

  // double dispatch

  std::cout << "\nDouble Dispatch";
  std::cout << "\nrcEmp.getBonus (rcBonusGiver);\n";
  rcEmp.getBonus (rcBonusGiver);
  std::cout << "\n\n";

  return EXIT_SUCCESS;
}