#include<iostream>
#include<cstdio>
#include<complex>
using namespace std;
typedef complex<double> cd;
const int maxn=1e5+10;
struct Complex
{
    double real, imag;
    Complex(double real = 0.0, double imag = 0.0)
    {
        this->real = real, this->imag = imag;
    }
    Complex operator - (const Complex &elem) const
    {
        return Complex(this->real - elem.real, this->imag - elem.imag);
    }
    Complex operator + (const Complex &elem) const
    {
        return Complex(this->real + elem.real, this->imag + elem.imag);
    }
    Complex operator * (const Complex &elem) const
    {
        return Complex(this->real * elem.real - this->imag * elem.imag, this->real * elem.imag + this->imag * elem.real);
    }
    void setValue(double real = 0.0, double imag = 0.0)
    {
        this->real = real, this->imag = imag;
    }
}y[maxn];
complex<double> a[maxn];
void Swap(Complex &a, Complex &b)
{
    Complex tmp = a;
    a = b;
    b = tmp;
}
void Rader(Complex y[], int n);
int main()
{
	for(int i=0;i<8;i++) a[i]=i,y[i].real=i;
	for(int i=0,j=0;i<8;i++)
	{
		if(i<j) swap(a[i],a[j]);
		int k=8;
		while(j & (k>>=1)) j&=~k;
		j|=k;
	}
	Rader(y,8);
	for(int i=0;i<8;i++) printf("%f %f\n",a[i].real(),y[i].real);
	return 0;
}
void Rader(Complex y[], int n)
{
	for(int i = 1, j = n >> 1, k; i < n - 1; ++ i)
	{
		if(i < j)
			swap(y[i], y[j]);
		k = n >> 1;
		while(j >= k)
		{
			j -= k;
			k >>= 1;
		}
		if(j < k)
			j += k;
	}
}
