#include <bits/stdc++.h>
using namespace std;



bool check(string s) {
    stack<char> st;
    for(char x : s) {
        if(x == '(') {
            st.push(x);
        } else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    // Kiểm tra biểu thức dấu ngoặc đúng. Ví dụ về biểu thức dấu ngoặc đúng: (), (()), (((()))), ()()...
    // )() -> Khop hop le 
   

    
    return 0;
}
