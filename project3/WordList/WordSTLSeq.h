//File: WordSTLSeq.h
// STL Container of WordData objects.
// Printing can be iterative or recursive

/*!	\file WordSTLSeq.h 
 * *	\brief A STL(vector) subclass implementation of WordList
 * *	\class WordSTLSeq 
 * *	\brief A STL(vector) subclass implementation of WordList
 * */

#ifndef WORDSTLSEQ_H
#define WORDSTLSEQ_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include <vector>

using namespace std;

class WordSTLSeq : public WordList {
public:

///                                                                  
///Function Name: WordSTLSeq                                  
///                                                                  
///Description:   constructor for a WordSTLSeq data
///               structure
///                                                                   
///Parameters:    None           
///
///Return:        None
/// 
  WordSTLSeq();

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

  vector<WordData> TheWords;

///                                                                  
///Function Name: incMatch                                  
///                                                                  
///Description: Checks to see if the current word is in the
///             data structure, if so, increments the occrences
///             of that word 
///                                                                   
///Parameters:  string temp - the current word
///
///Return:      void
///
  //Look for a match and increment if found
  bool incMatch(string temp);
  
///                                                                  
///Function Name: printRecursivelyWorker                                  
///                                                                  
///Description: Helper function that moves the position 
///             of the vector iterator and prints 
///             the values
///                                                                   
///Parameters:  vector<WordData>::iterator index - the current
///             position in the data object           
///
///Return:      void
///
  // Function to actually perform recursive print
  void printRecursivelyWorker(vector<WordData>::iterator index);
  
  //Function to actually perform recursive print using pointer
  void printPtrWorker(int numWords);
  
  
  };
#endif
