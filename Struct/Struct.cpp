#include <bits/stdc++.h>
using namespace std;

struct DATE
{
    int day, month, year;
};
struct SinhVien
{
    // Luu thong tin gi cua Sinh Vine ??
    string Ten;
    DATE ns; // Cau truc nay co the la kieu du lieu cua cau truc khac
    double GPA;
};

void nhap(SinhVien &s)
{
}
int main()
{
    // Struct : Cho phep ban tu dinh nghia 1 kieu du lieu moi cho minh
    SinhVien s;
    s.Ten = "Teo";
    // s.ns = "22/12/2025";
    s.ns.day = 10;
    s.ns.month = 2;
    s.ns.year = 2002;
    s.GPA = 5.5;
    cout << s.Ten << " " << s.ns.day << " " << s.GPA << endl;

    SinhVien t = s; // Tu do thong tin t giong voi s

    vector<SinhVien> v(1000); // Chi co the su dung voi mang va vector
    return 0;
}