#include <bits/stdc++.h>
#include <queue>
using namespace std;


typedef pair<int ,int> ii;

int n, m;
vector<ii> ke[1005];
int d[1005];

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y ,w; cin >> x >> y >> w;
        ke[x].push_back({y, w});
        ke[y].push_back({x, w}); // Neu la do thi vo huong thi bo cai nay di
    }
}

void Dijkstra(int s) {
    // Mang luu duong di 
    for(int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    d[s] = 0; // Duong di den chinh no 
    priority_queue<ii, vector<ii>, greater<ii> > Q; // Chon dinh co chi phi nho hon
    // vector<ii> là container chính của hàng đợi, dùng để lưu trữ các phần tử
    // greater<ii> giúp tạo hàng đợi ưu tiên nhỏ nhất (min-heap) thay vì mặc định là max-heap
    Q.push({0, s});
    while(!Q.empty()) {
        ii tmp = Q.top(); // Moi lan lay ra cap co chi phi nho nhat trong hang doi
        Q.pop();
        // First : Luu duong di, Second : Luu dinh
        int dis = tmp.first;
        int u = tmp.second;
        if(dis > d[u]) {
            continue; // Tai vi dis lon hon chi phi thuc te ma chung ta co
        }
        d[u] = dis; // Cap nhap
        for(ii it : ke[u]) {
            int v = it.first, w = it.second; // v -> dinh ke
            if(d[v] > d[u] + w) {
                // d[u] là khoảng cách ngắn nhất từ đỉnh nguồn đến đỉnh u
                // w la trong so cua canh u -> v
                // d[v] là khoảng cách hiện tại từ đỉnh nguồn đến v.
                // Nếu đi từ s → u → v ngắn hơn khoảng cách hiện tại đến v thì ta cập nhật d[v].
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}
int main() {
    // Thuật toán Dijkstra được sử dụng để tìm đường đi ngắn nhất từ 1 đỉnh tới mọi đỉnh còn lại trên đồ thị,
    // có thể áp dụng cho cả đồ thị có hướng và vô hướng không chứa trọng số âm.

    // Y tuong : Tap S chua tap cac dinh da tim duoc duong di ngan nhat tinh tu dinh nguon 
    //          Xet danh sach ke cua u : deu khoang canh tu nguon den v > duong di tu u sang v => Update
    //          Su dung hang doi uu tien Q, luu pair <chi phi duong di, dinh di kem> 
    //          Lay ra trong hang doi uu tien chi phi phai nho hon d - cai gia tri thuc te cua no
    //
    //      Ta su dung hang doi uu tien Q luu pair, voi first la luu khoang cach duong di ngan nhat tu dinh nguon
    //          va second luu dinh. Q se sap xep cac phan tu theo khoang cach duong di tang dan, neu 2 dinh co 
    //          cung khoang cach duong di thi luu theo dinh tang dan
    //      Ban dau Q chi bao gom cap {0, s} voi s la dinh bat dau cua thuat toan. Thuat toan se lap di lap lai cho 
    //          den khi Q con chua rong, moi lan lay ra cap (d, u) o dinh hang doi Q tuong ung voi dinh u la dinh co 
    //          duong di ngan nhat tinh tu dinh nguon s. Neu d > dist[u] voi dist[u] la khoang canh duong di ngan nhat 
    //          ghi nhan duoc cho dinh u thi ta se bo qua u 
    //      Khi dinh u duoc xet no se co gang cap nhap khoang cach nho nhat cho dinh v ke voi u, sau do tiep tuc day 
    //          dinh v va dist[v] vao hang doi, dieu nay co the dan den nhieu phien ban khac nhau cua cung 1 dinh voi
    //          khoang cach khac nhau trong hang doi. Tuy nhien, ta se luon chon phien ban co khoang cach ngan nhat de 
    //          xet truoc 

    // 6 9
    // 1 2 1 
    // 1 3 5
    // 2 5 1 
    // 2 2 2
    // 2 4 3
    // 3 4 2
    // 4 5 4 
    // 4 6 12
    // 5 6 7
    
    // 0 1 3 4 2 9
    nhap();
    Dijkstra(1);
    return 0;
}
