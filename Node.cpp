#include <iostream>
#include <string.h>
#include "Node.h"


using namespace std;

Node::Node(Student* s){
  next = NULL;
  
  studentpointer = s;
}

Node::~Node(){
  delete studentpointer;
}

Node* Node::getNext(){
  return next;
}

void Node::setNext(Node* n){
  next = n;
}

Student* Node::data(){
  return studentpointer;
}
