#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Hãy xem xét một hệ thống tiền tệ của ngân hàng XYZ bao gồm n đồng xu.
// Mỗi đồng xu có một giá trị nguyên dương. Nhiệm vụ của bạn là tính số cách riêng biệt mà bạn có thể tạo
// ra số tiền x bằng cách sử dụng số xu có sẵn. Ví dụ: nếu số xu là (2,3,5) và tổng mong muốn là 9,
// có 8 cách: 2 +2 +5;2 +5 + 2;5 + 2 + 2;3 + 3 + 3;2 +2 +2 +3;2+2+3+2;2+3+2+2;3+2+2+2;

// In ra kết quả lấy dư với 10^9 + 7
int coin[105];
ll F[1000001];
int n, S;

int main()
{
    cin >> n >> S;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    F[0] = 1;
    for (int i = 1; i <= S; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= coin[j])
            {
                F[i] += F[i - coin[j]];
                F[i] %= 1000000007;
            }
        }
    }
    cout << F[S] << endl;
    return 0;
}