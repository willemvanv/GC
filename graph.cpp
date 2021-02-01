//Includes
#include <iostream>
#include "graph.h"
#include "edge.h"
#include "Node.h"
#include <climits>

using namespace std;
//Constructor
graph::graph() {
  for (int i = 0; i < 20; i++) {
    table[i] = NULL;
  }
}
//Deconstructor
graph::~graph() {

}
//Function to add vertex
void graph::addVertex() {
  cout << "enter int label" << endl;
  int label;
  cin >> label;
  for (int i = 0; i < 20; i++) {
    if (table[i] == NULL) {
      table[i] = new Node(label);
      break;
    }
    else if (i == 19) {
      cout << "no more room" << endl;
    }
  }
}
//Function to add edge
void graph::addEdge() {
  int firstNode;
  int secondNode;
  int weight;
  Node* first = NULL;
  Node* second = NULL;
  cout << "enter first vertex's label" << endl;
  cin >> firstNode;
  cout << "enter second vertex's label" << endl;
  cin >> secondNode;
  cout << "enter edge weight" << endl;
  cin >> weight;
  for (int i = 0; i < 20; i++) {
    if (table[i] != NULL && table[i]->getValue() == firstNode)
      first = table[i];
    else if (table[i] != NULL && table[i]->getValue() == secondNode)
      second = table[i];
  }
  if (first == NULL || second == NULL) {
    cout << "one or both vertecies don't exist" << endl;
  }
  else {
    if (first->getNext() == NULL) {
      first->setNext(new edge(second->getValue(), weight));
    }
    else {
      edge* current = first->getNext();
      while (current->getNext() != NULL) {
	current = current->getNext();
      }
      current->setNext(new edge(second->getValue(), weight));
    }
  }
}
//Function to remove vertex
void graph::removeVertex() {
  cout << "enter vertex label" << endl;
  int a;
  cin >> a;
  Node* temp = NULL;
  bool del = false;
  for (int i = 0; i < 20; i++) {
    if (table[i] != NULL && table[i]->getValue() == a) {
      temp = table[i];
      table[i] = NULL;
      temp->~Node();
      del = true;
    }
  }
  if (del == false) {
    cout << "vertex does not exist" << endl;
  }
  else {
    edge* temp = NULL;
    for (int i = 0; i < 20; i++) {
      if (table[i] != NULL && table[i]->getNext() != NULL) {
	if (table[i]->getNext()->getNode() == a) {
	  if (table[i]->getNext()->getNext() != NULL) {
	    temp = table[i]->getNext()->getNext();
	    table[i]->getNext()->~edge();
	    table[i]->setNext(temp);
	  }
	  else {
	    table[i]->getNext()->~edge();
	    table[i]->setNext(NULL);
	  }
	}
	else {
	  edge* current = table[i]->getNext();
	  while (current->getNext() != NULL) {
	    if (current->getNext()->getNode() == a) {
	      if (table[i]->getNext()->getNext() != NULL) {
		temp = table[i]->getNext()->getNext();
		current->getNext()->~edge();
		current->setNext(temp);
	      }
	      else {
		current->getNext()->~edge();
		current->setNext(NULL);
	      }
	    }
	  }
	}
      }
    }
  }
}
//Function to remove edge
void graph::removeEdge() {
  int firstNode;
  int secondNode;
  Node* first = NULL;
  Node* second = NULL;
  edge* temp = NULL;
  bool exists = false;
  cout << "enter first vertex's label" << endl;
  cin >> firstNode;
  cout << "enter second vertex's label" << endl;
  cin >> secondNode;
  for (int i = 0; i < 20; i++) {
    if (table[i] != NULL && table[i]->getValue() == firstNode)
      first = table[i];
    else if (table[i] != NULL && table[i]->getValue() == secondNode)
      second = table[i];
  }
  if (first == NULL || second == NULL) {
    cout << "one or both vertecies don't exist" << endl;
  }
  else {
    int a = second->getValue();
    if (first->getNext() != NULL) {
      if (first->getNext()->getNode() == a) {
	if (first->getNext()->getNext() != NULL) {
	  temp = first->getNext()->getNext();
	  first->getNext()->~edge();
	  first->setNext(temp);
	}
	else {
	  first->getNext()->~edge();
	  first->setNext(NULL);
	}
	exists = true;
      }
      else {
	edge* current = first->getNext();
	while (current->getNext() != NULL) {
	  if (current->getNext()->getNode() == a) {
	    if (current->getNext()->getNext() != NULL) {
	      temp = current->getNext()->getNext();
	      current->getNext()->~edge();
	      current->setNext(temp);
	    }
	    else {
	      current->getNext()->~edge();
	      current->setNext(NULL);
	    }
	    exists = true;
	    break;
	  }
	}
      }
    }
  }
  if (exists == false) {
    cout << "edge does not exist" << endl;
  }
}
//Function to print adjacency table
void graph::printTable() {
  for (int i = 0; i < 20; i++) {
    if (table[i] != NULL) {
      cout << table[i]->getValue();
      edge* current = table[i]->getNext();
      while (current != NULL) {
	cout << " -> " << current->getValue() << " " << current->getNode();
	current = current->getNext();
      }
    }
    cout << endl;
  }
}
//Testing functions (feel free to ignore)
void graph::t() {
  table[0] = new Node(1);
  table[1] = new Node(2);
  table[0]->setNext(new edge(2, 1));
}
void graph::test() {
  table[0] = new Node(0);
  table[1] = new Node(1);
  table[2] = new Node(2);
  table[3] = new Node(3);
  table[4] = new Node(4);
  table[5] = new Node(5);
  table[0]->setNext(new edge(1, 1));
  table[0]->getNext()->setNext(new edge(4, 1));
  table[0]->getNext()->getNext()->setNext(new edge(5, 3));
  table[2]->setNext(new edge(0, 8));
  table[3]->setNext(new edge(2, 2));
  table[3]->getNext()->setNext(new edge(4, 3));
  table[4]->setNext(new edge(1, 4));
  table[5]->setNext(new edge(4, 5));
  table[5]->getNext()->setNext(new edge(2, 6));
  table[1]->setNext(new edge(3, 7));
}
//Function to find shortest path
void graph::findShortest() {
  int firstNode;
  int secondNode;
  Node* first = NULL;
  Node* second = NULL;
  edge* temp = NULL;
  bool exists = false;
  cout << "enter first vertex's label" << endl;
  cin >> firstNode;
  cout << "enter second vertex's label" << endl;
  cin >> secondNode;
  for (int i = 0; i < 20; i++) {
    if (table[i] != NULL && table[i]->getValue() == firstNode)
      first = table[i];
    else if (table[i] != NULL && table[i]->getValue() == secondNode)
      second = table[i];
  }
  if (first == NULL || second == NULL) {
    cout << "one or both vertecies don't exist" << endl;
  }
  // Dijkstra's algorithm
  else {
    int len = 0;
    for (int i = 0; i < 20; i++) {
      if (table[i] != NULL) {
	len++;
      }
    }
    Node* set[len];
    int b = 0;
    for (int i = 0; i < 20; i++) {
      if (table[i] != NULL) {
	set[b] = table[i];
	b++;
      }
    }
    int src = 0;
    int tgt = 0;
    for (int i = 0; i < len; i++) {
      if (set[i] == first) {
	src = i;
      }
      else if (set[i] == second) {
	tgt = i;
      }
    }
    bool SPTset[len];
    int dist[len];
    int prev[len];
    for (int i = 0; i < len; i++) {
      dist[i] = INT_MAX;
      prev[i] = INT_MAX;
      SPTset[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < len - 1; i++) {
      int u = getMinDist(SPTset, dist, len);
      SPTset[u] = true;
      for (int v = 0; v < len; v++) {
	if ((SPTset[v] == false) && (isEdge(set[u], set[v]) == true) && (dist[u] != INT_MAX) &&
	    (getEdgeWeight(set[u], set[v]) + dist[u] < dist[v])) {
	  dist[v] = getEdgeWeight(set[u], set[v]) + dist[u];
	  prev[v] = u;
	}
      }
    }
    if (prev[tgt] != INT_MAX) {
      Node* s[20];
      int u = tgt;
      for (int i = 0; i < 20; i++) {
	s[i] = NULL;
      }
      int j = 0;
      while (prev[u] != INT_MAX) {
	s[j] = set[u];
	u = prev[u];
	j++;
      }
      s[j] = set[src];
      cout << "quickest path:  " << endl;
      for (int l = j; l >= 0; l--) {
        cout << s[l]->getValue();
	if (l != 0) {
	  cout << " -> ";
	}
      }
      cout << "  total: " << dist[tgt] << endl;
    }
    else
      cout << "no connection found" << endl;
  }
}
//Utility Functions below
//Function to find vertex with lowest distance from a source
int graph::getMinDist(bool* SPTset, int* dist, int len) {
  int min = INT_MAX;
  int minIndex;
  for (int i = 0; i < len; i++) {
    if (SPTset[i] == false && dist[i] <= min) {
      min = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}
//Function to tell if an edge exists between two points
bool graph::isEdge(Node* a, Node* b) {
  int g = b->getValue();
  if (a->getNext() != NULL) {
    if (a->getNext()->getNode() == g) {
      return true;
    }
    else {
      edge* current = a->getNext();
      while (current->getNext() != NULL) {
	if (current->getNext()->getNode() == g) {
	  return true;
	}
	current = current->getNext();
      }
    }
  }
  return false;
}
//Function to get the weight of an edge between two points
int graph::getEdgeWeight(Node* a, Node* b) {
  int g = b->getValue();
  if (a->getNext() != NULL) {
    if (a->getNext()->getNode() == g) {
      return a->getNext()->getValue();
    }
    else {
      edge* current = a->getNext();
      while (current->getNext() != NULL) {
	if (current->getNext()->getNode() == g) {
	  return current->getNext()->getValue();
	}
	current = current->getNext();
      }
    }
  }
  return 0;
}
