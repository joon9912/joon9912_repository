#include <iostream>
using namespace std;

unsigned S, N;

int main() {
    long long sum = 0;

    cin >> S;

    for (unsigned i = 1; i <= S; ++i) {
        // sum = i * (i + 1) / 2;
        sum += i;
        if (sum >= S) {
            N = i;
            break;
        }
    }

    if (sum == S)
        cout << N << "\n";
    else // sum > S
        cout << N - 1 << "\n";

    return 0;
}
