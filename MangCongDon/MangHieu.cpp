#include <bits/stdc++.h>
using namespace std;
// Đặt vấn đề: Cho mảng A[] có N phần tử, có Q thao tác mỗi thao tác sẽ tăng các phần tử trong đoạn từ
// chỉ số L tới R của mảng A[] lên K đơn vị. Hãy xác định mảng A[] sau Q thao tác.

// VD : Update Operation
// Cho mảng số nguyên A gồm N phần tử, có Q thao tác, mỗi thao tác yêu cầu các bạn tăng tất cả các phần tử
// từ chỉ số L tới chỉ số R lên K đơn vị. Bạn hãy in ra mảng sau khi thực hiện các thao tác trên.

// Input
// 7 3
// 8 5 8 9 7 6 9
// 0 5 0
// 0 5 0
// 1 5 1

// Ouput
// 8 6 9 10 8 7 9

// Mang hieu giup cho cac bai toan update gia tri tu chi so L sang R len k don vi
// D[0] = A[0]
// D[i] = A[i] - A[i - 1]

// VD :
// A : 3 8 9 2 1 4 5
// D : 3 5 1 -7 -1 3 1 => Day la mang hieu

// l = 2
// A[2] = DO + D1 + D2
// A[3] = DO + D1 + D2 + D3
// A[4] = DO + D1 + D2 + D3 + D4 ...

// D[l] += k = D[2] += k => Tat ca deu tang len k don vi, anh huong tat ca A[] tro ve sau
// Tu chi so 2 tro di deu bi tang len k don vi het

int main()
{
    int n, q, a[1000001];
    long long D[1000005];
    long long F[1000005];
    cin >> n >> q;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Xay dung mang hieu
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            D[i] = a[i];
        }
        else
        {
            D[i] = a[i] - a[i - 1];
        }
    }
    // Neu tinh mang cong don cua mang hieu thi se quay lai mang a ban dau

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        // Cau lenh giup cap nhap
        // D[l] += k => Tat ca phan tu tu chi so l trong mang A deu dc tang len k don vi
        // Vi khi tinh mang cong don mang D se ra mang A ban dau
        // D[r + 1] -= k => Do tu R doi di chung ta ko muon tang nen phai - di k de khong bi thay doi
        D[l] += k;
        D[r + 1] -= k;
    }

    long long tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += D[i];
        cout << tong << " ";
    }
    return 0;
}