/****************************************************************/
/*   Author:         Dr. Spiegel & Tim Pasquel                  */
/*   Course:         CSC237                                     */
/*   Filename:       app.cpp                                    */
/*   Purpose:        This Example inputs a string and demon-    */
/*                   strates how to store it using a subclass   */
/*                   of an abstract base class that incorporates*/
/*                   virtual functions to enable polymorphism   */
/*                   If a file name is                          */
/*                   input through the command line all of the  */
/*                   options will be done automatically for the */
/*                   first line of the file                     */
/****************************************************************/


/*!	\file app.cpp 
 **	\brief Test driver program for the 3 data structures
 **/

#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "WordList.h"
#include "WordDataList.h"
#include "WordCList.h"
#include "WordSTLSeq.h"
// #include "WordData.h"        app only knows about the lists!

using namespace std;

///
///Function Name: displayMenu                                    
///                                                                   
///Description: Displays the menu on the screen.                   
///
///Parameters: None
///
///Return: void
///
void displayMenu();

///                                                                  
///Function Name: printEverything                                  
///                                                                  
///Description: Takes in a sentence and sends it through every     
///             parsing and printing function                      
///                                                                   
///Parameters:  ifstream &inf - file to be read
///           
///             WordList *TheList - WordList pointer that 
///             points to the current data structure
///
///Return: void
///
void printEverything(ifstream &inf,WordList *TheList);

///                                                                  
///Function Name: printObjArrayIterative                                  
///                                                                  
///Description: Takes in a file, parses into an Obj. Array
///             and then prints iteratively                      
///                                                                   
///Parameters:  ifstream &inf - file to be read           
///             WordList *TheList - WordList pointer that
///             will point to an Obj Array data structure         
///
///Return: void
///
void printObjArrayIterative(ifstream &inf, WordList *TheList);

///                                                                  
///Function Name: printObjArrayRecursive                                  
///                                                                  
///Description: Takes in a file, parses into an Obj. Array
///             and then prints recursively                      
///                                                                   
///Parameters:  ifstream &inf - file to be read           
///             WordList *TheList - WordList pointer that
///             will point to an Obj Array data structure         
///
///Return: void
///
void printObjArrayRecursive(ifstream &inf, WordList *TheList);

///                                                                  
///Function Name: printObjArrayPointerRecursive                                 
///                                                                  
///Description: Takes in a file, parses into an Obj. Array
///             and then prints recursively using a pointer                      
///                                                                   
///Parameters:  ifstream &inf - file to be read           
///             WordList *TheList - WordList pointer that
///             will point to an Obj Array data structure         
///
///Return: void
///
void printObjArrayPointerRecursive(ifstream &inf, WordList *TheList);

///                                                                  
///Function Name: printCListIterator                                  
///                                                                  
///Description: Takes in a file, parses into a CList object
///             and then prints iteratively                      
///                                                                   
///Parameters:  ifstream &inf - file to be read           
///             WordList *TheList - WordList pointer that
///             will point to a CList data structure         
///
///Return: void
///
void printCListIterator(ifstream &inf, WordList *TheList);

///                                                                  
///Function Name: printCListIteratorRecursive                                  
///                                                                  
///Description: Takes in a file, parses into a CList object
///             and then prints recursively using an 
///             iterator                      
///                                                                   
///Parameters:  ifstream &inf - file to be read           
///             WordList *TheList - WordList pointer that
///             will point to a CList data structure         
///
///Return: void
///
void printCListIteratorRecursive(ifstream &inf, WordList *TheList);

///                                                                  
///Function Name: printSTLSeqIterator                                  
///                                                                  
///Description: Takes in a file, parses into a vector object
///             and then prints iteratively                      
///                                                                   
///Parameters:  ifstream &inf - file to be read           
///             WordList *TheList - WordList pointer that
///             will point to a vector data structure         
///
///Return: void
///
void printSTLSeqIterator(ifstream &inf, WordList *TheList);

///                                                                  
///Function Name: printSTLSeqRecursive                                  
///                                                                  
///Description: Takes in a file, parses into a vector object
///             and then prints recursively                      
///                                                                   
///Parameters:  ifstream &inf - file to be read           
///             WordList *TheList - WordList pointer that
///             will point to a vector data structure         
///
///Return: void
///
void printSTLSeqRecursive(ifstream &inf, WordList *TheList);

