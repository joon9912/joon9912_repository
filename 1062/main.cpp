#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, m;
int alpha[26];
int visited[26];
vector<string> sv;
vector<char> w, z;

// N <= 50
// K <= 26
// 8 <= length <= 15
// anta ... tica

void init() {
    alpha['a' - 'a'] = 1;
    alpha['n' - 'a'] = 1;
    alpha['t' - 'a'] = 1;
    alpha['i' - 'a'] = 1;
    alpha['c' - 'a'] = 1;
}

bool isNotDup(char c) {
    return alpha[int(c - 'a')] == 0;
}

void choose(int level) {
    if (level == K - 5) {
        int tmp = 0;
        for (auto e : z) {
            alpha[e - 'a'] = 1;
        }

        for (auto e : sv) {
            int i;
            for (i = 0; i < e.length(); ++i) {
                if (alpha[int(e[i] - 'a')] == 0)
                    break;
            }
            if (i == e.length()) {
                tmp++;
            }
        }

        m = max(m, tmp);

        for (auto e : z) {
            alpha[e - 'a'] = 0;
        }
        return;
    }
    for (int i = 0; i < w.size(); ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            z.push_back(w[i]);
            choose(level + 1);
            z.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    init();

    string s;

    cin >> N >> K;

    if (K < 5) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        cin >> s;

        sv.push_back(s);

        for (int j = 4; j < s.length() - 4; ++j) {
            if (isNotDup(s[j])) {
                w.push_back(s[j]);
            }
        }
    }

    //for (int i = 0; i < 26; ++i)
    //    cout << alpha[i] << " ";
    //cout << endl;

    choose(0);

    cout << m << "\n";

    return 0;
}
