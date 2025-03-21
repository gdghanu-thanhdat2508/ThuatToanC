#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Bạn hãy tính tổ hợp chập K của N và chia dư cho 10^9 + 7
// Su dung quy hoach dong de tinh to hop chap k cua n

// Xay dung tam giac pascal

// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

// Xay dung mang 2 chieu bang Quy Hoach Dong

// k = 0 , c = k = 1 | Day la 2 bai toan co so
// c[i][j] luu to hop chay i cua j
// c[i][j] = c[i - 1][j - 1] + c[i - 1][j]
ll C[1000][1000];

int main()
{
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // C[i][j]
            if (i == 0 || i == j)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
            }
        }
    }

    int TC;
    cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        cout << C[n][k] << endl;
    }
    return 0;
}