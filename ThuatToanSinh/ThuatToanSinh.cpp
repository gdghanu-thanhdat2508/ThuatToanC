#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Thuật toán sinh là một phương pháp vét cạn được dùng với các bài toán liệt kê hoặc đếm cấu hình,
// thỏa các yêu cầu sau:
// Xac dinh duoc cau hinh dau tien va cai hinh cuoi cung
// Tim duoc thuat toan de cau hinh hien tai sinh ra cau hinh ke tiep

// Cac bai toan pho bien
// Lien ke xau nhi phan
// Liet ke hoan vi
// Liet ke tap con
// Sinh phan hoach

// <Buoc 1>
// Khoi tao cau hinh dau tien

// <Buoc 2> Lap
// while(<Cau hinh chua phai cau hinh cuoi cung>) {
//  <Dua ra cau hinh hien tai>
//  <Sinh ra cau hinh ke tiep>
// }
//  <Dua ra cau hinh cuoi cung>

// VD : Bai Toan Sinh xau nhi phan
// a[1], a[2],... a[n] : Bit tu 1 den n cua mang a
int n, a[100], final = 0;

void khoitao()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}

void sinh()
{
    // Di tu phai sang trai - bat dau tu bit cuoi cung
    // Gap bit 1 thi Chuyen sang 0
    // Con neu gap bit 0 dau tien thi chuyen sang 1 va dung vong lap
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        a[i] = 1;
    }
}

int main()
{
    khoitao();
    while (final == 0)
    {
        // in ra cau hinh hien tai
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << endl;
        }
        // thuat toan sinh de sinh ra cau hinh ke tiep
        sinh();
    }
    return 0;
}