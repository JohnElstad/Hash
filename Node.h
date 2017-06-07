#include <iostream>
#include <string.h>
#include "Student.h"

using namespace std;


class Node{
 public:
  Node* getNext();
  Node(Student* s);
  ~Node();
  Student* data();
  void setNext(Node* n);
 private:
  Student* studentpointer;
  Node* next;
};
