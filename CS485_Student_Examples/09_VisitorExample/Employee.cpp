//***************************************************************************
// File name:  Employee.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "Employee.h"
#include <iomanip>

//***************************************************************************
// Function:    giveBonus
//
// Description: Set the bonus for this Employee. Any previous bonus is ignored.
//
// Parameters:  bonus - the bonus to give
//
// Returned:    None
//***************************************************************************
void Employee::giveBonus (unsigned long long bonus)
{
  mCurrentBonus = bonus;
}

//***************************************************************************
// Function:    getSalary
//
// Description: Retrieve the Employee's salary
//
// Parameters:  None
//
// Returned:    the salary
//***************************************************************************
unsigned long long Employee::getSalary ()
{
  return mSalary;
}
//***************************************************************************
// Function:    operator<<
//
// Description: Write this Employee to the stream
//
// Parameters:  rcOut - the stream to write to
//              rcWorker - the object to write
//
// Returned:    ostream
//***************************************************************************
std::ostream& operator<<(std::ostream & rcOut, const Employee &rcEmp)
{
  rcOut << std::fixed << std::setprecision (2);
  rcOut << rcEmp.mFName << " " << rcEmp.mLName << " $" << rcEmp.mSalary / 100.0;
  rcOut << " + $" << rcEmp.mCurrentBonus / 100.0;
  return rcOut;
}

