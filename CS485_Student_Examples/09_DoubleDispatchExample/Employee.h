//***************************************************************************
// File name:  Employee.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Double Dispatch Example
// Purpose:    Demonstrate how double dispatch can be implemented in C++
//             inspired by: 
// https://en.wikipedia.org/wiki/Double_dispatch#Double_dispatch_in_C.2B.2B
//***************************************************************************
#pragma once

#include <string>
#include <iostream>
//#include "BonusGiver.h"
class BonusGiver;

class Employee
{
  
public:

  Employee () {};

  Employee (std::string fname, std::string lname, unsigned long long salary)
    : mFName (fname), mLName (lname), mSalary(salary), mCurrentBonus(0)
  {}

  void giveBonus (unsigned long long bonus);
  virtual void getBonus (BonusGiver &rcBG);

  unsigned long long getSalary ();

  friend std::ostream& operator<<(std::ostream & rcOut, const Employee &rcEmp);

private:
  std::string mFName;
  std::string mLName;

  unsigned long long mSalary=0;
  unsigned long long mCurrentBonus = 0;
};