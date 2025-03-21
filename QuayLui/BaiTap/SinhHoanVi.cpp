#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Hoan vi nen dung them 1 mang danh dau de xem xem phan tu do da dc su dung trong hoan vi do hay chua

int n, X[100];
int used[100];

void QL(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (used[j] == 0)
        {
            X[i] = j;
            used[j] = 1;

            if (i == n)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << X[j];
                }
                cout << endl;
            }
            else
            {
                QL(i + 1);
            }
            used[j] = 0; // Tra ve de thang j co the su dung tiep sau khi goi 1 lan de quy
        }
    }
}

int main()
{
    cin >> n;
    QL(1);
    return 0;
}