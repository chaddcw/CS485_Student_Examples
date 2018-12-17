//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/9/2017
// Class:      CS485
// Assignment: Demonstrate exceptions
// Purpose:    Demonstrate how exceptions are caught and thrown
//***************************************************************************

#include <iostream>
#include "CS485Exception.h"
#include <exception>
#include <memory>
//#include "vld.h"

// throw() specification
// depreciated in C++11
void foo () throw();
void bar () throw(CS485Exception);
void rab () throw(...);


//***************************************************************************
// Function:    riskyException
//
// Description: Demonstrate the risks of throwing an exception
//
// Parameters:  param - int to store in the new unsigned int
//
// Returned:    pointer to a new unsigned int
//***************************************************************************
//int cantThrowException (char data) noexcept;
unsigned int *riskyException (int param) noexcept(false)
{
  CS485Exception cException = CS485Exception(204);

  unsigned int *pRetVal = new unsigned int;

  if (0 > param)
  {
    throw std::range_error ("Negative value!");
  }

  *pRetVal = param;

  return pRetVal;
}

void mightThrowExceptionSmart (std::shared_ptr<unsigned int> p) 
  noexcept(false)
{
  throw CS485Exception(51);
}

void mightThrowException (unsigned int *pValue) noexcept(false)
{
  throw CS485Exception (56);
}

//***************************************************************************
// Function:    unknownException
//
// Description: Demonstrate the risks of calling code that might throw
//              an exception
//
// Parameters:  param - int to store in the new unsigned int
//
// Returned:    pointer to a new unsigned int
//***************************************************************************
unsigned int *unknownException (int param) noexcept(false)
{
  CS485Exception cException;

  unsigned int *pRetVal = new unsigned int;

  mightThrowException (pRetVal);

  return pRetVal;
}

//***************************************************************************
// Function:    safeUnknownException
//
// Description: Demonstrate how to mitigate the risks of calling code that 
//              might throw an exception by using smart_pointers
//
// Parameters:  param - int to store in the new unsigned int
//
// Returned:    pointer to a new unsigned int
//***************************************************************************
std::shared_ptr<unsigned int> safeUnknownException (int param) noexcept(false)
{
  CS485Exception cException;

  auto pRetVal (std::make_shared<unsigned int> ());

  mightThrowExceptionSmart (pRetVal);

  return pRetVal;
}

//***************************************************************************
// Function:    main
//
// Description: Demonstrate catching exceptions
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main ()
{
  std::bad_alloc cNotAString;

  unsigned int *pUInt = nullptr;

  int *paValues;
  int size = -1;

  try
  {
    paValues = new int[size]; // try to allocate array of size -1
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what () << std::endl;
  }
  catch (...)
  {
    std::cout << "Unknown exception" << std::endl;
  }

  try
  {
    dynamic_cast<std::string&>(cNotAString);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what () << std::endl;
  }

  try
  {
    throw CS485Exception (42);
  }
  catch (const CS485Exception &e)
  {
    std::cout << e.what () << std::endl;
  }

  try
  {
    pUInt = riskyException (-9);
  }
  catch (const std::range_error &e)
  {
    std::cout << e.what () << std::endl;
  }

  try
  {
    pUInt = riskyException (-9);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what () << std::endl;
  }

  try
  {
    pUInt = unknownException (-11);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what () << std::endl;
  }

  try
  {
    auto pSafeReturn = safeUnknownException(-12);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what () << std::endl;
  }
  //throw CS485Exception (0);

  return EXIT_SUCCESS;
}