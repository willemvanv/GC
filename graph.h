#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cstring>
#include "edge.h"
#include "Node.h"

using namespace std;

class graph {
 public:
  graph();
  ~graph();
  void addVertex();
  void addEdge();
  void removeVertex();
  void removeEdge();
  void printTable();
  void test();
  void findShortest();
  int getMinDist(bool* SPTset, int* dist, int len);
  bool isEdge(Node* a, Node* b);
  int getEdgeWeight(Node* a, Node* b);
  void t();
 private:
  Node* table[20];
};
#endif
