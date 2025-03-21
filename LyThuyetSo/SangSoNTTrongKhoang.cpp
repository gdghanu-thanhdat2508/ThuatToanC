#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Sang so nguyen to trong khoang l -> r

// VD : Sang so nguyen to tu 28 => 100

void sang(ll l, ll r)
{
    int prime[r - l + 1];
    for (int i = 0; i <= r - l; i++)
    {
        prime[i] = 1;
    }
    for (ll i = 2; i <= sqrt(r); i++)
    {
        for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
        // i * i, (l + i - 1) / i * i) -> Tim dc so lon hon hoac bang l va chia het cho i
        // Muc tieu la duyet cac so la boi cua i

        // i = 2
        // l = 85, r = 100
        // (85 + 2 - 1) / 2 * 2 = 86
        // / i * i -> Chia nguyen
        {
            prime[j - l] = 0;
        }
    }
    for (ll i = max(2ll, l); i <= r; i++)
    {
        // max(2ll, l) -> Bo qua so 0 va 1
        if (prime[i - l])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    sang(28, 100);
    return 0;
}