//
//    Author:        Tim Pasquel                                   
//    Course:        CSC237                                        
//    Filename:      p1.cpp                                        
//    Purpose:       Counts the number of each unique words using  
//    		     1 of 8 methods specified by the user. Option 1 and 2 use parallel arrays
//     		     in which one array holds the unique words while the other holds each words
//     		     count. Option 1 prints the arrays iteratively and option 2 does so recursively.
//     		     Options 3, 4, and 5 use object arrays in which there is an array of type
//     		     object. Option 3 prints the array iteratively, 4 does so recusively, and
//     		     5 does so by using pointers. Options 6 and 7 use seqential containers
//    		     to hold the WordData objects so that there can be an unlimited amount of
//     		     unique words to be counted. Option 6 prints via indexing and 7 prints     		     
//     		     via an iterator. The last option 8 is the exit function.        
//

#include <array>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"
#include <vector> 

using namespace std;

//
//    Function name:   getFilename                               
//                                                               
//    Description:     Will prompt the user for a filename and   
//    		       then reference it back			 
//     		       						 
//    Parameters:      string& filename - name of the file to be 
//    		       used. Import/Export                       
//                                                               
//    Member Type:     NA                                        
//                                                               
//    Return Value:    none                                      
//
void getFilename(string& filename) {
	cout << "Please enter in a filename." <<endl;
	cin >> filename;	
}

//
//    Function name:   printMenu                                 
//                                                               
//    Description:     Will display all 8 options for the user   
//                                                               
//    Parameters:      none					 
//                                                               
//    Member Type:     NA                                          
//                                                              
//    Return Value:    none                                      
//
void printMenu() {
	cout << "Enter a number, 1-8, to choose from the menu below:" << endl;
	cout << "1. Parallel Iterative" << endl;
	cout << "2. Parallel Recursive" << endl;
	cout << "3. Object Array Iterative" << endl;
	cout << "4. Obejct Array Recursive" << endl;
	cout << "5. Object Array Pointer" << endl;
	cout << "6. Seq Container Indexing" << endl;
	cout << "7. Seq Container Iterator" << endl;
	cout << "8. Exit" << endl;
}

//
//Function name:   readSeqContainer                          
//                                                               
//Description:     Takes a file parsing it into individual words. Then populates the vector with WordData 
//                 objects and their respective unique words and counts                           
//                                                               
//Parameters:      fstream& filename - The file to be parsed 
//                 Import/Export         
//
//                 vector<WordData>& vect - The vector of type WordData that is to be populated with unique words
//                 and their respective counts
//                 Import/Export
//
//                 int&real_size - The actual size of the vector that is incremented every time a new unique word
//                 is found
//                 import/Export                  
//                                                               
//Member Type:     NA                                          
//                                                               
//Return Value:    none                                      
//
void readSeqContainer(fstream& file, vector<WordData>& vect, int&real_size) {
	string current_word;

        while(file >> current_word) {							//Loops through the file taking each word

		if(real_size == 0) {							//Fills in the first index of seq container
			vect.push_back(WordData(current_word, 1));
			real_size += 1;
		}	
		else {
                        bool found = false;
                        for(int index = 0; index < vect.size(); index++) {
                                if(!current_word.compare(vect[index].getWord())) {      //checks to see if current word is in the seq container
                                        found = true;
                                        vect[index]++;
                                        break;                                          //then adds 1 to the word occurences
                                }
                        }
                        if(!found) {
                                vect.push_back(WordData(current_word, 1));       	//if not add it to the seq container
                                real_size += 1;
                        }

                }
                current_word.clear(); 							//resets the variable
	}	                                                                                                	
}

//
//Function name:   printSeqContainerIterator
//
//Description:     One of 8 subfunctions that takes a file and a newly created vector and passes it into the readSeqContainer function.
//		   Once the vector is populated, it is outputed via an Iterator
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//
//Member Type:     NA
//
//Return Value:    none
//
void printSeqContainerIterator(fstream& file) {
        vector<WordData> vect;									//Creates the vector

        int real_size = 0;

        readSeqContainer(file, vect, real_size);						//Populates the vector and finds its real size

        cout << "Seq Container Iterator" << endl;						//Prints the appropriate table header
        cout << "------------------------------" << endl;
        cout << "Word           Occurrences" << endl;
        cout << "------------------------------" << endl;

        for(vector<WordData>::iterator index = vect.begin(); index != vect.end(); index++) {    //Prints the data via an iterator
                cout << *index;
        }

}

