/*
 * File Name: BSTIterator.hpp
 * Author: Jiaxiao Zhou & Yuqi Kang
 * Userid: A14057703 & A92048017
 * Description: Implement functions of BST iterator to create a BST
 *              iterator to help the functions of BST
 * Date: 10/12/2017
 */

#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>


// Notice this class extends the std::iterator class.
/*
 * Class Name: BSTIterator
 * Class Function: Implement an BST iterator to help BST 
 */

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
  BSTIterator(BSTNode<Data>* curr);

  /** Dereference operator. */
  Data operator*() const;
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++();

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int);

  /** Equality test operator. */
  bool operator==(BSTIterator<Data> const & other) const;

  /** Inequality test operator. */ 
  bool operator!=(BSTIterator<Data> const & other) const;

};

/*
 * Name: Constructor.  
 * Description: Use the argument to initialize the current BSTNode
 *              in this BSTIterator.
 * Parameters: 
 *       arg1: BSTNode<Data>* curr -- a pointer to an BSTNode object
 *                                    to be current pointing node
 * Return Value: None
 */ 
template<typename Data>
BSTIterator<Data>::BSTIterator(BSTNode<Data>* curr) {
  this->curr = curr;
}

/*
 * Function name:operator*()
 * Function Prototype: Data operator*()
 * Description: Dereference operator. 
 * Parameters: None
 * Return Value: the data stored in the node that iterator is pointing
 */
template<typename Data>
Data BSTIterator<Data>::operator*() const {
  return curr->data;
}
  
/*
 * Function name: operator++()
 * Function Prototype: BSTIterator<Data>& operator++()
 * Description: Pre-increment operator. 
 * Parameters: None
 * Return Value: the address where the iterator is pointing
 */
template<typename Data>
BSTIterator<Data>& BSTIterator<Data>::operator++() {
  // Call the successor method of the BSTNode pointed to by curr.
  curr = curr->successor();
  return *this;
}

/*
 * Function name: operator++()
 * Function Prototype: BSTIterator<Data> operator++(iny)
 * Description: Post-increment operator. 
 * Parameters: 
 *       arg1: int -- the value to increment
 * Return Value: the original iterator is pointing
 */
template<typename Data>
BSTIterator<Data> BSTIterator<Data>::operator++(int) {
  BSTIterator before = BSTIterator(curr);
  ++(*this);
  return before;
}

/*
 * Function name: operator==(BSTIterator<Data> const & other)
 * Functon Prototype: boll operator==(BSTIterator<Data> const & other) const
 * Description: Equality test operator
 * Parameters:
 *       arg1: the BSTIterator to compare with
 * Return Value: whether two iterators are equal or not, true if equal
 */
template<typename Data>
bool BSTIterator<Data>::operator==(BSTIterator<Data> const & other) const {
 
  // Two iterators are equal if they point to the same BSTNode in the same BST  
  return this->curr == other.curr;

}

/*
 * Function name: operator!=(BSTIterator<Data> const & other)
 * Functon Prototype: boll operator!=(BSTIterator<Data> const & other) const
 * Description: Inequality test operator
 * Parameters:
 *       arg1: the BSTIterator to compare with
 * Return Value: whether two iterators are equal or not, true if unequal
 */ 
template<typename Data>
bool BSTIterator<Data>::operator!=(BSTIterator<Data> const & other) const {
 
  // Two iterators are equal if they point to the same BSTNode in the same BST
  return this->curr != other.curr;

}


#endif //BSTITERATOR_HPP
