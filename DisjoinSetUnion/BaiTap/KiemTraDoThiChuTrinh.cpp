#include <bits/stdc++.h>
using namespace std;
// CHI AP DUNG CHO DO THI VO HUONG

int n, m;
int parent[1005];

void init() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int Find(int u) {
    while(u != parent[u]) {
        u = parent[u];
    }
    return u;
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(u < v) {
        parent[v] = u;
    } else {
        parent[u] = v;
    }
    return true;
}

int main() {
    // Khi gop 2 dinh voi nhau thong qua canh cua do thi ma no khong gop dc 

    cin >> n >> m;
    init();
    bool check = false;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; 
        if(Union(x, y) == false) {
            // Co chu trinh
            check = true;
        }
    }
    if(check) cout << "YES" << endl;
    else cout << "NO";
    return 0;
}
