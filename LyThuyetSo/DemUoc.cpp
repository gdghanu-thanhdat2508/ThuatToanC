#include <bits/stdc++.h>
using namespace std;

int demUoc(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ++cnt;
            if (i != n / i)
            {
                ++cnt;
            }
        }
    }
    return cnt;
}