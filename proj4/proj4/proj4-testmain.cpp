/**
 * file:  proj4-testmain.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment:  project 4
 * due date: 2/27/2023
 *
 */
/*
#include <iostream>
#include "proj4-ItemInfo.hpp"

using namespace std;

int main() {

    //test negative
    char *junk = "-1.11";
    double junk2;
    junk2 = stuCstrToDbl(junk);
    cout << junk2 << endl;
    cout << junk2 * 2 << endl << endl;

    //test positive
    junk = "123";
    junk2 = stuCstrToDbl(junk);
    cout << junk2 << endl;
    cout << junk2 * 2 << endl << endl;

    //ints cut off decimal
    double a = 124.43;
    int b = a;
    cout << "b: " << b << endl;

    double c = a-(int(a));
    cout << c;

    //testing stuDblToCstr
    char junk3[10];
    double dub = 10.10;
    stuDblToCstr(junk3, dub);
    cout << junk3 << endl;

    //test sets and gets
    ItemInfo TestProduct;
    TestProduct.setItemId("67983");
    TestProduct.setDescription("Gameboy");
    TestProduct.setManCost("14.99");
    TestProduct.setSellPrice("107.89");
    cout << "itemId: " << TestProduct.getItemId() << endl;
    cout << "description: " << TestProduct.getDescription() << endl;
    cout << "ManCost: " << TestProduct.getManCost() << endl;
    cout << "SellPrice: " << TestProduct.getSellPrice() << endl;
    cout << "calculatedProfit: " << TestProduct.calcProfit() << endl << endl;

    TestProduct.toAmazonJSON(cout);
    cout << endl;

    TestProduct.displayItemInfo(cout);
    cout << endl;

    cout << "Calculating profit: " << TestProduct.calcProfit() << endl;

    char dest[4] = "yes";
    char src[4] = "nop";
    stuCstrCpy(dest, src);
    cout << dest << endl;

}*/

