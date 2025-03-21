#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Cho mang A gom N phan tu la ky tu, Dem xem co bao nhieu ky tu khac nhau

    set<char> ch;

    int n;
    cin >> n;

    // Input
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        ch.insert(x);
    }

    // Output
    cout << ch.size() << endl;

    // Liet ke theo thu tu tang dan
    // Set se tu dong duy tri thu thu tang dan

    // Neu khong biet cach dung reverse itergrator
    vector<char> v;

    for (char x : ch)
    {
        cout << x << " ";
        v.push_back(x);
    }
    cout << endl;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}