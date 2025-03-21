#include <bits/stdc++.h>
using namespace std;


//Cho ma trận kề A[] của đồ thị vô hướng G = chỉ bao gồm các số 0 hoặc 1. Hãy chuyển đổi đồ thị này thành
// danh sách cạnh và danh sách kể tương ứng

// 5
// 0 1 1 1 0
// 1 0 0 1 1
// 1 0 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0

// 2 1
// 3 1
// 4 1
// 4 2
// 4 3
// 5 2
// 5 3 
// 5 4
//
// 1 : 2 3 4
// 2 : 1 4 5
// 3 : 1 4 5
// 4 : 1 2 3 5
// 5 : 2 3 4

int a[1005][1005];
int n,m;
vector<int> ke[10000005];
int main() {
    int n;
    for(int i = 1; i <= n; i++ ) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] && i > j) {
                cout << i << " " << j << endl;
            }
        }
    }
    cout << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == 1) {
                ke[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << i << " : ";
        for(int x : ke[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;

}
