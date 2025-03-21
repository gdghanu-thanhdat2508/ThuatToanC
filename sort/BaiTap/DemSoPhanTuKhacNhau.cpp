#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Dem so luong phan tu khac nhau, su dung sort
    // 1 -> 2.10^5

    // Nhanh hon set va map
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int dem = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            ++dem;
        }
    }

    return 0;
}