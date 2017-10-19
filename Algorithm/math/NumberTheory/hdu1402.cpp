#include<iostream>
#include<cstdio>
#include<complex>
#include<cmath>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef complex<double> E;
const int maxn=3e5+10;
const double PI=acos(-1),eps=1e-8;
string str1,str2;
E a[maxn],b[maxn];
int ans[maxn];
bool flag=0;
void Rader(E*,int);
void FFT(E*,int,int);
int main()
{
//	freopen("data1.in","r",stdin);
	while(getline(cin,str1)&&getline(cin,str2))
	{
		flag=0;
		if(str1[0]=='-') str1.erase(0,1),flag^=1;
		if(str2[0]=='-') str2.erase(0,1),flag^=1;
		int len=1,len1=str1.size(),len2=str2.size();
		while(len<(max(len1,len2)<<1)) len<<=1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<len1;i++) a[i].real(str1[len1-i-1]-'0');
		for(int i=0;i<len2;i++) b[i].real(str2[len2-i-1]-'0');
		for(int i=len1;i<len;i++) a[i].real(0.0);
		for(int i=len2;i<len;i++) b[i].real(0.0);
		FFT(a,len,1),FFT(b,len,1);
		for(int i=0;i<len;i++) a[i]*=b[i];
		FFT(a,len,-1);
		for(int i=0;i<len;i++) ans[i]=(int)(a[i].real()+0.5);
		for(int i=0;i<len;i++)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		while(--len&&ans[len]==0);//不能把0全部去掉，因为有可能乘数为0. 
		if(flag) putchar('-');
		for(int i=len;i>=0;--i) putchar(ans[i]+'0');
		putchar('\n');
	}
	return 0;
}
void Rader(E *y,int n)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i<j) swap(y[i],y[j]);
		int k=n;
		while(j&(k>>=1)) j&=~k;
		j|=k; 
	}
}
void FFT(E *y,int n,int inv)
{
	Rader(y,n);
	for(int h=2;h<=n;h<<=1)
	{
		E Wn(cos(2*PI/h),inv*sin(2*PI/h));
		for(int i=0;i<n;i+=h)
		{
			E W(1,0);
			for(int j=i;j<i+h/2;j++)
			{
				E u=y[j],t=W*y[j+h/2];
				y[j]=u+t;
				y[j+h/2]=u-t;
				W*=Wn;
			}
		}
	}
	if(inv==-1) for(int i=0;i<n;i++) y[i]/=n;
}

