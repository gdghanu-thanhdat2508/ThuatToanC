#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

int main()
{
    int a[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 1, 2, 5},
        {1, 2, 1, 0, 3, 5},
        {1, 2, 1, 3, 4, 9},
        {1, 2, 1, 3, 0, 4},
        {1, 8, 7, 6, 2, 9}};
    int i = 2, j = 3;
    for (int k = 0; k < 8; k++)
    {
        int i1 = i + dx[k], i2 = j + dy[k];
        cout << a[i1][i2] << endl;
    }
    return 0;
}