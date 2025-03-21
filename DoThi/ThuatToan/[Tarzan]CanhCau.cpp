#include <bits/stdc++.h>
using namespace std;


int n, m, timer = 0;
vector<int> ke[1005];
int visited[1005], disc[1005], low[1005];
int ans = 0;

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
}

void DFS(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;


    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v, u);
            low[v] = min(low[v], low[u]);
            if(low[v] > disc[u]) {
               ++ans; 
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    // Canh cau : 
    // disc[u] < low[v]
    //
    // Khong co dau = xau ra trong TH nay 

    nhap();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i, -1); 
        }
    }
    cout << ans << endl; // Dem xem co bao nhieu canh cau 
    return 0;
}
