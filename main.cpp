#include "Graph.h"
#include "User.h"
#include <iostream>

using namespace std;

int main() {

    Graph g;

    // Create graph
    // 10 user objects
    User u1("WindTell", "Windtell@gmail.com", "pass1", "Windtell bio", "Windtell.jpg");
    User u2("Hensley", "Hensley@gmail.com", "pass2", "Hensley bio", "Hensley.jpg");
    User u3("Enrique", "Enrique@gmail.com", "pass3", "Enrique bio", "Enrique.jpg");
    User u4("Kana", "Kana@gmail.com", "pass4", "Kana bio", "Kana.jpg");
    User u5("Darnell", "Darnell@gmail.com", "pass5", "Darnell bio", "Darnell.jpg");
    User u6("Maddy", "Maddy@gmail.com", "pass6", "Maddy bio", "Maddy.jpg");
    User u7("Gina", "Gina@gmail.com", "pass7", "Gina bio", "Gina.jpg");
    User u8("Axel", "Axel@gmail.com", "pass8", "Axel bio", "Axel.jpg");
    User u9("Jose", "Jose@gmail.com", "pass9", "Jose bio", "Jose.jpg");
    User u10("Deanna", "Deanna@gmail.com", "pass10", "Deanna bio", "Deanna.jpg");

    // Assign IDs for graph vertices
    u1.setId(1);
    u2.setId(2);
    u3.setId(3);
    u4.setId(4);
    u5.setId(5);
    u6.setId(6);
    u7.setId(7);
    u8.setId(8);
    u9.setId(9);
    u10.setId(10);

    // Add users to graph
    g.addUser(u1);
    g.addUser(u2);
    g.addUser(u3);
    g.addUser(u4);
    g.addUser(u5);
    g.addUser(u6);
    g.addUser(u7);
    g.addUser(u8);
    g.addUser(u9);
    g.addUser(u10);

    // Add follow edges
    // followerId follows followeeId, with relationship weight
    g.addFollowEdge(1, 3, 2);
    g.addFollowEdge(1, 5, 4);
    g.addFollowEdge(2, 1, 3);
    g.addFollowEdge(2, 4, 2);
    g.addFollowEdge(3, 6, 1);
    g.addFollowEdge(3, 7, 5);
    g.addFollowEdge(4, 8, 2);
    g.addFollowEdge(5, 6, 3);
    g.addFollowEdge(5, 9, 4);
    g.addFollowEdge(6, 10, 2);
    g.addFollowEdge(7, 4, 1);
    g.addFollowEdge(8, 9, 2);
    g.addFollowEdge(9, 10, 1);

    // Part-I - Create/Build and display graph
    cout << "Graph adjacency list" << endl;
    g.displayGraph();

    cout << endl;

    // Part-II - Run BFS traversal on the graph
    cout << "BFS traversal" << endl;
    g.bfsSearch(1);

    cout << endl;

    // Part-II - Run DFS traversal on the graph
    cout << "DFS traversal" << endl;
    g.dfsSearch(1);

    cout << endl;

    // Part-III - Run Dijkstra's algorithm on the graph
    cout << "Dijkstra'sshortest paths" << endl;
    g.dijkstra(1);

    cout << endl;

    // Part-IV - Run Bellman-Ford algorithm on the graph
    cout << "Bellman-Ford shortest paths" << endl;
    g.bellmanFord(1);

    cout << endl;

    // Part-V - Run Topological Sort on the graph
    cout << "Topological Sort" << endl;

    // Separate DAG graph for topological sort
    Graph dag;

    User d1("Intro", "intro@email.com", "pass1", "DAG node 1", "intro.jpg");
    User d2("Design", "design@email.com", "pass2", "DAG node 2", "design.jpg");
    User d3("Code", "code@email.com", "pass3", "DAG node 3", "code.jpg");
    User d4("Test", "test@email.com", "pass4", "DAG node 4", "test.jpg");
    User d5("Submit", "submit@email.com", "pass5", "DAG node 5", "submit.jpg");

    d1.setId(1);
    d2.setId(2);
    d3.setId(3);
    d4.setId(4);
    d5.setId(5);

    dag.addUser(d1);
    dag.addUser(d2);
    dag.addUser(d3);
    dag.addUser(d4);
    dag.addUser(d5);

    //DAG edges: no cycles
    dag.addFollowEdge(1, 2, 1);
    dag.addFollowEdge(1, 3, 1);
    dag.addFollowEdge(2, 4, 1);
    dag.addFollowEdge(3, 4, 1);
    dag.addFollowEdge(4, 5, 1);

    dag.displayGraph();
    dag.topologicalSort(1);
    return 0;
}
