#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Sinh xau nhi phan bang bit

// Cac so tu nhien co dang 2^k => So nhi phan tuong ung chi co dung bit thu k la bit 1, con lai la bit 0

// Co gang phan tich tung bit 1 cua so do co dang nhi phan nhu nao

// And bit can tim voi bit 2^n => Khi ma ra 1 day nhi phan !=0 => Ta se biet dc bit thu n la 1 hay 0
// And so do voi 2^0, 2^1, ...

int main()
{
    int n = 6;
    for (int i = 0; i < (1 << n); i++)
    {
        // Phan tich tung bit 1 xem bit 0 hay bit 1 bang cach : And so do voi 2^0, 2^1, ...
        for (int j = n - 1; j >= 0; j--)
        {
            if ((i & (1 << j)) != 0)
            {
                cout << 1;
            }
            else
                cout << 0;
        }
        cout << endl;
    }
    // 1 << n -> 1 dich trai n bit
    // n >> 10 -> Dich phai 10 bit
    return 0;
}