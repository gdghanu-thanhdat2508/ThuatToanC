#include <bits/stdc++.h>
using namespace std;

// push_back, pop_back
// insert(vitri, xau) : 0(N)
// erase(vitri), erase(vitri, so ki tu)
// substr(vitri), substr(vitri, so ki tu)
// find(s, t) -> Tra ve vi tri cua xau t trong xau s neu ton tai
// reverse() -> Lay nguoc lai chuoi
// isdigit, isalpha, islower, isupper
// tolower, toupper
// > < >= <= : So sanh theo danh sach tu dien alpha b
// set, map, vector, ... => Luu lai string
int main()
{
    string s = "xin chao viet nam";
    // Giong nhu 1 vector, moi phan tu la 1 char
    char a = 'a';

    // Nhap 1 chuoi co dau cach
    cin.ignore(1);
    getline(cin, s);

    s.erase(2, 3);
    string t = s.substr(2, 3);

    string s2 = "viet nam";

    if (s.find(s2) == string::npos)
    {
        // Khong tim thay
        cout << "NOT FOUND\n";
    }
    else
    {
        cout << "FOUND ! \n";
        // Tim thay so chi ve chi so cua xay s2 trong xau s
    }

    // Lat nguoc 1 xau ky tu
    reverse(s.begin(), s.end()); // Ko tra ve xau lat nguoc, ma chi lat nguoc truc tiep xau

    // Chuyen doi xau thanh in hoa thanh in thuong
    string name = "Nguyen Thanh Dat";
    for (int i = 0; i < s.size(); i++)
    {
        name[i] = toupper(name[i]);
    }
    cout << name << endl;

    for (char &x : name)
    {
        x = tolower(x);
    }
    cout << name << endl;

    // Noi chuoi voi nhau = dau +
    string noichuoi = s + " + " + name;

    string arrString[] = {"C++", "Python", "Java", "C#", "vv"};
    sort(arrString, arrString + 5);
    for (string x : arrString)
    {
        cout << x << " \n";
    }
    return 0;
}
