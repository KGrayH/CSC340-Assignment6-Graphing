#include "Graph.h" // Use your actual path to the Graph class header file
#include "User.h"  // Use your actual path to the User class header file


int main() {

    // This is the main driver code for the banking graph application
    // It provides a menu-driven interface for users to interact with the graph
    // allowing them to load data, display the graph, and perform various graph algorithms such as BFS
    // DFS, Dijkstra's, Bellman-Ford, and topological sort.
    
    Graph g;

    User u1(1, "Alice");
    User u2(2, "Bob");
    User u3(3, "Charlie");
    User u4(4, "Diana");
    User u5(5, "Ethan");

    g.addUser(u1);
    g.addUser(u2);
    g.addUser(u3);
    g.addUser(u4);
    g.addUser(u5);

    // Follow relationships

    g.addFollowEdge(1, 2, 4);
    g.addFollowEdge(1, 3, 2);
    g.addFollowEdge(2, 4, 3);
    g.addFollowEdge(3, 4, 1);
    g.addFollowEdge(4, 5, 5);

    // Create graph

    //Part-I - Create/Build and display graph g. The 'displayGraph' method should be called to complete this task
    cout << "GRAPH ADJACENCY LIST" << endl;

    g.displayGraph();

    cout << endl;
    //Part-II - Run DFS traversal on the graph
    cout << "BFS TRAVERSAL" << endl;
    g.bfsSearch(1);

    cout << endl;
    cout << "DFS TRAVERSAL" << endl;
    g.dfsSearch(1);
    cout << endl;

    //Part-III - Run Dijkstra's algorithm on the graph
    cout << "===== DIJKSTRA SHORTEST PATHS =====" << endl;
    g.dijkstra(1);
    cout << endl;
    //Part-IV - Run Bellman-Ford algorithm on the graph
    //Part-V - Run Topological Sort on the graph

    return 0;
    
}
