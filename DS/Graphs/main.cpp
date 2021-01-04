
#include <iostream>
#include <list>

using namespace std;
/*
Points to note
V number of vertex pointer to list and DFS util are private

DFS creates a bool array of visited, sets all to false and passes the vertex/node under consideration and visited array to DFSutil

DFS util takes in v and array of visited sets v to visited and iterates through its adj list and recursively calls itself

Graph constructor creates the array of lists




*/ 
class Graph{
    int V;          // Number of vertex in Graph

    list<int>* adj; // Pointer to list
    void DFSutil(int v, bool visited[]);


public:
    Graph(int V);                   // Constructor Creates a array of list

    void addEdge(int v, int w);     // Push backs the edge node to vertex adjacency list in the array of  list

    void DFS(int v);    

    void BFS(int v);
};



Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int v){

    bool *visited = new bool[V];
    
    for (int i =0; i<V; i++)
    {
        visited[i] = false;             //set all to false
    }

    DFSutil(v, visited);
}

void Graph::DFSutil(int v, bool visited[]){
    visited[v] = true;
    cout<<v<<"->";
    list<int>::iterator it;

    for(it = adj[v].begin(); it!=adj[v].end();++it){
        if(!visited[*it])
        {
            DFSutil(*it, visited);
        }
    }
    
}
 
void Graph::BFS(int v){
    bool* visited = new bool[V];

    for(int i=0; i< V;  i++){
        visited[i] = false;
    }

    list<int> queue;

    queue.push_back(v);

    list<int>::iterator it;
    int s;

    while(!queue.empty()){
        s= queue.front();
        visited[s] = true;
        cout<<s<<"->";
        queue.pop_front();

        for(it = adj[s].begin(); it!=adj[s].end();++it)    // Span through entire adjacency list of current node and push it in queue
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }



    }

}


int main(){

    Graph G(7);

    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(2,4);
    G.addEdge(2,5);
    G.addEdge(3,6);

    G.DFS(0);
    cout<<endl;
    G.BFS(0);
    
    return 0;
}





