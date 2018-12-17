/***************************************************************************
File name:  animal.cpp
Author:     chadd
Date:       Mar 22, 2011
Class:      CS 480
Purpose:		Demonstrate gcc's C++ name mangling and virtual function table


***************************************************************************/


#include "animal.h"

/**************************************************************************
 Function:    animal::animal
 Description: default construtor that sets the weight of the object to -1
 Parameters:  None
 Returned:    None
**************************************************************************/
animal::animal()
{
	mWeight = -1;
}

/**************************************************************************
 Function:    animal::animal
 Description: construtor that sets the weight of the object to w
 Parameters:  w - an int
 Returned:    None
**************************************************************************/
animal::animal(int w)
{
	mWeight = w;
}

/**************************************************************************
 Function:    animal::hi
 Description: display hi to the screen
 Parameters:  None
 Returned:    None
**************************************************************************/
void animal::hi()
{
	printf("HI");
}

/**************************************************************************
 Function:    animal::getWeight
 Description: return the weight
 Parameters:  None
 Returned:    int
**************************************************************************/
int animal::getWeight()
{
	return mWeight;
}


/**************************************************************************
 Function:    animal::setWeight
 Description: set the weight of the animal to the parameter *w
  						This serves as an example of overloading
 Parameters:  w - a pointer to an int
 Returned:    None
**************************************************************************/
void animal::setWeight(int *w)
{
	mWeight = *w;
}


/**************************************************************************
 Function:    animal::eat
 Description: Eat the provided animal and take on 90% of its weight
 	 	 	 	 	 	 	The eaten animal has its weight set to zero
 Parameters:  pA an animal, by reference
 Returned:    The weight of the eaten animal, zero
**************************************************************************/
int animal::eat(animal &pA)
{
	// it takes 10% of the weight of the eaten animal to
	// digest that animal.
	mWeight += pA.getWeight() * 0.9;
	pA.setWeight(0);
	return pA.getWeight();
}
