#include <bits/stdc++.h>
using namespace std;
// Tổ hợp chập K của N
// Bạn hãy tính tổ hợp chập K của N và chia dư cho 10^9 + 7

// Su dung mang 2 chieu
// Tam giac pascal - su dung quy hoach dong

// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// 1 6 15 20 15 6 1

// C00
// C01 C11
// C02 C12 C22
// C03 C13 C23 C33
// C04 C14 C24 C34 C44
// C05 C15 C25 C35 C45 C55

// Xay dung tam giac pascal co 1000 dong

// Ckn = C(k - 1)(n - 1) + C(k)(n - 1)

long long c[1005][1005];
void init()
{
    // C[i][j] - to hop chap j cua i
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            { // Cot dau tien hoac duong cheo
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                c[i][j] %= 10000000007;
            }
        }
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << c[n][k] << " ";
    }
    return 0;
}