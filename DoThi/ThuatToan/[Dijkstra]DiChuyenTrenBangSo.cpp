#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, m, s;
vector<ii> ke[1005];
int d[1005][1005];
int a[1005][1005];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void nhap() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
}

void Dijkstra(int i, int j) {
    // i, j la o bat dau
    d[i][j] = a[i][j];
    priority_queue<iii, vector<iii>, greater<iii> > Q; // Luu khoang cach, hang va cot 
    // Hang doi Q co the sap xep cac o theo chi phi duong di 
    Q.push({d[i][j], {i, j}}); // Luu <khoang cach duong di, hang va cot>
    while(!Q.empty()) {
        iii tmp = Q.top();
        Q.pop();
        int dis = tmp.first;
        int u = tmp.second.first;
        int v = tmp.second.second; // Tu dinh nguon u den o i j 
        //(u, v) là tọa độ của ô đang được xét trong quá trình chạy thuật toán Dijkstra.
        if(dis > d[u][v]) { // d luu duong di chinh xac
            continue; //dis: Chi phí ngắn nhất đến ô (u, v).
            //d[u][v] lưu khoảng cách ngắn nhất từ ô (1,1) đến ô (u,v) trong ma trận.
        }
        // Tu cai o u,v se xet theo 4 o lien ke voi no
        for(int k = 0; k < 4; k++) {
            //u1 và v1 phải nằm trong lưới n x m
            int u1 = u + dx[k];
            int v1 = v + dy[k];
            //di chuyển từ ô (u, v) sang một ô lân cận (u1, v1) theo 4 hướng:
            if(u1 >= 1 && u1 <= n && v1 >= 1 && v1 <= m) {
                // Update 
                if(d[u1][v1] > d[u][v] + a[u1][v1]) {
                    //Chi phí đi từ (1,1) → (u1, v1) (đã biết trước đó)
                    //(d[u][v] + a[u1][v1]): Chi phí nếu đi qua (u, v)
                    //(d[u1][v1]): Chi phí hiện tại đến (u1, v1)
                    d[u1][v1] = d[u][v] + a[u1][v1];
                    Q.push({d[u1][v1], {u1, v1}});
                }
            }
        }
    }
    cout << d[n][m] << endl;
}

int main() {
    // Cho một bảng sô kích thước N x M. Chi phí khi đi qua ô (ij) băng A[][]. Nhiệm vụ cúa bạn là hãy tìm một
    // đường đi từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất. Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi
    // lên trên và xuống dưới.

    // 6 7
    // 0 3 6 0 5 9 1
    // 6 5 4 4 0 7 6
    // 4 0 2 1 5 6 1
    // 2 7 7 3 3 1 6 
    // 4 4 9 6 9 7 2 
    // 3 6 4 4 1 9 2
    //
    // 28

    // Di theo 4 huong -> Khong the ap dung QHD

    nhap();
    Dijkstra(1,  1);

    return 0;
}
