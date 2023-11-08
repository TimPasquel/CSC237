//File: WordSTLSeq.cpp
//Purpose: Container of WordData objects, STL(vector) 
//Implementations of member functions including 
//inherited pure virtual fns.

/*!	\file WordSTLSeq.cpp 
 * *	\brief A STL(vector) subclass implementation of WordList
 * *	\class WordSTLSeq 
 * *	\brief A STL(vector) subclass implementation of WordList
 * */

#include <sstream>
#include <iostream>
#include <vector>
#include "WordSTLSeq.h"
#include "WordData.h"
#include <algorithm>

using namespace std;

//Constructor
WordSTLSeq::WordSTLSeq()
{   }

//Increments the word count if a match is found 
bool WordSTLSeq::incMatch(string temp) {
   for(vector<WordData>::iterator index = TheWords.begin();
       index != TheWords.end(); index++) {
      if(temp == (*index).getWord()) {
         (*index).incCount();
         return true;
      }
   }
   return false;	
}

//Parses the file into the data structure
void WordSTLSeq::parseIntoList(ifstream &inf){
   //Current word
   string temp;
   //Within the file
   while(inf >> temp) {
      //Fill the first node
      if(!incMatch(temp)) {
         WordData word;
	 word.setWordData(temp, 1);
         TheWords.push_back(word); 
      }
      //temp.clear;
   }
   //
   //Author: Gabe
   //Publication Date: May 3, 2010
   //Title and Version: How to sort an STL vector?
   //Source: https://stackoverflow.com/questions/2758080/how-to-sort-an-stl-vector
   //Date Retrieved: 3/28/2023
   //
   sort(TheWords.begin(), TheWords.end());
}

// Print the data iteratively
void WordSTLSeq::printIteratively() {
   cout<<"--------------------------"<<endl;
   cout<<"|STL Vector Iterative    |"<<endl;
   cout<<"|Word         Occurences |"<<endl;  
   cout<<"--------------------------"<<endl;
   for(vector<WordData>::iterator index = TheWords.begin(); 
      index != TheWords.end(); index++) {
      cout << " " << *index << endl;
   }
}

//Helper function for printing recursively
void WordSTLSeq::printRecursivelyWorker(vector<WordData>::iterator index) {
   if(index == TheWords.begin()) {
      cout<<"--------------------------"<<endl;
      cout<<"|STL Vector Recursive    |"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
   }
   
   if(index != TheWords.end()) {
      cout << " " << *index << endl;
      index++;
      printRecursivelyWorker(index);
   }
}
  
// Print the data recursively
void WordSTLSeq::printRecursively() {
   vector<WordData>::iterator index = TheWords.begin();
   printRecursivelyWorker(index);
}
  
//Print the data recursively with a pointer
void WordSTLSeq::printPtr() {

}
