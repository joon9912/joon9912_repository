#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N, cnt;
string str;


int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> str;

        stack<int> st;
        for (int j = 0; j < str.length(); ++j) {
            if (st.empty())
                st.push(str[j]);
            else if (st.top() == str[j])
                st.pop();
            else if (st.top() != str[j])
                st.push(str[j]);
        }

        if (st.empty()) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
