#include "proj1-person.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

istream &getAPersonFromStream(istream &is, Person *ptr){
    istringstream inSS;
    string holder;

    getline(is, ptr->name, ',');
    inSS.clear();
    getline(is, holder);
    inSS.str(holder);
    inSS>>ptr->age;

    return is;
}


void sortPersonArrayByAge(Person **pointPtr, int sizeOfArray){

    Person *temp;
    for(int i=0; i<sizeOfArray-1; i++){

        int indexSmallest = i;
        for(int j=i+1; j<sizeOfArray; j++){

            if(pointPtr[j]->age < pointPtr[indexSmallest]->age){
                indexSmallest=j;
            }
        }

        temp = pointPtr[i];
        pointPtr[i]=pointPtr[indexSmallest];
        pointPtr[indexSmallest]=temp;
    }
} // implements selection sort ascending order


void sortPersonArrayByName(Person **pointPtr, int sizeOfArray){
    Person *temp;
    for(int i=0; i<sizeOfArray-1; i++){
        for(int j=0; j<sizeOfArray-i-1; j++){
            if(pointPtr[j]->name > pointPtr[j+1]->name){
                swap(pointPtr[j], pointPtr[j+1]);
            }
        }
    }
}// implements bubble sort ascending order


Person * findAPerson(Person **pointPtr, int sizeOfArray, string name){
    bool found = false;
    for(int i=0; i<sizeOfArray; i++){
        if(pointPtr[i]->name == name){
            return pointPtr[i];
            found = true;
        }
    }

    if(!found){
        return nullptr;
    }

} // implements linear search


void displayAPerson(ostream &out, const Person *ptr){
    out << ptr->name << ", " << ptr->age << endl;
} // writes a single Person to the stream
