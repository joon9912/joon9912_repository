#include <iostream>
#include <string>
using namespace std;

int N, cnt;
int s1[100001];
int s2[100001];
int visited[100001];

void print_s1() {
    for (int i = 0; i < N; ++i) {
        cout << s1[i];
    }
    cout << endl;
}

void print_s2() {
    for (int i = 0; i < N; ++i) {
        cout << s2[i];
    }
    cout << endl;
}


bool my_equal() {
    for (int i = 0; i < N; ++i) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

int main() {
    string n1, n2;
    cin >> N;

    cin >> n1;
    cin >> n2;

    for (int i = 0; i < N; ++i) {
        s1[i] = n1[i] - '0';
        s2[i] = n2[i] - '0';
    }


    cout << -1 << endl;
    // print_s();

    return 0;
}
