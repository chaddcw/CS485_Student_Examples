//***************************************************************************
// File name:  IntHolder.h
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: File reading example with >>
// Purpose:    Demonstrate how to detect EOF
//***************************************************************************
#pragma once
#include <iostream>

class IntHolder
{

public:

  friend std::istream& operator >> (std::istream &rcIn, IntHolder &rcData);
  friend std::ostream& operator << (std::ostream &rcOut, const IntHolder &rcData);
private:
  int mTheInt;
};