//***************************************************************************
// File name:  ExampleClass.h
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Initialize List Example
// Purpose:    Demonstrate how to use std::initializer_list
//***************************************************************************
#pragma once
#include <initializer_list>
#include <vector>
#include <iostream>

class ExampleClass
{
public:
  ExampleClass (std::initializer_list<int> cList);

  void printAll (std::ostream &rcOut) const;

private:
  std::vector<int> cVec;

};