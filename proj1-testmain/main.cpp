/**
 * file: proj1-testmain.cpp
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
    istringstream inSS;
    string tester;
    int count = 5;

    for(int i = 0; i < 25; ++i){
        referenceToThePeople[i] = &thePeople[i];
    }

    tester = "Jan Jasa, 20\nJaden Park, 15\nBill Booth, 30\nBrittney Spears, 101\nZach Last, 50";
    inSS.clear();
    inSS.str(tester);

    cout << "Testing getAPersonFromStream Function" << endl;
    for(int i=0; i<count; i++){
        getAPersonFromStream(inSS, referenceToThePeople[i]);
    }

    cout << "Testing displayAPerson Function " << endl;
    for(int i=0; i<count; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }
    //should see Jan Jasa, 20 Jaden Park, 15 Bill Booth, 30 Brittney Spears, 101 Zach Last 50

    cout << "\nTesting sortPersonArrayByAge" << endl;
    for(int i=0; i<count; i++){
        sortPersonArrayByAge(referenceToThePeople, count);
    }
    for(int i=0; i<count; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }
    //should display Jaden, Jan, Bill, Zach, Brittney (in that order)

    cout << "\nTesting sortPersonArrayByName" << endl;
    for(int i=0; i<count; i++){
        sortPersonArrayByName(referenceToThePeople, count);
    }
    for(int i=0; i<count; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }
    //should output Bill, Brittney, Jaden, Jan, Zach


    cout << "\nTesting findAPerson" << endl;
    string testName1="Jan Jasa";
    displayAPerson(cout, findAPerson(referenceToThePeople, count, testName1));
    cout << endl;
    //should output Jan Jasa, 20

    cout << "\nTesting nullptr on findAPerson" << endl;
    string testName2="Non Existent Human";
    if(findAPerson(referenceToThePeople, count, testName2)==nullptr){
        cout << "nullptr" << endl;
    }


    return 0;
}
