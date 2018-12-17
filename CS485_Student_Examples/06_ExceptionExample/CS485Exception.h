//***************************************************************************
// File name:  CS485Exception.h
// Author:     Chadd Williams
// Date:       3/9/2017
// Class:      CS485
// Assignment: Exception example
// Purpose:    Define an exception class to be used.
//***************************************************************************
#pragma once
#include <exception>

class CS485Exception : public std::exception
{
public:

  CS485Exception (int value=0);
  CS485Exception (const CS485Exception & rcOther);

  ~CS485Exception ();

  CS485Exception& operator= (CS485Exception cOther);

  virtual const char* what () const override;

private:
  int mValue;

  char *mpszMessage = nullptr;
};