#include "HashTable.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
//Hash table that cana add students, delete students and randomly add students.
HashTable::HashTable(){ 

  array = new Node*[100];
  size = 100;
}
//adds your basic student
void HashTable::add(){

  add(new Student());
}
//looks through the array and deletes if its there/ has the id that was typed in
void HashTable::remove(int id){

  for (int i = 0; i < size; i++){
    Node* current = array[i];
    if (current){
      if (current->data()->getId() == id){
	array[i] = current->getNext();
	delete current;
      }
      else{
	Node* last = current;
	current = current->getNext();
	while(current){
	  if (current->data()->getId() == id){
	    last->setNext(current->getNext());
	    delete current;
	  }
	  current = current->getNext();
	}
      }
    }
  }
}
//opens the first and last name files/ chooses randomly
void HashTable::addRandom(int newCount){

  char* firsts[100];
  char* seconds[100];
  ifstream firstStream;
  ifstream secondStream;
  firstStream.open("firsts.txt");
  secondStream.open("seconds.txt");
  if (firstStream.is_open() && secondStream.is_open()){
    int i = 0;
    char newInput[30];
    firstStream >> newInput;
    firsts[i] = strdup(newInput);
    i++;
    while(firstStream.peek() != '\n' && !firstStream.eof()){
      firstStream >> newInput;
      firsts[i] = strdup(newInput);
      i++;
      
    }
    int j = 0;
    secondStream >> newInput;
    seconds[j] = strdup(newInput);
    j++;
    while(secondStream.peek() != '\n' && !secondStream.eof()){
      secondStream >> newInput;    
      seconds[j] = strdup(newInput);
      j++;
    }
    int id;
    char* first;
    char* second;
    float gpa;
    
    
    for(int k = 0; k < newCount; k++){
      id = 1000 + rand()%9000;
      first = firsts[rand()%i];
      second = seconds[rand()%j];
      gpa = float(rand()%400)/100;
      add(new Student(id,first,second,gpa));
 
    }
  }
}
//basic print function
void HashTable::print(){

  for (int i = 0; i < size; i++){
    Node* current = array[i];
    while(current){
      current->data()->print();
      current = current->getNext();
    }
  }
}
//adds student
void HashTable::add(Student* student, bool checkCollisions){
  int key = getKey(student);
  if(array[key]){
    Node* current = array[key];
    int collisionCount = 1;
    while(current->getNext()){
      collisionCount ++;
      current = current->getNext();
    }
    current->setNext(new Node(student));
    if(collisionCount >= 3 && checkCollisions){
      expand();
    }
  }
  else{
    array[key] = new Node(student);
  }
}
//doubles the array size and then adds one to it so that your remainders are different.
void HashTable::expand(){

  Node** old = array;
  array = new Node*[size*2 + 1];
  int oldSize = size;
  size = size*2+1;
  for (int i = 0; i < oldSize; i++){
    Node* current = old[i];
    while(current){
      add(current->data(),false);
      current = current->getNext();
    }
  }
  delete old;
}
//hash function
int HashTable::getKey(Student* student){

  int toReturn = student->getId();
  return toReturn %size;
}
