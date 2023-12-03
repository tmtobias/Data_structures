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
#include <vector>
#include <queue>
#include <stack>

// Visualization of graph from the example
//
//    0______\1______\4______\5______\6______\7
//    |      /|      /       /       /       /
//    |       |
//   \|/______|
//    2\
//    |
//    |
//   \|/
//    3
//

class Graph {
public:
    Graph(int vertices) : V(vertices) {
        // Initialize adjacency matrix with zeros
        adjacencyMatrix.resize(V, std::vector<int>(V, 0));
    }

    void addEdge(int v1, int v2) {
        // Adding an edge from v1 to v2 (directed graph)
        // Assuming an unweighted graph, so set matrix[v1][v2] to 1
        adjacencyMatrix[v1][v2] = 1;
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(int startVertex);
    void DFS(int startVertex);

private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjacencyMatrix;
};

void Graph::BFS(int startVertex) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    std::cout << "BFS starting from  vertex " << startVertex << ": ";

    while (!q.empty()) {
        int currentVertex = q.front();
        std::cout << currentVertex << " ";
        q.pop();

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    std::cout << std::endl;
}

void Graph::DFS(int startVertex) {
    std::vector<bool> visited(V, false);
    std::stack<int> s;

    std::cout << "DFS starting from vertex " << startVertex << ": ";

    s.push(startVertex);

    while (!s.empty()) {
        int currentVertex = s.top();
        s.pop();

        if (!visited[currentVertex]) {
            std::cout << currentVertex << " ";
            visited[currentVertex] = true;
        }

        for (int neighbor = V - 1; neighbor >= 0; neighbor--) {
            if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }

    std::cout << std::endl;
}

int main()
{
    Graph g(8);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.printGraph();

    g.BFS(0);
    g.DFS(0);

    return 0;
}
