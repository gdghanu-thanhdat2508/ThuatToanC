#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][] nhất định (0 ≤ A[l[] ≤ 100),
// tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.
// Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

// 12 29 80 91 56 46 97 13
// 54 88 27 84 85 9 32 77
// 48 80 88 74 30 77 38 98
// 6 82 20 95 7 86 12 43
// 100 82 15 7 95 9 5 84
// 51 40 65 98 86 38 30 63
// 96 78 98 76 33 11 2 58
// 33 51 35 68 62 87 67 39

// 653

int n, X[1000], ans = 0;
int cot[100], xuoi[100], nguoc[100];
int a[100][100];

void QL(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0)
        {
            X[i] = j;
            cot[j] = 1;
            xuoi[i - j + n] = 1;
            nguoc[i + j - 1] = 1;

            if (i == n)
            {
                int tong = 0;
                for (int row = 1; row <= n; row++)
                {
                    tong += a[row][X[row]];
                    // Chi so cot cua con hau la X[row]
                }
                ans = max(ans, tong);
            }
            else
            {
                QL(i + 1);
            }
            cot[j] = 0;
            xuoi[i - j + n] = 0;
            nguoc[i + j - 1] = 0;
        }
    }
}

int main()
{
    int n = 8;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    QL(1);
    cout << ans << endl;
    return 0;
}