#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "edge.h"

using namespace std;

class Node {
 public:
  Node(int v);
  ~Node();
  int getValue();
  edge* getNext();
  void setNext(edge* e);
 private:
  int value;
  edge* next;
};
#endif
