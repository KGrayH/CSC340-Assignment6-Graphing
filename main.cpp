#include "Graph.h" // Use your actual path to the Graph class header file
#include "User.h"  // Use your actual path to the User class header file


int main() {

    // This is the main driver code for the banking graph application
    // It provides a menu-driven interface for users to interact with the graph
    // allowing them to load data, display the graph, and perform various graph algorithms such as BFS
    // DFS, Dijkstra's, Bellman-Ford, and topological sort.
    
    Graph g;

    // Create graph

    //10 user objects
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

    //assigning ID for each user for graph vertices
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

    //adding all users to graph
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

    //add follow edges
    //followerId follows followeeId, with a relationship weight
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

    //display finished adjacency list
    g.displayGraph();

    //Part-I - Create/Build and display graph g. The 'displayGraph' method should be called to complete this task
    //Part-II - Run DFS traversal on the graph
    //Part-III - Run Dijkstra's algorithm on the graph
    //Part-IV - Run Bellman-Ford algorithm on the graph
    //Part-V - Run Topological Sort on the graph

    return 0;
    
}