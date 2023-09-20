#ifndef PROJ1-PERSON_HPP_INCLUDED
#define PROJ1-PERSON_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  int age;
};

istream &getAPersonFromStream(istream &, Person *); // reads a single Person from the stream
void sortPersonArrayByAge(Person **, int); // implements selection sort ascending order
void sortPersonArrayByName(Person **, int); // implements bubble sort ascending order
Person * findAPerson(Person **, int, string); // implements linear search
void displayAPerson(ostream &, const Person *); // writes a single Person to the stream

#endif // PROJ1-PERSON_HPP_INCLUDED
