#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tình độ dài dấy con chung dài nhất có mặt trong cả ba xâu.
int main()
{
    // Su dung mang 3 chieu
    // F[i][j][k] => Cho biet xau con dai nhat
    // Lay i ky tu dau tien cua X, j ky tu dau tien cua Y va k ky tu dau tien cua Z
    // i == j == k = F[i - 1][j - 1][k - 1] + 1

    string s, t, z;
    cin >> s >> t >> z;

    int n = s.length(), m = t.length(), l = t.length();
    int F[n + 1][m + 1][l + 1];
    memset(F, 0, sizeof(F));
    s = " " + s;
    t = " " + t;
    z = " " + z;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= l; k++)
            {
                if (s[i] == t[j] && s[i] == z[k])
                {
                    F[i][j][k] = F[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    F[i][j][k] = max(F[i - 1][j][k], F[i][j - 1][k], F[i][j][k - 1]);
                }
            }
        }
    }
    cout << F[n][m][l] << endl;
    return 0;
}