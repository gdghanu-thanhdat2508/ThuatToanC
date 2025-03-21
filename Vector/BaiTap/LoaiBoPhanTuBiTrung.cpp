#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Cho 1 array so voi N so nguyen, dem so phan tu khac nhau tring set

    // nlog(n)
    set<int> se;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    cout << se.size() << endl;

    // Duyet 1 set
    for (auto it = se.begin(); it != se.end(); it++)
    {
        cout << *it << endl;
    }
    // Hoac co the dung cach nay
    for (auto it = se.rbegin(); it != se.rend(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}