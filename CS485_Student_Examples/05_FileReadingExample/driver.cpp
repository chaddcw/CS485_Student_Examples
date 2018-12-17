//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/21/2017
// Class:      CS485
// Assignment: File reading example with >>
// Purpose:    Demonstrate how to detect EOF
//***************************************************************************

#include "CharHolder.h"
#include "IntHolder.h"
#include <fstream>
//#include "vld.h"
//***************************************************************************
// Function:    main
//
// Description: Open the file example.txt and read objects. The first 
//              character on the line determines what type of object is read.
//              The objects are the immediately printed to the screen,
//              prepended with the current line number of the file.
//
// Parameters:  none
//
// Returned:    int - EXIT_SUCCESS or EXIT_FAILURE
//***************************************************************************

int main ()
{
  IntHolder cTheInt;
  CharHolder cTheChar;
  char prefix;
  int lineNumber = 1;

  std::ifstream cInFile;

  cInFile.open ("example.txt");
  if (!cInFile)
  {
    std::cerr << " Cannot open file \n\n";
    return EXIT_FAILURE;
  }

  while (cInFile >> prefix)
  {
    std::cout << lineNumber++ << " ";
    switch (prefix)
    {
    case 'I':
      cInFile >> cTheInt;
      std::cout << cTheInt << std::endl;
      break;
    case 'C':
      cInFile >> cTheChar;
      std::cout << cTheChar << std::endl;
      break;
    }
  }

  cInFile.close ();

  return EXIT_SUCCESS;
}