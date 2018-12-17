/***************************************************************************
File name:  cat.cpp
Author:     chadd
Date:       Mar 22, 2011
Class:      CS 480
Purpose:		Demonstrate gcc's C++ name mangling and virtual function table


***************************************************************************/

#include "cat.h"

/**************************************************************************
 Function:    cat::cat
 Description: construtor that sets the weight of the object
 Parameters:  w - an int
 Returned:    None
**************************************************************************/
cat::cat(int w)
{
	mWeight = w;
}

/**************************************************************************
 Function:    cat::makeSound
 Description: depending on the weight, print a particular sound
 Parameters:  None
 Returned:    None
**************************************************************************/
void cat::makeSound()
{
	mWeight > 20 ? printf("roar") : printf("meow");
}

/**************************************************************************
 Function:    cat::getWeight2
 Description: return the weight member variable declared in cat
 Parameters:  None
 Returned:    int
**************************************************************************/
int cat::getWeight2()
{
	return mWeight;
}

/**************************************************************************
 Function:    cat::bye
 Description: print bye to the screen
 Parameters:  None
 Returned:    None
**************************************************************************/
void cat::bye()
{
	printf("bye");
}

/**************************************************************************
 Function:    cat::hi
 Description: print meow hi to the screen
 Parameters:  None
 Returned:    None
**************************************************************************/
void cat::hi()
{
	printf("meow hi");
}

/**************************************************************************
Function:    cat::getTeeth
Description: return the number of teeth
Parameters:  None
Returned:    int, the number of teeth
**************************************************************************/
int cat::getTeeth ()
{
  return mTeeth;
}

/**************************************************************************
Function:    cat::nonVirtualFunction
Description: just exist as a non-virtual functin
Parameters:  None
Returned:    zero
**************************************************************************/
int cat::nonVirtualFunction ()
{
  return 0;
}

/**************************************************************************
 Function:    cat::boggle
 Description: print boggle to the screen. This serves as an example of
							overloading
 Parameters:  None
 Returned:    None
**************************************************************************/
void cat::boggle()
{
	printf("boggle");
}

/**************************************************************************
 Function:    cat::boggle
 Description: print boggle2 to the screen. This serves as an example of
							overloading
 Parameters:  x - int
 Returned:    None
**************************************************************************/
void cat::boggle(int x)
{
	printf("boggle2");
}
