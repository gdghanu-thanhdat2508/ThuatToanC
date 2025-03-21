#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho tập gồm N phần tử là các số từ 1 tới N và số K. Bạn hãy đưa ra tập con kế tiếp của tập con hiện tại.
// Nếu tập con hiện tại là tập con cuối cùng thì bạn hãy đưa ra tập con kế tiếp là tập con đầu tiên.

// 6 5
// 2 3 4 5 6

// 1 2 3 4 5

int n, k, a[1005], final = 0;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    if (i == 0)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << a[j] << " ";
        }
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
        for (int i = 1; i <= k; i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}