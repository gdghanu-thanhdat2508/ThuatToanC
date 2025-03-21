#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Tìm số Fibonacci thứ N sau khi chia dư kết quả cho 10^9 + 7

// Input
// 58

// Output
// 286725742

// Muon tim so fibo thu n, lay ma tran 1 1 1 0 luy thua mu n => In ra ket qua o duong cheo chinh

// A^n -> Su dung luy thua nhi phan

// Fibonacci matrix multipication - nhanh hon de quy + vong lap
int mod = 1000000007;

struct MaTran
{
    ll a[2][2];
    // Nap trong toan tu nhan cho ma tran | Nap chong toan tu cho cau truc
    friend MaTran operator*(MaTran x, MaTran y)
    // Từ khóa friend cho phép toán tử này có quyền truy cập trực tiếp vào các thành viên của
    // Hàm này định nghĩa toán tử nhân (*) giữa hai ma trận x và y. Kết quả trả về là một ma trận mới.
    {
        MaTran kq;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                kq.a[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    kq.a[i][j] += (x.a[i][j] * y.a[i][j]);
                    kq.a[i][j] %= mod;
                }
            }
        }
        return kq;
    }
};

MaTran binpow(MaTran x, ll n) // Toi uu, Log2n
{
    if (n == 1)
    {
        return x;
    }
    MaTran X = binpow(x, n / 2);
    if (n % 2 == 1)
    {
        return X * X * x;
    }
    else
    {
        return X * X;
    }
};

int main()
{
    MaTran x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;
    // Tao ma tran x co dang 1 1 1 0

    ll n;
    cin >> n;
    MaTran kq = binpow(x, n);

    // IN ra so fibonacci thu n
    cout << kq.a[0][1] << endl;
}