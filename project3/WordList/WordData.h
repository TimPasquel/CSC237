/****************************************************************/
/*   Filename:       WordData.h                                 */
/*   Purpose:        An object that holds a unique word and the */
/*                   number of occurences                       */ 
/****************************************************************/

/*!	\file WordData.h 
 * *    \brief Custom data obj, holds a unique word and a counter
 * *	\class WordData 
 * *    \brief Custom data obj, holds a unique word and a counter
 * */

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

class WordData {

public:

///
/// Function Name:  constructor
///
/// Description:    Will construct a default word data obj. Default
///                 values are an empty string zero as the count
///
/// Parameters:     string wrd - Word to be placed in obj
///                 int cnt - Value to be placed in counter
///
/// Return Value:   none
///
WordData(string wrd = "", int cnt = 1);

//Sets

///
/// Function Name:  setWord
///
/// Description:    Will set the object's string.
///
/// Parameters:     string wrd - Word to be placed in object
///
/// Return Value:   none
///
void setWord(string wrd);

///
/// Function Name:  setCount
///
/// Description:    Will set the occurence counter.
///
/// Parameters:     int cnt - Value to be placed in counter
///
/// Return Value:   none
///
void setCount(int cnt);

//Set Whole WordData Object

///
/// Function Name:  setWordData
///
/// Description:    Will set both the object's string and the
///                 object's occurence count
///
/// Parameters:     string wrd - Word to be placed in object
///                 int cnt - Value to be placed in counter
///
/// Return Value:   none
///
void setWordData(string,int);

//Gets

///
/// Function Name:  getWord
///
/// Description:    Will retrieve the object's string
///
/// Parameters:     none
///
/// Return Value:   string
///
string getWord() const;

///
/// Function Name:  getCount
///
/// Description:    Will retrieve the object's occurence counter
///
/// Parameters:     none
///
/// Return Value:   int
///
int getCount() const;

//Increment

///
/// Function Name:  incCount
///
/// Description:    Will increment the occurence counter
///
/// Parameters:     int inc - the value to be incremented (1)
///
/// Return Value:   none
///
void incCount(int inc = 1);

///
/// Function Name:  operator<
///
/// Description:    Associated < operator for WordData
///
/// Parameters:     WordData arg - object to be compared
///
/// Return Value:   bool
///
bool operator<(WordData arg);

///
/// Function Name:  operator>
///
/// Description:    Associated > operator for WordData
///
/// Parameters:     WordData arg - object to be compared
///
/// Return Value:   bool
///
bool operator>(WordData arg);

///
/// Function Name:  operator<=
///
/// Description:    Associated <= operator for WordData
///
/// Parameters:     WordData arg - object to be compared
///
/// Return Value:   bool
///
bool operator<=(WordData arg);

///
/// Function Name:  operator>=
///
/// Description:    Associated >= operator for WordData
///
/// Parameters:     WordData arg - object to be compared
///
/// Return Value:   bool
///
bool operator>=(WordData arg);

///
/// Function Name:  operator==
///
/// Description:    Associated == operator for WordData
///
/// Parameters:     WordData arg - object to be compared
///
/// Return Value:   bool
///
bool operator==(WordData arg);

///
/// Function Name:  operator!=
///
/// Description:    Associated != operator for WordData
///
/// Parameters:     WordData arg - object to be compared
///
/// Return Value:   bool
///
bool operator!=(WordData arg);

private:

        //variables
        string word;
        int count;


};

///
/// Function Name:  operator<<
///
/// Description:    Associated stream insertion operator
///
/// Parameters:     ostream &output - output stream
///                 const WordData &word - object to print
///
/// Return Value:   none
///
ostream &operator<<(ostream& output, const WordData &words);

#endif
