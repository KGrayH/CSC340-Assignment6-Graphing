#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <utility>
#include "User.h"

using namespace std;

class Graph {
private:
    // Map userId -> User object
    unordered_map<int, User> users;

    // Adjacency list representing the graph: userId -> list of (neighborId, weight)
    // userId represents the user who follows, neighborId represents the userId for the userit follows, and weight could represent the strength of the relationship
    // with smaller weight indicates a stronger relationship.
    // userId -> list of (neighborId, weight)
    unordered_map<int, vector<pair<int,int>>> adjList;

    // Helper function for recursive DFS traversal
    void dfsHelper(int currentUserId, unordered_map<int, bool>& visited);

public:
    void addUser(const User& user);          //add new user to graph

    // Graph edges (follow relationships)
    void addFollowEdge(int followerId, int followeeId, int weight);

    // Traversals
    void bfsSearch(int startUserId);
    void dfsSearch(int startUserId);

    // Shortest Paths
    void dijkstra(int startUserId);
    void bellmanFord(int startUserId);

    // Toplogical Sort
    void topologicalSort(int startId);

    // Utility
    void displayGraph() const;
};

#endif