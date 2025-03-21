#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột.
// Một con chuột bắt đầu tử ô (1, 1) và muốn di chuyển tới ô (N, N).
// Con chuột chỉ được di chuyển sang trái, sang phải, lên trên và xuống dưới và chỉ được di chuyển tới ô nào đó
// nếu ô đó có giá trị là 1. Bạn hãy in ra các cách đi hợp lệ của con chuột, trong đó nếu con chuột đi sang phải
// thì nước đi được mô tả là chữ R, và nếu con chuột đi xuống dưới thì nước đi được mô tả là chữ D,
//  nếu đi sang trái thì nước đi được mô tả là chữ L, nếu đi lên trên thì nước đi được mô tả là chữ U.
// Nếu con chuột không khể đi xuống ô (N, N) thì in ra - 1.
//  Chú ý trên mỗi đường đi con chuột chỉ có thể đi qua 1 ô nào đó đúng 1 lần.

int n, a[100][100], check = 0;
string s = "";

pair<int, int> path[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

string S = "DLRU";

void Try(int i, int j) // Tuong tu maze 1
{
    if (i == n && j == n)
    {
        cout << s << endl;
        check = 1; // Kiem tra xem con chuot co di duoc den dich hay khong
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int i1 = i + path[k].first;
        int j1 = j + path[k].second;

        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1)
        {
            s += S[k]; // Do phai if else nhieu | hoac la if else 4 lan
            a[i1][j1] = 0;
            Try(i1, j1);
            s.pop_back();
            a[i1][j1] = 1;
        }
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