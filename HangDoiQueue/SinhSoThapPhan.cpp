#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int n)
{
    queue<string> q;
    q.push("1");
    int ans = 0;
    while (!q.empty())
    {
        string x = q.front();
        q.pop();
        cout << x << " ";
        ++ans;
        if (ans == n)
        {
            break;
        }
        q.push(x + '0');
        q.push(x + '1');
    }
}
int main()
{
    // Queue co the sinh ra cac so tu cac so cho truoc

    // VD : cho 2 so 6 va 8 => Sinh ra cac so co 6 va 8

    // Sau do cho 6 va 8 vao hang doi
    // Lay 6 ra -> Them 8 va 6 vao sau -> 66 68 ..

    // Giong voi thuat toan BFS
    // Tat ca cac so se tang dan tu be den lon

    // BAI TAP
    // In ra tat ca cac so nhi phan tu 1 -> n  va khong in thua cac bit 0 o dau

    // Bat dau tu so 1, moi buoc se nem so 0 va so 1 vao dang sau
    // 1 -> 10 11 -> 100 111 101 ,...

    // CO THE THAY THE CHO THUAT TOAN SINH

    int n;
    cin >> n;
    solve(n);
    return 0;
}