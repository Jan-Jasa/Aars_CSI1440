/**
 * file: proj2-arrayFunctions.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment: Project 2
 * due date: 1/30/2023
 *
 * date modified: 1/28/2023
 *  - most of code created
 *
 * date modified: 1/29/2023
 *  - changed "swap" function and added manual swap
 *  - fixed median
 **/


#include "proj2-arrayFunctions.h"
#include <iostream>
#include <cstring>
#include <iomanip>

void bubbleSort(int *array, int size){
    int junk;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(*(array+j) > *(array+j+1)){
                junk=*(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1)=junk;
            }
        }
    }
}
int largestValue(int *array, int size){
    int max;

    max = *array;
    for(int i=0; i<size; i++){
        if(max < *(array+i)){
            max = *(array+i);
        }
    }
    return max;

} // used for largest in single array


int smallestValue(int *array, int size){
    int min;

    min = *array;
    for(int i=0;i<size; i++){
        if(min > *(array+i)){
            min = *(array+i);
        }
    }
    return min;
} // used for smallest in single array


double averageValue(int *array, int size){
    double avg=0;

    for(int i=0; i<size; i++){
        avg+=*(array+i);
    }

    avg = avg/size;

    return avg;
}


int medianValue(int *array, int size){
    int median;

    bubbleSort(array, size);
    //determine if odd or even
    if(size%2==1){
        median=*(array+size/2);
    }
    else{
        median=*(array+size/2-1);
    }

    return median;

}//choose the smaller value if an evenly sized array
