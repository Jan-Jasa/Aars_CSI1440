/*
 * file: proj10-MyVector.h
 * author: Jan Jasa
 * course: CSI 1440
 * assignment: project 10
 * due date: 5/1/2023
 *
 *
 * date modified: 4/30/2023
 *      - completion
 *
 */

#ifndef PROJ10_MYVECTOR_H_INCLUDED
#define PROJ10_MYVECTOR_H_INCLUDED

#include "proj10-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
  MyVector ();
  ~MyVector ();
  MyVector (const MyVector&);
  MyVector<T>& operator = (const MyVector&);
  MyVector<T>& pushFront(T);
  MyVector<T>& pushBack(T);
  MyVector<T>& popFront(T&); // throws BADINDEX
  MyVector<T>& popBack(T&);  // throws BADINDEX
  T  front();        // throws BADINDEX
  T  back();        // throws BADINDEX
  T&  operator [](int);   // throws BADINDEX
  int getSize();
  bool isEmpty();
  void erase();

protected:
  T  *data;
  int size;
  int capacity;
  void grow();
  void shiftRight();
  void shiftLeft();
};

template <class T>
void MyVector<T>::grow(){
    this->capacity*=2;
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
    this->size=0;
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
    for(int i=0; i<this->size; i++){
        this->data[i] = that.data[i];
    }
}

template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& that){
    if(this != &that){
        delete [] this->data;
        this->size = that.size;
        this->capacity = that.capacity;
        this->data = new T[this->capacity];
        for(int i=0; i<this->size; i++){
            this->data[i] = that.data[i];
        }
    }

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
MyVector<T>& MyVector<T>::pushFront(T e){
    if(this->size == this->capacity){
        this->grow();
    }
    this->shiftRight();
    this->data[0] = e;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }

    e=this->data[0];
    this->shiftLeft();
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }
    this->size--;
    e=this->data[this->size];
    return *this;
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
T& MyVector<T>::operator [](int n){
    if(isEmpty() || n < 0 || n >= this->size){
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
    if(this->size == 0){
        return true;
    }
    return false;
}

template <class T>
void MyVector<T>::erase(){
    this->size = 0;
    this->capacity = 10;
    delete[] this->data;
    this->data = new T[this->capacity];
}



#endif // PROJ10-MYVECTOR_H_INCLUDED
