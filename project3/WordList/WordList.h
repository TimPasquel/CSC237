// File: WordList.h
// Abstract base class for containers of word data
// Known subclasses:
//      WordDataList
// Coming soon: ParallelArrayWordList, WordVectorList, ...

#ifndef WORDLIST_H
#define WORDLIST_H

/*!	\file WordList.h 
 * *	\brief The parent class of the 3 subclasses
 * *	\class WordList 
 * *	\brief The parent class of the 3 subclasses
 * */

#include <fstream>
#include <string>

using namespace std;

class WordList {
public:

///                                                                  
///Function Name: parseIntoList                                  
///                                                                  
///Description: Takes an in file and then parses
///             the data into the corresponding
///             data structure  
///                                                                   
///Parameters:  ifstream &inf - file to be read
///           
///Return: void
///
// Place the line of text into the data structure
virtual void parseIntoList(ifstream &inf)=0;

///                                                                  
///Function Name: printIteratively                                  
///                                                                  
///Description: Takes the current WordList object
///             and prints it iteratively
///                                                                   
///Parameters:  None           
///
///Return: void
///
// Print the data iteratively
virtual void printIteratively()=0;
  
///                                                                  
///Function Name: printRecursively                                  
///                                                                  
///Description: Takes the current WordList object
///             and prints it recursively
///                                                                   
///Parameters:  None           
///
///Return: void
///
// Print the data recursively
virtual void printRecursively()=0;
  
///                                                                  
///Function Name: printPtr                                  
///                                                                  
///Description: Takes the current WordList object
///             and prints it using a pointer
///                                                                   
///Parameters:  None           
///
///Return: void
///
// Print the data recursively with a pointer
virtual void printPtr() {}   // not pure virtual; why?
    
};
  
#endif
