#ifndef PROJ10_CONTAINERIFC_H_INCLUDED
#define PROJ10_CONTAINERIFC_H_INCLUDED

class BADINDEX {};

template <class T>
class ContainerIfc {
public:
  virtual ContainerIfc <T>& pushFront(T) =0;
  virtual ContainerIfc <T>& pushBack(T)  =0;
  virtual ContainerIfc <T>& popFront(T&) =0; // throws BADINDEX
  virtual ContainerIfc <T>& popBack(T&)  =0; // throws BADINDEX
  virtual int getSize()                  =0;
  virtual bool isEmpty()                 =0;
  virtual T  front()                     =0; // throws BADINDEX
  virtual T  back()                      =0; // throws BADINDEX
  virtual T&  operator [](int)           =0; // throws BADINDEX
  virtual void erase()                   =0;
};

#endif // PROJ10-CONTAINERIFC_H_INCLUDED
