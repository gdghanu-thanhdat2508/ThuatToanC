#include <bits/stdc++.h>
using namespace std;


int n, m, ans = 0;
int parent[100005], sz[100005];

void init() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u) {
    if( u == parent[u]) {
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
    if(sz[u] > sz[v]) {
        parent[v] = u; 
        sz[u] += sz[v];
        ans = max(ans, sz[u]);
    } else {
        parent[u] = v;
        sz[v] += sz[u];
        ans = max(ans, sz[v]);
    }
    return true;
}

int main() {
    //có n thành phố và ban đầu không có đường giữa chúng. Tuy nhiên, mỗi ngày một con đường
    // mới sẽ được xây dựng và sẽ có tổng cộng m con đường. Một cụm thành phố là một nhóm các thành phố trong
    // đó có một tuyến đường giữa hai thành phố bất kỳ bằng cách sử dụng các con đường. Sau mỗi ngày, nhiệm vụ
    // của bạn là tìm ra số lượng cụm thành phố và kích thước của cụm thành phố lớn nhất.

    // Dòng đầu tiên có hai số nguyên n và m: số thành phố và đường. Các thành phố được đánh số 1,2...., n. Sau đó,
    // có m dòng mô tả các con đường mới. Mỗi dòng có hai số nguyên a và b: một con đường mới được xây dựng
    // giữa các thành phố a và b. Bạn có thể cho rằng mọi con đường sẽ được xây dựng giữa hai thành phố khác
    // nhau

    // 5 3
    // 1 2
    // 1 3
    // 4 5
    
    // 4 2
    // 3 3
    // 2 3

    cin >> n >> m;
    init();

    int cnt = n;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        cnt -= (int)Union(x, y); // Neu true -1 false khong tru 
    }
    cout << cnt << " " << ans << endl;

    return 0;
}
