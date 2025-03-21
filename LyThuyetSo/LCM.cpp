#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll b;
    cin >> b;
    ll tong_uoc_so = 0;
    for (ll i = 1; i <= sqrt(b); i++)
    {
        if (b % i == 0)
        {
            tong_uoc_so++;
            if (b / i != i)
            { // Dam bao moi uoc cua b chi dc dem duy nhat 1 lan
                tong_uoc_so++;
            }
        }
    }
    cout << tong_uoc_so << endl;
    return 0;
}