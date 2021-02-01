#include <iostream>
#include <cstring>
#include "edge.h"

using namespace std;
//Constructor
edge::edge(int n, int v) {
  node = n;
  value = v;
  next = NULL;
}
//Deconstructor
edge::~edge() {
  delete &node;
  delete &value;
  next = NULL;
}
//Get next edge in linked list
edge* edge::getNext() {
  return next;
}
//Connect another edge
void edge::setNext(edge* edge) {
  next = edge;
}
//Get the weight of an edge
int edge::getValue() {
  return value;
}
//Get the label of the node edge is pointed to
int edge::getNode() {
  return node;
}
