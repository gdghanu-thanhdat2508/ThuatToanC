#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // Dem tan so cua cac tu trong xau s
    map<string, int> mp;
    string s;

    while (cin >> s)
    {
        mp[s]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}