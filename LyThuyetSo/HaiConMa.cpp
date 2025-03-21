#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Đếm số cách đặt 2 con mã trên bàn cờ vua cỡ k x k với k = 1, 2, 3, .. n sao cho chúng không ăn nhau, 2 con mã
// này được coi là giống nhau.
int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        ll K = k * k;
        cout << K * (K - 1) / 2 - 4 * (k - 1) * (k - 2) << endl;
    }
    cout << " Hello world " << endl;
    return 0;
}
