#include <bits/stdc++.h>
using namespace std;
// Cho mảng số nguyên A[ gồm N phần tử, có Q truy vấn, mỗi truy vấn là 2 số L, R
// bạn hãy tính tổng các số từ chỉ số L tới chỉ số R của mảng.

// Moi truy van yeu cau tinh tong cac phan tu tu L sang R

// VD : 3 8 9 2 1 4 7 5
// L = 2, R = 5 => Tinh tong cac phan tu tu vi tri 2 den 5
// Xay dung mang cong don
// F[i] luu tong phan tu tu chi so 0 den chi so i cua mang a ban dau
// F : 3 11 20 22 23 27 34 39

// F[R] - F[L - 1]
// F[R] la toan bo tu chi so 0 den R = 27 (9 2 1 4)
// F[L - 1] chinh la 3 va 8
// Chi can lay 27 - 11 = 16

// Day la mang 1 chieu

int n, q, a[10000001];
long long F[10000001];
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Xay dung mang cong don F
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            F[i] = a[i];
        }
        else
        {
            F[i] = F[i - 1] + a[i];
        }
    }

    // Duyet Q truy van
    while (q--)
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