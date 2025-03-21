#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Cho số tự nhiên N. Nhiệm vụ của bạn là hãy liệt kê tất cả các số có đúng ba ước số không vượt quá n.
// Ví dụ n=100, ta có các số 4, 9, 25, 49.

// So co dung 3 uoc la binh phuong cua 1 so nguyen to
int primer[10000001];
void sang()
{
    for (int i = 0; i <= 100000; i++)
    {
        primer[i] = 1;
    }
    primer[0] = 0;
    primer[1] = 0;

    // Loai bang vong lap
    for (int i = 2; i <= sqrt(100000); i++)
    {
        if (primer[i] == 1)
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                primer[j] = 0;
            }
        }
    }
}
int main()
{
    sang();
    ll n;
    cin >> n;

    for (int i = 1; i < sqrt(n); i++)
    {
        if (primer[i] == 1)
        {
            cout << 1ll * i * i << endl; // So uoc
        }
    }
    return 0;
}