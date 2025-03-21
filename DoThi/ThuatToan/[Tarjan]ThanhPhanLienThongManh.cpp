#include <bits/stdc++.h>
using namespace std;
// NEU DE BAI YEU CAU TIM THANH PHAN LIEN THONG MANH : Dung Kosaraju

// Co the dung cho do thi co huong va vo huong 
// Neu la co huong thi can in_stack con vo huong thi khong can
int n, m , timer = 0, SCC = 0;
vector<int> ke[1005];
int visited[1005], disc[1005], low[1005];
bool in_stack[1005];
stack<int> st;

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
    memset(visited, 0, sizeof(visited));
    memset(in_stack, false, sizeof(visited));
}

void DFS(int u) {
    ++timer;
    //Moi bat dau thi disc = low = timer sau do se cap nhap dan
    disc[u] = low[u] = ++timer;
    st.push(u);
    visited[u] = 1;
    in_stack[u] = true; // Duy tri xem thang nao con dang trong ngan xep 
    // Vi chi co the cap nhap cho nhung thang con dang trong ngan xep
    // The hien no co mau xam hay khong ? chung ta chi xet lai gia tri voi node co mau xam 

    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
            low[u] = min(low[u], low[v]);
            // Cap nhap low cua thang dang truoc theo thang dang sau
        } else if (in_stack[v]){
            // Trong truong hop v da duoc tham va con nam trong stack (Mau xam)
            low[u] = min(low[u], disc[v]); // Cap nhap lai cai node mau xam do 
        }
    }
    if(disc[u] == low[u]) {
        // Khi disc == low thi chung to co 1 thanh phan lien thong manh
        // Do khong the nao quay vong lai duoc 
        ++SCC;
        while(st.top() != u) {
            cout << st.top() << " "; // IN ra dinh dau cua thanh phan lien thong manh
            in_stack[st.top()] = false;
            st.pop();
        } 
        cout << st.top() << endl;
        in_stack[st.top()] = false;
        st.pop();
    }
}
int main() {
    // Thuat toan Tarjan :
    //      Tim thanh phan lien thong manh
    //      Tim dinh tru 
    //      Tim canh cau
    //
    //  O(V + E) - Chi ton 1 lan thuat toan DFS -> da co the liet ke cac thanh phan lien thong manh thay vi 2 lan nhu Kosaraju
    //  Gom 2 mang : disc[] va low[] 
    //      disc[u] - chi ra thoi gian bat dau tham dinh u theo DFS
    //      low[u] - Chi ra thoi gian tham som nhat cua 1 dinh co the di toi duoc tu 1 cay con co goc la u
    //              disc cua cac o gan no ma nho nhat, se gan gia tri do cho low[u]
    //      Gap lai to tien cua no thi cap nhap

    //input 
    //7 8 
    //1 2
    //2 3 
    //3 1 
    //3 4 
    //4 5
    //5 6
    //6 7
    //7 5

    nhap();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i);
        }
    }
    cout << SCC << endl;
    return 0;
}
