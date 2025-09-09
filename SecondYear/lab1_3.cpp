#include <struct.h>
#include <iostream>

using namespace std;

struct Complex
{
    double real;
    double imag;
};

Complex add(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex multiply(Complex a, Complex b)
{
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

int main()
{
    Complex a = {1.0, 2.0};
    Complex b = {3.0, 4.0};

    Complex sum = add(a, b);
    Complex product = multiply(a, b);

    cout << "Sum " << sum.real << " + " << sum.imag << "i" << endl;
    cout << "Product " << product.real << " + " << product.imag << "i" << endl;

    return 0;
}