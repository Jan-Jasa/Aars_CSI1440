/**
 * file:  proj4-main.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment:  project 4
 * due date: 2/27/2023
 *
 */

#include <iostream>
#include <fstream>
#include "proj4-ItemInfo.hpp"

using namespace std;

void resizeList(ItemInfo *itemList, int capacity){
    //couldnt get pointer to capacity to work, was buggy.
    capacity+=2;
    ItemInfo *temp = itemList;
    itemList = new ItemInfo[capacity];
    for(int i=0; i<capacity; i++){
        itemList[i] = temp[i];
    }
    delete [] temp;
}

int main() {
    char buffer [500];
    int capacity = 2;
    int count, numItems = 0;
    int itemVariable = 0;
    ifstream inFS;
    ItemInfo *itemList = new ItemInfo[capacity];

    inFS.open("proj4-productServices.csv");

    while(inFS.get(buffer[count])){
        //check for resize if needed
        if(numItems == capacity){
            capacity += 2;
            ItemInfo *temp = itemList;
            itemList = new ItemInfo[capacity];
            for(int i = 0; i < numItems; ++i){
                itemList[i] = temp[i];
            }
            delete[] temp;
        }

        if(buffer[count] == '\n' || buffer[count] == ','){
            buffer[count] = '\0';
            if(itemVariable == 0){
                itemList[numItems].setItemId(buffer);
                itemVariable++;
                count = 0;
            }
            else if(itemVariable == 1){
                itemList[numItems].setDescription(buffer);
                itemVariable++;
                count = 0;
            }
            else if(itemVariable == 2){
                itemList[numItems].setManCost(buffer);
                itemVariable++;
                count = 0;
            }
            else if(itemVariable == 3){
                itemList[numItems].setSellPrice(buffer);
                itemVariable=0;
                count = 0;
                numItems++;
            }
        }
        else{
            count++;
        }
    }
    //bubble sort
    for(int i = 0; i < numItems - 1; i++){
        for(int j = 0; j < numItems - i - 1; j++){
            if(itemList[j].calcProfit() < itemList[j+1].calcProfit()){
                ItemInfo temp = itemList[j];
                itemList[j] = itemList[j+1];
                itemList[j+1] = temp;
            }
        }
    }

    char name[16] = "\"Jan Store\": [\n";
    char item1[13] = "\t\"firstItem\"";
    char item2[14] = "\t\"secondItem\"";
    char item3[13] = "\t\"thirdItem\"";
    char item4[14] = "\t\"fourthItem\"";
    char item5[13] = "\t\"fifthItem\"";
    printCString(cout, name);

    printCString(cout, item1);
    itemList[0].toAmazonJSON(cout);

    printCString(cout, item2);
    itemList[1].toAmazonJSON(cout);

    printCString(cout, item3);
    itemList[2].toAmazonJSON(cout);

    printCString(cout, item4);
    itemList[3].toAmazonJSON(cout);

    printCString(cout, item5);
    itemList[4].toAmazonJSON(cout);

    printCString(cout, "]");

    //dear god dont forget to delete/close
    delete[] itemList;
    inFS.close();

    return 0;
}
