#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cho một bàn cờ vua có kích thước n * n. Vẫn đề đặt ra rằng, có n quân hậu,
// bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không "ăn" nhau.

// Inout : 8

// Output : 92

int n, X[1000], ans = 0;
int cot[100], xuoi[100], nguoc[100];
// X[i] -> Luu con hau dang nam hang thu i va cot X[i]
// X[i]
// VD : X[1] = 1
//      X[2] = 3
// Khi dat vao cot nao do thi danh dau cot do da bi chiem cho => Danh dau
// Va danh dau 2 duong cheo con hau di qua ( Duong deo xuoi va duong cheo nguoc)

// n - 1 duong cheo

// hang i cot j
// Duong cheo xuoi : i tang => chi so duong cheo xuoi tang
// => Duong cheo Xuoi = i - j + n

// => Duong cheo nguoc = i + j - 1
void QL(int i)
{
    for (int j = 1; j <= n; j++)
    {
        // Chay tu cot 1 cho den cot n
        if (cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0)
        {
            X[i] = j; // Con hau nam o hang i cot j chiem cho 3 thang cot xuong va nguoc
            cot[j] = 1;
            xuoi[i - j + n] = 1;
            nguoc[i + j - 1] = 1;
            if (i == n)
            {
                for (int row = 1; row <= n; row++)
                {
                    for (int col = 1; col <= n; col++)
                    {
                        if (X[row] == col) // dat con hau nam thu i cot j
                        {
                            cout << "♛";
                        }
                        else
                        {
                            cout << "▪️";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else
            {
                QL(i + 1);
            }
            cot[j] = 0;
            xuoi[i - j + n] = 0;
            nguoc[i + j - 1] = 0;
        }
    }
}

int main()
{
    cin >> n;
    QL(1);
    cout << ans << endl;
    return 0;
}