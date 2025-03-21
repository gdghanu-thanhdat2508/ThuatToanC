#include <bits/stdc++.h> 
using namespace std;
 
// Thuat Toan tim kiem theo chieu sau
// Giong thuat toan loan 
// Tu 1 dinh se di het cac dinh chung thanh phan lien thong voi no 
// Giup tu 1 dinh di tham het tat ca cac dinh lien thong voi no 

// Giai thuat de quy 
// Thuat toan DFS

// Ma Gia : 
// void DFS(u) {
//  <Tham dinh u>
//  visited[u] = true // Danh dau la da tham u 
//  // Duyet danh sach ke cua u 
//  for(int v : adj[u]) {
//      if(!visited[v]) {
//          DFS(v);
//      }
//  }
// }
//
// Do phuc tap 
// O(V + E) neu su dung danh sach ke 
// O(V * V) neu su dung ma tran ke 
// O(V * E) neu su dung danh sach canh


//Cho đò thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy thực hiện in ra danh sách các đỉnh
// đợc duyệt theo thuật toán DFS(5).

// Liet ke cac dinh 

// input 
// 5 5 3
// 5 2
// 3 2
// 5 4
// 5 3
// 5 1

int n, m, s;
vector<int> ke[1005];
int visited[1005];

// n - đỉnh m - cạnh  

void nhap() {
    cin >> n >> m >> s;
    
    //Lặp theo m do có m cạnh thì sẽ có m cặp (a, b)
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    //Sắp xếp danh sánh kề của mỗi đỉnh theo chiều tăng dần 
    //Do chúng ta muốn duyệt theo đỉnh nhỏ nhất trước 
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}
void DFS(int u) {
    cout << u << " ";
    visited[u] = 1;
    for(int v : ke[u]) {
        if(visited[v] == 0) {
            DFS(v);
        }
    }
}


int main() {
    nhap();
    DFS(s);

    return 0;
    // Neu la do thi co huong thi khac moi cho khong co liet ke 2 lan
}
