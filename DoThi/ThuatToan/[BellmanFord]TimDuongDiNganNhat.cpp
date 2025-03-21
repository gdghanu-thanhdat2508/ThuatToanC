#include <algorithm>
#include <bits/stdc++.h>
#include <sys/wait.h>
using namespace std;

struct edge
{
    int x, y, w;
    // x : Dinh cuat phat
    // y : dinh dich
    // w : trong so
};

int INF = (int)1e9;
int n, m, s;
vector<edge> dscanh; // Danh sách các cạnh của đồ thị.
int d[1005];    // Mang luu khoang cach tu dinh xuat phat den cac dinh khac

void nhap()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        dscanh.push_back((edge){x, y, w});
        dscanh.push_back((edge){y,x,w}); // Cho do thi vo huong
    }
}

void BellmanFord(int s)
{
    for(int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    d[s] = 0;              // Khoang cach tu dinh xuat phat den chinh no = 0

    // Cap nhap khoang cacnh
    for (int i = 1; i <= n - 1; i++)
    { // n - 1 vi thuat toan chi can lap n - 1 canh
        for (edge e : dscanh)
        { // xet cac canh - thu tu nao cung duoc
            int u = e.x, v = e.y, w = e.w;
            if (d[u] < INF)
            {
                // Da tim duoc duong di
                // d[u] : Khoảng cách ngắn nhất từ đỉnh xuất phát s đến đỉnh u tính đến thời điểm hiện tại.
                // d[v] : Khoảng cách ngắn nhất từ đỉnh xuất phát s đến đỉnh v tính đến thời điểm hiện tại.
                d[v] = min(d[v], d[u] + w);
                // v la dinh dich cua do thi

            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}
int main()
{
    // Bellman-Ford được sử dụng đề tìm đường đi ngắn nhất từ 1 đỉnh tới mọi đỉnh còn lại trên đồ thị,
    // khác với Dijkstra thì Bellman-Ford có thể áp dụng cho đồ thị với cạnh có trọng số âm,
    // Thuật toán này có thể sử dụng để xác định rằng đồ thị có chu trình âm. -> Tuc la 1 chu trinh khep kin ma
    //   tong cua cac trong so cua cac canh ra so am
    //
    // Y tuong :
    //   Ban dau ta su dung moi mang d[] de luu khoang cach tu dinh nguon s toi moi dinh con lai tren do thi, d[s] = 0
    //   va d[u] = INF(Largest number) voi moi dinh u con lai tren do thi
    //   Thuat toan lap n - 1 buoc, moi buoc se xet tat cac cac cap canh (u, v) co trong so w.
    //   Neu d[v] > d[u] + w thi se cap nhap d[v]
    //   Moi lan lap se xet tat ca cac dinh u cung 1 luc

    // Update theo thu tu canh
    nhap();
    BellmanFord(s);
    return 0;
}
