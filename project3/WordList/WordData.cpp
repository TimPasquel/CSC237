//
// File:    WordData.cpp
// Purpose: Object that hold unique word and a counter
//

/*!	\file WordData.cpp 
 * *	\brief Custom data obj, holds a unique word and a counter
 * *	\class WordData 
 * *	\brief Custom data obj, holds a unique word and a counter
 * */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

//Constructor
WordData::WordData(string wrd, int cnt)
{
        setWordData(wrd, cnt);
}

//Sets the word 
void WordData::setWord(string wrd)
{
        word = wrd;
}

//Sets the count
void WordData::setCount(int cnt)
{
        count = cnt;
}

//Sets both the word and the count
void WordData::setWordData(string wrd, int cnt)
{
        setWord(wrd);
        setCount(cnt);
}

//Gets the word
string WordData::getWord() const
{
        return(word);
}

//Gets the count
int WordData::getCount() const
{
        return(count);
}

//Increments the count by 1
void WordData::incCount(int inc)
{
        count+=inc;              
}

//added operators so that inserting into clinkedlist
//would word properly

//overloaded > operator 
bool WordData::operator>(WordData arg) {
   return (this->getWord() > arg.getWord());
} 

//overloaded < operator 
bool WordData::operator<(WordData arg) {
   return (this->getWord() < arg.getWord());
}
 
//overloaded >= operator 
bool WordData::operator>=(WordData arg) {
   return (this->getWord() >= arg.getWord());
}
 
//overloaded <= operator 
bool WordData::operator<=(WordData arg) {
   return (this->getWord() <= arg.getWord());
}

//overloaded == operator 
bool WordData::operator==(WordData arg) {
   return (this->getWord() == arg.getWord());
} 

//overloaded != operator 
bool WordData::operator!=(WordData arg) {
   return (this->getWord() != arg.getWord());
}
//end of addition

//overloaded << operator 
ostream &operator<<(ostream& output, const WordData &words)
{
  output<< setw(20) << left << words.getWord() << setw(5) << left <<words.getCount();
  return output;
}
