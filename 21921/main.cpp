#include <iostream>
#include <vector>
using namespace std;

int X, N, cnt, m;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int visit, sum = 0;

    cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        cin >> visit;
        v.push_back(visit);
    }

    int left = 0;
    int right = left + X - 1;

    for (int i = left; i <= right; ++i) {
        sum += v[i];
    }

    while (right < N) {
        if (sum > m) {
            m = sum;
            cnt = 1;
        }
        else if (sum == m)
            cnt++;
        sum -= v[left++];
        sum += v[++right];
    }
    if (m == 0)
        cout << "SAD\n";
    else
        cout << m << "\n" << cnt << "\n";

    return 0;
}