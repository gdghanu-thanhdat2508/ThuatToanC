#include <bits/stdc++.h>
using namespace std;

// Tèo đang làm các bài toán với truy vấn tổng trên đoạn, mỗi truy vấn yêu cầu các bạn tính tổng các phần tử từ
// chỉ số L tới chỉ số R, tuy nhiên bài toán này đã quá quen thuộc và dễ dàng có thể dùng mảng cộng dồn để giải
// quyết vì thế To đưa ra thêm 1 yêu cầu cho bài toán.
// Cho trước các truy vấn tổng từ chỉ số L tới chỉ R, bây giờ bạn đã biết trước tất cả Q truy vấn bạn được phép
// thay đổi thu tự các phần tử trong mảng 1 lần duy nhất trước khi thực hiện các truy vấn. Hãy thay đổi mảng
// sao cho tổng các truy vấn trên đoạn đạt được giá trị lớn nhất. Một cách rõ ràng hơn, bạn hãy tính tổng mọi
// mảng con trong từng truy vấn sau đó cộng lại để đạt được giá trị lớn nhất.

// Input
// 6 2
// 5 2 5 3 5 1
// 2 5
// 2 4

// Output
// 33
#define ll long long;
int n, q, a[1000005];
long long D[1000005];
long long F[1000005];

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // Truy van cac phan tu l den r
        --l, --r;
        D[l] += 1;
        D[r + 1] -= 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            F[i] = D[i];
        else
            F[i] = F[i - 1] + D[i];
        cout << F[i] << " "; // Cho biet moi phan tu duoc truy van bao nhieu lan
    }
    sort(a, a + n);
    sort(F, F + n); // Dua phan tu co gia tri lon ve voi phan tu co truy van nhieu lan

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1ll * a[i] * F[i];
    }
    cout << ans << " ";
    return 0;
}