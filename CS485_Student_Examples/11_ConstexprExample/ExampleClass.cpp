//***************************************************************************
// File name:  ExampleClass.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how to use constexpr with objects
//***************************************************************************
#include "ExampleClass.h"
#include <algorithm>



/***************************************************************************
 Function:    printAll

 Description: print both the x and the y to the stream

 Parameters:  rcOut - the out stream to write to

 Returned:    None
***************************************************************************/
void ExampleClass::printAll (std::ostream &rcOut) const
{
  
  rcOut << "X: " << mX << " Y: " << < mY;;

}
