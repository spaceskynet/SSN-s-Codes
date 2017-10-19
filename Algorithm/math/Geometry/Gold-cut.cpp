#include<iostream>
#include<cstdio>
#define PHI 0.6180339887498949
using namespace std;
typedef double db;
const int maxn=15;
const db eps=1e-6;
int n;
db a[maxn],l,r;
db f(db);
int main()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=n;i>=0;i--)
	{
		scanf("%lf",&a[i]);
	}
	db d=(r-l)*PHI,rm=l+d,lm=r-d;
	while(d>eps)
	{
		d*=PHI;
		if(f(lm)>=f(rm))
		{
			r=rm=lm;
			lm=r-d;
		}
		else
		{
			l=lm=rm;
			rm=l+d;
		}
	}
	printf("%.5f",rm);
	return 0;
}
db f(db x)
{
	db ret=a[n];
	for(int i=n-1;i>=0;i--)
	{
		ret=ret*x+a[i];
	}
	return ret;
}
/*

*/
