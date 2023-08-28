#include <iostream>
#include <string>
using namespace std;

int k;
int visited[10]{
    0,0,0,
    0,0,0,
    0,0,0,
};
char s[10];
string ans, m;
bool lock = false;

void dfs(string str, int level) {
    if (level == k) {
        ans = str;

        if (!lock) {
            m = ans;
            lock = true;
        }
        return;
    }

    char c;

    if (s[level] == '<')
        c = '<';
    if (s[level] == '>')
        c = '>';

    if (c == '<') {
        for (int i = 0; i < 10; ++i) {
            if (!visited[i] && str[str.length() - 1] - '0' < i) {
                visited[i] = 1;
                str = str + to_string(i);
                dfs(str, level + 1);
                str = str.substr(0, str.length() - 1);
                visited[i] = 0;
            }
        }
    }
    else if (c == '>') {
        for (int i = 0; i < 10; ++i) {
            if (!visited[i] && str[str.length() - 1] - '0' > i) {
                visited[i] = 1;
                str = str + to_string(i);
                dfs(str, level + 1);
                str = str.substr(0, str.length() - 1);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    string x = "";

    cin >> k;

    for (int i = 0; i < k; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < 10; ++i) {
        visited[i] = 1;
        x = x + to_string(i);
        dfs(x, 0);
        x = x.substr(0, x.length() - 1);
        visited[i] = 0;
    }

    cout << ans << endl;
    cout << m << endl;
    return 0;
}
