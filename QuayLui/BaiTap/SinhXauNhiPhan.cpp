#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, X[100];

void QL(int a)
{
    for (int i = 0; i <= 1; i++)
    {
        X[a] = i;
        if (a == n)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << X[j];
            }
            cout << endl;
        }
        else
        {
            QL(a + 1);
        }
    }
}

int main()
{
    cin >> n;
    QL(1);
    return 0;
}