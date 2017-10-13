/*
 * File Name: BSTNode.hpp
 * Author: Jiaxiao Zhou & Yuqi Kang
 * Userid: A14057703 & A92048017
 * Description: Implement functions to construct a BST Node
 * Date: 10/12/2017
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/** Starter code for PA1, CSE 100 2017
 * This code is based on code by
 * Christine Alvarado and Paul Kube.
 * Jiaxiao Zhou & Yuqi Kang
 */

template<typename Data>
class BSTNode {

public:

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;.

 /*
  * Name: Constructor.  
  * Description: Initialize a BSTNode with the given Data item,
  *              no parent, and no children.
  * Parameters:
  *       arg1: Data &d -- the address of data to initialize
  */
  BSTNode(const Data & d);


 /* Return the successor of this BSTNode in a BST, or 0 if none.
  * PRECONDITION: this BSTNode is a node in a BST.
  * POSTCONDITION:  the BST is unchanged.
  * RETURNS: the BSTNode that is the successor of this BSTNode,
  *           or 0 if there is none.
  */
  BSTNode<Data>* successor(); 

}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file
// as the class declaration

/*
 * Function Name: BSTNode()
 * Function Prototype: BSTNode(const Data & d) : data(d), left(0), right(0), 
 *                     parent(0)
 * Decription: Initialize a BST node element
 * Parameters:
 *       arg1: Data &d -- the data that node to store
 * Return Value: BSTNode 
 */
template <typename Data>
BSTNode<Data>::BSTNode(const Data & d):data(d), left(0), right(0), parent(0) {}

/* 
 * Function Name: successor()
 * Function Prototype: BSTNode<Data>* successor()
 * Descirption: Return a pointer to the BSTNode that contains the item that is
 *              sequentially next in the tree 
 * Parameters: None
 * Return Value: a ptr to BSTNode containing items in the tree
 */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{
  
  if(right != nullptr) {// if this node has a right child
    BSTNode<Data>* current = right; 
    while(current->left != nullptr) {
      current = current->left;
    }
    return current;
  }
  
  else { // if this node has no right child. we go to the root
    BSTNode<Data>* current = parent;
    while(current != nullptr) {
      if(current->data < data) {
        current = current->parent;
      } else {
        return current;
      }
    }
    return nullptr;
  }
}

/*
 * Function Name: operator()
 * Function Prototype: operator<<(std::ostream& stm, const BSTNode<Data> & n)
 * Description: Overload operator<< to print a BSTNode's fields to an ostream. 
 * Parameters:
 *       arg1: std::ostream& stm -- the addressof ostram to store
 *       arg2: const BSTNode<Data> &n -- the address of data node
 * Return Value: ostream to print
 */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
