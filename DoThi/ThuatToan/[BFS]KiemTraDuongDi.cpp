#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;


int n, m, dem = 0;
vector<int> ke[1005];
int visited[1005];

int tplt[1005]; //tplt[i]

void nhap() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, 0 , sizeof(visited));

    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        tplt[x] = dem;


        //Do smthg with x

        for(int y : ke[x]) {
            if(!visited[y]) {
                q.push(y);
                visited[y] = 1;
            }
        }
    }
}

int main() {
    //Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. 
    //Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?
    nhap();
    //tplt[x] là mảng đánh dấu thành phần liên thông của mỗi đỉnh. 

    //📌 Ban đầu, tất cả các đỉnh chưa được gán thành phần liên thông (tplt[x] chưa có giá trị).
    //📌 Khi duyệt đồ thị bằng BFS, ta gán tplt[x] = dem, với dem là chỉ số của thành phần liên thông hiện tại.
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++dem; // Tang bien dem de bieu dien co thanh phan lien thong moi
            BFS(i);
        }
    }

    int q; cin >> q;
    while(q--) {
        int s, t; cin >> s >> t;

        if(tplt[s] == tplt[t]) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}





