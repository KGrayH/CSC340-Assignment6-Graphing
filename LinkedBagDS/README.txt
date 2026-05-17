CSC 340 Assignment 6 - Graphing
Team Members: Hensley Hensley, Windtell Souphavong

Compile:
g++ -std=c++17 main.cpp Graph.cpp User.cpp Post.cpp Reel.cpp Story.cpp -o graphProgram

Run:
./graphProgram
The program builds a directed weighted graph of users and follow relationships.

The output demonstrates:
1. Graph creation and adjacency list display
2. BFS traversal
3. DFS traversal
4. Dijkstra shortest paths
5. Bellman-Ford shortest paths
6. Topological sort on the DAG test graph

Notes:
- BFS is implemented iteratively using a queue.
- DFS is implemented recursively using a helper function.
- Dijkstra uses a priority queue and weighted edges.
- Bellman-Ford checks for shortest paths and negative cycles.
- Topological sort uses Kahn's Algorithm.

