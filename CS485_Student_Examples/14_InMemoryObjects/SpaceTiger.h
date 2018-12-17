/***************************************************************************
File name:  SpaceTiger.h
Author:     chadd
Date:       April 27, 2017
Class:      CS 485
Purpose:		Demonstrate VS's C++ name mangling and virtual function table

cl.exe /c /d1reportSingleClassLayoutcat cat.cpp > cat_single.out

cl.exe /c /d1reportSingleClassLayoutanimal animal.cpp > animal_single.out

***************************************************************************/


#pragma once

#include "tiger.h"
#include "SpaceCreature.h"

class SpaceTiger : public tiger, public SpaceCreature
{
public:
  SpaceTiger (int w, int oxygen);

  void useOxygen ();

  void hi ();


private:

  int mSpaceStripes;

};


