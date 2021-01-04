
# include "Graph.h"







///---------------> CREATIN AN ARRAY OF LIST - LIST FOR EACH NODE --------------
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int> [V];                                                    ///----> Pointing the pointer to a list with V elements in dynamic memory
}             ///---- ARRAY OF LIST---///                                       ///----> list<int> [V]  this is an array of list with V array indices, eah index location has a list




///----------------> Adding adjacent node w to adjacency list of node v --------
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    ///----> THIS LINE MAKES THE GRAPH BIDIRECTIONAL <-----                     ///-----VERY IMPORTANT---------
    //adj[w].push_back(v);
}



///----> BREADTH FRIST SEARCH --------------------------------------------------
void Graph::BFS(int s)
{
    bool *visited = new bool[V];                                                ///---->STORES VISITED INFORMATION
                    ///----> POINTER TO ARRAY OF BOOL
    for(int i=0; i<V; i++)
        visited[i] = false;



    list<int> temp_que;                                                         ///----> TO STORE THE NEIGHBORS


    ///----> START WITH THE CURRENT NODE ------------
    visited[s] = true;
    temp_que.push_back(s);


    list<int>::iterator iter;

    while(!temp_que.empty())            ///SCANS THE v NODES OF ARRAY
    {
        s=temp_que.front();                                                     ///----> READ NODE IN FRONT
        cout<<s<<" ";                                                           ///----> PRINT NODE IN FRONT
        temp_que.pop_front();                                                   ///----> DELETE NODE IN FRONT
                                    /// SCANS THE NEIGBORS w IN V NODES LIST
        for(iter = adj[s].begin(); iter != adj[s].end(); ++iter)                ///----> ITERATING LIST AT sTH NODE
        {
            if(!visited[*iter])                                                 ///----> iter POINTS TO ADDRESS OF NODE IN adj LIST OS USE *iter
            {                                                                   ///----> CONCEPT OF ARRAY OF ARRAY iter = adj[s], adj[s] is pointer to first element in list
                                                                                ///----> and hence is iter, u need to deref it *iter
                visited[*iter] = true;
                temp_que.push_back(*iter);
            }
        }
    }

}


void Graph::DFS(int s)
{
    bool * visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }

    DFSUtils(s, visited);
}

void Graph::DFSUtils(int s, bool visited[])                                          ///----->  GO DEEP
{
    visited[s] = true;                                                          ///-----> SET VISITED TRUE
    cout<<s<<" ";

    list<int>::iterator iter;

    for(iter = adj[s].begin(); iter!=adj[s].end(); ++iter)                      ///-----> FIND EACH NEIGHBOR
    {
        if(!visited[*iter])                                                     ///-----> IF NOT VISITED
            DFSUtils(*iter, visited);                                           ///-----> GO MORE DEEP AND REPEAT
    }

}