//***************************************************************************
// File name:  CS485Exception.cpp
// Author:     Chadd Williams
// Date:       3/9/2017
// Class:      CS485
// Assignment: Exception example
// Purpose:    Define an exception class to be used.
//***************************************************************************

#include "CS485Exception.h"
#include <string>

//***************************************************************************
// Constructor: CS485Exception
//
// Description: Initializes the exception, build the what string
//
// Parameters:  value - the int to reference in the what string
//
// Returned:    None
//***************************************************************************
CS485Exception::CS485Exception (int value) :mValue(value)
{

  std::string errMessage = "CS485Exception: " + std::to_string(value);

  mpszMessage = new char[errMessage.size () + 1];

  strncpy_s (mpszMessage, errMessage.size () + 1, errMessage.c_str (), 
    errMessage.size () + 1);
}

//***************************************************************************
// Constructor: CS485Exception
//
// Description: Copy constructor
//
// Parameters:  rcOther - the object to copy
//
// Returned:    None
//***************************************************************************
CS485Exception::CS485Exception (const CS485Exception & rcOther)
{
  int size;
  mValue = rcOther.mValue;
  if (nullptr != rcOther.mpszMessage)
  {
    size = strlen (rcOther.mpszMessage) + 1;
    mpszMessage = new char[size];

    strncpy_s (mpszMessage, size, rcOther.mpszMessage, size);
  }
}

//***************************************************************************
// Destructor:  ~CS485Exception
//
// Description: Deallocate the what string
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CS485Exception::~CS485Exception ()
{
  if (nullptr != mpszMessage)
  {
    delete mpszMessage;
    mpszMessage = nullptr;
  }
}


//***************************************************************************
// Function:    operator=
//
// Description: Copy assignment operator
//
// Parameters:  rcOther - the object to copy
//
// Returned:    the updated object
//***************************************************************************
CS485Exception& CS485Exception::operator= (CS485Exception cOther)
{
  using std::swap;
  mValue = cOther.mValue;
  
  std::swap (this->mpszMessage, cOther.mpszMessage);

  return *this;
}

//***************************************************************************
// Function:    what
//
// Description: Return the what string to the user
//
// Parameters:  None
//
// Returned:    the what string (null terminated)
//***************************************************************************
const char* CS485Exception::what () const
{

  return mpszMessage;
}
