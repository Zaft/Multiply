//COSC 222 - Lab4
//Kurt Fitz - 300213819

#include <iostream>
#include <fstream>
#include "linkedListType.cpp"

using namespace std;

int main(int argc, char** argv)
{ 
  //function to add two linked lists
  linkedListType* addNumbers(linkedListType* n1, linkedListType* n2);
  //function to multiply two linked lists
  linkedListType* multiplyNumbers(linkedListType* n1, linkedListType* n2);

  //iterative count of linkedlist nodes
  int iterative(linkedListType* list);


  linkedListType* num1;
  linkedListType* num2;

  num1 = new linkedListType();
  num2 = new linkedListType();
  
  if(argc != 4){ //argc should be 3 for correct execution (two input, one output).
    cout << "usage: " << argv[0] << " expected three 3 files at command line two input files, and one output file." << endl;
    return 1;
  }

  ifstream in1(argv[1]);
  ifstream in2(argv[2]);
  ofstream out(argv[3]);

  //open first input file and read in number
  if(in1.is_open()){
    while(in1.good()){ //loop while extraction from file is possible
      char c = in1.get(); //get character from file
	if(in1.good()){
	  num1->insert(c);
	}
    }
    in1.close(); //close the file
  }
  else cout << "Unable to open file1" << endl;

  //open second input file and read in number
  if(in2.is_open()){
    while(in2.good()){
      char c = in2.get();
      if(in2.good()){
	  num2->insert(c);
      }
    }
    in2.close(); //close the file
  }
  else cout << "Unable to open file2" << endl;
 
  num1->print();
  int numNodes =  iterative(num1);
  cout << numNodes << endl;
  int numNodes2 = iterative(num2);
  cout << numNodes2 << endl;

};

int iterative(linkedListType* list){
  int count = 0;
  digitType* temp;
  temp = new digitType();
  temp = list->getFirst();
  list->print();
  if(temp == NULL)
    return 0;
  else{
    while(temp->info==(3+'0')){
      temp = temp->link;
      count++;
    }
  }
  count++;
  return count;
}

linkedListType* addNumbers(linkedListType* num1, linkedListType* num2)
{
  linkedListType* result;
  result = new linkedListType();
  digitType* firstNum = new digitType();
  digitType* secondNum = new digitType();
  int carry = 0;

  firstNum = num1->getFirst();
  secondNum = num2->getFirst();

  while(firstNum != NULL || secondNum != NULL)
    {
      // subtracting the char '0' converts char to int
      int val1 = firstNum != NULL ? firstNum->getInfo() : 0;
      int val2 = secondNum != NULL ? secondNum->getInfo() : 0;
      
      int temp = carry + val1 + val2;
      if(temp > 9){
	carry = temp / 10;
	temp = temp % 10;
      } else {
	carry = 0;
      }
      result->insertLast(temp+'0'); 
      firstNum = firstNum != NULL ? firstNum->link : NULL;
      secondNum = secondNum != NULL ? secondNum->link : NULL;
    }
  if(carry>0)
    result->insertLast(carry+'0');

  return result;
}

linkedListType* multiplyNumbers(linkedListType* num1, linkedListType* num2){
  linkedListType* result;
  result = new linkedListType();
  
  digitType* firstNum;
  digitType* secondNum;
  digitType* tempSecondNum;

  firstNum = new digitType();
  secondNum = new digitType();
  tempSecondNum = new digitType();
  tempSecondNum = secondNum;

  firstNum = num1->getFirst();
  secondNum = num2->getFirst();

  int carry = 0;
  int placeHolder = 0;
  
  while(firstNum != NULL){
    int val1 = firstNum != NULL ? firstNum->getInfo() : 0;
    
    linkedListType* tempList;
    tempList = new linkedListType();
    for(int i = 0; i<placeHolder; i++){
      tempList->insert(0 + '0');
    }
    while(secondNum != NULL){ 
      int val2 = secondNum != NULL ? secondNum->getInfo() : 0;
      int temp = val1 * val2 + carry;
      if(temp > 9){
	carry = temp / 10;
	temp = temp % 10;
      }else{
	carry = 0;
      }
      tempList->insertLast(temp + '0');
      secondNum = secondNum != NULL ? secondNum->link : NULL;
    }
    if(carry>0){
      tempList->insertLast(carry + '0');
    }
    result = addNumbers(tempList, result);
    secondNum = num2->getFirst();
    firstNum = firstNum != NULL ? firstNum->link : NULL;
    placeHolder = placeHolder + 1;
  }
  return result;
}
