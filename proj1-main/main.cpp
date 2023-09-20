/**
 * file: proj1-main.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment: Project 1
 * due date: 1/23/2023
 **/
#include <iostream>
#include "proj1-person.hpp"
#include <fstream>
#include <sstream>

using namespace std;
const int MAX_SIZE = 25;

int main()
{

    Person thePeople[MAX_SIZE];
    Person *referenceToThePeople[MAX_SIZE];
    string givenFile = "people.dat";
    ifstream inFS;
    istringstream inSS;
    string holder;
    int count=0; //CURRENT size of array


    inFS.open(givenFile);

    for(int i=0; i<MAX_SIZE; i++){
        //set pointers to thePeople array
        referenceToThePeople[i]=&thePeople[i];
    }

    while(inFS){
        getline(inFS, holder);
        inSS.clear();
        inSS.str(holder);
        getAPersonFromStream(inSS, referenceToThePeople[count]);
        count++;
    }
    count--; //To offset repeating last person



    cout << "First 5 people sorted by age\n" << endl;
    sortPersonArrayByAge(referenceToThePeople, count);
    for(int i=0; i<5; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }

    cout << "\nFirst 5 people sorted by name\n" << endl;
    sortPersonArrayByName(referenceToThePeople, count);
    for(int i=0; i<5; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }

    cout << "\nEnter a person(Type no more to quit): ";
    getline(cin, holder);

    while(holder!="no more"){
        if(findAPerson(referenceToThePeople, count, holder) == nullptr){
            cout << "Not in the list." << endl;
        }
        else{
            displayAPerson(cout, findAPerson(referenceToThePeople, count, holder));
        }
        getline(cin, holder);
    }

    return 0;
}
