#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "edge.h"

using namespace std;
//Node/Vertex class
class Node {
 public:
  //Functions
  Node(int v);
  ~Node();
  int getValue();
  edge* getNext();
  void setNext(edge* e);
 private:
  //Label for vertex
  int value;
  //Connected edge
  edge* next;
};
#endif
