#include <bits/stdc++.h>

using namespace std;


int n, m;
vector<int> ke[1005];
int visited[1005];
vector<pair<int, int> > dscanh;

void nhap() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        ke[x].push_back(y);
        ke[y].push_back(x);

        memset(visited, 0, sizeof(visited));

        for(int i = 1; i <= n; i++) {
            sort(ke[i].begin(), ke[i].end());
        }
    }
}

void DFS(int u, int s, int t) {
    //s va t tuong ung canh ma muon xoa ra khoi do thi
    //Neu check dc 2 node ma muon xoa la canh can xoa thi khong mo rong nua => Loai bo canh do ra khoi do thi
    visited[u] = true;
    for(int v : ke[u]) {
        if((u == s && v == t) || (u == t && v == s)) {
            // Co nghia la : dang chuan bi mo rong thong qua canh ma chung ta muon loai bo khoi do thi 
            continue; // Khong xet
        }
        if(!visited[v]) {
            DFS(v, s , t);
        }
    }
}

int main() {
    nhap();

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++cnt;
            DFS(i, -1 , -1); // Khong loai bo canh nao
        }
    }

    int cau = 0;
    for(pair<int, int> it : dscanh) {
        int x = it.first, y = it.second;
        int dem = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                ++dem;
                DFS(i , x , y);
            }
        }
        if(dem > cnt) ++cau;
    }
    return 0;
}
