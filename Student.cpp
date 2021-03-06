B#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;
//Student class that contians student info

Student::~Student(){
  delete firstName;
  delete lastName;
}

Student:: Student(int newId, char* first, char* last, float newGpa){
  id = newId;
  firstName = first;
  lastName = last;
  gpa = newGpa;

}
//constructor to input data
Student::Student(){

  lastName = new char[30];
  firstName = new char[30];

  cout << "New ID" << endl;
  cin >> id;
  cin.ignore();
  cout << "New First Name?" << endl;
  cin.get(firstName,30);
  cin.ignore();
  cout << "New Last Name" << endl;
  cin.get(lastName,30);
  cin.ignore();
  cout << "New GPA?" << endl;
  cin >> gpa;
  cin.ignore();
  cout << "Added student with info" << endl;
  cout << "Name: " << firstName << " " << lastName << ", ID: " << id << ", GPA: " << setprecision(2) <<fixed << gpa << endl;
}
int Student::getId(){
  return id;
}
float Student::getGpa(){
  return gpa;
}
void Student::print() {
  cout << "Student: " << firstName << " " << lastName << ", " << id << ", " << gpa << endl;
}
