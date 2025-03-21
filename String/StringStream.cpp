#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// StringSteam : Tach tu trong xau ky tu
int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s); // Lay noi dung xau s va bien thanh 1 luong co the nhap tung tu
    string tmp;
    string res = ""; // Loai bo dau cach thua
    while (ss >> tmp)
    {
        res += tmp;
        res += " ";
    }
    res.pop_back();

    while (getline(ss, tmp, ',')) // Doc xau ky tu den dau , thi dung
    {
        if (tmp[0] == ' ')
        {
            tmp.erase(0, 1); // Xoa khoang cach neu co o dang truoc
        }
        cout << tmp << endl;
        // Nen kiam tra tmp != " " sau do xu ly
    }
    return 0;
}