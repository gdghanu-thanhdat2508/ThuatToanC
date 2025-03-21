

// Cho mảng A[] gồm N phần tử. Sắp xếp sao cho số có nhiều chữ số 0, 6 hoặc 8 hơn đứng trước,
// nếu có cùng số lượng chữ số 0 6 8 thì sp nào nhỏ hơn sẽ đứng trước

#include <bits/stdc++.h>
using namespace std;

int dem(int n)
{
    if (n == 0)
        return 1;
    int ans = 0;
    while (n != 0)
    {
        int r = n % 10;
        if (r == 0 || r == 6 || r == 8)
        {
            ++ans;
        }
        n /= 10;
    }
}

bool cmp(int a, int b)
{
    if (dem(a) != dem(b))
    {
        return dem(a) > dem(b);
    }
    return a < b;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int &x : a)
    {
        cin >> x;
    }
    sort(a, a + n, cmp);

    for (int x : a)
    {
        cout << x << " ";
    }
    return 0;
}