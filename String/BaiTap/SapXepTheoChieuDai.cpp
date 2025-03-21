#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho xâu kí tự S gồm các từ được phân cách nhau bởi một vài dấu cách.
// Thực hiện sắp xếp các từ trong xâu theo thứ tự chiều dài tăng dần,
// nếu 2 từ có cùng chiều dài thì từ nào có thứ tự từ điển nhỏ hơn sẽ được xếp trước.

bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main()
{
    vector<string> v;
    string s;

    while (cin >> s)
    {
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);

    return 0;
}