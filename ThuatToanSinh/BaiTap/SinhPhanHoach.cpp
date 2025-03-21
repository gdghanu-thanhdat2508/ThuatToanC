#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// In ra các cách phân tích N dưới dạng tổng các số tự nhiên nhỏ hơn hoặc bằng N không xét đến thứ tự.

// VD :
// 5
// 4 + 1
// 3 + 2
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1

// Cau hinh dau tien : N
// Cau hinh cuoi cung : N so 1

int n, cnt, a[1005], final = 0;
void khoitao()
{
    cin >> n;
    cnt = 1; // cnt de dem xem trong phan hoach do co bao nhieu phan tu
    // De biet xem cau hinh cua chung ta co bao nhieu so hang
    a[1] = n;
}

void sinh()
{
    // Di tim so hang dau tien tu ben phai != 1
    int i = cnt;
    while (i >= 1 && a[i] == 1)
    {
        --i;
    }
    if (i == 0)
    {
        final = 1;
    }
    else
    {
        --a[i];
        // Tinh xem con thieu bao nhieu -> Bieu dien thong qua a[i]
        int d = cnt - i + 1;         // i la so luong so 1 ma ta bo qua => Ra 4 so 1 sau do + 1 do giam a[i] 1 don vi
        cnt = i;                     // reset so luong so hang ve i
        int q = d / a[i];            // So con thieu gap may lan a[i]
        int r = d % a[i];            // So du
        for (int j = 1; j <= q; j++) // viet q lan so a[i] vao dang sau
        {
            ++cnt;
            a[cnt] = a[i];
        }
        if (r != 0)
        {
            // Neu co so du thi phai bo sung so du vao cuoi
            ++cnt;
            a[cnt] = r;
        }
    }
}

int main()
{
    khoitao();
    while (!final)
    {
        for (int i = 1; i <= cnt; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }

    return 0;
}
