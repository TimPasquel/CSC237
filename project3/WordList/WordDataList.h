// File: WordDataList.h
// Container of WordData objects. 
// Printing can be iterative or recursive. 


/*!	\file WordDataList.h 
 * *	\brief An obj. arry implementation of WordList
 * *	\class WordDataList 
 * *	\brief An obj. array implementation of WordList
 * */

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

class WordDataList : public WordList {
public:

///                                                                  
///Function Name: WordDataList                                  
///                                                                  
///Description:   constructor for a WordDataList data
///               structure
///                                                                   
///Parameters:    None           
///
///Return:        None
/// 
  WordDataList();

  // Put a string of strings into the list object
  virtual void parseIntoList(ifstream &inf);

  // Print the data iteratively
  virtual void printIteratively();
  
  // Print the data recursively
  virtual void printRecursively();
  
  // Print the data recursively with a pointer
  virtual void printPtr();

private:
  WordData TheWords[10];
  int numWords;

///                                                                  
///Function Name: incMatch                                  
///                                                                  
///Description: Takes the current word and checks to
///             see if that word is in the data structure,
///             if so, increment it
///                                                                   
///Parameters:  string temp - the current word
///
///Return:      bool - true if word is incremented
///
  // Look for a match and increment if found
  bool incMatch(string temp);
  
///                                                                  
///Function Name: printRecursivelyWorker                                  
///                                                                  
///Description: Helper function that changes the value 
///             of the index and prints the values
///                                                                   
///Parameters:  int numWords - the current
///             position in the data object           
///
///Return:      void
///
  // Function to actually perform recursive print
  void printRecursivelyWorker(int numWords);

///                                                                  
///Function Name: printPtrWorker                                  
///                                                                  
///Description: Helper function that moves the position 
///             of the pointer based on numWords and prints 
///             the values
///                                                                   
///Parameters:  int numWords - the current
///             position in the data object           
///
///Return:      void
///
  // Function to actually perform recursive print using pointer
  void printPtrWorker(int numWords);


};
  
#endif
