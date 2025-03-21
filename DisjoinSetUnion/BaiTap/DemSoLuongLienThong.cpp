#include <bits/stdc++.h>
using namespace std;

// Ban dau se la n dinh rieng le voi nhau
// Do thi cho 1 canh tuc la dang gop 2 dinh do lai voi nhau de tao thanh 1 thanh phan lien thong
//
// Neu gop duoc thi giam thanh phan lien thong di 1 - nguoc lai khong giam
//
// Sau khi nhap danh sach canh
// Nhanh hon BFS + DFS
int n, m;
int parent[1005];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}

int Find(int u)
{
    while (u != parent[u])
    {
        u = parent[u];
    }
    return u;
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if (u == v)
        return false;

    if (u < v)
        parent[v] = u;
    else
        parent[u] = v;

    return true;
}

int main()
{
    // Dem so luong lien thong bang Disjoint set onion

    cin >> n >> m;
    init();
    int cnt = n;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (Union(x, y))
        {
            // Neu tra ve true => Co the gop dc 2 dinh x y
            // Lam giam so luong tplt cua do thi
            --cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
