#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// graph edge 를 저장할 data structure
struct Edge {
    int src;
    int dst;
    int weight;
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

typedef pair<int, int> Pair;

class WeightGraph {
public:
    vector<vector<Pair>> adjList;

    WeightGraph(vector<Edge> const &edges, int n) {
        adjList.resize(n);

        for (auto &edge : edges) {
            int src = edge.src;
            int dst = edge.dst;
            int weight = edge.weight;

            adjList[src].push_back(make_pair(dst, weight));

            // undirected graph
            // adjList[dst].push_back(make_pair(src, weight));
        }
    }
};

void printWeightGraph(WeightGraph const &graph, int n) {
    for (int i = 0; i < n; ++i) {
        for (Pair v : graph.adjList[i]) {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        cout << "\n";
    }
}
// implement Graph by using STL
int main() {
    int n = 6;
    vector<Edge> edges = {
            {0, 1, 6},
            {1, 2, 7},
            {2, 0, 5},
            {2,1,4},
            {3,2,10},
            {5,4,1},
            {4,5,3},
    };

    WeightGraph graph(edges, n);

    printWeightGraph(graph, n);

    return 0;
}