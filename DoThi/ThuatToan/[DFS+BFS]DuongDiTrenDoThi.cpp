#include <bits/stdc++.h>
using namespace std;


int n, m, s, t; // Số đỉnh, số cạnh, đỉnh bắt đầu, đỉnh kết thúc
vector<int> ke[1005];
int visited[1005];
int parent[1005];

void nhap() {
    cin >> n >> m >> s >> t;

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}

void DFS(int u) {
    visited[u] = 1;
    for(int v : ke[u]) {
        if(!visited[v]) {
            parent[v] = u; // Ghi nhan xem thang nao mo rong thang nao
            DFS(v);
        }
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;

    while(!q.empty()) {
        int x = q.front(); q.pop();

        for(int y : ke[x]) {
            if(!visited[y]) {
                q.push(y);
                parent[y] = x;
                visited[y] = 1;
            }
        }
    }
}

int main() {
    //Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. 
    //Hãy tìm đường đi theo thuật toán
    //DFS từ đỉnh s tới đỉnh t. Trong qúa trình mở rộng của thuật toán DFS, luôn ưu tiên mở rộng đỉnh có số thứ tự nh hơn.
    //Tim duoc duong thi in ra 1 khong thi in ra -1
    
    //Dòng đầu tiên là 4 số n, m, s, t, tương ng với số lượng đỉnh, cạnh củađồ thị, đỉnh bắt đầu và đỉnh kết thúc.
    //Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với
    //một cạnh của đồ thị.

    // 5 3 4 3
    // 4 2 
    // 2 1 
    // 3 1 
    //
    // Output 
    // 4 2 1 3
    nhap();
    DFS(s); //BFS(s)
    if(!visited[t]) {
        cout << "-1" << endl;
    } else {
        vector<int> res;
        // Truy vết ngược từ t về s
        while(t != s) {
            res.push_back(t);
            t = parent[t]; // Lat nguoc lai cha cua thang t cho den 1 muc nao do se dung 
            
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        // Do res hiện tại chứa đường đi theo thứ tự ngược (t → s), ta cần đảo ngược lại để có s → t.

        for(int x : res) {
            cout << x << " ";
        }
    }
    return 0;
}
