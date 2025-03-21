#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Nguoi du lich
// Su dung quay lui - nhanh can

// Cho n thành phố đánh số từ 1 đến n và các đoạn đường hai chiều giữa chúng,
// chi phí đi lại giữa các thành phố này được cho bởi mảng 2 chiều CDI,
// trong đó C[i][j] = C[j][i] là chi phí đi đi từ thành phố i đến thành phố j.
// Chi phí giữa thành phố thứ i với chính nó là 0.

// Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại
// mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1.
// Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.

//  3
//  0 46 94
//  46 0 42
//  94 42 0
//  Duong 2 chieu => Ma tran doi xung

//  182

//  4
//  0 85 26 81
//  85 0 77 97
//  26 77 0 26
//  81 97 26 0

//  234
//  x1 = 1
//  x2 = 3
//  x3 = 4
//  x4 = 2
//  1 3 4 2 -> Thanh pho da di qua
//  MOI THANH PHO CHI DC DI QUA 1 LAN

int n, X[1000], ans = INT_MAX, sum = 0, cmin = INT_MAX;
int c[100][100];
int visited[100];
void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != 0)
            {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}

void Try(int i)
{
    for (int j = 1; j <= n; j++) // Chon 1 trong n thanh pho de xuat phat
    {
        // X[i] = j
        if (visited[j] == 0)
        {
            X[i] = j; // Luu lai thanh pho da di qua
            // Luot thu i di qua thanh pho co stt la j
            visited[j] = 1;
            sum += c[X[i - 1]][X[i]]; // mang c la mang luu gia tri cua tung thanh pho
            if (i == n)
            {
                // Tinh xem chi phi cuoi quay lai thanh pho dau tien
                ans = min(ans, sum + c[X[i]][1]);
            }
            else if (sum + (n - i + 1) * cmin < ans) // Nhánh cận
            {
                // Sum la luu quang duong tu 1 -> i
                // Con n - i + 1 doan duong chia di sau do nhan voi c min (Min value trong ma tran luu chi phi)
                // Danh gia xem neu try tiep thi co duoc dap an nho hon ans da luu hay khong
                Try(i + 1);
            }
            visited[j] = 0;
            sum -= c[X[i - 1]][X[i]]; // Backtrack ko di thanh pho do nua
        }
    }
}

int main()
{
    // X[i] = j
    // Thanh pho luot thu i di qua co so thu tu la j
    nhap();
    X[1] = 1; // Do dang dung o thanh pho dau tien
    visited[1] = 1;
    Try(2);
    cout << ans << endl;
    return 0;
}