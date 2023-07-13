#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M;
string str;
vector<string> v;
map<string, int> m;

bool compare(string s1, string s2) {
    if (m[s1] == m[s2]) {
        if (s1.length() == s2.length()) {
            return s1 < s2;
        }
        else
            return s1.length() > s2.length();
    }
    else
        return m[s1] > m[s2];
}

int main() {
    cin >> N >> M;

    for (int i = 0 ; i < N; ++i) {
        cin >> str;

        if (str.length() >= M) {
            if (m[str] == 0)
                v.push_back(str);
            m[str]++;
        }
    }
    sort(v.begin(), v.end(), compare);

    for (auto e : v)
        cout << e << "\n";
    return 0;
}