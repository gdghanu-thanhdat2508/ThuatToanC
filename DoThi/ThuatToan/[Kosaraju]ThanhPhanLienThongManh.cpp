#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<int> ke[1005], t_ke[1005];
int visited[1005];
int degree[1005];
stack<int> st;


void nhap() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        t_ke[y].push_back(x); // Tao do thi lat nguoc - t_ke la danh sach ke cua do thi lat nguoc
        // Ban dau la u -> v 
        // Lat nguoc lai la v -> u
    }
    memset(visited, 0 , sizeof(visited));
}

void DFS(int u) {
    visited[u] = 1;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
    st.push(u);
}

void DFS2(int u) {
    cout << u << " ";
    visited[u] = 1;
    for(int v : t_ke[u]) {
        if(!visited[v]) {
            DFS2(v);
        }
    }
}



int main() {

    // neu giua 2 dinh bat ky cua do thi co duong di => Do thi do duoc goi la lien thong manh 
    // Neu do thi khong lien thong manh, se chia ra cac thanh phan lien thong manh (SCC)
    // Thanh phan lien thong manh la thanh phan lien thong lon nhat ma giua 2 dinh cua no deu co duong di
    
    // Thuat toan Kosaraju : 
    //      O(2V + E)
    //      Do ap dung 2 lan thuat toan DFS
    //  3 buoc chinh : 
    //  B1 : Tao ngan xep rong, luu lai thu tu sap xep TOPO cua do thi
    //  B2 : Lat nguoc tat cac do thi ban dau : Tao ra do thi chuyen vi (Transpose Graph)
    //  B3 : Lan luot lay cac dinh o trong ngan xep (TOPO), moi lan gap dinh o trong ngan xep, se lay ra va goi 
    //  thuat toan DFS tren do thi chuyen vi (Transpose graph)
    //
    //  6 14
    //  3 4
    //  3 1 
    //  2 5 
    //  2 6
    //  4 6
    //  2 3
    //  5 6
    //  1 5
    //  1 2 
    //  3 5
    //  4 5
    //  6 3
    //  4 2 
    //  1 4

    // Output : 1
    
    nhap();
    // Lay thu tu sap xep topo
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i);
        }
    }
    memset(visited, 0, sizeof(visited));
    int dem = 0;
    while(!st.empty()) {
        int s = st.top();
        st.pop();
        if(!visited[s]) {
            // Neu chua visit thi s nay se la dinh dau cua 1 thanh phan lien thong manh
            DFS2(s);
            ++dem;
        }
        cout << endl;
    }
    if(dem == 1) cout << "Do thi lien thong manh" << endl;
    else cout << "Do thi khong lien thong manh" << endl;

    return 0;
}
