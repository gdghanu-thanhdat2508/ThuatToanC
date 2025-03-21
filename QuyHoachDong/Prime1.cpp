#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Cho số nguyên dương N, hãy đếm xem trong đoạn từ 0 tới N có bao nhiêu số nguyên tố. Hướng dẫn :
//  • Bước 1 : Sàng số nguyên tố
//  • Bước 2: Gọi F[i] là số lượng các số nguyên tố từ 0 tới i, xây dựng mảng F[i] sau khi sàng

const int maxn = (int)1e6;

int prime[maxn + 1];
int F[1000001];

void sang()
{
    // Bước 1: Đánh dấu tất cả các số từ 0 đến maxn là nguyên tố.

    // Bước 2: Loại bỏ các số không nguyên tố (0 và 1).

    // Bước 3: Với mỗi số nguyên tố i, đánh dấu tất cả bội số của i (từ i*i đến maxn) là không nguyên tố.

    for (int i = 0; i <= maxn; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(maxn); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    sang();
    for (int i = 1; i <= 1000000; i++)
    {
        if (prime[i])
        {
            F[i] = F[i - 1] + 1;
        }
        else
        {
            F[i] = F[i - 1];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << F[n] << endl;
    }

    return 0;
}
