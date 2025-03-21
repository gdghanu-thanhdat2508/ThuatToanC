#include <bits/stdc++.h>
using namespace std;


int n, m, check = 0;
vector<int> ke[1005];
int visited[1005];
int parent[1005];

void nhap() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        ke[x].push_back(y);
        ke[y].push_back(x);

        memset(visited, 0, sizeof(visited));

        for(int i = 1; i <=n ;i++) {
            sort(ke[i].begin(), ke[i].end());
        }
    }
}

void DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        // u tham v , check xem u va v co phai canh nguoc hay khong
        if(visited[v] = 1 && v != parent[u]) {
            check = 1; // Ghi nhanh lai da co canh nguoc
        }
        if(!visited[v]) {
            parent[v] = u; // Cap nhap parents 
            DFS(v);
        }
    }
}


int main() {
    // Đế kiếm tra chu trình trên đồ thị ta
    // kiểm tra trên đồ thị có cạnh ngược
    // hay không.
    //
    // Chu trinh la duong di cho dinh dau va dinh cuoi giong nhau
    // Vong tron khep kin giua cac dinh 

    // u va v co phai canh nguoc khong ? Check 2 dieu kien
    //  int v : ke[u]
    //      + v -> da duoc tham (Visited)
    //      + v != parent[u]
    //
    //  Do thi vo huong != do thi co huong 
    //  Do thi vo hung thi BFS = DFS

    nhap();
    // Xet tat ca cac thanh phan lien thong 
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i);
        }
    }
    if(check) {
        cout << 1 << endl;
    } else cout << 0 << endl;
    return 0;
}
