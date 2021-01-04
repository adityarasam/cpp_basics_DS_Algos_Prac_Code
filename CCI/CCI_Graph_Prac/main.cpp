#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    // adjacency list
    list<int> *adj;             //same as array

public:
    Graph(int V)
    {
        V=V;
        // Array of type list of int
        adj = new list<int> [V];    //Pointer adj pointing to the first location of list in dynamic \
            memory
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int s)
    {
        bool *visited = new bool[V];  //Like int* a =  & b
        list<int>  queue;
        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
        }


        // For first node
        visited[s] = true;
        queue.emplace_back(s);

        list<int>::iterator iter;

        while(!queue.empty())
        {
            s=queue.front();
            cout<<s<<" ";
            queue.pop_front();

            for (iter = adj[s].begin(); iter != adj[s].end(); iter++)
            {
                if(!visited[*iter])
                {
                    visited[*iter] = true;
                    queue.emplace_back(*iter);
                }
            }
        }
    }

    DFS_Utils(int s, bool visited[])
    {
        visited[s] =true;

        list<int>:: iterator iter;

        for(iter = adj[s].begin(); iter = adj[s].end();  iter++)
        {
            if(!visited[*iter])
            {
                DFS_Utils(*iter, visited);
            }
        }

    }

    void DFS (int s)
    {
        bool *visited = new bool[V];  //Like int* a =  & b
        list<int>  queue;
        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        DFS_Utils(s, visited);

    }
};

int main()
{

    cout << "Hello world!" << endl;

    return 0;
}
