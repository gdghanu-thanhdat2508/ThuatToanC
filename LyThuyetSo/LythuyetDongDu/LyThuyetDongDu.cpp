#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//  Ly thuyet dong du
//  (A + B) % C = ((A % C) + (B % C)) % C
//  (A - B) % C = ((A % C) - (B% C)) % C
//  (A * B) % C = ((A % C) * (B % C)) % C
//  (A / B) % C = ((A % C) * (B^-1 % C)) % C.
//  Co the ap dung cho n so, khong nhat thiet la phai 2 so A va B
//  Tranh duoc viec du am
//  Dac biet : Rieng phep chia la phai tinh nghich dao module

// Dang bai :
// Chia du ket qua cho 1 so cho truoc
// VD : Tinh n! sau do chiu du cho 1 so nao do
//      Tinh fibo sau do chia du cho 1 so nao do
// Dac diem : Se ra 1 so rat lon va chia du 1 so nao do

int main()
{
    int n;
    cin >> n;
    ll tich = 1;
    int mod = 1000000007;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        tich *= x % mod;
        tich %= mod; // quan trong
    }
    cout << tich << endl;
    return 0;
}