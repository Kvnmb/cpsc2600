// header file for Graph

#ifndef GRAPH_H
#define Graph_H

#include <iostream>

using namespace std;

class Graph {
    private:
        int **arr; // 2D dynamic array
        int size; // size of the array
        int *visited; // dynamic array to determine visited vertexes: 0 is unvisited, 1 is visited
    public:
        Graph(); // constructor
        ~Graph(); // destructor
        void load(char *filename); // loads file
        void display(); // displays adjacency matrix
        void displayDFS(int vertex); // depth first traversal
        void resetVisited(); // resets visited vertexes array
        void displayBFS(int vertex); // breadth first traversal
};

#endif