#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Có N nhóm hạt ngũ cốc được đánh số từ 1 tới N mỗi nhóm sẽ có lượng hạt ngũ cốc là A[i] với 1<=i<=N,
// một con sóc đang ở vị trí nhóm hạt số 1. Nhiệm vụ của nó là tới được nhóm hạt thứ N,
// chi phí mỗi lần di chuyển từ nhóm hạt x sang nhóm hạt y là abs(A[x] - A[y]),
// mỗi lần di chuyển con sóc chỉ có thể di chuyển từ nhóm hạt i sang nhóm hạt i + 1 hoặc i + 2,... i + K.
// Nhiệm vụ của bạn là tính số lượng ngũ cốc tối thiểu mà con sóc này phải tiêu tốn để có thể đi đến nhóm hạt thứ N

// 5 3
// 5 1 1 4 7

int main()
{
    int n, k;
    int a[n];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll F[n];

    F[0] = 0;

    for (int i = 1; i < n; i++)
    {
        F[i] = LLONG_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                F[i] = min(F[i], F[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }
    cout << F[n - 1] << endl;
    return 0;
}