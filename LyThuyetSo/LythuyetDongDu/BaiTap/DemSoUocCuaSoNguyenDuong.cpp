#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Cho phân tích thừa số nguyên tố của một số nguyên dương N, hãy đếm số lượng ước số của số nguyên dương đó.
// Ví dụ N = 60 = 2^2 * 3^1 * 5^1.

// In ra số lượng ước số của N, vì kết quả quá lớn, hãy lấy dư với số 1000000007 (1e9 + 7)
ll mod = (ll)1e9 + 7;
int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        ans *= (y + 1) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}