/***************************************************************************
File name:  main.cpp
Author:     chadd
Date:       Mar 22, 2011
Class:      CS 480
Purpose:		Demonstrate gcc's C++ name mangling and virtual function table

***************************************************************************/

#include "animal.h"
#include "cat.h"
#include <iostream>

int foo (int x)
{
  return 42;
}

int foo ()
{
  return 42;
}

int foo (float z)
{
  return 42;
}

void testRTTI (animal *pcAnimal)
{

  std::cout << "\nSTART TEST RTTI\n\n";
  std::cout << (dynamic_cast<cat *>(pcAnimal))->getTeeth ();
  std::cout << std::endl;

  std::cout << typeid(*pcAnimal).name () << std::endl;

  std::cout << typeid(*pcAnimal).raw_name () << std::endl;
  std::cout << "\nEND TEST RTTI\n\n";
}


int main()
{
  animal *pAn = new cat(93);
  pAn->makeSound();
  printf("\ngetWeight: %d\n",pAn->getWeight());
  printf("getWeight2: %d\n",pAn->getWeight2());
  pAn->hi();
  //pAn->bye();     // ????

  testRTTI (pAn);
  delete pAn;
}
