#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[100], final = 0;
void khoitao()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}

void sinh()
{
    int i = k;
    // Di tim phan tu dau tien tinh tu ben phai chua dat gia tri max
    while (i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    if (i == 0)
    {
        // Khi do bit tu 1 cho den k deu max => Cau hinh cuoi cung
        final = 1;
    }
    else
    {
        a[i]++;
        // i + 1 => k
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main()
{
    // VD :
    // n = 6
    // k = 4

    // To hop chap k luon dc luu tang dan
    // Cau hinh dau tien : 1 -> k
    // Cau hinh cuoi cung : k so cuoi cung , n - k + 1, n - k + 2,...

    // Cau hinh luon tang dan
    // i : n - k + i -> max i co the nhan

    khoitao();
    while (final == 0)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;
}