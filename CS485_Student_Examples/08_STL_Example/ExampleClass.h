//***************************************************************************
// File name:  ExampleClass.h
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: STL Example
// Purpose:    Demonstrate how to use STL and template programming
//***************************************************************************

#pragma once
#include <string>
#include <iostream>


class ExampleClass
{
public:

  ExampleClass ();
  ExampleClass (int key, std::string secretData);
  ExampleClass (const ExampleClass &rcData);
  ~ExampleClass ();


  ExampleClass& operator=(ExampleClass cData);


  bool operator>(const ExampleClass &rcData) const;
  bool operator<(const ExampleClass &rcData) const;
  bool operator==(const ExampleClass &rcData) const;
  bool operator>=(const ExampleClass &rcData) const;
  bool operator<=(const ExampleClass &rcData) const;
  
  friend std::ostream& operator<<(std::ostream &rcOut, 
    const ExampleClass &rcData);

private:
  int mKey;
  std::string mSecretData;
  static const bool CTOR_MSGS = false;
};
