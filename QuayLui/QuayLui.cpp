#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Backtracking : brute force
// Sinh cau hinh, ...
// Quay lui co the lam moi bai toan

// Quay lui : Chia cau hinh thanh tung phan nho
// Tu nhung thanh phan nno do co the sinh ra cac ket qua khac nhau

// Quay lui sinh xau nhi phan
int n, X[100];
// Di gan gia tri cho X[i]
// Phai kiem tra xem X[i] nhan dc nhung gia tri nao
void QuayLui(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        // Lap 2 lan, sinh ra 2 TH
        X[i] = j;
        if (i == n)
        {
            // Khi gan du X[1], X[2], ... X[n] roi
            for (int k = 1; k <= n; k++)
            {
                cout << X[k];
            }
            cout << endl;
        }
        else
        {
            QuayLui(i + 1); // Tiep tuc gan 
        }
    }
}
int main()
{
    cin >> n;
    QuayLui(1);
    return 0;
}
