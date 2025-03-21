#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;

vector<int> ke[1005];

int n, m;

int main() {
    
    //Dong dau tien la so nguyen đương n, tương ưng với so đinh cua đo thị.
    //N đong tiep theo môi đong chưa nhieu số nguyên, dòng thứ i tương ứng với các đỉnh trong danh sách kể của đỉnh i.

    // Liet ke theo thu tu tang dan 

    // Dung stringstream de tach 
    // 5
    // 4
    // 3 4 5
    // 2 5
    // 1 2 
    // 2 3

    // Chuyen danh sach ke sang danh sach canh
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n ;i++) {
        string s;
        getline(cin, s); // Loai bo phim enter trong cin 
        stringstream ss(s);
        string w;
        while(ss >> w) {
            if(stoi(w) > i) {
                cout << i << " " << w << endl;
            }
        }
    }

    return 0;
}
