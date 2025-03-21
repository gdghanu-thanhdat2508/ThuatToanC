#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // Cho xâu kí tự S gồm các từ được phân cách nhau bởi một vài dấu cách.
    // Thực hiện sắp xếp các từ trong xâu theo thứ tự từ điển tăng dần và giảm dần.
    vector<string> v;

    string s;
    while (cin >> s)
    {
        v.push_back(s);
    }
    // sap xep tang gian
    sort(v.begin(), v.end());

    for (string x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    // Sort theo giam dan
    sort(v.begin(), v.end(), greater<string>());
    for (string x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}