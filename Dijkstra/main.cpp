#include <iostream>
#include <vector>
#include <queue>

#define MAX 100 // �ִ� ���� ����
#define INF 99999999

using namespace std;

vector<int> dijkstra(int start, int V, vector<pair<int, int>> adj[]){
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;     // �湮�� ������ dist ��
        int cur = pq.top().second;      // ���� �湮�� ����
        pq.pop();

        // ���� �湮�� ������ �ֺ� ���� ��� ����
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
    cout << "������ ���� : ";
    cin >> V;
    cout << "������ ���� : ";
    cin >> E;

    for (int i = 0; i < E; ++i) {
        int from, to, cost;
        cout << "�׷��� �Է� [���� ���� ����ġ] : ";
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(to, cost));
        adj[to].push_back(make_pair(from, cost));
     }

    printf("\n===dijkstra result===\n");
    vector<int> dist = dijkstra(0, V, adj);
    for (int i = 0; i < V; ++i)
        printf("0�� �������� %d�� �������� �ִܰŸ� : %d\n", i, dist[i]);
    return 0;
}

/*
 ������ ���� :5
 ������ ���� :8
 �׷��� �Է� [���� ���� ����ġ] :0 1 5
 �׷��� �Է� [���� ���� ����ġ] :0 2 3
 �׷��� �Է� [���� ���� ����ġ] :0 3 7
 �׷��� �Է� [���� ���� ����ġ] :1 2 4
 �׷��� �Է� [���� ���� ����ġ] :2 3 3
 �׷��� �Է� [���� ���� ����ġ] :1 4 7
 �׷��� �Է� [���� ���� ����ġ] :2 4 8
 �׷��� �Է� [���� ���� ����ġ] :3 4 4
 */
