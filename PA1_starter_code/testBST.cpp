#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2017
 * Based on code by Christine Alvarado
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }

    // test not find element
    cout << "testing the element not in BST." << endl;
    BSTIterator<int> notFound = btemp.find(325);
    if( notFound != btemp.end() ) {
	cout << ": Incorrect, not found should return iterator with nullptr";
	return -1;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }
   
    // test height of the bst
    cout << "testing height of the bst" << endl;
      
    auto height = btemp.height();
    if( height != 2) {
        cout << ": Incorrect height of BST." << endl;
        return -1; 
    }
     
    btemp.insert(500);
    if( btemp.height() != 3) {
        cout << ": Incorrect height of BST." << endl;
	return -1;
    }
    
    BST<int> emptyTree;
    if( emptyTree.height() != 0 ) {
	cout << ":  Incorrect height of BST." << endl;
        return -1;
    }
   
    cout << "the height is correct!" << endl;

    // test size of the bst
    cout << "testing size of the bst" << endl;
    auto sizeBST = btemp.size();
    if( sizeBST != 6 ) {
        cout << ": Incorrect size of BST." << endl;
        return -1;
    }

    // test empty of the bst
    cout << "testing empty of the bst" << endl;
    BST<int> emptyBST;
    if( !emptyBST.empty() ) {
	cout << ": Incorrect empty of BST." << endl;
	return -1;
    }

    if( btemp.empty() ) {
	cout << ": Incorrect empty of BST." << endl;
	return -1;
    }

    // test inserting repeated element
    cout << "testing inserting repeated element to the bst" << endl;
    
    auto repeatedResult = btemp.insert(500);
    if(repeatedResult.second) {
	cout << ": Incorrect inserting repeated element to BST." << endl;
	return -1;
    } 

    if (*(repeatedResult.first) != 500) {
        cout << "Wrong iterator returned.  "
            << "Expected " << 500 << " but got " << *(repeatedResult.first) << endl;
        return -1;
    }
    cout << "success!" << endl;
    cout << "All tests passed!" << endl;
    return 0;
}
