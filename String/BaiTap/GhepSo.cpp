#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho một xâu kí tự S chỉ bao gồm các chữ cái và chữ số,
// hãy thực hiện tách các số xuất hiện trong xâu ra và ghép lại với nhau
// để tạo thành một số tự nhiên lớn nhất.
// Ví dụ với xâu S= "123abcda234kkf11" thì ta sẽ tách được các số 123, 234 và 11,
// trong trường hợp các số bắt đầu bằng chữ số 0 thì ta loại bỏ các số 0 vô nghĩa này.
// Sau đó ghép lại với nhau thành số 23412311 là số lớn nhất có thể đạt được.

bool cmp(string a, string b)
{
    string ab = a + b;
    string ba = b + a;

    return ab > ba;
}

int main()
{
    string s;
    getline(cin, s);
    for (char &x : s)
    {
        if (isalpha(x))
        {
            x = ' ';
        }
    }
    vector<string> v;
    string tmp;
    stringstream ss(s);
    while (ss >> tmp)
    {
        while (tmp.size() > 1 && tmp[0] == 0)
        {
            tmp.erase(0, 1);
        }
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);

    for (string x : v)
    {
        cout << x;
    }
    return 0;
}