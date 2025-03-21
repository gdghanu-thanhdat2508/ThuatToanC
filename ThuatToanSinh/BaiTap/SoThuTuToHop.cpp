#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho 2 số nguyên dương N và K và một tổ hợp K phần tử của tập N phần tử các số từ 1 tới N.
// Bạn hãy xác định xem tổ hợp đã cho có số thứ tự bao nhiêu nếu xếp các tổ hợp chập K của N theo thứ tự ngược.
// Ví dụ N = 5, K = 3 và tổ hợp đã cho là (2, 3, 4) sẽ là tổ hợp có số thứ tự 4.

// 12 4
// 8 9 10 11

// 5

int n, k, a[1005], final = 0, X[100];

void khoitao()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> X[i];
        a[i] = i;
    }
}

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
    {
        --i;
    }

    if (i == 0)
    {
        final = 1;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main()
{
    // Sinh ra cau hinh sau do so voi cau hinh da cho

    khoitao();
    int stt = 0;
    while (final == 1)
    {
        ++stt;
        // So sanh cau hinh vua moi sinh duoc voi cau hinh trong mang x
        bool check = true;
        for (int i = 1; i <= k; i++)
        {
            if (a[i] != X[i])
            {
                check = false;
            }
        }
        if (check = true)
        {
            cout << stt << endl;
            return 0;
        }
        cout << endl;
        sinh();
    }
    return 0;
}