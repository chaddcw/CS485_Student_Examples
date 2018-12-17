//***************************************************************************
// File name:  CharHolder.h
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: File reading example with >>
// Purpose:    Demonstrate how to detect EOF
//***************************************************************************
#pragma once
#include <iostream>

class CharHolder
{

public:

  friend std::istream& operator >> (std::istream &rcIn, CharHolder &rcData);
  friend std::ostream& operator << (std::ostream &rcOut, const CharHolder &rcData);
private:
  char mTheChar;
}; 
