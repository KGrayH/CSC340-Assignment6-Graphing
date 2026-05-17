#include "Graph.h"


using namespace std;

// this method will add a user
void Graph::addUser(const User& user) {
    users[user.getId()] = user;
}

// Adding an edge, with the 2 vertices of UserIds and the weight of the edge,
// representing the strength of the 'follow' relationship between the users
// A smaller weight indicates a stronger relationship, which will be used in Dijkstra's and Bellman-Ford 
// shortest path algorithms for finding shortest path(stronger relationship).
void Graph::addFollowEdge(int followerId, int followeeId, int weight) {
    adjList[followerId].push_back({followeeId, weight});
}

// display the adjacency list of the graph - all users and their neighbors
void Graph::displayGraph() const { }

void Graph::bfsSearch(int startId) {
    // TODO:
    // 1. Use queue<int>
    // 2. Track visited using set<int> or unordered_set<int>
    // 3. Print user names instead of IDs
}

// the DFS traversal starting from the user with startUserId and print the visited users in order.
void dfsHelper(int current,
               unordered_map<int, vector<pair<int,int>>>& adjList,
               set<int>& visited,
               unordered_map<int, User>& users) {
    // TODO:
    // 1. Mark visited
    // 2. Print user name
    // 3. Recurse on neighbors
}

// Start the DFS search
void Graph::dfsSearch(int startId) {
    // TODO:
    // Initialize visited to false, indicating that none is visited since the process is just starting
    // Call helper method
}

// the Dijkstra's algorithm to find the shortest paths from the user with startUserId to all other users.
void Graph::dijkstra(int startId) {
    // TODO:
    // 1. unordered_map<int, int> dist
    // 2. Initialize all distances to INT_MAX
    // 3. Use priority_queue<pair<int,int>>
    // 4. Relax edges
}

// the Bellman-Ford algorithm to find the shortest paths from the user with startUserId to all other users.
void Graph::bellmanFord(int startId) {
    // TODO:
    // 1. Initialize distances
    // 2. Loop |V|-1 times
    // 3. Relax all edges
    // 4. Detect negative cycle
}

// the topological sort of the graph, which will print the users in a linear order such that for every directed edge from user A to user B, user A comes before user B in the ordering. This is useful for understanding the hierarchy or influence among users in the graph.
// Please refer to the assignment document for the DAG graph that will be used for testing this method.
// Keep in mind that you will need to build the DAG graph in the main function and then call this method to test it.
void Graph::topologicalSort(int startId) {
    // TODO:
    // 1. Compute in-degrees
    // 2. Use queue<int> for vertices with in-degree 0
    // 3. Process vertices and update in-degrees
    // 4. Print user names in topological order
}