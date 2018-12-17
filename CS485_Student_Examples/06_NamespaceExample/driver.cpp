//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/9/2017
// Class:      CS485
// Assignment: Demonstrate namespaces
// Purpose:    Demonstrate how namespaces can be use
//***************************************************************************


#include <iostream>
#include <string>

namespace CS485
{
  const std::string objects = "have data and responsibilities";
}

namespace CS250
{
  const std::string objects = "have data and functionality";
}





//***************************************************************************
// Function:    outputDef
//
// Description: Use namespaces to output strings
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void outputDef ()
{
  using CS485::objects;

  std::cout << objects; // legal!

  std::cout << CS250::objects << std::endl;

  std::cout << CS485::objects << std::endl;
}

//***************************************************************************
// Function:    main
//
// Description: Demonstrate namespaces
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  outputDef ();

  std::cout << objects; // illegal!

  std::cout << CS250::objects << std::endl;

  std::cout << CS485::objects << std::endl;

  return EXIT_SUCCESS;
}