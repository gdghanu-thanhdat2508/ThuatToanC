#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//  Cho 2 số nguyên L, R, hãy đếm xem trong đoạn từ L tới R có bao nhiêu số nguyên tố.
//  Gợi ý :
//  • Bước 1 : Sàng số nguyên tố
//  • Bước 2: Gọi F[i] là số các nguyên tố từ 0 tới i, khi đó số các số nguyên tố từ L tới R là F[R] - F[L - 1]

const int maxn = (int)1e6;

int prime[maxn + 1];
int F[1000001];
void sang()
{
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
        int l, r;
        cin >> l >> r;
        if (l == 0)
        {
            cout << F[r] << endl;
        }
        else
        {
            cout << F[r] - F[l - 1] << endl;
        }
    }
    return 0;
}