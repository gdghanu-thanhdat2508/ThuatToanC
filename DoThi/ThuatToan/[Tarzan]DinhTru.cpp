#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int n, m, timer = 0;
vector<int> ke[1005];
int visited[1005], disc[1005], low[1005];
stack<int> st;
int AP[1005]; // Danh dau dinh tru , xem co dinh nao la dinh tru hay khong

void nhap() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;
    int cnt = 0; // Dem xem dinh u co bao nhieu dinh con voi no

    for(int v : ke[u]) {
        // 2 Truong hop : v chua duoc tham 
        if(!visited[v]) {
            ++cnt; // Moi lan dinh u di sang dinh v 
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(parent != -1 && low[v] >= disc[u]) { // Phai check xem u co phai dinh goc hay khong 
                AP[u] = 1; // Khi do chinh la dinh tru
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }

        // Truong hop quay lai thang cha 
        if(v == parent) {
            continue; // Do la do thi vo huong
        }
    }
    // Neu la goc thi phai dem xem no co bao nhieu thang con
    // Check dinh tru cho dinh goc cua loi goi ham DFS
    if(parent = -1 && cnt > 1) {
        // Dinh u la goc cua loi goi ham va SL con cua no > 1
        AP[u] = 1; 
    }
}

int main () {
    // Su dung thuat toan Tarzan de tim dinh tru
    //
    // Y tuong : 
    // Cho do thi G vo huong, tren do thi co 2 dinh U va V, giua U va V co duong di duyet theo DFS 
    // Neu ta co the di tu V den to tien A cua U ma khong can thong qua U => Do thi co canh nguoc
    // => Viec loai bo U ra khoi do thi khong lam tang thanh phan lien thong cua do thi 
    // Khi do U khong phai la dinh tru

    // Cach khong dung tarzan la cach code TRAU - Ngay tho => Can tim bang Tarzan 
    //
    // VD : 1 - 2 - 3
    // Xet canh 2 3 => Se so sanh Low[3], neu low[3] > disc[2] 
    //      low[3] the hien no co the quay lai dinh som la bao nhieu
    //          low[3] > disc[2] chung to la no khong the quay vong lai duoc som hon thang 2
    //          Khi do tat ca duong di tu 3 den to tien cua 2 deu phai di qua 2 
    //  Check xem thang 2 co phai dinh tru : Xem xem co duong nao ma 3 co the duoc som hon ma khong di qua 2 hay khong ? 
    //  Neu co => 2 ko phai dinh tru 
    //  Neu khong co => 2 la dinh tru
    //
    //  low[v] > disc[u] => u chinh la dinh tru
    // Dau = xay ra khi di u la goc cua 1 CHU TRINH  

    // 10 6
    // 5 4 
    // 5 2
    // 10 2
    // 10 7
    // 5 3
    // 10 1

    nhap();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i, -1); // Chi can goi 1 lan thuat toan DFS 
        }
    }

    int dem = 0;
    for(int i = 1; i <= n; i++) {
        if(AP[i] == 1) dem++;
    }
    cout << dem << endl;

    return 0;
}
