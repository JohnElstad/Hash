#include <iostream>
#include "HashTable.h"
#include <cstdlib>

//John Elstad, This is a Hash table to store students, June 6th

int main(){
  cout<<"Welcome to Hash Table:"<<endl;
  cout<<"Valid Commands are: Add, Delete, Print, Random and Quit"<<endl;
  srand (time(NULL));

  HashTable* table = new HashTable();
  char input[128];
  bool running = true;

  while(running){

    cin.getline(input, 128);
    
    if(input[0] == 'a') {
      table->add();
    }
    else if(input[0] == 'd'){
      int id;
      cout << "What is the student ID you want to remove?" << endl;
      cin >> id;
      table->remove(id);
      cin.ignore();
      
    }
    else if(input[0] == 'p'){
      table->print();
    }
    else if(input[0] == 'r'){
      int number;
      cout << "How many random students do you want?" << endl;
      cin >> number;
      cin.ignore();
      table->addRandom(number);
    }
    else if(input[0] == 'q'){
      running = false;
    }
    else{
      cout << "Something was mistyped:" << endl;
      cout << "Valid commands are:\nAdd\nDelete\nPrint\nRandom\nQuit" << endl;
    }
  }
}
