#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Sub set sum - chon tap con ma tong cua no = s
// Cho máng số nguyên All gồm N phân tứ và số nguyên dương S,
// nhiệm vụ cúa bạn hãy xác định xem có thê tạo ra một tập con các phần tử trong mảng có tổng bằng S hay không?
// Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.

// F[i] = 1 (Co the chon) / 0 (Khong the chon)

// F[s] == true => Co the tao ra tap con co tong = s

// Bai toan co so F[0] = 1

// S = 12
// A = {1,3, 7, 5}

// F[0, 1, 2, ... 12] (0 -> s)
// i: 0 1 2 3 4 5 6 7 8 9 10 11 12
// F: 1 0 0 0 0 0 0 0 0 0  0  0  0

// Xet : Xem xem co the su dung thang x trong A thi co the tao ra tong la bao nhieu
// Neu xet 1 thi chi can xet tong tu 12 do nguoc lai 1
// Neu xet 3 thu chi can xet tong tu 12 do nguoc lai 3
int main()
{
    int n, S;
    cin >> n >> S;
    int a[n];
    for (int &x : a)
    {
        cin >> x;
    }
    int F[S + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = S; j >= a[i]; j--)
        {
            if (F[j] - a[i] == 1)
            {
                F[j] = 1;
            }
        }
    }
    if (F[S] == 1)
    {
        cout << 1 << endl; // Co the tao ra 1 tap con co tong = S
    }
    else
    {
        cout << 0 << endl; // Khong the tao ra
    }
    return 0;
}