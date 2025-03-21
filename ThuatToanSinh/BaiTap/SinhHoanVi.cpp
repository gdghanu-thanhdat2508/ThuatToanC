#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Sinh ra các hoán vị của các số tự nhiên từ 1 đến N
// n!

// VD : N = 4
// 1 2 3 4 -> Tang dan tu 1 den N
// 4 3 2 1 -> Giam dan tu N ve 1

// Thang dung truoc nho hon thang dung sau sao do hoan vi/doi cho
// ai < aj (i < j)
// Tim thang nho nhat ma lon hon a[i] de swap

int n, a[1005], final = 0;

void khoitao()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}

void sinh()
{
    // Buoic 1 : Di tim a[i] < a[i + 1] dau tien tinh tu ben phai
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1])
    {
        --i;
    }
    if (i == 0)
    {
        // Khong tim thay
        final = 1;
    }
    else
    {
        // B2 : Di tim a[j] nho nhat lon hon a[i] va dung ben phai a[i]
        int j = n;
        while (a[i] > a[j])
        {
            --j;
        }
        swap(a[i], a[j]);
        // B4 : Sap xep tang dan i + 1 -> n
        sort(a + i + 1, a + n + 1); // Sap xep tu i + 1 den chi so n
    }
}

int main()
{
    khoitao();
    while (final == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;

    // Ham : next_permutation(), prev_permutation()
}