// Cho số nguyên n
// , đếm số cách tạo ra tổng n
//  bằng cách tung xúc xắc 6
//  mặt, số của mỗi lần tung sẽ được cộng vào tổng.

#include <bits/stdc++.h>
#define MOD 1000000007
#define maxn 1000006

int f[maxn];
using namespace std;
int main()
{
    int n;
    cin >> n;
    f[0] = 1; // TH co so
    for (int s = 1; s <= n; s++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= s)
            {
                f[s] = (f[s] + f[s - j]) % MOD;
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}