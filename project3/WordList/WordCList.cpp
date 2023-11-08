// File: WordCList.cpp
// Purpose: Container of WordData objects, CLinkedList 
// Implementations of member functions including inherited 
// pure virtual fns.


/*!	\file WordCList.cpp 
 * *	\brief CLinkedList subclass implementation of WordList 
 * */

#include <sstream>
#include <iostream>
#include "WordCList.h"
#include "CLinkedList.h"
#include "WordData.h"

using namespace std;

//Constructor
WordCList::WordCList()
{ }

//Increments the unique word if match is found
bool WordCList::incMatch(string temp) {
   CListItr<WordData> itr(TheWords);
   for(itr.begin(); !itr.isLastNode(); itr++) {

      if(itr.isEmpty())
      	 return false;

      if(temp==(*itr).getWord()) {
	 int occur = (*itr).getCount();
	 occur+=1;
	 string wrd = (*itr).getWord();

	 WordData word;
	 word.setWordData(wrd, occur);

         TheWords.remove((*itr));
	 TheWords.insert(word);
	 return true;
      } 
   }
   if(temp==(*itr).getWord()) {
      int occur = (*itr).getCount();
      occur+=1;
      string wrd = (*itr).getWord();

      WordData word;
      word.setWordData(wrd, occur);

      TheWords.remove((*itr));
      TheWords.insert(word);
      return true;
   } 
   return false;
}

//Parses the file into the data structure
void WordCList::parseIntoList(ifstream &inf) {
   //Current word
   string temp;
   //Within the file
   while(inf >> temp) {
      //Fill first node
      if(TheWords.empty()) {
         WordData word;	
         word.setWordData(temp, 1);
         TheWords.insert(word);
         continue;
      }
      //Check Nodes, if none add one
      if(!incMatch(temp)) {
	 WordData word;
	 word.setWordData(temp,1);
         TheWords.insert(word);
      }
      //temp.clear();
   }
}

// Print the data iteratively
void WordCList::printIteratively() {
   cout<<"--------------------------"<<endl;
   cout<<"|Circular List Iterator  |"<<endl;
   cout<<"|Word         Occurences |"<<endl;  
   cout<<"--------------------------"<<endl;
   
   if(TheWords.empty())
      return;

   CListItr<WordData> itr(TheWords);
   for(itr.begin(); !itr.isLastNode(); itr++) {
      cout << " " << *itr << endl;
   }
   cout << " " << *itr << endl;
}

// Print the data recursively
void WordCList::printRecursivelyWorker(CListItr<WordData> itr) {
   if(!itr.isLastNode()) {
      cout<<" "<< *itr <<endl;
      printRecursivelyWorker(itr++);
      if(itr.isLastNode()) {
         cout << " " << *itr << endl;
      }
   }
}

// Call worker function to print the data recursively
void WordCList::printRecursively()
{ 
   cout<<"--------------------------"<<endl;
   cout<<"|Circular List  Recursive|"<<endl;
   cout<<"|Word         Occurences |"<<endl;  
   cout<<"--------------------------"<<endl;
   
   if(TheWords.empty())
      return;

   CListItr<WordData> itr(TheWords);
   itr.begin();
   printRecursivelyWorker(itr); 
}

//Prints the data structure via a pointer
void WordCList::printPtr() {}
