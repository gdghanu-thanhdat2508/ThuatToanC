#include <bits/stdc++.h>
using namespace std;

int parent[200005], sz[200005];
int n, m, q;

void init() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if(parent[u] == u) return u;
    else return parent[u] = Find(parent[u]);
}

bool Union(int x, int y) {
    x = Find(x); y = Find(y);
    if(x == y) {
        return false;
    }
    if(sz[x] < sz[y]) {
        parent[x] = y;
        sz[y] += sz[x];
    } else {
        parent[y] = x;
        sz[x] += sz[y];
    }
    return true;
}


int main() {
    //People connect with each other in a social network.
    //A connection between Person i and Person f is represented as M i j. 
    //When two persons belonging to different communities connect, the net effect is the merge the communities which i and j belong to.
    //At the beginning, there are n people representing n communities.
    //Suppose person 1 and 2 connected and later 2 and 3 connected, then 1,2, and 3 will belong to the same community.
    //
    //There are two types of queries:
    //Mij → communities containing persons i and j are merged if they belong to different communities.
    //Qi → print the size of the community to which person i belongs.
    //
    //Input format :
    //The first line of input contains 2 space-separated integers n and q, the number of people and the number of queries.
    // The next q lines will contain the queries.
    //
    // 3 6
    // Q 1
    // M 1 2 
    // Q 2 
    // M 2 3
    // Q 3
    // Q 2


    cin >> n >> q;
    init();
    while(q--) {
        char c; cin >> c;
        if(c == 'M') {
            int i, j; cin >> i >> j;
            Union(i, j);
        } else {
            int i; cin >> i;
            cout << sz[Find(i)] << endl;
        }
    }
    return 0;
}
