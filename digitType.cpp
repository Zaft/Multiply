//COSC 222 - Lab4
//Kurt Fitz - 300213819
//Code for the node used in the Linked List

struct digitType
{
 char info;
 digitType* link;

  int getInfo()
  {
    return info - '0';
  }
};
