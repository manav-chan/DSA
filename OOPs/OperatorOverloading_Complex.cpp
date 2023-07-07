#include <bits/stdc++.h>
using namespace std;

class Complex 
{
    private:
        int real, imag;

    public:
        Complex(int r=0, int i=0)
        {
            real = r, imag = i;
        }

        Complex operator + (Complex const &a)
        {
            Complex res;
            res.real = real + a.real; // real is variable of the 2nd operand
            res.imag = imag + a.imag;
            return res;
        }

        void display()
        {
            cout<<real<<" + i"<<imag;
        }
};

int main()
{
    Complex c1(5,2);
    Complex c2(10,4);
    Complex c3 = c1 + c2;
    
    c3.display();

    return 0;
}