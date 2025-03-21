#include <bits/stdc++.h>
using namespace std;

// Cho mảng 2 chiều A gồm N hàng và N cột,
// hãy xét tất cả các hình vuông con cỡ 3x3 của mảng A, hãy tìm hình vuông có có tổng lớn nhất đó.

// 6
// 4 6 4 5 8 2
// 8 0 9 0 1 4
// 3 5 3 6 3 4
// 5 7 0 9 5 9
// 4 5 5 9 6 3
// 9 2 3 6 1 8

// Phai tim tam cua hinh vuong -> Tu do se duy ra hang va cot cua 8 o xung quanh
// (i-1, j-1) (i-1, j) (i-1, j+1)
// (i, j-1) (i, j) (i, j+1)
// (i+1, j-1) (i+1, j) (i+1, j+1)

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    long long res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            // a[i][j] la o trung tam
            long long tong = a[i][j];

            for (int k = 0; k < 8; k++)
            {
                int i1 = i + dx[k], j1 = j + dy[k];
                tong += a[i1][j1];
            }
            res = max(res, tong);
        }
    }
    cout << res << " ";
    return 0;
}