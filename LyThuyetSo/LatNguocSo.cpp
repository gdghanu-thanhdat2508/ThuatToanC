#include <bits/stdc++.h>
using namespace std;

int latnguocso(int n)
{
    int temp = 0;
    while (n != 0)
    {
        temp = temp * 10 + (n % 10);
        n /= 10;
    }
    return temp;
}

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    long long tmp = 0;
    int tmp2 = x;
    while (x != 0)
    {
        tmp = tmp * 10 + (x % 10);
        x /= 10;
    }
    if (tmp != tmp2)
    {
        return false;
    }
    return true;
}