//
//Function name:   printSeqContainerIndex
//
//Description:     One of 8 subfunctions that takes a file and a newly created vector and passes it into the readSeqContainer function.
//		   Once the vector is populated, it is outputed via indexing in a for loop
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//
//Member Type:     NA
//
//Return Value:    none
//
void printSeqContainerIndex(fstream& file) {
	vector<WordData> vect;							//creates the vector

	int real_size = 0;

	readSeqContainer(file, vect, real_size);				//populates the vector with data and finds its real size

	cout << "Seq Container Indexing" << endl;				//Prints appropriate table header
        cout << "------------------------------" << endl;
        cout << "Word           Occurrences" << endl;
        cout << "------------------------------" << endl;

	for(int index = 0; index < vect.size(); index++) {			//Prints the data via indexing
		cout << vect[index];
	}
		
}

//
//Function name:   readObjectArray
//
//Description: 	   Takes a file parsing it into individual words. Then populates the WordData object array
//		   with WordData objects and their respective counts
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//		   
//		   WordData Data[] - An array of Word Data Objects that stores unique words and their respective counts
//		   Import/Export
//		   
//		   int uniqueWordsTotal - An constant integer that is the length of the WordData array
//		   Import
//
//		   int&real_size - A reference integer that stores the actual size of the array. It is incremented
//		   for every unique word found
//		   Import/Export
//
//Member Type:     NA
//
//Return Value:	   none
//
void readObjectArray(fstream& file, WordData Data[], int uniqueWordsTotal, int&real_size) {
	string current_word;

	while(file >> current_word) {							//Loops through the file getting each individual word
		if(Data[0].getWord() == "") {						//fills in the first index of the WordData array
			Data[0].setWord(current_word);					//Sets the values and increments the realsize
			Data[0].setCount(1);
			real_size += 1;
		}
		else {
			bool found = false;
			for(int index = 0; index < uniqueWordsTotal; index++) {
				if(!current_word.compare(Data[index].getWord())) {	//checks to see if current word is in array
					found = true;
					Data[index]++;					//if so, increment that unique word
					break;
				}
			}					
			if(!found && (real_size < uniqueWordsTotal)) {
                                Data[real_size].setWord(current_word);       		//if not, add it to the array and set values
                                Data[real_size].setCount(1);
				real_size += 1;
                        }
		}
		current_word.clear();							//reset the current word
	}
} 

//
//Function name:   printObjectArrayPointer
//
//Description:     One of 8 subfunctions that takes a file and a newly created array of type WordData and passes it 
//		   into the readObjectArray function. Once the WordData array is populated, it is outputed via pointer 
//		   arithmatic and through an iterator (No indexing was used).
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//
//Member Type:     NA
//
//Return Value:    none
//
void printObjectArrayPointer(fstream& file) {
        const int uniqueWordsTotal = 10;
									
        WordData data[uniqueWordsTotal];					//Declares the Word Data array

        int real_size = 0; 

        readObjectArray(file, data, uniqueWordsTotal, real_size);		//Populates the Word Data array 

        cout << "Object Array Pointer" << endl;					//Print the appropriate table
        cout << "------------------------------" << endl;
        cout << "Word           Occurrences" << endl;
        cout << "------------------------------" << endl;

	WordData *pointer_object = data;					//create a pointer to use for printing

        for(int index = 0; index < real_size; index++) {			//Loop through the array
		cout << *pointer_object;					//output the pointer at the specific location
		pointer_object++;						//increment the pointer
        }
}

