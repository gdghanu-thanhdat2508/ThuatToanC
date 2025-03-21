#include <bits/stdc++.h>
using namespace std;

bool soHoanHao(int n)
{
    long long tong = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            tong += i;
            if (i != n / i)
            {
                tong += n / i;
            }
        }
    }
    if (tong - n == n)
    {
        return true;
    }
    else
        return false;
}