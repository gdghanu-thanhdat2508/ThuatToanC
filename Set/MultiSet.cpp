#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Multiset - tuong tu nhu set, nhung co the luu gia tri giong nhau

    multiset<int> se = {1, 2, 3, 4, 4, 5, 6, 7, 8};

    // Neu find ma co 2 so giong nhau thi se tra ve cai iterator cua thang dau tien

    auto it = se.find(4);

    cout << *it << endl;
    return 0;
}