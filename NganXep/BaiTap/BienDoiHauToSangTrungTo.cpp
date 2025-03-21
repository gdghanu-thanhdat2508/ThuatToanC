#include <bits/stdc++.h>
using namespace std;


void solve(string s) {
    stack<string> st;
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string tmp = "";
            tmp += "(" + op2 + s[i] + op1 + ")";
            st.push(tmp);
        }
    }
    cout << st.top() << endl;
}
int main () {
    // AB+UV-/

    string s; cin >> s;
    solve(s);
    return 0;
}
