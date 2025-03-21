#include <bits/stdc++.h>
using namespace std;
// Day con tang dai nhat ( LIS )
// Cho mảng A gồm N phần tử, hãy tìm dãy chon (Không nhất thiết phải đứng cạnh nhau) tăng chặt dài nhất của mảng A
// Tìm được độ dài của dãy con tăng dài nhất đó
// VD dãy 1 2 3 1 4 8 5
// Chọn được ra 1 2 3 4 5 : Dài nhất là 5
// Hoặc 1 2 3 4 8
// Làm quy hoạch động cần phải xác định được các bài toán con có cơ sở sau đó xây dựng bài toán lớn hơn
int main()
{
    // #Quy Hoach Dong

    // L[i] : độ dài của dãy con tăng dài nhất kết thúc ở chỉ số i
    // L[i] = max(L[i], L[j] + 1)
    // j là phần tử đứng trước i và a[i] > a[j]
    // O(n^2)

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> L(n, 1); // TH cơ sở
    for (int i = 0; i < n; i++)
    {
        // Cập nhập L[i] thông qua các trường hợp đã biết trước

        // Duyet qua tung phan tu dung truoc chi so i
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    cout << *max_element(L.begin(), L.end()) << endl;
    return 0;
}