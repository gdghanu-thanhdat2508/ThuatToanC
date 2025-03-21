#include <bits/stdc++.h>
using namespace std;

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

// Boi chung nho nhat - b(2) = {0 , 2, 4 ,..} Boi chung la cac so chia het cho b
// Bản chất nhân 2 số a và b là nhân  thừa số nguyên tố với nhau
// Nhưng khi nhân với nhau lại thừa ra các cặp ước chung lớn nhất
//==> Phải bỏ phần ước chung lớn nhât của a và b
int boichungnhonhat(int a, int b)
{
    return a * b / euclid(a, b);
}
