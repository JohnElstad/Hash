#include <iostream>
#include "Node.h"
//Class that holds students with hash table
class HashTable{
 public:
  HashTable();
  void add();
  void remove(int id);
  void addRandom(int number);
  void print();
 private:
  void add(Student* student,bool checkCollisions = true);
  void expand();
  int getKey(Student* student);
  Node** array;
  int size;
};
