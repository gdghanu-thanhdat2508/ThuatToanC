#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Ngân hàng XYZ hiện có N tờ tiền có mệnh giá khác nhau được lưu vào mảng CU, bạn hãy tìm cách đổi số tiền là S
// sao cho số tờ tiền cần dùng là ít nhất. Bạn được sử dụng một mệnh giá không giới hạn số lần.

//  3 10
//  4 5 8

//  2

// Khong dung duoc tham lam

// F[i] - can toi thieu bao nhieu dong xu de tao ra so tien la i

// Bai toan co so : F[0] = 0

// Xet to tien thu nhat truoc
// S = 9
// 2 3 7
// F[i] = 0 1 2 3 4 5 6 7 8 9
// F[0] = 0
// Xet thang 2 do di
// Ban dau F[i]= INT_MAX
// F[i - c] - danh sach dong coin duyet qua

// Lap bang gia tri F[i]

// Neu F[i - c] (c-la gia tri dong coin dang xet) = vo cung thi khong cap nhat

// In ra F[S]
int main()
{
    int n, S;
    cin >> n >> S;
    int c[n];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int F[S + 1];
    memset(F, 0, sizeof(F));
    F[0] = 0;
    for (int i = 1; i <= S; i++)
    {
        F[i] = 1e9;
        for (int coin : c)
        {
            if (i >= coin)
            {
                F[i] = min(F[i], F[i - coin] + 1);
            }
        }
    }

    if (F[S] == 1e9)
    {
        cout << "-1 \n";
    }
    else
    {
        cout << F[S] << endl;
    }
    return 0;
}