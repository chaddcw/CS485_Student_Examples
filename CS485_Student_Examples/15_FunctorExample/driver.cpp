//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/18/2019
// Class:      CS485
// Assignment: Functor Example
// Purpose:    Demonstrate how the a functor can be used
//***************************************************************************


#include "LogFunctor.h"
#include "StreamFunctor.h"
#include "IntFunctor.h"
#include "FilterFunctor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool isPrefix (std::string msg, std::string prefix) {
  return 0 == msg.find (prefix);
}

bool isSuffix (std::string msg, std::string prefix) {
  return (msg.length() - prefix.length()) == msg.find (prefix);
}

//***************************************************************************
// Function:    doWork
//
// Description: Do work and log work to appropriate location
//
// Parameters:  rcLog - log to use
//
// Returned:    none
//***************************************************************************

void doWork (const LogFunctor &rcLog) {

  for (int i = 0; i < 10; ++i)
  {
    std::cout << rcLog (std::to_string (i*i));
    std::cout << std::endl;
  }
}

//***************************************************************************
// Function:    main
//
// Description: Demonstrate functors
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main () {

  LogFunctor cTestLog ("Testing");
  LogFunctor cActualLog ("Actual");

  doWork (cTestLog);
  doWork (cActualLog);

  ////
  std::vector<std::string> cVecOfValues;
  
  StreamFunctor cScreenWriter (std::cout, cActualLog);

  for (int i = 0; i < 10; ++i)
  {
    cVecOfValues.push_back (std::to_string (i*i + i));
  }

  // for_each only knows about operator()
  std::for_each (cVecOfValues.begin (), cVecOfValues.end (), cScreenWriter);

  // change each entry in the vector using the functor
  std::transform (cVecOfValues.begin (), cVecOfValues.end (),
    cVecOfValues.begin (), cTestLog);

  // show actual values in the vector
  for (int i = 0; i < 10; ++i)
  {
    std::cout << "Vector values: "<< cVecOfValues[i] << std::endl;
  }


  ///
  IntFunctor cIntFunctor (100);

  // for_each only knows about operator()
  // COMPILE ERROR!
  //std::for_each (cVecOfValues.begin (), cVecOfValues.end (), cIntFunctor);


  FilterFunctor cFindPrefix ("Test", isPrefix);
  FilterFunctor cFindSuffix ("0", isSuffix);

  // show actual values in the vector
  for (int i = 0; i < 10; ++i)
  {
    if (cFindPrefix (cVecOfValues[i]))
    {
      std::cout << "PREFIX: Vector values: " << cVecOfValues[i] << std::endl;
    }
   }

  // show actual values in the vector
  for (int i = 0; i < 10; ++i)
  {
    if (cFindSuffix (cVecOfValues[i]))
    {
      std::cout << "SUFFIX: Vector values: " << cVecOfValues[i] << std::endl;
    }
  }

  return EXIT_SUCCESS;
}