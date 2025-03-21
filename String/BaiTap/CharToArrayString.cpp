#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho mảng char A gồm N kí tự, bạn hãy ghép các ký tự trong mảng này thành 1 string.
// Xây dựng chương trình theo khuôn mẫu hàm như sau
string arr_to_string(char a[], int n)
{
    string res = "";
    for (int i = 0; i < n; i++)
    {
        res += a[i];
    }
    return res;
}

int main()
{
    int n;
    char a[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << arr_to_string(a, n) << endl;
    return 0;
}