#include <bits/stdc++.h>
using namespace std;


struct canh {
    int x, y, w;
};


int n;
int a[1005][1005];

bool cmp(canh a, canh b) {
    if(a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}
int main() {

    //Cho đồ thị vô hướng G = được biểu diễn dưới ma trận trọng số Al, trong đó Afil] khác không có nghĩa có
    // cạnh nối giữa 2đỉnh i, j. Hãy chuyển đồ thị đã cho thành danh sách cạnh tương ứng.
    //


    // 5
    // 0 0 9 4 1
    // 0 0 1 0 6
    // 0 1 0 3 1
    // 4 0 3 0 8
    // 1 6 1 8 0

    cin >> n;
    vector<canh> dscanh;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];

            if(a[i][j] != 0) {
                // Co 1 canh moi i j va trong so j
                dscanh.push_back({i, j, a[i][j]});
            }
        }
    }
    sort(dscanh.begin(), dscanh.end(), cmp);
    for(canh X : dscanh) {
        cout << X.x << " " << X.y << " " << X.w << endl;
    }



    
    return 0;
}
