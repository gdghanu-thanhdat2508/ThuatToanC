#include <bits/stdc++.h>
using namespace std;

int main() {
    // Stack la cau truc du lieu chi ho tro 2 thao tac, them va lay ra (Push - Pop)
    // => Deu dc thuc hien tren  dinh cua ngan xep 
    // Last In First Out (LIFO) 

    stack<int> st;
    st.push(1);
    st.push(2);


    // size empty clear pop push
    cout << st.top() << endl;

    st.pop();

    // Dang bai tap : Bieu thuc, ()()(a + b),... 
    //          Kieu tra bieu thuc hop le
    return 0;
}
