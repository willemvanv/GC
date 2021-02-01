//Willem van Veldhuisen
//2/1/2021
//Program to create graphs and find shortest paths within them

//Includes
#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

//Main
int main() {
  graph Graph;
  cout << "commands: quit, add edge, add vertex, print table, remove edge, remove vertex, find shortest"
       << endl;
  //Main loop for
  while(1) {
    //Getting input
    char* input = new char[15];
    cin.getline(input, 15);
    if (strcmp(input, "add edge") == 0) {
      Graph.addEdge();
    }
    else if (strcmp(input, "add vertex") == 0) {
      Graph.addVertex();
    }
    else if (strcmp(input, "print table") == 0) {
      Graph.printTable();
    }
    else if (strcmp(input, "remove edge") == 0) {
      Graph.removeEdge();
    }
    else if (strcmp(input, "remove vertex") == 0) {
      Graph.removeVertex();
    }
    else if (strcmp(input, "test") == 0) {
      Graph.test();
    }
    else if (strcmp(input, "find shortest") == 0) {
      Graph.findShortest();
    }
    else if (strcmp(input, "t") == 0) {
      Graph.t();
    }
    else if (strcmp(input, "quit") == 0) {
      break;
    }
  }
  return 0;
}
