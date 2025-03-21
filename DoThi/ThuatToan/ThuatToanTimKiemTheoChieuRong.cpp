#include <bits/stdc++.h>
#include <cstring>
using namespace std;
// Thuat toan BFS - Tim Kiem theo Chieu Rong

vector<int> ke[1005];
int n, m, s;
int visited[1005];

void nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}


void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()) {
        int x = q.front(); // Lay phan tu dau tien tu hang doi nhung khong xoa luon
        q.pop(); // Xoa phan tu vua lay ra khoi hang doi
        cout << x << " ";
        // Duyet danh sach ke cua x 
        for(int y : ke[x]) {
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    // Do phuc tao giong voi DFS 
    // Pho bien nhat : Dung danh sach ke 
    // Y tuong : Sẽ xét những đỉnh gần đỉnh gốc trước 
    // Khác với DFS là đi theo 1 đường sau đó quay về và đi đường khác 
    // Xét những điểm cách điểm gốc 1 cạnh -> 2 cạnh -> 3 cạnh -> ...
    // Đi từng nấc từng nấc 1 
    // Để duy trì xem thằng nào gần thằng gốc nhất thì BFS sử dụng HÀNG ĐỢI 
    //
    //  Thuật toán BFS trên đồ thị vô hướng sẽ tạo ra được đường đi ngắn nhất 
    // Ví dụ 
    // BFS(u) {
    //  queue = rỗng;
    //  push(queue, u);
    //  visited[u] = true;
    //
    //  while(queue != 0) {
    //      v = queue.front();
    //      queue.pop():
    //      <Thăm đỉnh v>
    //      // Duyệt tất cả đỉnh kề với đỉnh v mà chưa được đẩy vào hàng đợi 
    //      for(int x : ke[v]) {
    //          if(!visited[x]) {
    //              push(queue, x);
    //              visited[x] = true;
    //          }
    //      }
    //  }
    // }
    // Thằng nào chưa thăm thì ném vào hàng đợi

    
    // Cho do thi vo huong, sau do in ra cac dinh duoc duyet thong qua thuat toan BFS
    // 5 7 5
    // 4 1 
    // 5 3
    // 4 3 
    // 5 1 
    // 3 2 
    // 4 2 
    // 2 1 
    //
    nhap();
    BFS(s);
    
    return 0;
}
