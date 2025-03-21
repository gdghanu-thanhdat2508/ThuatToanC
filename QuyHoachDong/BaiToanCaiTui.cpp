#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// B14

// Một tên trộm có 1 cái túi có thể mang các đố vật với trọng lượng tối đa là V.
// Hiện tại tên trộm muốn lựa chọn các đồ vật trong N đồ vật để ăn trộm,
// mỗi đồ vật có trọng lượng là w[i] và giá trị là v[i].
// Hãy xác định tổng giá trị lớn nhất của các đồ vật mà tên trộm này lựa chọn
// sao cho trọng lượng của chúng không vượt quá V.

// Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng W. Sau đó là một dòng ghi N số của mảng v.
// V<=1000; N≤1000; 1<=w[i], c[i]<=500;

//  6 22
//  39 44 4 59 91 70
//  47 26 92 33 6 69

//  92

// Su dung mang 2 chieu
// Tien hanh lua chon tuong do vat 1
// F[i][j] = luu gia tri lon nhat cua cai tui sau khi chon i do vat dau tien
// Trong luong ko duoc vuot qua j
// Duyet qua 1 do vat, 2 lua chon : + Chon do vat va dua vao trong tui va + kHong dua vao trong tui

// + Neu Khong dua vao trong tui => F[i][j] = F[i - 1][j] (Ko chon do vat thu i)
// + Neu dua do vat thu i vao tui => F[i-1][[j - w[i]] => Xem gia tri bang bao nhieu sau do + V[i] so sanh F[i][j]
// Xem co lon hon ko

// Bai toan co so : F[0][j] = 0 va F[i][0] => Tui dang rong
// Xem xem tai trong cua tui co lon hon tai trong cua do vat hay khong

int F[1005][1005];
int n, V, w[1005], v[1005];
int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    // Vong for duyet do vat
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            F[i][j] = F[i - 1][j];
            if (j >= v[i])
            {
                // Update F[i][j]
                F[i][j] = max(F[i][j], F[i - 1][j - w[i]] + v[i]);
                // Lon hon thi cap nhat
            }
        }
    }
    cout << F[n][V] << endl;
    return 0;
}