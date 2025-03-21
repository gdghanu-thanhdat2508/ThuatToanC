#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, X[100];

// X[i] : n - k + i -> Gia tri lon nhat co the nhan dc
// X[i - 1] + 1 -> Gia tri nho nhat co the nhan dc

void QL(int i)
{
    for (int j = X[i - 1] + 1; j <= n - k + i; j++)
    {
        X[i] = j;
        if (i == k)
        {
            for (int j = 1; j <= k; j++)
            {
                cout << X[j];
            }
            cout << endl;
        }
        else
        {
            QL(i + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    QL(1);
    return 0;
}