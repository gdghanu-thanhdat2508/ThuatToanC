#include <bits/stdc++.h>
#include <cctype>
using namespace std; 

string solve(string s) {
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(isalpha(s[i])) {
            // Nem vao ngan xep 
            string tmp = string(1, s[i]); // Chuyen thanh String
            st.push(tmp);
        } else {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string tmp = "(" + op1 + s[i] + op2 + ")";
            st.push(tmp);
        }
    }
}
int main() {
    // Trung to : (A + B) * (C - D) (Viet dau o sau)
    // Tien to : *+AB-CD (Viet dau truoc)
    // Hau to : AB+CD-* (Viet dau o cuoi)
    
    // Bien doi Tien to sang Trung to 
    
    // *+AB-CD
    // (A + b) * (C - D)
    
    // Ap dung ngan xep de duyet tu cuoi 
    // Duyet : Nem nhung thu khong phai dau vao ngan xep 
    //          Stack String 
    //          Khi gap toan tu -> Ap dung voi 2 toan hang o tren dinh ngan xep 
    //          Sau khi ap dung dau vao roi thi lai cho vao ngan xep
    
    string s; cin >> s;
    cout << solve(s) << endl;

    return 0;
}
