#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;


int n, m;
set<int> ke[1005];
int visited[1005];
vector<pair<int,int> > dscanh;
void nhap() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dscanh.push_back({x, y});
        ke[x].insert(y);
        ke[y].insert(x);
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
            DFS(v);
        }
    }
}

int main() {
    //Cạnh cầu: Những cạnh khi loại bỏ nó (chỉ
    // • loại bỏ cạnh, không loại bỏ 2đỉnh) làm •
    // tăng số thành phần liên thông của đồ thị.
    

    //Để kiểm tra cạnh cầu bằng thuật toán DFS
    // hoặc BFS cần độ phức tạp là O(E * (E + V)),
    // bạn cần gọi E lần thuật toán DFS hoặc BFS.


    // De xoa 1 canh ra khoi do thi : Xoa x khoi danh sanh ke cua y va xoa y ra khoi danh sach ke cua x
    // Sau do dung xong thi them nguoc lai

    nhap();
    int cnt = 0; 
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i);
            ++cnt;
        }
    }
    int cau = 0;
    for(pair<int, int> it : dscanh) {
        int x = it.first, y = it.second;

        //Tuong duong voi viec xoa di canh x y
        ke[x].erase(y);
        ke[y].erase(x);
        
        int dem = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                ++dem;
                DFS(i);
            }
        }

        ke[x].insert(y);
        ke[y].insert(x);

        if(dem > cnt) {
            ++cau;
        }
    }

    return 0;
}
