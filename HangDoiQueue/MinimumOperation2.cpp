#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef pair<int, int> ii;

int solve(int s, int t)
{
    queue<ii> q;
    q.push({s, 0});
    set<int> used;
    used.insert(s);

    while (!q.empty())
    {
        ii x = q.front();
        q.pop();
        if (x.first == t)
        {
            return x.second;
        }
        if (used.count(x.first - 1) == 0 && x.first - 1 > 0)
        {
            q.push({x.first - 1, x.second + 1});
            used.insert(x.first - 1);
        }
        for (int i = 2; i <= sqrt(x.first); i++)
        {
            if (x.first % i == 0)
            {
                int res = max(i, x.first / i);
                if (used.count(res) == 0)
                {
                    q.push({res, x.second() + 1});
                    used.insert(res);
                }
            }
        }
    }
    return -1;
}
int main()
{
    // Cho so thu nhien va 2 phep bien doi A va B : A -> Lay n - 1
    // B -> n = max(u,v) neu u * v = n, u && v != 1
    // Tim thao tac it nhat de bien doi so n thanh 1

    int T;
    cin >> T;
    while (T--)
    {
        int s;
        cin >> s;
        cout << solve(s, 1) << endl;
    }
    return 0;
}