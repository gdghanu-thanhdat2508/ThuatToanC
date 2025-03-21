#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho xau s va dem xem moi ky tu trong xau s xuat hien bao nhieu lan
int main()
{
    string s;
    getline(cin, s);
    map<char, int> mp;

    // Solution 2: Mang danh dau -> Nhanh hon map
    int cnt[256] = {0};
    for (char x : s)
    {
        mp[x]++;
        cnt[x]++; // Solution 2
    }

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    // Solution 2:
    for (int i = 0; i < 255; i++)
    {
        if (cnt[i])
        {
            cout << (char)i << " " << cnt[i] << endl;
        }
    }
    return 0;
}