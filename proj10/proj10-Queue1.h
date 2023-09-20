/*
 * file: proj10-Queue1.h
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

#ifndef PROJ10_QUEUE1_H_INCLUDED
#define PROJ10_QUEUE1_H_INCLUDED

#include "proj10-MyVector.h"

template <class T>
class Queue1 : public MyVector<T> {
public:
  void enqueue( T );
  void dequeue( T& ); // throws BADINDEX
};

template <class T>
void Queue1<T>::enqueue( T t){
    this->pushBack(t);
}

template <class T>
void Queue1<T>::dequeue( T& t){
    this->popFront(t);
}

#endif // PROJ10-QUEUE1_H_INCLUDED
