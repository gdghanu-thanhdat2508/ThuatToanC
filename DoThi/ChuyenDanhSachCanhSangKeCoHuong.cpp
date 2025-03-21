#include <algorithm>
#include <bits/stdc++.h>
using  namespace std;

//Cho đồ thị có hớng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh
// sách cạnh này sang danh sách kề tương ứng.


vector<int> ke[1005];
int n, m;

int main() {
   

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        // Co 2 dinh 1 va 3. chi dc cho phep cho 3 vao danh sach ke cua 1 chu khong duoc lam dieu nguoc lai
        // Do day la do thi co huong 

        ke[x].push_back(y);
    }

    for(int i = 1; i <= n; i++) {
        //ke[i]
        sort(ke[i].begin(), ke[i].end());
        cout << i << " : ";

        for(int x : ke[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
