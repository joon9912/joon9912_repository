#include <iostream>
using namespace std;

#define NUM_EDGES 8
#define NUM_VERTEX 5

struct node {
    int v;
    int weight;
    struct node* next;
};

struct edge {
    int from;
    int to;
    int w;
};

struct edge edges[NUM_EDGES];
struct node* graph[NUM_VERTEX];
int cycle_detection[NUM_VERTEX]{ 0,1,2,3,4 };

void addEdge(int v1, int v2, int w, int doReverse) {
    struct node* new_one = (struct node*)malloc(sizeof(struct node));
    struct node* cur = graph[v1];

    new_one->v = v2;
    new_one->next = 0;
    new_one->weight = w;

    if (cur == 0)
        graph[v1] = new_one;
    else {
        while (cur->next != 0)
            cur = cur->next;
        cur->next = new_one;
    }

    if (doReverse == 1)
        addEdge(v2, v1, w, 0);
}

void swap_edge(int e1, int e2) {
    struct edge tmp;

    tmp = edges[e1];
    edges[e1] = edges[e2];
    edges[e2] = tmp;
}

void sortEdges() {
    // 모든 edge를 edges 배열에 추가
    int edges_idx = 0;
    for (int i = 0; i < NUM_VERTEX; ++i) {
        struct node* cur = graph[i];

        while (cur != 0) {
            edges[edges_idx].from = i;
            edges[edges_idx].to = cur->v;
            edges[edges_idx++].w = cur->weight;
            cur = cur->next;
        }
    }

    // 오름차순 정렬 by bubble sort
    for (int y = 0; y < NUM_EDGES; ++y) {
        for (int x = 0; x < NUM_EDGES - 1 - y; ++x) {
            if (edges[x].w > edges[x + 1].w) {
                swap_edge(x, x + 1);
            }
        }
    }

}

void putSameGroup(int v1, int v2) {
    int g1 = cycle_detection[v1];
    int g2 = cycle_detection[v2];
    int s, b; // smaller, bigger

    if (g1 > g2) {
        b = g1;
        s = g2;
    }
    else {
        b = g2;
        s = g1;
    }

    for (int i = 0; i < NUM_VERTEX; ++i) {
        if (cycle_detection[i] == b)
            cycle_detection[i] = s;
    }
}

void doMST() {
    int mst_edges = 0;
    for (int i = 0; i < NUM_EDGES; ++i) {
        if (cycle_detection[edges[i].from] != cycle_detection[edges[i].to]) {
            cout << "MST edge " << edges[i].from << " --- " << edges[i].to << " (" << edges[i].w << ") \n";
            mst_edges++;

            if (mst_edges == NUM_VERTEX - 1)
                return;
            putSameGroup(edges[i].from, edges[i].to);
        }
    }
}

int main() {
    addEdge(0, 1, 1, 0);
    addEdge(0, 2, 3, 0);
    addEdge(0, 4, 5, 0);
    addEdge(1, 2, 2, 0);
    addEdge(1, 4, 4, 0);
    addEdge(2, 4, 6, 0);
    addEdge(2, 3, 7, 0);
    addEdge(3, 4, 8, 0);


    sortEdges();
    doMST();

    for (int i = 0; i < NUM_VERTEX; ++i)
        free(graph[i]);

    return 0;
}