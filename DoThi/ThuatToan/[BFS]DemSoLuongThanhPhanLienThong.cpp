#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector<int> ke[1005];
int n, m;
int visited[1005];

void nhap() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(),ke[i].end());
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);

    visited[u] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        // Do something  
        for(int y : ke[x]) {
            if(!visited[y]) {
                q.push(y);
                visited[y] = 1;
            }
        }
    }
}

int main() {
    //Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số thành phần liên thông của đồ thị.
    
    nhap();
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++cnt;
            BFS(i);
        }
    }
    cout << cnt << endl;

    return 0;
}
