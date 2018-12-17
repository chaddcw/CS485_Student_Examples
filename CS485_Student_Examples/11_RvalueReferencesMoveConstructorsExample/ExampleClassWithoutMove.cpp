//***************************************************************************
// File name:  ExampleClassWithoutMove.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how to use constexpr with objects
//***************************************************************************

#include "ExampleClassWithoutMove.h"

//***************************************************************************
//Function:    printAll
//
//Description : print the x and the y and the z to the stream
//
//Parameters : rcOut - the out stream to write to
//
//Returned : None
//***************************************************************************
void ExampleClassWithoutMove::printAll (std::ostream &rcOut) const
{

  rcOut << "X: " << mX << " Y: " << mY;

  if (nullptr != pInt)
  {
    rcOut << " Z: " << *pInt;
  }
}

//***************************************************************************
// Constructor: ExampleClassWithoutMove
//
// Description: Copy Constructor
//
// Parameters:  rcObj - the object to copy
//
// Returned:    None
//***************************************************************************

ExampleClassWithoutMove::ExampleClassWithoutMove (const ExampleClassWithoutMove &rcObj)
{
  std::cout << "cctor\n";
  mX = rcObj.mX;
  mY = rcObj.mY;

  delete pInt;
  if (nullptr == rcObj.pInt)
  {
    pInt = nullptr;
  }
  else
  {
    pInt = new int;
    runnew ();
    *pInt = *rcObj.pInt;
  }

  
}

//***************************************************************************
// Function:    ExampleClassWithoutMove
//
// Description: Copy assignment operator
//
// Parameters:  rcObj - the object to copy
//
// Returned:    a reference to *this
//***************************************************************************

ExampleClassWithoutMove & ExampleClassWithoutMove::operator=(const ExampleClassWithoutMove &rcObj)
{
  std::cout << "op=\n";
  mX = rcObj.mX;
  mY = rcObj.mY;

  delete pInt;
  if (nullptr == rcObj.pInt)
  {
    pInt = nullptr;
  }
  else
  {
    pInt = new int;
    runnew ();
    *pInt = *rcObj.pInt;
  }

  
  return *this;
}

//***************************************************************************
// Function:    operator+
//
// Description: Addition operator. Add each member variable to its 
//              same in the parameter
//
// Parameters:  rcObj - the object to add to *this
//
// Returned:    A new ExampleClassWithoutMove object containing the 
//              result of the addition
//***************************************************************************
ExampleClassWithoutMove ExampleClassWithoutMove::operator+(const ExampleClassWithoutMove & rcObj)
{
  std::cout << "op+\n";
  ExampleClassWithoutMove cRetVal (mX + rcObj.mX, mY + rcObj.mY);
  int *pTmpInt = nullptr;

  if (nullptr != pInt)
  {
    pTmpInt = new int;
    *pTmpInt = *pInt;
  }

  if (nullptr != rcObj.pInt)
  {
    if (nullptr != pTmpInt)
    {
      *pTmpInt += *rcObj.pInt;
    }
    else
    {
      pTmpInt = new int;
      *pTmpInt = *rcObj.pInt;
    }
  }

  cRetVal.pInt = pTmpInt;
  if (nullptr != pTmpInt)
  {
    runnew ();
  }

  
  return cRetVal;
}
