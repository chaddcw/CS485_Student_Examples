//***************************************************************************
// File name:  ExampleClass.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how to use constexpr with objects
//***************************************************************************

#include "ExampleClass.h"

//***************************************************************************
//Function:    printAll
//
//Description : print the x and the y and the z to the stream
//
//Parameters : rcOut - the out stream to write to
//
//Returned : None
//***************************************************************************
void ExampleClass::printAll (std::ostream &rcOut) const
{

  rcOut << "X: " << mX << " Y: " << mY;

  if (nullptr != pInt)
  {
    rcOut << " Z: " << *pInt;
  }
}


//***************************************************************************
// Constructor: ExampleClass
//
// Description: Copy Constructor
//
// Parameters:  rcObj - the object to copy
//
// Returned:    None
//***************************************************************************

ExampleClass::ExampleClass (const ExampleClass &rcObj)
{
  std::cout << "cctor\n";
  mX = rcObj.mX;
  mY = rcObj.mY;

  delete pInt;
  if( nullptr == rcObj.pInt)
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
// Constructor: ExampleClass
//
// Description: Move Constructor
//
// Parameters:  rcObj - the object to copy
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass (ExampleClass &&rcObj)
{
  std::cout << "mctor\n";
  mX = rcObj.mX;
  mY = rcObj.mY;

  delete pInt;

  pInt = rcObj.pInt;

  rcObj.pInt = nullptr;
  
}

//***************************************************************************
// Function:    operator=
//
// Description: Copy assignment operator
//
// Parameters:  rcObj - the object to copy
//
// Returned:    a reference to *this
//***************************************************************************
ExampleClass & ExampleClass::operator=(const ExampleClass &rcObj)
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
// Function:    operator=
//
// Description: Move assignment operator
//
// Parameters:  rcObj - the object to copy
//
// Returned:    a reference to *this
//***************************************************************************
ExampleClass & ExampleClass::operator=(ExampleClass &&rcObj)
{
  std::cout << "mop=\n";
  mX = rcObj.mX;
  mY = rcObj.mY;

  delete pInt;
  pInt = rcObj.pInt;

  rcObj.pInt = nullptr;

  

  return *this;
}

//***************************************************************************
// Function:    Operator+
//
// Description: Addition operator. Add each member variable to its 
//              same in the parameter
//
// Parameters:  rcObj - the object to add to *this
//
// Returned:    A new ExampleClass object containing the result of the +
//***************************************************************************
ExampleClass ExampleClass::operator+(const ExampleClass & rcObj)
{
  std::cout << "op+\n";
  ExampleClass cRetVal (mX + rcObj.mX, mY + rcObj.mY);
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


//***************************************************************************
// Fucntion:    runnew
//
// Description: Free function, print NEW! to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void runnew ()
{
  std::cout << "NEW!" << std::endl;
}

