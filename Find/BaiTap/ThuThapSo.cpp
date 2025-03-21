#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Bạn được cung cấp một mảng chứa mỗi số từ 1... n đúng một lần. Nhiệm vụ của bạn là thu thập các số từ 1.
// đến n theo thứ tự tăng dần.Trên mỗi vòng, bạn đi qua mảng từ trái sang phải và thu thập càng nhiều số càng tốt.
// Tổng số vòng sẽ là bao nhiêu ?

// 5
// 4 2 1 5 3
int pos[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
