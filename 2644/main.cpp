#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q, qq;
vector<int> v[101];
bool visited[101];

int main() {
    int n, x, y, m, a, b;

    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    q.push(a);
    visited[a] = true;

    int level = 1;
    int top = -1;
    while(!q.empty()) {
        while (!q.empty()) {
            top = q.front();
            q.pop();
            for (auto e : v[top]) {
                if (e == b) {
                    cout << level << endl;
                    return 0;
                }
                if (!visited[e]) {
                    qq.push(e);
                    visited[e] = true;
                }
            }
        }
        while (!qq.empty()) {
            top = qq.front();
            qq.pop();
            q.push(top);
        }
        level++;
    }

    cout << -1 << endl;
    /*
    for (int i = 1; i <= m; ++i) {
        cout << i << "\n";
        for (auto e : v[i]) {
            cout << e << " ";
        }
        cout << "\n\n";
    }
    */
    return 0;
}
