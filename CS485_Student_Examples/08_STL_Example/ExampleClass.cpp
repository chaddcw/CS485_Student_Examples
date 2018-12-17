//***************************************************************************
// File name:  ExampleClass.cpp
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: STL Example
// Purpose:    Demonstrate how to use STL and template programming
//***************************************************************************
#include "ExampleClass.h"

//***************************************************************************
// Constructor: Default Constructor
//
// Description: Initializes data members to default values
//              Display message that the ctor was called
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass () : mKey(-1), mSecretData("unknown")
{
  if (CTOR_MSGS)
  {
    std::cout << "ctor " << *this << std::endl;
  }
}

//***************************************************************************
// Constructor: ExampleClass
//
// Description: Initializes data members to the given values
//              Display message that the ctor was called
//
// Parameters:  key - int to use for mKey
//              secreteData - string to use for mSecretData
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass (int key, std::string secretData) :
  mKey(key), mSecretData(secretData)
{
  if (CTOR_MSGS)
  {
    std::cout << "ctor() " << *this << std::endl;
  }
}

//***************************************************************************
// Constructor: Copy Constructor
//
// Description: Copy the given object into the new object
//              Display message that the ctor was called
//
// Parameters:  rcData - the object to copy
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass (const ExampleClass &rcData) :
  mKey (rcData.mKey), mSecretData (rcData.mSecretData)
{
  if (CTOR_MSGS)
  {
    std::cout << "cctor " << *this << std::endl;
  }
}

//***************************************************************************
// Destructor:  ~ExampleClass
//
// Description: print a message to state the dtor was called
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ExampleClass::~ExampleClass ()
{
  if (CTOR_MSGS)
  {
    std::cout << "dtor" << *this << std::endl;
  }
}

//***************************************************************************
// Function:    operator=
//
// Description: Copy assignment operator
//
// Parameters:  rcData - the data to copy
//
// Returned:    The current object
//***************************************************************************
ExampleClass & ExampleClass::operator=(ExampleClass cData)
{
  std::swap (this->mKey, cData.mKey);
  std::swap (this->mSecretData, cData.mSecretData);

  return *this;
}

//***************************************************************************
// Function:    operator>
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this > RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator>(const ExampleClass &rcData) const
{
  return mKey > rcData.mKey;
}

//***************************************************************************
// Function:    operator<
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this < RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator<(const ExampleClass &rcData) const
{
  return mKey < rcData.mKey;
}

//***************************************************************************
// Function:    operator==
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this == RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator==(const ExampleClass &rcData) const
{
  return mKey == rcData.mKey;

}

//***************************************************************************
// Function:    operator>=
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this >= RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator>=(const ExampleClass &rcData) const
{
  return mKey >= rcData.mKey;
}

//***************************************************************************
// Function:    operator<=
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this <= RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator<=(const ExampleClass &rcData) const
{
  return mKey <= rcData.mKey;
}

//***************************************************************************
// Function:    operator<<
//
// Description: Write the object to the stream
//
// Parameters:  rcOut - the stream to write to
//              rcData - the object to write
//
// Returned:    the output stream
//***************************************************************************
std::ostream& operator<<(std::ostream &rcOut, const ExampleClass &rcData)
{
  rcOut << rcData.mKey << ":" << rcData.mSecretData;
  return rcOut;
}