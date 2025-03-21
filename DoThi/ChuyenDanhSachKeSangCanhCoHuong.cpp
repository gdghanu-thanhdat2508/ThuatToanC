#include <bits/stdc++.h>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

// Chuyen doi danh sach ke sang canh co huong 
// Cho đồ thị có hướng G = được biểu diễn dưới dạng danh sách kề. 
// Hãy chuyển đổi đồ thị dưới dạng danh sách kề này sang danh sách cạnh tương ứng.

// 5
// 5 3 4 
// 4 1 3 5
// 4 2
// 3 1 2 
// 3 2

vector<int> ke[1005];
int n, m;
int main() {
    cin >> n;
    cin.ignore();
    vector< pair<int, int> > danhsachcanh;
    for(int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);

        stringstream ss(s);

        string w;
        while(ss >> w) {
            danhsachcanh.push_back({i, stoi(w)});
        }
    }
    sort(danhsachcanh.begin(), danhsachcanh.end());

    for(auto it : danhsachcanh) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
