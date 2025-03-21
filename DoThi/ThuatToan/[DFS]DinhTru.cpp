#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


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
        
        memset(visited, 0, sizeof(visited));

        for(int i = 1; i < n; i++) {
            sort(ke[i].begin(), ke[i].end());
        }
    }
}

void DFS(int u) {
    visited[u] = 1;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}


int main() {
    // Đỉnh trụ: Là đỉnh khi loại bỏ đỉnh này và các cạnh liên thuộc voi
    // đỉnh này sẽ làm tăng số thành phần liên thông của đồ thị.
    //
    // Để kiểm trađỉnh trụ bằng thuật toán DFS
    // hoặc BFS cần độ phức tạp là O(V * (E + V)), bạn cần gọi V lần thuật toán DFS hoặc BFS.
    
    // Co nghia la neu xoa di 1 dinh tru thi se lam tang thanh phan lien thong len

    // Xet tung dinh 1 tren do thi va thu loai bo no di khoi do thi 
    // Sau do so sanh voi thanh phan lien thong ban dau voi sau khi bo dinh di xem co khac nhau hay khong

    // De co the loai bo 1 dinh nao do ra khoi do thi : Chi visted cua no = 1 , khi do no se khong xet thang visited = 1
    // => Da loai bo duoc 1 dinh trong do thi 


    //Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy đếm số lượng đỉnh trụ của đồ

    nhap();
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i);
            ++cnt;
        }
    }
    int tru = 0;
    for(int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int dem = 0;
        visited[i] = 1; // Loai bo i ra khoi do thi
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                DFS(i);
                ++dem;
            }
        }
        if(dem > cnt) {
            // Lam tang so luong thanh phan lien thong
            ++tru;
        }
    }
    cout << tru << endl;
    

    return 0;
}
