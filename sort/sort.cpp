#include <bits/stdc++.h>
using namespace std;

int main()
{
    // sort : intro sort = quick sort + heap sort

    int a[] = {10, 20, 1, 2, 4, 6, 2, 12, 22, 30};
    int n = 10;
    sort(a, a + n); // Tang dan

    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    sort(a, a + n, greater<int>()); // Giam dan

    // Sort tu chi so x dan chi so a
    sort(a + 2, a + 8);                 // Sort tu chi so 2 den chi so 7 theo chieu tang dan
    sort(a + 2, a + 8, greater<int>()); // Sort tu chi so 2 den chi so 7 theo chieu tang dan

    // Sap xem mang char - sap xem theo chieu tang dan va giam dan theo tu dien

    char b[] = {'a', 'z', 'c', 'b', 'e', 'l', 'o', 'd', 'm', 'n'};
    int n1 = 10;

    sort(b, b + n1); // Sap xep tang dan theo tu dien

    string s = "adandjanjbahrajnskdnajajfnajsnuaw";
    sort(s.begin(), s.end()); // sap xep 1 chuoi string theo tu dien tang dan

    cout << s << endl;

    return 0;
}