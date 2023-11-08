// File: WordCList.h
// Purpose: Container of WordData objects, CLinkedList 
// Implementations of member functions including inherited 
// pure virtual fns.

/*!	\file WordCList.h 
 * *	\brief CLinkedList subclass implementation of WordList
 * *	\class WordCList 
 * *    \brief CLinkedList subclass implementation of WordList
 * */
#ifndef WORDCLIST_H
#define WORDCLIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include "CLinkedList.h"

using namespace std;

class WordCList : public WordList {
public:

///                                                                  
///Function Name: WordCList                                  
///                                                                  
///Description:   constructor for a WordCList data
///               structure
///                                                                   
///Parameters:    None           
///
///Return:        None
/// 
  WordCList();

  //Put a string of strings into the list object
  virtual void parseIntoList(ifstream &inf);
  //
  // Print the data iteratively
  virtual void printIteratively();
  
  // Print the data recursively
  virtual void printRecursively();
  
  //Print the data recursively with a pointer
  virtual void printPtr();

private:

  CLinkedList<WordData> TheWords;

///                                                                  
///Function Name: incMatch                                  
///                                                                  
///Description: Takes the current word and checks
///             to see if it is in the object, if
///             so, increment the count of that word
///                                                                   
///Parameters:  string temp - the current word           
///
///Return:      bool - true if a match is found, otherwise
///             false
///
  //Look for a match and increment if found
  bool incMatch(string temp);
  
///                                                                  
///Function Name: printRecursivelyWorker                                  
///                                                                  
///Description: Helper function that moves the position
///             of the iterator and prints the values
///                                                                   
///Parameters:  CListItr<WordData> itr - the current
///             position in the data object           
///
///Return:      void
///
  // Function to actually perform recursive print
  void printRecursivelyWorker(CListItr<WordData> itr);
  
  //Function to actually perform recursive print using pointer
  //Dont Need --- void printPtrWorker(int numWords);
  
  
  };
#endif
