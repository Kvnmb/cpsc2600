#include <iostream>
#include "Graph.h"
#include <fstream>
#include <queue>

using namespace std;

Graph::Graph(){ // constructor, sets pointers to null
    arr = nullptr;
    visited = nullptr;
}

Graph::~Graph(){ // destructor, frees memory
    for(int x = 0; x < size; x++){
        delete [] arr[x];
    }
    delete [] arr;
    
    delete [] visited;
}

void Graph::load(char *filename){
    ifstream file;
    file.open(filename);
    int temp;
    int x, y;

    if(file){
        file >> temp;
        size = temp; // stores size of the array into object

        arr = new int*[size];

        visited = new int[size];

        for(int x = 0; x < size; x++){
            arr[x] = new int[size];     // column memory allocation
        }


        while(file >> x && file >> y){ // array indexes flipped are the same edges
            arr[x][y] = 1;
            arr[y][x] = 1;
        }

        file.close();

    }else{
        cout << "\n\nFile failed to open.\n\n" ;
    }
}

void Graph::display(){ // prints out the 2D array contents
    cout << "\n\nAdjacency Matrix:\n" ;

    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
}

void Graph::displayDFS(int vertex){
    cout << vertex << " " ;
    visited[vertex] = 1; // outputs starting vertex as visited
    for(int x = 0; x < size; x++){
        if((arr[vertex][x] == 1) && (visited[x] == 0)){
            displayDFS(x); // jumps to the adjacent vertex that is not visited
        }
    }
    if(visited[vertex] == 0){ // in the case that all adjacent vertexes are visited
        visited[vertex] = 1;
    }
}

void Graph::resetVisited(){
    for(int x = 0; x < size; x++){
        visited[x] = 0; // sets all indexes to 0
    }
}

void Graph::displayBFS(int vertex){ // queue implementation
    queue<int> q;
    q.push(vertex); // pushes vertex onto the queue
    cout << vertex << " " ;
    visited[vertex] = 1; // marks as visited
    while(!q.empty()){
        int w = q.front();
        q.pop(); // pop the queue, check for adjacent vertexes to add to queue
        for(int x = 0; x < size; x++){
            if((arr[w][x] == 1) && (visited[x] == 0)){
                q.push(x);
                visited[x] = 1;
                cout << x << " " ;
            }
        }
    }
}