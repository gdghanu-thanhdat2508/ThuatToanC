#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Thành phố X có N thị trấn trên trục đường chính. Tọa độ của các thị trấn lần lượt là a[1],a[2], ..., a[N],
    // các tọa độ này là phân biệt, không có 2 tọa độ nào trùng nhau. Chính quyền thành phố muốn xây dựng một tuyến buýt nhanh BRT
    // để kết nối 2 thị trấn gần nhau nhất với nhau. Bạn hãy tính thử xem chiều dài của tuyến buýt này bằng bao nhiêu?
    // Và có bao nhiêu cặp thị trấn có tiềm năng giống nhau để xây dựng tuyến BRT này.

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int diff = INT_MAX, dem = 0;
    for (int i = 1; i < n; i++)
    {
        // a[i] - a[i - 1]
        if (a[i] - a[i - 1] < diff)
        {
            diff = a[i];
            dem = 1;
        }
        else if (a[i] - a[i - 1] == diff)
        {
            ++dem;
        }
    }
    cout << diff << " " << dem << endl;

    return 0;
}