#ifndef PROJ10_NODE_H_INCLUDED
#define PROJ10_NODE_H_INCLUDED

template <class T>
class Node {
public:
  T data;
  Node <T>*next;

  Node( T d ) {
    data = d;
    next = NULL;
  }

  ~Node( ) {
    delete next;
  }
};

#endif // PROJ10-NODE_H_INCLUDED
