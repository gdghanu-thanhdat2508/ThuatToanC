#include <bits/stdc++.h>
#include <cmath>
using namespace std;


// 1 Cay co n dinh voi dieu kien la co n - 1 canh 
// Cay thi se khong co chu trinh 
// Tat ca dinh tren cay do phai ket noi voi nhau
//
// Kiem tra do thi co phai la 1 tree hay khong ? 
// 
// => Check 2 dieu kien :
//      Co dung n - 1 canh 
//      Phai lien thong voi nhau 
//      Khong co chu trinh
//

int n, m;
vector<int> ke[1005];
int visited[1005];

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

void DFS(int u) {
    visited[u] = 1;

    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

int tplt() {
    int ans = 0; 
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++ans;
            DFS(i);
        }
    }
    return ans;
}


int main() {
    nhap();

    if(tplt() == 1 && m == n - 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
