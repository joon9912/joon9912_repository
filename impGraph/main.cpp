#include <iostream>
#include <vector>
using namespace std;

// graph edge 를 저장할 data structure
struct Edge {
    int src;
    int dst;
};

class Graph {
public:
    // adj list
    vector<vector<int>> adjList;

    // Graph constructor
    Graph(vector<Edge> const &edges, int n) {
        adjList.resize(n);

        for (auto &edge : edges) {
            adjList[edge.src].push_back(edge.dst);

            // undirected graph comment
            // adjList[edge.dst].push_back(edge.src);
        }
    }
};

void printGraph(Graph const &graph, int n) {
    for (int i = 0; i < n; ++i) {
        // print vertex #
        cout << i << " ---> ";

        // print all adj vertex of 'i'
        for (int v : graph.adjList[i])
            cout << v << " ";
        cout << "\n";
    }
}

// implement Graph by using STL
int main() {
    int n = 6;
    vector<Edge> edges = {
            {0, 1},{1, 2},
            {2, 0},{2, 1},
            {3, 2},{4, 5},
            {5, 4},
    };
    Graph graph(edges, n);

    printGraph(graph, n);

    return 0;
}