//***************************************************************************
// File name:  BonusGiver.cpp
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: Double Dispatch Example
// Purpose:    Demonstrate how double dispatch can be implemented in C++
//             inspired by: 
// https://en.wikipedia.org/wiki/Double_dispatch#Double_dispatch_in_C.2B.2B
//***************************************************************************
#include "BonusGiver.h"

void BonusGiver::giveBonus (Manager & rcTheMan)
{
  std::cout << " Give Bonus to Manager" << std::endl;
}

void BonusGiver::giveBonus (Employee & rcEmp)
{
  std::cout << " Give Bonus to Employee" << std::endl;
}
