//***************************************************************************
// File name:  DoubleBonusGiver.cpp
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: Double Dispatch Example
// Purpose:    Demonstrate how double dispatch can be implemented in C++
//             inspired by: 
// https://en.wikipedia.org/wiki/Double_dispatch#Double_dispatch_in_C.2B.2B
//***************************************************************************
#include "DoubleBonusGiver.h"

void DoubleBonusGiver::giveBonus (Manager & rcTheMan)
{
  std::cout << " Give Double Bonus to Manager" << std::endl;
}

void DoubleBonusGiver::giveBonus (Employee & rcEmp)
{
  std::cout << " Give Double Bonus to Employee" << std::endl;
}
