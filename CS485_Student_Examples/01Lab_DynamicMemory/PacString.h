//***************************************************************************
// File name:  PacString.h
// Author:     Chadd Williams
// Date:       2/3/2017
// Class:      CS485
// Assignment: Dynamic Memory Lab
// Purpose:    Practice using raw pointers
//***************************************************************************
#pragma once
#include <iostream>

class PacString
{
public:
  PacString ();
  PacString (const char *pszString);
  PacString (const PacString &rcData);

  virtual ~PacString ();


  // write both operator=, but only compile
  // one at a time.
  // PacString& operator=(const PacString &rcData);

  PacString& operator=(PacString rcData);

  friend std::ostream& operator<<(std::ostream &out, const PacString &rcData);

  PacString& operator+=(const PacString &rcData);
  PacString operator+(const PacString &rcData) const;

private:
  char *mpszData = nullptr;
};