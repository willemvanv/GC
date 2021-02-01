#include <iostream>
#include <cstring>
#include "Node.h"
#include "edge.h"

using namespace std;
//Constructor
Node::Node(int v) {
  value = v;
  next = NULL;
}
//Deconstructor
Node::~Node() {
  delete &value;
}
//Get the value
int Node::getValue() {
  return value;
}
edge* Node::getNext() {
  return next;
}
void Node::setNext(edge* e) {
  next = e;
}
