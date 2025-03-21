#include <bits/stdc++.h>
using namespace std;


vector<int> ke[1005];
// ke[i] : vector luu danh sach ke, cac dinh ke voi dinh i 

int n, m;
int main() {
    // Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh.
    // Hãy chuyển đổi đồ thị dưới dạng danh sách cạnh này sang danh sách kề tương ứng.
    //

    // 5 4
    // 2 5
    // 4 1
    // 4 2
    // 4 3
    // In ra tu nho cho den lon 


    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        // ke[i]
        cout << i << " : ";
        sort(ke[i].begin(), ke[i].end());

        for(int x : ke[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
