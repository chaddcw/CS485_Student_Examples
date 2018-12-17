/***************************************************************************
File name:  cat.h
Author:     chadd
Date:       April 27, 2017
Class:      CS 485
Purpose:		Demonstrate VS's C++ name mangling and virtual function table

cl.exe /c /d1reportSingleClassLayoutcat cat.cpp > cat_single.out

cl.exe /c /d1reportSingleClassLayoutanimal animal.cpp > animal_single.out

***************************************************************************/


#pragma once

#include "animal.h"

class cat : public animal
{
  public:
    cat(int w);

    void makeSound();
    int getWeight2();
    void bye();
    void boggle();
    void boggle(int x);
    void hi();

    virtual int getTeeth ();

    int nonVirtualFunction ();
private:
  int mWeight;
  int mTeeth;
};


