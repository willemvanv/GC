#ifndef EDGE_H
#define EDGE_H
#include <iostream>
#include <cstring>

using namespace std;
//Edge class
class edge {
 public:
  //Functions
  edge(int n, int v);
  ~edge();
  edge* getNext();
  void setNext(edge* edge);
  int getValue();
  int getNode();
 private:
  //Weight of edge
  int value;
  //Label of vertex connected to from initial vertex
  int node;
  //Connected edge
  edge* next;
};
#endif
