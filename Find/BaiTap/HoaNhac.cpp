#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Có n vé xem hòa nhạc có sẵn, mỗi vé có một mức giá nhất định. Sau đó, m khách hàng lần lượt đến.
// Mỗi khách hàng thông báo mức giá tối đa mà họ sẵn sàng trả cho một vé và sau đó,
// họ sẽ nhận được một vé với mức giá gần nhất có thể sao cho không vượt quá mức giá tối đa.

// 5 3
// 5 3 7 8 5
// 4 8 3

// 3
// 8
// -1

int main()
{
    // Su dung multi set -> Co the luu tang dan -> Ap dung upper_bound -> Xoa phan tu cung don gian
    int n, m;
    cin >> n >> m;
    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = ms.upper_bound(x);
        // it tro vao ve nho nhat lon hon x
        // Dich sang trai se ra dc ket qua

        if (it != ms.begin())
        {
            --it;
            cout << *it << endl;
            ms.erase(it); // xoa 1 cai thoi
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}