#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho số tự nhiên N. Nhiệm vụ của bạn là in ra ước số nguyên tố nhỏ nhất của các số từ 1 đến N.
// Ước số nguyên tố nhỏ nhất của 1 là 1.
// Ước số nguyên tố nhỏ nhất của các số chẵn là 2.
// Ước số nguyên tố nhỏ nhất của các số nguyên tố là chính nó.

// primer[i] : Luu uoc nguyen to nho nhat cua i
int primer[];

void sang()
{
    for (int i = 0; i <= 1000000; i++)
    {
        primer[i] = i;
        // i la so nguyen to thi uoc cua so nguyen to la chinh no
    }
    // Loai bang vong lap
    for (int i = 2; i <= sqrt(1000000); i++)
    {
        if (primer[i] == i)
        // 1 so ma co uoc nguyen to nho nhat la chinh no => no la so nguyen to
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                if (primer[j] == j) // So j chua gap thua so nguyen to nao ca
                {
                    primer[j] = i; // Cap nhat uoc nguyen to nho nhat cua j la i
                }
            }
        }
    }
}

int main()
{
    sang();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << primer[i] << "\n";
    }
    return 0;
}