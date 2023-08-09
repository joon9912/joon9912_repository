#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// queue<int> q;
stack<string> st;
string str;
long long sum;

bool isDigit(string x) {
    for (int i = 0; i < x.length(); ++i)
        if (!isdigit(x[i]))
            return false;
    return true;
}

int main() {
    cin >> str;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ')') {
            if (st.empty()) {
                cout << 0 << endl;
                return 0;
            }
            long long st_sum = 0;
            while (st.top() != "(") {
                // cout << st.top() << "\n";
                if (!isDigit(st.top())) {
                    cout << 0 << endl;
                    return 0;
                }
                st_sum += stoi(st.top());
                st.pop();
                if (st.empty()) {
                    cout << 0 << endl;
                    return 0;
                }
            }
            st.pop();
            if (st_sum == 0)
                st.push("2");
            else
                st.push(to_string(st_sum * 2));
        }
        else if (str[i] == ']') {
            if (st.empty()) {
                cout << 0 << endl;
                return 0;
            }
            long long st_sum = 0;
            while (st.top() != "[") {
                if (!isDigit(st.top())) {
                    cout << 0 << endl;
                    return 0;
                }
                st_sum += stoi(st.top());
                st.pop();
                if (st.empty()) {
                    cout << 0 << endl;
                    return 0;
                }
            }

            st.pop();
            if (st_sum == 0)
                st.push("3");
            else
                st.push(to_string(st_sum * 3));
        }
        else {
            string tmp = "";
            st.push(tmp + str[i]);
        }
    }

    while (!st.empty()) {
        if (!isDigit(st.top())) {
            cout << 0 << endl;
            return 0;
        }
        sum += stoi(st.top());
        st.pop();
    }

    cout << sum << endl;
    return 0;
}
