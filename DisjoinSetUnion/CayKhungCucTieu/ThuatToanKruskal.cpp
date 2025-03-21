#include <bits/stdc++.h>
using namespace std;

struct canh {
    int x, y, w; // 3 thong so : Dinh dau, dinh cuoi va trong so
};

int n, m;
int parent[10005], sz[10005];
vector<canh> dsCanh;
void init() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u) {
    if(u == parent[u]) {
        return u;
    }
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) {
        return false;
    }
    if(sz[v] > sz[u]) {
        parent[v] = u;
        sz[u] += sz[v];
    } else {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}

bool cmp(canh a, canh b) {
   return a.w < b.w; 
}
void Kruskal() {
    // B1 : Sap xep danh sach canh theo trong so tang dan
    sort(dsCanh.begin(), dsCanh.end(), cmp);
    // B2 : Chon cac canh tu ngan den dai, sao cho du n - 1 canh
    int d = 0;
    vector<canh> MST; // Luu canh cay khung
    for(int i = 0; i < m; i++) {
        if(MST.size() == (n - 1)) {
            break;
        }
        // Duyet cac canh sau do gop lai voi nhau
        if(Union(dsCanh[i].xm dsCanh[i].y)) {
            // Neu gop lai dc voi nhau => Khong tao duoc chu trinh => Cho dc vao cay khung
            MST.push_back(dsCanh[i]);
            d += dsCanh[i].w;
        }
    }
    if(MST.size() != n - 1) {
        cout << "IMPOSSIBLE" << endl;
        // Do thi khong lien thong 
    } else {
        cout << d << endl;
    }
}
int main() {
    // Y tuong thuat toan Kruskal : Sap xep cac danh sanh canh theo trong so tang dan, chon cac canh ngan nhat den canh dai nhat
    // sau do dua vao cay khung sao cho du n - 1 canh thi no dung
    // Neu cho vao cay khung ma tao thanh chu trinh thi se khong dua canh do vao cay khung
    //
    // KHONG DUOC TAO THANH CHU TRINH
    //


    // Bai tap : Sua duong 
    // có n thành phố và m đường giữa chúng. Thật không may, tình trạng của những con đường quá
    // kém nên chúng không thể được sử dụng. Nhiệm vụ của bạn là sửa chữa một số con đường để có một con
    // đường tốt giữa hai thành phố bất kỳ. Đối với mỗi con đường, bạn biết chi phí sửa chữa của nó và bạn nên tìm
    // giải pháp sao cho tổng chi phí càng nhỏ càng tốt.
    //
    //Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố được đánh số 1,2,..., n. Sau đó,
    // có m dòng mô tả các con đường. Mỗi dòng có ba số nguyên a, b và c: có một con đường giữa các thành phố a
    // và b, và chi phí sửa chữa của nó là c. Tất cả các con đường đều là đường hai chiều. Mọi con đường đều nằm
    // giữa hai thành phố khác nhau và có nhiều nhất một con đường giữa hai thành phố.
    //
    // 5 6
    // 1 2 3
    // 2 3 5
    // 2 4 2
    // 3 4 8
    // 5 1 7
    // 5 4 4 

    // 14
    
    // DO THI PHAI LIEN THONG THI MOI CO CAY KHUNG CUC TIEU
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        dsCanh.push_back({x, y, w});
    }
    Kruskal();

    return 0;
}
