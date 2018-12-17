/***************************************************************************
File name:  SpaceTiger.cpp
Author:     chadd
Date:       April 27, 2017
Class:      CS 485
Purpose:		Demonstrate gcc's C++ name mangling and virtual function table


***************************************************************************/

#include "SpaceTiger.h"

/**************************************************************************
Function:    SpaceTiger::SpaceTiger
Description: constructor that calls the tiger and SpaceCreature ctors
Parameters:  w : weight for tiger
             oxygen : int oxygen for SpaceCreature
Returned:    None
**************************************************************************/
SpaceTiger::SpaceTiger (int w, int oxygen) : tiger(w), SpaceCreature(oxygen)
{
}

/**************************************************************************
Function:    SpaceTiger::useOxygen
Description: Call SpaceCreature::useOxygen () twice
Parameters:  None
Returned:    None
**************************************************************************/
void SpaceTiger::useOxygen ()
{
  SpaceCreature::useOxygen ();
  SpaceCreature::useOxygen ();
}

/**************************************************************************
Function:    SpaceTiger::hi
Description: Do nothing
Parameters:  None
Returned:    None
**************************************************************************/
void SpaceTiger::hi ()
{
}
