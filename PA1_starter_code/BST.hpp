/*
 * FileName: BST.hpp
 * Author: Jiaxiao Zhou & Yuqi Kang
 * Userid: A & A92048017
 * Description: Defines all the variables and functions required to construct
 *              a BST tree, and to add, find, delete nodes from it
 * Date: 10/12/2017
 */

#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

public:

  /*
   * define iterator as an aliased typename for BSTIterator<Data>. 
   */
  typedef BSTIterator<Data> iterator;

  /*
   * Default constructor.
   * Initialize an empty BST.
   * This is inlined because it is trivial.
   */
  BST() : root(nullptr), isize(0) {}


  /*
   * Default destructor.
   * Delete every node in this BST.
   */
  ~BST();

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return a pair where the first element is an iterator 
   *  pointing to either the newly inserted element or the element 
   *  that was already in the BST, and the second element is true if the 
   *  element was newly inserted or false if it was already in the BST.
   * 
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  
   */
  std::pair<iterator, bool> insert(const Data& item);


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  iterator find(const Data& item) const;

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const;
  
  /** Return the height of the BST.
      height of a tree starts with root at height 0
   */ 
  unsigned int height() const;


  /** Return true if the BST is empty, else false.
   */
  bool empty() const;

  /** Return an iterator pointing to the first (smallest) item in the BST.
   */ 
  iterator begin() const;

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const;


private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  
  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Find the first element of the BST
   * Helper function for the begin method above.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root);
  
  /** Helper method for giving the height of BST
   */
  unsigned int heightHelper(BSTNode<Data>* current) const;

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n);
 };


// ********** Function definitions ****************


/** Default destructor.
    Delete every node in this BST.
*/
template <typename Data>
BST<Data>::~BST() {
  deleteAll(root);
}


/*
 * Function Name: insert()
 * Function prototype: pair<BSTIterator<Data>, bool> insert(const Data& item)
 * Description: Given a reference to a Data item, insert a copy of it in 
 *               this BST.
 * Parameters:
 *       arg1: const Data& item -- the address of data to be inserted
 * Return Value: Apair where the first element is an iterator pointing 
 *               to either the newly inserted element or the element 
 *               that was already in the BST, and the second element is 
 *               true if the element was newly inserted or false if it 
 *               was already in the BST.
 *  
 */
template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {

  // BST empty 
  if(root == nullptr) { 
     root = new BSTNode<Data>(item); 
     isize ++;
     return std::pair<BSTIterator<Data>, bool>(iterator(root), true);
  }
  BSTNode<Data>* current = root;
  
  // compare with current node data
  while(current->data < item || item < current->data) {
    
    // go to the left child
    if(item < current->data) {
      if(current->left == nullptr) {
        current->left = new BSTNode<Data>(item);
	current->left->parent = current;
	isize ++;
        return std::pair<BSTIterator<Data>, bool>(iterator(current->left), 
               true);
      } 
      else {
        current = current->left;
      }
    }

    // go to the right child
    else {
      
      // if no right child 
      if(current->right == nullptr) {
        current->right = new BSTNode<Data>(item);
	current->right->parent = current;
        isize ++;
	return std::pair<BSTIterator<Data>, bool>(iterator(current->right), 
               true);
      }
      else {
      	current = current->right;
      }
    }
  }
  
  // return the pair
  return std::pair<BSTIterator<Data>, bool>(iterator(current), false);
}


/*
 * Function Name: find(const Data& item)
 * Function Prototype: BSTIterator<Data> find(const Data& item) const
 * Description: Find a Data item in the BST.
 * Parameter: 
 *      arg1: const Data& item -- the address of data to find
 * Return Value: an iterator pointing to the item, or pointing past
 *               the last node in the BST if not found.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{
  // BST empty
  if(root == nullptr) { return iterator(nullptr); }
  BSTNode<Data>* current = root;
  
  // compare with current node
  while(current->data < item || item < current->data) {
    if(item < current->data) { 
      if(current->left == nullptr) {return iterator(nullptr);}
      else { current = current->left; }
    }
    else {
      if(current->right == nullptr) {return iterator(nullptr); }
      else { current = current->right; }
    }
  }
  return iterator(current); 
}

  
/*
 * Function Name: size()
 * Function Prototype: unsigned int size() const
 * Description: Return the number of items currently in the BST.
 * Parameters: None
 * Return Value: the size of BST
 */ 
template <typename Data>
unsigned int BST<Data>::size() const
{
  return isize;
}

/*
 * Function Name: height()
 * Function Prototype: unsigned int height() const
 * Description: Return the current height of BST.
 * Parameters: None
 * Return Value: the height of BST
 */ 
template <typename Data> 
unsigned int BST<Data>::height() const
{
  if(root == nullptr) { return 0; }
  return heightHelper(root) - 1;
}

/*
 * Function Name: heightHelper()
 * Function Prototype: unsigned int heightHelper(BSTNode<Data>* current)
 * Description: Helper Method to find the current height of BST.
 * Parameters: 
 *       arg1: BSTNode<Data> *current -- the pointer to current node data
 * Return Value: the height until the current node
 */ 
template <typename Data>
unsigned int BST<Data>::heightHelper(BSTNode<Data>* current) const
{
  unsigned int leftlength = 0;
  unsigned int rightlength = 0;
  if(current->left != nullptr) { leftlength += heightHelper(current->left); }
  if(current->right != nullptr) {rightlength += heightHelper(current->right);}
  if(leftlength < rightlength) { return 1 + rightlength; }
  else { return 1 + leftlength; }
}


/*
 * Function Name: empty()
 * Function Prototype: bool empty() const
 * Description: Return whether BST is empty or not.
 * Parameters: None
 * Return Value: True if empty, False otherwise
 */ 
template <typename Data>
bool BST<Data>::empty() const
{
  return isize == 0;
}

/*
 * Function Name: begin()
 * Function Prototype: BSTIterator<Data> begin() const
 * Description:  Return an iterator pointing to the first (smallest) item
 *               in the BST.
 * Parameters: None
 * Return Value: iter pointing to the first item
 */  
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
  return BSTIterator<Data>(first(root));
}

/*
 * Function Name: end()
 * Function Prototype: BSTIterator<Data> end() const
 * Description:  Return an iterator pointing to the last (largest) item
 *               in the BST.
 * Parameters: None
 * Return Value: iter pointing to the last item
 */
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
  return BSTIterator<Data>(nullptr);
}

/*
 * Function Name: first()
 * Function Prototype: BSTNode<Data> first(BSTNode<Data>* root)
 * Description: Find the first element of the BST
 *              Helper function for the begin method above.
 * Parameters:
 *        arg: BSTNode<Data>* root -- the data stored in first node
 * Return Value: the first item
 */ 
template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
  if(root == nullptr) { return nullptr; }
  BSTNode<Data>* current = root;
  while(current->left != nullptr) {
    current = current->left;
  }
  return current;
}

/*
 * Function Name: deleteAll()
 * Function Prototype:  void first(BSTNode<Data>* n)
 * Description: Delete the current BST
 * Parameters:
 *        arg: BSTNode<Data>* n -- the data node to delete from
 * Return Value: None
 */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
  if(n == nullptr) {return;}
  deleteAll(n->left); 
  deleteAll(n->right);
  delete n;
}
#endif //BST_HPP
