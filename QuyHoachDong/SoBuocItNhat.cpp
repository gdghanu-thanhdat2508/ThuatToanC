// VNG + SAMSUNG

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//  Cho mảng A gồm N số nguyên. Nhiệm vụ của bạn là sắp xếp lại mảng số với số lượng bước là ít nhất. Tại mỗi
//  bước, bạn chỉ được phép chèn phần tử bất kỳ của mảng vào vị trí bất kỳ trong mảng. Ví dụ A = {2, 3, 5, 1, 4, 7,
//  6 }sẽ cho ta số phép chèn ít nhất là 3 bằng cách lãy số 1 chèn trước số 2, lấy số 4 chèn trước số 5, lấy số 6 chèn
//  trước số 7 ta nhận được mảng được sắp.

// Dòng đầu tiên là N; Dòng thứ 2 gồm N phần tử của mảng A;

// 1<=N<=1000; 1<=A[i]<=1000;

//  13
//  143 340 571 845 211 228 274 443 666 594 491 814 24

//  6

// So luong phan tu - Day con tang dai nhat (LIS) = So cach chen
int minInsertionsToSort(vector<int> &A)
{
    int n = A.size();
    if (n == 0)
        return 0;

    // Tìm dãy con tăng dài nhất (LIS)
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), A[i]);
        // lower_bound -  được sử dụng để tìm vị trí đầu tiên trong một phạm vi đã được sắp xếp
        // mà tại đó một giá trị cụ thể có thể được chèn vào mà vẫn đảm bảo thứ tự sắp xếp.
        if (it == dp.end())
        {
            dp.push_back(A[i]);
        }
        else
        {
            *it = A[i];
        }
    }

    // Số phép chèn ít nhất là n - độ dài của LIS
    return n - dp.size();
}

int main()
{
    vector<int> A = {2, 3, 5, 1, 4, 7, 6};
    int result = minInsertionsToSort(A);
    cout << "Số phép chèn ít nhất cần thực hiện: " << result << endl;
    return 0;
}