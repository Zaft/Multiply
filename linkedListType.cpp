//COSC 222 - Lab4
//Kurt Fitz - 300213819
//Code use for the linked list

#include <iostream>
#include "linkedListType.h"

using namespace std;

linkedListType::linkedListType() //default constructor
{
  first = NULL;
}

void linkedListType::print() const{
  string out = "";
  digitType* temp;
  temp = first;
  while(temp->link != NULL){
    out = temp->info + out;
    temp = temp->link;
  }
  if(temp->link == NULL)
    out = temp->info + out;
  cout << out << endl;
}

void linkedListType::insert(const char newItem){
  digitType *newNode;
 
  newNode = new digitType();
  newNode->info = newItem;

  if(first == NULL){
    first = newNode;
    last = newNode;
  } else {
    newNode->link = first;
    first = newNode;
  }
}

digitType* linkedListType::getFirst() const{
  return first;
}

void linkedListType::insertFirst(const char& newItem){
  digitType *newNode; //pointer to create the new node
  newNode = new digitType(); //create the new node

  newNode->info = newItem;
  newNode->link = first; //insert new node before first
  first = newNode;

  if(last == NULL) //If list was empty, newNode is also the last node
    last = newNode;
}

void linkedListType::insertLast(const char newItem){
  digitType *newNode; //pointer to create the new node
  newNode = new digitType(); //create the new node

  newNode->info = newItem;
  newNode->link = NULL;
  digitType* current;
  current = first;

  if(first == NULL){ //If the list is empty, newNode is first
    first = newNode;
  }
  else{
    while(current->link != NULL) {
	current = current->link;
      }
    current->link = newNode;
  }  
}
