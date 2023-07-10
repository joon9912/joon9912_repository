#include <iostream>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

priority_queue<int> pq;
list<int> v[1500];
int N, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1 <= N <= 1500
    cin >> N;

    int max = 0;
    int idx = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> x;
            v[j].push_back(x);

            if (i == N - 1) {
                pq.push(x);

                if (max < x) {
                    max = x; idx = j;
                }
            }
        }
    }

    v[idx].pop_back();
    pq.pop();
    pq.push(v[idx].back());

    for (int i = 0; i < N - 1; ++i) {
        max = v[0].back(); idx = 0;
        for (int j = 0; j < N; ++j) {
            if (max < v[j].back()) {
                max = v[j].back();
                idx = j;
            }
        }
        // cout << v[idx].back() << "\n";
        v[idx].pop_back();
        pq.pop();
        pq.push(v[idx].back());
    }

    cout << max << endl;

    return 0;
}
