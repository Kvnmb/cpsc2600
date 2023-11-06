#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << endl << endl << argv[1] << ":" << endl; // outputs filename

    Graph graph;
    graph.load(argv[1]); // loads file into object

    graph.display(); // displays adjacency matrix

    cout << "\n\nDFS at vertex 0: " ;
    graph.displayDFS(0); // displays the depth-first traversal

    graph.resetVisited(); // resets the array of visited vertexes

    cout << "\n\nBFS at vertex 0: " ;
    graph.displayBFS(0); // displays the breadth-first traversal

    cout << endl << endl;

    return 0;
}