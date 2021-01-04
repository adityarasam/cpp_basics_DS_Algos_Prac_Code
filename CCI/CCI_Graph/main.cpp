# include "Graph.h"


int main()
{
    cout << "Hello world!" << endl;
    Graph g(6);
    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);*/

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);


    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    cout<<endl;

    return 0;
}



