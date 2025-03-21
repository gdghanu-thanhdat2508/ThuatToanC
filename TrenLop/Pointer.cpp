#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
using ll = long long;

void abc()
{
    int b = 10;
}

int sum(int *a, int *b)
{
    return *a + *b; // address
}
// int * x => x is a pointer variable
// int * y => y is a pointer variable
// *x => the value of the memmory
// *x + *y = a + b

int main()
{
    int a = b + 10;
    cout << &a << endl;

    int *ptr = (int *)malloc(10 * sizeof(int)); // Dynamic memmory
                                                // If allocate too much -> Not enough memory -> NULL
                                                // Like a vector

    void swap(int *x, int *y)
    {
        int temp = = *x;
        *x = *y;
        *y = temp;
    }
    // x y are pointer varivable;
    // swap(&a, &b);
    // x = &a -> x is a pointer that point to the memory
    // y = &b
    //
    return 0;
}