// File: TreeTest.cpp
// Author: Dr. Spiegel and Tim Pasquel
// Course: CSC237
// Description: Driver for Binary Tree ADT

/*!	\file Treetest.cpp 
 * *	\brief Test application for the binary search tree
 * */

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

typedef BinaryTree<int> IntTree;

///
///Function Name: getChoice
///
///Description: Checks to make sure the input is correct and
///             capitalize it for case sensitivity 
///
///Parameters: string ok - The acceptable chars to be used
/// 
///Return Value: char
///
char getChoice(string ok);


///
///Function Name: addToTree
///
///Description: Adds a node to the tree, if the node exsists
///             Increments the count
///
///Parameters: IntTree &TheTree - The binary tree
/// 
///Return Value: void
///
// Insert Value to Search Tree
void addToTree(IntTree &TheTree);

///
///Function Name: removeFromTree
///
///Description: Removes the node if count is 1, also deletes the node
///             or decrements the counter for the node based on user input
///
///Parameters: IntTree &TheTree - The binary tree
/// 
///Return Value: void
///
// Remove Value from Search Tree
void removeFromTree(IntTree &TheTree);

int main()
{IntTree Tree;
 int entry,*result;
 char Choice;
 do {
  cout << "Select: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
  Choice=getChoice("ARPTQ");
  switch (Choice) {
   case 'A':
    addToTree(Tree);
    break;
   case 'P':
    cout << "The Tree:" << endl;
    Tree.inorder();
    break;
   case 'R':
    removeFromTree(Tree);
    break;
   case 'T':
    cout << "The tree, as it appears (sort of)..\n";
    Tree.treePrint();
    break;
  }
 } while (Choice!='Q');
}

//Gets the users choice
char getChoice(string ok)
{char ch=' ';
 do ch=toupper(cin.get()); while (ok.find(ch)==string::npos);
 cin.get(); // eat CR
 return(toupper(ch));
}

// Insert Value to Search Tree
void addToTree(IntTree &TheTree)
{  int entry;
   cout << " Enter an Integer >";
   cin >> entry;
   TheTree.insertToTree(entry);
}

// Remove Value from Search Tree
void removeFromTree(IntTree &TheTree)
{  int entry,*result;
   cout << "Value to Delete? >";
   cin >> entry;
   result=TheTree.treeSearch(entry);
   if (!result) 
     cout << entry << " Not Found\n";
   //Delete or decrement node
   else {
     int count = TheTree.retrieveCount(entry);
     //Node has more than one copy
     if(count > 1 ) {
        string choice; 
        do {
        cout << "Do you want to remove all " << count << " copies or only One? (A or O)" << endl;
        cin >> choice;
           if(choice != "a" || choice != "A" || choice != "o" || choice != "O")
              break;
           else
              cout << "Invalid Selection, Try Again" << endl;
        }
        while(choice != "a" || choice != "A" || choice != "o" || choice != "O");

        //Deletes the entire node
        if(choice == "a" || choice == "A")
           TheTree.deleteFromTree(entry);
        //Decrements the node
        else
           TheTree.decrementNode(entry);
     }
     //Node only has one copy
     else
        TheTree.deleteFromTree(entry);
   }
}
