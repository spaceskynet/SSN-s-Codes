#include <bits/stdc++.h>
#include <cmath>
#define PHI 0.6180339887498948482
using namespace std;

typedef long double LD;

int n, i;
LD L, R, mL, mR;
LD a[15], d, fL, fR;

LD f(LD x)
{
	LD s = a[n];
	for(int i = n - 1; i >= 0; i--)
		s = s * x + a[i];
	return s;
}

int main()
{
	scanf("%d%Lf%Lf", &n, &L, &R);
	for(i = n; i >= 0; i--)
		scanf("%Lf", a + i);
	d = (R - L) * PHI;
	mL = R - d;
	mR = L + d;
	while(d > 1e-6)
	{
		fL = f(mL);
		fR = f(mR);
		d *= PHI;
		if(fL >= fR)
		{
			R = mR = mL;
//			R = mR;
			mL = R - d;
		}
		else
		{
			L = mL = mR;
//			L = mL;
			mR = L + d;
		}
	}
	printf("%.5Lf\n", mR);
}
