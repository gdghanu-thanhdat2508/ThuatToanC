#include <bits/stdc++.h>
using ll = long long;

// C++ : Thu vien STL
int main()
{
    // Vector - co the that doi kich thuoc

    vector<int> v;        // Non-value vector
    vector<int> v2(5, 0); // 5 items and all items have value are 0

    v.push_back(2); // Day vao vuoi vector
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    cout << v.size() << endl;

    cout << v[1] << endl;

    // Basic loop
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    // Range base for loop - for x
    for (int x : v)
    {
        cout << x << endl;
    }

    // Range base for loop to change the value
    for (int &x : v)
    {
        x = 100;
    }

    int a[5] = {1, 2, 3, 4, 5};
    // copy all items in array a to vector v
    vector<int> vCopy(a, a + 5); // 5 is a number of items in array a

    // Input values to vector from keyboard
    for (int i = 0; i < v.size(); i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // container
    // iterator
    vector<int> contro = {1, 2, 3, 4, 5, 6};

    vector<int>::iterator it = contro.begin(); // Determine interator for vector

    cout << *it << endl; // Print value of interator that the pointer is pointing at

    it++; // Move the pointer up to 2 point | it can move to left or right
    cout << *it << endl;

    for (auto it = contro.begin(); it != contro.end(); it++)
    {
        // Duyet vector theo chieu xuoi
    }

    for (auto it = contro.rbegin(); it != contro.rend(); it++)
    {
        // Duyet vector theo chieu nguoc
    }

    auto it = contro.begin() + 2; // Pointer point to position 2 in vector
    cout << *it << endl;

    // insert
    contro.insert(contro.begin() + 3, 1); // Inset number 1 to the position is 3

    // eraser - erase items at position
    contro.erase(contro.begin() + 3); // erase items at loacation 3

    // Neu nhu muon nhap tat ca phan tu ma khong biet so luong phan tu la gi

    vector<int> v3;
    int n;
    while (cin >> n)
    {
        v3.push_back(n);
    } // Khi doc het tat ca data, se tu dong dung

    return 0;
}
