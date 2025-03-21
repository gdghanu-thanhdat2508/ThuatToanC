#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho xâu F được định nghĩa như sau : F(1) = "28tech", F(2) = "C++", F(3) = "DSA JAVA".
// F(N) = F(N -3) + "+ F(N -2) + "' + F(N - 1).
// Vì thế F(4) = "28tech C++ DSA JAVA", F(5) = "C++ DSA JAVA 28tech C++ DSAJAVA".
// Nhiệm vụ của bạn là tìm từ thứ K trong xâu F(N), dữ liệu đảm bảo xâu F(N) có từ thứ K

// Cho 2 so n va k => IN ra tu thu k trong xau s[n]

// Chia xau Fibo thanh 3 phan

ll F[100];

string Find(int n, int k)
{
    if (n == 1)
        return "28tech";
    if (n == 2)
        return "C++";
    if (n == 3)
    {
        if (k == 1)
        {
            return "DSA";
        }
        else
        {
            return "JAVA";
        }
    }

    if (k <= F[n - 3])
    {
        return Find(n - 3, k);
    }
    else if (k <= F[n - 2] + F[n - 3])
    {
        return Find(n - 2, k - F[n - 3]);
    }
    else
    {
        return Find(n - 1, k - F[n - 3] - F[n - 2]);
    }
}

int main()
{
    F[1] = 1;
    F[2] = 1;
    F[3] = 2;

    for (int i = 4; i <= 60; i++)
    {
        F[i] = F[i - 1] + F[i - 2] + F[i - 3];
    }
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << Find(n, k) << endl;
    }
    return 0;
}