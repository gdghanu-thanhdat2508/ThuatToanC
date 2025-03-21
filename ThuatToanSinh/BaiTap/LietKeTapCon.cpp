#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho một tập gồm N phần tử được đánh số từ 1 đến N.
// Nhiệm vụ của bạn là liệt kê tất cả các tập con khác rống của N theo thứ tự từ điển tăng dần.

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res;
    for (int i = 1; i < (1 << n); i++)
    {
        //(1 << n) -> 2^n
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            // Generate 2^n de end voi ma nhi phan n
            // VD : 2^0 -> 000000001
            if ((i & (1 << j)) != 0)
            {
                tmp.push_back(j + 1);
            }
        }
        res.push_back(tmp);
    }
    sort(res.begin(), res.end());
    for (auto it : res)
    {
        for (int x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}