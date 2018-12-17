//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: STL Example
// Purpose:    Demonstrate how to use STL and template programming
//***************************************************************************

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <iterator>
#include <functional>
#include <algorithm>
#include "ExampleClass.h"
#include "vld.h"

//***************************************************************************
// Function:    sumThem 
//
// Description: Template function to sum two objects with + and 
//              return the result
//
// Parameters:  rLhs - the left object
//              rRhs - the right object
//              
// Returned:    the sum of rLhs and rRhs
//***************************************************************************
template<class T>
T sumThem (const T &rLhs, const T &rRhs)
{
  return rLhs + rRhs;
}


//***************************************************************************
// Function:    CompareThem 
//
// Description: Template function to compare using < two objects and
//              return the result
//
// Parameters:  rLhs - the left object
//              rRhs - the right object
//              
// Returned:    rLhs < rRhs
//***************************************************************************
template<class T>
bool CompareThem(const T &rLhs, const T &rRhs)
{
  return rLhs < rRhs;
}


//***************************************************************************
// Struct:      CompareStruct 
//
// Description: Template struct to contain the operator() function
//
// Parameters:  T - the type to use in the template
//              
//***************************************************************************
template<class T>
struct CompareStruct
{
  //**************************************************************************
  // Function:    operator() 
  //
  // Description: Template function to compare using > two objects and
  //              return the result
  //
  // Parameters:  rLhs - the left object
  //              rRhs - the right object
  //              
  // Returned:    rLhs > rRhs
  //**************************************************************************
  bool operator()(const T &rLhs, const T &rRhs) const
  {
    return rLhs > rRhs;
  }
};

//***************************************************************************
// Struct:      Compare
//
// Description: Struct to contain the operator() function for strings
//
//***************************************************************************
struct Compare {
  //**************************************************************************
  // Function:    operator() 
  //
  // Description: Function to compare the first character of two strings
  //              using > and return the result
  //
  // Parameters:  rLhs - the left string
  //              rRhs - the right string
  //              
  // Returned:    true if first character of rLhs is larger than that of rRhs.
  //**************************************************************************
  bool operator()(const std::string &rLhs, const std::string &rRhs) const
  {
    return rLhs.at(1) > rRhs.at(1);
  }
};

//***************************************************************************
// Function:    vectorOfPointers() 
//
// Description: Function to demonstrate how to use a vector of pointers
//
// Parameters:  startKey - the starting key to use to generate objects
//              numberItems - the number of objects to generate
//              
// Returned:    None
//***************************************************************************
void vectorOfPointers (int startKey, int numberItems)
{
  std::vector<ExampleClass*> cVectorOfPtrs;

  std::cout << "VECTOR OF POINTERS" << std::endl;

  // add items to the vector
  for (int i = startKey; i < startKey + numberItems ; i++)
  {
    //cVector.emplace_back (new ExampleClass (i, std::to_string (i)));
    cVectorOfPtrs.push_back (new ExampleClass (i, std::to_string (i)));
  }

  // walk the vector and display each item using []
  for (std::size_t i = 0; i < cVectorOfPtrs.size (); ++i)
  {
    std::cout << *cVectorOfPtrs[i] << std::endl;
  }

  std::cout << cVectorOfPtrs.size () << std::endl;
  std::cout << "----------------------" << std::endl;

  // walk the vector and display each item using range-for
  // http://en.cppreference.com/w/cpp/language/range-for
  for (auto const &value : cVectorOfPtrs)
  {
    std::cout << *value << std::endl;
  }

  // walk the vector and display each pointer using an iterator
  for (std::vector<ExampleClass*>::iterator it = cVectorOfPtrs.begin ();
    it != cVectorOfPtrs.end (); ++it)
  {
    // print pointer value
    std::cout << *it << std::endl;
  }
  std::cout << "----------------------" << std::endl;

  // walk the vector and display each item using for_each
  std::for_each (cVectorOfPtrs.cbegin (), 
    cVectorOfPtrs.cend (),
    [](auto cExCl) 
  {
    std::cout << "FOR_EACH: " << *cExCl << std::endl; 
  });

  std::cout << "----------------------" << std::endl;
  std::cout << cVectorOfPtrs.size () << std::endl;

  // walk the vector and display each item using a reverse iterator
  // delete each item during the walk.
  std::cout << "REVERSE" << std::endl;
  for (auto it = cVectorOfPtrs.crbegin ();
    it != cVectorOfPtrs.crend (); ++it)
  {
    std::cout << **it << std::endl;
    delete *it;
  }
  std::cout << "----------------------" << std::endl;

  cVectorOfPtrs.clear ();

  std::cout << cVectorOfPtrs.size () << std::endl;
}

