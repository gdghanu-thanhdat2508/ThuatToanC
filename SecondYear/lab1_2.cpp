#include <iostream>

using namespace std;

void findMax(int *max, int a)
{
    if (a > *max)
    {
        *max = a;
    }
}

int main()
{
    int n = 10;
    int *ptr = &n;

    findMax(ptr, 15);
    cout << *ptr << endl;
    return 0;
}