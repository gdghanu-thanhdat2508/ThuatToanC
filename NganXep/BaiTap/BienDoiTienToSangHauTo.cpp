#include <bits/stdc++.h>
using namespace std;


string solve(string s) {
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(isalpha(s[i])) {
            string tmp = string(1, s[i]);
            st.push(tmp);
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string tmp = " ";
            tmp += op1 + op2 + s[i];
            st.push(tmp);
        }
    }
    return st.top();
}
int main() {
    string s; cin >> s;

    cout << solve(s) << endl;
    return 0;
}