//***************************************************************************
// Function:    vectorOfObjects() 
//
// Description: Function to demonstrate how to use a vector of objects
//
// Parameters:  startKey - the starting key to use to generate objects
//              numberItems - the number of objects to generate
//              
// Returned:    None
//***************************************************************************
void vectorOfObjects (int startKey, int numberItems)
{
  std::vector<ExampleClass> cVector;

  std::cout << "VECTOR OF OBJECTS" << std::endl;

  for (int i = startKey; i < numberItems + startKey; i++)
  {
    cVector.push_back (ExampleClass (i, std::to_string (i)));
    //cVector.emplace_back (ExampleClass (i, std::to_string (i)));
  }

  std::cout << cVector.size () << std::endl;
  std::cout << "----------------------" << std::endl;

  // http://en.cppreference.com/w/cpp/language/range-for
  for (auto const &value : cVector)
  {
    std::cout << value << std::endl;
  }

  std::cout << cVector.size () << std::endl;
  std::cout << "----------------------" << std::endl;
  for (std::vector<ExampleClass>::const_iterator it = cVector.cbegin ();
    it != cVector.cend (); ++it)
  {
    std::cout << *it << std::endl;
  }

  std::cout << cVector.size () << std::endl;
  std::cout << "----------------------" << std::endl;
  for (auto it = cVector.cbegin ();
    it != cVector.cend (); ++it)
  {
    std::cout << *it << std::endl;
  }
  cVector.clear ();

  std::cout << cVector.size () << std::endl;


}

//***************************************************************************
// Function:    mapOfObjects() 
//
// Description: Function to demonstrate how to use a map of objects
//
// Parameters:  startKey - the starting key to use to generate objects
//              numberItems - the number of objects to generate
//              
// Returned:    None
//***************************************************************************
void mapOfObjects (int startKey, int numberItems)
{

  //map,  pair
  //http://en.cppreference.com/w/cpp/container/map
  // usually a red-black tree
  std::map<int, ExampleClass> cTheMap;

  std::cout << "MAP OF OBJECTS" << std::endl;

  for (int i = startKey; i < startKey + numberItems; i++)
  {
    cTheMap.insert (std::make_pair (i, ExampleClass (i, std::to_string (i))));
  }

  for (auto it = cTheMap.cbegin ();
    it != cTheMap.cend (); ++it)
  {
    std::cout << it->first << " " << it->second << std::endl;
  }

  //<functional>
  std::map<int, ExampleClass, std::greater<int>> cTheMapDescending;
  for (int i = 30; i < 40; i++)
  {
    cTheMapDescending.insert (std::make_pair (i,
      ExampleClass (i, std::to_string (i))));

  }

  for (auto it = cTheMapDescending.cbegin ();
    it != cTheMapDescending.cend (); ++it)
  {
    std::cout << it->first << " " << it->second << std::endl;
  }


  std::cout << "----------------------" << std::endl;
  std::cout << "----------------------" << std::endl;

}

//***************************************************************************
// Function:    sortedMapOfObjects() 
//
// Description: Function to demonstrate how to use a map of objects
//
// Parameters:  startKey - the starting key to use to generate objects
//              numberItems - the number of objects to generate
//              
// Returned:    None
//***************************************************************************
void sortedMapOfObjects (int startKey, int numberItems)
{

  std::cout << "SORTED MAP OF OBJECTS" << std::endl;

  srand (2);
  std::map<std::string,ExampleClass, struct Compare> cTheMapStringsDescending;
  for (int i = startKey; i < startKey+numberItems; i++)
  {
    cTheMapStringsDescending.insert (std::make_pair (std::to_string(rand()),
      ExampleClass (i, std::to_string (i))));
  }
  std::cout << "----------------------" << std::endl;

  for (auto it = cTheMapStringsDescending.cbegin ();
    it != cTheMapStringsDescending.cend (); ++it)
  {
    std::cout << it->first << " " << it->second << std::endl;
  }
  std::cout << "----------------------" << std::endl;

  
  std::map<std::string, ExampleClass, struct CompareStruct<std::string>> 
    cTheMapStringsCompareStruct;
  for (int i = startKey; i < startKey + numberItems; i++)
  {
    cTheMapStringsCompareStruct.insert (std::make_pair 
    (std::to_string (rand ()), ExampleClass (i, std::to_string (i))));
  }
  std::cout << "----------------------" << std::endl;

  for (auto it = cTheMapStringsCompareStruct.cbegin ();
    it != cTheMapStringsCompareStruct.cend (); ++it)
  {
    std::cout << it->first << " " << it->second << std::endl;
  }
  std::cout << "--------COMPARE THEM--------------" << std::endl;

  auto func = [](auto &rLhs, auto &rRhs)
  { 
    return CompareThem<std::string> (rLhs, rRhs); 
  };

  std::map < std::string, ExampleClass, decltype(func)>
    cTheMapStringsCompareLambda(func);
  for (int i = startKey; i < startKey+numberItems; i++)
  {
    cTheMapStringsCompareLambda.insert (std::make_pair 
    (std::to_string (rand ()), ExampleClass (i, std::to_string (i))));
  }
  std::cout << "----------------------" << std::endl;

  for (auto it = cTheMapStringsCompareLambda.cbegin ();
    it != cTheMapStringsCompareLambda.cend (); ++it)
  {
    std::cout << it->first << " " << it->second << std::endl;
  }

}

