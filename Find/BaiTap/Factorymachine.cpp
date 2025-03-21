#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//  Một nhà máy có n máy có thể được sử dụng để tạo ra sản phẩm. Mục tiêu của bạn là tạo ra tổng số sản phẩm.
//  Đối với mỗi máy, bạn biết số giây nó cần để tạo ra một sản phẩm. Các máy có thể hoạt động đồng thời và bạn
//  có thể tự do quyết định lịch trình của chúng. Thời gian ngắn nhất cần thiết để làm ra t sản phẩm là bao nhiêu?
//  (Gợi ý: Binary search on answer)

//  3 7
//  3 2 5

//  8
// Ky thuat tim thoi gian ngan nhat

ll f(int a[], int n, int k, ll time)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += time / a[i];
        if (ans >= k)
            break;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll left = 0, right = 1e18;
    ll ans = -1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (f(a, n, k, mid) >= k)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}