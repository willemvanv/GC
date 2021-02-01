#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cstring>
#include "edge.h"
#include "Node.h"

using namespace std;

//Graph class that makes graph using adjecency table
class graph {
 public:
  //Functions
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
  //Adjecency table
  Node* table[20];
};
#endif