int main(int argc,char *argv[])
{ 
  using namespace std::chrono ;

  ifstream inf;
  WordList *TheList;
  if(argc>1) //if there was an input on the command line
    {
      inf.open(argv[1]); //try and open the file
      if (inf.fail())       //if the file does not open
        {                    //terminate
          cout<<"Sorry, the file failed to open."<<endl;
          return 0;
        }
      printEverything(inf,TheList);
      return 0;
    }
  
  char selection;
  string fileName;
  cout<<"Please enter a file name:"<<endl;
  getline(cin,fileName);
  inf.open(fileName.c_str());
  //Check to make sure file exsists
  if(inf.fail()) {
     cout << "Sorry, the file failed to open" << endl;
     return 0;
  }
  
  while (true)
    {
      displayMenu();
      cin>>selection;
      switch(selection)
        { case '1':
            printObjArrayIterative(inf, TheList);
            break;
          case '2':
            printObjArrayRecursive(inf, TheList);
            break;
          case '3':
            printObjArrayPointerRecursive(inf, TheList);
            break;
	  case '4':
	    printCListIterator(inf, TheList);
	    break;
          case '5':
	    printCListIteratorRecursive(inf, TheList);
            break;
          case '6':
            printSTLSeqIterator(inf, TheList);
            break;
          case '7':
            printSTLSeqRecursive(inf, TheList);
            break;
          case '8':
            cout<<"Goodbye"<<endl;
            return 0;
          default:
            cout<<"I cannot understand "<<selection<<".  Try again."<<endl;
             break;
        }
    }
  
  return 0;
}

void displayMenu()
{
  cout<<endl;
  cout<<"How do you want to print your sentence elements?"<<endl;
  cout<<"------------------------------------------------"<<endl;
  cout<<"1. Object Array Iterative"<<endl;
  cout<<"2. Object Array Recursive"<<endl;
  cout<<"3. Object Array Pointer Recursive"<<endl;
  cout<<"4. Circular List Iterator"<<endl;
  cout<<"5. Circular List Iterator Recursive"<<endl;
  cout<<"6. STL Container Iterative"<<endl;
  cout<<"7. STL Container Recursive"<<endl;
  cout<<"8. Quit"<<endl;
}

void printObjArrayIterative(ifstream &inf, WordList *TheList) {
   TheList = new WordDataList;

   //
   //Author: Remy Lebeau
   //Publication Date: Aug 22, 2020
   //Title and Version: error: 'high_resolution_clock' has not been declared
   //Source: https://stackoverflow.com/questions/63533235/error-high-resolution-clock-has-not-been-declared
   //Date Retrieved: 3/28/2023
   //

   auto begin = std::chrono::high_resolution_clock::now();
   TheList->parseIntoList(inf);
   auto end = std::chrono::high_resolution_clock::now();
   auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

   cout << "It took " << ticks.count() << 
   " microseconds to parse the data " << endl;

   auto begin1 = std::chrono::high_resolution_clock::now();
   TheList->printIteratively();
   auto end1 = std::chrono::high_resolution_clock::now();
   auto ticks1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

   cout << "It took " << ticks1.count() <<
   " microseconds to print the data " << endl;
   cout << endl;
 
   inf.clear();
   inf.seekg(0);
   delete TheList;
}

void printObjArrayRecursive(ifstream &inf, WordList *TheList) {
   TheList = new WordDataList;

   auto begin = std::chrono::high_resolution_clock::now();
   TheList->parseIntoList(inf);
   auto end = std::chrono::high_resolution_clock::now();
   auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

   cout << "It took " << ticks.count() <<
   " microseconds to parse the data " << endl;

   auto begin1 = std::chrono::high_resolution_clock::now();
   TheList->printRecursively();
   auto end1 = std::chrono::high_resolution_clock::now();
   auto ticks1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

   cout << "It took " << ticks1.count() <<
   " microseconds to print the data " << endl;
   cout << endl;

   inf.clear();
   inf.seekg(0);
   delete TheList;
}

