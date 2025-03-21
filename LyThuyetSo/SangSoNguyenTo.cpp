#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Sang so nguyen to - thuat toan giup ktra nhan so nguyen to => Nhanh hon thang kiem tra nt thong thuong

int primer[10000001]; // 0 -> 10000001 : Danh dau + Truy xuat xem so tu 0 den 10000001 co phai so nguyen to hay khong

// Buoc 1 : Coi tat ca cac so tu 0 - > n la cac so nguyen to
// Buoc 2 : Sang, loai dan cac so khong phai so nguyen to
// 1 số là bội của 1 số nguyên tố => không phải là số nguyên tố
// VD : Boi cua 2 la 4 6 8 10 ... khong phai so nguyen to

// Luu y : Ko the sang so nguyen to den 10^9, n <= 10^7
void sang()
{
    for (int i = 0; i <= 1000000; i++)
    {
        primer[i] = 1;
    }
    primer[0] = 0;
    primer[1] = 0;

    // Loai bang vong lap
    for (int i = 2; i <= sqrt(1000000); i++)
    {
        if (primer[i] == 1)
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                primer[j] = 0;
            }
        }
    }
}

int main()
{
    sang();
    for (int i = 0; i <= 10000; i++)
    {
        if (primer[i] == 1)
        {
            cout << primer[i] << endl;
        }
    }
    return 0;
}