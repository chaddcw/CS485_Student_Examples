//***************************************************************************
// File name:  BonusGiver.h
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: Double Dispatch Example
// Purpose:    Demonstrate how double dispatch can be implemented in C++
//             inspired by: 
// https://en.wikipedia.org/wiki/Double_dispatch#Double_dispatch_in_C.2B.2B
//***************************************************************************

#pragma once
#include "Manager.h"

class BonusGiver
{
public:
  virtual void giveBonus (Manager &rcTheMan);
  virtual void giveBonus (Employee &rcEmp);
};