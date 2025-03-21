#include <bits/stdc++.h>
using namespace std;

void LyThuyetDongDu()
{
    // Cho N!, tinh N! chia du 10^9 + 7

    // 4 cong thuc dong du - Co the ap dung cho nhieu so
    //(A + B) % C = ((A % C) + (B % C)) % C
    //(A - B) % C = ((A % C) - (B % C)) % C
    //(A * B) % C = ((A % C) * (B % C)) % C
    //(A / B) % C = ((A % C) * (B^-1 % C)) % C

    // VD : (23 + 9) % 3 = ((23 % 3) + (9 % 3)) % 3
    int n;
    cin >> n;
    long long gt = 1;
    for (int i = 1; i <= n; i++)
    {
        gt = (gt % 100000007) * (i * 1000000007) % 100000007;
    }
    cout << gt << endl;
}

bool cmp(string a, string b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
        return a < b; // Neu do dai bang nhau ti xep theo tu dien
}
void Sapxepkytu()
{
    string s;
    vector<string> v;
    while (cin >> s)
    {
        v.push_back(s);
    }
    // Sap xep theo tu dien tang dan
    sort(v.begin(), v.end(), cmp);
    for (string x : v)
    {
        cout << x " ";
    }
    cout << endl;
}

void LietKeCacTuKhacNhauTrongXau()
{
    string s;
    vector<string> v;
    set<string> se;
    while (cin >> s)
    {
        if (se.count(0) == 0)
        {
            v.push_back(s); // Luu cac tu != nhau theo thu tu xuat hien
        }
        se.insert(s); // Luu cac tu != nhau theo thu tu tu dien tang dan
    }
    for (string x : se)
    {
        cout << x << ' ';
    }
    cout << endl;
    for (string x : v)
    {
        cout << x << endl;
    }
    cout << endl;
}

void demphantutronhstring()
{
    string s;
    int dem = 0;
    while (cin >> s)
    {
        dem++;
    }
    cout << dem << endl;
}

void pangram()
{
    // Chua day du ki tu tu A den Z
    string s;
    cin >> s;
    int cnt[256] = 0;
    for (char x : s)
    {
        cnt[tolower(x)] = 1;
    }
    for (int i = 97; i <= 132; i++)
    {
        if (cnt[i] == 0)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES" << endl;
}

void KyTuChung()
{
    string s, t;
    cin >> s >> t;
    int cnt1[256] = {0}, cnt2[256] = {0};
    for (char x : s)
    {
        cnt1[x] = 1;
    }
    for (char x : t)
    {
        cnt2[x] = 1;
    }
    for (int i = 0; i < 256; i++)
    {
        if (cnt1[i] && cnt2[i])
        {
            cout << (char)i;
        }
    }
    cout << endl;
    for (int i = 0; i < 256; i++)
    {
        if (cnt1[1] || cnt2[i])
        {
            cout << (char)i;
        }
    }
    cout << endl;
}

void StringSangInt()
{
    string s = "1234556";
    int n = stoi(s);
}

void IntSangString()
{
    int a = 1234;
    string s = to_string(a);
}

void ChuSoDungGiua()
{
    string s;
    getline(cin, s);
    if (s.size() % 2 == 0)
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        cout << s[s.size() / 2] << endl;
    }
}

void inhoa(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
    }
    // for (char &x : s)
    //     x = toupper(x);
}

void SoSanh2XauKyTu()
{
    // So sanh theo thu tu tu dien
    string s = "abcdz";
    string t = "abcduakselie";
    if (s < t)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    string s = 'aaaaaaa';
    cout << s.size() << s.length() << endl; // So ky tu trong string
    // Ban chat string la 1 mang cac ky tu
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }
    string a;
    cin >> a;        // tu dong dung khi gap dau cach
    getline(cin, a); // Doc het dong ke ca nut cach - dung khi gap phim enter
    for (char x : a)
    {
        cout << x << endl;
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }

    // Ham push_back / pop_back - them / xoa 1 char sau chuoi - nhu vector
    a.push_back('a');
    a.pop_back(); // Xoa ky tu cuoi cung

    // insert()
    a.insert(2, "@@"); // chen @@ vao chi so 2 trong xau a

    // erase
    s.erase(2, 3); // xoá đi 3 ký tự từ chỉ số 2 đến cuối dẫy

    // find
    s.find("@@"); // neu khong tim thay se tra ve string::npos

    // substr
    s.substr(2, 4); // Cắt lấy ra 4 kí tự từ chỉ số 2

    // String - co the so sanh / cong / tru / ...

    // islower , isdigit, issupper, tolower, toupper
}