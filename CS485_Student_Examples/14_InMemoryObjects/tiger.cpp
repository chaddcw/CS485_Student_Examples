/***************************************************************************
File name:  tiger.cpp
Author:     chadd
Date:       April 27, 2017
Class:      CS 485
Purpose:		Demonstrate gcc's C++ name mangling and virtual function table


***************************************************************************/
#include "tiger.h"

/**************************************************************************
Function:    tiger::tiger
Description: constructor that calls the cat ctor with the parameter
Parameters:  int - weight
Returned:    None
**************************************************************************/
tiger::tiger (int w) : cat(w)
{
}

/**************************************************************************
Function:    tiger::getWeight2
Description: return 2
Parameters:  None
Returned:    2
**************************************************************************/
int tiger::getWeight2 ()
{
  return 2;
}

/**************************************************************************
Function:    tiger::hi
Description: Do nothing
Parameters:  None
Returned:    None
**************************************************************************/
void tiger::hi ()
{
}

/**************************************************************************
Function:    tiger::nonVirtualFunction
Description: Exist as a non-virtual function
Parameters:  None
Returned:    int, 0
**************************************************************************/
int tiger::nonVirtualFunction ()
{
  return 0;
}
