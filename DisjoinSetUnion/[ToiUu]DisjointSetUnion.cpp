#include <bits/stdc++.h>
using namespace std;

// Toi uu nen duong
// Trong qua trinh di tim dai dien , cac dinh tren duong di ay se thay dai dien thanh 1 het
// Khi tim duong dai dien cho cac buoc sau se ngan hon

int n, m;
int parent[1005], sz[1005];
// sz[i] : Luu so phan tu thuoc tap hop ma i lam dai dien

void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1; // Tat ca dai dien cho chinh no nen chi co 1
    }
}

int Find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = Find(parent[u]);
    // VD : find(6) ma parent cua 6 la 5
    // => parent[6] = Find(5);
    // De quy cho den khi u == parent[u]
    // => Sau khi ra = 1 la Parent roi thi gan nguoc lai cho tat cac cac node con
    // => Sau do khi find se mat it thoi gian hon
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return false;
    // Toi uu : Xem xem tap hop nao co nhieu phan tu hon => Lam sao cho it thang thay doi thang dai dien nhat
    if (sz[u] < sz[v])
    {
        parent[v] = u;
        // Sau khi gop voi nhau thi size 1 trong 2 se duoc bo sung
        sz[u] += sz[v];
    }
    else
    {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}

int main()
{
    return 0;
}
