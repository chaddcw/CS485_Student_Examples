/***************************************************************************
File name:  animal.h
Author:     chadd
Date:       April 27, 2017
Class:      CS 485
Purpose:		Demonstrate VS's C++ name mangling and virtual function table

cl.exe /c /d1reportSingleClassLayoutcat cat.cpp > cat_single.out

cl.exe /c /d1reportSingleClassLayoutanimal animal.cpp > animal_single.out

***************************************************************************/


#pragma once

#include <stdio.h>

class animal 
{
  public:
    animal() ;
    animal(int w);
    int getWeight() ;
    void setWeight (int *w);

    virtual int eat(animal &pA);
    virtual void makeSound () = 0;
    virtual int getWeight2 () = 0;
    virtual void hi ();
    
private:
  int mWeight;
  int mHeight;

  static int mSTATIC;
  static const int mSTATIC_CONST = 1 ;
};
