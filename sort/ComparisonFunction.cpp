#include <bits/stdc++.h>
using namespace std;

// Comparison function - cung cap tieu chi sap xep theo tieu chu cua minh
// True : Neu muon a dung truoc b sau khi sap xep
// False : Neu muon a dung sau b sau khi sap xep

// B1 : Minh muon sap xep mang cua minh nhu the nao
// B2 : Suy luan a nhu the nao se dung truoc b sau khi sap xep
// B3 : Kiem tra dieu kien B2 => True

int tong(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

bool cmp(int a, int b)
{
    // if (a < b)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    if (tong(a) < tong(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a[] = {999, 31, 10001, 20, 939, 1191, 223, 501};

    int n = 8;
    sort(a, a + n, cmp);

    for (int x : a)
    {
        cout << x << " ";
    }
    return 0;
}