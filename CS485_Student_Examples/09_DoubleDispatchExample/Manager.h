//***************************************************************************
// File name:  Manager.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Double Dispatch Example
// Purpose:    Demonstrate how double dispatch can be implemented in C++
//             inspired by: 
// https://en.wikipedia.org/wiki/Double_dispatch#Double_dispatch_in_C.2B.2B
//***************************************************************************
#pragma once
#include "Employee.h"

class Manager : public Employee
{
public:
  Manager () {};

  Manager (std::string fname, std::string lname, unsigned long long salary)
    : Employee (fname, lname, salary)
  {}

  virtual void getBonus (BonusGiver &rcBG);

  friend std::ostream& operator<<(std::ostream & rcOut, const Manager &rcTheMan);

private:

};