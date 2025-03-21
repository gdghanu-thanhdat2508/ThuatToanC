#include <bits/stdc++.h>
using namespace std;

bool kiemtra(char x, char y)
{
    return (x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']');
}

bool check(string s)
{
    stack<char> st;
    for (char x : s)
    {
        if (x == '(' || '[' || '{')
            st.push(x);
        else
        {
            if (st.empty())
                return false;
            char y = st.top();
            st.pop();
            // y <> x
            if (!kiemtra(y, x))
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    // Cho một xâu kí tự chỉ bao gồm các kí tự (, '), 't. '3'% 'C'. "J",
    // hãy xác định xem các dấu ngoặc trong xâu có cân bằng hay không. Một vài ví dụ về xâu cân bằng:...

    string s;
    cin >> s;
    if (check(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
