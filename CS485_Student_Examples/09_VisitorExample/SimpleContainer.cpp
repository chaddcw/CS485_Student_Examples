//***************************************************************************
// File name:  SimpleContainer.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "SimpleContainer.h"

//***************************************************************************
// Constructor: SimpleContainer
//
// Description: Initializes data members to default values
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
EmpContainer::SimpleContainer::SimpleContainer ()
{
}

//***************************************************************************
// Destructor: SimpleContainer
//
// Description: Delete each object held in the container
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
EmpContainer::SimpleContainer::~SimpleContainer ()
{
  for (int i = 0; i < mCurrentEmployees; i++)
  {
    delete mcEmployees[i];
    mcEmployees[i] = nullptr;
  }
}

//***************************************************************************
// Function:    addEmployee
//
// Description: Add an employee to the container if the container is not full
//
// Parameters:  pcAcct   -  the Employee to add
//
// Returned:    None
//***************************************************************************
void EmpContainer::SimpleContainer::addEmployee (Employee *pcAcct)
{
  if (!isFull ())
  {
    mcEmployees[mCurrentEmployees++] = pcAcct;
  }
}


//***************************************************************************
// Function:    isFull
//
// Description: Return if the container is full or not
//
// Parameters:  None
//
// Returned:    true if full, false otherwise
//***************************************************************************
bool EmpContainer::SimpleContainer::isFull () const
{
  return !(mCurrentEmployees < MAX_PPL);
}

//***************************************************************************
// Function:    count
//
// Description: Return the number of employees in the container
//
// Parameters:  None
//
// Returned:    the number of employees in the container
//***************************************************************************
std::size_t EmpContainer::SimpleContainer::count () const
{
  return mCurrentEmployees;
}

//***************************************************************************
// Function:    operator[]
//
// Description: Allow read/write access via the [] operator
//
// Parameters:  index - the index to use to find the Employee
//
// Returned:    A reference to that the entry in the container
//***************************************************************************
Employee*& EmpContainer::SimpleContainer::operator[] (std::size_t index)
{
  return mcEmployees[index];
}

//***************************************************************************
// Function:    operator[]
//
// Description: Allow read only access via the [] operator
//
// Parameters:  index - the index to use to find the Employee
//
// Returned:    A const reference to that the entry in the container
//***************************************************************************
Employee* const & EmpContainer::SimpleContainer::operator[] (std::size_t index) const
{
  return mcEmployees[index];
}

//***************************************************************************
// Function:    applyVisitor
//
// Description: Helper function that will walk through the container and
//              invoke the visitor on each element.
//
// Parameters:  rcCon - the container to walk
//              pcVisitor - the visitor to invoke
//
// Returned:    None
//***************************************************************************
void EmpContainer::applyVisitor (EmpContainer::SimpleContainer &rcCon,
  IEmployeeVisitor *pcVisitor)
{
  for (std::size_t i = 0; i < rcCon.count (); ++i)
  {
    rcCon[i]->accept (pcVisitor);
  }
}
