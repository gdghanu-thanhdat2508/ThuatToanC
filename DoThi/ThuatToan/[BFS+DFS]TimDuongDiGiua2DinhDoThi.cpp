#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int n, m, dem = 0;
vector<int> ke[1005];
int visited[1005];
int tplt[1005]; // Thanh phan lien thong

void Nhap() {
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

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        tplt[x] = dem;
        
        for(int y : ke[x]) {
            if(!visited[y]) {
                q.push(y);
                visited[y] = 1;
            }
        }
    }
}

int main() {
    //Xem xem Tu dinh A co di qua duoc dinh B hay khong ? 
   
    int q; cin >> q;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++dem;
            BFS(i);
        }
    }

    while(q--) {
        int d, t; cin >> d >> t;
        if(tplt[d] != tplt[t]) {
            cout << "Khong co duong di" << endl;
        } else {
            cout << "Co duong di" << endl;
        }
    }

    return 0;
}
