#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<bool> st;
stack<bool> st2;
string s;
int cnt = 0;

int main() {
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            st.push(true);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
                cnt++;
            }
        }
        if (s[i] == '[') {
            st2.push(true);
        } else if (s[i] == ']') {
            if (!st2.empty()) {
                st2.pop();
                cnt++;
            }
        }
    }
    cout << cnt*2 << endl;
    return 0;
}
