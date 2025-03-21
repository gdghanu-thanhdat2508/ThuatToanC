#include <bits/stdc++.h>
using namespace std;


int uutien(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void solve(string s) {
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            res += s[i];
        } else if(s[i] == '(') { // Nem dau ( vao trong ngan xep
            st.push(s[i]);
        } else if(s[i] == ')') {
            // Pop lan luot cac toan tu trong ngan xep
            while(!st.empty() && st.top() != '(') {
                res += st.top(); // Dua toan tu trong ngan xep vao xau ket qua 
                st.pop();
            }
            st.pop(); // Xoa dau mo ngoac
        } else {
            // + - * / 
            while(!st.empty() && uutien(st.top()) >= uutien(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    cout << res << endl;
}

int main() {
    // Bien doi tu Trung to sang hau to  
    // (A + B) - C * (D / E) + F

    // Nem toan tu vao ngan xep va cho toan hang vao xau ket qua
    // Neu la dau '(' thi them vao ngan xep 
    // Neu la dau ')' thi lan luot pop cac ki tu tu ngan xep va dua vao xau ket qua cho toi khi gap '('
    // Phai xem do uu tien xem toan hang nao dang thuc hien truoc  sau do dua vao xau ket qua 
    //
    // Khi gap dau co muc do uu tien cao hon thi moi duoc pop dau trong ngan xep va dua vao xau, con khong thi
    //      chi duoc push vao ngan xep cho den khi het hoac gap toan tu co hang cao hon
    // Tu trai sang phai 

    string s; cin >> s;
    solve(s);
    return 0;
}

