#include <iostream>
using namespace std;

#define SIZE 100001

int N, s, maximum;
int honey[SIZE];
int sum[SIZE];

int main() {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> honey[i];
        sum[i] = sum[i - 1] + honey[i];
    }

    int honeycomb;
    // h1 - honeycomb - h2
    for (int i = 2; i < N; ++i) {
        s += (sum[i] - honey[1]) + (sum[N] - honey[N] - sum[i - 1]);
        maximum = max(maximum, s);
        s = 0;
    }

    // h1 - h2 - honeycomb
    for (int i = 2; i < N; ++i) {
        s += (sum[N] - honey[1] - honey[i]) + (sum[N] - sum[i]);
        maximum = max(maximum, s);
        s = 0;
    }

    // honeycomb - h1 - h2
    for (int i = 2; i < N; ++i) {
        s += (sum[N] - honey[N] - honey[i]) + (sum[i] - honey[i]);
        maximum = max(maximum, s);
        s = 0;
    }

    cout << maximum << "\n";

    return 0;
}
