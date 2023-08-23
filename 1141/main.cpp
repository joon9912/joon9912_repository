#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
int N; // <= 50
vector<string> v;

bool compare(string s1, string s2) {
    return s1.length() < s2.length();
}

int main() {
    string s;

    cin >> N;
    ans = N;

    for (int i = 0; i < N; ++i) {
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);

    int v_size = v.size();
    for (int i = 0; i < v_size - 1; ++i) {
        // bool flag = false;
        for (int j = i + 1; j < v_size; ++j) {
            if (v[i].length() == v[j].length()) {
                if (v[i] == v[j]) {
                    ans--;
                    break;
                }
            }
            else { // v[i].length() < v[j].length()
                int k;
                for (k = 0; k < v[i].length(); ++k) {
                    if (v[i][k] != v[j][k]) break;
                }
                if (k != v[i].length())
                    continue;
                else {
                    ans--;
                    break;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
