#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho xâu kí tự S gồm các từ được phân cách nhau bởi một vài dấu cách.
// Thực hiện đếm số lượng các từ khác nhau trong xâu mà không phân biệt hoa thường,
// ví dụ "28TecH" được coi là giống với từ "28teCH".
//(Bài này các bạn có thể thử code 2 vòng for lồng nhau hoặc sử dụng sort)

int main()
{
    set<string> se;
    string s;

    // Chuyen xau s thanh in thuong
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    while (cin >> s)
    {
        // Chuyen s ve dang in thuong
        for (char &x : s)
            x = tolower(x);
        se.insert(s);
    }
    cout << se.size() << endl;
    return 0;
}