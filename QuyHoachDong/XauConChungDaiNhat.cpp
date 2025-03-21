#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho 2 xâu kí tự S và T, hãy tìm xâu con chung dài nhất của S và T.
// Các kí tự của xâu con không nhất thiết phải liền kề nhau.

// ZHFTDFHF
// TFTSHROV

// 3

// F[i][j] - i ky tu dau tien xau S va j ky tu dau tien cua xau T
// = Xem xem F[i][j] co do dai la bao nhieu

// Dap an la F[n][m] - n la so luong ky tu cua xau F va m la so luong ky tu cua xau S

// Bai toan co so : F[0][j] -> KO chon ky tu nao xau thu nhat, F[i][0] -> KO chon ky tu nao xau thu 2

// F[i][j] : Xac dinh ky tu o chi so i va j bang nhau

// Neu khac nhau : chon F[i][j - 1] hoac F[i - 1][j] - Xem xem thang nao do do dai lon hon thi ghep cho F[i][j]

// So sanh chi so i - 1 va j - 1
int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    // Bo sung 1 ky tu vao xau s va t de ve sau co the truy cap vao chi so 1 trong xau
    s = " " + s;
    t = " " + t;

    int F[n + 1][m + 1];
    for (int i = 0; i <= m; i++)
    {
        F[0][i] = 0; // hang dau tien
    }
    for (int i = 0; i <= n; i++)
    {
        F[i][0] = 0; // Cot dau tien
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                // Neu khong them ky tu dau tien thi phai xet s[i - 1] va t[j - 1]
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else
            {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            }
        }
    }
    cout << F[n][m] << endl;
    return 0;
}