void printObjArrayPointerRecursive(ifstream &inf, WordList *TheList) {
   TheList = new WordDataList;

   auto begin = std::chrono::high_resolution_clock::now();
   TheList->parseIntoList(inf);
   auto end = std::chrono::high_resolution_clock::now();
   auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

   cout << "It took " << ticks.count() <<
   " microseconds to parse the data " << endl;
   
   auto begin1 = std::chrono::high_resolution_clock::now();
   TheList->printPtr();
   auto end1 = std::chrono::high_resolution_clock::now();
   auto ticks1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

   cout << "It took " << ticks1.count() <<
   " microseconds to print the data " << endl;
   cout << endl;

   inf.clear();
   inf.seekg(0);
   delete TheList;
}

void printCListIterator(ifstream &inf, WordList *TheList) {
   TheList = new WordCList;

   auto begin = std::chrono::high_resolution_clock::now();
   TheList->parseIntoList(inf);
   auto end = std::chrono::high_resolution_clock::now();
   auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

   cout << "It took " << ticks.count() <<
   " microseconds to parse the data " << endl;

   auto begin1 = std::chrono::high_resolution_clock::now();
   TheList->printIteratively();
   auto end1 = std::chrono::high_resolution_clock::now();
   auto ticks1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

   cout << "It took " << ticks1.count() <<
   " microseconds to print the data " << endl;
   cout << endl;

   inf.clear();
   inf.seekg(0);
   delete TheList;
}

void printCListIteratorRecursive(ifstream &inf, WordList *TheList) {
   TheList = new WordCList;

   auto begin = std::chrono::high_resolution_clock::now();
   TheList->parseIntoList(inf);
   auto end = std::chrono::high_resolution_clock::now();
   auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

   cout << "It took " << ticks.count() <<
   " microseconds to parse the data " << endl;

   auto begin1 = std::chrono::high_resolution_clock::now();
   TheList->printRecursively();
   auto end1 = std::chrono::high_resolution_clock::now();
   auto ticks1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

   cout << "It took " << ticks1.count() <<
   " microseconds to print the data " << endl;
   cout << endl;

   inf.clear();
   inf.seekg(0);
   delete TheList;
}

void printSTLSeqIterator(ifstream &inf, WordList *TheList) {
   TheList = new WordSTLSeq;

   auto begin = std::chrono::high_resolution_clock::now();
   TheList->parseIntoList(inf);
   auto end = std::chrono::high_resolution_clock::now();
   auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

   cout << "It took " << ticks.count() <<
   " microseconds to parse the data " << endl;

   auto begin1 = std::chrono::high_resolution_clock::now();
   TheList->printIteratively();
   auto end1 = std::chrono::high_resolution_clock::now();
   auto ticks1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

   cout << "It took " << ticks1.count() <<
   " microseconds to print the data " << endl;
   cout << endl;

   inf.clear();
   inf.seekg(0);
   delete TheList;
}

void printSTLSeqRecursive(ifstream &inf, WordList *TheList) {
   TheList = new WordSTLSeq;

   auto begin = std::chrono::high_resolution_clock::now();
   TheList->parseIntoList(inf);
   auto end = std::chrono::high_resolution_clock::now();
   auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

   cout << "It took " << ticks.count() <<
   " microseconds to parse the data " << endl;

   auto begin1 = std::chrono::high_resolution_clock::now();
   TheList->printRecursively();
   auto end1 = std::chrono::high_resolution_clock::now();
   auto ticks1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-begin1);

   cout << "It took " << ticks1.count() <<
   " microseconds to print the data " << endl;
   cout << endl;

   inf.clear();
   inf.seekg(0);
   delete TheList;
}

void printEverything(ifstream &inf,WordList *TheList) {
   printObjArrayIterative(inf, TheList);
   printObjArrayRecursive(inf, TheList);
   printObjArrayPointerRecursive(inf, TheList);
   printCListIterator(inf, TheList);
   printCListIteratorRecursive(inf, TheList);
   printSTLSeqIterator(inf, TheList);
   printSTLSeqRecursive(inf, TheList);
}
