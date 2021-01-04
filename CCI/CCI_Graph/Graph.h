#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;                                                                      ///--------> Number of vertices
    list<int>  *adj;                                                            ///------Pointer to an array of adjacency list
    void DFSUtils(int s, bool visited[]);

public:
    Graph(int V);                                                               ///----> Constructor
    void addEdge(int v, int w);                                                 ///----> Function to add edge between vertices v and w
    void BFS(int s);                                                            ///----> Function to perform breadth first search from vertex s
    void DFS(int s);

};


#endif