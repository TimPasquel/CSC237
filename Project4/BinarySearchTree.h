// File: BinarySearchTree.h
// Author: Dr. Spiegel and Tim Pasquel
// Course: CSC237
// Description: Binary Tree ADT defined using Linked Structures

/*!	\file BinarySearchTree.h 
 * *	\brief A custom data structure that uses a binary search tree
 * *	\class BinaryTree 
 * *	\brief A class that utilizes a binary search tree
 * *    \class TreeNode
 * *    \brief An individual node on the binary search tree, holds info and a pointers to the next node
 * */

#ifndef TREE_H
#define TREE_H

 template <typename treeEltType> class BinaryTree;

 template <typename eltType> class TreeNode {
 private:
  eltType info;
  //UPDATE: Added a counter
  int count = 1;
  TreeNode<eltType> *left,*right;  
  TreeNode(const eltType &data,
                        TreeNode<eltType> *lChild=NULL,TreeNode *rChild=NULL)
  {info=data;   left=lChild; right=rChild;  }
  
  friend class BinaryTree<eltType>;
 };

template <typename treeEltType> class BinaryTree {

public:

 // Constructor
///
///Function Name: constructor
///
///Description: Constructs a binary tree
///
///Parameters: None
/// 
///Member Type: Mutator
///
///Return Value: None
///
 BinaryTree();

 // Place Element into Tree
 // Returns 1 if inserted, 0 if Data already in tree
///
///Function Name: insertToTree
///
///Description: Sends a value in which a node is to be created 
///             or incremented 
///
///Parameters: const treeEltType &data - The value in which a node
///            will be created or incremented
/// 
///Member Type: Mutator
///
///Return Value: int 
///
 int insertToTree(const treeEltType &data);

 // Search for Element in Tree
 // Assumes == is defined for treeEltType
 // Returns pointer to data, or NULL, according to success
///
///Function Name: treeSearch
///
///Description: Searches for an element in a tree, if found returns
///             a pointer to the data, or Null otherwise 
///
///Parameters: const treeEltType &data - The value of a node
///            to be found
/// 
///Member Type: Facilitator
///
///Return Value: treeEltType* - pointer of the return node 
///
 treeEltType *treeSearch(const treeEltType &data);

///
///Function Name: retrieveCount
///
///Description: Searches for a node, returns a reference to 
///             it's counter
///
///Parameters: const treeEltType &key - The value of a node
///            to be found
/// 
///Member Type: Inspector
///
///Return Value: treeEltType& - A reference to the count in the node
///
 treeEltType &retrieveCount(const treeEltType &key);

///
///Function Name: decrementNode
///
///Description: Searches for the node whose count need to be
///             decremented by 1
///
///Parameters: const treeEltType &data - The value of a node
///            to be found
/// 
///Member Type: Mutator
///
///Return Value: void
///
 void decrementNode(const treeEltType &data);

 // Retrieve Element from Tree (leaving Tree Intact)
 // Precondition: Item is in Tree
///
///Function Name: retrieveFromTree
///
///Description: Retrieve an element from the tree, leaves the tree 
///             intact. Item must be in the tree first
///
///Parameters: const treeEltType &data - The value of a node
///            to be retrieved
/// 
///Member Type: Facilitator
///
///Return Value: treeEltType& - A reference of the return node 
///
 treeEltType &retrieveFromTree(const treeEltType &data);

 // Remove an Element from the tree
 // Pre: Element is in the Tree
///
///Function Name: deleteFromTree
///
///Description: Deletes a node from the tree that equals to data
///
///Parameters: const treeEltType &dada - the value to be deleted
/// 
///Member Type: Mutator
///
///Return Value: void
///
 void deleteFromTree(const treeEltType &data);

 // Display Tree using InOrder Traversal
///
///Function Name: inorder
///
///Description: Prints the binary tree in order based on value
///
///Parameters: None
/// 
///Member Type: Inspector
///
///Return Value: void
///
 void inorder() const;

 // Display Tree using PreOrder Traversal
///
///Function Name: preorder
///
///Description: Prints the binary tree using a preorder traversal
///
///Parameters: None
/// 
///Member Type: Inspector
///
///Return Value: void 
///
 void preorder() const;

 // Display Tree using PostOrder Traversal
///
///Function Name: postorder
///
///Description: Prints the binary tree using a postorder traversal
///
///Parameters: None
/// 
///Member Type: Inspector
///
///Return Value: void 
///
 void postorder() const;
 
 // Breadth first print
///
///Function Name: treePrint
///
///Description: Prints the binary tree of how it would look
///             like in a drawing
///
///Parameters: None
/// 
///Member Type: Inspector
///
///Return Value: void 
///
 void treePrint() const;
 
private:

 TreeNode<treeEltType> *root;

 // Display Tree using InOrder Traversal
///
///Function Name: printInorder
///
///Description: The helper function that prints the binary tree
///             in order by value
///
///Parameters: TreeNode<treeEltType> * - The current node
/// 
///Member Type: Inspector
///
///Return Value: void 
///
 void printInorder(TreeNode<treeEltType> *) const;

 // Display Tree using PreOrder Traversal
///
///Function Name: printPreorder
///
///Description: The helper function that prints the binary tree
///             using a preorder traversal
///
///Parameters: TreeNode<treeEltType> * - The current node
/// 
///Member Type: Inspector
///
///Return Value: void 
///
 void printPreorder(TreeNode<treeEltType> *) const;

 // Display Tree using PostOrder Traversal
///
///Function Name: printPostorder
///
///Description: The helper function that prints the binary tree
///             using a postorder traversal
///
///Parameters: TreeNode<treeEltType> * - The current node
/// 
///Member Type: Inspector
///
///Return Value: void 
///
 void printPostorder(TreeNode<treeEltType> *) const;
 
///
///Function Name: treePrintHelper
///
///Description: The helper function that prints the binary tree
///             like how it would look in a drawing
///
///Parameters: TreeNode<treeEltType> * - The current node
/// 
///Member Type: Inspector
///
///Return Value: void 
///
 void treePrintHelper(TreeNode<treeEltType> *) const;

};

#endif
