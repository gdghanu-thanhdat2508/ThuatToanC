#include <bits/stdc++.h>
using namespace std;



int n, m;
vector<int> ke[1005];
int visited[1005];
stack<int> st;

void nhap() {
    cin >> n >> m;

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

void DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
    st.push(u); // Sau khi duyet xong va day ra khoi ngan xep
    // Chung ta nem no vao stack de luu ket qua 
}

int main() {
    //Sắp xếp topo áp dụng cho đồ thị có hướng không
    // có chu trình (DAG - Directed Acyclic Graph) là một thứ tự của các đỉnh sao cho với mọi cạnh u -> v thì u
    // sẽ xuất hiện trước v trong thứ tự topo. Một đồ thị có
    // thể tồn tại nhiều thứ tự topo khác nhau.

    //Sắp xếp topo sử dụng DFS dựa trên thứ tự khi duyệt xong một đỉnh của đồ thị, 
    //khi một đỉnh được duyệt xong ta đẩy đỉnh này vào trong ngăn xếp.  
    // Thứ tự sắp xếp topo chính là các đỉnh nằm trong ngăn xếp tính từ đỉnh.

    // Do thi co huong va khong co chu trinh (Khong co canh quay lai)
    // Sap xep theo huong di chuyen cua do thi 
    
    // Thang nao duoc duyet sau trong DFS thi se dung o cuoi TOPO
    // Su dung ngan xep de luu 

    // Ap dung vao bai toan sap xep cong vieng
    nhap();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i);
        }
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
