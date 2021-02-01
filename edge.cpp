#include <iostream>
#include <cstring>
#include "edge.h"

using namespace std;

edge::edge(int n, int v) {
  node = n;
  value = v;
  next = NULL;
}
edge::~edge() {
  delete &node;
  delete &value;
  next = NULL;
}
edge* edge::getNext() {
  return next;
}
void edge::setNext(edge* edge) {
  next = edge;
}
int edge::getValue() {
  return value;
}
int edge::getNode() {
  return node;
}
