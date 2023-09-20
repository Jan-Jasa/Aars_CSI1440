/*
 * file: proj10-Queue3.h
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

#ifndef PROJ10_QUEUE3_H_INCLUDED
#define PROJ10_QUEUE3_H_INCLUDED

#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
public:
  void enqueue( T );
  void dequeue( T& ); // throws BADINDEX
};

template <class T>
void Queue3<T>::enqueue( T t){
    this->pushBack(t);
}

template <class T>
void Queue3<T>::dequeue( T& t){
    this->popFront(t);
}

#endif // PROJ10_QUEUE3_H_INCLUDED
