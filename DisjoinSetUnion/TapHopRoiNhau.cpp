#include <bits/stdc++.h>
using namespace std;


int n, m;
int parent[1005];

void init() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i; // n thang thi dai dien cua no la chinh no
    }
}

int Find(int u) {
    // Di tim dai dien 
    while(u != parent[u]) {
        // Khi u != cha cua chinh no => Chua phai la dai dien
        u = parent[u];
    }
    return u;
}

// ham gop 
bool Union(int u, int v) {
    // Di tim nguoi dai dien chu u 
    u = Find(u);
    v = Find(v);
    if(u == v) {
        // Cung 1 tap hop => Khong phai lam cai j nua 
        return false; // Khong gop duoc
    }

    // Chon thang nho hon trong 2 thang de lam thang dai dien cho thang con lai
    if(u < v) parent[v] = u;
    else parent[u] = v;
    return true;
}


int main() {
    // Xau truc du lieu roi nhau - Disjoint Set Union 
    //  Union Find - DSU 
    //  Co the ap dung cho cac bai toan lien quan den tap hop / Do thi 
    //
    //  Giup bai toan : Cho mot tap hop cac phan tu, ban dau moi phan tu la mot tap hop rieng biet. 
    //  DSU cho phep gop 2 tap hon khac nhau hoac chi ra phan tu bat ky dang thuoc tap hop nao
    //
    //
    //  Union : gop
    //  Find : Tim (Tim thang dai dien cho nhom day)
    //      Neu khac dai dien thi co the gop voi nhau => Do thuoc 2 tap hop khac nhau
    //
    //  Co N dinh dung roi rac voi nhau, moi dinh tuong ung 1 tap hop/ Thanh phan lien thong
    //      Moi lan keo canh de ket noi 2 dinh lai voi nhau => Tao noi 1 thanh phan lien thong / 1 tap hop
    //          Check nhanh 1 dinh thuoc thanh phan lien thong thu may
    //          Gop 2 than phan lien thong voi nhau / gop 2 dinh lai voi nhau
    //  => Can nguoi dai dien
    

    return 0;
}
