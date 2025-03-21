#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 5};
    int n = 10;

    // 2 tim kiem chinh : Tim kiem nhi phan, tim kiem tuyen tinh
    // 2 ham san : find, binary_search => Tra ve con tro
    auto *p = find(a, a + n, 5); // Tra ve con tro den thang 5 => Con tro tra ve : a + 9
    // Neu khong tm thay se tra ve a + n
    // Neu la vector se tra ve iterator
    if (p == a + n)
    {
        cout << " Not found \n";
    }
    else
    {
        cout << "FOUND \n";
    }

    sort(a, a + n);
    if (binary_search(a, a + n, 5)) // OLog(N) => Mang phai sap xep
    {
        cout << " FOUND \n";
    }
    else
    {
        cout << "NOT FOUND \n";
    }

    auto *p2 = lower_bound(a, a + n, 5); // Tang dan, tra ve vi tri phan tu dau tien,
    // gia tri lon hon hoac bang 5
    return 0;
}