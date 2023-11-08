/********************************************************
 *    File:    WordData.cpp            			*
 *    Prepared by: Dr. Spiegel         			*
 *    Description:  An object that is designed to hold
 *    		    the string of a word as well as an
 *    		    integer for the amount of occurences
 *    		    the word has in a file. The object
 *    		    can both set the values of these
 *    		    variables as well as get the values
 *    		    of these variables independantly.
 *    		    It can also increment the occurances 
 *		    of a word through a single function. *
 ********************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;


WordData::WordData(string wrd, int cnt)
{
	setWordData(wrd, cnt);	
}

void WordData::setWord(string wrd)
{
	word = wrd;
}

void WordData::setCount(int cnt)
{
	count = cnt;
}

void WordData::setWordData(string wrd, int cnt)
{
	setWord(wrd);
	setCount(cnt);
}

string WordData::getWord() const
{
	return(word);
}

int WordData::getCount() const
{
	return(count);
}

WordData& WordData::operator++()	// preincrement
{	setCount(getCount()+1);
	return(*this);
}

WordData WordData::operator++(int)	// postincrement
{	WordData temp;
	setCount(getCount()+1);
	return(temp);
}

ostream &operator<<(ostream &output, const WordData &word){
	output << setw(20) << left << word.getWord() << setw(5) << left << word.getCount() << endl;
	return output;
}
