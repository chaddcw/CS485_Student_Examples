//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Lambda Examples
// Purpose:    Demonstrate how to use lambda, focus on variable capture 
//***************************************************************************

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <typeinfo>

//***************************************************************************
// Function:    takeOperator
//
// Description: Takes a function as a parameter and invokes that function
//              the return value of the passed in function is returned
//
// Parameters:  func - function with prototype int(int,int)
//
// Returned:    the return value of func(1,100)
//***************************************************************************
int takeOperator (std::function<int (int, int)> func)
{
  return func (1, 100);
}

//***************************************************************************
// Function:    changeOperator
//
// Description: Takes a function as a by-reference parameter and replaces that
//              function with a new function.  The new function is then
//              invoked and the return value of the new function 
//              is returned
//
// Parameters:  func - function with prototype int(int,int)
//
// Returned:    the return value of func(2,2)
//***************************************************************************
int changeOperator (std::function<int (int, int)> &func)
{
  func = [] (int param1, int param2) -> int
  {
    return param1 * param2;
  };
  return func (2, 2);
}

//***************************************************************************
// Function:    changeOperatorSecretRef
//
// Description: Takes a function as a by-reference parameter and replaces that
//              function with a new function.  The new function is then
//              invoked and the return value of the new function 
//              is returned
//              The new function captures a local variable by reference
// 
// Parameters:  func - function with prototype int(int,int)
//
// Returned:    the return value of func(2,2)
//***************************************************************************
int changeOperatorSecretRef (std::function<int (int, int)> &func)
{
  int secret = 42;
  func = [&](int param1, int param2) -> int
  {
    return param1 * param2 * secret;
  };
  return func (2, 2);
}

//***************************************************************************
// Function:    changeOperatorSecretCopy
//
// Description: Takes a function as a by-reference parameter and replaces that
//              function with a new function.  The new function is then
//              invoked and the return value of the new function 
//              is returned
//              The new function captures a local variable by copy
// 
// Parameters:  func - function with prototype int(int,int)
//
// Returned:    the return value of func(2,2)
//***************************************************************************
int changeOperatorSecretCopy (std::function<int (int, int)> &func)
{
  int secret = 42;
  func = [=](int param1, int param2) -> int
  {
    return param1 * param2 * secret;
  };
  return func (2, 2);
}

//***************************************************************************
// Function:    main
//
// Description: Create and invoke various lambda functions for demonstration
// 
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  std::vector<int> cLocalVector;

  auto list = { 1,2,3,4,5 };

  // capture the cLocalVector by reference
  std::for_each(list.begin(), list.end(),
    [&](auto cItem)
  {
    cLocalVector.push_back (cItem);
  });

  // capture the cLocalVector by copy
  // mutable keyword allows you to modify
  // a copy-capture variable
  std::for_each (list.begin (), list.end (),
    [cLocalVector](auto cItem) mutable
  {
    cLocalVector.push_back (cItem);
    std::cout << cItem << " < " << std::endl;
  });

  // print the vector
  // no capture necessary
  std::for_each (cLocalVector.begin (), cLocalVector.end (),
    [](auto cItem)
  {
    std::cout << cItem << std::endl;
  });


  // store a function into a variable
  auto func = 
  [](int param1, int param2) -> int
  { 
    return param1 + param2;
  };

  // invoke the function
  std::cout << func (1, 2) << std::endl;

  /// explicitly type the variable as an std::function
  std::function<int(int,int)> add =
    [](int param1, int param2) -> int
  {
    return param1 + param2;
  };

  // invoke the function
  std::cout << add (1, 2) << std::endl;

  // create an array of functions
  std::function<int (int, int)> aMathOps[2] =
  {
    [] (int param1, int param2) -> int
    {
      return param1 + param2;
    },
    [](int param1, int param2) -> int
    {
      return param1 - param2;
    }
  };

  std::cout << std::endl;

  // invoke each function in the array
  std::cout << "aMathOps[0] " << aMathOps[0] (1, 2) << std::endl;
  std::cout << "aMathOps[1] " << aMathOps[1] (1, 2) << std::endl;

  // pass the function to a function
  std::cout << std::endl;
  std::cout << "aMathOps[0] " << takeOperator(aMathOps[0]) << std::endl;

  int secret = 1138;

  // create a function and bind the variable secret by copy
  std::function<int (int, int)> secretHash =
    [secret](int param1, int param2) -> int
  {
    return param1 + param2 + secret;
  };


  // pass the function to a function, the value of secret remains
  std::cout << std::endl;
  std::cout << "secret " << takeOperator (secretHash) << std::endl;


  // pass the function by reference so the function may be altered!
  std::cout << std::endl;
  std::cout << "changeOperator " << changeOperator (aMathOps[0]) << std::endl;
  std::cout << "aMathOps[0] " << aMathOps[0] (10, 2) << std::endl;
  

  std::cout << std::endl;
  std::cout << "changeOperatorSecretRef " << 
    changeOperatorSecretRef (aMathOps[1]) << std::endl;
  takeOperator (aMathOps[1]);
  std::cout << "aMathOps[1] " << aMathOps[1] (10, 2) << std::endl;

  std::cout << std::endl;
  std::cout << "changeOperatorSecretCopy " << 
    changeOperatorSecretCopy(aMathOps[1]) << std::endl;
  takeOperator (aMathOps[1]);
  std::cout << "aMathOps[1] " << aMathOps[1] (10, 2) << std::endl;

  return EXIT_SUCCESS;
}
