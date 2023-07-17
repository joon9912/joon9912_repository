#include <iostream>
#include <vector>
#include <queue>

#define MAX 100 // 최대 정점 개수
#define INF 99999999

using namespace std;

vector<int> dijkstra(int start, int V, vector<pair<int, int>> adj[]){
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;     // 방문한 정점의 dist 값
        int cur = pq.top().second;      // 현재 방문한 정점
        pq.pop();

        // 현재 방문한 정점의 주변 정점 모두 조사
        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i].first;
            int nCost = cost + adj[cur][i].second;
            if (nCost < dist[next]) {
                dist[next] = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    vector<pair<int, int>> adj[MAX];
    cout << "정점의 개수 : ";
    cin >> V;
    cout << "간선의 개수 : ";
    cin >> E;

    for (int i = 0; i < E; ++i) {
        int from, to, cost;
        cout << "그래프 입력 [정점 정점 가중치] : ";
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(to, cost));
        adj[to].push_back(make_pair(from, cost));
     }

    printf("\n===dijkstra result===\n");
    vector<int> dist = dijkstra(0, V, adj);
    for (int i = 0; i < V; ++i)
        printf("0번 정점에서 %d번 정점까지 최단거리 : %d\n", i, dist[i]);
    return 0;
}

/*
 정점의 개수 :5
 간선의 개수 :8
 그래프 입력 [정점 정점 가중치] :0 1 5
 그래프 입력 [정점 정점 가중치] :0 2 3
 그래프 입력 [정점 정점 가중치] :0 3 7
 그래프 입력 [정점 정점 가중치] :1 2 4
 그래프 입력 [정점 정점 가중치] :2 3 3
 그래프 입력 [정점 정점 가중치] :1 4 7
 그래프 입력 [정점 정점 가중치] :2 4 8
 그래프 입력 [정점 정점 가중치] :3 4 4
 */