//***************************************************************************
// Function:    unorderedMapOfObjects() 
//
// Description: Function to demonstrate how to use an unordered_map of objects
//
// Parameters:  startKey - the starting key to use to generate objects
//              numberItems - the number of objects to generate
//              
// Returned:    None
//***************************************************************************
void unorderedMapOfObjects (int startKey, int numberItems) 
{

  //unordered_map
  // http://en.cppreference.com/w/cpp/container/unordered_map
  // hash table
  std::unordered_map<int, ExampleClass> cTheHashMap;

  std::cout << "UNOREDED_MAP OF OBJECTS" << std::endl;

  for (int i = startKey; i < startKey+numberItems; i++)
  {
    cTheHashMap.insert (std::make_pair (i, ExampleClass 
    (i, std::to_string (i))));

  }

  for (auto it = cTheHashMap.cbegin ();
    it != cTheHashMap.cend (); ++it)
  {
    std::cout << it->first << " " << it->second << std::endl;
  }
  std::cout << "----------------------" << std::endl;

  auto hashFunc = [](auto &key) 
  { 
    return key + 1; 
  };

  std::unordered_map<int, ExampleClass, decltype(hashFunc)> 
    cTheHashMapHashGiven (1024, hashFunc);
  for (int i = 60; i < 70; i++)
  {
    cTheHashMapHashGiven.insert (std::make_pair (i, 
      ExampleClass (i, std::to_string (i))));

  }

  for (auto it = cTheHashMapHashGiven.cbegin ();
    it != cTheHashMapHashGiven.cend (); ++it)
  {
    std::cout << it->first << " " << it->second << " HASH: " <<
      hashFunc(it->first) <<std::endl;
  }
  std::cout << "----------------------" << std::endl;
}

//***************************************************************************
// Function:    main
//
// Description: Demonstrate template functions and invoke the functions 
//              that demonstrate STL containers
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  
  auto value = sumThem (1, 2);

  std::cout << value << std::endl;

  std::cout << sumThem (1, 2) << std::endl;
  std::cout << sumThem (1.1, 2.2) << std::endl;
  //std::cout << sumThem (1.1, 2) << std::endl; // type mismatch
  //std::cout << sumThem ('a', 1) << std::endl; // type mismatch
  //std::cout << sumThem ("test", "test") << std::endl; // const char * 
  std::cout << sumThem (std::string ("CS"), std::string ("485")) << std::endl;
  

  // Containers
  vectorOfPointers (0, 10);

  std::cout << "----------------------" << std::endl;
  std::cout << "----------------------" << std::endl;

  vectorOfObjects (10, 10);

  std::cout << "----------------------" << std::endl;
  std::cout << "----------------------" << std::endl;
  //// list is very similar to vector. different backing store.

  mapOfObjects (20, 10);

  std::cout << "----------------------" << std::endl;
  std::cout << "----------------------" << std::endl;

  sortedMapOfObjects (30, 10);
  
  std::cout << "----------------------" << std::endl;
  std::cout << "----------------------" << std::endl;

  unorderedMapOfObjects (40, 10);
  std::cout << "----------------------" << std::endl;
  std::cout << "----------------------" << std::endl;

  return EXIT_SUCCESS;
}
