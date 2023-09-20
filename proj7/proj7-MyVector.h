/*
 * file: proj7-MyVector.h
 * author: Jan Jasa
 * course: CSI 1440
 * assignment: project 7
 * due date: 4/3/2023
 *
 * date modified: 4/1/2023
 *     -april fools
 *     -most of code written
 */

#ifndef PROJ7_MYVECTOR_H_INCLUDED
#define PROJ7_MYVECTOR_H_INCLUDED

#include "proj7-ContainerIfc.h"
#include <iostream>

using namespace std;

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    /*
     * default constructor
     *
     * MyVector constructor
     *
     * Parameters:
     *
     * Output:
     *      return:  none
     *      reference parameters: none
     *      stream:  none
     */
  MyVector ();
    /*
     * destructor
     *
     * deletes data
     *
     * Parameters:
     *
     * Output:
     *      return:  none
     *      reference parameters: none
     *      stream:  none
     */
  ~MyVector ();
    /*
     * copy constructor
     *
     * copys data from that to this
     *
     * Parameters:
     *      that: reference to target MyVector
     *
     * Output:
     *      return:  none
     *      reference parameters: none
     *      stream:  none
     */
  MyVector (const MyVector&);
    /*
     * operator =
     *
     * overloaded assignment operator
     *
     * Parameters:
     *      that: a reference to target MyVector
     * Output:
     *      return:  MyVector&
     *      reference parameters: that
     *      stream:  none
     */
  MyVector<T>& operator = (const MyVector&);
    /*
     * pushFront
     *
     * shifts all values to the right and puts a new value at index 0
     *
     * Parameters:
     *      e: a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: none
     *      stream:  none
     */
  MyVector<T>& pushFront(T);
    /*
     * pushBack
     *
     * shifts all values to the left and puts a new value at last index
     *
     * Parameters:
     *      e: a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: none
     *      stream:  none
     */
  MyVector<T>& pushBack(T);
    /*
     * popBack
     *
     * removes a data element from the front
     *
     * Parameters:
     *      e: a reference to a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: e
     *      stream:  none
     */
  MyVector<T>& popFront(T&);
    /*
     * popBack
     *
     * removes a data element from the end
     *
     * Parameters:
     *      e: a reference to a value of type T
     * Output:
     *      return:  MyVector&
     *      reference parameters: e
     *      stream:  none
     */
  MyVector<T>& popBack(T&);
    /*
     * front
     *
     * returns the value at the first index
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
  T  front();
    /*
     * back
     *
     * returns the value at the last index
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
  T  back();
    /*
     * operator[]
     *
     * returns the value at the index provided
     *
     * Parameters:
     *      n: int
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
  T&  operator [](int);
    /*
     * getSize
     *
     * returns the size of the array
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream:  none
     */
  int getSize();
    /*
     * isEmpty
     *
     * returns if the array is empty or not
     *
     * Parameters: none
     *
     * Output:
     *      return: bool
     *      reference parameters: none
     *      stream:  none
     */
  bool isEmpty();
    /*
     * erase
     *
     * erases the array
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
  void erase();

private:
  T  *data;
  int size;
  int capacity;
  /*
     * grow
     *
     * increases the capacity of the array by double
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
  void grow();
    /*
     * shiftRight
     *
     * shifts all values of the array to the right
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
  void shiftRight();
    /*
     * shiftLeft
     *
     * shifts all values of the array to the left
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream:  none
     */
  void shiftLeft();
};

template <class T>
void MyVector<T>::grow(){
    this->capacity *= 2;
    T *temp = this->data;
    this->data = new T[this->capacity];

    for(int i=0; i<this->size; i++){
        this->data[i] = temp[i];
    }

    delete [] temp;
}

template <class T>
void MyVector<T>::shiftRight(){
    for(int i=this->size; i>0; i--){
        this->data[i] = this->data[i-1];
    }
    this->size++;
}

template <class T>
void MyVector<T>::shiftLeft(){
    for(int i=0; i<this->size; i++){
        this->data[i] = this->data[i+1];
    }
    this->size--;
}

template <class T>
MyVector<T>::MyVector(){
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
}

template <class T>
MyVector<T>::~MyVector(){
    delete [] this->data;
}

template <class T>
MyVector<T>::MyVector(const MyVector& that){
    this->size = that.size;
    this->capacity = that.capacity;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; i++){
        this->data[i] = that.data[i];
    }
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& that){
    if(this != &that){
        delete [] this->data;
        this->size = that.size;
        this->capacity = that.capacity;
        this->data = new T[this->capacity];

        for(int i=0; i<that.size; i++){
            this->data[i] = that.data[i];
        }
    }

    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T e){
    if(this->size == this->capacity){
        this->grow();
    }

    this->shiftRight();
    this->data[0] = e;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T e){
    if(this->size == this->capacity){
        this->grow();
    }
    this->data[this->size] = e;
    this->size++;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }
    else{
        e = this->data[0];
        this->shiftLeft();
        return *this;
    }
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }
    else{
        e=this->data[this->size-1];
        --this->size;
        return *this;
    }
}

template <class T>
T MyVector<T>::front(){
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->data[0];
}

template <class T>
T MyVector<T>::back(){
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->data[this->size-1];

}

template <class T>
T&  MyVector<T>::operator [](int n){
    if(isEmpty() || n>=this->size || n<0){
        throw BADINDEX();
    }
    return this->data[n];
}

template <class T>
int MyVector<T>::getSize(){
    return this->size;
}

template <class T>
bool MyVector<T>::isEmpty(){
    if(this->size==0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void MyVector<T>::erase(){
    this->size=0;
    this->capacity=10;
    delete [] this->data;
    this->data = new T[this->capacity];
}


#endif // PROJ7-MYVECTOR_H_INCLUDED
