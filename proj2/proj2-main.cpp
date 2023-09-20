/**
 * file: proj2-main.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment: Project 2
 * due date: 1/30/2023
 **/

#include <iostream>
#include "proj2-arrayFunctions.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream inFS;
    int size;

    //first variable is size, next line is data
    inFS.open("arrays.txt");

    while(inFS >> size){
        int *array = new int[size];

        //input n output values
        for(int i=0; i<size; i++){
            inFS >> *(array+i);
        }
        for(int i=0; i<size; i++){
            cout << *(array+i) << " ";
        }
        cout << "\n" << endl;

        //bubble sort
        bubbleSort(array, size);

        cout << "The array bubble sorted: " << endl;
        for(int i=0; i<size; i++){
            cout << *(array+i) << " ";
        }
        cout << endl;

        cout << "Largest value: " << largestValue(array, size) << endl;
        cout << "Smallest value: "<<smallestValue(array, size) << endl;
        cout << "Average value: " <<averageValue(array, size) << endl;
        cout << "Median value: "<<medianValue(array, size) << endl;

        delete[] array;
    }

    return 0;
}

