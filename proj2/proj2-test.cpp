#include <iostream>
#include "proj2-arrayFunctions.h"
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    istringstream inSS;
    int size;

    inSS.clear();
    inSS.str("7\n5 36 27 65 26 50 72\n3\n75 3 10\n4\n25 1 99 30");



    while(inSS >> size){
        int *array = new int[size];

        //input n output values
        for(int i=0; i<size; i++){
            inSS >> *(array+i);
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

        cout << "Testing largestValue(): " << largestValue(array, size) << endl;
        cout << "Testing smallestValue: "<<smallestValue(array, size) << endl;
        cout << "Testing  averageValue(): " <<averageValue(array, size) << endl;
        cout << "Testing medianValue(): "<<medianValue(array, size) << endl;

        delete[] array;
    }

    return 0;
}
