#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Toc do chia va tri chay nhanh

// Ap Dung : Xau Fibonacci

// Xâu S chỉ bao gồm các kí tự A và B được gọi là xâu Fibonacci
// nếu S(1) = 'A', S(2) = 'B', S(n) = S(n - 2) + S(n - 1).
// trong đó phép + là phép nối 2 xâu.
// Bài toán đặt ra là tìm kí tự thứ K trong xâu fibonacci thứ N.

// Input
// 5 3

// Output
// B

// Dem di chia doi chia doi cho den khi den 2 xu nho nhat la A va B thi ta tim dc dap ans

ll F[100];

char Find(ll n, ll k)
{
    cout << n << " " << k << endl;
    if (n == 1)
    {
        return 'A';
    }
    if (n == 2)
    {
        return 'B';
    }

    // Chia doi
    if (k <= F[n - 2])
    {
        // So sanh STT k voi do dai cua F[n - 2]
        // Xem xem thang k thuoc nua trai hay phai
        // F[n - 2] - Do dai cua Fibonacci thu n - 2

        // VD : Xau fibo thu 9 duoc cau tao tu xau Fibo thu 7 va 8 => Chia ra lam 2 nua 1 ben tao tu 8
        // 1 ben tao tu 7 : F[n - 2] (Xau fibo thu 7) va F[n - 1] ( Xau fibo thu 8 )

        // Neu no o Xau Fibo[n-2] thi goi de quy den F[n - 2], khong thi F[n - 1]
        return Find(n - 2, k);
    }
    else
    {
        // Doi voi nua con lai F[n - 1]

        // k - do dai cua xau fino truoc do moi ra
        return Find(n - 1, k - F[n - 2]);
    }
}

int main()
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= 92; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }

    ll n, k;
    cin >> n >> k;

    cout << Find(n, k) << endl;
    return 0;
}