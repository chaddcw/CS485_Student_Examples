//***************************************************************************
// File name:  Employee.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once

#include <string>
#include <iostream>
//#include "IEmployeeVisitor.h"
class IEmployeeVisitor;

class Employee
{
  
public:

  Employee () {};

  Employee (std::string fname, std::string lname, unsigned long long salary)
    : mFName (fname), mLName (lname), mSalary(salary), mCurrentBonus(0)
  {}

  void giveBonus (unsigned long long bonus);

  unsigned long long getSalary ();

  virtual void accept (IEmployeeVisitor *pcVisitor)=0;

  friend std::ostream& operator<<(std::ostream & rcOut, const Employee &rcEmp);

private:
  std::string mFName;
  std::string mLName;

  unsigned long long mSalary=0;
  unsigned long long mCurrentBonus = 0;
};