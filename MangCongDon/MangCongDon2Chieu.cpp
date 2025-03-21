#include <bits/stdc++.h>
using namespace std;

// Mảng cộng dồn trên mảng hai chiều:
// Đối với mảng 2 chiều, khi muốn tính tổng các phần tử trong phạm vi của 1 hình chữ nhật có N hàng và M cột
// bạn cần lặp qua N hàng mỗi hàng duyệt qua M cột để tính tổng, độ phức tạp sẽ là O(N*M).

// Mảng cộng dồn trên mảng 2 chiều, giả sử mảng 2 chiều của bạn có n hàng và m cột.
// Bạn cần tính tổng các phần tử trên HCN con bắt đầu từ hàng 1 tới hàng a và từ cột 1 tới cột b:

// prefix[i]lj] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j]

// input
// 8 8
// 1 1 0 0 0 1 1 1
// 1 0 0 0 1 1 1 1
// 0 1 1 1 0 0 1 0
// 1 1 1 1 0 1 1 0
// 1 1 1 1 1 0 1 1
// 1 0 0 1 0 1 0 1
// 0 0 0 0 1 0 1 0
// 1 1 0 0 0 1 0 1
// 3
// 2 3 1 7
// 2 2 2 7
// 1 2 1 8

// output
// 8
// 3
// 10

int a[1005][1005];
int n, m;
long long prefix[1005][1005];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // Xay dung prefix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    }
// Tai lai luu hang 1 va cot 1 Vi neu tinh tu hang 0 va cot 0 thi khi tinh no se truy cap vao i - 1 va j - 1 rat nhieu
    int q;
    cin >> q;
    while (q--)
    {
        int h1, h2, c1, c2;
        cin >> h1 >> h2 >> c1 >> c2;
        cout << prefix[h2][c2] - prefix[h1 - 1][c2] - prefix[h2][c1 - 1] - prefix[h1 - 1][c1 - 1] << endl;
    }

    return 0;
}
