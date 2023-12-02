// Graph:
// Hierarchical data structure
//
// Node = Vertex
// Edge = Connecting point
// Adjency = Dirrectly connected nodes
// Degree = Number of edges
// Possibility to be cyclic is the biggest difference against the tree
// Types: Directed, Undirected, Weighted, Unweighted, Cyclic, Acyclic
//
// Search = Breadth First Search & Depth First Search

#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// Visualization of graph from the example
//
//    1______\2______\5______\6______\7______\8
//    |      /|      /       /       /       /
//    |       |
//   \|/______|
//    3\
//    |
//    |
//   \|/
//    4
//


class Graph {
public:
    void addVertex(int v) {
        // If the vertex doesn't exist, add it to the adjacency list
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = {};
        }
    }

    void addEdge(int v1, int v2) {
        // Add an edge from v1 to v2 (directed graph)
        // If vertices don't exist, add them

        addVertex(v1);
        addVertex(v2);

        adjList[v1].push_back(v2);
    }

    void printGraph() {
        for (const auto& entry : adjList) {
            std::cout << entry.first << " -> ";
            for (const auto& neighbor : entry.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void DFS(int startVertex);
    void BFS(int startVertex);

private:
    std::unordered_map<int, std::list<int>> adjList;

    void DFSUtil(int vertex, std::unordered_set<int>& visited);
    void BFSUtil(int startVertex, std::unordered_set<int>& visited);
};

void Graph::DFS(int startVertex) {
    std::unordered_set<int> visited;
    std::cout << "DFS starting from vertex " << startVertex << ": ";
    DFSUtil(startVertex, visited);
    std::cout << std::endl;
}

void Graph::DFSUtil(int vertex, std::unordered_set<int>& visited) {
    visited.insert(vertex);
    std::cout << vertex << " ";

    for (int neighbor : adjList[vertex]) {
        if (visited.find(neighbor) == visited.end()) {
            DFSUtil(neighbor, visited);
        }
    }
}

void Graph::BFS(int startVertex) {
    std::unordered_set<int> visited;
    std::cout << "BFS starting from vertex " << startVertex << ": ";
    BFSUtil(startVertex, visited);
    std::cout << std::endl;
}

void Graph::BFSUtil(int startVertex, std::unordered_set<int>& visited) {
    std::queue<int> q;
    visited.insert(startVertex);
    q.push(startVertex);

    while (!q.empty()) {
        int vertex = q.front();
        std::cout << vertex << " ";
        q.pop();

        for (int neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    Graph g;

    // Adding vertices
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    // Adding edges
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);

    // Printing the graph
    std::cout << "Graph representation:" << std::endl;
    g.printGraph();

    std::cout << std::endl;

    // Performing DFS and BFS from vertex 1
    g.DFS(1);
    g.BFS(1);

    std::cout << std::endl;

    // Performing DFS and BFS from vertex 2
    g.DFS(2);
    g.BFS(2);

    return 0;
}
