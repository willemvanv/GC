#ifndef EDGE_H
#define EDGE_H
#include <iostream>
#include <cstring>

using namespace std;

class edge {
 public:
  edge(int n, int v);
  ~edge();
  edge* getNext();
  void setNext(edge* edge);
  int getValue();
  int getNode();
 private:
  int value;
  int node;
  edge* next;
};
#endif
