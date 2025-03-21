#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1005];
int visited[1005], degree[1005];
stack<int> st;

void nhap() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        degree[y]++;

    }
    memset(visited, 0, sizeof(visited));
}

void BFS() {
    queue<int> q;
    for(int i = 1; i <= n;  i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        //Xoa dinh u ra khoi hang doi
        for(int v : ke[u]) {
            //Giam ban bac vao cua v
            degree[v]--;
            if(degree[v] == 0) {
                q.push(v);
            }
        }
    }
    for(int x : topo) {
        cout << x << " ";
    }
}
int main() {
    //Thua toan sap xep Topo voi BFS (Thuat toan Kahn, thuat toan xoa dan dinh)
    //
    //B1 : Tính bán bậc vào (Số cạnh đi vào đỉnh) của đồ thị 
    //B2 :  Lọc ra các đỉnh có bán bậc vào là 0
    //      Bán bậc vào = 0 thể hiện rằng nó sẽ xuất hiện đầu tiên trong sắp xếp TOPO
    //
    //B3 : Tạo ra Hàng đợi vào đẩy các thằng bán bậc vào = 0 vào hàng đợi trước 
    //B4 : Sau khi lấy ra, sẽ xoá nó đi khởi đò thị, sau đó giảm bán bậc vào của thằng kế tiếp vì đã xoá đi thằng đứng trước 

    // Co huong va khong co chu trinh
    // Co the ap dung cho bai toan xem xem co phai la 1 chu trinh hay khong

    nhap();
    BFS();
    return 0;
}