//
//Function name:   printObjectArrayIterative
//
//Description:     One of 8 subfunctions that takes a file and a newly created array of type WordData and passes it 
//		   into the readObjectArray function. Once the WordData array is populated, it is outputed via iteration
//		   in a for loop.
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//
//Member Type:     NA
//
//Return Value:    none
//
void printObjectArrayIterative(fstream& file) {
	const int uniqueWordsTotal = 10;

	WordData data[uniqueWordsTotal];					//Declare the WordData array object
	
        int real_size = 0;

	readObjectArray(file, data, uniqueWordsTotal, real_size);		//Populate the WordData array with unique words and their values

	cout << "Object Array Iterative" << endl;				//Print the appropriate table
        cout << "------------------------------" << endl;
        cout << "Word           Occurrences" << endl;
        cout << "------------------------------" << endl;

        for(int index = 0; index < real_size; index++) {			//Loop through the array by printing it iteratively
        	cout << data[index]; 
        }
}

//
//Function name:   printObjectArrayTable
//
//Description:     A helper function that takes the array of type WordData and prints it into a table. It does this
//		   by using a variable called flag and incrementing it after each time an instance of WordData is printed.
//		   When flag and real_size are equal, the printing is complete. 
//
//Parameters:      WordData* data - A pointer of an array of type WordData that is then used to print each instance.
//                 Import
//
//                 int real_size - An integer that holds the value of the actual size of array of type WordData
//		   Import
//
//Member Type:     NA
//
//Return Value:    none
//
void printObjectArrayTable(WordData* data, int real_size) {
	static int flag = 0;							//Variable that is used as a marker for recursive nature

        if(flag == 0) {								
                cout << "Object Array Recursive" << endl;			//Print the appropriate table
                cout << "------------------------------" << endl;
                cout << "Word           Occurrences" << endl;
                cout << "------------------------------" << endl;
        }
        if(flag == real_size) {							//If the flag matches the size of the array then there are no more values and can end
                flag = 0;
                return;
        }

        cout << data[flag];							//Print the data at the current index
        flag += 1;								//Increment the index

        printObjectArrayTable(data, real_size);					//Call the function again for recursion 
}

//
//Function name:   printObjectArrayRecursive
//
//Description:     One of 8 subfunctions that takes a file and a newly created array of type WordData and passes it 
//		   into the readObjectArray function. Once the WordData array is populated, it is outputed via a recursive
//		   function.
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//
//Member Type:     NA
//
//Return Value:    none
//
void printObjectArrayRecursive(fstream& file) {
	const int uniqueWordsTotal = 10;

        WordData data[uniqueWordsTotal];					//Creates the array of type WordData

        int real_size = 0;

        readObjectArray(file, data, uniqueWordsTotal, real_size);		//Populates the array

	printObjectArrayTable(data, real_size);					//Prints the appropriate table recursively
}

//
//Function name:   readParallelArrays
//
//Description: 	   Takes a file parsing it into individual words. Then populates two parallel arrays. One holds the one of 
//		   the 10 unique strings found and the other holds each unique words count respectivly
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//		   
//		   string words[] - An array of type string that holds all of the unqiue words
//		   Import/Export
//
//		   int wordsCount[] - An array of type int that holds all of the respective counts for each unique word
//		   Import/Export
//
//		   int uniqueWordsTotal - An constant integer that is the length of the WordData array
//		   Import
//
//		   int&real_size - A reference integer that stores the actual size of the array. It is incremented
//		   for every unique word found
//		   Import/Export
//
//Member Type:     NA
//
//Return Value:	   none
//
void readParallelArrays(fstream& file, string words[], int wordsCount[], int uniqueWordsTotal, int& real_size) {
	string current_word;

	//
        //Author: Arnab Chakraborty
        //Publication Date: 9/13/2019
        //Title and Version:C++ program to read file word by word?
 	//Source:https:https://www.tutorialspoint.com/cplusplus-program-to-read-file-word-by-word
        //Date Retrieved: 2/7/20223
 	//
	while(file >> current_word) {							//Loops through the file and gets each word
		if (words[0] == "") {							//fill in first index of the parallel arrays
			words[0] = current_word;		
			wordsCount[0] = 1;
			real_size += 1;							//Increment the real_size of the two arrays
		}
		else {
			bool found = false;
			for(int index = 0; index < uniqueWordsTotal; index++) {
				if(!current_word.compare(words[index])) {		//checks to see if current word is in array
					found = true;
					wordsCount[index] += 1;
					break;						//then adds 1 to the word count if the unique word was found
				}
			}
			if(!found && (real_size < uniqueWordsTotal)) {
				words[real_size] = current_word;       			//if not add it and set the proper values
				wordsCount[real_size] = 1;
				real_size += 1;						//Increment the real_size
			}

		}	
		current_word.clear();
	}
}

