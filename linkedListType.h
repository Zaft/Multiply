//COSC 222 - Lab4
//Kurt Fitz - 300213819

#include <iostream>
#include "digitType.cpp"

using namespace std;

class linkedListType
{
public:
 
  void print() const;
  //Prints date contained in each node

  digitType* getfirst();
  //returns a pointer to the first element in list
 
  void insert(const char newItem);
  //Function to insert in the front of list

  void insertFirst(const char& newItem);
  //Function to insert item in the front of list

  void insertLast(const char newItem);
  //Function to insert item at the end of list
  
  digitType* getFirst() const;
  //returns 

  linkedListType();
  //Default constructor
  //Initializes list to an empty state
  //Postcondition: first = NULL, last = NULL

private: 
  digitType *first;
  digitType *last;

};
