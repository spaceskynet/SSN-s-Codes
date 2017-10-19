//high* or many* UOJ 34
#include<iostream>
#include<cstdio>
#include<complex>
#include<cmath>
#include<cstring>
using namespace std;
typedef complex<double> E;
const int maxn=3e5+10;//max len
const double PI=acos(-1),eps=1e-8;
E a[maxn],b[maxn];
int n,m;
double x;
inline void Rader(E*,int);
void FFT(E*,int,int);
int main()
{
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	for(int i=0;i<=n;i++) scanf("%lf",&x),a[i].real(x);
	for(int i=0;i<=m;i++) scanf("%lf",&x),b[i].real(x);
	int len=1;
	while(len<=n+m) len<<=1;
	FFT(a,len,1),FFT(b,len,1);
	for(int i=0;i<len;i++) a[i]*=b[i];
	FFT(a,len,-1);
	for(int i=0;i<=n+m;i++) printf("%d ",(int)(a[i].real()+0.5));
	return 0;
}
inline void Rader(E *y,int n)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i<j) swap(y[i],y[j]);
		int k=n;
		while(j&(k>>=1)) j&=~k;//is & not &&
		j|=k;
	}
}
void FFT(E *y,int n,int inv)
{
	Rader(y,n);
	for(int h=2;h<=n;h<<=1)
	{
		E Wn(cos(2*PI/h),inv*sin(2*PI/h));//e^(2*PI/h)=cos(2*PI/h)+i*sin(2*PI/h)
		for(int i=0;i<n;i+=h)
		{
			E W(1,0);
			for(int j=i;j<i+h/2;j++)
			{
				E u=y[j],t=W*y[j+h/2];
				y[j]=u+t;
				y[j+h/2]=u-t;
				W*=Wn;//а§зЊвђзг 
			}
		}
	}
	if(inv==-1) for(int i=0;i<n;i++) y[i]/=n;
}
