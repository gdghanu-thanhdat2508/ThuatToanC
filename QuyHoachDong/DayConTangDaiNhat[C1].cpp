#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // Cho mảng số nguyên A[] gồm N phần tử,
    // hãy tìm dãy con (không nhất thiết các phần tử phải liên tiếp) tăng chặt dài nhất của mảng A.

    // 14
    // 128 104 53 876 660 961 754 775 290 231 224 915 392 994

    // 6

    // Su dung quy hoach dong

    // O(n^2) - cach 1

    // F[i] : Luu lai do dai Day con tang dai nhat ket thuc o chi so i
    // F[i] : Cap nhap thong qua cac F[i] o vi tri truoc

    // Bai toan co so : F ban dau deu bang 1
    // Update F[] khi ai > aj
    // In ra thang lon nhat trong mang F

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int F[n];
    for (int i = 0; i < n; i++)
    {
        F[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (F[i] > F[j])
            {
                F[i] = max(F[i], F[j] + 1);
            }
        }
    }
    return 0;
}