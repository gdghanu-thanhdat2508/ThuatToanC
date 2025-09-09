#include <iostream>
#include <cmath>

using namespace std;
int swapDigits(int num)
{

    if (num < 10)
    {
        return num;
    }

    int last = num % 10;
    int digits = 0;
    int temp = num;

    while (temp >= 1)
    {
        temp /= 10;
        digits++;
    }

    int digit = pow(10, digits - 1);
    int first = num / digit;
    int middle = ((num % digit) / 10) * 10;

    return last * digit + middle + first;
}

int main()
{
    int n = 123;
    cout << swapDigits(n) << endl;
    return 0;
}