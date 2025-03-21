#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột.
// Một con chuột bắt đầu tử ô (1, 1) và muốn di chuyển tới ô (N, N).
// Con chuột chỉ được di chuyển xuống dưới hoặc sang phải và chỉ được di chuyển tới ô nào đó nếu ô đó có giá trị là 1.
// Bạn hãy in ra các cách đi hợp lệ của con chuột, trong đó nếu con chuột đi sang phải thì nước đi được mô tả là chữ R,
// và nếu con chuột đi xuống dưới thì nước đi được mô tả là chữ D.
// Nếu con chuột không thể đi xuống ô (N, N) thì in ra -1.
// Chú ý trên mỗi đường đi con chuột chỉ có thể đi qua 1 ô nào đó đúng 1 lần.

// 4
// 1 1 0 1
// 1 1 1 1
// 1 0 1 1
// 1 1 1 1

// DDDRRR
// DRRDDR
// DRRDRD
// DRRRDD
int n, a[100][100], check = 0;
string s = "";

void Try(int i, int j)
{
    if (i == n && j == n)
    {
        cout << s << endl;
        check = 1; // Kiem tra xem con chuot co di duoc den dich hay khong
        return;
    }

    // Xet 2 nhanh
    if (i + 1 <= n && a[i + 1][j] == 1)
    {
        s += "D";
        a[i + 1][j] = 0; // Da di qua o do roi
        Try(i + 1, j);   // Gi tiep tuc de nhay xuog do duoi
        s.pop_back();    // Sau khi di xong thi phai xoa di (Backtracking) - tai vi neu try co the di sang 1 huong khac
        // Giup khi quay lui lai de tim 1 duong moi, no se khong bi cong don vao s
        a[i + 1][j] = 1; // Tra nguoc lai gia tri o ma da di qua
    }
    if (j + 1 <= n && a[i][j + 1] == 1)
    {
        s += "R";
        a[i][j + 1] = 0;
        Try(i, j + 1);
        s.pop_back();
        a[i][j + 1] = 1;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1, 1);
    if (check == 0)
    {
        cout << "-1 \n";
    }
    return 0;
}