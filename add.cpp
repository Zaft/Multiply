//COSC 222 - Lab4
//Kurt Fitz - 300213819
//Code to add two arbitrarily large numbers a linked list data structure.

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
  
  //Call addNumbers
  linkedListType* result;
  result = new linkedListType();
  result = addNumbers(num1, num2);

  if(out.is_open()){
    digitType* tempNum;
    string output = "";
    tempNum = new digitType();
    tempNum = result->getFirst();
    while(tempNum->link != NULL){
      output = tempNum->info + output;
      tempNum = tempNum->link;
    }
    if(tempNum->link == NULL)
      output = tempNum->info + output;
    out << output << endl;
  }

  return 0;
};

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

