#include <bits/stdc++.h>
using namespace std;

// Su dung thuat toan Euclid
// Uoc chung lon nhat cua a b
// = a neu b = 0
// gcd(a,b) = gcd(b , a % b) ==> lap di lap lai cho don khi b = 0
// VD gcd(10, 0) => uoc chung lon nhat la 10
// gcd(32,15)
// Bien doi gcd(15, 32 % 15) => gcd(15, 2) => tiep tuc lap lai

// Uoc cua a la cac so a chia het . 6 chia het cho 6 3 2 1 => uoc
int euclid(int a, int b)
{ // Khuyen dung
    while (b != 0)
    {
        // a, b => b , a % b
        int r = a % b; // Phai tao bien tam
        a = b;
        b = r;
    }
    return a;
}