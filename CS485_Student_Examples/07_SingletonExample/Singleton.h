//***************************************************************************
// File name:  Singleton.h
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: Singleton Example
// Purpose:    Demonstrate Meyer's Singleton Example in C++11
//***************************************************************************
#pragma once
#include <iostream>

class Singleton
{
public:

  // More Effective C++: S. Meyers. (modified)

  static Singleton& Instance ();

  // non-static public methods
  void incrCount ();

  friend std::ostream& operator<<(std::ostream &rcOut,
    const Singleton &rcData);

private:
  Singleton ();                                     // ctor is hidden
  Singleton (Singleton const&) = delete;            // copy ctor is hidden

  ~Singleton (); // not virtual, no subclass. hidden so no user can delete obj.

  Singleton& operator=(Singleton const&) = delete;  // assign op is hidden

                                                    // private data members
  int mCounter = 0;

};