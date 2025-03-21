#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Cho xâu kí tự S gồm các từ được phân cách nhau bởi một vài dấu cách.
// Hãy tách ra các từ thuận nghịch trong xâu và sắp xếp theo thứ tự từ điển tăng dần.

bool tn(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return s == t;
}
int main()
{
    vector<string> v;
    string s;
    while (cin >> s) // Lay tung tu 1 trong xau ky tu : VD Thanh Dat -> Co 2 tu
    {
        if (tn(s))
        {
            v.push_back(s);
        }
    }

    sort(v.begin(), v.end());
    for (string x : v)
    {
        cout << x << " ";
    }
    return 0;
}