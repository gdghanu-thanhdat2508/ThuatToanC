#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Trong lớp học có n bạn nam và m bạn nữ.
// Các bạn nam có chiều cao là a1, a2, ..., an. Các bạn nữ có chiều cao là b1, b2, ..., bm.
// Nhân dịp lễ tổng kết cuối năm, cả lớp dự định tổ chức buổi khiêu vũ nhưng có điều kiện
// là trong một đôi khiếu vũ bát ky, bạn nam phải cao hơn bạn nữ. Và mỗi bạn không tham gia quả 1 doi khieu vu
// Hay tinh so luong cap doi nhieu nhat thoa man yeu cau tren

// Co the dung 2 con tro

// Nam : 1 3 7 8 9 14
//  Nu : 3 5 8 9 22 24
// Sap xep nam tang dan va nu giam dan, va su dung 2 chi so i va j (2 con tro)
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    int i = 0, j = 0, cnt = 0;

    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            ++cnt;
            ++i;
            ++j;
        }
        else
        {
            // ban nam thap hon hoac cho cao bang ban nu => Bo ban nam do di
            ++i;
        }
    }
    cout << cnt << endl;

    return 0;
}