/*
 * file: proj7-testmain.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment: project 7
 * due date: 4/3/2023
 *
 * date modified: 4/1/2023
 *     -april fools
 *     -most of code written
 */

#include <iostream>
#include "proj7-MyVector.h"
#include <stdexcept>

using namespace std;

int main()
{
    int n;
    MyVector<int> testVector;

    //pushfront testing + grow()
    cout << "Testing push front..." << endl;
    for(int i=0; i<5; i++){
        cout << i << " ";
        testVector.pushFront(i);
    }
    cout << endl;

    for(int i = 0; i < testVector.getSize(); i++){
        cout << testVector[i] << " ";
    }
    cout << endl << endl;


    //pushback testing
    cout << "Testing push back..." << endl;
    for(int i=0; i<5; i++){
        cout << i << " ";
        testVector.pushBack(i);
    }
    cout << endl;

    for(int i = 0; i < testVector.getSize(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl << endl;


    //popfront testing
    cout << "Testing pop front..." << endl;
    for(int i = 0; i < 5; ++i){
        testVector.popFront(n);
        cout << n << " ";
    }
    cout << endl;

    for(int i = 0; i < testVector.getSize(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl << endl;

    //popback testing
    cout << "Testing pop back..." << endl;
    for(int i = 0; i < 5; ++i){
        testVector.popBack(n);
        cout << n << " ";
    }
    cout << endl;

    for(int i = 0; i < testVector.getSize(); ++i){
        cout << testVector[i] << " ";
    }
    cout << endl << endl;

    //getSize proven, do isEmpty
    cout << "Testing isEmpty..." << endl;
    if(testVector.isEmpty()){
        cout << "testVector is empty (Should show)" << endl;
    }


    try{
        testVector.popFront(n);
    } catch(BADINDEX){
        cout << "popFront doesn't work, isEmpty()." << endl << endl;
    }

    try{
        testVector.popBack(n);
    } catch(BADINDEX){
        cout << "popBack doesn't work, isEmpty()." << endl << endl;
    }

    for(int i = 0; i < 10; ++i){
        testVector.pushBack(i);
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "Testing front..." << endl;
    cout << testVector.front() << endl << endl;

    cout << "Testing back..." << endl;
    cout << testVector.back() << endl << endl;


    cout << "Testing copy constructor..." << endl;
    MyVector<int> MyVector2(testVector);

    cout << "testVector: " << endl;
    for(int i=0; i<testVector.getSize(); i++){
        cout << testVector[i] << " ";
    }
    cout << endl << endl;

    cout << "MyVector2: " << endl;
    for(int i=0; i<MyVector2.getSize(); i++){
        cout << MyVector2[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing overloaded assignment operator..." << endl;
    MyVector<int> MyVector3;
    MyVector3 = testVector;
    cout << "MyVector3: " << endl;
    for(int i = 0; i < MyVector3.getSize(); ++i){
        cout << MyVector3[i] << " ";
    }
    cout << endl << endl;


    //different template
    cout << "Testing using char template..." << endl << endl;

    MyVector<char> charVector;
    char c;
    char letter = 'a';

    cout << "Testing push front..." << endl;
    for(int i = 0; i < 5; i++, letter++){
        cout << letter << " ";
        charVector.pushFront(letter);
    }
    cout << endl;

    for(int i = 0; i < charVector.getSize(); i++){
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    letter = 'a';
    cout << "Testing push back..." << endl;
    for(int i = 0; i < 5; i++, letter++){
        cout << letter << " ";
        charVector.pushBack(letter);
    }
    cout << endl;

    for(int i = 0; i < charVector.getSize(); i++){
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing pop front..." << endl;
    for(int i = 0; i < 5; ++i){
        charVector.popFront(c);
        cout << c << " ";
    }
    cout << endl;

    for(int i = 0; i < charVector.getSize(); i++){
        cout << charVector[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing pop back..." << endl;
    for(int i = 0; i < 5; i++){
        charVector.popBack(c);
        cout << c << " ";
    }
    cout << endl << endl;

    cout << "Testing isEmpty()..." << endl;
    if(charVector.isEmpty()){
        cout << "charVector is empty (Should show)" << endl;
    }
    cout << endl;

    try{
        charVector.popBack(c);
    } catch(BADINDEX){
        cout << "popBack doesn't work, isEmpty()." << endl;
    }

    try{
        charVector.popFront(c);
    } catch(BADINDEX){
        cout << "popFront doesn't work, isEmpty()." << endl << endl;
    }

    letter = 'a';
    for(int i = 0; i < 10; ++i, ++letter){
        charVector.pushBack(letter);
        cout << letter << " ";
    }
    cout << endl << endl;

    cout << "Testing front..." << endl;
    cout << charVector.front() << endl << endl;

    cout << "Testing back..." << endl;
    cout << charVector.back() << endl << endl;

    cout << "Testing copy constructor..." << endl;
    MyVector<char> charVector2(charVector);

    cout << "charVector: " << endl;
    for(int i = 0; i < charVector.getSize(); i++){
        cout << charVector[i] << " ";
    }
    cout << endl;
    cout << "charVector2: " << endl;
    for(int i = 0; i < charVector2.getSize(); i++){
        cout << charVector2[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing overloaded assignment operator..." << endl;
    MyVector<char> charVector3;
    charVector3 = charVector;
    cout << "charVector3: " << endl;
    for(int i = 0; i < charVector3.getSize(); i++){
        cout << charVector3[i] << " ";
    }
    cout << endl << endl;

    try{
        cout << charVector[50] << endl;
    }catch(BADINDEX){
        cout << "Should see this message." << endl << endl;
    }

    cout << "testing erase..." << endl;
    charVector.erase();
    if(charVector.isEmpty()){
        cout << "charVector has been erased." << endl;
    }


    return 0;
}
