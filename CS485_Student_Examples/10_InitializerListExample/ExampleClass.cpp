//***************************************************************************
// File name:  ExampleClass.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Initialize List Example
// Purpose:    Demonstrate how to use std::initializer_list
//***************************************************************************
#include "ExampleClass.h"
#include <algorithm>


//***************************************************************************
// Constructor: ExampleClass
//
// Description: copy items from the initializer_list to the private vector
//
// Parameters:  cList – the std::initialize_list
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass (std::initializer_list<int> cList)
{
  std::for_each (cList.begin (), cList.end (),
    [this](auto cItem) 
    { 
      cVec.push_back (cItem); 
    }
  );
}

//***************************************************************************
// Function:    printAll
//
// Description: print all the items in the private vector to rcOut
//
// Parameters:  rcOut - the out stream to write to
//
// Returned:    None
//***************************************************************************
void ExampleClass::printAll (std::ostream &rcOut) const
{
  std::for_each (cVec.begin (), cVec.end (),
    [&](auto cItem) 
    { 
      rcOut << cItem << std::endl; 
    }
  );

}
