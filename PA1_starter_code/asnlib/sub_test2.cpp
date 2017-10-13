#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

  /* Create an STL vector of some strings */
  /*test*/
  vector<std::string> vn;
  vn.push_back("LEIGH, NELSON");
  vn.push_back("STAMP, TERENCE");
  vn.push_back("ROCKWELL, ROBERT");
  vn.push_back("CROWE, RUSSELL");
  vn.push_back("WELLING, TOM");
  vn.push_back("WARNER, DAVID");
  vn.push_back("SANDS, JULIAN");
  vn.push_back("BRANDO, MARLON");

  /* Create an instance of BST holding int */
  BST<std::string> bn;

  /* Insert a few data items. */
  vector<std::string>::iterator vnit = vn.begin();
  vector<std::string>::iterator vnen = vn.end();

  cout << "Testing empty... ";

  if(!bn.empty())
    {
      cout << "Incorrect bool when calling empty(). Exiting..." << endl;
      return -1;
    } 

  cout << "SUCCESS!" << endl;


  /* Test insert function */
  cout << "\n" << "Testing insert..." << endl;
  for(; vnit != vnen; ++vnit) {
    // all these inserts are unique, so should return true
    cout << "Inserting " << *vnit << "... ";
    auto pr = bn.insert(*vnit);
    if(! pr.second ) {
      cout << "Incorrect bool return value when inserting " << *vnit << ". Exiting." << endl;
      return -1;
    }
    cout << "SUCCESS!" << endl;
  }


  /* Test find function */
  cout << "\n" << "Attempting to find elements..." << endl;
  vnit = vn.begin();
  BST<std::string>::iterator bnen = bn.end();
  for(; vnit != vnen; ++vnit) {
    cout << "Searching for " << *vnit << "... ";
    if(bn.find(*vnit) == bnen)
      {
	cout << "Failed to find" << *vnit << ". Exiting." << endl;
      }
    cout << "SUCCESS!" << endl;
    }

  sort(vn.begin(),vn.end());
  vnit = vn.begin();
  vnen = vn.end();

  /* Testing iteration (successor, begin, end)*/

  BST<std::string>::iterator bnit = bn.begin();
  bnen = bn.end();

  cout << "\n" << "Testing inorder traversal using for loop... " << endl;

  for(; bnit != bnen; ++bnit)
    {
      if(vnit == vnen)
	{
	  cout << "Early termination of inorder traversal via for loop. Exiting." << endl;
	  return -1;
	}
      if(*vnit != *bnit)
	{
	  cout << "Expected " << *vnit << " but found " << *bnit << ". Exiting." << endl;
	  return -1;
	}
      cout << *bnit << endl;
      ++vnit;
    }

  cout << "SUCCESS!" << endl << endl;

  /* Printing functions: size, height */
  cout << "Printing size: " << bn.size() << endl;
  if(bn.size()!= vn.size())
  {
    cout << "Error. Expected size = " << vn.size() << ". Exiting" << endl;
    return -1;
  }
  cout << "Printing height: " << bn.height() << endl;
  if(bn.height()!= 3)
  {
    cout << "Error. Expected height = 3. Exiting" << endl;
    return -1;
  }

  return 0;
}
