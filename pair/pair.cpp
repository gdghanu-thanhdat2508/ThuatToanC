#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pair
    pair<int, int> p;
    // First va second

    p.first = 100;
    p.second = 200;

    // Cach 2 de gan gia tri cho pair
    pair<string, int> n = make_pair("Hello", 20);

    // Cach 3
    pair<int, int> s = {10, 20};

    // Cach 4: Cin tu ban phim

    pair<int, int> pa;

    cin >> pa.first >> pa.second;
    cout << pa.first << " " << pa.second;

    // Set long vao pair
    pair<int, set<int>> pai;

    pai.first = 10 ;
    pai.second.insert(3);
    pai.second.insert(4);
    pai.second.insert(5);
    pai.second.insert(1);
    return 0;
}
