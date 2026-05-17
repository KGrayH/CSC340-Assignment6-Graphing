#include "Graph.h"

#include <iostream>
#include <queue>
#include <set>
#include <climits>
#include <functional>

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
void Graph::displayGraph() const {

    for (const auto& userPair : adjList) {

        int userId = userPair.first;

        cout << users.at(userId).getUsername() << " -> ";

        for (const auto& neighbor : userPair.second) {

            int neighborId = neighbor.first;
            int weight = neighbor.second;

            cout << "("
                 << users.at(neighborId).getUsername()
                 << ", weight: "
                 << weight
                 << ") ";
        }

        cout << endl;
    }
}

void Graph::bfsSearch(int startId) {

    if (users.find(startId) == users.end()) {
        cout << "User does not exist." << endl;
        return;
    }

    unordered_map<int, bool> visited;
    queue<int> q;

    visited[startId] = true;
    q.push(startId);

    cout << "BFS Traversal: ";

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        cout << users[current].getUsername() << " ";

        for (const auto& neighbor : adjList[current]) {

            int neighborId = neighbor.first;

            if (!visited[neighborId]) {

                visited[neighborId] = true;
                q.push(neighborId);
            }
        }
    }

    cout << endl;
}

// the DFS traversal starting from the user with startUserId and print the visited users in order.
void Graph::dfsHelper(int currentUserId,
                      unordered_map<int, bool>& visited) {

    visited[currentUserId] = true;

    cout << users[currentUserId].getUsername() << " ";

    for (const auto& neighbor : adjList[currentUserId]) {

        int neighborId = neighbor.first;

        if (!visited[neighborId]) {

            dfsHelper(neighborId, visited);
        }
    }
}

// Start the DFS search
void Graph::dfsSearch(int startId) {

    if (users.find(startId) == users.end()) {
        cout << "User does not exist." << endl;
        return;
    }

    unordered_map<int, bool> visited;

    cout << "DFS Traversal: ";

    dfsHelper(startId, visited);

    cout << endl;
}

// the Dijkstra's algorithm to find the shortest paths from the user with startUserId to all other users.
void Graph::dijkstra(int startId) {
    // TODO:
    // 1. unordered_map<int, int> dist
    // 2. Initialize all distances to INT_MAX
    // 3. Use priority_queue<pair<int,int>>
    // 4. Relax edges

    if (users.find(startId) == users.end()) {
        cout << "User does not exist." << endl;
        return;
    }

    unordered_map<int, int> dist;

    for (const auto& userPair : users) {
        dist[userPair.first] = INT_MAX;
    }

    dist[startId] = 0;

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    pq.push({0, startId});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentUserId = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentUserId]) {
            continue;
        }

        for (const auto& neighbor : adjList[currentUserId]) {
            int neighborId = neighbor.first;
            int weight = neighbor.second;

            if (dist[currentUserId] != INT_MAX &&
                dist[currentUserId] + weight < dist[neighborId]) {

                dist[neighborId] = dist[currentUserId] + weight;
                pq.push({dist[neighborId], neighborId});
            }
        }
    }

    cout << "Dijkstra shortest paths starting from "
         << users[startId].getUsername()
         << ":" << endl;

    for (const auto& userPair : users) {
        int userId = userPair.first;

        cout << users[userId].getUsername() << ": ";

        if (dist[userId] == INT_MAX) {
            cout << "Unreachable";
        } else {
            cout << dist[userId];
        }

        cout << endl;
    }
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