//
//Function name:   printParallelRecursiveTable
//
//Description:     A helper function that takes the array words of type string and the array wordsCount of type int and prints
//		   them into a table. It does this by using a variable called flag and incrementing it after each time an 
//		   instance of each array is printed.When flag and real_size are equal, the printing is complete. 
//
//Parameters:      string words[] - An array of type string that holds the string of each unique word
//                 Import
//
//                 int wordsCount[] - An array of type int that holds the number of occurences of each respective unique word
//		   Import
//
//                 int real_size - An integer that holds the value of the actual size of array of type WordData
//		   Import
//
//Member Type:     NA
//
//Return Value:    none
//
void printParallelRecursiveTable(string words[], int wordsCount[], int real_size) {
	
	    //
 	    //Author: Geeksforgeek.org
 	    //Publication Date: 11/22/2022
            //Title and Version:C++ Program to print an Array using Recursion
 	    //Source:https://www.geeksforgeeks.org/c-program-to-print-an-array-using-recursion/
            //Date Retrieved: 2/7/20223
 	    //
      
            static int flag = 0;							//Variable that is used as a marker for recursive nature
      
            if(flag == 0) {					
                    cout << "Parallel Recursive" << endl;				//prints the appropriate table header
                    cout << "------------------------------" << endl;
                    cout << "Word           Occurrences" << endl;
                    cout << "------------------------------" << endl;
            }
            if(flag == real_size) {							//if the flag equals the real size stop recursion
                    flag = 0;
                    return;
            }
      
            cout << setw(20) << left << words[flag] << setw(10) << wordsCount[flag] << endl;	//output the data at the index
            flag += 1;										//increment the flag

            printParallelRecursiveTable(words, wordsCount, real_size);				//recall the function for recursive nature
}

//
//Function name:   printParallelRecursive
//
//Description:     One of 8 subfunctions that takes a file and a newly created array uniqueWords of type string as well
//		   as a newly created array uniqueWordsCount of type int and and passes them into the readParallelArrays 
//		   function to be populated. Once the parallel arrays are populated, they are outputed via a recursive
//		   function.
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//
//Member Type:     NA
//
//Return Value:    none
//
void printParallelRecursive(fstream& file) {
	const int uniqueWordsTotal = 10;

        string uniqueWords[uniqueWordsTotal];			//declare the array of type string for unique words 			
        int uniqueWordsCount[uniqueWordsTotal]; 		//declare the array of type int for unique word count

        int real_size = 0; 					//how many unique words are actually in the lists

	readParallelArrays(file, uniqueWords, uniqueWordsCount, uniqueWordsTotal, real_size); //Populates the parallel arrays with data

	printParallelRecursiveTable(uniqueWords, uniqueWordsCount, real_size); 		      //Prints the appriopriate table recursively
}

//
//Function name:   printParallelIterative
//
//Description:     One of 8 subfunctions that takes a file and a newly created array uniqueWords of type string as well
//		   as a newly created array uniqueWordsCount of type int and and passes them into the readParallelArrays 
//		   function to be populated. Once the parallel arrays are populated, they are outputed via a iteration in
//		   a for loop.
//
//Parameters:      fstream& filename - The file to be parsed
//                 Import/Export
//
//Member Type:     NA
//
//Return Value:    none
//
void printParallelIterative(fstream& file) { 		
	const int uniqueWordsTotal = 10;

        string uniqueWords[uniqueWordsTotal]; 				//Declares an array of type string for unique words	
        int uniqueWordsCount[uniqueWordsTotal]; 			//Delcares an array of type int for the count of each word

        int real_size = 0; 						//how many unique words are actually in the lists

	readParallelArrays(file, uniqueWords, uniqueWordsCount, uniqueWordsTotal, real_size);	//Populates the parallel arrays

	cout << "Parallel Iterative" << endl;				//Prints the table header
        cout << "------------------------------" << endl;
        cout << "Word           Occurrences" << endl;
        cout << "------------------------------" << endl;

        for(int index = 0; index < real_size; index++) {		//Loops through the arrays iteratively to display the data
                cout << setw(20) << left << uniqueWords[index] << setw(10) << uniqueWordsCount[index] << endl;
        }
}

