/***************************************************************************
File name:  SpaceCreature.cpp
Author:     chadd
Date:       April 27, 2017
Class:      CS 485
Purpose:		Demonstrate gcc's C++ name mangling and virtual function table


***************************************************************************/
#include "SpaceCreature.h"

/**************************************************************************
Function:    SpaceCreature::SpaceCreature
Description: Constructor that sets the Oxygen level
Parameters:  oxygen : int oxygen for SpaceCreature
Returned:    None
**************************************************************************/
SpaceCreature::SpaceCreature (int oxygen)
{
  mOxygen = oxygen;
}

/**************************************************************************
Function:    SpaceCreature::getOxygen
Description: return oxygen level
Parameters:  None
Returned:    int
**************************************************************************/
int SpaceCreature::getOxygen () const
{
  return mOxygen;
}

/**************************************************************************
Function:    SpaceCreature::useOxygen 
Description: Decrement oxygen by 1
Parameters:  None
Returned:    None
**************************************************************************/
void SpaceCreature::useOxygen ()
{
  mOxygen--;
}
