//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/9/2017
// Class:      CS485
// Assignment: Demonstrate enum class
// Purpose:    Demonstrate how scoped enums work
//***************************************************************************

#include <iostream>
#include <string>

enum class Day { MON, TUE, WED, THU, FRI, SAT, SUN };
const std::string DayStr[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
enum UnscopedDay {mon, tue, wed, thur, fri, sat, sun};

int foo (char param)
{
  return param + 1;
}

int bar (bool bParam)
{
  return bParam + 1;
}


//***************************************************************************
// Function:    main
//
// Description: Demonstrate using enums
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  Day today = Day::MON;

  if (4.2 > today) // illegal
  {
    std::cout << DayStr[today]; // illegal

    std::cout << DayStr[static_cast<int>(today)]; // legal
    std::cout << std::endl;

    std::cout << DayStr[static_cast<int>(Day::FRI)]; // legal
    std::cout << std::endl;

    std::cout << foo (today); // illegal
    std::cout << bar (today); // illegal
    today = TUE; // illegal
  }

  UnscopedDay tomorrow = tue;
  if (4.2 > tomorrow) // legal
  {
    std::cout << foo (tomorrow); // legal
    std::cout << bar (tomorrow); // legal
  }

  return EXIT_SUCCESS;
}