int main(int argc, char **argv) {
	
	if(argc == 2) {				//Batch Mode
		string filename = argv[1];
		
		fstream file;
		file.open(filename.c_str());	//Attempts to open the file
		//
 		//Author: CPlusPlus.com
 		//Publication Date: 12/1/2008
 		//Title and Version:Checking to see if file opened (File I/O)
 		//Source:https://cplusplus.com/forum/beginner/6033/
		//Date Retrieved: 2/7/20223
 		//	
		if(file.fail()){		//If it fails, print error then terminates program
			cout << "Failed to open file " << filename << endl;			
		}
		else {
		printParallelIterative(file);	//Prints each option individually i.e option 1
		
		//
 		//Author: Raydel Miranda
 		//Publication Date: 2/4/2015
 		//Title and Version: Rewind an ifstream object after hitting the end of file
 		//Source: https://stackoverflow.com/questions/28331017/rewind-an-ifstream-object-after-hitting-the-end-of-file
		//Date Retrieved: 2/7/20223
 		//
		file.clear();			//Clears and resets the file for the next option to use
		file.seekg(0);

		printParallelRecursive(file);

		file.clear();
		file.seekg(0);

		printObjectArrayIterative(file);
	
		file.clear();
		file.seekg(0);

	        printObjectArrayRecursive(file);

		file.clear();
                file.seekg(0);

		printObjectArrayPointer(file);

		file.clear();
                file.seekg(0);

		printSeqContainerIndex(file);

		file.clear();
		file.seekg(0);

		printSeqContainerIterator(file);

		file.clear();
                file.seekg(0);	

	        file.close();
		}
	}
	else {						//User selection mode

	string filename;

	getFilename(filename);				//gets filename from user
	
	fstream file;
        file.open(filename.c_str());			//attempts to open the file

	if(file.fail()){				//If the file does not exsist, terminate program
        	cout << "Failed to open file " << filename << endl;
        }
        else {

	int user_selection = 0;

	do {						//Loop to get input from the user, ends when they enter 8

	printMenu();					//print menu for user to see

	cin >> user_selection;				//gets the user input
	cout << "Choice Entered: " << user_selection << endl;

	switch(user_selection) {			//switch to select the proper subfunction based on the users selection
	//PARALLEL ARRAYS
	case 8:
		break;
	case 1:
	{
		printParallelIterative(file);		//prints the subfunction based on the case i.e option 1
		file.clear();				//Clear and reset the file for the next use
		file.seekg(0);
		break;
	}
	case 2:
	{
		printParallelRecursive(file);
		file.clear();
		file.seekg(0);
		break;
	}
	//OBJECT ARRAYS
	case 3:
	{
		printObjectArrayIterative(file);
		file.clear();
		file.seekg(0);
		break;
	}
	case 4:
	{
		printObjectArrayRecursive(file);
		file.clear();
		file.seekg(0);
		break;
	}
	case 5:
	{
		printObjectArrayPointer(file);	
		file.clear();
		file.seekg(0);
		break;
	}
	//SEQUENTIAL CONTAINER //
	case 6:
	{
		printSeqContainerIndex(file);
		file.clear();
		file.seekg(0);
		break;
	}
	case 7:
	{	
		printSeqContainerIterator(file);
		file.clear();
                file.seekg(0);
		break;
	}
	default:
	{
		cout << "Invalid Selection" << endl;		
		break;
	}
	
	} //switch

	} //do
	while(user_selection != 8);

	file.close();				//close the file
	} // else

	}

	return 0;				//end the program
}
