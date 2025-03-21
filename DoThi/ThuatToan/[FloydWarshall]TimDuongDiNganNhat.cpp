#include <bits/stdc++.h>
using namespace std;

int Mat[1005][1005];
int n, m;

void nhap() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                Mat[i][j] = 0;
            } else {
                Mat[i][j] = 1e9;
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        Mat[x][y] = Mat[y][x] = w;
    }
}

void Floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                Mat[i][j] = min(Mat[i][j], Mat[i][k] + Mat[k][j]);
            }
        }
    }
}

int main () {

    // Thuat toan tim duong di ngan nhat den moi CAP DIEM tren do thi
    // Khác với thuật toán Dijkstra vs Bellman-Ford áp dụng để tìm đường đi ngắn nhất từ 1 đỉnh
    // tới mọi đỉnh còn lại trên đồ thị (SSSP - Single source shortest path),
    //
    // Floyd được áp dụng để tìm đường đi ngắn nhất giữa mọi cặp đỉnh trên đồ thị (All-pair Shortest Path).
    //
    // Thuật toán áp dụng cho đồ thị có hướng, vô hướng không có chu trình âm (có thể có cạnh âm).
    // Tim moi duong di ngan nhat sau do luu vao 1 cai ma tran    

    // Ap dung cho do thi V <= 400
    //
    // Duong di tu dinh i den dinh j voi k la trung gian
    //
    //
    // Bai toan : 
    // Cho đơn đồ thị vô hướng liên thông đị = (V, E) gồm N đỉnh và M cạnh, 
    // các đỉnh được đánh số từ 1 tới N và các cạnh được đánh số từ 1 tới M. Có Q truy vấn, 
    // mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X tới Y.
    
    nhap();
    Floyd();
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        cout << Mat[x][y] << endl;
    }
    return 0;
}
